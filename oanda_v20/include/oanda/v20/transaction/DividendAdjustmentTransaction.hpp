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
 * @file   DividendAdjustmentTransaction.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_DIVIDENDADJUSTMENTTRANSACTION_HPP
#define OANDA_V20_TRANSACTION_DIVIDENDADJUSTMENTTRANSACTION_HPP

#include <string>
#include <vector>

#include "oanda/v20/account/AccountDefinitions.hpp"
#include "oanda/v20/primitives/HomeConversionFactors.hpp"
#include "oanda/v20/transaction/OpenTradeDividendAdjustment.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * A DividendAdjustment Transaction is created administratively to pay or collect dividend adjustment mounts to or from an Account.
 * DividendAdjustmentTransaction is an application/json object with the following Schema:
 */
struct DividendAdjustmentTransaction {
	DividendAdjustmentTransaction():
		userID(),
		type(oanda::v20::transaction::TransactionType::UNDEFINED)
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
	 *  The Type of the Transaction. Always set to “DIVIDEND_ADJUSTMENT” for a
	 *  DividendAdjustmentTransaction.
	 */
	oanda::v20::transaction::TransactionType type;

	/**
	 *  The name of the instrument for the dividendAdjustment transaction
	 */
	oanda::v20::primitives::InstrumentName instrument;

	/**
	 *  The total dividend adjustment amount paid or collected in the Account’s
	 *  home currency for the Account as a result of applying the
	 *  DividendAdjustment Transaction. This is the sum of the dividend
	 *  adjustments paid/collected for each OpenTradeDividendAdjustment found
	 *  within the Transaction.
	 */
	oanda::v20::primitives::AccountUnits dividendAdjustment;

	/**
	 *  The total dividend adjustment amount paid or collected in the
	 *  Instrument’s quote currency for the Account as a result of applying the
	 *  DividendAdjustment Transaction. This is the sum of the quote dividend
	 *  adjustments paid/collected for each OpenTradeDividendAdjustment found
	 *  within the Transaction.
	 */
	oanda::v20::primitives::DecimalNumber quoteDividendAdjustment;

	/**
	 *  The HomeConversionFactors in effect at the time of the
	 *  DividendAdjustment.
	 */
	oanda::v20::primitives::HomeConversionFactors homeConversionFactors;

	/**
	 *  The Account balance after applying the DividendAdjustment Transaction
	 */
	oanda::v20::primitives::AccountUnits accountBalance;

	/**
	 *  The dividend adjustment payment/collection details for each open Trade,
	 *  within the Account, for which a dividend adjustment is to be paid or
	 *  collected.
	 */
	std::vector<oanda::v20::transaction::OpenTradeDividendAdjustment> openTradeDividendAdjustments;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_DIVIDENDADJUSTMENTTRANSACTION_HPP */
