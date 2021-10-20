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
 * @file   Transaction.hpp
 * @author Scott Brauer
 * @date   02-07-2021
 */

#ifndef OANDA_V20_ENDPOINT_TRANSACTION_HPP
#define OANDA_V20_ENDPOINT_TRANSACTION_HPP

#include <nlohmann/json.hpp>
#include <cpprest/http_headers.h>

#include "oanda/v20/json/JsonToFrom.hpp"

#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"
#include "oanda/v20/endpoint/OandaEndpointResponses.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace transaction {

namespace transactions {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			from("from", endpoint::ParameterType::QUERY, *this),
			to("to", endpoint::ParameterType::QUERY, *this),
			pageSize("pageSize", endpoint::ParameterType::QUERY, *this),
			type("type", endpoint::ParameterType::QUERY, *this)
		{}

		/// Format of DateTime fields in the request and response.
		AcceptDatetimeFormatParameter acceptDateTimeFormat;

		/// Account Identifier [required]
		Parameter accountID;

		/// The starting time (inclusive) of the time range for the Transactions being queried. [default=Account Creation Time]
		Parameter from;

		/// The ending time (inclusive) of the time range for the Transactions being queried. [default=Request Time]
		Parameter to;

		/// The number of Transactions to include in each page of the results. [default=100, maximum=1000]
		Parameter pageSize;

		/// A filter for restricting the types of Transactions to retrieve.
		Parameter type;

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
		/// The unique identifier generated for the request
		std::string requestID;

		/// The starting time provided in the request.
		oanda::v20::primitives::DateTime from;

		/// The ending time provided in the request.
		oanda::v20::primitives::DateTime to;

		/// The pageSize provided in the request
		int pageSize;

		/// The Transaction-type filter provided in the request
		std::vector<oanda::v20::transaction::TransactionFilter> type;

		/// The number of Transactions that are contained in the pages returned
		int count;

		/// The list of URLs that represent idrange queries providing the data for
		/// each page in the query results
		std::vector<oanda::v20::common::String> pages;

		/// The ID of the most recent Transaction created for the Account
		oanda::v20::transaction::TransactionID lastTransactionID;
	};

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace transactions */

namespace transaction {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			transactionID("transactionID", endpoint::ParameterType::PATH, *this) {}

		AcceptDatetimeFormatParameter acceptDateTimeFormat; ///< Format of DateTime fields in the request and response.
		Parameter accountID; ///< Account Identifier [required]
		Parameter transactionID; ///< A Transaction ID [required]

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
		std::string requestID; ///< The unique identifier generated for the request

		/// The details of the Transaction requested
		oanda::v20::transaction::Transaction transaction;

		/// The ID of the most recent Transaction created for the Account
		oanda::v20::transaction::TransactionID lastTransactionID;
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace transaction */

namespace transactionsrange {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			from("from", endpoint::ParameterType::QUERY, *this),
			to("to", endpoint::ParameterType::QUERY, *this),
			type("type", endpoint::ParameterType::QUERY, *this)
		{}

		/// Format of DateTime fields in the request and response.
		AcceptDatetimeFormatParameter acceptDateTimeFormat;

		/// Account Identifier [required]
		Parameter accountID;

		/// The starting Transaction ID (inclusive) to fetch. [required]
		Parameter from;

		/// The ending Transaction ID (inclusive) to fetch. [required]
		Parameter to;

		/// The filter that restricts the types of Transactions to retrieve.
		Parameter type;
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
		std::string requestID; ///< The unique identifier generated for the request

		/// The list of Transactions that satisfy the request.
		std::vector<oanda::v20::transaction::Transaction> transactions;

		/// The ID of the most recent Transaction created for the Account
		oanda::v20::transaction::TransactionID lastTransactionID;
	};


	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace transactionsrange */

namespace transactionssince {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			id("id", endpoint::ParameterType::QUERY, *this),
			type("type", endpoint::ParameterType::QUERY, *this) {}

		AcceptDatetimeFormatParameter acceptDateTimeFormat; ///< Format of DateTime fields in the request and response.
		Parameter accountID; ///< Account Identifier [required]
		Parameter id; ///< The ID of the last Transaction fetched. This query will return all Transactions newer than the TransactionID. [required]
		Parameter type; ///< A filter for restricting the types of Transactions to retrieve.
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
		std::string requestID; ///< The unique identifier generated for the request

		/// The list of Transactions that satisfy the request.
		std::vector<oanda::v20::transaction::Transaction> transactions;

		/// The ID of the most recent Transaction created for the Account
		oanda::v20::transaction::TransactionID lastTransactionID;
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace transactionssince */


namespace transactionsstream {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this) {}

		AcceptDatetimeFormatParameter acceptDateTimeFormat; ///< Format of DateTime fields in the request and response.
		Parameter accountID; ///< Account Identifier [required]
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
//		std::string requestID; ///< The unique identifier generated for the request

//		oanda::v20::instrument::PositionBook positionBook; ///< The instrument’s position book
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace transactionsstream */

} /* namespace transaction */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_TRANSACTION_HPP */
