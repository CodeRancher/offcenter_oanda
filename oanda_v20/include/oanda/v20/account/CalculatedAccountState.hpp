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
 * @file   CalculatedAccountState.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ACCOUNT_CALCULATEDACCOUNTSTATE_HPP
#define OANDA_V20_ACCOUNT_CALCULATEDACCOUNTSTATE_HPP

#include <string>
#include <vector>

#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace account {

/**
 * @brief The dynamically calculated state of a client’s Account.
 *
 * CalculatedAccountState is an application/json object with the following Schema:
 */
struct CalculatedAccountState {

	/**
	 * @brief The total unrealized profit/loss for all Trades currently open in the Account.
	 */
	oanda::v20::primitives::AccountUnits unrealizedPL;

	/**
	 * @brief The net asset value of the Account. Equal to Account balance + unrealizedPL.
	 */
	oanda::v20::primitives::AccountUnits NAV;

	/**
	 * @brief Margin currently used for the Account.
	 */
	oanda::v20::primitives::AccountUnits marginUsed;

	/**
	 * @brief Margin available for Account currency.
	 */
	oanda::v20::primitives::AccountUnits marginAvailable;

	/**
	 * @brief The value of the Account’s open positions represented in the Account’s home currency.
	 */
	oanda::v20::primitives::AccountUnits positionValue;

	/**
	 * @brief The Account’s margin closeout unrealized PL.
	 */
	oanda::v20::primitives::AccountUnits marginCloseoutUnrealizedPL;

	/**
	 * @brief The Account’s margin closeout NAV.
	 */
	oanda::v20::primitives::AccountUnits marginCloseoutNAV;

	/**
	 * @brief The Account’s margin closeout margin used.
	 */
	oanda::v20::primitives::AccountUnits marginCloseoutMarginUsed;

	/**
	 * @brief The Account’s margin closeout percentage. When this value is 1.0 or above
	 *		  the Account is in a margin closeout situation.
	 */
	oanda::v20::primitives::DecimalNumber marginCloseoutPercent;

	/**
	 * @brief The value of the Account’s open positions as used for margin closeout
	 *		  calculations represented in the Account’s home currency.
	 */
	oanda::v20::primitives::DecimalNumber marginCloseoutPositionValue;

	/**
	 * @brief The current WithdrawalLimit for the account which will be zero or a
	 *		  positive value indicating how much can be withdrawn from the account.
	 */
	oanda::v20::primitives::AccountUnits withdrawalLimit;

	/**
	 * @brief The Account’s margin call margin used.
	 */
	oanda::v20::primitives::AccountUnits marginCallMarginUsed;

	/**
	 * @brief The Account’s margin call percentage. When this value is 1.0 or above the
	 *		  Account is in a margin call situation.
	 */
	oanda::v20::primitives::DecimalNumber marginCallPercent;
};

} /* namespace account */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ACCOUNT_CALCULATEDACCOUNTSTATE_HPP */
