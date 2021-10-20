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
 * @file   JsonConversion.cpp
 * @author Scott Brauer
 * @date   12-16-2020
 */

#include <iostream>
#include <type_traits>
#include <typeinfo>

#include "oanda/v20/json/JsonConversion.hpp"
#include "oanda/v20/json/exception/UnhandledNull.hpp"

namespace oanda {
namespace v20 {
namespace json {

template <>
void convertJson<std::string>(const nlohmann::json& j, const std::string& key, std::string& value)
{
	try {
		auto iter = j.find(key);
		if (iter != j.end()) {
			// If value is int, throw error because primitive int doesn't handle null
			if ((*iter).is_null()) {
				std::ostringstream ss;
				ss << "Json conversion of NULL not handled (" << key << ")";

				#ifdef LOG_V20_ACCESS
					LOG(ERROR) << ss.str();
				#endif

				throw oanda::v20::json::exception::UnhandledNull(ss.str());
			}

			value = *iter;
		} else {
			value = "";
		}
	} catch(nlohmann::json::exception& e) {
		#ifdef LOG_V20_ACCESS
			std::ostringstream ss;
			ss << e.what() << std::endl << "Value for (" << key << ") defaults to \"\"";
			LOG(ERROR) << ss.str();
		#endif
		value = "";
	}
}

template <>
void convertJson<oanda::v20::common::String>(const nlohmann::json& j, const std::string& key, oanda::v20::common::String& value)
{
	try {
		auto iter = j.find(key);
		if (iter != j.end()) {
			if ((*iter).is_null()) {
				value = nullptr;
			} else {
				(*iter).get_to(value);
			}
		} else {
			value = "";
		}
	} catch(nlohmann::json::exception& e) {
		#ifdef LOG_V20_ACCESS
			std::ostringstream ss;
			ss << e.what() << std::endl << "Value for (" << key << ") defaults to \"\"";
			LOG(ERROR) << ss.str();
		#endif
		value = "";
	}
}

template <>
void convertJson<int>(const nlohmann::json& j, const std::string& key, int& value)
{
	try {
		auto iter = j.find(key);
		if (iter != j.end()) {
			// If value is int, throw error because primitive int doesn't handle null
			if ((*iter).is_null()) {
				std::ostringstream ss;
				ss << "Json conversion of NULL not handled (" << key << ")";

				#ifdef LOG_V20_ACCESS
					LOG(ERROR) << ss.str();
				#endif

				throw oanda::v20::json::exception::UnhandledNull(ss.str());
			}

			value = *iter;
		} else {
			value = 0;
		}
	} catch(nlohmann::json::exception& e) {
		#ifdef LOG_V20_ACCESS
			std::ostringstream ss;
			ss << e.what() << std::endl << "Value for (" << key << ") defaults to 0";
			LOG(ERROR) << ss.str();
		#endif
		value = 0;
	}
}

template <>
void convertJson<bool>(const nlohmann::json& j, const std::string& key, bool& value)
{
	try {
		auto iter = j.find(key);
		if (iter != j.end()) {
			// If value is bool, throw error because primitive bool doesn't handle null
			if ((*iter).is_null()) {
				std::ostringstream ss;
				ss << "Json conversion of NULL not handled (" << key << ")";

				#ifdef LOG_V20_ACCESS
					LOG(ERROR) << ss.str();
				#endif

				throw oanda::v20::json::exception::UnhandledNull(ss.str());
			}

			value = *iter;
		} else {
			value = false;
		}
	} catch(nlohmann::json::exception& e) {
		#ifdef LOG_V20_ACCESS
			std::ostringstream ss;
			ss << e.what() << std::endl << "Value for (" << key << ") defaults to false";
			LOG(ERROR) << ss.str();
		#endif
		value = false;
	}
}

} /* namespace json */
} /* namespace v20 */
} /* namespace oanda */
