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
 * @file   DynamicOrderState.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_DYNAMICORDERSTATE_HPP
#define OANDA_V20_ORDER_DYNAMICORDERSTATE_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/common/CommonDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace order {

/**
 * @brief The dynamic state of an Order. This is only relevant to TrailingStopLoss Orders, as no other Order type has dynamic state.
 *
 * DynamicOrderState is an application/json object with the following Schema:
 */
struct DynamicOrderState {
	DynamicOrderState():
		isTriggerDistanceExact(oanda::v20::common::BoolType::Undefined)
	{}

	/**
	 * @brief The Order’s ID.
	 */
	oanda::v20::order::OrderID id;

	/**
	 * @brief The Order’s calculated trailing stop value.
	 */
	oanda::v20::pricing_common::PriceValue trailingStopValue;

	/**
	 * @brief The distance between the Trailing Stop Loss Order’s trailingStopValue and
	 * 		  the current Market Price.
	 *
	 * This represents the distance (in price units)
	 * of the Order from a triggering price. If the distance could not be
	 * determined, this value will not be set.
	 */
	oanda::v20::pricing_common::PriceValue triggerDistance;

	/**
	 * @brief True if an exact trigger distance could be calculated. If false, it means
	 *		  the provided trigger distance is a best estimate. If the distance could
	 *		  not be determined, this value will not be set.
	 */
	oanda::v20::common::BoolType isTriggerDistanceExact;
};

} /* namespace order */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ORDER_DYNAMICORDERSTATE_HPP */
