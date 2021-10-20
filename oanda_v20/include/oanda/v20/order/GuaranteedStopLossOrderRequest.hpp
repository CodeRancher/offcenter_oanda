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
 * @file   GuaranteedStopLossOrderRequest.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_GUARANTEEDSTOPLOSSORDERREQUEST_HPP
#define OANDA_V20_ORDER_GUARANTEEDSTOPLOSSORDERREQUEST_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace order {

/**
 * @brief A GuaranteedStopLossOrderRequest specifies the parameters that may be set when creating a Guaranteed Stop Loss Order.
 *		  Only one of the price and distance fields may be specified.
 *
 * GuaranteedStopLossOrderRequest is an application/json object with the following Schema:
 */
struct GuaranteedStopLossOrderRequest {
	GuaranteedStopLossOrderRequest():
		type(oanda::v20::order::OrderType::GUARANTEED_STOP_LOSS),
		timeInForce(oanda::v20::order::TimeInForce::GTC),
		triggerCondition(oanda::v20::order::OrderTriggerCondition::DEFAULT)
	{}

	/**
	 * @brief The type of the Order to Create. Must be set to “GUARANTEED_STOP_LOSS”
	 *		  when creating a Guaranteed Stop Loss Order.
	 */
	oanda::v20::order::OrderType type;

	/**
	 * @brief The ID of the Trade to close when the price threshold is breached.
	 */
	oanda::v20::trade::TradeID tradeID;

	/**
	 * @brief The client ID of the Trade to be closed when the price threshold is breached.
	 */
	oanda::v20::transaction::ClientID clientTradeID;

	/**
	 * @brief The price threshold specified for the Guaranteed Stop Loss Order. The
	 *		  associated Trade will be closed at this price.
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 * @brief Specifies the distance (in price units) from the Account’s current price
	 *		  to use as the Guaranteed Stop Loss Order price.
	 *
	 * If the Trade is short the Instrument’s bid price is used, and for long Trades the ask is used.
	 */
	oanda::v20::primitives::DecimalNumber distance;

	/**
	 * @brief The time-in-force requested for the GuaranteedStopLoss Order.
	 * Restricted to “GTC”, “GFD” and “GTD” for GuaranteedStopLoss Orders.
	 */
	oanda::v20::order::TimeInForce timeInForce;

	/**
	 * @brief The date/time when the GuaranteedStopLoss Order will be cancelled if its timeInForce is “GTD”.
	 */
	oanda::v20::primitives::DateTime gtdTime;

	/**
	 * @brief Specification of which price component should be used when determining if an Order should be triggered and filled.
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
	 * @brief The client extensions to add to the Order. Do not set, modify, or delete
	 *		  clientExtensions if your account is associated with MT4.
	 */
	oanda::v20::transaction::ClientExtensions clientExtensions;
};

} /* namespace order */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ORDER_GUARANTEEDSTOPLOSSORDERREQUEST_HPP */
