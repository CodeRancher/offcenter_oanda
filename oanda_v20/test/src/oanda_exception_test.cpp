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
 * File: oanda_exception_test.cpp
 * Author: Scott Brauer
 *
 * Mon 21 Dec 2020 04:32:08 PM MST
 */

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <cpprest/http_msg.h>

#include "oanda/v20/endpoint/OandaConnectionException.hpp"
#include "oanda/v20/endpoint/OandaExceptionFactory.hpp"
#include "oanda/v20/endpoint/OandaEndpoints.hpp"

#include "WaitForMessage.hpp"

TEST (OandaExceptions, BadRequest)
{
	EXPECT_THROW(
			oanda::v20::endpoint::oandaExceptionFactory(web::http::status_codes::BadRequest, "{\"unused\" : \"I am unused\"}"),
			oanda::v20::endpoint::BadRequest);

	EXPECT_THROW(
			oanda::v20::endpoint::oandaExceptionFactory(web::http::status_codes::BadRequest, "{\"errorMessage\" : \"The request was missing required data\"}"),
			oanda::v20::endpoint::MalformedRequest);

	EXPECT_THROW(
			oanda::v20::endpoint::oandaExceptionFactory(web::http::status_codes::BadRequest, "{\"errorMessage\" : \"Invalid value specified for 'instrument'\"}"),
			oanda::v20::endpoint::InvalidInstrument);

	EXPECT_THROW(
			oanda::v20::endpoint::oandaExceptionFactory(web::http::status_codes::BadRequest, "{\"rejectReason\" : \" STOP_LOSS_ON_FILL_PRICE_PRECISION_EXCEEDED\"}"),
			oanda::v20::endpoint::PrecisionExceeded);
}

TEST (OandaExceptions, Unauthorized)
{
	EXPECT_THROW(
			oanda::v20::endpoint::oandaExceptionFactory(web::http::status_codes::Unauthorized, "{\"unused\" : \"I am unused\"}"),
			oanda::v20::endpoint::Unauthorized);

	EXPECT_THROW(
			oanda::v20::endpoint::oandaExceptionFactory(web::http::status_codes::Unauthorized, "{\"errorMessage\" : \"The provided request was forbidden.\"}"),
			oanda::v20::endpoint::InvalidAccountID);

	EXPECT_THROW(
			oanda::v20::endpoint::oandaExceptionFactory(web::http::status_codes::Unauthorized, "{\"errorMessage\" : \"Insufficient authorization to perform request.\"}"),
			oanda::v20::endpoint::InsufficientAuthorization);
}

TEST (OandaExceptions, Forbidden)
{
	EXPECT_THROW(
			oanda::v20::endpoint::oandaExceptionFactory(web::http::status_codes::Forbidden, "{\"unused\" : \"I am unused\"}"),
			oanda::v20::endpoint::Forbidden);

	EXPECT_THROW(
			oanda::v20::endpoint::oandaExceptionFactory(web::http::status_codes::Forbidden, "{\"errorMessage\" : \"Insufficient authorization to perform request.\"}"),
			oanda::v20::endpoint::AccountNotTradable);
}

TEST (OandaExceptions, NotFound)
{
	EXPECT_THROW(
			oanda::v20::endpoint::oandaExceptionFactory(web::http::status_codes::NotFound, "{\"unused\" : \"I am unused\"}"),
			oanda::v20::endpoint::NotFound);

	EXPECT_THROW(
			oanda::v20::endpoint::oandaExceptionFactory(web::http::status_codes::NotFound, "{\"errorMessage\" : \"The trade ID specified does not exist\"}"),
			oanda::v20::endpoint::NoSuchTrade);

	EXPECT_THROW(
			oanda::v20::endpoint::oandaExceptionFactory(web::http::status_codes::NotFound, "{\"errorMessage\" : \"The transaction ID specified does not exist\"}"),
			oanda::v20::endpoint::NoSuchTransaction);

	EXPECT_THROW(
			oanda::v20::endpoint::oandaExceptionFactory(web::http::status_codes::NotFound, "{\"errorMessage\" : \"The order ID specified does not exist\"}"),
			oanda::v20::endpoint::NoSuchOrder);
}

TEST (OandaExceptions, MethodNotAllowed)
{
	EXPECT_THROW(
			oanda::v20::endpoint::oandaExceptionFactory(web::http::status_codes::MethodNotAllowed, "{\"unused\" : \"I am unused\"}"),
			oanda::v20::endpoint::MethodNotAllowed);
}

TEST (OandaExceptions, BearerTokenNotSupplied)
{
	oanda::v20::endpoint::OandaPracticeServer server;
	oanda::v20::endpoint::OandaAuthorization authorization("ABCD");
	oanda::v20::endpoint::OandaEndpoints::Ptr endpoints = oanda::v20::endpoint::OandaEndpoints::factory(server, authorization);

	/*
	ASSERT_THROW(
		endpoints->accountsSync([](oanda::v20::endpoint::account::AccountsResponse accounts) -> void {
			FAIL(); // This should never execute. An exception must be returned.
		}
	), oanda::v20::endpoint::InsufficientAuthorization);

	endpoints->accountsAsync([](pplx::task<oanda::v20::endpoint::account::AccountsResponse> accounts) -> void {
		ASSERT_THROW(accounts.get(), oanda::v20::endpoint::InsufficientAuthorization);
	});
	*/
}
