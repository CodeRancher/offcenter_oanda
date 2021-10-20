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
 * @file   GuaranteedStopLossOrderParameters.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ACCOUNT_GUARANTEEDSTOPLOSSORDERPARAMETERS_HPP
#define OANDA_V20_ACCOUNT_GUARANTEEDSTOPLOSSORDERPARAMETERS_HPP

#include <string>
#include <vector>

#include "oanda/v20/account/AccountDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace account {

/**
 * @brief The current mutability and hedging settings related to guaranteed Stop Loss orders.
 *
 * GuaranteedStopLossOrderParameters is an application/json object with the following Schema:
 */
struct GuaranteedStopLossOrderParameters {
	GuaranteedStopLossOrderParameters():
		mutabilityMarketOpen(oanda::v20::account::GuaranteedStopLossOrderMutability::UNDEFINED),
		mutabilityMarketHalted(oanda::v20::account::GuaranteedStopLossOrderMutability::UNDEFINED)
	{}

	/**
	 * @brief The current guaranteed Stop Loss Order mutability setting of the Account
	 *		  when market is open.
	 */
	oanda::v20::account::GuaranteedStopLossOrderMutability mutabilityMarketOpen;

	/**
	 * @brief The current guaranteed Stop Loss Order mutability setting of the Account
	 *		  when market is halted.
	 */
	oanda::v20::account::GuaranteedStopLossOrderMutability mutabilityMarketHalted;
};

} /* namespace account */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ACCOUNT_GUARANTEEDSTOPLOSSORDERPARAMETERS_HPP */
