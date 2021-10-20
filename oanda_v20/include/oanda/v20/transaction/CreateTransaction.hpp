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
 * @file   CreateTransaction.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_CREATETRANSACTION_HPP
#define OANDA_V20_TRANSACTION_CREATETRANSACTION_HPP

#include <string>
#include <vector>

#include "oanda/v20/account/AccountDefinitions.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * A CreateTransaction represents the creation of an Account.
 * CreateTransaction is an application/json object with the following Schema:
 */
struct CreateTransaction {
	CreateTransaction():
		userID(0),
		type(oanda::v20::transaction::TransactionType::UNDEFINED),
		divisionID(0),
		siteID(0),
		accountUserID(0),
		accountNumber(0)
	{}

	/**
	 *  The Transaction’s Identifier.
	 */
	oanda::v20::transaction::TransactionID id;

	/**
	 *  The date/time when the Transaction was created.
	 */
	oanda::v20::primitives::DateTime time;

	/**
	 *  The ID of the user that initiated the creation of the Transaction.
	 */
	int userID;

	/**
	 *  The ID of the Account the Transaction was created for.
	 */
	oanda::v20::account::AccountID accountID;

	/**
	 *  The ID of the “batch” that the Transaction belongs to. Transactions in
	 *  the same batch are applied to the Account simultaneously.
	 */
	oanda::v20::transaction::TransactionID batchID;

	/**
	 *  The Request ID of the request which generated the transaction.
	 */
	oanda::v20::transaction::RequestID requestID;

	/**
	 *  The Type of the Transaction. Always set to “CREATE” in a
	 *  CreateTransaction.
	 */
	oanda::v20::transaction::TransactionType type;

	/**
	 *  The ID of the Division that the Account is in
	 */
	int divisionID;

	/**
	 *  The ID of the Site that the Account was created at
	 */
	int siteID;

	/**
	 *  The ID of the user that the Account was created for
	 */
	int accountUserID;

	/**
	 *  The number of the Account within the site/division/user
	 */
	int accountNumber;

	/**
	 *  The home currency of the Account
	 */
	oanda::v20::primitives::Currency homeCurrency;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_CREATETRANSACTION_HPP */
