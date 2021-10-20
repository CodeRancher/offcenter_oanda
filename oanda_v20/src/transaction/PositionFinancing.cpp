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
 * File: PositionFinancing.cpp
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

void to_json(nlohmann::json& j, const PositionFinancing& p) {
	j = nlohmann::json {
		{"instrument", p.instrument},
		{"financing", p.financing},
		{"baseFinancing", p.baseFinancing},
		{"quoteFinancing", p.quoteFinancing},
		{"homeConversionFactors", p.homeConversionFactors},
		{"openTradeFinancings", p.openTradeFinancings},
		{"accountFinancingMode", p.accountFinancingMode}
	};
}

void from_json(const nlohmann::json& j, PositionFinancing& p) {
	try {
		oanda::v20::json::convertJson(j, "instrument", p.instrument);
		oanda::v20::json::convertJson(j, "financing", p.financing);
		oanda::v20::json::convertJson(j, "baseFinancing", p.baseFinancing);
		oanda::v20::json::convertJson(j, "quoteFinancing", p.quoteFinancing);
		oanda::v20::json::convertJson(j, "homeConversionFactors", p.homeConversionFactors);
		oanda::v20::json::convertJson(j, "openTradeFinancings", p.openTradeFinancings);
		oanda::v20::json::convertJson(j, "accountFinancingMode", p.accountFinancingMode);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */
