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
 * @file   DailyFinancingTransaction.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_DAILYFINANCINGTRANSACTION_HPP
#define OANDA_V20_TRANSACTION_DAILYFINANCINGTRANSACTION_HPP

#include <string>
#include <vector>

#include "oanda/v20/account/AccountDefinitions.hpp"
#include "oanda/v20/transaction/PositionFinancing.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * A DailyFinancingTransaction represents the daily payment/collection of financing for an Account.
 * DailyFinancingTransaction is an application/json object with the following Schema:
 */
struct DailyFinancingTransaction {
	DailyFinancingTransaction():
		userID(0),
		type(oanda::v20::transaction::TransactionType::UNDEFINED),
		accountFinancingMode(oanda::v20::account::AccountFinancingMode::UNDEFINED)
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
	 *  The Type of the Transaction. Always set to “DAILY_FINANCING” for a
	 *  DailyFinancingTransaction.
	 */
	oanda::v20::transaction::TransactionType type;

	/**
	 *  The amount of financing paid/collected for the Account.
	 */
	oanda::v20::primitives::AccountUnits financing;

	/**
	 *  The Account’s balance after daily financing.
	 */
	oanda::v20::primitives::AccountUnits accountBalance;

	/**
	 *  The account financing mode at the time of the daily financing. This field
	 *  is no longer in use moving forward and was replaced by
	 *  accountFinancingMode in individual positionFinancings since the financing
	 *  mode could differ between instruments.
	 *  <b>Deprecated</b>: Will be removed in a future API update.
	 */
	oanda::v20::account::AccountFinancingMode accountFinancingMode;

	/**
	 *  The financing paid/collected for each Position in the Account.
	 */
	std::vector<oanda::v20::transaction::PositionFinancing> positionFinancings;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_DAILYFINANCINGTRANSACTION_HPP */
