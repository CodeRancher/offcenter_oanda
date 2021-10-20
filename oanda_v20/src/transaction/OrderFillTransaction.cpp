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
 * File: OrderFillTransaction.cpp
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

void to_json(nlohmann::json& j, const OrderFillTransaction& p) {
	j = nlohmann::json {
		{"id", p.id},
		{"time", p.time},
		{"userID", p.userID},
		{"accountID", p.accountID},
		{"batchID", p.batchID},
		{"requestID", p.requestID},
		{"type", p.type},
		{"orderID", p.orderID},
		{"clientOrderID", p.clientOrderID},
		{"instrument", p.instrument},
		{"units", p.units},
		{"gainQuoteHomeConversionFactor", p.gainQuoteHomeConversionFactor},
		{"lossQuoteHomeConversionFactor", p.lossQuoteHomeConversionFactor},
		{"homeConversionFactors", p.homeConversionFactors},
		{"price", p.price},
		{"fullVWAP", p.fullVWAP},
		{"fullPrice", p.fullPrice},
		{"reason", p.reason},
		{"pl", p.pl},
		{"quotePL", p.quotePL},
		{"financing", p.financing},
		{"baseFinancing", p.baseFinancing},
		{"quoteFinancing", p.quoteFinancing},
		{"commission", p.commission},
		{"guaranteedExecutionFee", p.guaranteedExecutionFee},
		{"quoteGuaranteedExecutionFee", p.quoteGuaranteedExecutionFee},
		{"accountBalance", p.accountBalance},
		{"tradeOpened", p.tradeOpened},
		{"tradesClosed", p.tradesClosed},
		{"tradeReduced", p.tradeReduced},
		{"halfSpreadCost", p.halfSpreadCost}
	};
}

void from_json(const nlohmann::json& j, OrderFillTransaction& p) {
	try {
		oanda::v20::json::convertJson(j, "id", p.id);
		oanda::v20::json::convertJson(j, "time", p.time);
		oanda::v20::json::convertJson(j, "userID", p.userID);
		oanda::v20::json::convertJson(j, "accountID", p.accountID);
		oanda::v20::json::convertJson(j, "batchID", p.batchID);
		oanda::v20::json::convertJson(j, "requestID", p.requestID);
		oanda::v20::json::convertJson(j, "type", p.type);
		oanda::v20::json::convertJson(j, "orderID", p.orderID);
		oanda::v20::json::convertJson(j, "clientOrderID", p.clientOrderID);
		oanda::v20::json::convertJson(j, "instrument", p.instrument);
		oanda::v20::json::convertJson(j, "units", p.units);
		oanda::v20::json::convertJson(j, "gainQuoteHomeConversionFactor", p.gainQuoteHomeConversionFactor);
		oanda::v20::json::convertJson(j, "lossQuoteHomeConversionFactor", p.lossQuoteHomeConversionFactor);
		oanda::v20::json::convertJson(j, "homeConversionFactors", p.homeConversionFactors);
		oanda::v20::json::convertJson(j, "price", p.price);
		oanda::v20::json::convertJson(j, "fullVWAP", p.fullVWAP);
		oanda::v20::json::convertJson(j, "fullPrice", p.fullPrice);
		oanda::v20::json::convertJson(j, "reason", p.reason);
		oanda::v20::json::convertJson(j, "pl", p.pl);
		oanda::v20::json::convertJson(j, "quotePL", p.quotePL);
		oanda::v20::json::convertJson(j, "financing", p.financing);
		oanda::v20::json::convertJson(j, "baseFinancing", p.baseFinancing);
		oanda::v20::json::convertJson(j, "quoteFinancing", p.quoteFinancing);
		oanda::v20::json::convertJson(j, "commission", p.commission);
		oanda::v20::json::convertJson(j, "guaranteedExecutionFee", p.guaranteedExecutionFee);
		oanda::v20::json::convertJson(j, "quoteGuaranteedExecutionFee", p.quoteGuaranteedExecutionFee);
		oanda::v20::json::convertJson(j, "accountBalance", p.accountBalance);
		oanda::v20::json::convertJson(j, "tradeOpened", p.tradeOpened);
		oanda::v20::json::convertJson(j, "tradesClosed", p.tradesClosed);
		oanda::v20::json::convertJson(j, "tradeReduced", p.tradeReduced);
		oanda::v20::json::convertJson(j, "halfSpreadCost", p.halfSpreadCost);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */
