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
 * @file   list_candles.cpp
 * @author Scott Brauer
 * @date   03-05-2021
 */

#include <iostream>
#include <iomanip>
#include <thread>
#include <mutex>
#include <atomic>

#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP

#include "oanda/v20/endpoint/OandaEndpoints.hpp"
using namespace oanda::v20;

/**
 * Query Oanda for the default (500) candles of EUR/USD
 */
int main(int argc, char* argv[])
{
	START_EASYLOGGINGPP(argc, argv);

	// Move logging to a file so stdout is not flooded
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToFile, "true");
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToStandardOutput, "false");
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format, "%datetime:%thread [%level] %msg");
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Filename, "list_candles.log");

	// Verify correct number of command line arguments
	if(argc != 3) {
		std::cerr << "Incorrect Number Of Arguments: " << argc << std::endl;
		std::cerr << "Expected command line:" << std::endl << std::endl;
		std::cerr << "	list_candles <access_token> <instrument>" << std::endl << std::endl;
		std::cerr << "access_token: Oanda supplied access token" << std::endl;
		std::cerr << "instrument:   Instrument data to retrieve" << std::endl;
		return 1;
	}

	// Connect to the Oanda server
	endpoint::OandaPracticeServer server;
	endpoint::OandaAuthorization authorization(argv[1]);
	std::string instrument = argv[2];
	endpoint::OandaEndpoints oandaEndpoints(server, authorization);

	// Initialize Request and Parameter values
	endpoint::instrument::candles::Request request;
	endpoint::instrument::candles::Parameters parameters;
	parameters.acceptDateTimeFormat = primitives::AcceptDatetimeFormat::RFC3339;
	parameters.instrument = instrument;

	std::mutex mutex;
	std::condition_variable conditionVariable;
	std::atomic_bool exitReady{false};

	// Synchronously retrieve the accounts
	oandaEndpoints.instrument.candles(request, parameters)->async([&conditionVariable, &exitReady](pplx::task<endpoint::instrument::candles::Response> candlesResponse) {
		static const int timeWidth = 30;
		static const auto timeJust = std::left;
		static const int priceWidth = 10;
		static const auto priceJust = std::right;

		endpoint::instrument::candles::Response candles = candlesResponse.get();

		std::string granularity;
		to_string(candles.granularity, granularity);

		// Output headers
		std::cout <<
				std::setw(timeWidth) << timeJust << candles.instrument + " - " + granularity << " " <<
				std::setw(priceWidth) << priceJust << "Open" << " " <<
				std::setw(priceWidth) << priceJust << "Low" << " " <<
				std::setw(priceWidth) << priceJust << "High" << " " <<
				std::setw(priceWidth) << priceJust << "Close" << std::endl;

		// Output candlestick values
		for (instrument::Candlestick& candlestick : candles.candles) {
			std::cout <<
					std::setw(timeWidth) << timeJust << candlestick.time << ":" <<
					std::setw(priceWidth) << priceJust << candlestick.mid.o << "," <<
					std::setw(priceWidth) << priceJust << candlestick.mid.l << "," <<
					std::setw(priceWidth) << priceJust << candlestick.mid.h << "," <<
					std::setw(priceWidth) << priceJust << candlestick.mid.c << std::endl;
		}

		// Signal thread finished
		exitReady = true;
		conditionVariable.notify_one();
	});

	// Wait for thread to complete
	std::unique_lock<std::mutex> lock(mutex);
	conditionVariable.wait(lock, [&exitReady]{ return exitReady.load(); });

	return 0;
}
