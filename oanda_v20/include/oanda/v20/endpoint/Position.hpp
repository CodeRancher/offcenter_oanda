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
 * @file   Position.hpp
 * @author Scott Brauer
 * @date   02-06-2021
 */

#ifndef OANDA_V20_ENDPOINT_POSITION_HPP
#define OANDA_V20_ENDPOINT_POSITION_HPP

#include <nlohmann/json.hpp>
#include <cpprest/http_headers.h>

#include "oanda/v20/json/JsonToFrom.hpp"

#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"
#include "oanda/v20/endpoint/OandaEndpointResponses.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace position {

namespace positions {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			accountID("accountID", endpoint::ParameterType::PATH, *this)
		{}

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

		 std::vector<oanda::v20::position::Position> positions; ///< The list of Account Positions.
		 oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the most recent Transaction created for the Account
	};

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace positions */

namespace openpositions {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			accountID("accountID", endpoint::ParameterType::PATH, *this)
		{}

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
		std::string requestID; ///< The unique identifier generated for the request

		std::vector<oanda::v20::position::Position> positions; ///< The list of open Positions in the Account.
		oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the most recent Transaction created for the Account
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace openpositions */

namespace position {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			instrument("instrument", endpoint::ParameterType::PATH, *this) {}

		Parameter accountID; ///< Account Identifier [required]
		Parameter instrument; ///< Name of the Instrument [required]
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

		oanda::v20::position::Position position; ///< The requested Position.
		oanda::v20::transaction::TransactionID lastTransactionID; ///< The ID of the most recent Transaction created for the Account
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace position */

namespace close {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			instrument("instrument", endpoint::ParameterType::PATH, *this) {}

		AcceptDatetimeFormatParameter acceptDateTimeFormat; ///< Format of DateTime fields in the request and response.
		Parameter accountID; ///< Account Identifier [required]
		Parameter instrument; ///< Name of the Instrument [required]
	};

	/**
	 *
	 */
	struct Request
	{
		Request():
			longUnits("ALL"),
			shortUnits("ALL") {}

		/**
		 * Indication of how much of the long Position to closeout.
		 *
		 * Either the string “ALL”, the string “NONE”, or a DecimalNumber representing how many
		 * units of the long position to close using a PositionCloseout MarketOrder.
		 * The units specified must always be positive.
		 */
		oanda::v20::common::String longUnits;

		/**
		 * The client extensions to add to the MarketOrder used to close the long position.
		 */
		oanda::v20::transaction::ClientExtensions longClientExtensions;

		/**
		 * Indication of how much of the short Position to closeout.
		 * Either the string “ALL”, the string “NONE”, or a DecimalNumber representing how many
		 * units of the short position to close using a PositionCloseout
		 * MarketOrder. The units specified must always be positive.
		 */
		oanda::v20::common::String shortUnits;

		/**
		 * The client extensions to add to the MarketOrder used to close the short position.
		 */
		oanda::v20::transaction::ClientExtensions shortClientExtensions;
	};

	/**
	 *
	 */
	struct Response
	{
		std::string location; ///< A link to the Position that was just closed out
		std::string requestID; ///< The unique identifier generated for the request

		/// The MarketOrderTransaction created to close the long Position.
    	oanda::v20::transaction::MarketOrderTransaction longOrderCreateTransaction;

		/// OrderFill Transaction that closes the long Position
   		oanda::v20::transaction::OrderFillTransaction longOrderFillTransaction;

		/// OrderCancel Transaction that cancels the MarketOrder created to close the long Position
   		oanda::v20::transaction::OrderCancelTransaction longOrderCancelTransaction;

		/// The MarketOrderTransaction created to close the short Position.
   		oanda::v20::transaction::MarketOrderTransaction shortOrderCreateTransaction;

		/// OrderFill Transaction that closes the short Position
   		oanda::v20::transaction::OrderFillTransaction shortOrderFillTransaction;

		/// OrderCancel Transaction that cancels the MarketOrder created to close the short Position
   		oanda::v20::transaction::OrderCancelTransaction shortOrderCancelTransaction;

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

} /* namespace position */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_POSITION_HPP */
