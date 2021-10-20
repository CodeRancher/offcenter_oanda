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
 * File: Instrument.cpp
 * Author: Scott Brauer
 *
 * Mon 07 Dec 2020 07:45:11 PM MST
 */

#include "oanda/v20/json/JsonConversion.hpp"

#include "oanda/v20/json/JsonToFrom.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace primitives {

void to_json(nlohmann::json& j, const Instrument& p) {
	j = nlohmann::json {
		{"name", p.name},
		{"type", p.type},
		{"displayName", p.displayName},
		{"pipLocation", p.pipLocation},
		{"displayPrecision", p.displayPrecision},
		{"tradeUnitsPrecision", p.tradeUnitsPrecision},
		{"minimumTradeSize", p.minimumTradeSize},
		{"maximumTrailingStopDistance", p.maximumTrailingStopDistance},
		{"minimumGuaranteedStopLossDistance", p.minimumGuaranteedStopLossDistance},
		{"minimumTrailingStopDistance", p.minimumTrailingStopDistance},
		{"maximumPositionSize", p.maximumPositionSize},
		{"maximumOrderUnits", p.maximumOrderUnits},
		{"marginRate", p.marginRate},
		{"commission", p.commission},
		{"guaranteedStopLossOrderMode", p.guaranteedStopLossOrderMode},
		{"guaranteedStopLossOrderExecutionPremium", p.guaranteedStopLossOrderExecutionPremium},
		{"guaranteedStopLossOrderLevelRestriction", p.guaranteedStopLossOrderLevelRestriction},
		{"financing", p.financing},
		{"tags", p.tags}
	};
}

void from_json(const nlohmann::json& j, Instrument& p) {
	try {
		oanda::v20::json::convertJson(j, "name", p.name);
		oanda::v20::json::convertJson(j, "type", p.type);
		oanda::v20::json::convertJson(j, "displayName", p.displayName);
		oanda::v20::json::convertJson(j, "pipLocation", p.pipLocation);
		oanda::v20::json::convertJson(j, "displayPrecision", p.displayPrecision);
		oanda::v20::json::convertJson(j, "tradeUnitsPrecision", p.tradeUnitsPrecision);
		oanda::v20::json::convertJson(j, "minimumTradeSize", p.minimumTradeSize);
		oanda::v20::json::convertJson(j, "maximumTrailingStopDistance", p.maximumTrailingStopDistance);
		oanda::v20::json::convertJson(j, "minimumGuaranteedStopLossDistance", p.minimumGuaranteedStopLossDistance);
		oanda::v20::json::convertJson(j, "minimumTrailingStopDistance", p.minimumTrailingStopDistance);
		oanda::v20::json::convertJson(j, "maximumPositionSize", p.maximumPositionSize);
		oanda::v20::json::convertJson(j, "maximumOrderUnits", p.maximumOrderUnits);
		oanda::v20::json::convertJson(j, "marginRate", p.marginRate);
		oanda::v20::json::convertJson(j, "commission", p.commission);
		oanda::v20::json::convertJson(j, "guaranteedStopLossOrderMode", p.guaranteedStopLossOrderMode);
		oanda::v20::json::convertJson(j, "guaranteedStopLossOrderExecutionPremium", p.guaranteedStopLossOrderExecutionPremium);
		oanda::v20::json::convertJson(j, "guaranteedStopLossOrderLevelRestriction", p.guaranteedStopLossOrderLevelRestriction);
		oanda::v20::json::convertJson(j, "financing", p.financing);
		oanda::v20::json::convertJson(j, "tags", p.tags);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}


} /* namespace primitives */
} /* namespace v20 */
} /* namespace oanda */
