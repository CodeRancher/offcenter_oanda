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
 * @file   UnitsAvailable.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_UNITSAVAILABLE_HPP
#define OANDA_V20_ORDER_UNITSAVAILABLE_HPP

#include <string>
#include <vector>

#include "oanda/v20/order/UnitsAvailableDetails.hpp"

namespace oanda {
namespace v20 {
namespace order {

/**
 * Representation of how many units of an Instrument are available to be traded by an Order depending on its positionFill option.
 * UnitsAvailable is an application/json object with the following Schema:
 */
struct UnitsAvailable {

	/**
	 * @brief The number of units that are available to be traded using an Order with a
	 * @brief positionFill option of “DEFAULT”. For an Account with hedging enabled,
	 * @brief this value will be the same as the “OPEN_ONLY” value. For an Account
	 * @brief without hedging enabled, this value will be the same as the
	 * @brief “REDUCE_FIRST” value.
	 */
	oanda::v20::order::UnitsAvailableDetails defaultVal;

	/**
	 * @brief The number of units that may are available to be traded with an Order
	 * @brief with a positionFill option of “REDUCE_FIRST”.
	 */
	oanda::v20::order::UnitsAvailableDetails reduceFirst;

	/**
	 * @brief The number of units that may are available to be traded with an Order
	 * @brief with a positionFill option of “REDUCE_ONLY”.
	 */
	oanda::v20::order::UnitsAvailableDetails reduceOnly;

	/**
	 * @brief The number of units that may are available to be traded with an Order
	 * @brief with a positionFill option of “OPEN_ONLY”.
	 */
	oanda::v20::order::UnitsAvailableDetails openOnly;
};

} /* namespace order */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ORDER_UNITSAVAILABLE_HPP */
