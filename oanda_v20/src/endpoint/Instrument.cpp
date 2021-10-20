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
 * @file   Account.cpp
 * @author Scott Brauer
 * @date   01-14-2021
 */

#include "oanda/v20/common/Utility.hpp"
#include "oanda/v20/json/JsonConversion.hpp"
using namespace oanda::v20::json;

#include "oanda/v20/endpoint/Instrument.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace instrument {

namespace candles {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"instrument", p.instrument},
			{"granularity", p.granularity},
			{"candles", p.candles}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "instrument", p.instrument);
			convertJson(j, "granularity", p.granularity);
			convertJson(j, "candles", p.candles);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace candles */

namespace orderbook {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"orderBook", p.orderBook}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "orderBook", p.orderBook);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "Content-Encoding", p.contentEncoding);
		oanda::v20::common::convertHttpHeader(h, "Link", p.link);
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace orderbook */

namespace positionbook {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"positionBook", p.positionBook}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "positionBook", p.positionBook);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "Content-Encoding", p.contentEncoding);
		oanda::v20::common::convertHttpHeader(h, "Link", p.link);
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace positionbook */

} /* namespace instrument */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */
