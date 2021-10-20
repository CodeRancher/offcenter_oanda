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
 * File: UserAttributes.cpp
 * Author: Scott Brauer
 *
 * Mon 07 Dec 2020 07:45:08 PM MST
 */

#include "oanda/v20/json/JsonConversion.hpp"

#include "oanda/v20/json/JsonToFrom.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace account {

void to_json(nlohmann::json& j, const UserAttributes& p) {
	j = nlohmann::json {
		{"userID", p.userID},
		{"username", p.username},
		{"title", p.title},
		{"name", p.name},
		{"email", p.email},
		{"divisionAbbreviation", p.divisionAbbreviation},
		{"languageAbbreviation", p.languageAbbreviation},
		{"homeCurrency", p.homeCurrency}
	};
}

void from_json(const nlohmann::json& j, UserAttributes& p) {
	try {
		oanda::v20::json::convertJson(j, "userID", p.userID);
		oanda::v20::json::convertJson(j, "username", p.username);
		oanda::v20::json::convertJson(j, "title", p.title);
		oanda::v20::json::convertJson(j, "name", p.name);
		oanda::v20::json::convertJson(j, "email", p.email);
		oanda::v20::json::convertJson(j, "divisionAbbreviation", p.divisionAbbreviation);
		oanda::v20::json::convertJson(j, "languageAbbreviation", p.languageAbbreviation);
		oanda::v20::json::convertJson(j, "homeCurrency", p.homeCurrency);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}


} /* namespace account */
} /* namespace v20 */
} /* namespace oanda */
