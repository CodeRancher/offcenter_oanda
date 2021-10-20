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
 * @file   CalculatedTradeState.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRADE_CALCULATEDTRADESTATE_HPP
#define OANDA_V20_TRADE_CALCULATEDTRADESTATE_HPP

#include <string>
#include <vector>

#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace trade {

/**
 * The dynamic (calculated) state of an open Trade
 * CalculatedTradeState is an application/json object with the following Schema:
 */
struct CalculatedTradeState {

	/**
	 *  The Trade’s ID.
	 */
	oanda::v20::trade::TradeID id;

	/**
	 *  The Trade’s unrealized profit/loss.
	 */
	oanda::v20::primitives::AccountUnits unrealizedPL;

	/**
	 *  Margin currently used by the Trade.
	 */
	oanda::v20::primitives::AccountUnits marginUsed;
};

} /* namespace trade */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRADE_CALCULATEDTRADESTATE_HPP */
