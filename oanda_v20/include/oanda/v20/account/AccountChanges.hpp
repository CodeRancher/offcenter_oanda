/**
 * Copyright 2020 Scott Brauer
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
	 * @brief    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an  BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file   AccountChanges.hpp
 * @author Scott Brauer
 * @date   12-07-2020
 */

#ifndef OANDA_V20_ACCOUNT_ACCOUNTCHANGES_HPP
#define OANDA_V20_ACCOUNT_ACCOUNTCHANGES_HPP

#include <string>
#include <vector>

#include "oanda/v20/trade/TradeSummary.hpp"
#include "oanda/v20/transaction/Transaction.hpp"
#include "oanda/v20/order/Order.hpp"
#include "oanda/v20/position/Position.hpp"

namespace oanda {
namespace v20 {
namespace account {

/**
 * @brief An AccountChanges Object is used to represent the changes to an Account’s Orders,
 *		  Trades and Positions since a specified Account TransactionID in the past.
 *		  AccountChanges is an application/json object with the following Schema:
 */
struct AccountChanges {

	/**
	 * @brief The Orders created. These Orders may have been filled, cancelled or
	 *		  triggered in the same period.
	 */
	std::vector<oanda::v20::order::Order> ordersCreated;

	/**
	 * @brief The Orders cancelled.
	 */
	std::vector<oanda::v20::order::Order> ordersCancelled;

	/**
	 * @brief The Orders filled.
	 */
	std::vector<oanda::v20::order::Order> ordersFilled;

	/**
	 * @brief The Orders triggered.
	 */
	std::vector<oanda::v20::order::Order> ordersTriggered;

	/**
	 * @brief The Trades opened.
	 */
	std::vector<oanda::v20::trade::TradeSummary> tradesOpened;

	/**
	 * @brief The Trades reduced.
	 */
	std::vector<oanda::v20::trade::TradeSummary> tradesReduced;

	/**
	 * @brief The Trades closed.
	 */
	std::vector<oanda::v20::trade::TradeSummary> tradesClosed;

	/**
	 * @brief The Positions changed.
	 */
	std::vector<oanda::v20::position::Position> positions;

	/**
	 * @brief The Transactions that have been generated.
	 */
	std::vector<oanda::v20::transaction::Transaction> transactions;
};

} /* namespace account */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ACCOUNT_ACCOUNTCHANGES_HPP */
