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
 * @file   ConversionFactor.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRIMATIVES_CONVERSIONFACTOR_HPP
#define OANDA_V20_PRIMATIVES_CONVERSIONFACTOR_HPP

#include <string>
#include <vector>

#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace primitives {

/**
 * A ConversionFactor contains information used to convert an amount, from an Instrument’s base or quote currency, to the home currency of an Account.
 * ConversionFactor is an application/json object with the following Schema:
 */
struct ConversionFactor {

	/**
	 *  The factor by which to multiply the amount in the given currency to
	 *  obtain the amount in the home currency of the Account.
	 */
	oanda::v20::primitives::DecimalNumber factor;
};

} /* namespace primitives */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRIMATIVES_CONVERSIONFACTOR_HPP */
