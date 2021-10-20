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
 * @file   OandaConnectionException.cpp
 * @author Scott Brauer
 * @date   12-21-2020
 */

#include <nlohmann/json.hpp>

#include "oanda/v20/endpoint/OandaConnectionException.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {

//*****************************************************************************
// BadRequest
//*****************************************************************************
template<> std::string OandaExceptionBase<BadRequest>::m_reason =
		"The client has provided invalid data to be processed.";
template<> OandaExceptionType OandaExceptionBase<BadRequest>::m_exceptionType = OandaExceptionType::BadRequest;
template<> unsigned short OandaExceptionBase<BadRequest>::m_httpStatusCode = 400;

//*****************************************************************************
// MalformedRequest
//*****************************************************************************
template<> std::string OandaExceptionBase<MalformedRequest>::m_reason =
		"One or more required parameters for the request is missing or is invalid.";
template<> OandaExceptionType OandaExceptionBase<MalformedRequest>::m_exceptionType = OandaExceptionType::MalformedRequest;
template<> unsigned short OandaExceptionBase<MalformedRequest>::m_httpStatusCode = 400;
template<> std::string OandaExceptionJsonTest<MalformedRequest>::m_jsonKey = "errorMessage";

//*****************************************************************************
// InvalidInstrument
//*****************************************************************************
template<> std::string OandaExceptionBase<InvalidInstrument>::m_reason =
		"The Currency provided is invalid. Confirm the structure of currency is correct.";
template<> OandaExceptionType OandaExceptionBase<InvalidInstrument>::m_exceptionType = OandaExceptionType::InvalidInstrument;
template<> unsigned short OandaExceptionBase<InvalidInstrument>::m_httpStatusCode = 400;
template<> std::string OandaExceptionJsonTest<InvalidInstrument>::m_jsonKey = "errorMessage";

//*****************************************************************************
// PrecisionExceeded
//*****************************************************************************
template<> std::string OandaExceptionBase<PrecisionExceeded>::m_reason =
		"The error message “STOP_LOSS_ON_FILL_PRICE_PRECISION_EXCEEDED” means that The Stop Loss on fill "
		"specifies a price with more precision than is allowed by the Order’s instrument. "
		"Confirm the value provided for price is a string.";
template<> OandaExceptionType OandaExceptionBase<PrecisionExceeded>::m_exceptionType = OandaExceptionType::PrecisionExceeded;
template<> unsigned short OandaExceptionBase<PrecisionExceeded>::m_httpStatusCode = 400;
template<> std::string OandaExceptionJsonTest<PrecisionExceeded>::m_jsonKey = "rejectReason";

//*****************************************************************************
// Unauthorized
//*****************************************************************************
template<> std::string OandaExceptionBase<Unauthorized>::m_reason =
		"The endpoint being accessed requires the client to be authenticated however the authentication token is invalid or has not been provided.";
template<> OandaExceptionType OandaExceptionBase<Unauthorized>::m_exceptionType = OandaExceptionType::Unauthorized;
template<> unsigned short OandaExceptionBase<Unauthorized>::m_httpStatusCode = 401;

//*****************************************************************************
// InvalidAccountID
//*****************************************************************************
template<> std::string OandaExceptionBase<InvalidAccountID>::m_reason =
		"The given accountID is invalid. Confirm the accountID is correct.";
template<> OandaExceptionType OandaExceptionBase<InvalidAccountID>::m_exceptionType = OandaExceptionType::InvalidAccountID;
template<> unsigned short OandaExceptionBase<InvalidAccountID>::m_httpStatusCode = 401;
template<> std::string OandaExceptionJsonTest<InvalidAccountID>::m_jsonKey = "errorMessage";

//*****************************************************************************
// InsufficientAuthorization
//*****************************************************************************
template<> std::string OandaExceptionBase<InsufficientAuthorization>::m_reason = "The endpoint being accessed requires the client to be authenticated. "
		"The following information needs to be verified:\n"
		"1.The URL provided to the curl command is correct. Click here to learn how to configure curl examples that can be copied without further modification.\n"
		"2.The authentication token is valid and has been added as a Bearer token in the HTTP Authorization header.";
template<> OandaExceptionType OandaExceptionBase<InsufficientAuthorization>::m_exceptionType = OandaExceptionType::InsufficientAuthorization;
template<> unsigned short OandaExceptionBase<InsufficientAuthorization>::m_httpStatusCode = 401;
template<> std::string OandaExceptionJsonTest<InsufficientAuthorization>::m_jsonKey = "errorMessage";

//*****************************************************************************
// Forbidden
//*****************************************************************************
template<> std::string OandaExceptionBase<Forbidden>::m_reason =
		"The client has provided a token that does not authorize them to perform the action implemented by the API endpoint.";
template<> OandaExceptionType OandaExceptionBase<Forbidden>::m_exceptionType = OandaExceptionType::Forbidden;
template<> unsigned short OandaExceptionBase<Forbidden>::m_httpStatusCode = 403;

//*****************************************************************************
// AccountNotTradable
//*****************************************************************************
template<> std::string OandaExceptionBase<AccountNotTradable>::m_reason =
		"The account specified can not be used for trading. Please contact OANDA support for more details.";
template<> OandaExceptionType OandaExceptionBase<AccountNotTradable>::m_exceptionType = OandaExceptionType::AccountNotTradable;
template<> unsigned short OandaExceptionBase<AccountNotTradable>::m_httpStatusCode = 403;
template<> std::string OandaExceptionJsonTest<AccountNotTradable>::m_jsonKey = "errorMessage";

//*****************************************************************************
// NotFound
//*****************************************************************************
template<> std::string OandaExceptionBase<NotFound>::m_reason =
		"The client is attempting to refer to an entity (Account, Trade, Order, Position, etc.) that does not exist.";
template<> OandaExceptionType OandaExceptionBase<NotFound>::m_exceptionType = OandaExceptionType::NotFound;
template<> unsigned short OandaExceptionBase<NotFound>::m_httpStatusCode = 404;

//*****************************************************************************
// NoSuchTrade
//*****************************************************************************
template<> std::string OandaExceptionBase<NoSuchTrade>::m_reason =
		"The trade id specified is not valid. The trade returns recent trade and it is possible that "
		"the trade being referenced is no longer in the recent trade list.";
template<> OandaExceptionType OandaExceptionBase<NoSuchTrade>::m_exceptionType = OandaExceptionType::NoSuchTrade;
template<> unsigned short OandaExceptionBase<NoSuchTrade>::m_httpStatusCode = 404;
template<> std::string OandaExceptionJsonTest<NoSuchTrade>::m_jsonKey = "errorMessage";

//*****************************************************************************
// NoSuchTransaction
//*****************************************************************************
template<> std::string OandaExceptionBase<NoSuchTransaction>::m_reason =
		"The transaction id specified is not valid. The transactions returns recent transactions and it "
		"is possible that the transaction being referenced is no longer in the recent transactions list.";
template<> OandaExceptionType OandaExceptionBase<NoSuchTransaction>::m_exceptionType = OandaExceptionType::NoSuchTransaction;
template<> unsigned short OandaExceptionBase<NoSuchTransaction>::m_httpStatusCode = 404;
template<> std::string OandaExceptionJsonTest<NoSuchTransaction>::m_jsonKey = "errorMessage";

//*****************************************************************************
// NoSuchOrder
//*****************************************************************************
template<> std::string OandaExceptionBase<NoSuchOrder>::m_reason =
		"The order id specified is not valid. The /orders returns recent transactions and it is possible "
		"that the order being referenced is no longer in the recent order list.";
template<> OandaExceptionType OandaExceptionBase<NoSuchOrder>::m_exceptionType = OandaExceptionType::NoSuchOrder;
template<> unsigned short OandaExceptionBase<NoSuchOrder>::m_httpStatusCode = 404;
template<> std::string OandaExceptionJsonTest<NoSuchOrder>::m_jsonKey = "errorMessage";

//*****************************************************************************
// MethodNotAllowed
//*****************************************************************************
template<> std::string OandaExceptionBase<MethodNotAllowed>::m_reason =
		"The client is accessing an endpoint using an incorrect HTTP method – for example, using GET on an endpoint that requires POST.";
template<> OandaExceptionType OandaExceptionBase<MethodNotAllowed>::m_exceptionType = OandaExceptionType::MethodNotAllowed;
template<> unsigned short OandaExceptionBase<MethodNotAllowed>::m_httpStatusCode = 405;

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */
