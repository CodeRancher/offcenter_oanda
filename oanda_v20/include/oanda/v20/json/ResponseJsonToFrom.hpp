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
 * File: nlohmannResponseJson.hpp"
 * Author: Scott Brauer
 *
 * Mon 07 Dec 2020
 */

#ifndef OANDA_V20_JSON_RESPONSEJSONTOFROM_HPP
#define OANDA_V20_JSON_RESPONSEJSONTOFROM_HPP

#include <string>
#include <vector>
using namespace std;

#include <nlohmann/json.hpp>

/*
#include "oanda/v20/json/JsonToFrom.hpp"
#include "oanda/v20/endpoint/account/AccountsResponse.hpp"
#include "oanda/v20/endpoint/account/AccountResponse.hpp"
#include "oanda/v20/endpoint/account/AccountSummaryResponse.hpp"
#include "oanda/v20/endpoint/account/AccountInstrumentsResponse.hpp"
#include "oanda/v20/endpoint/account/AccountConfigurationResponse.hpp"
#include "oanda/v20/endpoint/account/AccountChangesResponse.hpp"
*/

namespace oanda {
namespace v20 {
namespace endpoint {

namespace account {

/*
// AccountsResponse
void to_json(nlohmann::json&, const oanda::v20::endpoint::account::AccountsResponse&); \
void from_json(const nlohmann::json&, oanda::v20::endpoint::account::AccountsResponse&);

// AccountResponse
void to_json(nlohmann::json&, const oanda::v20::endpoint::account::AccountResponse&); \
void from_json(const nlohmann::json&, oanda::v20::endpoint::account::AccountResponse&);

// AccountSummaryResponse
void to_json(nlohmann::json&, const oanda::v20::endpoint::account::AccountSummaryResponse&); \
void from_json(const nlohmann::json&, oanda::v20::endpoint::account::AccountSummaryResponse&);

// AccountInstrumentsResponse
void to_json(nlohmann::json&, const oanda::v20::endpoint::account::AccountInstrumentsResponse&); \
void from_json(const nlohmann::json&, oanda::v20::endpoint::account::AccountInstrumentsResponse&);

// AccountConfigurationResponse
void to_json(nlohmann::json&, const oanda::v20::endpoint::account::AccountConfigurationResponse&); \
void from_json(const nlohmann::json&, oanda::v20::endpoint::account::AccountConfigurationResponse&);

// AccountChangesResponse
void to_json(nlohmann::json&, const oanda::v20::endpoint::account::AccountChangesResponse&); \
void from_json(const nlohmann::json&, oanda::v20::endpoint::account::AccountChangesResponse&);
*/
} /* namespace account */

namespace instrument {

} /* namespace instrument */

namespace order {

} /* namespace order */

namespace position {

} /* namespace position */

namespace pricing {

} /* namespace pricing */

namespace pricing_common {

} /* namespace pricing_common */

namespace primitives {

} /* namespace primitives */

namespace trade {

} /* namespace trade */

namespace transaction {

} /* namespace transaction */

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_JSON_RESPONSEJSONTOFROM_HPP */
