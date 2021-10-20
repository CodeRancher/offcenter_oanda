/**
 * Copyright 2021 Scott Brauer
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
 * @file   PrimitivesDefinitions.cpp
 * @author Scott Brauer
 * @date   03-05-2021
 */

#include <string>
#include <map>
#include <stdexcept>

#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"
#include "oanda/v20/common/OandaCommonException.hpp"
#include "oanda/v20/common/Utility.hpp"
using namespace oanda::v20;

namespace oanda {
namespace v20 {
namespace primitives {

void to_string(const InstrumentType &from, std::string &to)
{
	switch(from) {
		case InstrumentType::UNDEFINED: to = "UNDEFINED"; break;
		case InstrumentType::CFD: to = "CFD"; break;
		case InstrumentType::METAL: to = "METAL"; break;
		case InstrumentType::CURRENCY: to = "CURRENCY"; break;
		default:
			throw common::OandaInvalidType("Unknown InstrumentType");
	}

}

void from_string(const std::string &from, InstrumentType &to)
{
	static std::map<std::string, InstrumentType> lookup = {
			{"UNDEFINED", InstrumentType::UNDEFINED},
			{"CFD", InstrumentType::CFD},
			{"METAL", InstrumentType::METAL},
			{"CURRENCY", InstrumentType::CURRENCY}
	};

	try {
		to = lookup.at(common::toUpper(from));
	} catch(std::out_of_range& e) {
		throw common::OandaInvalidType("Unknown InstrumentType");
	}
}

void to_string(const DayOfWeek &from, std::string &to)
{
	switch(from) {
		case DayOfWeek::UNDEFINED: to = "UNDEFINED"; break;
		case DayOfWeek::SUNDAY: to = "SUNDAY"; break;
		case DayOfWeek::SATURDAY: to = "SATURDAY"; break;
		case DayOfWeek::THURSDAY: to = "THURSDAY"; break;
		case DayOfWeek::MONDAY: to = "MONDAY"; break;
		case DayOfWeek::WEDNESDAY: to = "WEDNESDAY"; break;
		case DayOfWeek::TUESDAY: to = "TUESDAY"; break;
		case DayOfWeek::FRIDAY: to = "FRIDAY"; break;
		default:
			throw common::OandaInvalidType("Unknown DayOfWeek");
	}
}

void from_string(const std::string &from, DayOfWeek &to)
{
	static std::map<std::string, DayOfWeek> lookup = {
			{"UNDEFINED", DayOfWeek::UNDEFINED},
			{"SUNDAY", DayOfWeek::SUNDAY},
			{"SATURDAY", DayOfWeek::SATURDAY},
			{"THURSDAY", DayOfWeek::THURSDAY},
			{"MONDAY", DayOfWeek::MONDAY},
			{"WEDNESDAY", DayOfWeek::WEDNESDAY},
			{"TUESDAY", DayOfWeek::TUESDAY},
			{"FRIDAY", DayOfWeek::FRIDAY}
	};

	try {
		to = lookup.at(common::toUpper(from));
	} catch(std::out_of_range& e) {
		throw common::OandaInvalidType("Unknown DayOfWeek");
	}
}

void to_string(const AcceptDatetimeFormat& from, std::string& to)
{
	switch(from) {
		case AcceptDatetimeFormat::UNDEFINED: to = "UNDEFINED"; break;
		case AcceptDatetimeFormat::UNIX: to = "UNIX"; break;
		case AcceptDatetimeFormat::RFC3339: to = "RFC3339"; break;
		default:
			throw common::OandaInvalidType("Unknown AcceptDatetimeFormat");
	}
}

void from_string(const std::string& from, AcceptDatetimeFormat& to)
{
	static std::map<std::string, AcceptDatetimeFormat> lookup = {
			{"UNDEFINED", AcceptDatetimeFormat::UNDEFINED},
			{"UNIX", AcceptDatetimeFormat::UNIX},
			{"RFC3339", AcceptDatetimeFormat::RFC3339}
	};

	try {
		to = lookup.at(common::toUpper(from));
	} catch(std::out_of_range& e) {
		throw common::OandaInvalidType("Unknown AcceptDatetimeFormat");
	}
}

void to_string(const GuaranteedStopLossOrderModeForInstrument &from,
        std::string &to)
{
	switch(from) {
		case GuaranteedStopLossOrderModeForInstrument::UNDEFINED: to = "UNDEFINED"; break;
		case GuaranteedStopLossOrderModeForInstrument::REQUIRED: to = "REQUIRED"; break;
		case GuaranteedStopLossOrderModeForInstrument::DISABLED: to = "DISABLED"; break;
		case GuaranteedStopLossOrderModeForInstrument::ALLOWED: to = "ALLOWED"; break;
		default:
			throw common::OandaInvalidType("Unknown GuaranteedStopLossOrderModeForInstrument");
	}
}

void from_string(const std::string &from,
        GuaranteedStopLossOrderModeForInstrument &to)
{
	static std::map<std::string, GuaranteedStopLossOrderModeForInstrument> lookup = {
			{"UNDEFINED", GuaranteedStopLossOrderModeForInstrument::UNDEFINED},
			{"REQUIRED", GuaranteedStopLossOrderModeForInstrument::REQUIRED},
			{"DISABLED", GuaranteedStopLossOrderModeForInstrument::DISABLED},
			{"ALLOWED", GuaranteedStopLossOrderModeForInstrument::ALLOWED}
	};

	try {
		to = lookup.at(common::toUpper(from));
	} catch(std::out_of_range& e) {
		throw common::OandaInvalidType("Unknown GuaranteedStopLossOrderModeForInstrument (" + from + ")");
	}
}

void to_string(const PricingComponentElement& from, std::string& to)
{
	switch(from) {
		case PricingComponentElement::M: to = "M"; break;
		case PricingComponentElement::B: to = "B"; break;
		case PricingComponentElement::A: to = "A"; break;
		default:
			throw common::OandaInvalidType("Unknown PricingComponentElement");
	}
}

void from_string(const std::string& from, PricingComponentElement& to)
{
	static std::map<std::string, PricingComponentElement> lookup = {
			{"M", PricingComponentElement::M},
			{"B", PricingComponentElement::B},
			{"A", PricingComponentElement::A}
	};

	try {
		to = lookup.at(common::toUpper(from));
	} catch(std::out_of_range& e) {
		throw common::OandaInvalidType("Unknown PricingComponentElement (" + from + ")");
	}
}

} /* namespace primitives */
} /* namespace v20 */
} /* namespace oanda */
