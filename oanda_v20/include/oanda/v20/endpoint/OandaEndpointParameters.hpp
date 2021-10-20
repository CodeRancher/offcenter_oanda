/**
 * Copyright 2021 Scott Brauer
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
 * @file   OandaEndpointParameters.hpp
 * @author Scott Brauer
 * @date   01-13-2021
 */

#ifndef OANDA_V20_ENDPOINT_OANDAENDPOINTPARAMETERS_HPP_
#define OANDA_V20_ENDPOINT_OANDAENDPOINTPARAMETERS_HPP_

#include <string>
#include <map>
#include <regex>
#include <chrono>

#include <cpprest/uri_builder.h>
//#include <date/date.h>

#include "oanda/v20/endpoint/OandaParameter.hpp"
#include "oanda/v20/common/Utility.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"
#include "oanda/v20/instrument/InstrumentDefinitions.hpp"
#include "oanda/v20/common/OandaCommonException.hpp"

using namespace oanda::v20;

namespace oanda {
namespace v20 {
namespace endpoint {

using Parameters = std::map<std::string, std::string>;

/// What type of parameter
enum class ParameterType {
	HEADER,	/// Value goes in header
	PATH,	/// Value goes in path
	QUERY	/// Value goes in query
};

class OandaEndpointParameters;

/**
 *
 */
class BaseParameter {
public:
	///
	explicit BaseParameter(const std::string name, ParameterType type, OandaEndpointParameters& parameterManager);

	///
	virtual ~BaseParameter() = default;

	///
	const std::string name() const;

	///
	virtual const std::string value() const = 0;

	///
	const ParameterType type() const;

	//virtual const std::string get() = 0;

	//void set(std::initializer_list<std::string> value, const std::string sep = ",") {
	//	set(oanda::v20::common::join(value, sep));
	//}
	//void set(const T& value) { setValue(value); }

	///
	const std::string operator()();

	///
	bool isDirty() const { return m_isDirty; }

	///
	//void operator()(const T& value) { setValue(value); }

	///
	//void operator=(const T& value) { setValue(value); }
	//void operator=(std::initializer_list<std::string> value) { setValue(value); }

protected:
	OandaEndpointParameters& parameterManager() const { return m_parameterManager; }
	bool m_isDirty;

private:
	std::string m_name;
	ParameterType m_type;
	OandaEndpointParameters& m_parameterManager;
};

/**
 *
 */
class StringParameter: public BaseParameter {
public:
	explicit StringParameter(const std::string name, ParameterType type, OandaEndpointParameters& parameterManager);

	virtual ~StringParameter() = default;

	const std::string value() const override;

	void set(const std::string value);

	void set(std::initializer_list<std::string> value, const std::string sep = ",");

//	const std::string operator()() { return get(); }
	void operator()(const std::string value);
	void operator=(const std::string value);
	void operator=(std::initializer_list<std::string> value);

private:
	std::string m_value;
};

/**
 *
 */
template<int MIN, int DEFAULT, int MAX>
class IntegerParameter: public BaseParameter {
public:
	explicit IntegerParameter(const std::string name, ParameterType type, OandaEndpointParameters& parameterManager):
		BaseParameter(name, type, parameterManager),
		m_value(DEFAULT) {}

	virtual ~IntegerParameter() = default;

	const std::string value() const override {
		return std::to_string(m_value);
	}

	void set(const std::string value) {
		std::stringstream ss(value);
		int tmp;
		ss >> tmp;
		set(tmp);
	}

	void set(int value) {
		if ((value < MIN) || (value > MAX)) {
			std::stringstream ss;
			ss << "Invalid value (" << value << "): ";
			ss << "Must be between " << MIN << " and " << MAX;
			throw common::OandaInvalidValue(ss.str());
		}
		m_value = value;
		m_isDirty = true;
	}

	void operator()(const std::string value) { set(value); }
	void operator()(int value) { set(value); }
	void operator=(const std::string value) { set(value); }
	void operator=(int value) { set(value); }

private:
	int m_value;
};

/**
 *
 */
template<bool DEFAULT>
class BooleanParameter: public BaseParameter {
public:
	explicit BooleanParameter(const std::string name, ParameterType type, OandaEndpointParameters& parameterManager):
		BaseParameter(name, type, parameterManager),
		m_value(DEFAULT) {}

	virtual ~BooleanParameter() = default;

	const std::string value() const override {
		return m_value ? "True" : "False";
	}

	void set(const bool value) {
		m_value = value;
		m_isDirty = true;
	}

	void operator()(const std::string value) { set(value); }
	void operator()(bool value) { set(value); }
	void operator=(const std::string value) { set(value); }
	void operator=(bool value) { set(value); }

private:
	int m_value;
};

/**
 *
 */
template<typename E>
class EnumParameter: public BaseParameter {
public:
	explicit EnumParameter(const std::string name, ParameterType type, OandaEndpointParameters& parameterManager):
		BaseParameter(name, type, parameterManager),
		m_value(E::UNDEFINED) {}

	virtual ~EnumParameter() = default;

	const std::string value() const override {
		if (m_value == E::UNDEFINED) {
			return "";
		} else {
			std::string tmp;
			to_string(m_value, tmp);
			return tmp;
		}
	}

	void set(const std::string& value) {
		E tmp;
		from_string(value, tmp);
		set(tmp);
	}

	void set(const E& value) {
		m_value = value;
		m_isDirty = true;
	}

	void operator()(const std::string& value) { set(value); }
	void operator()(const E& value) { set(value); }
	void operator=(const std::string& value) { set(value); }
	void operator=(const E& value) { set(value); }

private:
	E m_value;
};

/**
 *
 */
class AcceptDatetimeFormatParameter: public EnumParameter<primitives::AcceptDatetimeFormat> {
public:
	explicit AcceptDatetimeFormatParameter(const std::string name, ParameterType type, OandaEndpointParameters& parameterManager):
		EnumParameter(name, type, parameterManager) {}

	virtual ~AcceptDatetimeFormatParameter() = default;

	void operator=(const std::string value) { set(value); }
	void operator=(const primitives::AcceptDatetimeFormat value) { set(value); }
};

/**
 *
 */
class CandlestickGranularityParameter: public EnumParameter<instrument::CandlestickGranularity> {
public:
	explicit CandlestickGranularityParameter(const std::string name, ParameterType type, OandaEndpointParameters& parameterManager):
		EnumParameter(name, type, parameterManager) {}

	virtual ~CandlestickGranularityParameter() = default;

	void operator=(const std::string value) { set(value); }
	void operator=(const instrument::CandlestickGranularity value) { set(value); }
};

/**
 *
 */
class WeeklyAlignmentParameter: public EnumParameter<instrument::WeeklyAlignment> {
public:
	explicit WeeklyAlignmentParameter(const std::string name, ParameterType type, OandaEndpointParameters& parameterManager):
		EnumParameter(name, type, parameterManager) {}

	virtual ~WeeklyAlignmentParameter() = default;

	void operator=(const std::string value) { set(value); }
	void operator=(const instrument::WeeklyAlignment value) { set(value); }
};

/**
 *
 */
class DateTimeParameter: public BaseParameter {
public:
	using DateTimeDuration = std::chrono::duration<long double>;
	using DateTimePoint = std::chrono::time_point<std::chrono::system_clock, DateTimeDuration>;
	using SystemClockTimePoint = std::chrono::time_point<std::chrono::system_clock>;

public:
	///
	explicit DateTimeParameter(const std::string name, ParameterType type, OandaEndpointParameters& parameterManager);

	virtual ~DateTimeParameter() = default;

	const std::string value() const override;

	///
	void set(const SystemClockTimePoint& value);

//	const std::string operator()() { return get(); }
	void operator()(const SystemClockTimePoint& value);
	void operator=(const SystemClockTimePoint& value);
private:
	DateTimePoint m_value;
};

/**
 *
 */
class PricingComponentParameter: public BaseParameter {
public:
	using DateTimeDuration = std::chrono::duration<long double>;
	using DateTimePoint = std::chrono::time_point<std::chrono::system_clock, DateTimeDuration>;
	using SystemClockTimePoint = std::chrono::time_point<std::chrono::system_clock>;

public:
	///
	explicit PricingComponentParameter(const std::string name, ParameterType type, OandaEndpointParameters& parameterManager);

	virtual ~PricingComponentParameter() = default;

	const std::string value() const override;

	///
	void set(const primitives::PricingComponents& value);

//	const std::string operator()() { return get(); }
	void operator()(const primitives::PricingComponents& value);
	void operator=(const primitives::PricingComponents& value);
private:
	primitives::PricingComponents m_value;
};

/**
 *
 */
class OandaEndpointParameters
{
public:
	using Parameters = std::map<std::string, std::string>;
	using ParameterElement = std::pair<std::string, std::string>;

	using Parameter = StringParameter;

public:
	///
	explicit OandaEndpointParameters();

	///
	virtual ~OandaEndpointParameters() = default;

	///
	void registerParameter(const BaseParameter* parameter);

	///
	web::uri buildURI(const std::string origPath) const;

	///
	std::string value(std::string name) const;

	///
	const Parameters headers() const;

protected:
	//Parameters m_headers;
	//Parameters m_paths;
	//Parameters m_queries;
	std::vector<const BaseParameter*> m_parameters;

};

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_OANDAENDPOINTPARAMETERS_HPP_ */
