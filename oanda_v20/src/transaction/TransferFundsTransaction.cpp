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
 * File: TransferFundsTransaction.cpp
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

void to_json(nlohmann::json& j, const TransferFundsTransaction& p) {
	j = nlohmann::json {
		{"id", p.id},
		{"time", p.time},
		{"userID", p.userID},
		{"accountID", p.accountID},
		{"batchID", p.batchID},
		{"requestID", p.requestID},
		{"type", p.type},
		{"amount", p.amount},
		{"fundingReason", p.fundingReason},
		{"comment", p.comment},
		{"accountBalance", p.accountBalance}
	};
}

void from_json(const nlohmann::json& j, TransferFundsTransaction& p) {
	try {
		oanda::v20::json::convertJson(j, "id", p.id);
		oanda::v20::json::convertJson(j, "time", p.time);
		oanda::v20::json::convertJson(j, "userID", p.userID);
		oanda::v20::json::convertJson(j, "accountID", p.accountID);
		oanda::v20::json::convertJson(j, "batchID", p.batchID);
		oanda::v20::json::convertJson(j, "requestID", p.requestID);
		oanda::v20::json::convertJson(j, "type", p.type);
		oanda::v20::json::convertJson(j, "amount", p.amount);
		oanda::v20::json::convertJson(j, "fundingReason", p.fundingReason);
		oanda::v20::json::convertJson(j, "comment", p.comment);
		oanda::v20::json::convertJson(j, "accountBalance", p.accountBalance);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}


} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */
