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
 * @file   string_test.hpp
 * @author Scott Brauer
 * @date   01-21-2020
 */

#include <string>

#include <gtest/gtest.h>

#include "oanda/v20/common/String.hpp"

class CreateStringTestFixture :public ::testing::TestWithParam<oanda::v20::common::String> {
};

TEST_P(CreateStringTestFixture, BasicCreation) {
	const oanda::v20::common::String& s = GetParam();
	EXPECT_FALSE(s.isDirty());
	EXPECT_FALSE(s.isNull());
}

INSTANTIATE_TEST_SUITE_P(
	BasicCreationTests,
	CreateStringTestFixture,
	::testing::Values(
		oanda::v20::common::String(),
		oanda::v20::common::String(std::string("Test Value")),
		oanda::v20::common::String(oanda::v20::common::String("Test Value")),
		oanda::v20::common::String(std::string("Test Value", 4, 4)),
		oanda::v20::common::String("Test Value"),
		oanda::v20::common::String("Test Value", 4),
		oanda::v20::common::String(5, 'c'),
		oanda::v20::common::String({'v','a','l'}),
		oanda::v20::common::String(std::string("Test Value"))
	)
);

TEST (String, BasicCreation)
{
	oanda::v20::common::String nullPtrVal(nullptr);
	EXPECT_FALSE(nullPtrVal.isDirty());
	EXPECT_TRUE(nullPtrVal.isNull());
}

TEST (String, SetEmptyValue)
{
	{
		oanda::v20::common::String val;
		val = std::string("");
		EXPECT_FALSE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	{
		oanda::v20::common::String val;
		val = oanda::v20::common::String("");
		EXPECT_FALSE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	{
		oanda::v20::common::String val;
		val = "";
		EXPECT_FALSE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	// Skipping setting char. This test is about empty strings

	{
		oanda::v20::common::String val;
		val = {};
		EXPECT_FALSE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	{
		std::string&& set = "";
		oanda::v20::common::String val;
		val = set;
		EXPECT_FALSE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	{
		oanda::v20::common::String&& set = "";
		oanda::v20::common::String val;
		val = set;
		EXPECT_FALSE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	{
		oanda::v20::common::String val(nullptr);
		val = nullptr;
		EXPECT_FALSE(val.isDirty());
		EXPECT_TRUE(val.isNull());
	}

	{
		oanda::v20::common::String val;
		val = nullptr;
		EXPECT_TRUE(val.isDirty());
		EXPECT_TRUE(val.isNull());
	}
}

TEST (String, SetValue)
{
	{
		oanda::v20::common::String val;
		val = std::string("M");
		EXPECT_TRUE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	{
		oanda::v20::common::String val;
		val = oanda::v20::common::String("M");
		EXPECT_TRUE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	{
		oanda::v20::common::String val;
		val = "M";
		EXPECT_TRUE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	// Skipping setting char. This test is about empty strings

	{
		oanda::v20::common::String val;
		val = {'M'};
		EXPECT_TRUE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	{
		std::string&& set = "M";
		oanda::v20::common::String val;
		val = set;
		EXPECT_TRUE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	{
		oanda::v20::common::String&& set = "M";
		oanda::v20::common::String val;
		val = set;
		EXPECT_TRUE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	{
		oanda::v20::common::String val(nullptr);
		val = "M";
		EXPECT_TRUE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}
}

TEST (String, SetFromNullValue)
{
	{
		oanda::v20::common::String val(nullptr);
		val = std::string("M");
		EXPECT_TRUE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	{
		oanda::v20::common::String val(nullptr);
		val = oanda::v20::common::String("M");
		EXPECT_TRUE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	{
		oanda::v20::common::String val(nullptr);
		val = "M";
		EXPECT_TRUE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	// Skipping setting char. This test is about empty strings

	{
		std::string&& set = "M";
		oanda::v20::common::String val(nullptr);
		val = set;
		EXPECT_TRUE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}

	{
		oanda::v20::common::String&& set = "M";
		oanda::v20::common::String val(nullptr);
		val = set;
		EXPECT_TRUE(val.isDirty());
		EXPECT_FALSE(val.isNull());
	}
}
