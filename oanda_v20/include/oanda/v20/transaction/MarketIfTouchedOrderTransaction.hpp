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
 * @file   MarketIfTouchedOrderTransaction.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_MARKETIFTOUCHEDORDERTRANSACTION_HPP
#define OANDA_V20_TRANSACTION_MARKETIFTOUCHEDORDERTRANSACTION_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/account/AccountDefinitions.hpp"
#include "oanda/v20/transaction/TrailingStopLossDetails.hpp"
#include "oanda/v20/transaction/TakeProfitDetails.hpp"
#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/transaction/StopLossDetails.hpp"
#include "oanda/v20/transaction/GuaranteedStopLossDetails.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * A MarketIfTouchedOrderTransaction represents the creation of a MarketIfTouched Order in the user’s Account.
 * MarketIfTouchedOrderTransaction is an application/json object with the following Schema:
 */
struct MarketIfTouchedOrderTransaction {
	MarketIfTouchedOrderTransaction():
		userID(0),
		type(oanda::v20::transaction::TransactionType::UNDEFINED),
		timeInForce(oanda::v20::order::TimeInForce::UNDEFINED),
		positionFill(oanda::v20::order::OrderPositionFill::UNDEFINED),
		triggerCondition(oanda::v20::order::OrderTriggerCondition::UNDEFINED),
		reason(oanda::v20::transaction::MarketIfTouchedOrderReason::UNDEFINED)
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
	 *  The Type of the Transaction. Always set to “MARKET_IF_TOUCHED_ORDER” in a
	 *  MarketIfTouchedOrderTransaction.
	 */
	oanda::v20::transaction::TransactionType type;

	/**
	 *  The MarketIfTouched Order’s Instrument.
	 */
	oanda::v20::primitives::InstrumentName instrument;

	/**
	 *  The quantity requested to be filled by the MarketIfTouched Order. A
	 *  positive number of units results in a long Order, and a negative number
	 *  of units results in a short Order.
	 */
	oanda::v20::primitives::DecimalNumber units;

	/**
	 *  The price threshold specified for the MarketIfTouched Order. The
	 *  MarketIfTouched Order will only be filled by a market price that crosses
	 *  this price from the direction of the market price at the time when the
	 *  Order was created (the initialMarketPrice). Depending on the value of the
	 *  Order’s price and initialMarketPrice, the MarketIfTouchedOrder will
	 *  behave like a Limit or a Stop Order.
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 *  The worst market price that may be used to fill this MarketIfTouched
	 *  Order.
	 */
	oanda::v20::pricing_common::PriceValue priceBound;

	/**
	 *  The time-in-force requested for the MarketIfTouched Order. Restricted to
	 *  “GTC”, “GFD” and “GTD” for MarketIfTouched Orders.
	 */
	oanda::v20::order::TimeInForce timeInForce;

	/**
	 *  The date/time when the MarketIfTouched Order will be cancelled if its
	 *  timeInForce is “GTD”.
	 */
	oanda::v20::primitives::DateTime gtdTime;

	/**
	 *  Specification of how Positions in the Account are modified when the Order
	 *  is filled.
	 */
	oanda::v20::order::OrderPositionFill positionFill;

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
	 *  The reason that the Market-if-touched Order was initiated
	 */
	oanda::v20::transaction::MarketIfTouchedOrderReason reason;

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

#endif /* OANDA_V20_TRANSACTION_MARKETIFTOUCHEDORDERTRANSACTION_HPP */
