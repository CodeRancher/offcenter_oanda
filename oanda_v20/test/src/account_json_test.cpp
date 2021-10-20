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
 * @file   account_json_test.hpp
 * @author Scott Brauer
 * @date 12-08-2020
 */

#include <algorithm>

#include <gtest/gtest.h>

#include "oanda/v20/endpoint/Account.hpp"

TEST (AccountRest, Accounts)
{
    // or even nicer with a raw string literal
    auto accountsText = R"(
        {
        "accounts": [
            {
            "id": "<ACCOUNT>", 
            "tags": []
            }
        ]
        }
    )"_json;

    auto accounts = accountsText.get<oanda::v20::endpoint::account::accounts::Response>();
    
	EXPECT_EQ(1, accounts.accounts.size());
}

#ifdef NOTUSED
TEST (AccountRest, PositionSideEmpty)
{
    auto positionSideText = R"(
        {
		}
    )"_json;

    auto positionSide = positionSideText.get<oanda::v20::position::PositionSide>();

	EXPECT_EQ(positionSide.units, "");
	EXPECT_EQ(positionSide.averagePrice, "");
	EXPECT_EQ(positionSide.tradeIDs.size(), 0);
	EXPECT_EQ(positionSide.pl, "");
	EXPECT_EQ(positionSide.unrealizedPL, "");
	EXPECT_EQ(positionSide.resettablePL, "");
	EXPECT_EQ(positionSide.financing, "");
	EXPECT_EQ(positionSide.dividendAdjustment, "");
	EXPECT_EQ(positionSide.guaranteedExecutionFees, "");
}

TEST (AccountRest, PositionSide)
{
    // or even nicer with a raw string literal
    auto positionSideText = R"(
        {
			"units": "123",
			"averagePrice": "1.357",
			"tradeIDs": ["tradeID1", "tradeID2", "tradeID3"],
			"pl": "-2.468",
			"unrealizedPL": "7.890",
			"resettablePL": "5.6789",
			"financing": "4.567",
			"dividendAdjustment": "3.456",
			"guaranteedExecutionFees": "2.345"
		}
    )"_json;

    auto positionSide = positionSideText.get<oanda::v20::position::PositionSide>();

	EXPECT_EQ(positionSide.units, "123");
	EXPECT_EQ(positionSide.averagePrice, "1.357");
	EXPECT_EQ(positionSide.tradeIDs.size(), 3);

	EXPECT_TRUE(std::find(positionSide.tradeIDs.begin(), positionSide.tradeIDs.end(), "tradeID1") != positionSide.tradeIDs.end());
	EXPECT_TRUE(std::find(positionSide.tradeIDs.begin(), positionSide.tradeIDs.end(), "tradeID2") != positionSide.tradeIDs.end());
	EXPECT_TRUE(std::find(positionSide.tradeIDs.begin(), positionSide.tradeIDs.end(), "tradeID3") != positionSide.tradeIDs.end());

	EXPECT_EQ(positionSide.pl, "-2.468");
	EXPECT_EQ(positionSide.unrealizedPL, "7.890");
	EXPECT_EQ(positionSide.resettablePL, "5.6789");
	EXPECT_EQ(positionSide.financing, "4.567");
	EXPECT_EQ(positionSide.dividendAdjustment, "3.456");
	EXPECT_EQ(positionSide.guaranteedExecutionFees, "2.345");
}

TEST (AccountRest, Position)
{
    // or even nicer with a raw string literal
    auto positionText = R"(
        {
			"instrument": "EUR_USD",
			"long": {
				"pl": "-54344.82371",
				"resettablePL": "-54344.82371",
				"units": "0",
				"unrealizedPL": "0.00000"
			},
			"pl": "-54300.41484",
			"resettablePL": "-54300.41484",
			"short": {
				"pl": "44.40887",
				"resettablePL": "44.40887",
				"units": "0",
				"unrealizedPL": "0.00000"
			},
			"unrealizedPL": "0.00000"
		}
    )"_json;

    auto position = positionText.get<oanda::v20::position::Position>();

	//EXPECT_EQ(1, accounts.accounts.size());
}

TEST (AccountRest, SingleAccount)
{
    // or even nicer with a raw string literal
    auto accountsText = R"(
        {
			"account": {
				"NAV": "43650.78835",
				"alias": "My New Account #2",
				"balance": "43650.78835",
				"createdByUserID": 123456,
				"createdTime": "2015-08-12T18:21:00.697504698Z",
				"currency": "CHF",
				"hedgingEnabled": false,
				"id": "<ACCOUNT>",
				"lastTransactionID": "6356",
				"marginAvailable": "43650.78835",
				"marginCloseoutMarginUsed": "0.00000",
				"marginCloseoutNAV": "43650.78835",
				"marginCloseoutPercent": "0.00000",
				"marginCloseoutPositionValue": "0.00000",
				"marginCloseoutUnrealizedPL": "0.00000",
				"marginRate": "0.02",
				"marginUsed": "0.00000",
				"openPositionCount": 0,
				"openTradeCount": 0,
				"orders": [],
				"pendingOrderCount": 0,
				"pl": "-56034.41199",
				"positionValue": "0.00000",
				"positions": [
					{
						"instrument": "EUR_USD",
						"long": {
							"pl": "-54344.82371",
							"resettablePL": "-54344.82371",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"pl": "-54300.41484",
						"resettablePL": "-54300.41484",
						"short": {
							"pl": "44.40887",
							"resettablePL": "44.40887",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"unrealizedPL": "0.00000"
					},
					{
						"instrument": "EUR_GBP",
						"long": {
							"pl": "-21.81721",
							"resettablePL": "-21.81721",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"pl": "-21.81721",
						"resettablePL": "-21.81721",
						"short": {
							"pl": "0.00000",
							"resettablePL": "0.00000",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"unrealizedPL": "0.00000"
					},
					{
						"instrument": "EUR_CAD",
						"long": {
							"pl": "0.35963",
							"resettablePL": "0.35963",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"pl": "0.35963",
						"resettablePL": "0.35963",
						"short": {
							"pl": "0.00000",
							"resettablePL": "0.00000",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"unrealizedPL": "0.00000"
					},
					{
						"instrument": "EUR_CHF",
						"long": {
							"pl": "-868.95147",
							"resettablePL": "-868.95147",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"pl": "-868.95147",
						"resettablePL": "-868.95147",
						"short": {
							"pl": "0.00000",
							"resettablePL": "0.00000",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"unrealizedPL": "0.00000"
					},
					{
						"instrument": "EUR_CZK",
						"long": {
							"pl": "-0.11620",
							"resettablePL": "-0.11620",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"pl": "-0.11620",
						"resettablePL": "-0.11620",
						"short": {
							"pl": "0.00000",
							"resettablePL": "0.00000",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"unrealizedPL": "0.00000"
					},
					{
						"instrument": "USD_CAD",
						"long": {
							"pl": "-483.91941",
							"resettablePL": "-483.91941",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"pl": "-486.15018",
						"resettablePL": "-486.15018",
						"short": {
							"pl": "-2.23077",
							"resettablePL": "-2.23077",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"unrealizedPL": "0.00000"
					},
					{
						"instrument": "USD_JPY",
						"long": {
							"pl": "-20.20008",
							"resettablePL": "-20.20008",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"pl": "-20.20008",
						"resettablePL": "-20.20008",
						"short": {
							"pl": "0.00000",
							"resettablePL": "0.00000",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"unrealizedPL": "0.00000"
					},
					{
						"instrument": "USD_DKK",
						"long": {
							"pl": "-84.23588",
							"resettablePL": "-84.23588",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"pl": "-84.23588",
						"resettablePL": "-84.23588",
						"short": {
							"pl": "0.00000",
							"resettablePL": "0.00000",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"unrealizedPL": "0.00000"
					},
					{
						"instrument": "GBP_CHF",
						"long": {
							"pl": "-17.36306",
							"resettablePL": "-17.36306",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"pl": "-17.36306",
						"resettablePL": "-17.36306",
						"short": {
							"pl": "0.00000",
							"resettablePL": "0.00000",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"unrealizedPL": "0.00000"
					},
					{
						"instrument": "GBP_JPY",
						"long": {
							"pl": "-0.32444",
							"resettablePL": "-0.32444",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"pl": "-0.32444",
						"resettablePL": "-0.32444",
						"short": {
							"pl": "0.00000",
							"resettablePL": "0.00000",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"unrealizedPL": "0.00000"
					},
					{
						"instrument": "AUD_USD",
						"long": {
							"pl": "-2.31173",
							"resettablePL": "-2.31173",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"pl": "-2.31173",
						"resettablePL": "-2.31173",
						"short": {
							"pl": "0.00000",
							"resettablePL": "0.00000",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"unrealizedPL": "0.00000"
					},
					{
						"instrument": "AUD_JPY",
						"long": {
							"pl": "-230.54045",
							"resettablePL": "-230.54045",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"pl": "-230.54045",
						"resettablePL": "-230.54045",
						"short": {
							"pl": "0.00000",
							"resettablePL": "0.00000",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"unrealizedPL": "0.00000"
					},
					{
						"instrument": "CHF_JPY",
						"long": {
							"pl": "-2.34608",
							"resettablePL": "-2.34608",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"pl": "-2.34608",
						"resettablePL": "-2.34608",
						"short": {
							"pl": "0.00000",
							"resettablePL": "0.00000",
							"units": "0",
							"unrealizedPL": "0.00000"
						},
						"unrealizedPL": "0.00000"
					}
				],
				"resettablePL": "-56034.41199",
				"trades": [],
				"unrealizedPL": "0.00000",
				"withdrawalLimit": "43650.78835"
			},
			"lastTransactionID": "6356"
		}
    )"_json;

    auto accounts = accountsText.get<oanda::v20::account::Account>();

	//EXPECT_EQ(1, accounts.accounts.size());
}


#endif
