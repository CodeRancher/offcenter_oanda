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
 * File: AccountChanges.cpp
 * Author: Scott Brauer
 *
 * Mon 07 Dec 2020 07:45:08 PM MST
 */

#include "oanda/v20/json/JsonConversion.hpp"
using namespace oanda::v20::json;

#include "oanda/v20/json/JsonToFrom.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace account {

void to_json(nlohmann::json& j, const AccountChanges& p) {
	j = nlohmann::json {
		{"ordersCreated", p.ordersCreated},
		{"ordersCancelled", p.ordersCancelled},
		{"ordersFilled", p.ordersFilled},
		{"ordersTriggered", p.ordersTriggered},
		{"tradesOpened", p.tradesOpened},
		{"tradesReduced", p.tradesReduced},
		{"tradesClosed", p.tradesClosed},
		{"positions", p.positions},
		{"transactions", p.transactions}
	};
}

void from_json(const nlohmann::json& j, AccountChanges& p) {
	try {
		convertJson(j, "ordersCreated", p.ordersCreated);
		convertJson(j, "ordersCancelled", p.ordersCancelled);
		convertJson(j, "ordersFilled", p.ordersFilled);
		convertJson(j, "ordersTriggered", p.ordersTriggered);
		convertJson(j, "tradesOpened", p.tradesOpened);
		convertJson(j, "tradesReduced", p.tradesReduced);
		convertJson(j, "tradesClosed", p.tradesClosed);
		convertJson(j, "positions", p.positions);
		convertJson(j, "transactions", p.transactions);
	} catch(nlohmann::json::exception& e) {
		throw exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}


} /* namespace account */
} /* namespace v20 */
} /* namespace oanda */
