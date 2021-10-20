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

/*
 * @file   JsonConversion.hpp
 * @author Scott Brauer
 * @date   12-16-2020
 */

#ifndef OANDA_V20_JSON_JSONCONVERSION_HPP_
#define OANDA_V20_JSON_JSONCONVERSION_HPP_

#include <string>
#include <sstream>
#include <iostream>

#include <nlohmann/json.hpp>

#ifdef LOG_V20_ACCESS
	#include "easylogging++.h"
#endif

#include "oanda/v20/common/String.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"
#include "oanda/v20/json/exception/UnhandledNull.hpp"

namespace oanda {
namespace v20 {
namespace json {

template <typename JV, typename V>
void setJson(const JV& jsonValue, V& value)
{
	value = jsonValue;
}

template <typename T>
void convertJson(const nlohmann::json& j, const std::string& key, T& value)
{
	try {
		if (j.contains(key)) {
			auto element = j.at(key);
			if (element.is_null()) {
				#ifdef LOG_V20_ACCESS
					LOG(WARNING) << "convertToJson: Element at key (" << key << ") is null";
				#endif
				value = T();
			} else {
				element.get_to(value);
			}
		} else {
			//#ifdef LOG_V20_ACCESS
			//	LOG(WARNING) << "convertToJson: Unable to find key: " << key;
			//#endif
			value = T();
		}
	} catch(nlohmann::json::exception& e) {
		#ifdef LOG_V20_ACCESS
			LOG(ERROR) << "*** Error on key (" << key << ") *********************************" << std::endl <<
					"Exception: " << e.what() << std::endl <<
					"Json:      " << j.dump(4) << std::endl <<
					"******************************************************************";
		#endif
		value = T();
	}
}

template <>
void convertJson<std::string>(const nlohmann::json& j, const std::string& key, std::string& value);

template <>
void convertJson<oanda::v20::common::String>(const nlohmann::json& j, const std::string& key, oanda::v20::common::String& value);

template <>
void convertJson<int>(const nlohmann::json& j, const std::string& key, int& value);

template <>
void convertJson<bool>(const nlohmann::json& j, const std::string& key, bool& value);

} /* namespace json */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_JSON_JSONCONVERSION_HPP_ */
