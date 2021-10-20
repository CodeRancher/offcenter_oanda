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
 * @file   StopLossOrder.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_STOPLOSSORDER_HPP
#define OANDA_V20_ORDER_STOPLOSSORDER_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"
#include "oanda/v20/common/CommonDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace order {

/**
 * @brief A StopLossOrder is an order that is linked to an open Trade and created with a price threshold.
 *
 * The Order will be filled (closing the Trade) by the first price that is equal to or worse than the threshold.
 * A StopLossOrder cannot be used to open a new Position.
 *
 * StopLossOrder is an application/json object with the following Schema:
 */
struct StopLossOrder {
	StopLossOrder():
		state(oanda::v20::order::OrderState::UNDEFINED),
		type(oanda::v20::order::OrderType::UNDEFINED),
		timeInForce(oanda::v20::order::TimeInForce::UNDEFINED),
		triggerCondition(oanda::v20::order::OrderTriggerCondition::UNDEFINED),
		guaranteed(oanda::v20::common::BoolType::Undefined)
	{}

	/**
	 * @brief The Order’s identifier, unique within the Order’s Account.
	 */
	oanda::v20::order::OrderID id;

	/**
	 * @brief The time when the Order was created.
	 */
	oanda::v20::primitives::DateTime createTime;

	/**
	 * @brief The current state of the Order.
	 */
	oanda::v20::order::OrderState state;

	/**
	 * @brief The client extensions of the Order. Do not set, modify, or delete
	 *		  clientExtensions if your account is associated with MT4.
	 */
	oanda::v20::transaction::ClientExtensions clientExtensions;

	/**
	 * @brief The type of the Order. Always set to “STOP_LOSS” for Stop Loss Orders.
	 */
	oanda::v20::order::OrderType type;

	/**
	 * @brief The premium that will be charged if the Stop Loss Order is guaranteed and
	 *		  the Order is filled at the guaranteed price. It is in price units and is
	 *		  charged for each unit of the Trade.
	 *		  <b>Deprecated</b>: Will be removed in a future API update.
	 */
	oanda::v20::primitives::DecimalNumber guaranteedExecutionPremium;

	/**
	 * @brief The ID of the Trade to close when the price threshold is breached.
	 */
	oanda::v20::trade::TradeID tradeID;

	/**
	 * @brief The client ID of the Trade to be closed when the price threshold is
	 *		  breached.
	 */
	oanda::v20::transaction::ClientID clientTradeID;

	/**
	 * @brief The price threshold specified for the Stop Loss Order. The associated
	 *		  Trade will be closed by a market price that is equal to or worse than
	 *		  this threshold.
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 * @brief Specifies the distance (in price units) from the Account’s current price
	 *		  to use as the Stop Loss Order price. If the Trade is short the
	 *		  Instrument’s bid price is used, and for long Trades the ask is used.
	 */
	oanda::v20::primitives::DecimalNumber distance;

	/**
	 * @brief The time-in-force requested for the StopLoss Order. Restricted to “GTC”,
	 *		  “GFD” and “GTD” for StopLoss Orders.
	 */
	oanda::v20::order::TimeInForce timeInForce;

	/**
	 * @brief The date/time when the StopLoss Order will be cancelled if its
	 *		  timeInForce is “GTD”.
	 */
	oanda::v20::primitives::DateTime gtdTime;

	/**
	 * @brief Specification of which price component should be used when determining if
	 *		  an Order should be triggered and filled.
	 *
	 * This allows Orders to be triggered based on the bid, ask, mid, default (ask for buy, bid for sell)
	 * or inverse (ask for sell, bid for buy) price depending on the desired
	 * behaviour. Orders are always filled using their default price component.
	 * This feature is only provided through the REST API. Clients who choose to
	 * specify a non-default trigger condition will not see it reflected in any
	 * of OANDA’s proprietary or partner trading platforms, their transaction
	 * history or their account statements. OANDA platforms always assume that
	 * an Order’s trigger condition is set to the default value when indicating
	 * the distance from an Order’s trigger price, and will always provide the
	 * default trigger condition when creating or modifying an Order. A special
	 * restriction applies when creating a Guaranteed Stop Loss Order. In this
	 * case the TriggerCondition value must either be “DEFAULT”, or the
	 * “natural” trigger side “DEFAULT” results in. So for a Guaranteed Stop
	 * Loss Order for a long trade valid values are “DEFAULT” and “BID”, and for
	 * short trades “DEFAULT” and “ASK” are valid.
	 */
	oanda::v20::order::OrderTriggerCondition triggerCondition;

	/**
	 * @brief Flag indicating that the Stop Loss Order is guaranteed. The default value
	 *		  depends on the GuaranteedStopLossOrderMode of the account, if it is
	 *		  REQUIRED, the default will be true, for DISABLED or ENABLED the default
	 *		  is false.
	 * @deprecated Will be removed in a future API update.
	 */
	oanda::v20::common::BoolType guaranteed;

	/**
	 * @brief ID of the Transaction that filled this Order (only provided when the
	 *		  Order’s state is FILLED)
	 */
	oanda::v20::transaction::TransactionID fillingTransactionID;

	/**
	 * @brief Date/time when the Order was filled (only provided when the Order’s state
	 *		  is FILLED)
	 */
	oanda::v20::primitives::DateTime filledTime;

	/**
	 * @brief Trade ID of Trade opened when the Order was filled (only provided when
	 *		  the Order’s state is FILLED and a Trade was opened as a result of the
	 *		  fill)
	 */
	oanda::v20::trade::TradeID tradeOpenedID;

	/**
	 * @brief Trade ID of Trade reduced when the Order was filled (only provided when
	 *		  the Order’s state is FILLED and a Trade was reduced as a result of the
	 *		  fill)
	 */
	oanda::v20::trade::TradeID tradeReducedID;

	/**
	 * @brief Trade IDs of Trades closed when the Order was filled (only provided when
	 *		  the Order’s state is FILLED and one or more Trades were closed as a
	 *		  result of the fill)
	 */
	std::vector<oanda::v20::trade::TradeID> tradeClosedIDs;

	/**
	 * @brief ID of the Transaction that cancelled the Order (only provided when the
	 *		  Order’s state is CANCELLED)
	 */
	oanda::v20::transaction::TransactionID cancellingTransactionID;

	/**
	 * @brief Date/time when the Order was cancelled (only provided when the state of
	 *		  the Order is CANCELLED)
	 */
	oanda::v20::primitives::DateTime cancelledTime;

	/**
	 * @brief The ID of the Order that was replaced by this Order (only provided if
	 *		  this Order was created as part of a cancel/replace).
	 */
	oanda::v20::order::OrderID replacesOrderID;

	/**
	 * @brief The ID of the Order that replaced this Order (only provided if this Order
	 *		  was cancelled as part of a cancel/replace).
	 */
	oanda::v20::order::OrderID replacedByOrderID;
};

} /* namespace order */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ORDER_STOPLOSSORDER_HPP */
