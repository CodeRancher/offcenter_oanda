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
 * File: AccumulatedAccountState.cpp
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

void to_json(nlohmann::json& j, const AccumulatedAccountState& p) {
	j = nlohmann::json {
		{"balance", p.balance},
		{"pl", p.pl},
		{"resettablePL", p.resettablePL},
		{"financing", p.financing},
		{"commission", p.commission},
		{"dividendAdjustment", p.dividendAdjustment},
		{"guaranteedExecutionFees", p.guaranteedExecutionFees},
		{"marginCallEnterTime", p.marginCallEnterTime},
		{"marginCallExtensionCount", p.marginCallExtensionCount},
		{"lastMarginCallExtensionTime", p.lastMarginCallExtensionTime}
	};
}

void from_json(const nlohmann::json& j, AccumulatedAccountState& p) {
	try {
		oanda::v20::json::convertJson(j, "balance", p.balance);
		oanda::v20::json::convertJson(j, "pl", p.pl);
		oanda::v20::json::convertJson(j, "resettablePL", p.resettablePL);
		oanda::v20::json::convertJson(j, "financing", p.financing);
		oanda::v20::json::convertJson(j, "commission", p.commission);
		oanda::v20::json::convertJson(j, "dividendAdjustment", p.dividendAdjustment);
		oanda::v20::json::convertJson(j, "guaranteedExecutionFees", p.guaranteedExecutionFees);
		oanda::v20::json::convertJson(j, "marginCallEnterTime", p.marginCallEnterTime);
		oanda::v20::json::convertJson(j, "marginCallExtensionCount", p.marginCallExtensionCount);
		oanda::v20::json::convertJson(j, "lastMarginCallExtensionTime", p.lastMarginCallExtensionTime);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}


} /* namespace account */
} /* namespace v20 */
} /* namespace oanda */
