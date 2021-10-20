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
 * @file   OrderDefinitions.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_ORDERDEFINITIONS_HPP
#define OANDA_V20_ORDER_ORDERDEFINITIONS_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"

namespace oanda {
namespace v20 {
namespace order {

/**
 * @brief The Order’s identifier, unique within the Order’s Account.
 */
using OrderID = oanda::v20::common::String;

/**
 * @brief The type of the Order.
 */
enum class OrderType {
	UNDEFINED = 0, ///< Default value allows json to be blank
	TAKE_PROFIT, ///< A Take Profit Order
	MARKET, ///< A Market Order
	LIMIT, ///< A Limit Order
	TRAILING_STOP_LOSS, ///< A Trailing Stop Loss Order
	STOP_LOSS, ///< A Stop Loss Order
	FIXED_PRICE, ///< A Fixed Price Order
	GUARANTEED_STOP_LOSS, ///< A Guaranteed Stop Loss Order
	MARKET_IF_TOUCHED, ///< A Market-if-touched Order
	STOP ///< A Stop Order
};

/**
 * @brief The type of the Order.
 */
enum class CancellableOrderType {
	UNDEFINED = 0, ///< Default value allows json to be blank
	TAKE_PROFIT, ///< A Take Profit Order
	LIMIT, ///< A Limit Order
	TRAILING_STOP_LOSS, ///< A Trailing Stop Loss Order
	STOP_LOSS, ///< A Stop Loss Order
	GUARANTEED_STOP_LOSS, ///< A Guaranteed Stop Loss Order
	MARKET_IF_TOUCHED, ///< A Market-if-touched Order
	STOP ///< A Stop Order
};

/**
 * @brief The current state of the Order.
 */
enum class OrderState {
	UNDEFINED = 0, ///< Default value allows json to be blank
	FILLED, ///< The Order has been filled
	CANCELLED, ///< The Order has been cancelled
	TRIGGERED, ///< The Order has been triggered
	PENDING ///< The Order is currently pending execution
};

/**
 * @brief The state to filter the requested Orders by.
 */
enum class OrderStateFilter {
	UNDEFINED = 0, ///< Default value allows json to be blank
	FILLED, ///< The Orders that have been filled
	CANCELLED, ///< The Orders that have been cancelled
	TRIGGERED, ///< The Orders that have been triggered
	ALL, ///< The Orders that are in any of the possible states listed above
	PENDING ///< The Orders that are currently pending execution
};

/**
 * @brief The specification of an Order as referred to by clients
 */
using OrderSpecifier = oanda::v20::common::String;

/**
 * The time-in-force of an Order. TimeInForce describes how long an Order should remain pending before being automatically cancelled by the execution system.
 */
enum class TimeInForce {
	UNDEFINED = 0, ///< Default value allows json to be blank
	GTD, ///< The Order is “Good unTil Date” and will be cancelled at the provided time
	IOC, ///< The Order must be “Immediately partially filled Or Cancelled”
	FOK, ///< The Order must be immediately “Filled Or Killed”
	GFD, ///< The Order is “Good For Day” and will be cancelled at 5pm New York time
	GTC ///< The Order is “Good unTil Cancelled”
};

/**
 * @brief Specification of how Positions in the Account are modified when the Order is filled.
 */
enum class OrderPositionFill {
	UNDEFINED = 0, ///< Default value allows json to be blank
	REDUCE_FIRST, ///< When the Order is filled, always fully reduce an existing Position before opening a new Position.
	OPEN_ONLY, ///< When the Order is filled, only allow Positions to be opened or extended.
	DEFAULT, ///< When the Order is filled, use REDUCE_FIRST behaviour for non-client hedging Accounts, and OPEN_ONLY behaviour for client hedging Accounts.
	REDUCE_ONLY ///< When the Order is filled, only reduce an existing Position.
};

/**
 * @brief Specification of which price component should be used when determining if an Order should be triggered
 *		  and filled.
 *
 *  This allows Orders to be triggered based on the bid, ask, mid, default (ask for buy, bid for sell)
 *  or inverse (ask for sell, bid for buy) price depending on the desired behaviour. Orders are always filled
 *  using their default price component. This feature is only provided through the REST API. Clients who choose
 *  to specify a non-default trigger condition will not see it reflected in any of OANDA’s proprietary or partner
 *  trading platforms, their transaction history or their account statements. OANDA platforms always assume that
 *  an Order’s trigger condition is set to the default value when indicating the distance from an Order’s trigger
 *  price, and will always provide the default trigger condition when creating or modifying an Order. A special
 *  restriction applies when creating a Guaranteed Stop Loss Order. In this case the TriggerCondition value must
 *  either be “DEFAULT”, or the “natural” trigger side “DEFAULT” results in. So for a Guaranteed Stop Loss Order
 *  for a long trade valid values are “DEFAULT” and “BID”, and for short trades “DEFAULT” and “ASK” are valid.
 */
enum class OrderTriggerCondition {
	UNDEFINED = 0, ///< Default value allows json to be blank
	INVERSE, ///< Trigger an Order the opposite of the “natural” way: compare its price the bid for long Orders and ask for short Orders.
	ASK, ///< Trigger an Order by comparing its price to the ask regardless of whether it is long or short.
	BID, ///< Trigger an Order by comparing its price to the bid regardless of whether it is long or short.
	MID, ///< Trigger an Order by comparing its price to the midpoint regardless of whether it is long or short.
	DEFAULT ///< Trigger an Order the “natural” way: compare its price to the ask for long Orders and bid for short Orders.
};

} /* namespace order */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ORDER_ORDERDEFINITIONS_HPP */
