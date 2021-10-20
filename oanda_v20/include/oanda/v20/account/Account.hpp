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
 * @file   Account.hpp
 * @author Scott Brauer
 * @date   12-07-2020
 */

#ifndef OANDA_V20_ACCOUNT_ACCOUNT_HPP
#define OANDA_V20_ACCOUNT_ACCOUNT_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"
#include "oanda/v20/account/AccountDefinitions.hpp"
#include "oanda/v20/trade/TradeSummary.hpp"
#include "oanda/v20/order/Order.hpp"
#include "oanda/v20/position/Position.hpp"
#include "oanda/v20/account/GuaranteedStopLossOrderParameters.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"
#include "oanda/v20/common/CommonDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace account {

/**
 * @brief The full details of a client’s Account. This includes full open Trade, open Position and pending Order representation.
 * 		  Account is an application/json object with the following Schema:
 */
struct Account {
	Account():
		createdByUserID(0),
		guaranteedStopLossOrderMode(oanda::v20::account::GuaranteedStopLossOrderMode::UNDEFINED),
		guaranteedStopLossOrderMutability(oanda::v20::account::GuaranteedStopLossOrderMutability::UNDEFINED),
		openTradeCount(0),
		openPositionCount(0),
		pendingOrderCount(0),
		hedgingEnabled(oanda::v20::common::BoolType::Undefined),
		marginCallExtensionCount(0)
	{}

	/**
	 * @brief The Account’s identifier
	 */
	oanda::v20::account::AccountID id;

	/**
	 * @brief Client-assigned alias for the Account. Only provided if the Account has an alias set
	 */
	oanda::v20::common::String alias;

	/**
	 * @brief The home currency of the Account
	 */
	oanda::v20::primitives::Currency currency;

	/**
	 * @brief ID of the user that created the Account.
	 */
	int createdByUserID;

	/**
	 * @brief The date/time when the Account was created.
	 */
	oanda::v20::primitives::DateTime createdTime;

	/**
	 * @brief The current guaranteed Stop Loss Order settings of the Account. This
	 *		  field will only be present if the guaranteedStopLossOrderMode is not ‘DISABLED’.
	 */
	oanda::v20::account::GuaranteedStopLossOrderParameters guaranteedStopLossOrderParameters;

	/**
	 * @brief The current guaranteed Stop Loss Order mode of the Account.
	 */
	oanda::v20::account::GuaranteedStopLossOrderMode guaranteedStopLossOrderMode;

	/**
	 * @brief The current guaranteed Stop Loss Order mutability setting of the Account.
	 *		  This field will only be present if the guaranteedStopLossOrderMode is not ‘DISABLED’.
	 * @deprecated Will be removed in a future API update.
	 */
	oanda::v20::account::GuaranteedStopLossOrderMutability guaranteedStopLossOrderMutability;

	/**
	 * @brief The date/time that the Account’s resettablePL was last reset.
	 */
	oanda::v20::primitives::DateTime resettablePLTime;

	/**
	 * @brief Client-provided margin rate override for the Account. The effective
	 *		  margin rate of the Account is the lesser of this value and the OANDA
	 *		  margin rate for the Account’s division. This value is only provided if a
	 *		  margin rate override exists for the Account.
	 */
	oanda::v20::primitives::DecimalNumber marginRate;

	/**
	 * @brief The number of Trades currently open in the Account.
	 */
	int openTradeCount;

	/**
	 * @brief The number of Positions currently open in the Account.
	 */
	int openPositionCount;

	/**
	 * @brief The number of Orders currently pending in the Account.
	 */
	int pendingOrderCount;

	/**
	 * @brief Flag indicating that the Account has hedging enabled.
	 */
	oanda::v20::common::BoolType hedgingEnabled;

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
	 * @brief The ID of the last Transaction created for the Account.
	 */
	oanda::v20::transaction::TransactionID lastTransactionID;

	/**
	 * @brief The details of the Trades currently open in the Account.
	 */
	std::vector<oanda::v20::trade::TradeSummary> trades;

	/**
	 * @brief The details all Account Positions.
	 */
	std::vector<oanda::v20::position::Position> positions;

	/**
	 * @brief The details of the Orders currently pending in the Account.
	 */
	std::vector<oanda::v20::order::Order> orders;
};

} /* namespace account */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ACCOUNT_ACCOUNT_HPP */
