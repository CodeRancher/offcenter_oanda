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
 * @file   MarketOrderDelayedTradeClose.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_MARKETORDERDELAYEDTRADECLOSE_HPP
#define OANDA_V20_TRANSACTION_MARKETORDERDELAYEDTRADECLOSE_HPP

#include <vector>

#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * Details for the Market Order extensions specific to a Market Order placed with the intent of fully closing a specific open trade that should have already been closed but wasn’t due to halted market conditions
 * MarketOrderDelayedTradeClose is an application/json object with the following Schema:
 */
struct MarketOrderDelayedTradeClose {

	/**
	 *  The ID of the Trade being closed
	 */
	oanda::v20::trade::TradeID tradeID;

	/**
	 *  The Client ID of the Trade being closed
	 */
	oanda::v20::trade::TradeID clientTradeID;

	/**
	 *  The Transaction ID of the DelayedTradeClosure transaction to which this
	 *  Delayed Trade Close belongs to
	 */
	oanda::v20::transaction::TransactionID sourceTransactionID;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_MARKETORDERDELAYEDTRADECLOSE_HPP */
