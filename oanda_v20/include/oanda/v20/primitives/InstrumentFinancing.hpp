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
 * @file   InstrumentFinancing.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRIMATIVES_INSTRUMENTFINANCING_HPP
#define OANDA_V20_PRIMATIVES_INSTRUMENTFINANCING_HPP

#include <string>
#include <vector>

#include "oanda/v20/primitives/FinancingDayOfWeek.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace primitives {

/**
 * Financing data for the instrument.
 * InstrumentFinancing is an application/json object with the following Schema:
 */
struct InstrumentFinancing {

	/**
	 *  The financing rate to be used for a long position for the instrument. The
	 *  value is in decimal rather than percentage points, i.e. 5% is represented
	 *  as 0.05.
	 */
	oanda::v20::primitives::DecimalNumber longRate;

	/**
	 *  The financing rate to be used for a short position for the instrument.
	 *  The value is in decimal rather than percentage points, i.e. 5% is
	 *  represented as 0.05.
	 */
	oanda::v20::primitives::DecimalNumber shortRate;

	/**
	 *  The days of the week to debit or credit financing charges; the exact time
	 *  of day at which to charge the financing is set in the
	 *  DivisionTradingGroup for the client’s account.
	 */
	std::vector<oanda::v20::primitives::FinancingDayOfWeek> financingDaysOfWeek;
};

} /* namespace primitives */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRIMATIVES_INSTRUMENTFINANCING_HPP */
