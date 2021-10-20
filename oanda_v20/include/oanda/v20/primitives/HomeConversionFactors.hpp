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
 * @file   HomeConversionFactors.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRIMATIVES_HOMECONVERSIONFACTORS_HPP
#define OANDA_V20_PRIMATIVES_HOMECONVERSIONFACTORS_HPP

#include <string>
#include <vector>

#include "oanda/v20/primitives/ConversionFactor.hpp"

namespace oanda {
namespace v20 {
namespace primitives {

/**
 * A HomeConversionFactors message contains information used to convert amounts, from an Instrument’s base or quote currency, to the home currency of an Account.
 * HomeConversionFactors is an application/json object with the following Schema:
 */
struct HomeConversionFactors {

	/**
	 *  The ConversionFactor in effect for the Account for converting any gains
	 *  realized in Instrument quote units into units of the Account’s home
	 *  currency.
	 */
	oanda::v20::primitives::ConversionFactor gainQuoteHome;

	/**
	 *  The ConversionFactor in effect for the Account for converting any losses
	 *  realized in Instrument quote units into units of the Account’s home
	 *  currency.
	 */
	oanda::v20::primitives::ConversionFactor lossQuoteHome;

	/**
	 *  The ConversionFactor in effect for the Account for converting any gains
	 *  realized in Instrument base units into units of the Account’s home
	 *  currency.
	 */
	oanda::v20::primitives::ConversionFactor gainBaseHome;

	/**
	 *  The ConversionFactor in effect for the Account for converting any losses
	 *  realized in Instrument base units into units of the Account’s home
	 *  currency.
	 */
	oanda::v20::primitives::ConversionFactor lossBaseHome;
};

} /* namespace primitives */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRIMATIVES_HOMECONVERSIONFACTORS_HPP */
