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
 * @file   PositionBookBucket.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_INSTRUMENT_POSITIONBOOKBUCKET_HPP
#define OANDA_V20_INSTRUMENT_POSITIONBOOKBUCKET_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace instrument {

/**
 * @brief The position book data for a partition of the instrument’s prices.
 *
 * PositionBookBucket is an application/json object with the following Schema:
 */
struct PositionBookBucket {

	/**
	 * @brief The lowest price (inclusive) covered by the bucket. The bucket covers the
	 *		  price range from the price to price + the position book’s bucketWidth.
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 * @brief The percentage of the total number of positions represented by the long
	 *		  positions found in this bucket.
	 */
	oanda::v20::primitives::DecimalNumber longCountPercent;

	/**
	 * @brief The percentage of the total number of positions represented by the short
	 *		  positions found in this bucket.
	 */
	oanda::v20::primitives::DecimalNumber shortCountPercent;
};

} /* namespace instrument */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_INSTRUMENT_POSITIONBOOKBUCKET_HPP */
