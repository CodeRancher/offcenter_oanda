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
 * @file   CalculatedPositionState.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_POSITION_CALCULATEDPOSITIONSTATE_HPP
#define OANDA_V20_POSITION_CALCULATEDPOSITIONSTATE_HPP

#include <string>
#include <vector>

#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace position {

/**
 * The dynamic (calculated) state of a Position
 * CalculatedPositionState is an application/json object with the following Schema:
 */
struct CalculatedPositionState {

	/**
	 *  The Position’s Instrument.
	 */
	oanda::v20::primitives::InstrumentName instrument;

	/**
	 *  The Position’s net unrealized profit/loss
	 */
	oanda::v20::primitives::AccountUnits netUnrealizedPL;

	/**
	 *  The unrealized profit/loss of the Position’s long open Trades
	 */
	oanda::v20::primitives::AccountUnits longUnrealizedPL;

	/**
	 *  The unrealized profit/loss of the Position’s short open Trades
	 */
	oanda::v20::primitives::AccountUnits shortUnrealizedPL;

	/**
	 *  Margin currently used by the Position.
	 */
	oanda::v20::primitives::AccountUnits marginUsed;
};

} /* namespace position */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_POSITION_CALCULATEDPOSITIONSTATE_HPP */
