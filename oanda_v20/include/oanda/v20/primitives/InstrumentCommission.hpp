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
 * @file   InstrumentCommission.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRIMATIVES_INSTRUMENTCOMMISSION_HPP
#define OANDA_V20_PRIMATIVES_INSTRUMENTCOMMISSION_HPP

#include <string>
#include <vector>

#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace primitives {

/**
 * An InstrumentCommission represents an instrument-specific commission
 * InstrumentCommission is an application/json object with the following Schema:
 */
struct InstrumentCommission {

	/**
	 *  The commission amount (in the Account’s home currency) charged per
	 *  unitsTraded of the instrument
	 */
	oanda::v20::primitives::DecimalNumber commission;

	/**
	 *  The number of units traded that the commission amount is based on.
	 */
	oanda::v20::primitives::DecimalNumber unitsTraded;

	/**
	 *  The minimum commission amount (in the Account’s home currency) that is
	 *  charged when an Order is filled for this instrument.
	 */
	oanda::v20::primitives::DecimalNumber minimumCommission;
};

} /* namespace primitives */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRIMATIVES_INSTRUMENTCOMMISSION_HPP */
