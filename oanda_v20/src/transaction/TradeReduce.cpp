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
 * File: TradeReduce.cpp
 * Author: Scott Brauer
 *
 * Mon 07 Dec 2020 07:45:10 PM MST
 */

#include "oanda/v20/json/JsonConversion.hpp"

#include "oanda/v20/json/JsonToFrom.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

void to_json(nlohmann::json& j, const TradeReduce& p) {
	j = nlohmann::json {
		{"tradeID", p.tradeID},
		{"units", p.units},
		{"price", p.price},
		{"realizedPL", p.realizedPL},
		{"financing", p.financing},
		{"baseFinancing", p.baseFinancing},
		{"quoteFinancing", p.quoteFinancing},
		{"financingRate", p.financingRate},
		{"guaranteedExecutionFee", p.guaranteedExecutionFee},
		{"quoteGuaranteedExecutionFee", p.quoteGuaranteedExecutionFee},
		{"halfSpreadCost", p.halfSpreadCost}
	};
}

void from_json(const nlohmann::json& j, TradeReduce& p) {
	try {
		oanda::v20::json::convertJson(j, "tradeID", p.tradeID);
		oanda::v20::json::convertJson(j, "units", p.units);
		oanda::v20::json::convertJson(j, "price", p.price);
		oanda::v20::json::convertJson(j, "realizedPL", p.realizedPL);
		oanda::v20::json::convertJson(j, "financing", p.financing);
		oanda::v20::json::convertJson(j, "baseFinancing", p.baseFinancing);
		oanda::v20::json::convertJson(j, "quoteFinancing", p.quoteFinancing);
		oanda::v20::json::convertJson(j, "financingRate", p.financingRate);
		oanda::v20::json::convertJson(j, "guaranteedExecutionFee", p.guaranteedExecutionFee);
		oanda::v20::json::convertJson(j, "quoteGuaranteedExecutionFee", p.quoteGuaranteedExecutionFee);
		oanda::v20::json::convertJson(j, "halfSpreadCost", p.halfSpreadCost);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}


} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */
