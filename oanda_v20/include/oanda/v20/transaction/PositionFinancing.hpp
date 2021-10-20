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
 * @file   PositionFinancing.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_POSITIONFINANCING_HPP
#define OANDA_V20_TRANSACTION_POSITIONFINANCING_HPP

#include <string>
#include <vector>

#include "oanda/v20/account/AccountDefinitions.hpp"
#include "oanda/v20/primitives/HomeConversionFactors.hpp"
#include "oanda/v20/transaction/OpenTradeFinancing.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * OpenTradeFinancing is used to pay/collect daily financing charge for a Position within an Account
 * PositionFinancing is an application/json object with the following Schema:
 */
struct PositionFinancing {
	PositionFinancing():
		accountFinancingMode(oanda::v20::account::AccountFinancingMode::UNDEFINED)
	{}

	/**
	 *  The instrument of the Position that financing is being paid/collected
	 *  for.
	 */
	oanda::v20::primitives::InstrumentName instrument;

	/**
	 *  The amount of financing paid/collected for the Position.
	 */
	oanda::v20::primitives::AccountUnits financing;

	/**
	 *  The amount of base financing paid/collected for the Position.
	 */
	oanda::v20::primitives::DecimalNumber baseFinancing;

	/**
	 *  The amount of quote financing paid/collected for the Position.
	 */
	oanda::v20::primitives::DecimalNumber quoteFinancing;

	/**
	 *  The HomeConversionFactors in effect for the Position’s Instrument at the
	 *  time of the DailyFinancing.
	 */
	oanda::v20::primitives::HomeConversionFactors homeConversionFactors;

	/**
	 *  The financing paid/collected for each open Trade within the Position.
	 */
	std::vector<oanda::v20::transaction::OpenTradeFinancing> openTradeFinancings;

	/**
	 *  The account financing mode at the time of the daily financing.
	 */
	oanda::v20::account::AccountFinancingMode accountFinancingMode;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_POSITIONFINANCING_HPP */
