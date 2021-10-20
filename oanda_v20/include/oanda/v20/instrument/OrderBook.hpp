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
 * @file   OrderBook.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_INSTRUMENT_ORDERBOOK_HPP
#define OANDA_V20_INSTRUMENT_ORDERBOOK_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/instrument/OrderBookBucket.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace instrument {

/**
 * @brief The representation of an instrument’s order book at a point in time
 *
 * OrderBook is an application/json object with the following Schema:
 */
struct OrderBook {

	/**
	 * @brief The order book’s instrument
	 */
	oanda::v20::primitives::InstrumentName instrument;

	/**
	 * @brief The time when the order book snapshot was created.
	 */
	oanda::v20::primitives::DateTime time;

	/**
	 * @brief The price (midpoint) for the order book’s instrument at the time of the
	 *		  order book snapshot
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 * @brief The price width for each bucket. Each bucket covers the price range from
	 *		  the bucket’s price to the bucket’s price + bucketWidth.
	 */
	oanda::v20::pricing_common::PriceValue bucketWidth;

	/**
	 * @brief The partitioned order book, divided into buckets using a default bucket
	 *		  width. These buckets are only provided for price ranges which actually
	 *		  contain order or position data.
	 */
	std::vector<oanda::v20::instrument::OrderBookBucket> buckets;
};

} /* namespace instrument */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_INSTRUMENT_ORDERBOOK_HPP */
