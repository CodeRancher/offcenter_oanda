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
 * @file   pricing_test.cpp
 * @author Scott Brauer
 * @date   02-08-2021
 */

#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>

#include <gtest/gtest.h>

#include "easylogging++.h"

#include "oanda/v20/endpoint/OandaConnectionException.hpp"
#include "OandaEndpointsFixture.hpp"

#include "oanda/v20/endpoint/Pricing.hpp"
using namespace oanda::v20;

#include "WaitForMessage.hpp"
#include "GlobalVariables.hpp"

TEST_F (OandaEndpointsFixture, DISABLED_Pricing_Candles)
{
	endpoint::pricing::candles::Request request;
	endpoint::pricing::candles::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	parameters.instrument = "EUR_USD";
	parameters.count = "10";

	oandaEndpoints().pricing.candles(request, parameters)->sync([&](endpoint::pricing::candles::Response candles) -> void {
		EXPECT_EQ(candles.candles.size(), 10);

		std::cout << "Pricing-Candles: " << std::endl <<
				"Request ID: " << candles.requestID << std::endl <<
				"Instrument: " << candles.instrument << std::endl;
		for (instrument::Candlestick& candlestick : candles.candles) {
			std::cout << "	" << candlestick.time << "	" << candlestick.mid.o << ", " << candlestick.mid.h << ", " << candlestick.mid.l << ", " << candlestick.mid.c << std::endl;
		}
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_Pricing_PricingStream)
{
	endpoint::pricing::pricingstream::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	parameters.instruments = "EUR_USD";

	auto start = std::chrono::high_resolution_clock::now();

	endpoint::OandaClient::StreamingRequestID requestID = oandaEndpoints().pricing.pricingStream(
		parameters,
		[&, start](oanda::v20::pricing::ClientPrice clientPrice) -> void {
			std::cout << "Client Price: " <<
					clientPrice.instrument << "-" <<
					clientPrice.time << std::endl;
		},
		[&, start](pricing::PricingHeartbeat pricingHeartbeat) -> void {
			std::cout << "Pricing Heartbeat: " <<
					pricingHeartbeat.time << "-" << pricingHeartbeat.time << std::endl;
			auto duration = std::chrono::high_resolution_clock::now() - start;
			auto runningTime = std::chrono::duration_cast<std::chrono::seconds>(duration);
			//std::cout << "Duration: " << runningTime.count() << " Start: " << start << " Now: " << std::chrono::high_resolution_clock::now() << std::endl;
			//if (runningTime.count() > 10) {
			//	cts.cancel();
			//}
		}
	);
//	std::this_thread::sleep_for (std::chrono::seconds(12));
	std::this_thread::sleep_for (std::chrono::hours(3));
	oandaEndpoints().pricing.pricingStream.cancel(requestID);
	std::this_thread::sleep_for (std::chrono::seconds(10));
	std::cout << "After 2nd sleep" << std::endl;
}

TEST_F (OandaEndpointsFixture, DISABLED_Pricing_MultiplePricingStream)
{
	auto lambda = [&] (const std::string& currency) -> endpoint::OandaClient::StreamingRequestID {
		oanda::v20::endpoint::pricing::pricingstream::Parameters parameters;
		parameters.accountID = g_oandaAccountID;
		parameters.instruments = currency;

		return oandaEndpoints().pricing.pricingStream(
			parameters,
			[&](pricing::ClientPrice clientPrice) -> void {
				LOG(INFO) << "Client Price: " <<
						clientPrice.instrument << "-" <<
						clientPrice.time << " - " <<
						clientPrice.closeoutBid << ":" << clientPrice.closeoutAsk;
			},
			[&](pricing::PricingHeartbeat pricingHeartbeat) -> void {
				LOG(INFO) << "Pricing Heartbeat: " << pricingHeartbeat.type << " - " << pricingHeartbeat.time;
			}
		);
	};

	endpoint::OandaClient::StreamingRequestID requestID1 = lambda("EUR_USD");
	endpoint::OandaClient::StreamingRequestID requestID2 = lambda("USD_JPY");
	endpoint::OandaClient::StreamingRequestID requestID3 = lambda("AUD_USD");

	std::this_thread::sleep_for (std::chrono::seconds(10));

	LOG(INFO) << "Stop stream EUR_USD";
	oandaEndpoints().pricing.pricingStream.cancel(requestID1);
	std::this_thread::sleep_for (std::chrono::seconds(10));
	LOG(INFO) << "Stop stream USD_JPY";
	oandaEndpoints().pricing.pricingStream.cancel(requestID2);
	std::this_thread::sleep_for (std::chrono::seconds(10));
	LOG(INFO) << "Stop stream AUD_USD";
	oandaEndpoints().pricing.pricingStream.cancel(requestID3);

	std::this_thread::sleep_for (std::chrono::seconds(10));
	std::cout << "After 2nd sleep" << std::endl;
}

TEST_F (OandaEndpointsFixture, DISABLED_Pricing_AutoCancelPricingStream)
{
	auto lambda = [&] (const std::string& currency) -> endpoint::OandaClient::StreamingRequestID {
		oanda::v20::endpoint::pricing::pricingstream::Parameters parameters;
		parameters.accountID = g_oandaAccountID;
		parameters.instruments = currency;

		return oandaEndpoints().pricing.pricingStream(
			parameters,
			[&](pricing::ClientPrice clientPrice) -> void {
				LOG(INFO) << "Client Price: " <<
						clientPrice.instrument << "-" <<
						clientPrice.time << " - " <<
						clientPrice.closeoutBid << ":" << clientPrice.closeoutAsk;
			},
			[&](pricing::PricingHeartbeat pricingHeartbeat) -> void {
				LOG(INFO) << "Pricing Heartbeat: " << pricingHeartbeat.type << " - " << pricingHeartbeat.time;
			}
		);
	};

	endpoint::OandaClient::StreamingRequestID requestID1 = lambda("EUR_USD");
	//endpoint::OandaClient::StreamingRequestID requestID2 = lambda("USD_JPY");
	//endpoint::OandaClient::StreamingRequestID requestID3 = lambda("AUD_USD");

	std::this_thread::sleep_for (std::chrono::seconds(10));
	LOG(INFO) << "Auto stop all streams";
}
