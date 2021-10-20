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
 * @file   MarketOrderRejectTransaction.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_MARKETORDERREJECTTRANSACTION_HPP
#define OANDA_V20_TRANSACTION_MARKETORDERREJECTTRANSACTION_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/account/AccountDefinitions.hpp"
#include "oanda/v20/transaction/TrailingStopLossDetails.hpp"
#include "oanda/v20/transaction/MarketOrderDelayedTradeClose.hpp"
#include "oanda/v20/transaction/TakeProfitDetails.hpp"
#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/transaction/StopLossDetails.hpp"
#include "oanda/v20/transaction/MarketOrderTradeClose.hpp"
#include "oanda/v20/transaction/GuaranteedStopLossDetails.hpp"
#include "oanda/v20/transaction/MarketOrderMarginCloseout.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"
#include "oanda/v20/transaction/MarketOrderPositionCloseout.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * A MarketOrderRejectTransaction represents the rejection of the creation of a Market Order.
 * MarketOrderRejectTransaction is an application/json object with the following Schema:
 */
struct MarketOrderRejectTransaction {
	MarketOrderRejectTransaction():
		userID(0),
		type(oanda::v20::transaction::TransactionType::UNDEFINED),
		timeInForce(oanda::v20::order::TimeInForce::UNDEFINED),
		positionFill(oanda::v20::order::OrderPositionFill::UNDEFINED),
		reason(oanda::v20::transaction::MarketOrderReason::UNDEFINED),
		rejectReason(oanda::v20::transaction::TransactionRejectReason::UNDEFINED)
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

	/**
	 *  The Type of the Transaction. Always set to “MARKET_ORDER_REJECT” in a
	 *  MarketOrderRejectTransaction.
	 */
	oanda::v20::transaction::TransactionType type;

	/**
	 *  The Market Order’s Instrument.
	 */
	oanda::v20::primitives::InstrumentName instrument;

	/**
	 *  The quantity requested to be filled by the Market Order. A positive
	 *  number of units results in a long Order, and a negative number of units
	 *  results in a short Order.
	 */
	oanda::v20::primitives::DecimalNumber units;

	/**
	 *  The time-in-force requested for the Market Order. Restricted to FOK or
	 *  IOC for a MarketOrder.
	 */
	oanda::v20::order::TimeInForce timeInForce;

	/**
	 *  The worst price that the client is willing to have the Market Order
	 *  filled at.
	 */
	oanda::v20::pricing_common::PriceValue priceBound;

	/**
	 *  Specification of how Positions in the Account are modified when the Order
	 *  is filled.
	 */
	oanda::v20::order::OrderPositionFill positionFill;

	/**
	 *  Details of the Trade requested to be closed, only provided when the
	 *  Market Order is being used to explicitly close a Trade.
	 */
	oanda::v20::transaction::MarketOrderTradeClose tradeClose;

	/**
	 *  Details of the long Position requested to be closed out, only provided
	 *  when a Market Order is being used to explicitly closeout a long Position.
	 */
	oanda::v20::transaction::MarketOrderPositionCloseout longPositionCloseout;

	/**
	 *  Details of the short Position requested to be closed out, only provided
	 *  when a Market Order is being used to explicitly closeout a short
	 *  Position.
	 */
	oanda::v20::transaction::MarketOrderPositionCloseout shortPositionCloseout;

	/**
	 *  Details of the Margin Closeout that this Market Order was created for
	 */
	oanda::v20::transaction::MarketOrderMarginCloseout marginCloseout;

	/**
	 *  Details of the delayed Trade close that this Market Order was created for
	 */
	oanda::v20::transaction::MarketOrderDelayedTradeClose delayedTradeClose;

	/**
	 *  The reason that the Market Order was created
	 */
	oanda::v20::transaction::MarketOrderReason reason;

	/**
	 *  Client Extensions to add to the Order (only provided if the Order is
	 *  being created with client extensions).
	 */
	oanda::v20::transaction::ClientExtensions clientExtensions;

	/**
	 *  The specification of the Take Profit Order that should be created for a
	 *  Trade opened when the Order is filled (if such a Trade is created).
	 */
	oanda::v20::transaction::TakeProfitDetails takeProfitOnFill;

	/**
	 *  The specification of the Stop Loss Order that should be created for a
	 *  Trade opened when the Order is filled (if such a Trade is created).
	 */
	oanda::v20::transaction::StopLossDetails stopLossOnFill;

	/**
	 *  The specification of the Trailing Stop Loss Order that should be created
	 *  for a Trade that is opened when the Order is filled (if such a Trade is
	 *  created).
	 */
	oanda::v20::transaction::TrailingStopLossDetails trailingStopLossOnFill;

	/**
	 *  The specification of the Guaranteed Stop Loss Order that should be
	 *  created for a Trade that is opened when the Order is filled (if such a
	 *  Trade is created).
	 */
	oanda::v20::transaction::GuaranteedStopLossDetails guaranteedStopLossOnFill;

	/**
	 *  Client Extensions to add to the Trade created when the Order is filled
	 *  (if such a Trade is created).  Do not set, modify, delete
	 *  tradeClientExtensions if your account is associated with MT4.
	 */
	oanda::v20::transaction::ClientExtensions tradeClientExtensions;

	/**
	 *  The reason that the Reject Transaction was created
	 */
	oanda::v20::transaction::TransactionRejectReason rejectReason;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_MARKETORDERREJECTTRANSACTION_HPP */
