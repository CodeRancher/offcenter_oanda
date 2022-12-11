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
 * @file   eur_usd_to_csv.cpp
 * @author Scott Brauer
 * @date   02-17-2021
 */

#include <iostream>

#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

#include "oanda/v20/endpoint/OandaEndpoints.hpp"
using namespace oanda::v20;

/**
 * Query Oanda for a 1000 daily mid candles for EUR/USD that are smoothed.
 */
int main(int argc, char* argv[])
{
	START_EASYLOGGINGPP(argc, argv);

	// Move logging to a file so stdout is not flooded
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToFile, "true");
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToStandardOutput, "false");
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format, "%datetime:%thread [%level] %msg");
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Filename, "eur_usd_to_csv.log");

	// Verify correct number of command line arguments
	if(argc != 3) {
		std::cerr << "Incorrect Number Of Arguments: " << argc << std::endl;
		std::cerr << "Expected command line:" << std::endl << std::endl;
		std::cerr << "	eur_usd_to_csv <access_token> <account>" << std::endl << std::endl;
		std::cerr << "access_token: Oanda supplied access token" << std::endl;
		std::cerr << "account:      User Account" << std::endl;
		return 1;
	}

	// Connect to the Oanda server
	endpoint::OandaPracticeServer server;
	endpoint::OandaAuthorization authorization(argv[1]);
	std::string accountID = argv[2];
	endpoint::OandaEndpoints oandaEndpoints(server, authorization);

	// Initialize Request and Parameter values
	endpoint::pricing::candles::Request request;
	endpoint::pricing::candles::Parameters parameters;
	parameters.accountID = accountID;
	parameters.instrument = "EUR_USD";
	parameters.granularity = "D";
	parameters.price = "M";
	parameters.smooth = "True";
	parameters.count = "1000";

	// Synchronously retrieve the candle values
	oandaEndpoints.pricing.candles(request, parameters)->sync([](endpoint::pricing::candles::Response candles) -> void {
		std::string granularity;
		to_string(candles.granularity, granularity);

		// Output headers
		std::cout <<
				candles.instrument << " - " << granularity << "," <<
				"Open," <<
				"Low," <<
				"High," <<
				"Close" << std::endl;

		// Output candlestick values
		for (oanda::v20::instrument::Candlestick& candlestick : candles.candles) {
			std::cout <<
					candlestick.time << "," <<
					candlestick.mid.o << "," <<
					candlestick.mid.l << "," <<
					candlestick.mid.h << "," <<
					candlestick.mid.c << std::endl;
		}
	});

	return 0;
}
