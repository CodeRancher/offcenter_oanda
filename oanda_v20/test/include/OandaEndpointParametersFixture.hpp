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
 * @file   OandaEndpointParametersFixture.hpp
 * @author Scott Brauer
 * @date   03-10-2021
 */

#ifndef OANDAENDPOINTPARAMETERSFIXTURE_HPP_
#define OANDAENDPOINTPARAMETERSFIXTURE_HPP_

#include <gtest/gtest.h>

#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"
using namespace oanda::v20;

class OandaEndpointParametersFixture : public ::testing::Test
{
public:
	OandaEndpointParametersFixture();
	virtual ~OandaEndpointParametersFixture();

	static const std::string acceptDatetimeFormatParameterName;
	static const std::string dateTimeParameterName;
	static const std::string pricingComponentParameterName;
	static const std::string candlestickGranularityParameterName;
	static const std::string integerParameterName;
	static const std::string booleanParameterName;
	static const std::string weeklyAlignmentParameterName;

	class Parameters: public endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDatetimeFormatParameter(acceptDatetimeFormatParameterName, endpoint::ParameterType::HEADER, *this),
			dateTimeParameter(dateTimeParameterName, endpoint::ParameterType::QUERY, *this),
			pricingComponentParameter(pricingComponentParameterName, endpoint::ParameterType::QUERY, *this),
			candlestickGranularityParameter(candlestickGranularityParameterName, endpoint::ParameterType::QUERY, *this),
			integerParameter(integerParameterName, endpoint::ParameterType::QUERY, *this),
			booleanParameter(booleanParameterName, endpoint::ParameterType::QUERY, *this),
			weeklyAlignmentParameter(weeklyAlignmentParameterName, endpoint::ParameterType::QUERY, *this)
		{}

		endpoint::AcceptDatetimeFormatParameter acceptDatetimeFormatParameter;
		endpoint::DateTimeParameter dateTimeParameter;
		endpoint::PricingComponentParameter pricingComponentParameter;
		endpoint::CandlestickGranularityParameter candlestickGranularityParameter;
		endpoint::IntegerParameter<0, 50, 100> integerParameter;
		endpoint::BooleanParameter<false> booleanParameter;
		endpoint::WeeklyAlignmentParameter weeklyAlignmentParameter;
	};

	Parameters parameters;

};

#endif /* OANDAENDPOINTPARAMETERSFIXTURE_HPP_ */
