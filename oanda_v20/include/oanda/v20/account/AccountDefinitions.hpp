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
 * @file   AccountDefinitions.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ACCOUNT_ACCOUNTDEFINITIONS_HPP
#define OANDA_V20_ACCOUNT_ACCOUNTDEFINITIONS_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"

namespace oanda {
namespace v20 {
namespace account {

/**
 * @brief The string representation of an Account Identifier.
 */
using AccountID = oanda::v20::common::String;

/**
 * @brief The overall behaviour of the Account regarding guaranteed Stop Loss Orders.
 */
enum class GuaranteedStopLossOrderMode {
	UNDEFINED = 0, ///< Default value allows json to be blank
	REQUIRED,	///< The Account is required to have guaranteed Stop Loss Orders for all open Trades.
	DISABLED,	///< The Account is not permitted to create guaranteed Stop Loss Orders.
	ALLOWED		///< The Account is able, but not required to have guaranteed Stop Loss Orders for open Trades.
};

/**
 * @brief For Accounts that support guaranteed Stop Loss Orders, describes the actions that can be be performed on guaranteed Stop Loss Orders.
 */
enum class GuaranteedStopLossOrderMutability {
	UNDEFINED = 0,		///< Default value allows json to be blank
	REPLACEABLE,		///< An existing guaranteed Stop Loss Order can only be replaced, not cancelled.
	PRICE_WIDEN_ONLY,	///< An existing guaranteed Stop Loss Order can only be replaced to widen the gap from the current price, not cancelled.
	CANCELABLE,			///< Once a guaranteed Stop Loss Order has been created it can be either replaced or cancelled.
	FIXED				///< Once a guaranteed Stop Loss Order has been created it cannot be replaced or cancelled.
};

/**
 * @brief The financing mode of an Account
 */
enum class AccountFinancingMode {
	UNDEFINED = 0,		///< Default value allows json to be blank
	DAILY,				///< A full day’s worth of financing is paid/charged for open Trades in the Account daily at 5pm New York time
	SECOND_BY_SECOND,	///< Second-by-second financing is paid/charged for open Trades in the Account, both daily and when the the Trade is closed
	NO_FINANCING		///< No financing is paid/charged for open Trades in the Account
};

/**
 * @brief The way that position values for an Account are calculated and aggregated.
 */
enum class PositionAggregationMode {
	UNDEFINED = 0,	///< Default value allows json to be blank
	NET_SUM,		///< The units for each side (long and short) of the Position are netted together and the resulting value
					///< (long or short) is used to compute the Position value or margin.
	MAXIMAL_SIDE,	///< The Position value or margin for each side (long and short) of the Position are computed independently.
					///< The Position value or margin chosen is the maximal absolute value of the two.
	ABSOLUTE_SUM	///< The Position value or margin for each side (long and short) of the Position are computed independently and added together.
};

} /* namespace account */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ACCOUNT_ACCOUNTDEFINITIONS_HPP */
