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
 * @file   OpenTradeFinancing.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_OPENTRADEFINANCING_HPP
#define OANDA_V20_TRANSACTION_OPENTRADEFINANCING_HPP

#include <string>
#include <vector>

#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * OpenTradeFinancing is used to pay/collect daily financing charge for an open Trade within an Account
 * OpenTradeFinancing is an application/json object with the following Schema:
 */
struct OpenTradeFinancing {

	/**
	 *  The ID of the Trade that financing is being paid/collected for.
	 */
	oanda::v20::trade::TradeID tradeID;

	/**
	 *  The amount of financing paid/collected for the Trade.
	 */
	oanda::v20::primitives::AccountUnits financing;

	/**
	 *  The amount of financing paid/collected in the Instrument’s base currency
	 *  for the Trade.
	 */
	oanda::v20::primitives::DecimalNumber baseFinancing;

	/**
	 *  The amount of financing paid/collected in the Instrument’s quote currency
	 *  for the Trade.
	 */
	oanda::v20::primitives::DecimalNumber quoteFinancing;

	/**
	 *  The financing rate in effect for the instrument used to calculate the the
	 *  amount of financing paid/collected for the Trade. This field will only be
	 *  set if the AccountFinancingMode at the time of the daily financing is
	 *  DAILY_INSTRUMENT or SECOND_BY_SECOND_INSTRUMENT. The value is in decimal
	 *  rather than percentage points, e.g. 5% is represented as 0.05.
	 */
	oanda::v20::primitives::DecimalNumber financingRate;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_OPENTRADEFINANCING_HPP */
