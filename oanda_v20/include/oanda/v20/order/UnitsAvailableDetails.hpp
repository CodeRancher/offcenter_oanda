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
 * @file   UnitsAvailableDetails.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_UNITSAVAILABLEDETAILS_HPP
#define OANDA_V20_ORDER_UNITSAVAILABLEDETAILS_HPP

#include <string>
#include <vector>

#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace order {

/**
 * Representation of many units of an Instrument are available to be traded for both long and short Orders.
 * UnitsAvailableDetails is an application/json object with the following Schema:
 */
struct UnitsAvailableDetails {

	/**
	 * @brief The units available for long Orders.
	 */
	oanda::v20::primitives::DecimalNumber longVal;

	/**
	 * @brief The units available for short Orders.
	 */
	oanda::v20::primitives::DecimalNumber shortVal;
};

} /* namespace order */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ORDER_UNITSAVAILABLEDETAILS_HPP */
