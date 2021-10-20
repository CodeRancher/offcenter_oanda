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
 * @file   Order.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_ORDER_HPP
#define OANDA_V20_ORDER_ORDER_HPP

#include <string>
#include <vector>

#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace order {

/**
 * @brief The base Order definition specifies the properties that are common to all Orders.
 *
 * Order is an application/json object with the following Schema:
 */
struct Order {
	Order():
		state(oanda::v20::order::OrderState::UNDEFINED)
	{}

	/**
	 * @brief The Order’s identifier, unique within the Order’s Account.
	 */
	oanda::v20::order::OrderID id;

	/**
	 * @brief The time when the Order was created.
	 */
	oanda::v20::primitives::DateTime createTime;

	/**
	 * @brief The current state of the Order.
	 */
	oanda::v20::order::OrderState state;

	/**
	 * @brief The client extensions of the Order. Do not set, modify, or delete
	 *		  clientExtensions if your account is associated with MT4.
	 */
	oanda::v20::transaction::ClientExtensions clientExtensions;
};

} /* namespace order */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ORDER_ORDER_HPP */
