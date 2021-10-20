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
 * @file   list_account.cpp
 * @author Scott Brauer
 * @date   02-17-2021
 */

#include <iostream>
#include <iomanip>

#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP

#include "oanda/v20/endpoint/OandaEndpoints.hpp"
using namespace oanda::v20;

/**
 * Query Oanda for all accounts related to an access token
 */
int main(int argc, char* argv[])
{
	START_EASYLOGGINGPP(argc, argv);

	// Move logging to a file so stdout is not flooded
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToFile, "true");
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToStandardOutput, "false");
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format, "%datetime:%thread [%level] %msg");
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Filename, "list_accounts.log");

	// Verify correct number of command line arguments
	if(argc != 2) {
		std::cerr << "Incorrect Number Of Arguments: " << argc << std::endl;
		std::cerr << argc << std::endl;
		std::cerr << "Expected command line:" << std::endl << std::endl;
		std::cerr << "	list_accounts <access_token>" << std::endl << std::endl;
		std::cerr << "access_token: Oanda supplied access token" << std::endl;
		return 1;
	}

	// Connect to the Oanda server
	endpoint::OandaPracticeServer server;
	endpoint::OandaAuthorization authorization(argv[1]);
	endpoint::OandaEndpoints oandaEndpoints(server, authorization);

	// Initialize Request and Parameter values
	endpoint::account::accounts::Request request;
	endpoint::account::accounts::Parameters parameters;

	// Synchronously retrieve the accounts
	oandaEndpoints.account.accounts(request, parameters)->sync([](endpoint::account::accounts::Response accounts) -> void {
		static const int idWidth = 20;
		static const auto idJust = std::right;
		static const int mt4Width = 20;
		static const auto mt4Just = std::right;
		static const auto tagJust = std::left;

		// Output headers
		std::cout <<
				std::setw(idWidth) << idJust << "id" << "," <<
				std::setw(mt4Width) << mt4Just << "mt4AccountID" << ", " <<
				tagJust << "tags" << std::endl;

		// Output account values
		for (account::AccountProperties& account : accounts.accounts) {
			std::cout <<
					std::setw(idWidth) << idJust << account.id << "," <<
					std::setw(mt4Width) << mt4Just << account.mt4AccountID << ", " <<
					tagJust << common::join(account.tags, ", ") << std::endl;
		}
	});

	return 0;
}
