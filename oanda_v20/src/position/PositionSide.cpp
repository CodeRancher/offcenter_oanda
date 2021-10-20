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
 * File: PositionSide.cpp
 * Author: Scott Brauer
 *
 * Mon 07 Dec 2020 07:45:09 PM MST
 */

#include "oanda/v20/json/JsonConversion.hpp"

#include "oanda/v20/json/JsonToFrom.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace position {

void to_json(nlohmann::json& j, const PositionSide& p) {
	j = nlohmann::json {
		{"units", p.units},
		{"averagePrice", p.averagePrice},
		{"tradeIDs", p.tradeIDs},
		{"pl", p.pl},
		{"unrealizedPL", p.unrealizedPL},
		{"resettablePL", p.resettablePL},
		{"financing", p.financing},
		{"dividendAdjustment", p.dividendAdjustment},
		{"guaranteedExecutionFees", p.guaranteedExecutionFees}
	};
}

void from_json(const nlohmann::json& j, PositionSide& p) {
	try {
		oanda::v20::json::convertJson(j, "units", p.units);
		oanda::v20::json::convertJson(j, "averagePrice", p.averagePrice);
		oanda::v20::json::convertJson(j, "tradeIDs", p.tradeIDs);
		oanda::v20::json::convertJson(j, "pl", p.pl);
		oanda::v20::json::convertJson(j, "unrealizedPL", p.unrealizedPL);
		oanda::v20::json::convertJson(j, "resettablePL", p.resettablePL);
		oanda::v20::json::convertJson(j, "financing", p.financing);
		oanda::v20::json::convertJson(j, "dividendAdjustment", p.dividendAdjustment);
		oanda::v20::json::convertJson(j, "guaranteedExecutionFees", p.guaranteedExecutionFees);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}

} /* namespace position */
} /* namespace v20 */
} /* namespace oanda */
