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
 * @file   LiquidityRegenerationScheduleStep.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_LIQUIDITYREGENERATIONSCHEDULESTEP_HPP
#define OANDA_V20_TRANSACTION_LIQUIDITYREGENERATIONSCHEDULESTEP_HPP

#include <string>
#include <vector>

#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * A liquidity regeneration schedule Step indicates the amount of bid and ask liquidity that is used by the Account at a certain time. These amounts will only change at the timestamp of the following step.
 * LiquidityRegenerationScheduleStep is an application/json object with the following Schema:
 */
struct LiquidityRegenerationScheduleStep {

	/**
	 *  The timestamp of the schedule step.
	 */
	oanda::v20::primitives::DateTime timestamp;

	/**
	 *  The amount of bid liquidity used at this step in the schedule.
	 */
	oanda::v20::primitives::DecimalNumber bidLiquidityUsed;

	/**
	 *  The amount of ask liquidity used at this step in the schedule.
	 */
	oanda::v20::primitives::DecimalNumber askLiquidityUsed;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_LIQUIDITYREGENERATIONSCHEDULESTEP_HPP */
