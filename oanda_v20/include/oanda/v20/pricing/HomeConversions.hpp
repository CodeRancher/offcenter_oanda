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
 * @file   HomeConversions.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRICING_HOMECONVERSIONS_HPP
#define OANDA_V20_PRICING_HOMECONVERSIONS_HPP

#include <string>
#include <vector>

#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace pricing {

/**
 * HomeConversions represents the factors to use to convert quantities of a given currency into the Account’s home currency. The conversion factor depends on the scenario the conversion is required for.
 * HomeConversions is an application/json object with the following Schema:
 */
struct HomeConversions {

	/**
	 *  The currency to be converted into the home currency.
	 */
	oanda::v20::primitives::Currency currency;

	/**
	 *  The factor used to convert any gains for an Account in the specified
	 *  currency into the Account’s home currency. This would include positive
	 *  realized P/L and positive financing amounts. Conversion is performed by
	 *  multiplying the positive P/L by the conversion factor.
	 */
	oanda::v20::primitives::DecimalNumber accountGain;

	/**
	 *  The factor used to convert any losses for an Account in the specified
	 *  currency into the Account’s home currency. This would include negative
	 *  realized P/L and negative financing amounts. Conversion is performed by
	 *  multiplying the positive P/L by the conversion factor.
	 */
	oanda::v20::primitives::DecimalNumber accountLoss;

	/**
	 *  The factor used to convert a Position or Trade Value in the specified
	 *  currency into the Account’s home currency. Conversion is performed by
	 *  multiplying the Position or Trade Value by the conversion factor.
	 */
	oanda::v20::primitives::DecimalNumber positionValue;
};

} /* namespace pricing */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRICING_HOMECONVERSIONS_HPP */
