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
 * @file   CandlestickResponse.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_INSTRUMENT_CANDLESTICKRESPONSE_HPP
#define OANDA_V20_INSTRUMENT_CANDLESTICKRESPONSE_HPP

#include <string>
#include <vector>

#include "oanda/v20/instrument/Candlestick.hpp"
#include "oanda/v20/instrument/InstrumentDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace instrument {

/**
 * @brief Response containing instrument, granularity, and list of candles.
 *
 * CandlestickResponse is an application/json object with the following Schema:
 */
struct CandlestickResponse {
	CandlestickResponse():
		granularity(oanda::v20::instrument::CandlestickGranularity::UNDEFINED)
	{}

	/**
	 * @brief The instrument whose Prices are represented by the candlesticks.
	 */
	oanda::v20::primitives::InstrumentName instrument;

	/**
	 * @brief The granularity of the candlesticks provided.
	 */
	oanda::v20::instrument::CandlestickGranularity granularity;

	/**
	 * @brief The list of candlesticks that satisfy the request.
	 */
	std::vector<oanda::v20::instrument::Candlestick> candles;
};

} /* namespace instrument */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_INSTRUMENT_CANDLESTICKRESPONSE_HPP */
