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
 * @file   TradeOpen.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_TRADEOPEN_HPP
#define OANDA_V20_TRANSACTION_TRADEOPEN_HPP

#include <string>
#include <vector>

#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * A TradeOpen object represents a Trade for an instrument that was opened in an Account. It is found embedded in Transactions that affect the position of an instrument in the Account, specifically the OrderFill Transaction.
 * TradeOpen is an application/json object with the following Schema:
 */
struct TradeOpen {

	/**
	 *  The ID of the Trade that was opened
	 */
	oanda::v20::trade::TradeID tradeID;

	/**
	 *  The number of units opened by the Trade
	 */
	oanda::v20::primitives::DecimalNumber units;

	/**
	 *  The average price that the units were opened at.
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 *  This is the fee charged for opening the trade if it has a guaranteed Stop
	 *  Loss Order attached to it.
	 */
	oanda::v20::primitives::AccountUnits guaranteedExecutionFee;

	/**
	 *  This is the fee charged for opening the trade if it has a guaranteed Stop
	 *  Loss Order attached to it, expressed in the Instrument’s quote currency.
	 */
	oanda::v20::primitives::DecimalNumber quoteGuaranteedExecutionFee;

	/**
	 *  The client extensions for the newly opened Trade
	 */
	oanda::v20::transaction::ClientExtensions clientExtensions;

	/**
	 *  The half spread cost for the trade open. This can be a positive or
	 *  negative value and is represented in the home currency of the Account.
	 */
	oanda::v20::primitives::AccountUnits halfSpreadCost;

	/**
	 *  The margin required at the time the Trade was created. Note, this is the
	 *  ‘pure’ margin required, it is not the ‘effective’ margin used that
	 *  factors in the trade risk if a GSLO is attached to the trade.
	 */
	oanda::v20::primitives::AccountUnits initialMarginRequired;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_TRADEOPEN_HPP */
