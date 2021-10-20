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
 * File: StopOrderRejectTransaction.cpp
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

void to_json(nlohmann::json& j, const StopOrderRejectTransaction& p) {
	j = nlohmann::json {
		{"id", p.id},
		{"time", p.time},
		{"userID", p.userID},
		{"accountID", p.accountID},
		{"batchID", p.batchID},
		{"requestID", p.requestID},
		{"type", p.type},
		{"instrument", p.instrument},
		{"units", p.units},
		{"price", p.price},
		{"priceBound", p.priceBound},
		{"timeInForce", p.timeInForce},
		{"gtdTime", p.gtdTime},
		{"positionFill", p.positionFill},
		{"triggerCondition", p.triggerCondition},
		{"reason", p.reason},
		{"clientExtensions", p.clientExtensions},
		{"takeProfitOnFill", p.takeProfitOnFill},
		{"stopLossOnFill", p.stopLossOnFill},
		{"trailingStopLossOnFill", p.trailingStopLossOnFill},
		{"guaranteedStopLossOnFill", p.guaranteedStopLossOnFill},
		{"tradeClientExtensions", p.tradeClientExtensions},
		{"intendedReplacesOrderID", p.intendedReplacesOrderID},
		{"rejectReason", p.rejectReason}
	};
}

void from_json(const nlohmann::json& j, StopOrderRejectTransaction& p) {
	try {
		oanda::v20::json::convertJson(j, "id", p.id);
		oanda::v20::json::convertJson(j, "time", p.time);
		oanda::v20::json::convertJson(j, "userID", p.userID);
		oanda::v20::json::convertJson(j, "accountID", p.accountID);
		oanda::v20::json::convertJson(j, "batchID", p.batchID);
		oanda::v20::json::convertJson(j, "requestID", p.requestID);
		oanda::v20::json::convertJson(j, "type", p.type);
		oanda::v20::json::convertJson(j, "instrument", p.instrument);
		oanda::v20::json::convertJson(j, "units", p.units);
		oanda::v20::json::convertJson(j, "price", p.price);
		oanda::v20::json::convertJson(j, "priceBound", p.priceBound);
		oanda::v20::json::convertJson(j, "timeInForce", p.timeInForce);
		oanda::v20::json::convertJson(j, "gtdTime", p.gtdTime);
		oanda::v20::json::convertJson(j, "positionFill", p.positionFill);
		oanda::v20::json::convertJson(j, "triggerCondition", p.triggerCondition);
		oanda::v20::json::convertJson(j, "reason", p.reason);
		oanda::v20::json::convertJson(j, "clientExtensions", p.clientExtensions);
		oanda::v20::json::convertJson(j, "takeProfitOnFill", p.takeProfitOnFill);
		oanda::v20::json::convertJson(j, "stopLossOnFill", p.stopLossOnFill);
		oanda::v20::json::convertJson(j, "trailingStopLossOnFill", p.trailingStopLossOnFill);
		oanda::v20::json::convertJson(j, "guaranteedStopLossOnFill", p.guaranteedStopLossOnFill);
		oanda::v20::json::convertJson(j, "tradeClientExtensions", p.tradeClientExtensions);
		oanda::v20::json::convertJson(j, "intendedReplacesOrderID", p.intendedReplacesOrderID);
		oanda::v20::json::convertJson(j, "rejectReason", p.rejectReason);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */
