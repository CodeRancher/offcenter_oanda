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
 * @file   Transaction.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_TRANSACTION_HPP
#define OANDA_V20_TRANSACTION_TRANSACTION_HPP

#include <string>
#include <vector>

#include "oanda/v20/account/AccountDefinitions.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * The base Transaction specification. Specifies properties that are common between all Transaction.
 * Implemented by: <a href="../transaction-df/#OrderFillTransaction">OrderFillTransaction</a>, <a href="../transaction-df/#OrderCancelTransaction">OrderCancelTransaction</a>, <a href="../transaction-df/#OrderCancelRejectTransaction">OrderCancelRejectTransaction</a>, <a href="../transaction-df/#OrderClientExtensionsModifyTransaction">OrderClientExtensionsModifyTransaction</a>, <a href="../transaction-df/#OrderClientExtensionsModifyRejectTransaction">OrderClientExtensionsModifyRejectTransaction</a>, <a href="../transaction-df/#CreateTransaction">CreateTransaction</a>, <a href="../transaction-df/#CloseTransaction">CloseTransaction</a>, <a href="../transaction-df/#ReopenTransaction">ReopenTransaction</a>, <a href="../transaction-df/#ClientConfigureTransaction">ClientConfigureTransaction</a>, <a href="../transaction-df/#ClientConfigureRejectTransaction">ClientConfigureRejectTransaction</a>, <a href="../transaction-df/#TransferFundsTransaction">TransferFundsTransaction</a>, <a href="../transaction-df/#TransferFundsRejectTransaction">TransferFundsRejectTransaction</a>, <a href="../transaction-df/#MarketOrderTransaction">MarketOrderTransaction</a>, <a href="../transaction-df/#MarketOrderRejectTransaction">MarketOrderRejectTransaction</a>, <a href="../transaction-df/#FixedPriceOrderTransaction">FixedPriceOrderTransaction</a>, <a href="../transaction-df/#LimitOrderTransaction">LimitOrderTransaction</a>, <a href="../transaction-df/#LimitOrderRejectTransaction">LimitOrderRejectTransaction</a>, <a href="../transaction-df/#StopOrderTransaction">StopOrderTransaction</a>, <a href="../transaction-df/#StopOrderRejectTransaction">StopOrderRejectTransaction</a>, <a href="../transaction-df/#MarketIfTouchedOrderTransaction">MarketIfTouchedOrderTransaction</a>, <a href="../transaction-df/#MarketIfTouchedOrderRejectTransaction">MarketIfTouchedOrderRejectTransaction</a>, <a href="../transaction-df/#TakeProfitOrderTransaction">TakeProfitOrderTransaction</a>, <a href="../transaction-df/#TakeProfitOrderRejectTransaction">TakeProfitOrderRejectTransaction</a>, <a href="../transaction-df/#StopLossOrderTransaction">StopLossOrderTransaction</a>, <a href="../transaction-df/#StopLossOrderRejectTransaction">StopLossOrderRejectTransaction</a>, <a href="../transaction-df/#GuaranteedStopLossOrderTransaction">GuaranteedStopLossOrderTransaction</a>, <a href="../transaction-df/#GuaranteedStopLossOrderRejectTransaction">GuaranteedStopLossOrderRejectTransaction</a>, <a href="../transaction-df/#TrailingStopLossOrderTransaction">TrailingStopLossOrderTransaction</a>, <a href="../transaction-df/#TrailingStopLossOrderRejectTransaction">TrailingStopLossOrderRejectTransaction</a>, <a href="../transaction-df/#TradeClientExtensionsModifyTransaction">TradeClientExtensionsModifyTransaction</a>, <a href="../transaction-df/#TradeClientExtensionsModifyRejectTransaction">TradeClientExtensionsModifyRejectTransaction</a>, <a href="../transaction-df/#MarginCallEnterTransaction">MarginCallEnterTransaction</a>, <a href="../transaction-df/#MarginCallExtendTransaction">MarginCallExtendTransaction</a>, <a href="../transaction-df/#MarginCallExitTransaction">MarginCallExitTransaction</a>, <a href="../transaction-df/#DelayedTradeClosureTransaction">DelayedTradeClosureTransaction</a>, <a href="../transaction-df/#DailyFinancingTransaction">DailyFinancingTransaction</a>, <a href="../transaction-df/#DividendAdjustmentTransaction">DividendAdjustmentTransaction</a>, <a href="../transaction-df/#ResetResettablePLTransaction">ResetResettablePLTransaction</a>
 * Transaction is an application/json object with the following Schema:
 */
struct Transaction {
	Transaction():
		userID(0)
	{}

	/**
	 *  The Transaction’s Identifier.
	 */
	oanda::v20::transaction::TransactionID id;

	/**
	 *  The date/time when the Transaction was created.
	 */
	oanda::v20::primitives::DateTime time;

	/**
	 *  The ID of the user that initiated the creation of the Transaction.
	 */
	int userID;

	/**
	 *  The ID of the Account the Transaction was created for.
	 */
	oanda::v20::account::AccountID accountID;

	/**
	 *  The ID of the “batch” that the Transaction belongs to. Transactions in
	 *  the same batch are applied to the Account simultaneously.
	 */
	oanda::v20::transaction::TransactionID batchID;

	/**
	 *  The Request ID of the request which generated the transaction.
	 */
	oanda::v20::transaction::RequestID requestID;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_TRANSACTION_HPP */
