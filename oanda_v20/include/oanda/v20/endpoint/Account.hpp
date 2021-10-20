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
 * @file   Account.hpp
 * @author Scott Brauer
 * @date   01-14-2021
 */

#ifndef OANDA_V20_ENDPOINT_ACCOUNT_HPP
#define OANDA_V20_ENDPOINT_ACCOUNT_HPP

#include <nlohmann/json.hpp>
#include <cpprest/http_headers.h>

#include "oanda/v20/json/JsonToFrom.hpp"

#include "oanda/v20/account/AccountProperties.hpp"
#include "oanda/v20/account/Account.hpp"
#include "oanda/v20/account/AccountSummary.hpp"
#include "oanda/v20/primitives/Instrument.hpp"
#include "oanda/v20/transaction/ClientConfigureTransaction.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/account/AccountChanges.hpp"
#include "oanda/v20/account/AccountChangesState.hpp"

#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"
#include "oanda/v20/endpoint/OandaEndpointResponses.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace account {

namespace accounts {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters() {}

	};

	/**
	 *
	 */
	class Request {};

	/**
	 *
	 */
	struct Response
	{
		// Response Headers
		oanda::v20::common::String requestID; ///< The unique identifier generated for the request

		std::vector<oanda::v20::account::AccountProperties> accounts; ///< The list of Accounts the client is authorized to access and their associated properties.
	};

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace accounts */

namespace account {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this) {}

		Parameter accountID;
		AcceptDatetimeFormatParameter acceptDateTimeFormat;
	};

	/**
	 *
	 */
	class Request {};

	/**
	 *
	 */
	struct Response
	{
		// Response Headers
		oanda::v20::common::String requestID; ///< The unique identifier generated for the request

		oanda::v20::account::Account account; ///< The full details of the requested Account.
		oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the most recent Transaction created for the Account.
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace account */

namespace accountsummary {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this) {}

		Parameter accountID;
		AcceptDatetimeFormatParameter acceptDateTimeFormat;
	};

	/**
	 *
	 */
	class Request {};

	/**
	 *
	 */
	struct Response
	{
		// Response Headers
		oanda::v20::common::String requestID; ///< The unique identifier generated for the request

		oanda::v20::account::AccountSummary account; ///< The summary of the requested Account.
		oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the most recent Transaction created for the Account.
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace accountsummary */

namespace accountinstruments {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			instruments("instruments", endpoint::ParameterType::QUERY, *this) {}

		Parameter accountID;
		Parameter instruments;
	};

	/**
	 *
	 */
	class Request {};

	struct Response
	{
		// Response Headers
		oanda::v20::common::String requestID; ///< The unique identifier generated for the request

		std::vector<oanda::v20::primitives::Instrument> instruments; ///< The requested list of instruments.
		oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the most recent Transaction created for the Account.
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace accountinstruments */

namespace accountconfiguration {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this) {}

		Parameter accountID;
		AcceptDatetimeFormatParameter acceptDateTimeFormat;
	};

	/**
	 *
	 */
	struct Request
	{
		oanda::v20::common::String alias; ///< Client-defined alias (name) for the Account
		oanda::v20::primitives::DecimalNumber marginRate; ///< The string representation of a decimal number.
	};

	/**
	 *
	 */
	struct Response
	{
		// Response Headers
		oanda::v20::common::String requestID; ///< The unique identifier generated for the request

		oanda::v20::transaction::ClientConfigureTransaction clientConfigureTransaction; ///< The transaction that configures the Account.
		oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the last Transaction created for the Account.
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace accountconfiguration */

namespace accountchanges {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			sinceTransactionID("TransactionID", endpoint::ParameterType::QUERY, *this) {}

		Parameter accountID;
		AcceptDatetimeFormatParameter acceptDateTimeFormat;
		Parameter sinceTransactionID;
	};

	/**
	 *
	 */
	class Request {};

	/**
	 *
	 */
	struct Response
	{
		// Response Headers
		oanda::v20::common::String requestID; ///< The unique identifier generated for the request

		oanda::v20::account::AccountChanges changes; ///< The changes to the Account’s Orders, Trades and Positions since the specified Transaction ID.
													 ///< Only provided if the sinceTransactionID is supplied to the poll request.
		oanda::v20::account::AccountChangesState  state; ///< The Account’s current price-dependent state.
		oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the last Transaction created for the Account.
																  ///< This Transaction ID should be used for future poll requests,
																  ///< as the client has already observed all changes up to and including it.
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace accountchanges */

} /* namespace account */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_ACCOUNT_HPP */
