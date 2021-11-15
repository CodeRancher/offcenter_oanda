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
 * @file   OandaException.cpp
 * @author Scott Brauer
 * @date   12-21-2020
 */

#include <nlohmann/json.hpp>

#include "oanda/v20/endpoint/OandaExceptionFactory.hpp"
#include "oanda/v20/endpoint/OandaConnectionException.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {

/**
 * Common code to test and execute an exception
 *
 * @param statusCode The http status code
 * @param responseText The json response text from the http call
 */
template<class T>
void testOandaException(const web::http::status_code statusCode, const nlohmann::json& json)
{
	if (T::errorTest(statusCode, json.value(T::jsonKey(), ""))) {
		throw T(json.at(T::jsonKey()));
	}

}

/**
 * Execute a specific Oanda exception based on a status code and what the response text contains
 *
 * @param statusCode The http status code
 * @param responseText The json response text from the http call
 *
 * @exception oanda::v20::endpoint::MalformedRequest
 * @exception oanda::v20::endpoint::InvalidInstrument
 * @exception oanda::v20::endpoint::PrecisionExceeded
 * @exception oanda::v20::endpoint::BadRequest
 * @exception oanda::v20::endpoint::InvalidAccountID
 * @exception oanda::v20::endpoint::InsufficientAuthorization
 * @exception oanda::v20::endpoint::Unauthorized
 * @exception oanda::v20::endpoint::AccountNotTradable
 * @exception oanda::v20::endpoint::Forbidden
 * @exception oanda::v20::endpoint::NoSuchTrade
 * @exception oanda::v20::endpoint::NoSuchTransaction
 * @exception oanda::v20::endpoint::NotFound
 * @exception oanda::v20::endpoint::MethodNotAllowed
 */
void oandaExceptionFactory(const web::http::status_code statusCode, const utility::string_t& responseText)
{
	// Short circuit when no error
	if (statusCode == web::http::status_codes::OK) {
		return;
	}

	auto json = nlohmann::json::parse(responseText);

	switch(statusCode) {
		// 400 - BadRequest
		case web::http::status_codes::BadRequest:
			testOandaException<oanda::v20::endpoint::MalformedRequest>(statusCode, json);
			testOandaException<oanda::v20::endpoint::InvalidInstrument>(statusCode, json);
			testOandaException<oanda::v20::endpoint::PrecisionExceeded>(statusCode, json);
			throw oanda::v20::endpoint::BadRequest(json.dump(4));

		// 401 - Unauthorized
		case web::http::status_codes::Unauthorized:
			testOandaException<oanda::v20::endpoint::InvalidAccountID>(statusCode, json);
			testOandaException<oanda::v20::endpoint::InsufficientAuthorization>(statusCode, json);
			throw oanda::v20::endpoint::Unauthorized(json.dump(4));

		// 403 - Forbidden
		case web::http::status_codes::Forbidden:
			testOandaException<oanda::v20::endpoint::AccountNotTradable>(statusCode, json);
			throw oanda::v20::endpoint::Forbidden(json.dump(4));
			break;

		// 404 - Not Found
		case web::http::status_codes::NotFound:
			testOandaException<oanda::v20::endpoint::NoSuchTrade>(statusCode, json);
			testOandaException<oanda::v20::endpoint::NoSuchTransaction>(statusCode, json);
			testOandaException<oanda::v20::endpoint::NoSuchOrder>(statusCode, json);
			throw oanda::v20::endpoint::NotFound(json.dump(4));
			break;

		// 405 - Method Not Allowed
		case web::http::status_codes::MethodNotAllowed:
			throw oanda::v20::endpoint::MethodNotAllowed(json.dump(4));
			break;

		default:
			throw oanda::v20::endpoint::UnknownBadRequest(statusCode, json.dump(4));
	}
}

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */
