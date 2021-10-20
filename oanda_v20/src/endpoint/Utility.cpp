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
 * @file   Utility.cpp
 * @author Scott Brauer
 * @date   12-11-2020
 */

#include <sstream>
#include <algorithm>
#include <iterator>

#include <cpprest/uri_builder.h>

#include "oanda/v20/common/Utility.hpp"
#include "oanda/v20/common/OandaCommonException.hpp"

namespace oanda {
namespace v20 {
namespace common {

web::uri relativeURI(RelativeURIPathElements pathElements, RelativeURIQueryElements queryElements)
{
	web::uri_builder builder;

	for (std::string pathElement : pathElements) {
		builder.append_path(pathElement);
	}

	for (RelativeURIQueryElement queryElement : queryElements) {
		builder.append_query(queryElement.first, queryElement.second);
	}

	return builder.to_uri();
}

/*
 * Case insensitive string compare
 */
bool stringCompareI(const std::string& str1, const std::string& str2)
{
    return (
    		(str1.size() == str2.size())
    		&& std::equal(str1.begin(), str1.end(), str2.begin(), [](const char& c1, const char& c2) {
    			return (c1 == c2 || std::toupper(c1) == std::toupper(c2));
           }));
}

/** Return string as uppercase
 *  @param str string to uppercase
 *  @return uppercase version of str
 */
std::string toUpper(const std::string& str)
{
	std::string upperStr;
	upperStr.resize(str.length());
	std::transform(str.begin(), str.end(), upperStr.begin(),
			[](unsigned char c) -> unsigned char { return std::toupper(c); });
	return upperStr;
}

/** Return string as lowercase
 *  @param str string to lowercase
 *  @return lowercase version of str
 */
std::string toLower(const std::string& str)
{
	std::string lowerStr;
	lowerStr.resize(str.length());
	std::transform(str.begin(), str.end(), lowerStr.begin(),
			[](unsigned char c) -> unsigned char { return std::tolower(c); });
	return lowerStr;
}

// Convert string to bool
bool stringToBool(const std::string& str)
{
	static std::map<std::string, bool> lookup = {
			{"TRUE", true},
			{"FALSE", false}
	};

	try {
		return lookup.at(toUpper(str));
	} catch(std::out_of_range& e) {
		std::string msg("Unknown boolean string (");
		msg += str;
		msg += ")";
		throw common::OandaInvalidType(msg);
	}
}

} /* namespace common */
} /* namespace v20 */
} /* namespace oanda */
