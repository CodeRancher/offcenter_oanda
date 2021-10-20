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
 * @file   FinancingDayOfWeek.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRIMATIVES_FINANCINGDAYOFWEEK_HPP
#define OANDA_V20_PRIMATIVES_FINANCINGDAYOFWEEK_HPP

#include <string>
#include <vector>

#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace primitives {

/**
 * A FinancingDayOfWeek message defines a day of the week when financing charges are debited or credited.
 * FinancingDayOfWeek is an application/json object with the following Schema:
 */
struct FinancingDayOfWeek {
	FinancingDayOfWeek():
		dayOfWeek(oanda::v20::primitives::DayOfWeek::UNDEFINED),
		daysCharged(0)
	{}

	/**
	 *  The day of the week to charge the financing.
	 */
	oanda::v20::primitives::DayOfWeek dayOfWeek;

	/**
	 *  The number of days worth of financing to be charged on dayOfWeek.
	 */
	int daysCharged;
};

} /* namespace primitives */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRIMATIVES_FINANCINGDAYOFWEEK_HPP */
