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
 * @file   InstrumentDefinitions.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_INSTRUMENT_INSTRUMENTDEFINITIONS_HPP
#define OANDA_V20_INSTRUMENT_INSTRUMENTDEFINITIONS_HPP

#include <string>
#include <vector>

namespace oanda {
namespace v20 {
namespace instrument {

/**
 * @brief The granularity of a candlestick
 */
enum class CandlestickGranularity {
	UNDEFINED = 0, ///< Default value allows json to be blank
	S5,		///< 5 second candlesticks, minute alignment
	S10,	///< 10 second candlesticks, minute alignment
	S15,	///< 15 second candlesticks, minute alignment
	S30,	///< 30 second candlesticks, minute alignment
	M1,		///< 1 minute candlesticks, minute alignment
	M2,		///< 2 minute candlesticks, hour alignment
	M4,		///< 4 minute candlesticks, hour alignment
	M5,		///< 5 minute candlesticks, hour alignment
	M10,	///< 10 minute candlesticks, hour alignment
	M15,	///< 15 minute candlesticks, hour alignment
	M30,	///< 30 minute candlesticks, hour alignment
	H1,		///< 1 hour candlesticks, hour alignment
	H2,		///< 2 hour candlesticks, day alignment
	H3,		///< 3 hour candlesticks, day alignment
	H4,		///< 4 hour candlesticks, day alignment
	H6,		///< 6 hour candlesticks, day alignment
	H8,		///< 8 hour candlesticks, day alignment
	H12,	///< 12 hour candlesticks, day alignment
	D,		///< 1 day candlesticks, day alignment
	W,		///< 1 week candlesticks, aligned to start of week
	M		///< 1 month candlesticks, aligned to first day of the month
};

/// Convert CandlestickGranularity to string
void to_string(const CandlestickGranularity& from, std::string& to);

/// Convert string to CandlestickGranularity
void from_string(const std::string& from, CandlestickGranularity& to);

/**
 * @brief The day of the week to use for candlestick granularities with weekly alignment.
 */
enum class WeeklyAlignment {
	UNDEFINED = 0,	///< Default value allows json to be blank
	Sunday,		///< Sunday
	Monday,		///< Monday
	Tuesday,	///< Tuesday
	Wednesday,	///< Wednesday
	Thursday,	///< Thursday
	Friday,		///< Friday
	Saturday	///< Saturday
};

/// Convert WeeklyAlignment to string
void to_string(const WeeklyAlignment& from, std::string& to);

/// Convert string to WeeklyAlignment
void from_string(const std::string& from, WeeklyAlignment& to);

} /* namespace instrument */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_INSTRUMENT_INSTRUMENTDEFINITIONS_HPP */
