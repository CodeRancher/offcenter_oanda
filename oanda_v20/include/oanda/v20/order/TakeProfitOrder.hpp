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
 * @file   TakeProfitOrder.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_TAKEPROFITORDER_HPP
#define OANDA_V20_ORDER_TAKEPROFITORDER_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace order {

/**
 * A TakeProfitOrder is an order that is linked to an open Trade and created with a price threshold.
 * The Order will be filled (closing the Trade) by the first price that is equal to or better than the threshold.
 * A TakeProfitOrder cannot be used to open a new Position.
 * TakeProfitOrder is an application/json object with the following Schema:
 */
struct TakeProfitOrder {
	TakeProfitOrder():
		state(oanda::v20::order::OrderState::UNDEFINED),
		type(oanda::v20::order::OrderType::UNDEFINED),
		timeInForce(oanda::v20::order::TimeInForce::UNDEFINED),
		triggerCondition(oanda::v20::order::OrderTriggerCondition::UNDEFINED)
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
	 * @brief clientExtensions if your account is associated with MT4.
	 */
	oanda::v20::transaction::ClientExtensions clientExtensions;

	/**
	 * @brief The type of the Order. Always set to “TAKE_PROFIT” for Take Profit
	 * @brief Orders.
	 */
	oanda::v20::order::OrderType type;

	/**
	 * @brief The ID of the Trade to close when the price threshold is breached.
	 */
	oanda::v20::trade::TradeID tradeID;

	/**
	 * @brief The client ID of the Trade to be closed when the price threshold is
	 * @brief breached.
	 */
	oanda::v20::transaction::ClientID clientTradeID;

	/**
	 * @brief The price threshold specified for the TakeProfit Order. The associated
	 * @brief Trade will be closed by a market price that is equal to or better than
	 * @brief this threshold.
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 * @brief The time-in-force requested for the TakeProfit Order. Restricted to
	 * @brief “GTC”, “GFD” and “GTD” for TakeProfit Orders.
	 */
	oanda::v20::order::TimeInForce timeInForce;

	/**
	 * @brief The date/time when the TakeProfit Order will be cancelled if its
	 * @brief timeInForce is “GTD”.
	 */
	oanda::v20::primitives::DateTime gtdTime;

	/**
	 * @brief Specification of which price component should be used when determining if
	 * @brief an Order should be triggered and filled. This allows Orders to be
	 * @brief triggered based on the bid, ask, mid, default (ask for buy, bid for sell)
	 * @brief or inverse (ask for sell, bid for buy) price depending on the desired
	 * @brief behaviour. Orders are always filled using their default price component.
	 * @brief This feature is only provided through the REST API. Clients who choose to
	 * @brief specify a non-default trigger condition will not see it reflected in any
	 * @brief of OANDA’s proprietary or partner trading platforms, their transaction
	 * @brief history or their account statements. OANDA platforms always assume that
	 * @brief an Order’s trigger condition is set to the default value when indicating
	 * @brief the distance from an Order’s trigger price, and will always provide the
	 * @brief default trigger condition when creating or modifying an Order. A special
	 * @brief restriction applies when creating a Guaranteed Stop Loss Order. In this
	 * @brief case the TriggerCondition value must either be “DEFAULT”, or the
	 * @brief “natural” trigger side “DEFAULT” results in. So for a Guaranteed Stop
	 * @brief Loss Order for a long trade valid values are “DEFAULT” and “BID”, and for
	 * @brief short trades “DEFAULT” and “ASK” are valid.
	 */
	oanda::v20::order::OrderTriggerCondition triggerCondition;

	/**
	 * @brief ID of the Transaction that filled this Order (only provided when the
	 * @brief Order’s state is FILLED)
	 */
	oanda::v20::transaction::TransactionID fillingTransactionID;

	/**
	 * @brief Date/time when the Order was filled (only provided when the Order’s state
	 * @brief is FILLED)
	 */
	oanda::v20::primitives::DateTime filledTime;

	/**
	 * @brief Trade ID of Trade opened when the Order was filled (only provided when
	 * @brief the Order’s state is FILLED and a Trade was opened as a result of the
	 * @brief fill)
	 */
	oanda::v20::trade::TradeID tradeOpenedID;

	/**
	 * @brief Trade ID of Trade reduced when the Order was filled (only provided when
	 * @brief the Order’s state is FILLED and a Trade was reduced as a result of the
	 * @brief fill)
	 */
	oanda::v20::trade::TradeID tradeReducedID;

	/**
	 * @brief Trade IDs of Trades closed when the Order was filled (only provided when
	 * @brief the Order’s state is FILLED and one or more Trades were closed as a
	 * @brief result of the fill)
	 */
	std::vector<oanda::v20::trade::TradeID> tradeClosedIDs;

	/**
	 * @brief ID of the Transaction that cancelled the Order (only provided when the
	 * @brief Order’s state is CANCELLED)
	 */
	oanda::v20::transaction::TransactionID cancellingTransactionID;

	/**
	 * @brief Date/time when the Order was cancelled (only provided when the state of
	 * @brief the Order is CANCELLED)
	 */
	oanda::v20::primitives::DateTime cancelledTime;

	/**
	 * @brief The ID of the Order that was replaced by this Order (only provided if
	 * @brief this Order was created as part of a cancel/replace).
	 */
	oanda::v20::order::OrderID replacesOrderID;

	/**
	 * @brief The ID of the Order that replaced this Order (only provided if this Order
	 * @brief was cancelled as part of a cancel/replace).
	 */
	oanda::v20::order::OrderID replacedByOrderID;
};

} /* namespace order */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ORDER_TAKEPROFITORDER_HPP */
