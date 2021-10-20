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
 * @file   json_test.cpp
 * @author Scott Brauer
 * @date   01-29-2021
 */

#include <gtest/gtest.h>

#include "oanda/v20/json/JsonConversion.hpp"
#include "oanda/v20/common/String.hpp"
using namespace oanda::v20;

TEST (Json, ConvertJson)
{
	nlohmann::json j = {
		{"radius", 123},
		{"happy", true},
		{"name", "Niels"},
		{"nothing", nullptr}
	};

	int radius;
	json::convertJson(j, "radius", radius);
	EXPECT_EQ(radius, 123);

	bool happy;
	json::convertJson(j, "happy", happy);
	EXPECT_EQ(happy, true);

	/*
	std::string name;
	json::convertJson(j, "name", name);
	EXPECT_EQ(name, "Niels");

	std::string nothing;
	json::convertJson(j, "nothing", nothing);
	//EXPECT_EQ(nothing, nullptr);
	*/

	common::String nameS;
	json::convertJson(j, "name", nameS);
	EXPECT_EQ(nameS, "Niels");

	common::String nothingS;
	json::convertJson(j, "nothing", nothingS);
	//EXPECT_EQ(nothingS, nullptr);
}

#ifdef NOT_USED
class ConvertJsonTestFixture :public ::testing::TestWithParam<nlohmann::json> {
//protected:
    //LeapYearCalendar leapYearCalendar;
};

TEST_P(ConvertJsonTestFixture, OddYearsAreNotLeapYears) {
	const nlohmann::json& j = GetParam();
	std::cout << "is_primitive: " << j.is_primitive() << std::endl;
	std::cout << "is_structured: " << j.is_structured() << std::endl;
	std::cout << "is_null: " << j.is_null() << std::endl;
	std::cout << "is_boolean: " << j.is_boolean() << std::endl;
	std::cout << "is_number: " << j.is_number() << std::endl;
	std::cout << "is_number_integer: " << j.is_number_integer() << std::endl;
	std::cout << "is_number_unsigned: " << j.is_number_unsigned() << std::endl;
	std::cout << "is_number_float: " << j.is_number_float() << std::endl;
	std::cout << "is_object: " << j.is_object() << std::endl;
	std::cout << "is_array: " << j.is_array() << std::endl;
	std::cout << "is_string: " << j.is_string() << std::endl;
	std::cout << "is_discarded: " << j.is_discarded() << std::endl;
	std::cout << "is_binary: " << j.is_binary() << std::endl;

	int intValue;
	json::convertJson(j, "value", intValue);
	EXPECT_EQ(intValue, j["value"]);

	/*
	bool boolValue;
	json::convertJson(j, "value", boolValue);
	EXPECT_EQ(boolValue, j["value"]);
	*/

	std::string stringValue;
	json::convertJson(j, "value", stringValue);
	EXPECT_EQ(stringValue, j["value"]);

	common::String commonStringValue;
	json::convertJson(j, "value", commonStringValue);
	EXPECT_EQ(commonStringValue, j["value"]);
}

INSTANTIATE_TEST_SUITE_P(
	LeapYearTests,
	ConvertJsonTestFixture,
	::testing::Values(
		R"({"value": 123})"_json,
		R"({"value": 3.141})"_json,
		//R"({"value": true})"_json,
		R"({"value": "Niels"})"_json,
		R"({"value": null})"_json
	)
);

#endif


