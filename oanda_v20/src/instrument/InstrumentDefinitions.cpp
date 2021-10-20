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
 * @file   InstrumentDefinitions.cpp
 * @author Scott Brauer
 * @date   02-17-2021
 */

#include <string>

#include "oanda/v20/instrument/InstrumentDefinitions.hpp"
#include "oanda/v20/common/OandaCommonException.hpp"
#include "oanda/v20/common/Utility.hpp"
using namespace oanda::v20;

namespace oanda {
namespace v20 {
namespace instrument {

void to_string(const CandlestickGranularity& from, std::string& to)
{
	switch(from) {
		case CandlestickGranularity::UNDEFINED: to = "UNDEFINED"; break;
		case CandlestickGranularity::S5:	to = "S5"; break;
		case CandlestickGranularity::S10:	to = "S10"; break;
		case CandlestickGranularity::S15:	to = "S15"; break;
		case CandlestickGranularity::S30:	to = "S30"; break;
		case CandlestickGranularity::M1:	to = "M1"; break;
		case CandlestickGranularity::M2:	to = "M2"; break;
		case CandlestickGranularity::M4:	to = "M4"; break;
		case CandlestickGranularity::M5:	to = "M5"; break;
		case CandlestickGranularity::M10:	to = "M10"; break;
		case CandlestickGranularity::M15:	to = "M15"; break;
		case CandlestickGranularity::M30:	to = "M30"; break;
		case CandlestickGranularity::H1:	to = "H1"; break;
		case CandlestickGranularity::H2:	to = "H2"; break;
		case CandlestickGranularity::H3:	to = "H3"; break;
		case CandlestickGranularity::H4:	to = "H4"; break;
		case CandlestickGranularity::H6:	to = "H6"; break;
		case CandlestickGranularity::H8:	to = "H8"; break;
		case CandlestickGranularity::H12:	to = "H12"; break;
		case CandlestickGranularity::D:		to = "D"; break;
		case CandlestickGranularity::W:		to = "W"; break;
		case CandlestickGranularity::M:		to = "M"; break;
		default:
			throw common::OandaInvalidType("Unknown CandlestickGranularity");
	}

}

void from_string(const std::string& from, CandlestickGranularity& to)
{
	const char increment = from.size() > 0 ? std::toupper(from[0]) : '\0';
	const int value = (from.size() > 1 && increment != 'U') ? std::stoi(from.substr(1)) : -1;
	bool error = false;

	switch(increment) {
		case 'S':
			switch(value) {
				case 5:		to = CandlestickGranularity::S5; break;
				case 10:	to = CandlestickGranularity::S10; break;
				case 15:	to = CandlestickGranularity::S15; break;
				case 30:	to = CandlestickGranularity::S30; break;
				default:	error = true;
			}
			break;

		case 'M':
			switch(value) {
				case -1:	to = CandlestickGranularity::M; break;
				case 1:		to = CandlestickGranularity::M1; break;
				case 2:		to = CandlestickGranularity::M2; break;
				case 4:		to = CandlestickGranularity::M4; break;
				case 5:		to = CandlestickGranularity::M5; break;
				case 10:	to = CandlestickGranularity::M10; break;
				case 15:	to = CandlestickGranularity::M15; break;
				case 30:	to = CandlestickGranularity::M30; break;
				default:	error = true;
			}
			break;

		case 'H':
			switch(value) {
				case 1:		to = CandlestickGranularity::H1; break;
				case 2:		to = CandlestickGranularity::H2; break;
				case 3:		to = CandlestickGranularity::H3; break;
				case 4:		to = CandlestickGranularity::H4; break;
				case 6:		to = CandlestickGranularity::H6; break;
				case 8:		to = CandlestickGranularity::H8; break;
				case 12:	to = CandlestickGranularity::H12; break;
				default:	error = true;
			}
			break;

		case 'D':
			switch(value) {
				case -1: to = CandlestickGranularity::D; break;
				default: error = true;
			}
			break;

		case 'W':
			switch(value) {
				case -1: to = CandlestickGranularity::W; break;
				default: error = true;
			}
			break;

		case 'U':
			if (common::stringCompareI(from, "UNDEFINED")) {
				to = CandlestickGranularity::UNDEFINED;
			} else {
				error = true;
			}
			break;

		default:
			error = true;
	}

	if (error) {
		throw common::OandaInvalidType("Unknown CandlestickGranularity (" + from + ")");
	}

}

// Convert WeeklyAlignment to string
void to_string(const WeeklyAlignment& from, std::string& to)
{
	switch(from) {
		case WeeklyAlignment::UNDEFINED:	to = "UNDEFINED"; break;
		case WeeklyAlignment::Sunday:		to = "Sunday"; break;
		case WeeklyAlignment::Monday:		to = "Monday"; break;
		case WeeklyAlignment::Tuesday:		to = "Tuesday"; break;
		case WeeklyAlignment::Wednesday:	to = "Wednesday"; break;
		case WeeklyAlignment::Thursday:		to = "Thursday"; break;
		case WeeklyAlignment::Friday:		to = "Friday"; break;
		case WeeklyAlignment::Saturday:		to = "Saturday"; break;
		default:
			throw common::OandaInvalidType("Unknown WeeklyAlignment");
	}
}

// Convert string to WeeklyAlignment
void from_string(const std::string& from, WeeklyAlignment& to)
{
	static std::map<std::string, WeeklyAlignment> lookup = {
			{"UNDEFINED", WeeklyAlignment::UNDEFINED},
			{"SUNDAY", WeeklyAlignment::Sunday},
			{"MONDAY", WeeklyAlignment::Monday},
			{"TUESDAY", WeeklyAlignment::Tuesday},
			{"WEDNESDAY", WeeklyAlignment::Wednesday},
			{"THURSDAY", WeeklyAlignment::Thursday},
			{"FRIDAY", WeeklyAlignment::Friday},
			{"SATURDAY", WeeklyAlignment::Saturday}
	};

	try {
		to = lookup.at(common::toUpper(from));
	} catch(std::out_of_range& e) {
		throw common::OandaInvalidValue("Unknown WeeklyAlignment (" + from + ")");
	}
}

} /* namespace instrument */
} /* namespace v20 */
} /* namespace oanda */
