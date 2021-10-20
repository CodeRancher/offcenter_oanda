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
 * @file   PriceBucket.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRICING_COMMON_PRICEBUCKET_HPP
#define OANDA_V20_PRICING_COMMON_PRICEBUCKET_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace pricing_common {

/**
 * A PriceBucket represents a price available for an amount of liquidity
 * PriceBucket is an application/json object with the following Schema:
 */
struct PriceBucket {

	/**
	 *  The Price offered by the PriceBucket
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 *  The amount of liquidity offered by the PriceBucket
	 */
	int liquidity;
};

} /* namespace pricing_common */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRICING_COMMON_PRICEBUCKET_HPP */
