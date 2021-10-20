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
 * @file   OpenTradeDividendAdjustment.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_OPENTRADEDIVIDENDADJUSTMENT_HPP
#define OANDA_V20_TRANSACTION_OPENTRADEDIVIDENDADJUSTMENT_HPP

#include <string>
#include <vector>

#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * Used to pay or collect a dividend adjustment amount for an open Trade within the Account.
 * OpenTradeDividendAdjustment is an application/json object with the following Schema:
 */
struct OpenTradeDividendAdjustment {

	/**
	 *  The ID of the Trade for which the dividend adjustment is to be paid or
	 *  collected.
	 */
	oanda::v20::trade::TradeID tradeID;

	/**
	 *  The dividend adjustment amount to pay or collect for the Trade.
	 */
	oanda::v20::primitives::AccountUnits dividendAdjustment;

	/**
	 *  The dividend adjustment amount to pay or collect for the Trade, in the
	 *  Instrument’s quote currency.
	 */
	oanda::v20::primitives::DecimalNumber quoteDividendAdjustment;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_OPENTRADEDIVIDENDADJUSTMENT_HPP */
