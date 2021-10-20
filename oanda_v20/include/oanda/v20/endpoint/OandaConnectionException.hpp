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
 * @file   OandaException.hpp
 * @author Scott Brauer
 * @date   12-21-2020
 */

#ifndef OANDA_V20_ENDPOINT_OANDAEXCEPTION_HPP_
#define OANDA_V20_ENDPOINT_OANDAEXCEPTION_HPP_

#include <string>
#include <stdexcept>

#include "oanda/v20/common/OandaCommonException.hpp"
using namespace oanda::v20;

namespace oanda {
namespace v20 {
namespace endpoint {

enum class OandaExceptionType {
	UnknownException,
	BadRequest,
	MalformedRequest,
	InvalidInstrument,
	PrecisionExceeded,
	Unauthorized,
	InvalidAccountID,
	InsufficientAuthorization,
	Forbidden,
	AccountNotTradable,
	NotFound,
	NoSuchTrade,
	NoSuchTransaction,
	NoSuchOrder,
	MethodNotAllowed
};

/**
 * Base exception for all Oanda exceptions
 */
class OandaConnectionException: public common::OandaRuntimeException
{
public:
	explicit OandaConnectionException(const std::string& what_arg): OandaRuntimeException(what_arg) {}
	explicit OandaConnectionException(const char* what_arg): OandaRuntimeException(what_arg) {}

	virtual const std::string reason() = 0;
	virtual OandaExceptionType exceptionType() = 0;
	virtual unsigned short httpStatusCode() = 0;
};


/**
 * Base exception for all Oanda exceptions
 */
template<class Derived>
class OandaExceptionBase: public OandaConnectionException
{
public:
	explicit OandaExceptionBase(const std::string& what_arg): OandaConnectionException(what_arg) {}
	explicit OandaExceptionBase(const char* what_arg): OandaConnectionException(what_arg) {}

	virtual const std::string reason() { return m_reason; }
	virtual OandaExceptionType exceptionType() { return m_exceptionType; }
	virtual unsigned short httpStatusCode() { return m_httpStatusCode; }

	static const std::string s_reason() { return m_reason; }
	static OandaExceptionType s_exceptionType() { return m_exceptionType; }
	static unsigned short s_httpStatusCode() { return m_httpStatusCode; }

private:
	static std::string m_reason;
	static OandaExceptionType m_exceptionType;
	static unsigned short m_httpStatusCode;
};

template<class T>
struct OandaExceptionJsonTest
{
public:
	static std::string& jsonKey() { return m_jsonKey; }
	static bool errorTest(unsigned short statusCode, const std::string& msg) {
		return (statusCode == T::s_httpStatusCode()) && T::jsonMsgMatch(msg);
	}

private:
	static std::string m_jsonKey;
};

/**
 * Unknown Bad Request
 * A “Unknown Bad Request” response may be returned from the v20 REST API
 * when the client has provided invalid data to be processed.
 */
class UnknownBadRequest: public common::OandaRuntimeException
{
public:
	explicit UnknownBadRequest(unsigned short httpStatusCode, const std::string& what_arg):
			m_httpStatusCode(httpStatusCode),
			OandaRuntimeException("HTTP StatusCode(" + std::to_string(httpStatusCode) + "): " + what_arg) {}
	explicit UnknownBadRequest(unsigned short httpStatusCode, const char* what_arg):
			m_httpStatusCode(httpStatusCode),
			OandaRuntimeException("HTTP StatusCode(" + std::to_string(httpStatusCode) + "): " + what_arg) {}

private:
	explicit UnknownBadRequest(const std::string& what_arg):
			OandaRuntimeException(what_arg),
			m_httpStatusCode(0) {}
	explicit UnknownBadRequest(const char* what_arg):
			OandaRuntimeException(what_arg),
			m_httpStatusCode(0) {}

	unsigned short m_httpStatusCode;
};

/**
 * 400 Bad Request
 * A “400 Bad Request” response may be returned from the v20 REST API
 * when the client has provided invalid data to be processed.
 */
class BadRequest: public OandaExceptionBase<BadRequest>
{
public:
	explicit BadRequest(const std::string& what_arg): OandaExceptionBase<BadRequest>(what_arg) {}
	explicit BadRequest(const char* what_arg): OandaExceptionBase<BadRequest>(what_arg) {}
};

/**
 * Malformed Request
 * If an incorrect request is submitted the following error will be returned to the user.
 * "errorMessage" : "The request was missing required data"
 * Reason: One or more required parameters for the request is missing or is invalid.
 */
class MalformedRequest: public OandaExceptionBase<MalformedRequest>, public OandaExceptionJsonTest<MalformedRequest>
{
public:
	explicit MalformedRequest(const std::string& what_arg): OandaExceptionBase<MalformedRequest>(what_arg) {}
	explicit MalformedRequest(const char* what_arg): OandaExceptionBase<MalformedRequest>(what_arg) {}
	static bool jsonMsgMatch(const std::string& msg) { return msg.find("request") != std::string::npos; }
};

/**
 * Invalid Instrument
 * If an incorrect currency is submitted the following error will be returned to the user.
 * "errorMessage":"Invalid value specified for 'instrument'"
 * Reason: The Currency provided is invalid. Confirm the structure of currency is correct.
 */
class InvalidInstrument: public OandaExceptionBase<InvalidInstrument>, public OandaExceptionJsonTest<InvalidInstrument>
{
public:
	explicit InvalidInstrument(const std::string& what_arg): OandaExceptionBase<InvalidInstrument>(what_arg) {}
	explicit InvalidInstrument(const char* what_arg): OandaExceptionBase<InvalidInstrument>(what_arg) {}
	static bool jsonMsgMatch(const std::string& msg) { return msg.find("instrument") != std::string::npos; }
};

/**
 * PRECISION_EXCEEDED
 * If an incorrect value is submitted the following error will be returned to the user.
 * "rejectReason":" STOP_LOSS_ON_FILL_PRICE_PRECISION_EXCEEDED"
 * Reason: The error message “STOP_LOSS_ON_FILL_PRICE_PRECISION_EXCEEDED” means that
 * The Stop Loss on fill specifies a price with more precision than is allowed by the Order’s instrument.
 * Confirm the value provided for price is a string.
 */
class PrecisionExceeded: public OandaExceptionBase<PrecisionExceeded>, public OandaExceptionJsonTest<PrecisionExceeded>
{
public:
	explicit PrecisionExceeded(const std::string& what_arg): OandaExceptionBase<PrecisionExceeded>(what_arg) {}
	explicit PrecisionExceeded(const char* what_arg): OandaExceptionBase<PrecisionExceeded>(what_arg) {}
	static bool jsonMsgMatch(const std::string& msg) { return msg.find("STOP_LOSS_ON_FILL_PRICE_PRECISION_EXCEEDED") != std::string::npos; }
};

/**
 * 401 Unauthorized
 * A “401 Unauthorized” response may be returned from the v20 REST API when the endpoint
 * being accessed requires the client to be authenticated however the authentication token
 * is invalid or has not been provided. *
 */
class Unauthorized: public OandaExceptionBase<Unauthorized>
{
public:
	explicit Unauthorized(const std::string& what_arg): OandaExceptionBase<Unauthorized>(what_arg) {}
	explicit Unauthorized(const char* what_arg): OandaExceptionBase<Unauthorized>(what_arg) {}
};

/**
 * Invalid AccountID
 * If an incorrect accountID is submitted the following error will be returned to the user.
 * "errorMessage":"The provided request was forbidden."
 * Reason: The given accountID is invalid. Confirm the accountID is correct.
 */
class InvalidAccountID: public OandaExceptionBase<InvalidAccountID>, public OandaExceptionJsonTest<InvalidAccountID>
{
public:
	explicit InvalidAccountID(const std::string& what_arg): OandaExceptionBase<InvalidAccountID>(what_arg) {}
	explicit InvalidAccountID(const char* what_arg): OandaExceptionBase<InvalidAccountID>(what_arg) {}
	static bool jsonMsgMatch(const std::string& msg) { return msg.find("request was forbidden") != std::string::npos; }
};

/**
 * Insufficient Authorization
 * If an incorrect request is submitted the following error will be returned to the user.
 * "errorMessage":"Insufficient authorization to perform request."
 * Reason: The endpoint being accessed requires the client to be authenticated. The following information needs to be verified:
 * 1.The URL provided to the curl command is correct. Click here to learn how to configure curl examples that can be copied without further modification.
 * 2.The authentication token is valid and has been added as a Bearer token in the HTTP Authorization header.
 */
class InsufficientAuthorization: public OandaExceptionBase<InsufficientAuthorization>, public OandaExceptionJsonTest<InsufficientAuthorization>
{
public:
	explicit InsufficientAuthorization(const std::string& what_arg): OandaExceptionBase<InsufficientAuthorization>(what_arg) {}
	explicit InsufficientAuthorization(const char* what_arg): OandaExceptionBase<InsufficientAuthorization>(what_arg) {}
	static bool jsonMsgMatch(const std::string& msg) { return msg.find("Insufficient authorization") != std::string::npos; }
};

/**
 * 403 Forbidden
 * A “403 Forbidden” response may be returned from the v20 REST API when the client has provided
 * a token that does not authorize them to perform the action implemented by the API endpoint.
 */
class Forbidden: public OandaExceptionBase<Forbidden>
{
public:
	explicit Forbidden(const std::string& what_arg): OandaExceptionBase<Forbidden>(what_arg) {}
	explicit Forbidden(const char* what_arg): OandaExceptionBase<Forbidden>(what_arg) {}
};

/**
 * Account Not Tradable
 * If an incorrect request is submitted the following error will be returned to the user.
 * "errorMessage":"Insufficient authorization to perform request."
 * Reason: The account specified can not be used for trading. Please contact OANDA support for more details
 */
class AccountNotTradable: public OandaExceptionBase<AccountNotTradable>, public OandaExceptionJsonTest<AccountNotTradable>
{
public:
	explicit AccountNotTradable(const std::string& what_arg): OandaExceptionBase<AccountNotTradable>(what_arg) {}
	explicit AccountNotTradable(const char* what_arg): OandaExceptionBase<AccountNotTradable>(what_arg) {}
	static bool jsonMsgMatch(const std::string& msg) { return msg.find("Insufficient authorization") != std::string::npos; }
};

/**
 * 404 Not Found
 * A “404 Not Found” response may be returned from the v20 REST API when the client is attempting to refer
 * to an entity (Account, Trade, Order, Position, etc.) that does not exist.
 */
class NotFound: public OandaExceptionBase<NotFound>
{
public:
	explicit NotFound(const std::string& what_arg): OandaExceptionBase<NotFound>(what_arg) {}
	explicit NotFound(const char* what_arg): OandaExceptionBase<NotFound>(what_arg) {}
};

/**
 * NO_SUCH_TRADE
 * If an incorrect trade ID is submitted the following error will be returned to the user.
 * "errorMessage":"The trade ID specified does not exist"
 * Reason: The trade id specified is not valid. The /trade returns recent trade and it is
 * possible that the trade being referenced is no longer in the recent trade list.
 */
class NoSuchTrade: public OandaExceptionBase<NoSuchTrade>, public OandaExceptionJsonTest<NoSuchTrade>
{
public:
	explicit NoSuchTrade(const std::string& what_arg): OandaExceptionBase<NoSuchTrade>(what_arg) {}
	explicit NoSuchTrade(const char* what_arg): OandaExceptionBase<NoSuchTrade>(what_arg) {}
	static bool jsonMsgMatch(const std::string& msg) { return msg.find("trade ID") != std::string::npos; }
};

/**
 * NO_SUCH_TRANSACTION
 * If an incorrect transaction ID is submitted the following error will be returned to the user.
 * "errorMessage":"The transaction ID specified does not exist"
 * Reason: The transaction id specified is not valid. The /transactions returns recent transactions
 * and it is possible that the transaction being referenced is no longer in the recent transactions list.
 */
class NoSuchTransaction: public OandaExceptionBase<NoSuchTransaction>, public OandaExceptionJsonTest<NoSuchTransaction>
{
public:
	explicit NoSuchTransaction(const std::string& what_arg): OandaExceptionBase<NoSuchTransaction>(what_arg) {}
	explicit NoSuchTransaction(const char* what_arg): OandaExceptionBase<NoSuchTransaction>(what_arg) {}
	static bool jsonMsgMatch(const std::string& msg) { return msg.find("transaction ID") != std::string::npos; }
};

/**
 * NO_SUCH_ORDER
 * If an incorrect order ID is submitted the following error will be returned to the user.
 * "errorMessage":"The order ID specified does not exist"
 * Reason: The order id specified is not valid. The /orders returns recent transactions and it is possible
 * that the order being referenced is no longer in the recent order list.
 */
class NoSuchOrder: public OandaExceptionBase<NoSuchOrder>, public OandaExceptionJsonTest<NoSuchOrder>
{
public:
	explicit NoSuchOrder(const std::string& what_arg): OandaExceptionBase<NoSuchOrder>(what_arg) {}
	explicit NoSuchOrder(const char* what_arg): OandaExceptionBase<NoSuchOrder>(what_arg) {}
	static bool jsonMsgMatch(const std::string& msg) { return msg.find("order ID") != std::string::npos; }
};

/**
 * 405 Method Not Allowed
 * The “405 Method Not Allowed” response may be returned from the v20 REST API when the client is accessing
 * an endpoint using an incorrect HTTP method – for example, using GET on an endpoint that requires POST.
 */
class MethodNotAllowed: public OandaExceptionBase<MethodNotAllowed>
{
public:
	explicit MethodNotAllowed(const std::string& what_arg): OandaExceptionBase<MethodNotAllowed>(what_arg) {}
	explicit MethodNotAllowed(const char* what_arg): OandaExceptionBase<MethodNotAllowed>(what_arg) {}
};

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_OANDAEXCEPTION_HPP_ */
