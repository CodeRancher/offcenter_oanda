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
 * @file   TrailingStopLossDetails.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_TRAILINGSTOPLOSSDETAILS_HPP
#define OANDA_V20_TRANSACTION_TRAILINGSTOPLOSSDETAILS_HPP

#include <string>
#include <vector>

#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * TrailingStopLossDetails specifies the details of a Trailing Stop Loss Order to be created on behalf of a client. This may happen when an Order is filled that opens a Trade requiring a Trailing Stop Loss, or when a Trade’s dependent Trailing Stop Loss Order is modified directly through the Trade.
 * TrailingStopLossDetails is an application/json object with the following Schema:
 */
struct TrailingStopLossDetails {
	TrailingStopLossDetails():
		timeInForce(oanda::v20::order::TimeInForce::UNDEFINED)
	{}

	/**
	 *  The distance (in price units) from the Trade’s fill price that the
	 *  Trailing Stop Loss Order will be triggered at.
	 */
	oanda::v20::primitives::DecimalNumber distance;

	/**
	 *  The time in force for the created Trailing Stop Loss Order. This may only
	 *  be GTC, GTD or GFD.
	 */
	oanda::v20::order::TimeInForce timeInForce;

	/**
	 *  The date when the Trailing Stop Loss Order will be cancelled on if
	 *  timeInForce is GTD.
	 */
	oanda::v20::primitives::DateTime gtdTime;

	/**
	 *  The Client Extensions to add to the Trailing Stop Loss Order when
	 *  created.
	 */
	oanda::v20::transaction::ClientExtensions clientExtensions;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_TRAILINGSTOPLOSSDETAILS_HPP */
