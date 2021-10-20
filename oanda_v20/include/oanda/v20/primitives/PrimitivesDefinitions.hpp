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
 * @file   PrimitivesDefinitions.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRIMATIVES_PRIMITIVESDEFINITIONS_HPP
#define OANDA_V20_PRIMATIVES_PRIMITIVESDEFINITIONS_HPP

#include <vector>
#include <sstream>

#include "oanda/v20/common/String.hpp"

namespace oanda {
namespace v20 {
namespace primitives {

/**
 * The string representation of a decimal number.
 * A decimal number encoded as a string. The amount of precision provided depends on what the number represents.
 */
using DecimalNumber = oanda::v20::common::String;

/**
 * The string representation of a quantity of an Account’s home currency.
 * A decimal number encoded as a string. The amount of precision provided depends on the Account’s home currency.
 */
using AccountUnits = oanda::v20::common::String;

/**
 * Currency name identifier. Used by clients to refer to currencies.
 * 
 */
using Currency = oanda::v20::common::String;

/**
 * Instrument name identifier. Used by clients to refer to an Instrument.
 * A string containing the base currency and quote currency delimited by a “_”.
 */
using InstrumentName = oanda::v20::common::String;

/**
 * The type of an Instrument.
 */
enum class InstrumentType {
	UNDEFINED = 0,	///< Default value allows json to be blank
	CFD,		///< Contract For Difference
	METAL,		///< Metal
	CURRENCY	///< Currency
};

/// Convert AcceptDatetimeFormat to string
void to_string(const InstrumentType& from, std::string& to);

/// Convert string to AcceptDatetimeFormat
void from_string(const std::string& from, InstrumentType& to);

/**
 * The DayOfWeek provides a representation of the day of the week.
 */
enum class DayOfWeek {
	UNDEFINED = 0,	///< Default value allows json to be blank
	SUNDAY,		///< Sunday
	SATURDAY,	///< Saturday
	THURSDAY,	///< Thursday
	MONDAY,		///< Monday
	WEDNESDAY,	///< Wednesday
	TUESDAY,	///< Tuesday
	FRIDAY		///< Friday
};

/// Convert DayOfWeek to string
void to_string(const DayOfWeek& from, std::string& to);

/// Convert string to DayOfWeek
void from_string(const std::string& from, DayOfWeek& to);

/// A date and time value using either RFC3339 or UNIX time representation.
using DateTime = oanda::v20::common::String;

/// DateTime header
enum class AcceptDatetimeFormat {
	UNDEFINED = 0,	///< Default value allows json to be blank
	UNIX,	///< If “UNIX” is specified DateTime fields will be specified or returned in the “12345678.000000123” format.
	RFC3339	///< If “RFC3339” is specified DateTime will be specified or returned in “YYYY-MM-DDTHH:MM:SS.nnnnnnnnnZ” format.
};

/// Convert AcceptDatetimeFormat to string
void to_string(const AcceptDatetimeFormat& from, std::string& to);

/// Convert string to AcceptDatetimeFormat
void from_string(const std::string& from, AcceptDatetimeFormat& to);

/**
 * The overall behaviour of the Account regarding Guaranteed Stop Loss Orders for a specific Instrument.
 */
enum class GuaranteedStopLossOrderModeForInstrument {
	UNDEFINED = 0,	///< Default value allows json to be blank
	REQUIRED,	///< The Account is required to have Guaranteed Stop Loss Orders for all open Trades for this Instrument.
	DISABLED,	///< The Account is not permitted to create Guaranteed Stop Loss Orders for this Instrument.
	ALLOWED		///< The Account is able, but not required to have Guaranteed Stop Loss Orders for open Trades for this Instrument.
};

/// Convert GuaranteedStopLossOrderModeForInstrument to string
void to_string(const GuaranteedStopLossOrderModeForInstrument& from, std::string& to);

/// Convert string to GuaranteedStopLossOrderModeForInstrument
void from_string(const std::string& from, GuaranteedStopLossOrderModeForInstrument& to);

/**
 * In the context of an Order or a Trade, defines whether the units are positive or negative.
 */
enum class Direction {
	UNDEFINED = 0,	///< Default value allows json to be blank
	SHORT,	///< A short Order is used to to sell units of an Instrument.
			///< A Trade is short when it has sold units of an Instrument.
	LONG	///< A long Order is used to to buy units of an Instrument.
			///< A Trade is long when it has bought units of an Instrument.
};

/**
 * Price component individual element
 */
enum class PricingComponentElement {
	M,	/// Midpoint candles
	B,	/// Bid candles
	A	/// Ask candles
};

/// Convert AcceptDatetimeFormat to string
void to_string(const PricingComponentElement& from, std::string& to);

/// Convert string to AcceptDatetimeFormat
void from_string(const std::string& from, PricingComponentElement& to);


/**
 * The Price component(s) to get candlestick data for.
 * Can contain any combination of the characters “M” (midpoint candles) “B” (bid candles) and “A” (ask candles).
 */
using PricingComponent = oanda::v20::common::String;

class PricingComponents {
public:
	explicit PricingComponents():
		m_midpointCandles(false),
		m_bidCandles(false),
		m_askCandles(false) {}
	bool midpointCandles() const { return m_midpointCandles; }
	bool bidCandles() const { return m_bidCandles; }
	bool askCandles() const { return m_askCandles; }
	void clear() {
		m_midpointCandles = false;
		m_bidCandles = false;
		m_askCandles = false;
	}
	void set(PricingComponentElement value) {
		switch(value) {
			case PricingComponentElement::M: m_midpointCandles = true; break;
			case PricingComponentElement::B: m_bidCandles = true; break;
			case PricingComponentElement::A: m_askCandles = true; break;
		}
	}
	void set(std::initializer_list<PricingComponentElement> elements) {
		clear();
		for (auto element : elements) {
			set(element);
		}
	}
	void set(const std::string value) {
		clear();
		for (char const& c: value) {
			PricingComponentElement pricingComponentElement;
			from_string(std::string(1, c), pricingComponentElement);
			set(pricingComponentElement);
		}
	}
	const std::string pricingComponent() const {
		std::ostringstream ss;
		ss << (m_midpointCandles || !(m_midpointCandles || m_bidCandles || m_askCandles) ? "M" : "");
		ss << (m_bidCandles ? "B" : "");
		ss << (m_askCandles ? "A" : "");
		return ss.str();
	}
private:
	bool m_midpointCandles;
	bool m_bidCandles;
	bool m_askCandles;
};

} /* namespace primitives */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRIMATIVES_PRIMITIVESDEFINITIONS_HPP */
