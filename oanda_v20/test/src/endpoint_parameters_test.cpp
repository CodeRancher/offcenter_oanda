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
 * @file   endpoint_parameters_test.hpp
 * @author Scott Brauer
 * @date   01-15-2021
 */

#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

#include "oanda/v20/endpoint/OandaEndpointResponses.hpp"
#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"
#include "oanda/v20/common/OandaCommonException.hpp"
#include "OandaEndpointParametersFixture.hpp"
using namespace oanda::v20;

TEST (EndpointParameters, GetSet)
{
	endpoint::OandaEndpointResponses responses;

	EXPECT_EQ(responses.requestID.name(), "RequestID");
	EXPECT_EQ(responses.requestID.value(), "");
	EXPECT_EQ(responses.requestID.get(), "");
	EXPECT_EQ(responses.requestID(), "");

	std::string testValue = "TestValue";
	responses.requestID.set(testValue);
	EXPECT_EQ(responses.requestID.get(), testValue);

	testValue = "TestValue1";
	responses.requestID(testValue);
	EXPECT_EQ(responses.requestID.get(), testValue);

	testValue = "TestValue2";
	responses.requestID = testValue;
	EXPECT_EQ(responses.requestID.get(), testValue);
}

TEST (EndpointParameters, Copy)
{
	endpoint::OandaEndpointResponses response1;
	endpoint::OandaEndpointResponses response2 = response1;
	//EXPECT_EQ(response1.requestID, response2.requestID);
}

struct TestResponse: public oanda::v20::endpoint::OandaEndpointResponses
{
	explicit TestResponse():
		OandaEndpointResponses() {}

	std::vector<int> ints;
};

TEST (EndpointParameters, CopyInherited)
{
	TestResponse response1;
	TestResponse response2 = response1;
//	EXPECT_EQ(response1.requestID, response2.requestID);
}

#include <chrono>

time_t toUTC(std::tm& timeinfo)
{
#ifdef _WIN32
    std::time_t tt = _mkgmtime(&timeinfo);
#else
    time_t tt = timegm(&timeinfo);
#endif
    return tt;
}

std::chrono::system_clock::time_point
createDateTime(int year,
               int month,
               int day,
               int hour,
               int minute,
               int second) // these are UTC values
{
    tm timeinfo1 = tm();
    timeinfo1.tm_year = year - 1900;
    timeinfo1.tm_mon = month - 1;
    timeinfo1.tm_mday = day;
    timeinfo1.tm_hour = hour;
    timeinfo1.tm_min = minute;
    timeinfo1.tm_sec = second;
    tm timeinfo = timeinfo1;
    time_t tt = toUTC(timeinfo);
    return std::chrono::system_clock::from_time_t(tt);
}

TEST_F (OandaEndpointParametersFixture, BasicParameters)
{
	EXPECT_EQ(parameters.value(acceptDatetimeFormatParameterName), "");
	EXPECT_EQ(parameters.buildURI("/end").to_string(), "/end");

	parameters.acceptDatetimeFormatParameter.set(primitives::AcceptDatetimeFormat::UNIX);
	EXPECT_EQ(parameters.value(acceptDatetimeFormatParameterName), "UNIX");
	parameters.acceptDatetimeFormatParameter.set(primitives::AcceptDatetimeFormat::RFC3339);
	EXPECT_EQ(parameters.value(acceptDatetimeFormatParameterName), "RFC3339");
	parameters.acceptDatetimeFormatParameter.set(primitives::AcceptDatetimeFormat::UNDEFINED);
	EXPECT_EQ(parameters.value(acceptDatetimeFormatParameterName), "");

	const std::string dateTimeParameterURI = "/first";
	parameters.acceptDatetimeFormatParameter.set(primitives::AcceptDatetimeFormat::UNIX);
	parameters.dateTimeParameter.set(createDateTime(1970, 1, 1, 0, 0, 0));
	EXPECT_EQ(parameters.value(dateTimeParameterName), "0");
	EXPECT_EQ(parameters.buildURI(dateTimeParameterURI).to_string(), "/first?dateTimeParameter=0");
	parameters.dateTimeParameter.set(createDateTime(1970, 1, 1, 0, 0, 1));
	EXPECT_EQ(parameters.value(dateTimeParameterName), "1");
	EXPECT_EQ(parameters.buildURI(dateTimeParameterURI).to_string(), "/first?dateTimeParameter=1");
	parameters.dateTimeParameter.set(createDateTime(1970, 1, 1, 0, 1, 0));
	EXPECT_EQ(parameters.value(dateTimeParameterName), "60");
	EXPECT_EQ(parameters.buildURI(dateTimeParameterURI).to_string(), "/first?dateTimeParameter=60");

	parameters.acceptDatetimeFormatParameter.set(primitives::AcceptDatetimeFormat::RFC3339);
	parameters.dateTimeParameter.set(createDateTime(1970, 1, 1, 0, 0, 0));
	EXPECT_EQ(parameters.value(dateTimeParameterName), "1970-01-01T00:00:00.000000000Z");
	EXPECT_EQ(parameters.buildURI(dateTimeParameterURI).to_string(), "/first?dateTimeParameter=1970-01-01T00:00:00.000000000Z");
	parameters.dateTimeParameter.set(createDateTime(1970, 1, 1, 0, 0, 1));
	EXPECT_EQ(parameters.value(dateTimeParameterName), "1970-01-01T00:00:01.000000000Z");
	EXPECT_EQ(parameters.buildURI(dateTimeParameterURI).to_string(), "/first?dateTimeParameter=1970-01-01T00:00:01.000000000Z");
	parameters.dateTimeParameter.set(createDateTime(1971, 2, 3, 23, 59, 59));
	EXPECT_EQ(parameters.value(dateTimeParameterName), "1971-02-03T23:59:59.000000000Z");
	EXPECT_EQ(parameters.buildURI(dateTimeParameterURI).to_string(), "/first?dateTimeParameter=1971-02-03T23:59:59.000000000Z");
	parameters.acceptDatetimeFormatParameter.set(primitives::AcceptDatetimeFormat::UNDEFINED);
	EXPECT_EQ(parameters.value(dateTimeParameterName), "1971-02-03T23:59:59.000000000Z");
	EXPECT_EQ(parameters.buildURI(dateTimeParameterURI).to_string(), "/first?dateTimeParameter=1971-02-03T23:59:59.000000000Z");
}

TEST_F (OandaEndpointParametersFixture, PricingComponentParameters)
{
	const std::string uri = "/end";
	EXPECT_EQ(parameters.value(pricingComponentParameterName), "M");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end");

	primitives::PricingComponents pricingComponents;
	parameters.pricingComponentParameter.set(pricingComponents);
	EXPECT_EQ(parameters.value(pricingComponentParameterName), "M");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end?pricingComponentParameter=M");

	pricingComponents.set({primitives::PricingComponentElement::M, primitives::PricingComponentElement::B, primitives::PricingComponentElement::A});
	parameters.pricingComponentParameter.set(pricingComponents);
	EXPECT_EQ(parameters.value(pricingComponentParameterName), "MBA");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end?pricingComponentParameter=MBA");

	pricingComponents.set({primitives::PricingComponentElement::M, primitives::PricingComponentElement::B, primitives::PricingComponentElement::A});
	parameters.pricingComponentParameter.set(pricingComponents);
	EXPECT_EQ(parameters.value(pricingComponentParameterName), "MBA");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end?pricingComponentParameter=MBA");

	pricingComponents.set("MBA");
	parameters.pricingComponentParameter.set(pricingComponents);
	EXPECT_EQ(parameters.value(pricingComponentParameterName), "MBA");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end?pricingComponentParameter=MBA");
}

TEST_F (OandaEndpointParametersFixture, CandlestickGranularityParameter)
{
	const std::string uri = "/end";
	EXPECT_EQ(parameters.value(candlestickGranularityParameterName), "");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end");

	parameters.candlestickGranularityParameter.set(instrument::CandlestickGranularity::S5);
	EXPECT_EQ(parameters.value(candlestickGranularityParameterName), "S5");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end?candlestickGranularityParameter=S5");

	parameters.candlestickGranularityParameter.set(instrument::CandlestickGranularity::M);
	EXPECT_EQ(parameters.value(candlestickGranularityParameterName), "M");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end?candlestickGranularityParameter=M");

	parameters.candlestickGranularityParameter.set(instrument::CandlestickGranularity::UNDEFINED);
	EXPECT_EQ(parameters.value(candlestickGranularityParameterName), "");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end?candlestickGranularityParameter=");
}

TEST_F (OandaEndpointParametersFixture, IntegerParameter)
{
	const std::string uri = "/end";
	EXPECT_EQ(parameters.value(integerParameterName), "50");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end");

	parameters.integerParameter.set("0");
	EXPECT_EQ(parameters.value(integerParameterName), "0");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end?integerParameter=0");

	parameters.integerParameter.set("100");
	EXPECT_EQ(parameters.value(integerParameterName), "100");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end?integerParameter=100");

	EXPECT_THROW(
			parameters.integerParameter.set("101"),
			common::OandaInvalidValue
	);
}

TEST_F (OandaEndpointParametersFixture, BooleanParameter)
{
	const std::string uri = "/end";
	EXPECT_EQ(parameters.value(booleanParameterName), "False");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end");

	parameters.booleanParameter.set(true);
	EXPECT_EQ(parameters.value(booleanParameterName), "True");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end?booleanParameter=True");

	parameters.booleanParameter.set(false);
	EXPECT_EQ(parameters.value(booleanParameterName), "False");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end?booleanParameter=False");
}

TEST_F (OandaEndpointParametersFixture, WeeklyAlignmentParameter)
{
	const std::string uri = "/end";
	EXPECT_EQ(parameters.value(weeklyAlignmentParameterName), "");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end");

	parameters.weeklyAlignmentParameter.set(instrument::WeeklyAlignment::Sunday);
	EXPECT_EQ(parameters.value(weeklyAlignmentParameterName), "Sunday");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end?weeklyAlignmentParameter=Sunday");

	parameters.weeklyAlignmentParameter.set(instrument::WeeklyAlignment::Saturday);
	EXPECT_EQ(parameters.value(weeklyAlignmentParameterName), "Saturday");
	EXPECT_EQ(parameters.buildURI(uri).to_string(), "/end?weeklyAlignmentParameter=Saturday");

	EXPECT_THROW(
			parameters.weeklyAlignmentParameter.set("BadValue"),
			common::OandaInvalidValue
	);
}
