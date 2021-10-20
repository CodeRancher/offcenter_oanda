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
 * @file   Instrument.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRIMATIVES_INSTRUMENT_HPP
#define OANDA_V20_PRIMATIVES_INSTRUMENT_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"
#include "oanda/v20/primitives/Tag.hpp"
#include "oanda/v20/primitives/InstrumentFinancing.hpp"
#include "oanda/v20/primitives/InstrumentCommission.hpp"
#include "oanda/v20/primitives/GuaranteedStopLossOrderLevelRestriction.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace primitives {

/**
 * Full specification of an Instrument.
 * Instrument is an application/json object with the following Schema:
 */
struct Instrument {
	Instrument():
		type(oanda::v20::primitives::InstrumentType::UNDEFINED),
		pipLocation(0),
		displayPrecision(0),
		tradeUnitsPrecision(0),
		guaranteedStopLossOrderMode(oanda::v20::primitives::GuaranteedStopLossOrderModeForInstrument::UNDEFINED)
	{}

	/**
	 *  The name of the Instrument
	 */
	oanda::v20::primitives::InstrumentName name;

	/**
	 *  The type of the Instrument
	 */
	oanda::v20::primitives::InstrumentType type;

	/**
	 *  The display name of the Instrument
	 */
	oanda::v20::common::String displayName;

	/**
	 *  The location of the “pip” for this instrument. The decimal position of
	 *  the pip in this Instrument’s price can be found at 10 ^ pipLocation (e.g.
	 *  -4 pipLocation results in a decimal pip position of 10 ^ -4 = 0.0001).
	 */
	int pipLocation;

	/**
	 *  The number of decimal places that should be used to display prices for
	 *  this instrument. (e.g. a displayPrecision of 5 would result in a price of
	 *  “1” being displayed as “1.00000”)
	 */
	int displayPrecision;

	/**
	 *  The amount of decimal places that may be provided when specifying the
	 *  number of units traded for this instrument.
	 */
	int tradeUnitsPrecision;

	/**
	 *  The smallest number of units allowed to be traded for this instrument.
	 */
	oanda::v20::primitives::DecimalNumber minimumTradeSize;

	/**
	 *  The maximum trailing stop distance allowed for a trailing stop loss
	 *  created for this instrument. Specified in price units.
	 */
	oanda::v20::primitives::DecimalNumber maximumTrailingStopDistance;

	/**
	 *  The minimum distance allowed between the Trade’s fill price and the
	 *  configured price for guaranteed Stop Loss Orders created for this
	 *  instrument. Specified in price units.
	 */
	oanda::v20::primitives::DecimalNumber minimumGuaranteedStopLossDistance;

	/**
	 *  The minimum trailing stop distance allowed for a trailing stop loss
	 *  created for this instrument. Specified in price units.
	 */
	oanda::v20::primitives::DecimalNumber minimumTrailingStopDistance;

	/**
	 *  The maximum position size allowed for this instrument. Specified in
	 *  units.
	 */
	oanda::v20::primitives::DecimalNumber maximumPositionSize;

	/**
	 *  The maximum units allowed for an Order placed for this instrument.
	 *  Specified in units.
	 */
	oanda::v20::primitives::DecimalNumber maximumOrderUnits;

	/**
	 *  The margin rate for this instrument.
	 */
	oanda::v20::primitives::DecimalNumber marginRate;

	/**
	 *  The commission structure for this instrument.
	 */
	oanda::v20::primitives::InstrumentCommission commission;

	/**
	 *  The current Guaranteed Stop Loss Order mode of the Account for this
	 *  Instrument.
	 */
	oanda::v20::primitives::GuaranteedStopLossOrderModeForInstrument guaranteedStopLossOrderMode;

	/**
	 *  The amount that is charged to the account if a guaranteed Stop Loss Order
	 *  is triggered and filled. The value is in price units and is charged for
	 *  each unit of the Trade. This field will only be present if the Account’s
	 *  guaranteedStopLossOrderMode for this Instrument is not ‘DISABLED’.
	 */
	oanda::v20::primitives::DecimalNumber guaranteedStopLossOrderExecutionPremium;

	/**
	 *  The guaranteed Stop Loss Order level restriction for this instrument.
	 *  This field will only be present if the Account’s
	 *  guaranteedStopLossOrderMode for this Instrument is not ‘DISABLED’.
	 */
	oanda::v20::primitives::GuaranteedStopLossOrderLevelRestriction guaranteedStopLossOrderLevelRestriction;

	/**
	 *  Financing data for this instrument.
	 */
	oanda::v20::primitives::InstrumentFinancing financing;

	/**
	 *  The tags associated with this instrument.
	 */
	std::vector<oanda::v20::primitives::Tag> tags;
};

} /* namespace primitives */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRIMATIVES_INSTRUMENT_HPP */
