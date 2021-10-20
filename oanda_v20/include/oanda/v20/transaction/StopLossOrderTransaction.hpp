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
 * @file   StopLossOrderTransaction.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_STOPLOSSORDERTRANSACTION_HPP
#define OANDA_V20_TRANSACTION_STOPLOSSORDERTRANSACTION_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/account/AccountDefinitions.hpp"
#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"
#include "oanda/v20/common/CommonDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * A StopLossOrderTransaction represents the creation of a StopLoss Order in the user’s Account.
 * StopLossOrderTransaction is an application/json object with the following Schema:
 */
struct StopLossOrderTransaction {
	StopLossOrderTransaction():
		userID(0),
		type(oanda::v20::transaction::TransactionType::UNDEFINED),
		timeInForce(oanda::v20::order::TimeInForce::UNDEFINED),
		triggerCondition(oanda::v20::order::OrderTriggerCondition::UNDEFINED),
		guaranteed(oanda::v20::common::BoolType::Undefined),
		reason(oanda::v20::transaction::StopLossOrderReason::UNDEFINED)
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
	 *  The Type of the Transaction. Always set to “STOP_LOSS_ORDER” in a
	 *  StopLossOrderTransaction.
	 */
	oanda::v20::transaction::TransactionType type;

	/**
	 *  The ID of the Trade to close when the price threshold is breached.
	 */
	oanda::v20::trade::TradeID tradeID;

	/**
	 *  The client ID of the Trade to be closed when the price threshold is
	 *  breached.
	 */
	oanda::v20::transaction::ClientID clientTradeID;

	/**
	 *  The price threshold specified for the Stop Loss Order. The associated
	 *  Trade will be closed by a market price that is equal to or worse than
	 *  this threshold.
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 *  Specifies the distance (in price units) from the Account’s current price
	 *  to use as the Stop Loss Order price. If the Trade is short the
	 *  Instrument’s bid price is used, and for long Trades the ask is used.
	 */
	oanda::v20::primitives::DecimalNumber distance;

	/**
	 *  The time-in-force requested for the StopLoss Order. Restricted to “GTC”,
	 *  “GFD” and “GTD” for StopLoss Orders.
	 */
	oanda::v20::order::TimeInForce timeInForce;

	/**
	 *  The date/time when the StopLoss Order will be cancelled if its
	 *  timeInForce is “GTD”.
	 */
	oanda::v20::primitives::DateTime gtdTime;

	/**
	 *  Specification of which price component should be used when determining if
	 *  an Order should be triggered and filled. This allows Orders to be
	 *  triggered based on the bid, ask, mid, default (ask for buy, bid for sell)
	 *  or inverse (ask for sell, bid for buy) price depending on the desired
	 *  behaviour. Orders are always filled using their default price component.
	 *  This feature is only provided through the REST API. Clients who choose to
	 *  specify a non-default trigger condition will not see it reflected in any
	 *  of OANDA’s proprietary or partner trading platforms, their transaction
	 *  history or their account statements. OANDA platforms always assume that
	 *  an Order’s trigger condition is set to the default value when indicating
	 *  the distance from an Order’s trigger price, and will always provide the
	 *  default trigger condition when creating or modifying an Order. A special
	 *  restriction applies when creating a Guaranteed Stop Loss Order. In this
	 *  case the TriggerCondition value must either be “DEFAULT”, or the
	 *  “natural” trigger side “DEFAULT” results in. So for a Guaranteed Stop
	 *  Loss Order for a long trade valid values are “DEFAULT” and “BID”, and for
	 *  short trades “DEFAULT” and “ASK” are valid.
	 */
	oanda::v20::order::OrderTriggerCondition triggerCondition;

	/**
	 *  Flag indicating that the Stop Loss Order is guaranteed. The default value
	 *  depends on the GuaranteedStopLossOrderMode of the account, if it is
	 *  REQUIRED, the default will be true, for DISABLED or ENABLED the default
	 *  is false.
	 *  <b>Deprecated</b>: Will be removed in a future API update.
	 */
	oanda::v20::common::BoolType guaranteed;

	/**
	 *  The fee that will be charged if the Stop Loss Order is guaranteed and the
	 *  Order is filled at the guaranteed price. The value is determined at Order
	 *  creation time. It is in price units and is charged for each unit of the
	 *  Trade.
	 *  <b>Deprecated</b>: Will be removed in a future API update.
	 */
	oanda::v20::primitives::DecimalNumber guaranteedExecutionPremium;

	/**
	 *  The reason that the Stop Loss Order was initiated
	 */
	oanda::v20::transaction::StopLossOrderReason reason;

	/**
	 *  Client Extensions to add to the Order (only provided if the Order is
	 *  being created with client extensions).
	 */
	oanda::v20::transaction::ClientExtensions clientExtensions;

	/**
	 *  The ID of the OrderFill Transaction that caused this Order to be created
	 *  (only provided if this Order was created automatically when another Order
	 *  was filled).
	 */
	oanda::v20::transaction::TransactionID orderFillTransactionID;

	/**
	 *  The ID of the Order that this Order replaces (only provided if this Order
	 *  replaces an existing Order).
	 */
	oanda::v20::order::OrderID replacesOrderID;

	/**
	 *  The ID of the Transaction that cancels the replaced Order (only provided
	 *  if this Order replaces an existing Order).
	 */
	oanda::v20::transaction::TransactionID cancellingTransactionID;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_STOPLOSSORDERTRANSACTION_HPP */
