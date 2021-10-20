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
 * @file   instrument_test.cpp
 * @author Scott Brauer
 * @date   01-20-2021
 */

#include <iostream>
#include <sstream>
#include <thread>

#include <gtest/gtest.h>
#include "OandaEndpointsFixture.hpp"

#include "oanda/v20/endpoint/Account.hpp"
#include "oanda/v20/instrument/InstrumentDefinitions.hpp"
using namespace oanda::v20;

#include "WaitForMessage.hpp"
#include "GlobalVariables.hpp"

TEST_F (OandaEndpointsFixture, DISABLED_InstrumentCandles)
{
	std::string instrument = "EUR_USD";
	endpoint::instrument::candles::Request request;
	endpoint::instrument::candles::Parameters parameters;
	parameters.instrument = instrument;

	oandaEndpoints().instrument.candles(request, parameters)->sync([&](endpoint::instrument::candles::Response candles) -> void {
//		std::cout << "Sync - " << candles.instrument << std::endl;
//		for (instrument::Candlestick& candlestick : candles.candles) {
//			std::cout << "\t" << candlestick.mid.o << ", " << candlestick.mid.h << ", " << candlestick.mid.l << ", " << candlestick.mid.c << std::endl;
//		}
		EXPECT_EQ(candles.instrument, instrument);
		ASSERT_GT(candles.candles.size(), 0);
	});

	oandaEndpoints().instrument.candles(request, parameters)->async([&](pplx::task<endpoint::instrument::candles::Response> response) -> void {
		endpoint::instrument::candles::Response candles = response.get();
//		std::cout << "Async - " << candles.instrument << std::endl;
//		for (instrument::Candlestick& candlestick : candles.candles) {
//			std::cout << "\t" << candlestick.mid.o << ", " << candlestick.mid.h << ", " << candlestick.mid.l << ", " << candlestick.mid.c << std::endl;
//		}
		EXPECT_EQ(candles.instrument, instrument);
		ASSERT_GT(candles.candles.size(), 0);
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_InstrumentOrderBook)
{
	std::string instrument = "EUR_USD";
	endpoint::instrument::orderbook::Request request;
	endpoint::instrument::orderbook::Parameters parameters;
	parameters.instrument = instrument;

	oandaEndpoints().instrument.orderBook(request, parameters)->sync([&](endpoint::instrument::orderbook::Response orderBook) -> void {
//		std::cout << "Sync - " << orderBook.orderBook.instrument << std::endl;
//		for (instrument::OrderBookBucket& orderBookBucket : orderBook.orderBook.buckets) {
//			std::cout << "\t" << orderBookBucket.price << ", " << orderBookBucket.longCountPercent << ", " << orderBookBucket.shortCountPercent << std::endl;
//		}
		EXPECT_EQ(orderBook.orderBook.instrument, instrument);
		ASSERT_GT(orderBook.orderBook.buckets.size(), 0);
	});

	oandaEndpoints().instrument.orderBook(request, parameters)->async([&](pplx::task<endpoint::instrument::orderbook::Response> response) -> void {
		endpoint::instrument::orderbook::Response orderBook = response.get();
//		std::cout << "Async - " << orderBook.orderBook.instrument << std::endl;
//		for (instrument::OrderBookBucket& orderBookBucket : orderBook.orderBook.buckets) {
//			std::cout << "\t" << orderBookBucket.price << ", " << orderBookBucket.longCountPercent << ", " << orderBookBucket.shortCountPercent << std::endl;
//		}
		EXPECT_EQ(orderBook.orderBook.instrument, instrument);
		ASSERT_GT(orderBook.orderBook.buckets.size(), 0);
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_InstrumentPositionBook)
{
	std::string instrument = "EUR_USD";
	endpoint::instrument::positionbook::Request request;
	endpoint::instrument::positionbook::Parameters parameters;
	parameters.instrument = instrument;

	oandaEndpoints().instrument.positionBook(request, parameters)->sync([&](endpoint::instrument::positionbook::Response positionBook) -> void {
//		std::cout << "Sync - " << positionBook.positionBook.instrument << std::endl;
//		for (instrument::PositionBookBucket& positionBookBucket : positionBook.positionBook.buckets) {
//			std::cout << "\t" << positionBookBucket.price << ", " << positionBookBucket.longCountPercent << ", " << positionBookBucket.shortCountPercent << std::endl;
//		}
		EXPECT_EQ(positionBook.positionBook.instrument, instrument);
		ASSERT_GT(positionBook.positionBook.buckets.size(), 0);
	});

	oandaEndpoints().instrument.positionBook(request, parameters)->async([&](pplx::task<endpoint::instrument::positionbook::Response> response) -> void {
		endpoint::instrument::positionbook::Response positionBook = response.get();
//		std::cout << "Async - " << positionBook.positionBook.instrument << std::endl;
//		for (instrument::PositionBookBucket& positionBookBucket : positionBook.positionBook.buckets) {
//			std::cout << "\t" << positionBookBucket.price << ", " << positionBookBucket.longCountPercent << ", " << positionBookBucket.shortCountPercent << std::endl;
//		}
		EXPECT_EQ(positionBook.positionBook.instrument, instrument);
		ASSERT_GT(positionBook.positionBook.buckets.size(), 0);
	});
}

TEST (Instrument, CandlestickGranularityToString)
{

}

TEST (Instrument, CandlestickGranularityFromString)
{

}


class CandlestickGranularityTestFixture : public ::testing::TestWithParam<std::pair<instrument::CandlestickGranularity, std::string> > {
};

TEST_P(CandlestickGranularityTestFixture, ToFromString) {
	const std::pair<instrument::CandlestickGranularity, std::string>& pair = GetParam();

	// Test convert granularity to a string
	std::string granularityStr;
	to_string(pair.first, granularityStr);
	EXPECT_EQ(granularityStr, pair.second);

	// Test convert string to granularity
	instrument::CandlestickGranularity granularityEnum;
	from_string(pair.second, granularityEnum);
	EXPECT_EQ(granularityEnum, pair.first);
}

INSTANTIATE_TEST_SUITE_P(
	ToFromStringTests,
	CandlestickGranularityTestFixture,
	::testing::Values(
			std::make_pair(instrument::CandlestickGranularity::UNDEFINED, std::string("UNDEFINED")),
			std::make_pair(instrument::CandlestickGranularity::S5, std::string("S5")),
			std::make_pair(instrument::CandlestickGranularity::S10, std::string("S10")),
			std::make_pair(instrument::CandlestickGranularity::S15, std::string("S15")),
			std::make_pair(instrument::CandlestickGranularity::S30, std::string("S30")),
			std::make_pair(instrument::CandlestickGranularity::M1, std::string("M1")),
			std::make_pair(instrument::CandlestickGranularity::M2, std::string("M2")),
			std::make_pair(instrument::CandlestickGranularity::M4, std::string("M4")),
			std::make_pair(instrument::CandlestickGranularity::M5, std::string("M5")),
			std::make_pair(instrument::CandlestickGranularity::M10, std::string("M10")),
			std::make_pair(instrument::CandlestickGranularity::M15, std::string("M15")),
			std::make_pair(instrument::CandlestickGranularity::M30, std::string("M30")),
			std::make_pair(instrument::CandlestickGranularity::H1, std::string("H1")),
			std::make_pair(instrument::CandlestickGranularity::H2, std::string("H2")),
			std::make_pair(instrument::CandlestickGranularity::H3, std::string("H3")),
			std::make_pair(instrument::CandlestickGranularity::H4, std::string("H4")),
			std::make_pair(instrument::CandlestickGranularity::H6, std::string("H6")),
			std::make_pair(instrument::CandlestickGranularity::H8, std::string("H8")),
			std::make_pair(instrument::CandlestickGranularity::H12, std::string("H12")),
			std::make_pair(instrument::CandlestickGranularity::D, std::string("D")),
			std::make_pair(instrument::CandlestickGranularity::W, std::string("W")),
			std::make_pair(instrument::CandlestickGranularity::M, std::string("M"))
	)
);
