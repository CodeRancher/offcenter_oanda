/**
 * Copyright 2020 Scott Brauer
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
	 * @brief    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an  BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file   AccountChangesState.hpp
 * @author Scott Brauer
 * @date   12-07-2020
 */

#ifndef OANDA_V20_ACCOUNT_ACCOUNTCHANGESSTATE_HPP
#define OANDA_V20_ACCOUNT_ACCOUNTCHANGESSTATE_HPP

#include <string>
#include <vector>

#include "oanda/v20/order/DynamicOrderState.hpp"
#include "oanda/v20/trade/CalculatedTradeState.hpp"
#include "oanda/v20/position/CalculatedPositionState.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace account {

/**
 * @brief An AccountState Object is used to represent an Account’s current price-dependent state.
 *
 * Price-dependent Account state is dependent on OANDA’s current Prices, and includes things
 * like unrealized PL, NAV and Trailing Stop Loss Order state. Fields will be omitted if their
 * value has not changed since the specified transaction ID.
 * AccountChangesState is an application/json object with the following Schema:
 */
struct AccountChangesState {
	AccountChangesState():
		marginCallExtensionCount(0)
	{}

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
	 * @brief positive value indicating how much can be withdrawn from the account.
	 */
	oanda::v20::primitives::AccountUnits withdrawalLimit;

	/**
	 * @brief The Account’s margin call margin used.
	 */
	oanda::v20::primitives::AccountUnits marginCallMarginUsed;

	/**
	 * @brief The Account’s margin call percentage. When this value is 1.0 or above the
	 *		  ccount is in a margin call situation.
	 */
	oanda::v20::primitives::DecimalNumber marginCallPercent;

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
	 *		  Account in the Account’s home currency.
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

	/**
	 * @brief The price-dependent state of each pending Order in the Account.
	 */
	std::vector<oanda::v20::order::DynamicOrderState> orders;

	/**
	 * @brief The price-dependent state for each open Trade in the Account.
	 */
	std::vector<oanda::v20::trade::CalculatedTradeState> trades;

	/**
	 * @brief The price-dependent state for each open Position in the Account.
	 */
	std::vector<oanda::v20::position::CalculatedPositionState> positions;
};

} /* namespace account */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ACCOUNT_ACCOUNTCHANGESSTATE_HPP */
