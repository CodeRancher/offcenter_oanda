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
 * File: UnitsAvailableDetails.cpp
 * Author: Scott Brauer
 *
 * Mon 07 Dec 2020 07:45:09 PM MST
 */

#include "oanda/v20/json/JsonConversion.hpp"

#include "oanda/v20/json/JsonToFrom.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace order {

void to_json(nlohmann::json& j, const UnitsAvailableDetails& p) {
	j = nlohmann::json {
		{"long", p.longVal},
		{"short", p.shortVal}
	};
}

void from_json(const nlohmann::json& j, UnitsAvailableDetails& p) {
	try {
		oanda::v20::json::convertJson(j, "long", p.longVal);
		oanda::v20::json::convertJson(j, "short", p.shortVal);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}


} /* namespace order */
} /* namespace v20 */
} /* namespace oanda */
