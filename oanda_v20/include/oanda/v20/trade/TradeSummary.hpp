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
 * @file   TradeSummary.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRADE_TRADESUMMARY_HPP
#define OANDA_V20_TRADE_TRADESUMMARY_HPP

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
namespace trade {

/**
 * The summary of a Trade within an Account. This representation does not provide the full details of the Trade’s dependent Orders.
 * TradeSummary is an application/json object with the following Schema:
 */
struct TradeSummary {
	TradeSummary():
		state(oanda::v20::trade::TradeState::UNDEFINED)
	{}

	/**
	 *  The Trade’s identifier, unique within the Trade’s Account.
	 */
	oanda::v20::trade::TradeID id;

	/**
	 *  The Trade’s Instrument.
	 */
	oanda::v20::primitives::InstrumentName instrument;

	/**
	 *  The execution price of the Trade.
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 *  The date/time when the Trade was opened.
	 */
	oanda::v20::primitives::DateTime openTime;

	/**
	 *  The current state of the Trade.
	 */
	oanda::v20::trade::TradeState state;

	/**
	 *  The initial size of the Trade. Negative values indicate a short Trade,
	 *  and positive values indicate a long Trade.
	 */
	oanda::v20::primitives::DecimalNumber initialUnits;

	/**
	 *  The margin required at the time the Trade was created. Note, this is the
	 *  ‘pure’ margin required, it is not the ‘effective’ margin used that
	 *  factors in the trade risk if a GSLO is attached to the trade.
	 */
	oanda::v20::primitives::AccountUnits initialMarginRequired;

	/**
	 *  The number of units currently open for the Trade. This value is reduced
	 *  to 0.0 as the Trade is closed.
	 */
	oanda::v20::primitives::DecimalNumber currentUnits;

	/**
	 *  The total profit/loss realized on the closed portion of the Trade.
	 */
	oanda::v20::primitives::AccountUnits realizedPL;

	/**
	 *  The unrealized profit/loss on the open portion of the Trade.
	 */
	oanda::v20::primitives::AccountUnits unrealizedPL;

	/**
	 *  Margin currently used by the Trade.
	 */
	oanda::v20::primitives::AccountUnits marginUsed;

	/**
	 *  The average closing price of the Trade. Only present if the Trade has
	 *  been closed or reduced at least once.
	 */
	oanda::v20::pricing_common::PriceValue averageClosePrice;

	/**
	 *  The IDs of the Transactions that have closed portions of this Trade.
	 */
	std::vector<oanda::v20::transaction::TransactionID> closingTransactionIDs;

	/**
	 *  The financing paid/collected for this Trade.
	 */
	oanda::v20::primitives::AccountUnits financing;

	/**
	 *  The dividend adjustment paid for this Trade.
	 */
	oanda::v20::primitives::AccountUnits dividendAdjustment;

	/**
	 *  The date/time when the Trade was fully closed. Only provided for Trades
	 *  whose state is CLOSED.
	 */
	oanda::v20::primitives::DateTime closeTime;

	/**
	 *  The client extensions of the Trade.
	 */
	oanda::v20::transaction::ClientExtensions clientExtensions;

	/**
	 *  ID of the Trade’s Take Profit Order, only provided if such an Order
	 *  exists.
	 */
	oanda::v20::order::OrderID takeProfitOrderID;

	/**
	 *  ID of the Trade’s Stop Loss Order, only provided if such an Order exists.
	 */
	oanda::v20::order::OrderID stopLossOrderID;

	/**
	 *  ID of the Trade’s Guaranteed Stop Loss Order, only provided if such an
	 *  Order exists.
	 */
	oanda::v20::order::OrderID guaranteedStopLossOrderID;

	/**
	 *  ID of the Trade’s Trailing Stop Loss Order, only provided if such an
	 *  Order exists.
	 */
	oanda::v20::order::OrderID trailingStopLossOrderID;
};

} /* namespace trade */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRADE_TRADESUMMARY_HPP */
