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
 * @file   MarketOrderRequest.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_MARKETORDERREQUEST_HPP
#define OANDA_V20_ORDER_MARKETORDERREQUEST_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/transaction/TrailingStopLossDetails.hpp"
#include "oanda/v20/transaction/TakeProfitDetails.hpp"
#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/transaction/StopLossDetails.hpp"
#include "oanda/v20/transaction/GuaranteedStopLossDetails.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace order {

/**
 * @brief A MarketOrderRequest specifies the parameters that may be set when creating a Market Order.
 *
 * MarketOrderRequest is an application/json object with the following Schema:
 */
struct MarketOrderRequest {
	MarketOrderRequest():
		type(oanda::v20::order::OrderType::MARKET),
		timeInForce(oanda::v20::order::TimeInForce::FOK),
		positionFill(oanda::v20::order::OrderPositionFill::DEFAULT)
	{}

	/**
	 * @brief The type of the Order to Create. Must be set to “MARKET” when creating a
	 *		  Market Order.
	 */
	oanda::v20::order::OrderType type;

	/**
	 * @brief The Market Order’s Instrument.
	 */
	oanda::v20::primitives::InstrumentName instrument;

	/**
	 * @brief The quantity requested to be filled by the Market Order. A positive
	 *		  number of units results in a long Order, and a negative number of units
	 *		  results in a short Order.
	 */
	oanda::v20::primitives::DecimalNumber units;

	/**
	 * @brief The time-in-force requested for the Market Order. Restricted to FOK or
	 *		  IOC for a MarketOrder.
	 */
	oanda::v20::order::TimeInForce timeInForce;

	/**
	 * @brief The worst price that the client is willing to have the Market Order
	 *		  filled at.
	 */
	oanda::v20::pricing_common::PriceValue priceBound;

	/**
	 * @brief Specification of how Positions in the Account are modified when the Order
	 *		  is filled.
	 */
	oanda::v20::order::OrderPositionFill positionFill;

	/**
	 * @brief The client extensions to add to the Order. Do not set, modify, or delete
	 *		  clientExtensions if your account is associated with MT4.
	 */
	oanda::v20::transaction::ClientExtensions clientExtensions;

	/**
	 * @brief TakeProfitDetails specifies the details of a Take Profit Order to be
	 *		  created on behalf of a client. This may happen when an Order is filled
	 *		  that opens a Trade requiring a Take Profit, or when a Trade’s dependent
	 *		  Take Profit Order is modified directly through the Trade.
	 */
	oanda::v20::transaction::TakeProfitDetails takeProfitOnFill;

	/**
	 * @brief StopLossDetails specifies the details of a Stop Loss Order to be created
	 *		  on behalf of a client. This may happen when an Order is filled that opens
	 *		  a Trade requiring a Stop Loss, or when a Trade’s dependent Stop Loss
	 *		  Order is modified directly through the Trade.
	 */
	oanda::v20::transaction::StopLossDetails stopLossOnFill;

	/**
	 * @brief GuaranteedStopLossDetails specifies the details of a Guaranteed Stop Loss
	 *		  Order to be created on behalf of a client. This may happen when an Order
	 *		  is filled that opens a Trade requiring a Guaranteed Stop Loss, or when a
	 *		  Trade’s dependent Guaranteed Stop Loss Order is modified directly through
	 *		  the Trade.
	 */
	oanda::v20::transaction::GuaranteedStopLossDetails guaranteedStopLossOnFill;

	/**
	 * @brief TrailingStopLossDetails specifies the details of a Trailing Stop Loss
	 *		  Order to be created on behalf of a client. This may happen when an Order
	 *		  is filled that opens a Trade requiring a Trailing Stop Loss, or when a
	 *		  Trade’s dependent Trailing Stop Loss Order is modified directly through
	 *		  the Trade.
	 */
	oanda::v20::transaction::TrailingStopLossDetails trailingStopLossOnFill;

	/**
	 * @brief Client Extensions to add to the Trade created when the Order is filled
	 *		  (if such a Trade is created). Do not set, modify, or delete
	 *		  tradeClientExtensions if your account is associated with MT4.
	 */
	oanda::v20::transaction::ClientExtensions tradeClientExtensions;
};

} /* namespace order */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ORDER_MARKETORDERREQUEST_HPP */
