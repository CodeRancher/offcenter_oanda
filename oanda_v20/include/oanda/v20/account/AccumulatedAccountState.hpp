/**
 * Copyright 2020 Scott Brauer
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an  BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file   AccumulatedAccountState.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ACCOUNT_ACCUMULATEDACCOUNTSTATE_HPP
#define OANDA_V20_ACCOUNT_ACCUMULATEDACCOUNTSTATE_HPP

#include <string>
#include <vector>

#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace account {

/**
 * @brief The mutable state of a client’s Account.
 *
 * AccumulatedAccountState is an application/json object with the following Schema:
 */
struct AccumulatedAccountState {
	AccumulatedAccountState():
		marginCallExtensionCount(0)
	{}

	/**
	 * @brief The current balance of the account.
	 */
	oanda::v20::primitives::AccountUnits balance;

	/**
	 * @brief The total profit/loss realized over the lifetime of the Account.
	 */
	oanda::v20::primitives::AccountUnits pl;

	/**
	 * @brief The total realized profit/loss for the account since it was last reset by the client.
	 */
	oanda::v20::primitives::AccountUnits resettablePL;

	/**
	 * @brief The total amount of financing paid/collected over the lifetime of the account.
	 */
	oanda::v20::primitives::AccountUnits financing;

	/**
	 * @brief The total amount of commission paid over the lifetime of the Account.
	 */
	oanda::v20::primitives::AccountUnits commission;

	/**
	 * @brief The total amount of dividend adjustment paid over the lifetime of the
	 * @brief Account in the Account’s home currency.
	 */
	oanda::v20::primitives::AccountUnits dividendAdjustment;

	/**
	 * @brief The total amount of fees charged over the lifetime of the Account for the
	 *		  execution of guaranteed Stop Loss Orders.
	 */
	oanda::v20::primitives::AccountUnits guaranteedExecutionFees;

	/**
	 * @brief The date/time when the Account entered a margin call state. Only provided
	 *		  if the Account is in a margin call.
	 */
	oanda::v20::primitives::DateTime marginCallEnterTime;

	/**
	 * @brief The number of times that the Account’s current margin call was extended.
	 */
	int marginCallExtensionCount;

	/**
	 * @brief The date/time of the Account’s last margin call extension.
	 */
	oanda::v20::primitives::DateTime lastMarginCallExtensionTime;
};

} /* namespace account */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ACCOUNT_ACCUMULATEDACCOUNTSTATE_HPP */
