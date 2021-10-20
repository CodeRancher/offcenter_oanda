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
 * @file   PositionSide.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_POSITION_POSITIONSIDE_HPP
#define OANDA_V20_POSITION_POSITIONSIDE_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace position {

/**
 * The representation of a Position for a single direction (long or short).
 * PositionSide is an application/json object with the following Schema:
 */
struct PositionSide {

	/**
	 *  Number of units in the position (negative value indicates short position,
	 *  positive indicates long position).
	 */
	oanda::v20::primitives::DecimalNumber units;

	/**
	 *  Volume-weighted average of the underlying Trade open prices for the
	 *  Position.
	 */
	oanda::v20::pricing_common::PriceValue averagePrice;

	/**
	 *  List of the open Trade IDs which contribute to the open Position.
	 */
	std::vector<oanda::v20::trade::TradeID> tradeIDs;

	/**
	 *  Profit/loss realized by the PositionSide over the lifetime of the
	 *  Account.
	 */
	oanda::v20::primitives::AccountUnits pl;

	/**
	 *  The unrealized profit/loss of all open Trades that contribute to this
	 *  PositionSide.
	 */
	oanda::v20::primitives::AccountUnits unrealizedPL;

	/**
	 *  Profit/loss realized by the PositionSide since the Account’s resettablePL
	 *  was last reset by the client.
	 */
	oanda::v20::primitives::AccountUnits resettablePL;

	/**
	 *  The total amount of financing paid/collected for this PositionSide over
	 *  the lifetime of the Account.
	 */
	oanda::v20::primitives::AccountUnits financing;

	/**
	 *  The total amount of dividend adjustment paid for the PositionSide over
	 *  the lifetime of the Account.
	 */
	oanda::v20::primitives::AccountUnits dividendAdjustment;

	/**
	 *  The total amount of fees charged over the lifetime of the Account for the
	 *  execution of guaranteed Stop Loss Orders attached to Trades for this
	 *  PositionSide.
	 */
	oanda::v20::primitives::AccountUnits guaranteedExecutionFees;
};

} /* namespace position */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_POSITION_POSITIONSIDE_HPP */
