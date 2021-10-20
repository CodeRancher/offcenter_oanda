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
 * File: Candlestick.cpp
 * Author: Scott Brauer
 *
 * Mon 07 Dec 2020 07:45:08 PM MST
 */

#include "oanda/v20/json/JsonConversion.hpp"

#include "oanda/v20/json/JsonToFrom.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace instrument {

void to_json(nlohmann::json& j, const Candlestick& p) {
	j = nlohmann::json {
		{"time", p.time},
		{"bid", p.bid},
		{"ask", p.ask},
		{"mid", p.mid},
		{"volume", p.volume},
		{"complete", p.complete}
	};
}

void from_json(const nlohmann::json& j, Candlestick& p) {
	try {
		oanda::v20::json::convertJson(j, "time", p.time);
		oanda::v20::json::convertJson(j, "bid", p.bid);
		oanda::v20::json::convertJson(j, "ask", p.ask);
		oanda::v20::json::convertJson(j, "mid", p.mid);
		oanda::v20::json::convertJson(j, "volume", p.volume);
		oanda::v20::json::convertJson(j, "complete", p.complete);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}


} /* namespace instrument */
} /* namespace v20 */
} /* namespace oanda */
