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
 * @file   Candlestick.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_INSTRUMENT_CANDLESTICK_HPP
#define OANDA_V20_INSTRUMENT_CANDLESTICK_HPP

#include <string>
#include <vector>

#include "oanda/v20/instrument/CandlestickData.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"
#include "oanda/v20/common/CommonDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace instrument {

/**
 * @brief The Candlestick representation
 *
 * Candlestick is an application/json object with the following Schema:
 */
struct Candlestick {
	Candlestick():
		volume(0),
		complete(oanda::v20::common::BoolType::Undefined)
	{}

	/// The start time of the candlestick
	oanda::v20::primitives::DateTime time;

	/// The candlestick data based on bids. Only provided if bid-based candles were requested.
	oanda::v20::instrument::CandlestickData bid;

	/// The candlestick data based on asks. Only provided if ask-based candles were requested.
	oanda::v20::instrument::CandlestickData ask;

	/// The candlestick data based on midpoints. Only provided if midpoint-based candles were requested.
	oanda::v20::instrument::CandlestickData mid;

	/// The number of prices created during the time-range represented by the candlestick.
	int volume;

	/// A flag indicating if the candlestick is complete. A complete candlestick is one whose ending time is not in the future.
	oanda::v20::common::BoolType complete;
};

} /* namespace instrument */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_INSTRUMENT_CANDLESTICK_HPP */
