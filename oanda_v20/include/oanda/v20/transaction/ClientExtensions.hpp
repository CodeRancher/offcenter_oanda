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
 * @file   ClientExtensions.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_CLIENTEXTENSIONS_HPP
#define OANDA_V20_TRANSACTION_CLIENTEXTENSIONS_HPP

#include <string>
#include <vector>

#include "oanda/v20/transaction/TransactionDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * A ClientExtensions object allows a client to attach a clientID, tag and comment to Orders and Trades in their Account. Do not set, modify, or delete this field if your account is associated with MT4.
 * ClientExtensions is an application/json object with the following Schema:
 */
struct ClientExtensions {

	/**
	 *  The Client ID of the Order/Trade
	 */
	oanda::v20::transaction::ClientID id;

	/**
	 *  A tag associated with the Order/Trade
	 */
	oanda::v20::transaction::ClientTag tag;

	/**
	 *  A comment associated with the Order/Trade
	 */
	oanda::v20::transaction::ClientComment comment;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_CLIENTEXTENSIONS_HPP */
