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
 * @file   LiquidityRegenerationSchedule.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_LIQUIDITYREGENERATIONSCHEDULE_HPP
#define OANDA_V20_TRANSACTION_LIQUIDITYREGENERATIONSCHEDULE_HPP

#include <string>
#include <vector>

#include "oanda/v20/transaction/LiquidityRegenerationScheduleStep.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * A LiquidityRegenerationSchedule indicates how liquidity that is used when filling an Order for an instrument is regenerated following the fill. A liquidity regeneration schedule will be in effect until the timestamp of its final step, but may be replaced by a schedule created for an Order of the same instrument that is filled while it is still in effect.
 * LiquidityRegenerationSchedule is an application/json object with the following Schema:
 */
struct LiquidityRegenerationSchedule {

	/**
	 *  The steps in the Liquidity Regeneration Schedule
	 */
	std::vector<oanda::v20::transaction::LiquidityRegenerationScheduleStep> steps;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_LIQUIDITYREGENERATIONSCHEDULE_HPP */
