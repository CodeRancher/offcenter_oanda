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
 * @file   ClientPrice.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRICING_CLIENTPRICE_HPP
#define OANDA_V20_PRICING_CLIENTPRICE_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"
#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/pricing_common/PriceBucket.hpp"
#include "oanda/v20/pricing/QuoteHomeConversionFactors.hpp"
#include "oanda/v20/pricing/PricingDefinitions.hpp"
#include "oanda/v20/order/UnitsAvailable.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"
#include "oanda/v20/common/CommonDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace pricing {

/**
 * The specification of an Account-specific Price.
 * ClientPrice is an application/json object with the following Schema:
 */
struct ClientPrice {
	ClientPrice():
		status(oanda::v20::pricing::PriceStatus::UNDEFINED),
		tradeable(oanda::v20::common::BoolType::Undefined)
	{}

	/**
	 *  The string “PRICE”. Used to identify the a Price object when found in a
	 *  stream.
	 */
	oanda::v20::common::String type;

	/**
	 *  The Price’s Instrument.
	 */
	oanda::v20::primitives::InstrumentName instrument;

	/**
	 *  The date/time when the Price was created
	 */
	oanda::v20::primitives::DateTime time;

	/**
	 *  The status of the Price.
	 *  <b>Deprecated</b>: Will be removed in a future API update.
	 */
	oanda::v20::pricing::PriceStatus status;

	/**
	 *  Flag indicating if the Price is tradeable or not
	 */
	oanda::v20::common::BoolType tradeable;

	/**
	 *  The list of prices and liquidity available on the Instrument’s bid side.
	 *  It is possible for this list to be empty if there is no bid liquidity
	 *  currently available for the Instrument in the Account.
	 */
	std::vector<oanda::v20::pricing_common::PriceBucket> bids;

	/**
	 *  The list of prices and liquidity available on the Instrument’s ask side.
	 *  It is possible for this list to be empty if there is no ask liquidity
	 *  currently available for the Instrument in the Account.
	 */
	std::vector<oanda::v20::pricing_common::PriceBucket> asks;

	/**
	 *  The closeout bid Price. This Price is used when a bid is required to
	 *  closeout a Position (margin closeout or manual) yet there is no bid
	 *  liquidity. The closeout bid is never used to open a new position.
	 */
	oanda::v20::pricing_common::PriceValue closeoutBid;

	/**
	 *  The closeout ask Price. This Price is used when a ask is required to
	 *  closeout a Position (margin closeout or manual) yet there is no ask
	 *  liquidity. The closeout ask is never used to open a new position.
	 */
	oanda::v20::pricing_common::PriceValue closeoutAsk;

	/**
	 *  The factors used to convert quantities of this price’s Instrument’s quote
	 *  currency into a quantity of the Account’s home currency. When the
	 *  includeHomeConversions is present in the pricing request (regardless of
	 *  its value), this field will not be present.
	 *  <b>Deprecated</b>: Will be removed in a future API update.
	 */
	oanda::v20::pricing::QuoteHomeConversionFactors quoteHomeConversionFactors;

	/**
	 *  Representation of how many units of an Instrument are available to be
	 *  traded by an Order depending on its positionFill option.
	 *  <b>Deprecated</b>: Will be removed in a future API update.
	 */
	oanda::v20::order::UnitsAvailable unitsAvailable;
};

} /* namespace pricing */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRICING_CLIENTPRICE_HPP */
