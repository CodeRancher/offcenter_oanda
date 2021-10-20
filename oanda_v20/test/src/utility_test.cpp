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
 * @file   utility_test.hpp
 * @author Scott Brauer
 * @date   12-11-2020
 */

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <cpprest/base_uri.h>

#include "oanda/v20/common/Utility.hpp"
#include "oanda/v20/common/OandaCommonException.hpp"
using namespace oanda::v20;

TEST (Utility, join)
{

	EXPECT_EQ(common::join(std::vector<std::string>({"a","b","c"})), "abc");
	EXPECT_EQ(common::join(std::vector<std::string>({})), "");

	EXPECT_EQ(common::join(std::vector<std::string>({"a","b","c"}), ","), "a,b,c");
}

TEST (Utility, relativeURI)
{
	web::uri uri1 = common::relativeURI({"a/", "b/", "c"});
	EXPECT_EQ(uri1.to_string(), "/a/b/c");


	web::uri uri2 = common::relativeURI({}, {{"a", "1"}, {"b", "2"}});
	EXPECT_EQ(uri2.to_string(), "/?a=1&b=2");
}

TEST (Utility, StringCompareI)
{
	EXPECT_TRUE(common::stringCompareI("UNDEFINED", "UNDEFINED"));
	EXPECT_TRUE(common::stringCompareI("UNDEFINED", "undefined"));

	EXPECT_FALSE(common::stringCompareI("UNDEFINED", "UNDEFINE"));
	EXPECT_FALSE(common::stringCompareI("UNDEFINED", "abcdefghi"));
}

TEST (Utility, ToUpper)
{
	EXPECT_EQ(common::toUpper(""), "");
	EXPECT_EQ(common::toUpper("m"), "M");
	EXPECT_EQ(common::toUpper("M"), "M");
	EXPECT_EQ(common::toUpper("The Lazy brown Dog"), "THE LAZY BROWN DOG");
}

TEST (Utility, ToLower)
{
	EXPECT_EQ(common::toLower(""), "");
	EXPECT_EQ(common::toLower("m"), "m");
	EXPECT_EQ(common::toLower("M"), "m");
	EXPECT_EQ(common::toLower("The Lazy brown Dog"), "the lazy brown dog");
}

TEST (Utility, StringToBool)
{
	EXPECT_EQ(common::stringToBool("TRUE"), true);
	EXPECT_EQ(common::stringToBool("true"), true);
	EXPECT_EQ(common::stringToBool("FALSE"), false);
	EXPECT_EQ(common::stringToBool("false"), false);

	EXPECT_THROW(
			common::stringToBool(""),
			common::OandaInvalidType
	);

	EXPECT_THROW(
			common::stringToBool("GobbledyGook"),
			common::OandaInvalidType
	);
}

