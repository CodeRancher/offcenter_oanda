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
 * @file   TakeProfitDetails.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_TAKEPROFITDETAILS_HPP
#define OANDA_V20_TRANSACTION_TAKEPROFITDETAILS_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * TakeProfitDetails specifies the details of a Take Profit Order to be created on behalf of a client. This may happen when an Order is filled that opens a Trade requiring a Take Profit, or when a Trade’s dependent Take Profit Order is modified directly through the Trade.
 * TakeProfitDetails is an application/json object with the following Schema:
 */
struct TakeProfitDetails {
	TakeProfitDetails():
		timeInForce(oanda::v20::order::TimeInForce::UNDEFINED)
	{}

	/**
	 *  The price that the Take Profit Order will be triggered at. Only one of
	 *  the price and distance fields may be specified.
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 *  The time in force for the created Take Profit Order. This may only be
	 *  GTC, GTD or GFD.
	 */
	oanda::v20::order::TimeInForce timeInForce;

	/**
	 *  The date when the Take Profit Order will be cancelled on if timeInForce
	 *  is GTD.
	 */
	oanda::v20::primitives::DateTime gtdTime;

	/**
	 *  The Client Extensions to add to the Take Profit Order when created.
	 */
	oanda::v20::transaction::ClientExtensions clientExtensions;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_TAKEPROFITDETAILS_HPP */
