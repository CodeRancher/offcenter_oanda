/**
 * Copyright 2020 Scott Brauer
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an  BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file   OandaEndpoints.cpp
 * @author Scott Brauer
 * @date   12-14-2020
 */

#include "date/date.h"

#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"
using namespace oanda::v20;

namespace oanda {
namespace v20 {
namespace endpoint {

BaseParameter::BaseParameter(const std::string name, ParameterType type, OandaEndpointParameters& parameterManager):
	m_isDirty(false),
	m_name(name),
	m_type(type),
	m_parameterManager(parameterManager)
{
	parameterManager.registerParameter(this);
}

const std::string BaseParameter::name() const
{
	return m_name;
}

const ParameterType BaseParameter::type() const
{
	return m_type;
}

const std::string BaseParameter::operator()()
{
	return value();
}

/**
 *
 */
StringParameter::StringParameter(const std::string name, ParameterType type, OandaEndpointParameters& parameterManager):
	BaseParameter(name, type, parameterManager)
{
}

const std::string StringParameter::value() const
{
	return m_value;
}

void StringParameter::set(const std::string value)
{
	m_value = value;
	m_isDirty = true;
}

void StringParameter::set(std::initializer_list<std::string> value, const std::string sep)
{
	set(common::join(value, sep));
}

//	const std::string operator()() { return get(); }
void StringParameter::operator()(const std::string value)
{
	set(value);
}

void StringParameter::operator=(const std::string value)
{
	set(value);
}

void StringParameter::operator=(std::initializer_list<std::string> value)
{
	set(value);
}

///
DateTimeParameter::DateTimeParameter(const std::string name, ParameterType type, OandaEndpointParameters& parameterManager):
	BaseParameter(name, type, parameterManager),
	m_value()
{}

const std::string DateTimeParameter::value() const
{
	std::string unix;
	to_string(primitives::AcceptDatetimeFormat::UNIX, unix);
	std::ostringstream ss;
	if (parameterManager().value("Accept-Datetime-Format") == unix) {
		// 12345678.000000123
		ss << m_value.time_since_epoch().count();
	} else {
		// YYYY-MM-DDTHH:MM:SS.nnnnnnnnnZ
		ss << date::format("%FT%TZ", std::chrono::time_point_cast<std::chrono::nanoseconds>(m_value));
	}
	return ss.str();
}

///
void DateTimeParameter::set(const SystemClockTimePoint& value)
{
	m_value = value;
	m_isDirty = true;
}

//	const std::string operator()() { return get(); }
void DateTimeParameter::operator()(const SystemClockTimePoint& value)
{
	set(value);
}

void DateTimeParameter::operator=(const SystemClockTimePoint& value)
{
	set(value);
}

///
PricingComponentParameter::PricingComponentParameter(const std::string name, ParameterType type, OandaEndpointParameters& parameterManager):
	BaseParameter(name, type, parameterManager),
	m_value()
{}

const std::string PricingComponentParameter::value() const
{
	return m_value.pricingComponent();
}

///
void PricingComponentParameter::set(const primitives::PricingComponents& value)
{
	m_value = value;
	m_isDirty = true;
}

void PricingComponentParameter::operator()(const primitives::PricingComponents& value)
{
	set(value);
}

void PricingComponentParameter::operator=(const primitives::PricingComponents& value)
{
	set(value);
}

///
OandaEndpointParameters::OandaEndpointParameters()
	//m_headers(),
	//m_paths(),
	//m_queries()
{}

///
void OandaEndpointParameters::registerParameter(const BaseParameter* parameter) {
	m_parameters.push_back(parameter);
}

///
web::uri OandaEndpointParameters::buildURI(const std::string origPath) const
{
	std::string path = origPath;

	web::uri_builder builder;
	for (const BaseParameter* element : m_parameters) {
		if (element->type() == endpoint::ParameterType::PATH) {
			std::ostringstream ss;
			ss << "\\{" << element->name() << "\\}";
			path = std::regex_replace(path, std::regex(ss.str()), element->value());
		}

		if ((element->type() == endpoint::ParameterType::QUERY) && element->isDirty()) {
			builder.append_query(element->name(), element->value());
		}
	}

	builder.set_path(path);

	return builder.to_uri();
}

///
std::string OandaEndpointParameters::value(std::string name) const {
	for (const BaseParameter* element : m_parameters) {
		if (element->name() == name) {
			return element->value();
		}
	}
	throw common::OandaInvalidType("Unknown Parameter: " + name);
}

///
const Parameters OandaEndpointParameters::headers() const {
	Parameters parameters;
	for (const BaseParameter* element : m_parameters) {
		if ((element->type() == endpoint::ParameterType::HEADER) && element->isDirty()) {
			parameters[element->name()] = element->value();
		}
	}
	return parameters;
}

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */
