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
 * @file   QuoteHomeConversionFactors.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRICING_QUOTEHOMECONVERSIONFACTORS_HPP
#define OANDA_V20_PRICING_QUOTEHOMECONVERSIONFACTORS_HPP

#include <string>
#include <vector>

#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace pricing {

/**
 * QuoteHomeConversionFactors represents the factors that can be used used to convert quantities of a Price’s Instrument’s quote currency into the Account’s home currency.
 * QuoteHomeConversionFactors is an application/json object with the following Schema:
 */
struct QuoteHomeConversionFactors {

	/**
	 *  The factor used to convert a positive amount of the Price’s Instrument’s
	 *  quote currency into a positive amount of the Account’s home currency.
	 *  Conversion is performed by multiplying the quote units by the conversion
	 *  factor.
	 */
	oanda::v20::primitives::DecimalNumber positiveUnits;

	/**
	 *  The factor used to convert a negative amount of the Price’s Instrument’s
	 *  quote currency into a negative amount of the Account’s home currency.
	 *  Conversion is performed by multiplying the quote units by the conversion
	 *  factor.
	 */
	oanda::v20::primitives::DecimalNumber negativeUnits;
};

} /* namespace pricing */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRICING_QUOTEHOMECONVERSIONFACTORS_HPP */
