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
 * @file   TradeDefinitions.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRADE_TRADEDEFINITIONS_HPP
#define OANDA_V20_TRADE_TRADEDEFINITIONS_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"

namespace oanda {
namespace v20 {
namespace trade {

/**
 * The Trade’s identifier, unique within the Trade’s Account.
 * 1523
 */
using TradeID = oanda::v20::common::String;

/**
 * The current state of the Trade.
 */
enum class TradeState {
	UNDEFINED = 0,	///< Default value allows json to be blank
	OPEN,					///< The Trade is currently open
	CLOSE_WHEN_TRADEABLE,	///< The Trade will be closed as soon as the trade’s instrument becomes tradeable
	CLOSED					///< The Trade has been fully closed
};

/**
 * The state to filter the Trades by
 */
enum class TradeStateFilter {
	UNDEFINED = 0,	///< Default value allows json to be blank
	OPEN,					///< The Trades that are currently open
	CLOSE_WHEN_TRADEABLE,	///< The Trades that will be closed as soon as the trades’ instrument becomes tradeable
	ALL,					///< The Trades that are in any of the possible states listed above.
	CLOSED					///< The Trades that have been fully closed
};

/**
 * The identification of a Trade as referred to by clients
 * @my_trade_id
 */
using TradeSpecifier = oanda::v20::common::String;

/**
 * The classification of TradePLs.
 */
enum class TradePL {
	UNDEFINED = 0,	///< Default value allows json to be blank
	POSITIVE,	///< An open Trade currently has a positive (profitable) unrealized P/L, or a closed Trade realized a positive amount of P/L.
	NEGATIVE,	///< An open Trade currently has a negative (losing) unrealized P/L, or a closed Trade realized a negative amount of P/L.
	ZERO		///< An open Trade currently has unrealized P/L of zero (neither profitable nor losing), or a closed Trade realized a P/L amount of zero.
};

} /* namespace trade */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRADE_TRADEDEFINITIONS_HPP */
