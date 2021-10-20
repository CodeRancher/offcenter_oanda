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
 * @file   Position.cpp
 * @author Scott Brauer
 * @date   02-07-2021
 */

#include "oanda/v20/common/Utility.hpp"
#include "oanda/v20/json/JsonConversion.hpp"
using namespace oanda::v20::json;

#include "oanda/v20/endpoint/Position.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace position {

namespace positions {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"positions", p.positions},
			{"lastTransactionID", p.lastTransactionID}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "positions", p.positions);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace positions */

namespace openpositions {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"positions", p.positions},
			{"lastTransactionID", p.lastTransactionID}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "positions", p.positions);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace openpositions */

namespace position {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"position", p.position},
			{"lastTransactionID", p.lastTransactionID}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "position", p.position);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace position */

namespace close {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {
			{"longUnits", p.longUnits},
			{"longClientExtensions", p.longClientExtensions},
			{"shortUnits", p.shortUnits},
			{"shortClientExtensions", p.shortClientExtensions}
		};
	}

	void from_json(const nlohmann::json& j, Request& p) {
		try {
			convertJson(j, "longUnits", p.longUnits);
			convertJson(j, "longClientExtensions", p.longClientExtensions);
			convertJson(j, "shortUnits", p.shortUnits);
			convertJson(j, "shortClientExtensions", p.shortClientExtensions);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"longOrderCreateTransaction", p.longOrderCreateTransaction},
			{"longOrderFillTransaction", p.longOrderFillTransaction},
			{"longOrderCancelTransaction", p.longOrderCancelTransaction},
			{"shortOrderCreateTransaction", p.shortOrderCreateTransaction},
			{"shortOrderFillTransaction", p.shortOrderFillTransaction},
			{"shortOrderCancelTransaction", p.shortOrderCancelTransaction},
			{"relatedTransactionIDs", p.relatedTransactionIDs},
			{"lastTransactionID", p.lastTransactionID}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "longOrderCreateTransaction", p.longOrderCreateTransaction);
			convertJson(j, "longOrderFillTransaction", p.longOrderFillTransaction);
			convertJson(j, "longOrderCancelTransaction", p.longOrderCancelTransaction);
			convertJson(j, "shortOrderCreateTransaction", p.shortOrderCreateTransaction);
			convertJson(j, "shortOrderFillTransaction", p.shortOrderFillTransaction);
			convertJson(j, "shortOrderCancelTransaction", p.shortOrderCancelTransaction);
			convertJson(j, "relatedTransactionIDs", p.relatedTransactionIDs);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "Location", p.location);
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace close */

} /* namespace position */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */
