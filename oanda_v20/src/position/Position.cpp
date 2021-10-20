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
 * File: Position.cpp
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

void to_json(nlohmann::json& j, const Position& p) {
	j = nlohmann::json {
		{"instrument", p.instrument},
		{"pl", p.pl},
		{"unrealizedPL", p.unrealizedPL},
		{"marginUsed", p.marginUsed},
		{"resettablePL", p.resettablePL},
		{"financing", p.financing},
		{"commission", p.commission},
		{"dividendAdjustment", p.dividendAdjustment},
		{"guaranteedExecutionFees", p.guaranteedExecutionFees},
		{"long", p.longVal},
		{"short", p.shortVal}
	};
}

void from_json(const nlohmann::json& j, Position& p) {
	try {
		oanda::v20::json::convertJson(j, "instrument", p.instrument);
		oanda::v20::json::convertJson(j, "pl", p.pl);
		oanda::v20::json::convertJson(j, "unrealizedPL", p.unrealizedPL);
		oanda::v20::json::convertJson(j, "marginUsed", p.marginUsed);
		oanda::v20::json::convertJson(j, "resettablePL", p.resettablePL);
		oanda::v20::json::convertJson(j, "financing", p.financing);
		oanda::v20::json::convertJson(j, "commission", p.commission);
		oanda::v20::json::convertJson(j, "dividendAdjustment", p.dividendAdjustment);
		oanda::v20::json::convertJson(j, "guaranteedExecutionFees", p.guaranteedExecutionFees);
		oanda::v20::json::convertJson(j, "long", p.longVal);
		oanda::v20::json::convertJson(j, "short", p.shortVal);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}

} /* namespace position */
} /* namespace v20 */
} /* namespace oanda */
