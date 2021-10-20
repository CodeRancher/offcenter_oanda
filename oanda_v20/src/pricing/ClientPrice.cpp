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
 * File: ClientPrice.cpp
 * Author: Scott Brauer
 *
 * Mon 07 Dec 2020 07:45:10 PM MST
 */

#include "oanda/v20/json/JsonConversion.hpp"

#include "oanda/v20/json/JsonToFrom.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace pricing {

void to_json(nlohmann::json& j, const ClientPrice& p) {
	j = nlohmann::json {
		{"type", p.type},
		{"instrument", p.instrument},
		{"time", p.time},
		{"status", p.status},
		{"tradeable", p.tradeable},
		{"bids", p.bids},
		{"asks", p.asks},
		{"closeoutBid", p.closeoutBid},
		{"closeoutAsk", p.closeoutAsk},
		{"quoteHomeConversionFactors", p.quoteHomeConversionFactors},
		{"unitsAvailable", p.unitsAvailable}
	};
}

void from_json(const nlohmann::json& j, ClientPrice& p) {
	try {
		oanda::v20::json::convertJson(j, "type", p.type);
		oanda::v20::json::convertJson(j, "instrument", p.instrument);
		oanda::v20::json::convertJson(j, "time", p.time);
		oanda::v20::json::convertJson(j, "status", p.status);
		oanda::v20::json::convertJson(j, "tradeable", p.tradeable);
		oanda::v20::json::convertJson(j, "bids", p.bids);
		oanda::v20::json::convertJson(j, "asks", p.asks);
		oanda::v20::json::convertJson(j, "closeoutBid", p.closeoutBid);
		oanda::v20::json::convertJson(j, "closeoutAsk", p.closeoutAsk);
		oanda::v20::json::convertJson(j, "quoteHomeConversionFactors", p.quoteHomeConversionFactors);
		oanda::v20::json::convertJson(j, "unitsAvailable", p.unitsAvailable);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}


} /* namespace pricing */
} /* namespace v20 */
} /* namespace oanda */
