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
 * @file   TrailingStopLossOrderRequest.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_TRAILINGSTOPLOSSORDERREQUEST_HPP
#define OANDA_V20_ORDER_TRAILINGSTOPLOSSORDERREQUEST_HPP

#include <string>
#include <vector>

#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace order {

/**
 * A TrailingStopLossOrderRequest specifies the parameters that may be set when creating a Trailing Stop Loss Order.
 * TrailingStopLossOrderRequest is an application/json object with the following Schema:
 */
struct TrailingStopLossOrderRequest {
	TrailingStopLossOrderRequest():
		type(oanda::v20::order::OrderType::TRAILING_STOP_LOSS),
		timeInForce(oanda::v20::order::TimeInForce::GTC),
		triggerCondition(oanda::v20::order::OrderTriggerCondition::DEFAULT)
	{}

	/**
	 * @brief The type of the Order to Create. Must be set to “TRAILING_STOP_LOSS” when
	 * @brief creating a Trailing Stop Loss Order.
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
	 * @brief The price distance (in price units) specified for the TrailingStopLoss
	 * @brief Order.
	 */
	oanda::v20::primitives::DecimalNumber distance;

	/**
	 * @brief The time-in-force requested for the TrailingStopLoss Order. Restricted to
	 * @brief “GTC”, “GFD” and “GTD” for TrailingStopLoss Orders.
	 */
	oanda::v20::order::TimeInForce timeInForce;

	/**
	 * @brief The date/time when the StopLoss Order will be cancelled if its
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
	 * @brief The client extensions to add to the Order. Do not set, modify, or delete
	 * @brief clientExtensions if your account is associated with MT4.
	 */
	oanda::v20::transaction::ClientExtensions clientExtensions;
};

} /* namespace order */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ORDER_TRAILINGSTOPLOSSORDERREQUEST_HPP */
