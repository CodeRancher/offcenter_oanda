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
 * @file   Position.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_POSITION_POSITION_HPP
#define OANDA_V20_POSITION_POSITION_HPP

#include <string>
#include <vector>

#include "oanda/v20/position/PositionSide.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace position {

/**
 * The specification of a Position within an Account.
 * Position is an application/json object with the following Schema:
 */
struct Position {

	/**
	 *  The Position’s Instrument.
	 */
	oanda::v20::primitives::InstrumentName instrument;

	/**
	 *  Profit/loss realized by the Position over the lifetime of the Account.
	 */
	oanda::v20::primitives::AccountUnits pl;

	/**
	 *  The unrealized profit/loss of all open Trades that contribute to this
	 *  Position.
	 */
	oanda::v20::primitives::AccountUnits unrealizedPL;

	/**
	 *  Margin currently used by the Position.
	 */
	oanda::v20::primitives::AccountUnits marginUsed;

	/**
	 *  Profit/loss realized by the Position since the Account’s resettablePL was
	 *  last reset by the client.
	 */
	oanda::v20::primitives::AccountUnits resettablePL;

	/**
	 *  The total amount of financing paid/collected for this instrument over the
	 *  lifetime of the Account.
	 */
	oanda::v20::primitives::AccountUnits financing;

	/**
	 *  The total amount of commission paid for this instrument over the lifetime
	 *  of the Account.
	 */
	oanda::v20::primitives::AccountUnits commission;

	/**
	 *  The total amount of dividend adjustment paid for this instrument over the
	 *  lifetime of the Account.
	 */
	oanda::v20::primitives::AccountUnits dividendAdjustment;

	/**
	 *  The total amount of fees charged over the lifetime of the Account for the
	 *  execution of guaranteed Stop Loss Orders for this instrument.
	 */
	oanda::v20::primitives::AccountUnits guaranteedExecutionFees;

	/**
	 *  The details of the long side of the Position.
	 */
	oanda::v20::position::PositionSide longVal;

	/**
	 *  The details of the short side of the Position.
	 */
	oanda::v20::position::PositionSide shortVal;
};

} /* namespace position */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_POSITION_POSITION_HPP */
