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
 * @file   MarketOrder.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_MARKETORDER_HPP
#define OANDA_V20_ORDER_MARKETORDER_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/transaction/TrailingStopLossDetails.hpp"
#include "oanda/v20/transaction/MarketOrderDelayedTradeClose.hpp"
#include "oanda/v20/transaction/TakeProfitDetails.hpp"
#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/transaction/StopLossDetails.hpp"
#include "oanda/v20/transaction/MarketOrderTradeClose.hpp"
#include "oanda/v20/transaction/GuaranteedStopLossDetails.hpp"
#include "oanda/v20/transaction/MarketOrderMarginCloseout.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"
#include "oanda/v20/transaction/MarketOrderPositionCloseout.hpp"

namespace oanda {
namespace v20 {
namespace order {

/**
 * @brief A MarketOrder is an order that is filled immediately upon creation using the current market price.
 *
 * MarketOrder is an application/json object with the following Schema:
 */
struct MarketOrder {
	MarketOrder():
		state(oanda::v20::order::OrderState::UNDEFINED),
		type(oanda::v20::order::OrderType::UNDEFINED),
		timeInForce(oanda::v20::order::TimeInForce::UNDEFINED),
		positionFill(oanda::v20::order::OrderPositionFill::UNDEFINED)
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
	 * @brief The type of the Order. Always set to “MARKET” for Market Orders.
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
	 * @brief Details of the Trade requested to be closed, only provided when the
	 *		  Market Order is being used to explicitly close a Trade.
	 */
	oanda::v20::transaction::MarketOrderTradeClose tradeClose;

	/**
	 * @brief Details of the long Position requested to be closed out, only provided
	 *		  when a Market Order is being used to explicitly closeout a long Position.
	 */
	oanda::v20::transaction::MarketOrderPositionCloseout longPositionCloseout;

	/**
	 * @brief Details of the short Position requested to be closed out, only provided
	 *		  when a Market Order is being used to explicitly closeout a short
	 *		  Position.
	 */
	oanda::v20::transaction::MarketOrderPositionCloseout shortPositionCloseout;

	/**
	 * @brief Details of the Margin Closeout that this Market Order was created for
	 */
	oanda::v20::transaction::MarketOrderMarginCloseout marginCloseout;

	/**
	 * @brief Details of the delayed Trade close that this Market Order was created for
	 */
	oanda::v20::transaction::MarketOrderDelayedTradeClose delayedTradeClose;

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
};

} /* namespace order */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ORDER_MARKETORDER_HPP */
