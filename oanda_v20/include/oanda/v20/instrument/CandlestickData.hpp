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
 * @file   CandlestickData.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_INSTRUMENT_CANDLESTICKDATA_HPP
#define OANDA_V20_INSTRUMENT_CANDLESTICKDATA_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace instrument {

/** The price data (open, high, low, close) for the Candlestick representation.
 *
 *  CandlestickData is an application/json object with the following Schema:
 */
struct CandlestickData {

	/// The first (open) price in the time-range represented by the candlestick.
	oanda::v20::pricing_common::PriceValue o;

	/// The highest price in the time-range represented by the candlestick.
	oanda::v20::pricing_common::PriceValue h;

	 /// The lowest price in the time-range represented by the candlestick.
	oanda::v20::pricing_common::PriceValue l;

	/// The last (closing) price in the time-range represented by the candlestick.
	oanda::v20::pricing_common::PriceValue c;
};

} /* namespace instrument */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_INSTRUMENT_CANDLESTICKDATA_HPP */
