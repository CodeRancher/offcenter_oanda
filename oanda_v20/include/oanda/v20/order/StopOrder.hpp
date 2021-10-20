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
 * @file   StopOrder.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_STOPORDER_HPP
#define OANDA_V20_ORDER_STOPORDER_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/transaction/TrailingStopLossDetails.hpp"
#include "oanda/v20/transaction/TakeProfitDetails.hpp"
#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/transaction/StopLossDetails.hpp"
#include "oanda/v20/transaction/GuaranteedStopLossDetails.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace order {

/**
 * A StopOrder is an order that is created with a price threshold, and will only be filled by a price that is equal to or worse than the threshold.
 * StopOrder is an application/json object with the following Schema:
 */
struct StopOrder {
	StopOrder():
		state(oanda::v20::order::OrderState::UNDEFINED),
		type(oanda::v20::order::OrderType::UNDEFINED),
		timeInForce(oanda::v20::order::TimeInForce::UNDEFINED),
		positionFill(oanda::v20::order::OrderPositionFill::UNDEFINED),
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
	 * @brief The type of the Order. Always set to “STOP” for Stop Orders.
	 */
	oanda::v20::order::OrderType type;

	/**
	 * @brief The Stop Order’s Instrument.
	 */
	oanda::v20::primitives::InstrumentName instrument;

	/**
	 * @brief The quantity requested to be filled by the Stop Order. A positive number
	 * @brief of units results in a long Order, and a negative number of units results
	 * @brief in a short Order.
	 */
	oanda::v20::primitives::DecimalNumber units;

	/**
	 * @brief The price threshold specified for the Stop Order. The Stop Order will
	 * @brief only be filled by a market price that is equal to or worse than this
	 * @brief price.
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 * @brief The worst market price that may be used to fill this Stop Order. If the
	 * @brief market gaps and crosses through both the price and the priceBound, the
	 * @brief Stop Order will be cancelled instead of being filled.
	 */
	oanda::v20::pricing_common::PriceValue priceBound;

	/**
	 * @brief The time-in-force requested for the Stop Order.
	 */
	oanda::v20::order::TimeInForce timeInForce;

	/**
	 * @brief The date/time when the Stop Order will be cancelled if its timeInForce is
	 * @brief “GTD”.
	 */
	oanda::v20::primitives::DateTime gtdTime;

	/**
	 * @brief Specification of how Positions in the Account are modified when the Order
	 * @brief is filled.
	 */
	oanda::v20::order::OrderPositionFill positionFill;

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
	 * @brief TakeProfitDetails specifies the details of a Take Profit Order to be
	 * @brief created on behalf of a client. This may happen when an Order is filled
	 * @brief that opens a Trade requiring a Take Profit, or when a Trade’s dependent
	 * @brief Take Profit Order is modified directly through the Trade.
	 */
	oanda::v20::transaction::TakeProfitDetails takeProfitOnFill;

	/**
	 * @brief StopLossDetails specifies the details of a Stop Loss Order to be created
	 * @brief on behalf of a client. This may happen when an Order is filled that opens
	 * @brief a Trade requiring a Stop Loss, or when a Trade’s dependent Stop Loss
	 * @brief Order is modified directly through the Trade.
	 */
	oanda::v20::transaction::StopLossDetails stopLossOnFill;

	/**
	 * @brief GuaranteedStopLossDetails specifies the details of a Guaranteed Stop Loss
	 * @brief Order to be created on behalf of a client. This may happen when an Order
	 * @brief is filled that opens a Trade requiring a Guaranteed Stop Loss, or when a
	 * @brief Trade’s dependent Guaranteed Stop Loss Order is modified directly through
	 * @brief the Trade.
	 */
	oanda::v20::transaction::GuaranteedStopLossDetails guaranteedStopLossOnFill;

	/**
	 * @brief TrailingStopLossDetails specifies the details of a Trailing Stop Loss
	 * @brief Order to be created on behalf of a client. This may happen when an Order
	 * @brief is filled that opens a Trade requiring a Trailing Stop Loss, or when a
	 * @brief Trade’s dependent Trailing Stop Loss Order is modified directly through
	 * @brief the Trade.
	 */
	oanda::v20::transaction::TrailingStopLossDetails trailingStopLossOnFill;

	/**
	 * @brief Client Extensions to add to the Trade created when the Order is filled
	 * @brief (if such a Trade is created). Do not set, modify, or delete
	 * @brief tradeClientExtensions if your account is associated with MT4.
	 */
	oanda::v20::transaction::ClientExtensions tradeClientExtensions;

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

#endif /* OANDA_V20_ORDER_STOPORDER_HPP */
