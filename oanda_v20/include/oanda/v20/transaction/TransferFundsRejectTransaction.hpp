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
 * @file   TransferFundsRejectTransaction.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_TRANSFERFUNDSREJECTTRANSACTION_HPP
#define OANDA_V20_TRANSACTION_TRANSFERFUNDSREJECTTRANSACTION_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"
#include "oanda/v20/account/AccountDefinitions.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * A TransferFundsRejectTransaction represents the rejection of the transfer of funds in/out of an Account.
 * TransferFundsRejectTransaction is an application/json object with the following Schema:
 */
struct TransferFundsRejectTransaction {
	TransferFundsRejectTransaction():
		userID(0),
		type(oanda::v20::transaction::TransactionType::UNDEFINED),
		fundingReason(oanda::v20::transaction::FundingReason::UNDEFINED),
		rejectReason(oanda::v20::transaction::TransactionRejectReason::UNDEFINED)
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
	 *  The Type of the Transaction. Always set to “TRANSFER_FUNDS_REJECT” in a
	 *  TransferFundsRejectTransaction.
	 */
	oanda::v20::transaction::TransactionType type;

	/**
	 *  The amount to deposit/withdraw from the Account in the Account’s home
	 *  currency. A positive value indicates a deposit, a negative value
	 *  indicates a withdrawal.
	 */
	oanda::v20::primitives::AccountUnits amount;

	/**
	 *  The reason that an Account is being funded.
	 */
	oanda::v20::transaction::FundingReason fundingReason;

	/**
	 *  An optional comment that may be attached to a fund transfer for audit
	 *  purposes
	 */
	oanda::v20::common::String comment;

	/**
	 *  The reason that the Reject Transaction was created
	 */
	oanda::v20::transaction::TransactionRejectReason rejectReason;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_TRANSFERFUNDSREJECTTRANSACTION_HPP */
