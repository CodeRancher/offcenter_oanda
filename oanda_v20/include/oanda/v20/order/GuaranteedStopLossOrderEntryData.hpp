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
 * @file   GuaranteedStopLossOrderEntryData.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_GUARANTEEDSTOPLOSSORDERENTRYDATA_HPP
#define OANDA_V20_ORDER_GUARANTEEDSTOPLOSSORDERENTRYDATA_HPP

#include <string>
#include <vector>

#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"
#include "oanda/v20/primitives/GuaranteedStopLossOrderLevelRestriction.hpp"

namespace oanda {
namespace v20 {
namespace order {

/**
 * @brief Details required by clients creating a Guaranteed Stop Loss Order
 *
 * GuaranteedStopLossOrderEntryData is an application/json object with the following Schema:
 */
struct GuaranteedStopLossOrderEntryData {

	/**
	 * @brief The minimum distance allowed between the Trade’s fill price and the
	 *		  configured price for guaranteed Stop Loss Orders created for this
	 *		  instrument. Specified in price units.
	 */
	oanda::v20::primitives::DecimalNumber minimumDistance;

	/**
	 * @brief The amount that is charged to the account if a guaranteed Stop Loss Order
	 *		  is triggered and filled. The value is in price units and is charged for
	 *		  each unit of the Trade.
	 */
	oanda::v20::primitives::DecimalNumber premium;

	/**
	 * @brief The guaranteed Stop Loss Order level restriction for this instrument.
	 */
	oanda::v20::primitives::GuaranteedStopLossOrderLevelRestriction levelRestriction;
};

} /* namespace order */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ORDER_GUARANTEEDSTOPLOSSORDERENTRYDATA_HPP */
