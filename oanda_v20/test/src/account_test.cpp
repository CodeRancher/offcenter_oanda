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
 * @file   account_test.cpp
 * @author Scott Brauer
 * @date   12-11-2020
 */

#include <iostream>
#include <sstream>
#include <thread>

#include <gtest/gtest.h>
#include "OandaEndpointsFixture.hpp"

#include "oanda/v20/endpoint/Account.hpp"
using namespace oanda::v20;

#include "WaitForMessage.hpp"
#include "GlobalVariables.hpp"

TEST_F (OandaEndpointsFixture, DISABLED_Accounts)
{
	endpoint::account::accounts::Request request;
	endpoint::account::accounts::Parameters parameters;

	oandaEndpoints().account.accounts(request, parameters)->sync([&](endpoint::account::accounts::Response accounts) -> void {
		ASSERT_GT(accounts.accounts.size(), 0);
	});

	oandaEndpoints().account.accounts(request, parameters)->async([&](pplx::task<endpoint::account::accounts::Response> accounts) -> void {
		ASSERT_GT(accounts.get().accounts.size(), 0);
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_Account)
{
	endpoint::account::account::Request request;
	endpoint::account::account::Parameters parameters;
	parameters.accountID = g_oandaAccountID;

	oandaEndpoints().account.account(request, parameters)->sync([&](endpoint::account::account::Response account) -> void {
		EXPECT_EQ(account.account.id, g_oandaAccountID);
	});

	oandaEndpoints().account.account(request, parameters)->async([&](pplx::task<endpoint::account::account::Response> account) -> void {
		EXPECT_EQ(account.get().account.id, g_oandaAccountID);
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_AccountSummary)
{
	endpoint::account::accountsummary::Request request;
	endpoint::account::accountsummary::Parameters parameters;
	parameters.accountID = g_oandaAccountID;

	oandaEndpoints().account.accountSummary(request, parameters)->sync([&](endpoint::account::accountsummary::Response accountSummary) -> void {
		EXPECT_EQ(accountSummary.account.id, g_oandaAccountID);
	});

	oandaEndpoints().account.accountSummary(request, parameters)->async([&](pplx::task<endpoint::account::accountsummary::Response> accountSummary) -> void {
		EXPECT_EQ(accountSummary.get().account.id, g_oandaAccountID);
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_AccountInstruments)
{
	endpoint::account::accountinstruments::Request request;
	endpoint::account::accountinstruments::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	parameters.instruments = { "EUR_USD", "USD_JPY" };

	oandaEndpoints().account.accountInstruments(request, parameters)
			->sync([&](endpoint::account::accountinstruments::Response accountInstruments) -> void
	{
		EXPECT_GT(accountInstruments.instruments.size(), 1);
	});

	oandaEndpoints().account.accountInstruments(request, parameters)
			->async([&](pplx::task<endpoint::account::accountinstruments::Response> accountInstruments) -> void
	{
		EXPECT_EQ(accountInstruments.get().instruments.size(), 2);
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_AccountConfiguration)
{
	// First, get the original values
	std::string origMarginRate;
	std::string origAlias;
	endpoint::account::accountsummary::Request accountSummaryRequest;
	endpoint::account::accountsummary::Parameters accountSummaryParameters;
	accountSummaryParameters.accountID = g_oandaAccountID;
	oandaEndpoints().account.accountSummary(accountSummaryRequest, accountSummaryParameters)
			->sync([&origMarginRate, &origAlias](endpoint::account::accountsummary::Response accountSummary) -> void
	{
		origMarginRate = accountSummary.account.marginRate;
		origAlias = accountSummary.account.alias;
	});

	std::string newMarginRate;
	std::string newAlias;

	// Pick a new margin rate that is different than the current
	try {
		double origMarginRateVal = std::stod(origMarginRate);
		if (origMarginRateVal > (1/25)) {
			newMarginRate = "0.02";
		} else {
			newMarginRate = "1.0";
		}
	} catch(std::invalid_argument&) {
		newMarginRate = "1.0";
	}

	// Pick a new alias that is different than the current
	if (origAlias == "TestAlias") {
		newAlias = "ModAlias";
	} else {
		newAlias = "TestAlias";
	}

	// Test accountConfigurationSync with new values
	endpoint::account::accountconfiguration::Request accountConfigurationRequest;
	endpoint::account::accountconfiguration::Parameters accountConfigurationParameters;
	accountConfigurationRequest.marginRate = newMarginRate;
	accountConfigurationRequest.alias = newAlias;
	accountConfigurationParameters.accountID = g_oandaAccountID;
	oandaEndpoints().account.accountConfiguration(accountConfigurationRequest, accountConfigurationParameters)
			->sync([&](const endpoint::account::accountconfiguration::Response accountConfiguration) -> void
	{
		EXPECT_EQ(accountConfiguration.clientConfigureTransaction.marginRate, newMarginRate);
		EXPECT_EQ(accountConfiguration.clientConfigureTransaction.alias, newAlias);
	});

	// Rest accountConfigurationSync to original values
	accountConfigurationRequest.marginRate = origMarginRate;
	accountConfigurationRequest.alias = origAlias;
	oandaEndpoints().account.accountConfiguration(accountConfigurationRequest, accountConfigurationParameters)
			->sync([&](const endpoint::account::accountconfiguration::Response accountConfiguration) -> void
	{
		EXPECT_EQ(accountConfiguration.clientConfigureTransaction.marginRate, origMarginRate);
		EXPECT_EQ(accountConfiguration.clientConfigureTransaction.alias, origAlias);
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_AccountChanges)
{
	endpoint::account::accountchanges::Request request;
	endpoint::account::accountchanges::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	oandaEndpoints().account.accountChanges(request, parameters)
			->sync([&](endpoint::account::accountchanges::Response accountChanges) -> void
	{
		std::cout << "changes: " << accountChanges.state.balance << std::endl;
		//EXPECT_EQ(account.account.id, g_oandaAccountID);
	});
}
