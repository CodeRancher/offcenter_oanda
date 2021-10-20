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
 * @file   TradeReduce.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_TRADEREDUCE_HPP
#define OANDA_V20_TRANSACTION_TRADEREDUCE_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * A TradeReduce object represents a Trade for an instrument that was reduced (either partially or fully) in an Account. It is found embedded in Transactions that affect the position of an instrument in the account, specifically the OrderFill Transaction.
 * TradeReduce is an application/json object with the following Schema:
 */
struct TradeReduce {

	/**
	 *  The ID of the Trade that was reduced or closed
	 */
	oanda::v20::trade::TradeID tradeID;

	/**
	 *  The number of units that the Trade was reduced by
	 */
	oanda::v20::primitives::DecimalNumber units;

	/**
	 *  The average price that the units were closed at. This price may be
	 *  clamped for guaranteed Stop Loss Orders.
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 *  The PL realized when reducing the Trade
	 */
	oanda::v20::primitives::AccountUnits realizedPL;

	/**
	 *  The financing paid/collected when reducing the Trade
	 */
	oanda::v20::primitives::AccountUnits financing;

	/**
	 *  The base financing paid/collected when reducing the Trade
	 */
	oanda::v20::primitives::DecimalNumber baseFinancing;

	/**
	 *  The quote financing paid/collected when reducing the Trade
	 */
	oanda::v20::primitives::DecimalNumber quoteFinancing;

	/**
	 *  The financing rate in effect for the instrument used to calculate the
	 *  amount of financing paid/collected when reducing the Trade. This field
	 *  will only be set if the AccountFinancingMode at the time of the order
	 *  fill is SECOND_BY_SECOND_INSTRUMENT. The value is in decimal rather than
	 *  percentage points, e.g. 5% is represented as 0.05.
	 */
	oanda::v20::primitives::DecimalNumber financingRate;

	/**
	 *  This is the fee that is charged for closing the Trade if it has a
	 *  guaranteed Stop Loss Order attached to it.
	 */
	oanda::v20::primitives::AccountUnits guaranteedExecutionFee;

	/**
	 *  This is the fee that is charged for closing the Trade if it has a
	 *  guaranteed Stop Loss Order attached to it, expressed in the Instrument’s
	 *  quote currency.
	 */
	oanda::v20::primitives::DecimalNumber quoteGuaranteedExecutionFee;

	/**
	 *  The half spread cost for the trade reduce/close. This can be a positive
	 *  or negative value and is represented in the home currency of the Account.
	 */
	oanda::v20::primitives::AccountUnits halfSpreadCost;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_TRADEREDUCE_HPP */
