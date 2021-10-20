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
 * @file   Order.hpp
 * @author Scott Brauer
 * @date   01-20-2021
 */

#ifndef OANDA_V20_ENDPOINT_ORDER_HPP
#define OANDA_V20_ENDPOINT_ORDER_HPP

#include <nlohmann/json.hpp>
#include <cpprest/http_headers.h>

#include "oanda/v20/json/JsonToFrom.hpp"

#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"
#include "oanda/v20/endpoint/OandaEndpointResponses.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace order {

namespace order {

	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this)
		{}

		AcceptDatetimeFormatParameter acceptDateTimeFormat; ///< Format of DateTime fields in the request and response.
		Parameter accountID;	 ///< Account Identifier [required]
	};

	template<typename OrderRequest>
	struct Request {
		OrderRequest order; ///< Specification of the Order to create
	};

	struct Response
	{
		// Response Headers
		std::string requestID;	///< The unique identifier generated for the request
		std::string location;	///< A link to the Order that was just created

		oanda::v20::transaction::Transaction orderCreateTransaction; ///< The Transaction that created the Order specified by the request.
		oanda::v20::transaction::OrderFillTransaction orderFillTransaction; ///< The Transaction that filled the newly created Order.
																			///< Only provided when the Order was immediately filled.
		oanda::v20::transaction::OrderCancelTransaction orderCancelTransaction; ///< The Transaction that cancelled the newly created Order.
																				///< Only provided when the Order was immediately cancelled.
		oanda::v20::transaction::Transaction orderReissueTransaction; ///< The Transaction that reissues the Order.
																	  ///< Only provided when the Order is configured to be reissued for its
																	  ///< remaining units after a partial fill and the reissue was successful.
		oanda::v20::transaction::Transaction orderReissueRejectTransaction; ///< The Transaction that rejects the reissue of the Order.
																			///< Only provided when the Order is configured to be reissued for
																			///< its remaining units after a partial fill and the reissue was rejected.
		std::vector<oanda::v20::transaction::TransactionID> relatedTransactionIDs; ///< The IDs of all Transactions that were created while satisfying the request.
		oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the most recent Transaction created for the Account
	};

	template<typename OrderRequest>
	void to_json(nlohmann::json& j, const Request<OrderRequest>& p);
	template<typename OrderRequest>
	void from_json(const nlohmann::json& j, Request<OrderRequest>& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace order */

namespace marketorder {

	using Parameters =	order::Parameters;
	using Request =		order::Request<oanda::v20::order::MarketOrderRequest>;
	using Response =	order::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace marketorder */

namespace limitorder {

	using Parameters =	order::Parameters;
	using Request =		order::Request<oanda::v20::order::LimitOrderRequest>;
	using Response =	order::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace limitorder */

namespace stoporder {

	using Parameters =	order::Parameters;
	using Request =		order::Request<oanda::v20::order::StopOrderRequest>;
	using Response =	order::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace stoporder */

namespace marketiftouchedorder {

	using Parameters =	order::Parameters;
	using Request =		order::Request<oanda::v20::order::MarketIfTouchedOrderRequest>;
	using Response =	order::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace marketiftouchedorder */

namespace takeprofitorder {

	using Parameters =	order::Parameters;
	using Request =		order::Request<oanda::v20::order::TakeProfitOrderRequest>;
	using Response =	order::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace takeprofitorder */

namespace stoplossorder {

	using Parameters =	order::Parameters;
	using Request =		order::Request<oanda::v20::order::StopLossOrderRequest>;
	using Response =	order::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace stoplossorder */

namespace guaranteedstoplossorder {

	using Parameters =	order::Parameters;
	using Request =		order::Request<oanda::v20::order::GuaranteedStopLossOrderRequest>;
	using Response =	order::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace guaranteedstoplossorder */

namespace trailingstoplossorder {

	using Parameters =	order::Parameters;
	using Request =		order::Request<oanda::v20::order::TrailingStopLossOrderRequest>;
	using Response =	order::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace trailingstoplossorder */

namespace orders {

	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			ids("ids", endpoint::ParameterType::QUERY, *this),
			state("state", endpoint::ParameterType::QUERY, *this),
			instrument("instrument", endpoint::ParameterType::QUERY, *this),
			count("count", endpoint::ParameterType::QUERY, *this),
			beforeID("beforeID", endpoint::ParameterType::QUERY, *this)
		{}

		AcceptDatetimeFormatParameter acceptDateTimeFormat; ///< Format of DateTime fields in the request and response.
		Parameter accountID;	///< Account Identifier [required]
		Parameter ids;			///< List of OrderID (csv)	List of Order IDs to retrieve
		Parameter state;		///< The state to filter the requested Orders by [default=PENDING]
		Parameter instrument;	///< The instrument to filter the requested orders by
		Parameter count;		///< The maximum number of Orders to return [default=50, maximum=500]
		Parameter beforeID;		///< The maximum Order ID to return. If not provided the most recent Orders in the Account are returned
	};

	struct Request {}; ///< Empty

	struct Response
	{
		// Response Headers
		std::string requestID;	///< The unique identifier generated for the request
		std::string link;		///< A link to the next page of results if the results were paginated

   		std::vector<oanda::v20::order::Order> orders; ///< The list of Order detail objects
   		oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the most recent Transaction created for the Account
	};

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace orders */

namespace pendingorders {

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
	struct Request {};

	/**
	 *
	 */
	struct Response
	{
		std::string requestID; ///< The unique identifier generated for the request

		std::vector<oanda::v20::order::Order> orders; ///< The list of pending Order details
   		oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the most recent Transaction created for the Account
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace pendingorders */

namespace orderdetails {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			orderSpecifier("orderSpecifier", endpoint::ParameterType::PATH, *this) {}

		AcceptDatetimeFormatParameter acceptDateTimeFormat; ///< Format of DateTime fields in the request and response.
		Parameter accountID; ///< Account Identifier [required]
		Parameter orderSpecifier; ///< The Order Specifier [required]
	};

	/**
	 *
	 */
	struct Request {};

	/**
	 *
	 */
	struct Response
	{
		std::string link; ///< A link to the next/previous order book snapshot.
		std::string requestID; ///< The unique identifier generated for the request

		oanda::v20::order::Order order; ///< The details of the Order requested
   		oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the most recent Transaction created for the Account
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace orderdetails */


namespace replaceorder {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			clientRequestID("ClientRequestID", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			orderSpecifier("orderSpecifier", endpoint::ParameterType::PATH, *this) {}

		AcceptDatetimeFormatParameter acceptDateTimeFormat; ///< Format of DateTime fields in the request and response.
		Parameter clientRequestID;		///< Client specified RequestID to be sent with request.
		Parameter accountID;			///< Account Identifier [required]
		Parameter orderSpecifier;		///< The Order Specifier [required]
	};

	/**
	 *
	 */
	template<typename OrderRequest>
	struct Request {
		OrderRequest order; ///< Specification of the replacing Order
	};

	/**
	 *
	 */
	struct Response
	{
		std::string location; ///< A link to the replacing Order
		std::string requestID; ///< The unique identifier generated for the request

   		oanda::v20::transaction::OrderCancelTransaction orderCancelTransaction; ///< The Transaction that cancelled the Order to be replaced.
   		oanda::v20::transaction::Transaction orderCreateTransaction; ///< The Transaction that created the replacing Order as requested.
   		oanda::v20::transaction::OrderFillTransaction orderFillTransaction; ///< The Transaction that filled the replacing Order.
   													   ///< This is only provided when the replacing Order was immediately filled.
   		oanda::v20::transaction::Transaction orderReissueTransaction; ///< The Transaction that reissues the replacing Order.
																	  ///< Only provided when the replacing Order was partially filled
																	  ///< immediately and is configured to be reissued for its remaining units.
   		oanda::v20::transaction::Transaction orderReissueRejectTransaction; ///< The Transaction that rejects the reissue of the Order.
																			///< Only provided when the replacing Order was partially filled immediately and
																			///< was configured to be reissued, however the reissue was rejected.
   		oanda::v20::transaction::OrderCancelTransaction replacingOrderCancelTransaction; ///< The Transaction that cancelled the replacing Order.
   																						 ///< Only provided when the replacing Order was immediately cancelled.
   		std::vector<oanda::v20::transaction::TransactionID> relatedTransactionIDs; ///< The IDs of all Transactions that were created while satisfying the request.
		oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the most recent Transaction created for the Account
	};

	// Json
	template<typename OrderRequest>
	void to_json(nlohmann::json& j, const Request<OrderRequest>& p);
	template<typename OrderRequest>
	void from_json(const nlohmann::json& j, Request<OrderRequest>& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace replaceorder */

namespace replacemarketorder {

	using Parameters =	replaceorder::Parameters;
	using Request =		replaceorder::Request<oanda::v20::order::MarketOrderRequest>;
	using Response =	replaceorder::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace replacemarketorder */

namespace replacelimitorder {

	using Parameters =	replaceorder::Parameters;
	using Request =		replaceorder::Request<oanda::v20::order::LimitOrderRequest>;
	using Response =	replaceorder::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace replacelimitorder */

namespace replacestoporder {

	using Parameters =	replaceorder::Parameters;
	using Request =		replaceorder::Request<oanda::v20::order::StopOrderRequest>;
	using Response =	replaceorder::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace replacestoporder */

namespace replacemarketiftouchedorder {

	using Parameters =	replaceorder::Parameters;
	using Request =		replaceorder::Request<oanda::v20::order::MarketIfTouchedOrderRequest>;
	using Response =	replaceorder::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace replacemarketiftouchedorder */

namespace replacetakeprofitorder {

	using Parameters =	replaceorder::Parameters;
	using Request =		replaceorder::Request<oanda::v20::order::TakeProfitOrderRequest>;
	using Response =	replaceorder::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace replacetakeprofitorder */

namespace replacestoplossorder {

	using Parameters =	replaceorder::Parameters;
	using Request =		replaceorder::Request<oanda::v20::order::StopLossOrderRequest>;
	using Response =	replaceorder::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace replacestoplossorder */

namespace replaceguaranteedstoplossorder {

	using Parameters =	replaceorder::Parameters;
	using Request =		replaceorder::Request<oanda::v20::order::GuaranteedStopLossOrderRequest>;
	using Response =	replaceorder::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace replaceguaranteedstoplossorder */

namespace replacetrailingstoplossorder {

	using Parameters =	replaceorder::Parameters;
	using Request =		replaceorder::Request<oanda::v20::order::TrailingStopLossOrderRequest>;
	using Response =	replaceorder::Response;

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace replacetrailingstoplossorder */

namespace cancelorder {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			clientRequestID("ClientRequestID", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			orderSpecifier("orderSpecifier", endpoint::ParameterType::PATH, *this) {}

		AcceptDatetimeFormatParameter acceptDateTimeFormat; ///< Format of DateTime fields in the request and response.
		Parameter clientRequestID; ///< Client specified RequestID to be sent with request.
		Parameter accountID; ///< Account Identifier [required]
		Parameter orderSpecifier; ///< The Order Specifier [required]
	};

	/**
	 *
	 */
	struct Request {};

	/**
	 *
	 */
	struct Response
	{
		std::string requestID; ///< The unique identifier generated for the request

		oanda::v20::transaction::OrderCancelTransaction orderCancelTransaction;		///< The Transaction that cancelled the Order
		std::vector<oanda::v20::transaction::TransactionID> relatedTransactionIDs;	///< The IDs of all Transactions that were created while satisfying the request.
		oanda::v20::transaction::TransactionID lastTransactionID;					///< The ID of the most recent Transaction created for the Account
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace cancelorder */

namespace clientextensions {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("instrument", endpoint::ParameterType::PATH, *this),
			orderSpecifier("time", endpoint::ParameterType::PATH, *this) {}

		AcceptDatetimeFormatParameter acceptDateTimeFormat; ///< Format of DateTime fields in the request and response.
		Parameter accountID; ///< Account Identifier [required]
		Parameter orderSpecifier; ///< The Order Specifier [required]
	};

	/**
	 *
	 */
	struct Request {
		 oanda::v20::transaction::ClientExtensions clientExtensions; ///< The Client Extensions to update for the Order.
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 ///< Do not set, modify, or delete clientExtensions if your account is associated with MT4.
		 oanda::v20::transaction::ClientExtensions tradeClientExtensions;	///< The Client Extensions to update for the Trade created when the Order is filled.
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	///< Do not set, modify, or delete clientExtensions if your account is associated with MT4.
	};

	/**
	 *
	 */
	struct Response
	{
		std::string requestID; ///< The unique identifier generated for the request

		 oanda::v20::transaction::OrderClientExtensionsModifyTransaction orderClientExtensionsModifyTransaction; ///< The Transaction that modified the Client Extensions for the Order
		 oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the most recent Transaction created for the Account
		 std::vector<oanda::v20::transaction::TransactionID> relatedTransactionIDs; ///< The IDs of all Transactions that were created while satisfying the request.
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace clientextensions */

} /* namespace order */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_ORDER_HPP */
