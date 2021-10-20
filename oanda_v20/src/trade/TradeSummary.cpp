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
 * File: TradeSummary.cpp
 * Author: Scott Brauer
 *
 * Mon 07 Dec 2020 07:45:09 PM MST
 */

#include "oanda/v20/json/JsonConversion.hpp"

#include "oanda/v20/json/JsonToFrom.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace trade {

void to_json(nlohmann::json& j, const TradeSummary& p) {
	j = nlohmann::json {
		{"id", p.id},
		{"instrument", p.instrument},
		{"price", p.price},
		{"openTime", p.openTime},
		{"state", p.state},
		{"initialUnits", p.initialUnits},
		{"initialMarginRequired", p.initialMarginRequired},
		{"currentUnits", p.currentUnits},
		{"realizedPL", p.realizedPL},
		{"unrealizedPL", p.unrealizedPL},
		{"marginUsed", p.marginUsed},
		{"averageClosePrice", p.averageClosePrice},
		{"closingTransactionIDs", p.closingTransactionIDs},
		{"financing", p.financing},
		{"dividendAdjustment", p.dividendAdjustment},
		{"closeTime", p.closeTime},
		{"clientExtensions", p.clientExtensions},
		{"takeProfitOrderID", p.takeProfitOrderID},
		{"stopLossOrderID", p.stopLossOrderID},
		{"guaranteedStopLossOrderID", p.guaranteedStopLossOrderID},
		{"trailingStopLossOrderID", p.trailingStopLossOrderID}
	};
}

void from_json(const nlohmann::json& j, TradeSummary& p) {
	try {
		oanda::v20::json::convertJson(j, "id", p.id);
		oanda::v20::json::convertJson(j, "instrument", p.instrument);
		oanda::v20::json::convertJson(j, "price", p.price);
		oanda::v20::json::convertJson(j, "openTime", p.openTime);
		oanda::v20::json::convertJson(j, "state", p.state);
		oanda::v20::json::convertJson(j, "initialUnits", p.initialUnits);
		oanda::v20::json::convertJson(j, "initialMarginRequired", p.initialMarginRequired);
		oanda::v20::json::convertJson(j, "currentUnits", p.currentUnits);
		oanda::v20::json::convertJson(j, "realizedPL", p.realizedPL);
		oanda::v20::json::convertJson(j, "unrealizedPL", p.unrealizedPL);
		oanda::v20::json::convertJson(j, "marginUsed", p.marginUsed);
		oanda::v20::json::convertJson(j, "averageClosePrice", p.averageClosePrice);
		oanda::v20::json::convertJson(j, "closingTransactionIDs", p.closingTransactionIDs);
		oanda::v20::json::convertJson(j, "financing", p.financing);
		oanda::v20::json::convertJson(j, "dividendAdjustment", p.dividendAdjustment);
		oanda::v20::json::convertJson(j, "closeTime", p.closeTime);
		oanda::v20::json::convertJson(j, "clientExtensions", p.clientExtensions);
		oanda::v20::json::convertJson(j, "takeProfitOrderID", p.takeProfitOrderID);
		oanda::v20::json::convertJson(j, "stopLossOrderID", p.stopLossOrderID);
		oanda::v20::json::convertJson(j, "guaranteedStopLossOrderID", p.guaranteedStopLossOrderID);
		oanda::v20::json::convertJson(j, "trailingStopLossOrderID", p.trailingStopLossOrderID);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}


} /* namespace trade */
} /* namespace v20 */
} /* namespace oanda */
