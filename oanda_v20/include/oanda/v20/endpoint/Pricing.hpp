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
 * @file   Pricing.hpp
 * @author Scott Brauer
 * @date   02-07-2021
 */

#ifndef OANDA_V20_ENDPOINT_PRICING_HPP
#define OANDA_V20_ENDPOINT_PRICING_HPP

#include <nlohmann/json.hpp>
#include <cpprest/http_headers.h>

#include "oanda/v20/json/JsonToFrom.hpp"

#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"
#include "oanda/v20/endpoint/OandaEndpointResponses.hpp"
#include "oanda/v20/pricing/ClientPrice.hpp"
#include "oanda/v20/pricing/PricingHeartbeat.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace pricing {

namespace latest {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			candleSpecifications("candleSpecifications", endpoint::ParameterType::QUERY, *this),
			units("units", endpoint::ParameterType::QUERY, *this),
			smooth("smooth", endpoint::ParameterType::QUERY, *this),
			dailyAlignment("dailyAlignment", endpoint::ParameterType::QUERY, *this),
			alignmentTimezone("alignmentTimezone", endpoint::ParameterType::QUERY, *this),
			weeklyAlignment("weeklyAlignment", endpoint::ParameterType::QUERY, *this)
		{}

		/// Format of DateTime fields in the request and response.
		AcceptDatetimeFormatParameter acceptDateTimeFormat;

		/// Account Identifier [required]
		Parameter accountID;

		/// List of candle specifications to get pricing for. [required]
		Parameter candleSpecifications;

		/// The number of units used to calculate the volume-weighted average bid and ask prices in the returned candles. [default=1]
		Parameter units;

		/** A flag that controls whether the candlestick is “smoothed” or not.
		 *	A smoothed candlestick uses the previous candle’s close price as its open price, while an unsmoothed candlestick uses the first price from its time range as its open price. [default=False]
		 */
		Parameter smooth;

		/// The hour of the day (in the specified timezone) to use for granularities that have daily alignments. [default=17, minimum=0, maximum=23]
		Parameter dailyAlignment;

		/** The timezone to use for the dailyAlignment parameter.
		 *  Candlesticks with daily alignment will be aligned to the dailyAlignment hour within the alignmentTimezone. Note that the returned times will still be represented in UTC. [default=America/New_York]
		 */
		Parameter alignmentTimezone;

		/// The day of the week used for granularities that have weekly alignment. [default=Friday]
		Parameter weeklyAlignment;

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

		/// The latest candle sticks.
		std::vector<oanda::v20::instrument::CandlestickResponse> latestCandles;
	};

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace latest */

namespace pricing {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			instruments("instruments", endpoint::ParameterType::QUERY, *this),
			since("since", endpoint::ParameterType::QUERY, *this),
			includeUnitsAvailable("includeUnitsAvailable", endpoint::ParameterType::QUERY, *this),
			includeHomeConversions("includeHomeConversions", endpoint::ParameterType::QUERY, *this) {}

		/// Format of DateTime fields in the request and response.
		AcceptDatetimeFormatParameter acceptDateTimeFormat;

		/// Account Identifier [required]
		Parameter accountID;

		/// List of Instruments to get pricing for. [required]
		Parameter instruments;

		/** Date/Time filter to apply to the response.
		 *  Only prices and home conversions (if requested) with a time later than this filter
		 *  (i.e. the price has changed after the since time) will be provided, and are filtered independently.
		 */
		Parameter since;

		/** Flag that enables the inclusion of the unitsAvailable field in the returned Price objects. [default=True]
		 *  @ deprecated Will be removed in a future API update.
		 */
		Parameter includeUnitsAvailable;

		/** Flag that enables the inclusion of the homeConversions field in the returned response.
		 *  An entry will be returned for each currency in the set of all base and quote currencies
		 *  present in the requested instruments list. [default=False]
		 */
		Parameter includeHomeConversions;

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

		/// The list of Price objects requested.
		std::vector<oanda::v20::pricing::ClientPrice> prices;

		/** The list of home currency conversion factors requested.
		 *  This field will only be present if includeHomeConversions was set to true in the request.
		 */
		std::vector<oanda::v20::pricing::HomeConversions> homeConversions;

		/// The DateTime value to use for the “since” parameter in the next poll request.
		oanda::v20::primitives::DateTime time;
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace pricing */

namespace pricingstream {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			instruments("instruments", endpoint::ParameterType::QUERY, *this),
			snapshot("snapshot", endpoint::ParameterType::QUERY, *this),
			includeHomeConversions("includeHomeConversions", endpoint::ParameterType::QUERY, *this) {}

		/// Format of DateTime fields in the request and response.
		AcceptDatetimeFormatParameter acceptDateTimeFormat;

		/// Account Identifier [required]
		Parameter accountID;

		/// List of Instruments to stream Prices for. [required]
		Parameter instruments;

		/// Flag that enables/disables the sending of a pricing snapshot when initially connecting to the stream. [default=True]
		Parameter snapshot;

		/** Flag that enables the inclusion of the homeConversions field in the returned response.
		 *  An entry will be returned for each currency in the set of all base and quote currencies present in the requested instruments list. [default=False]
		 */
		Parameter includeHomeConversions;
	};

	/**
	 *
	 */
	class Request {};

	/**
	 *
	 */
	using DataResponse = oanda::v20::pricing::ClientPrice;
//	struct DataResponse
//	{
		//std::string contentEncoding; ///< Value will be “gzip” regardless of provided Accept-Encoding header
		//std::string link; ///< A link to the next/previous order book snapshot.
		//std::string requestID; ///< The unique identifier generated for the request

		//oanda::v20::instrument::PositionBook positionBook; ///< The instrument’s position book
//	};

	/**
	 *
	 */
	using HeartbeatResponse = oanda::v20::pricing::PricingHeartbeat;
//	struct HeartbeatResponse
//	{
		//std::string contentEncoding; ///< Value will be “gzip” regardless of provided Accept-Encoding header
		//std::string link; ///< A link to the next/previous order book snapshot.
		//std::string requestID; ///< The unique identifier generated for the request

		//oanda::v20::instrument::PositionBook positionBook; ///< The instrument’s position book
//	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const DataResponse& p);
	void from_json(const nlohmann::json& j, DataResponse& p);
	void to_json(nlohmann::json& j, const HeartbeatResponse& p);
	void from_json(const nlohmann::json& j, HeartbeatResponse& p);


} /* namespace pricingstream */

namespace candles {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			accountID("accountID", endpoint::ParameterType::PATH, *this),
			instrument("instrument", endpoint::ParameterType::PATH, *this),
			price("price", endpoint::ParameterType::QUERY, *this),
			granularity("granularity", endpoint::ParameterType::QUERY, *this),
			count("count", endpoint::ParameterType::QUERY, *this),
			from("from", endpoint::ParameterType::QUERY, *this),
			to("to", endpoint::ParameterType::QUERY, *this),
			smooth("smooth", endpoint::ParameterType::QUERY, *this),
			includeFirst("includeFirst", endpoint::ParameterType::QUERY, *this),
			dailyAlignment("dailyAlignment", endpoint::ParameterType::QUERY, *this),
			alignmentTimezone("alignmentTimezone", endpoint::ParameterType::QUERY, *this),
			weeklyAlignment("weeklyAlignment", endpoint::ParameterType::QUERY, *this),
			units("units", endpoint::ParameterType::QUERY, *this) {}

		/// Format of DateTime fields in the request and response.
		AcceptDatetimeFormatParameter acceptDateTimeFormat;

		/// Account Identifier [required]
		Parameter accountID;

		/// Name of the Instrument [required]
		Parameter instrument;

		/// The Price component(s) to get candlestick data for. [default=M]
		Parameter price;

		/// The granularity of the candlesticks to fetch [default=S5]
		Parameter granularity;

		/** The number of candlesticks to return in the response.
		 *  Count should not be specified if both the start and end parameters are provided,
		 *  as the time range combined with the granularity will determine the number of
		 *  candlesticks to return. [default=500, maximum=5000]
		 */
		Parameter count;

		/// The start of the time range to fetch candlesticks for.
		Parameter from;

		/// The end of the time range to fetch candlesticks for.
		Parameter to;

		/** A flag that controls whether the candlestick is “smoothed” or not.
		 *  A smoothed candlestick uses the previous candle’s close price as its open price,
		 *  while an unsmoothed candlestick uses the first price from its time range as its
		 *  open price. [default=False]
		 */
		Parameter smooth;

		/** A flag that controls whether the candlestick that is covered by the from time should be included in the results.
		 *  This flag enables clients to use the timestamp of the last completed candlestick received to poll for future
		 *  candlesticks but avoid receiving the previous candlestick repeatedly. [default=True]
		 */
		Parameter includeFirst;

		/// The hour of the day (in the specified timezone) to use for granularities that have daily alignments. [default=17, minimum=0, maximum=23]
		Parameter dailyAlignment;

		/** The timezone to use for the dailyAlignment parameter.
		 *  Candlesticks with daily alignment will be aligned to the dailyAlignment
		 *  hour within the alignmentTimezone. Note that the returned times will still
		 *  be represented in UTC. [default=America/New_York]
		 */
		Parameter alignmentTimezone;

		/// The day of the week used for granularities that have weekly alignment. [default=Friday]
		Parameter weeklyAlignment;

		/// The number of units used to calculate the volume-weighted average bid and ask prices in the returned candles. [default=1]
		Parameter units;
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

		/// The instrument whose Prices are represented by the candlesticks.
		oanda::v20::primitives::InstrumentName instrument;

		/// The granularity of the candlesticks provided.
		oanda::v20::instrument::CandlestickGranularity granularity;

		/// The list of candlesticks that satisfy the request.
		std::vector<oanda::v20::instrument::Candlestick> candles;
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace candles */

} /* namespace pricing */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_PRICING_HPP */
