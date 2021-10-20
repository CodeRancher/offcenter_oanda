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
 * @file   PricingDefinitions.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRICING_PRICINGDEFINITIONS_HPP
#define OANDA_V20_PRICING_PRICINGDEFINITIONS_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"

namespace oanda {
namespace v20 {
namespace pricing {

/**
 * The status of the Price.
 */
enum class PriceStatus {
	UNDEFINED = 0,	///< Default value allows json to be blank
	tradeable,		///< The Instrument’s price is tradeable.
	invalid,		///< The Instrument of the price is invalid or there is no valid Price for the Instrument.
	non_tradeable	///< The Instrument’s price is not tradeable.
};

/**
 * An instrument name, a granularity, and a price component to get candlestick data for.
 * A string containing the following, all delimited by “:” characters: 1) InstrumentName 2) CandlestickGranularity 3) PricingComponent e.g. EUR_USD:S10:BM
 */
using CandleSpecification = oanda::v20::common::String;

} /* namespace pricing */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRICING_PRICINGDEFINITIONS_HPP */
