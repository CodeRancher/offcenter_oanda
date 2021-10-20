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
 * @file   Utility.hpp
 * @author Scott Brauer
 * @date   12-11-2020
 */

#ifndef OANDA_V20_COMMON_UTILITY_HPP_
#define OANDA_V20_COMMON_UTILITY_HPP_

#include <string>
#include <initializer_list>
#include <sstream>

#include <cpprest/base_uri.h>
#include <cpprest/http_headers.h>

namespace oanda {
namespace v20 {
namespace common {

/**
 * Join a list of strings
 *
 * @param elements A list of strings
 * @param sep An optional separator
 * @return all elements joined together separated by sep
 */
template<class Container>
std::string join(const Container& elements, const std::string sep = "")
{
	std::ostringstream ss;
	bool firstElement = true;
	for (auto element : elements) {
		ss << (!firstElement ? sep : "") << element;
		firstElement = false;
	}
	return ss.str();
}



//! Set of partial path elements to add to a uri
using RelativeURIPathElements = std::initializer_list<std::string>;
//! A key-value pair to add to a uri query section
using RelativeURIQueryElement = std::pair<std::string, std::string>;
//! A set of key-value pairs to add to a uri query section
using RelativeURIQueryElements = std::vector<RelativeURIQueryElement>;

/**
 * Create a relative uri for a set of path elements and query elements
 *
 * @param pathElements A list of path elements to append to the base uri from the Oanda Server.
 * @param queryElements A list of key-value pairs (RelativeURIQueryElement) that will be appended
 * 			to the query part of the uri.
 */
web::uri  relativeURI(RelativeURIPathElements pathElements, RelativeURIQueryElements queryElements = {});

/**
 * Search http_headers for key and place it's value into value
 *
 * @param h http headers to search
 * @param key key to search for in h
 * @param value where to place found value
 */
template <typename T>
void convertHttpHeader(const web::http::http_headers& h, const std::string& key, T& value)
{
	auto iter = h.find(key);
	if (iter != h.end()) {
		value = (*iter).second;
	} else {
		value = "";
	}
}

/**
 * Case insensitive string compare
 *
 * @param str1 first string to compare
 * @param str2 second string to compare
 * @return true is strings are equal, false otherwise
 */
bool stringCompareI(const std::string& str1, const std::string& str2);

/**
 * Convert string to upper case
 *
 * @param str string to upper case
 * @return copy of string converted to upper case
 */
std::string toUpper(const std::string& str);

/**
 * Convert string to lower case
 *
 * @param str string to lower case
 * @return copy of string converted to lower case
 */
std::string toLower(const std::string& str);

/**
 * Convert string to bool
 *
 * @param str string to convert to bool
 * @return bool conversion of string
 */
bool stringToBool(const std::string& str);

} /* namespace common */
} /* namespace v20 */
} /* namespace oanda */



#endif /* OANDA_V20_COMMON_UTILITY_HPP_ */
