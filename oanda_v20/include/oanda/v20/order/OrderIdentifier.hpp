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
 * @file   OrderIdentifier.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_ORDERIDENTIFIER_HPP
#define OANDA_V20_ORDER_ORDERIDENTIFIER_HPP

#include <string>
#include <vector>

#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace order {

/**
 * @brief An OrderIdentifier is used to refer to an Order, and contains both the OrderID and the ClientOrderID.
 *
 * OrderIdentifier is an application/json object with the following Schema:
 */
struct OrderIdentifier {

	/**
	 * @brief The OANDA-assigned Order ID
	 */
	oanda::v20::order::OrderID orderID;

	/**
	 * @brief The client-provided client Order ID
	 */
	oanda::v20::transaction::ClientID clientOrderID;
};

} /* namespace order */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ORDER_ORDERIDENTIFIER_HPP */
