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
 * @file   Trade.hpp
 * @author Scott Brauer
 * @date   02-04-2021
 */

#ifndef OANDA_V20_ENDPOINT_TRADE_HPP
#define OANDA_V20_ENDPOINT_TRADE_HPP

#include <vector>

#include <nlohmann/json.hpp>
#include <cpprest/http_headers.h>

#include "oanda/v20/json/JsonToFrom.hpp"

#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"
#include "oanda/v20/endpoint/OandaEndpointResponses.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace trade {

namespace trades {

	/**
	 *
	 */
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
		Parameter accountID; ///< Account Identifier [required]
		Parameter ids; ///< List of Trade IDs to retrieve.
		Parameter state; ///< The state to filter the requested Trades by. [default=OPEN]
		Parameter instrument; ///< The instrument to filter the requested Trades by.
		Parameter count; ///< The maximum number of Trades to return. [default=50, maximum=500]
		Parameter beforeID; ///< The maximum Trade ID to return. If not provided the most recent Trades in the Account are returned.

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
		std::string requestID; ///< The unique identifier generated for the request
		std::string link; ///< A link to the next page of Trades if the results were paginated

		std::vector<oanda::v20::trade::Trade> trades; ///< The list of Trade detail objects
		oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the most recent Transaction created for the Account
	};

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace trades */

namespace opentrades {

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
		// Response Headers
		std::string requestID; ///< The unique identifier generated for the request

		std::vector<oanda::v20::trade::Trade> trades; ///< The list of Trade detail objects
		oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the most recent Transaction created for the Account
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace opentrades */

namespace trade {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			tradeSpecifier("tradeSpecifier", endpoint::ParameterType::PATH, *this) {}

		/// Format of DateTime fields in the request and response.
		AcceptDatetimeFormatParameter acceptDateTimeFormat;

		/// Account Identifier [required]
		Parameter accountID;

		/// Specifier for the Trade [required]
		Parameter tradeSpecifier;
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
		/// The unique identifier generated for the request
		std::string requestID;

		/// The details of the requested trade
		oanda::v20::trade::Trade trade;

		/// The ID of the most recent Transaction created for the Account
		oanda::v20::transaction::TransactionID lastTransactionID;
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace trade */

namespace close {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("instrument", endpoint::ParameterType::PATH, *this),
			tradeSpecifier("time", endpoint::ParameterType::QUERY, *this) {}

		AcceptDatetimeFormatParameter acceptDateTimeFormat; ///< Format of DateTime fields in the request and response.
		Parameter accountID; ///< Account Identifier [required]
		Parameter tradeSpecifier; ///< Specifier for the Trade [required]
	};

	/**
	 *
	 */
	struct Request
	{
		Request():
			units("ALL") {}
		/**
		 * Indication of how much of the Trade to close.
		 *
		 * Either the string “ALL”
		 * (indicating that all of the Trade should be closed), or a DecimalNumber
		 * representing the number of units of the open Trade to Close using a
		 * TradeClose MarketOrder. The units specified must always be positive, and
		 * the magnitude of the value cannot exceed the magnitude of the Trade’s
		 * open units.
		 *
		 * default=ALL
		 */
		oanda::v20::common::String units;
	};

	/**
	 *
	 */
	struct Response
	{
		/// The unique identifier generated for the request
		std::string requestID;

		/// The MarketOrder Transaction created to close the Trade.
		oanda::v20::transaction::MarketOrderTransaction orderCreateTransaction;

		/// The OrderFill Transaction that fills the Trade-closing MarketOrder and closes the Trade.
		oanda::v20::transaction::OrderFillTransaction orderFillTransaction;

		/// The OrderCancel Transaction that immediately cancelled the Trade-closing MarketOrder.
		oanda::v20::transaction::OrderCancelTransaction orderCancelTransaction;

		/// The IDs of all Transactions that were created while satisfying the request.
		std::vector<oanda::v20::transaction::TransactionID> relatedTransactionIDs;

		/// The ID of the most recent Transaction created for the Account
		oanda::v20::transaction::TransactionID lastTransactionID;
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace close */

namespace clientextensions {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			tradeSpecifier("tradeSpecifier", endpoint::ParameterType::PATH, *this) {}

		/// Format of DateTime fields in the request and response.
		AcceptDatetimeFormatParameter acceptDateTimeFormat;

		/// Account Identifier [required]
		Parameter accountID;

		/// Specifier for the Trade [required]
		Parameter tradeSpecifier;
	};

	/**
	 *
	 */
	struct Request {
		/** The Client Extensions to update the Trade with.
		 * Do not add, update, or delete the Client Extensions
		 * if your account is associated with MT4.
		 */
		oanda::v20::transaction::ClientExtensions clientExtensions;
	};

	/**
	 *
	 */
	struct Response
	{
		/// The unique identifier generated for the request
		std::string requestID;

		/// The Transaction that updates the Trade’s Client Extensions.
		oanda::v20::transaction::TradeClientExtensionsModifyTransaction tradeClientExtensionsModifyTransaction;

		/// The IDs of all Transactions that were created while satisfying the request.
		std::vector<oanda::v20::transaction::TransactionID> relatedTransactionIDs;

		/// The ID of the most recent Transaction created for the Account
		oanda::v20::transaction::TransactionID lastTransactionID;
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace clientextensions */

namespace orders {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			tradeSpecifier("tradeSpecifier", endpoint::ParameterType::PATH, *this) {}

		AcceptDatetimeFormatParameter acceptDateTimeFormat; ///< Format of DateTime fields in the request and response.
		Parameter accountID; ///< Account Identifier [required]
		Parameter tradeSpecifier; ///< Specifier for the Trade [required]
	};

	/**
	 *
	 */
	struct Request {
		/**
		 * The specification of the Take Profit to create/modify/cancel.
		 *
		 * If takeProfit is set to null, the Take Profit Order will be cancelled if it
		 * exists. If takeProfit is not provided, the existing Take Profit Order
		 * will not be modified. If a sub-field of takeProfit is not specified, that
		 * field will be set to a default value on create, and be inherited by the
		 * replacing order on modify.
		 */
		oanda::v20::transaction::TakeProfitDetails takeProfit;

		/**
		 * The specification of the Stop Loss to create/modify/cancel.
		 *
		 * If stopLoss is set to null, the Stop Loss Order will be cancelled if it exists. If
		 * stopLoss is not provided, the existing Stop Loss Order will not be
		 * modified. If a sub-field of stopLoss is not specified, that field will be
		 * set to a default value on create, and be inherited by the replacing order
		 * on modify.
		 */
		oanda::v20::transaction::StopLossDetails stopLoss;

		/**
		 * The specification of the Trailing Stop Loss to create/modify/cancel.
		 *
		 * If trailingStopLoss is set to null, the Trailing Stop Loss Order will be
		 * cancelled if it exists. If trailingStopLoss is not provided, the existing
		 * Trailing Stop Loss Order will not be modified. If a sub-field of
		 * trailingStopLoss is not specified, that field will be set to a default
		 * value on create, and be inherited by the replacing order on modify.
		 */
		oanda::v20::transaction::TrailingStopLossDetails trailingStopLoss;

		/**
		 * The specification of the Guaranteed Stop Loss to create/modify/cancel.
		 *
		 * If guaranteedStopLoss is set to null, the Guaranteed Stop Loss Order will be
		 * cancelled if it exists. If guaranteedStopLoss is not provided, the
		 * existing Guaranteed Stop Loss Order will not be modified. If a sub-field
		 * of guaranteedStopLoss is not specified, that field will be set to a
		 * efault value on create, and be inherited by the replacing order on
		 * modify.
		 */
		oanda::v20::transaction::GuaranteedStopLossDetails guaranteedStopLoss;
	};

	/**
	 *
	 */
	struct Response
	{
		std::string requestID; ///< The unique identifier generated for the request

		/**
		 * The Transaction created that cancels the Trade’s existing Take Profit
		 * Order.
		 */
		oanda::v20::transaction::OrderCancelTransaction takeProfitOrderCancelTransaction;

		/**
		 * The Transaction created that creates a new Take Profit Order for the
		 * Trade.
		 */
		oanda::v20::transaction::TakeProfitOrderTransaction takeProfitOrderTransaction;

		/**
		 * The Transaction created that immediately fills the Trade’s new Take
		 * Profit Order. Only provided if the new Take Profit Order was immediately
		 * filled.
		 */
		oanda::v20::transaction::OrderFillTransaction takeProfitOrderFillTransaction;

		/**
		 * The Transaction created that immediately cancels the Trade’s new Take
		 * Profit Order. Only provided if the new Take Profit Order was immediately
		 * cancelled.
		 */
		oanda::v20::transaction::OrderCancelTransaction takeProfitOrderCreatedCancelTransaction;

		/**
		 * The Transaction created that cancels the Trade’s existing Stop Loss
		 * Order.
		 */
		oanda::v20::transaction::OrderCancelTransaction stopLossOrderCancelTransaction;

		/**
		 * The Transaction created that creates a new Stop Loss Order for the Trade.
		 */
		oanda::v20::transaction::StopLossOrderTransaction stopLossOrderTransaction;

		/**
		 * The Transaction created that immediately fills the Trade’s new Stop
		 * Order. Only provided if the new Stop Loss Order was immediately filled.
		 */
		oanda::v20::transaction::OrderFillTransaction stopLossOrderFillTransaction;

		/**
		 * The Transaction created that immediately cancels the Trade’s new Stop
		 * Loss Order. Only provided if the new Stop Loss Order was immediately
		 * cancelled.
		 */
		oanda::v20::transaction::OrderCancelTransaction stopLossOrderCreatedCancelTransaction;

		/**
		 * The Transaction created that cancels the Trade’s existing Trailing Stop
		 * Loss Order.
		 */
		oanda::v20::transaction::OrderCancelTransaction trailingStopLossOrderCancelTransaction;

		/**
		 * The Transaction created that creates a new Trailing Stop Loss Order for
		 * the Trade.
		 */
		oanda::v20::transaction::TrailingStopLossOrderTransaction trailingStopLossOrderTransaction;

		/**
		 * The Transaction created that cancels the Trade’s existing Guaranteed Stop
		 * Loss Order.
		 */
		oanda::v20::transaction::OrderCancelTransaction guaranteedStopLossOrderCancelTransaction;

		/**
		 * The Transaction created that creates a new Guaranteed Stop Loss Order for
		 * the Trade.
		 */
		oanda::v20::transaction::GuaranteedStopLossOrderTransaction guaranteedStopLossOrderTransaction;

		/**
		 * The IDs of all Transactions that were created while satisfying the
		 * request.
		 */
		std::vector<oanda::v20::transaction::TransactionID> relatedTransactionIDs;

		/**
		 * The ID of the most recent Transaction created for the Account
		 */
		oanda::v20::transaction::TransactionID lastTransactionID;
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace orders */

} /* namespace trade */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_TRADE_HPP */
