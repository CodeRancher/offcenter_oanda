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
 * @file   Instrument.hpp
 * @author Scott Brauer
 * @date   01-20-2021
 */

#ifndef OANDA_V20_ENDPOINT_INSTRUMENT_HPP
#define OANDA_V20_ENDPOINT_INSTRUMENT_HPP

#include <nlohmann/json.hpp>
#include <cpprest/http_headers.h>

#include "oanda/v20/json/JsonToFrom.hpp"

#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"
#include "oanda/v20/endpoint/OandaEndpointResponses.hpp"
using namespace oanda::v20;

namespace oanda {
namespace v20 {
namespace endpoint {
namespace instrument {

namespace candles {

	/**
	 *
	 */
	class Parameters: public endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
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
			weeklyAlignment("weeklyAlignment", endpoint::ParameterType::QUERY, *this)
		{}

		/// Format of DateTime fields in the request and response.
		AcceptDatetimeFormatParameter acceptDateTimeFormat;

		/// Name of the Instrument
		/// [required]
		StringParameter instrument;

		/// The Price component(s) to get candlestick data for.
		/// [default=M]
		PricingComponentParameter price;

		/// The granularity of the candlesticks to fetch
		/// [default=S5]
		CandlestickGranularityParameter granularity;

		/// The number of candlesticks to return in the response.
		/// Count should not be specified if both the start and end parameters are provided, as the time range combined
		/// with the granularity will determine the number of candlesticks to return.
		/// [default=500, maximum=5000]
		IntegerParameter<1, 500, 5000> count;

		/// The start of the time range to fetch candlesticks for.
		DateTimeParameter from;

		/// The end of the time range to fetch candlesticks for.
		DateTimeParameter to;

		/// A flag that controls whether the candlestick is “smoothed” or not.
		/// A smoothed candlestick uses the previous candle’s close price as its open price, while an un-smoothed
		/// candlestick uses the first price from its time range as its open price.
		/// [default=False]
		BooleanParameter<false> smooth;

		/// A flag that controls whether the candlestick that is covered by the from time should be included in the results.
		/// This flag enables clients to use the timestamp of the last completed candlestick received to poll for future
		/// candlesticks but avoid receiving the previous candlestick repeatedly.
		/// [default=True]
		BooleanParameter<true> includeFirst;

		/// The hour of the day (in the specified timezone) to use for granularities that have daily alignments.
		/// [default=17, minimum=0, maximum=23]
		IntegerParameter<0, 17, 23> dailyAlignment;

		/// The timezone to use for the dailyAlignment parameter.
		/// Candlesticks with daily alignment will be aligned to the dailyAlignment hour within the alignmentTimezone.
		/// Note that the returned times will still be represented in UTC.
		/// [default=America/New_York]
		StringParameter alignmentTimezone;

		///	The day of the week used for granularities that have weekly alignment.
		/// [default=Friday]
		StringParameter weeklyAlignment;

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

		/**
		 * @brief The instrument whose Prices are represented by the candlesticks.
		 */
		primitives::InstrumentName instrument;

		/**
		 * @brief The granularity of the candlesticks provided.
		 */
		oanda::v20::instrument::CandlestickGranularity granularity;

		/**
		 * @brief The list of candlesticks that satisfy the request.
		 */
		std::vector<oanda::v20::instrument::Candlestick> candles;
	};

	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace candles */

namespace orderbook {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			instrument("instrument", endpoint::ParameterType::PATH, *this),
			time("time", endpoint::ParameterType::QUERY, *this) {}

		AcceptDatetimeFormatParameter acceptDateTimeFormat; ///< Format of DateTime fields in the request and response.
		Parameter instrument; ///< Name of the Instrument [required]
		Parameter time; ///< The time of the snapshot to fetch.
						///< If not specified, then the most recent snapshot is fetched.

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
		std::string contentEncoding; ///< Value will be “gzip” regardless of provided Accept-Encoding header
		std::string link; ///< A link to the next/previous order book snapshot.
		std::string requestID; ///< The unique identifier generated for the request

		oanda::v20::instrument::OrderBook orderBook; ///< The instrument’s order book
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace orderbook */

namespace positionbook {

	/**
	 *
	 */
	class Parameters: public oanda::v20::endpoint::OandaEndpointParameters
	{
	public:
		explicit Parameters(): OandaEndpointParameters(),
			acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
			instrument("instrument", endpoint::ParameterType::PATH, *this),
			time("time", endpoint::ParameterType::QUERY, *this) {}

		AcceptDatetimeFormatParameter acceptDateTimeFormat; ///< Format of DateTime fields in the request and response.
		Parameter instrument; ///< Name of the Instrument [required]
		Parameter time; ///< The time of the snapshot to fetch. If not specified, then the most recent snapshot is fetched.
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
		std::string contentEncoding; ///< Value will be “gzip” regardless of provided Accept-Encoding header
		std::string link; ///< A link to the next/previous order book snapshot.
		std::string requestID; ///< The unique identifier generated for the request

		oanda::v20::instrument::PositionBook positionBook; ///< The instrument’s position book
	};

	// Json
	void to_json(nlohmann::json& j, const Request& p);
	void from_json(const nlohmann::json& j, Request& p);
	void to_json(nlohmann::json& j, const Response& p);
	void from_json(const nlohmann::json& j, Response& p);
	void parseHeader(const web::http::http_headers& h, Response& p);

} /* namespace positionbook */

} /* namespace instrument */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_INSTRUMENT_HPP */
