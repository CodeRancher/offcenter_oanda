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
 * @file   MarketOrderMarginCloseout.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_MARKETORDERMARGINCLOSEOUT_HPP
#define OANDA_V20_TRANSACTION_MARKETORDERMARGINCLOSEOUT_HPP

#include <string>
#include <vector>

#include "oanda/v20/transaction/TransactionDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * Details for the Market Order extensions specific to a Market Order placed that is part of a Market Order Margin Closeout in a client’s account
 * MarketOrderMarginCloseout is an application/json object with the following Schema:
 */
struct MarketOrderMarginCloseout {
	MarketOrderMarginCloseout():
		reason(oanda::v20::transaction::MarketOrderMarginCloseoutReason::UNDEFINED)
	{}

	/**
	 *  The reason the Market Order was created to perform a margin closeout
	 */
	oanda::v20::transaction::MarketOrderMarginCloseoutReason reason;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_MARKETORDERMARGINCLOSEOUT_HPP */
