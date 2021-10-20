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
 * @file   AccountChangesResponse.cpp
 * @author Scott Brauer
 * @date   01-13-2021
 */

#include "oanda/v20/json/JsonConversion.hpp"
using namespace oanda::v20::json;

#include "oanda/v20/json/ResponseJsonToFrom.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace account {

void to_json(nlohmann::json& j, const AccountChangesResponse& p) {
	j = nlohmann::json {
		{"changes", p.changes},
		{"state", p.state},
		{"lastTransactionID", p.lastTransactionID}
	};
}

void from_json(const nlohmann::json& j, AccountChangesResponse& p) {
	try {
		convertJson(j, "changes", p.changes);
		convertJson(j, "state", p.state);
		convertJson(j, "lastTransactionID", p.lastTransactionID);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}

} /* namespace account */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */
