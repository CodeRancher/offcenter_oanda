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
 * @file   GuaranteedStopLossOrderLevelRestriction.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRIMATIVES_GUARANTEEDSTOPLOSSORDERLEVELRESTRICTION_HPP
#define OANDA_V20_PRIMATIVES_GUARANTEEDSTOPLOSSORDERLEVELRESTRICTION_HPP

#include <string>
#include <vector>

#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace primitives {

/**
 * A GuaranteedStopLossOrderLevelRestriction represents the total position size that can exist within a given price window for Trades with guaranteed Stop Loss Orders attached for a specific Instrument.
 * GuaranteedStopLossOrderLevelRestriction is an application/json object with the following Schema:
 */
struct GuaranteedStopLossOrderLevelRestriction {

	/**
	 *  Applies to Trades with a guaranteed Stop Loss Order attached for the
	 *  specified Instrument. This is the total allowed Trade volume that can
	 *  exist within the priceRange based on the trigger prices of the guaranteed
	 *  Stop Loss Orders.
	 */
	oanda::v20::primitives::DecimalNumber volume;

	/**
	 *  The price range the volume applies to. This value is in price units.
	 */
	oanda::v20::primitives::DecimalNumber priceRange;
};

} /* namespace primitives */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRIMATIVES_GUARANTEEDSTOPLOSSORDERLEVELRESTRICTION_HPP */
