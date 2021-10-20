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
 * @file   Order.cpp
 * @author Scott Brauer
 * @date   01-21-2021
 */

#include "oanda/v20/common/Utility.hpp"
#include "oanda/v20/json/JsonConversion.hpp"
using namespace oanda::v20::json;

#include "oanda/v20/endpoint/Trade.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace trade {

namespace trades {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"trades", p.trades},
			{"lastTransactionID", p.lastTransactionID}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "trades", p.trades);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
		oanda::v20::common::convertHttpHeader(h, "Link", p.link);
	}

} /* namespace trades */

namespace opentrades {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"trades", p.trades},
			{"lastTransactionID", p.lastTransactionID}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "trades", p.trades);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace opentrades */

namespace trade {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"trade", p.trade},
			{"lastTransactionID", p.lastTransactionID}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "trade", p.trade);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace trade */

namespace close {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {
			{"units", p.units}
		};
	}

	void from_json(const nlohmann::json& j, Request& p) {
		try {
			convertJson(j, "units", p.units);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"orderCreateTransaction", p.orderCreateTransaction},
			{"orderFillTransaction", p.orderFillTransaction},
			{"orderCancelTransaction", p.orderCancelTransaction},
			{"relatedTransactionIDs", p.relatedTransactionIDs},
			{"lastTransactionID", p.lastTransactionID}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "orderCreateTransaction", p.orderCreateTransaction);
			convertJson(j, "orderFillTransaction", p.orderFillTransaction);
			convertJson(j, "orderCancelTransaction", p.orderCancelTransaction);
			convertJson(j, "relatedTransactionIDs", p.relatedTransactionIDs);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace close */

namespace clientextensions {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {
			{"clientExtensions", p.clientExtensions}
		};
	}

	void from_json(const nlohmann::json& j, Request& p) {
		try {
			convertJson(j, "clientExtensions", p.clientExtensions);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"tradeClientExtensionsModifyTransaction", p.tradeClientExtensionsModifyTransaction},
			{"relatedTransactionIDs", p.relatedTransactionIDs},
			{"lastTransactionID", p.lastTransactionID}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "tradeClientExtensionsModifyTransaction", p.tradeClientExtensionsModifyTransaction);
			convertJson(j, "relatedTransactionIDs", p.relatedTransactionIDs);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace clientextensions */

namespace orders {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {
			{"takeProfit", p.takeProfit},
			{"stopLoss", p.stopLoss},
			{"trailingStopLoss", p.trailingStopLoss},
			{"guaranteedStopLoss", p.guaranteedStopLoss}
		};
	}

	void from_json(const nlohmann::json& j, Request& p) {
		try {
			convertJson(j, "takeProfit", p.takeProfit);
			convertJson(j, "stopLoss", p.stopLoss);
			convertJson(j, "trailingStopLoss", p.trailingStopLoss);
			convertJson(j, "guaranteedStopLoss", p.guaranteedStopLoss);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"takeProfitOrderCancelTransaction", p.takeProfitOrderCancelTransaction},
			{"takeProfitOrderTransaction", p.takeProfitOrderTransaction},
			{"takeProfitOrderFillTransaction", p.takeProfitOrderFillTransaction},
			{"takeProfitOrderCreatedCancelTransaction", p.takeProfitOrderCreatedCancelTransaction},
			{"stopLossOrderCancelTransaction", p.stopLossOrderCancelTransaction},
			{"stopLossOrderTransaction", p.stopLossOrderTransaction},
			{"stopLossOrderFillTransaction", p.stopLossOrderFillTransaction},
			{"stopLossOrderCreatedCancelTransaction", p.stopLossOrderCreatedCancelTransaction},
			{"trailingStopLossOrderCancelTransaction", p.trailingStopLossOrderCancelTransaction},
			{"trailingStopLossOrderTransaction", p.trailingStopLossOrderTransaction},
			{"guaranteedStopLossOrderCancelTransaction", p.guaranteedStopLossOrderCancelTransaction},
			{"guaranteedStopLossOrderTransaction", p.guaranteedStopLossOrderTransaction},
			{"relatedTransactionIDs", p.relatedTransactionIDs},
			{"lastTransactionID", p.lastTransactionID}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "takeProfitOrderCancelTransaction", p.takeProfitOrderCancelTransaction);
			convertJson(j, "takeProfitOrderTransaction", p.takeProfitOrderTransaction);
			convertJson(j, "takeProfitOrderFillTransaction", p.takeProfitOrderFillTransaction);
			convertJson(j, "takeProfitOrderCreatedCancelTransaction", p.takeProfitOrderCreatedCancelTransaction);
			convertJson(j, "stopLossOrderCancelTransaction", p.stopLossOrderCancelTransaction);
			convertJson(j, "stopLossOrderTransaction", p.stopLossOrderTransaction);
			convertJson(j, "stopLossOrderFillTransaction", p.stopLossOrderFillTransaction);
			convertJson(j, "stopLossOrderCreatedCancelTransaction", p.stopLossOrderCreatedCancelTransaction);
			convertJson(j, "trailingStopLossOrderCancelTransaction", p.trailingStopLossOrderCancelTransaction);
			convertJson(j, "trailingStopLossOrderTransaction", p.trailingStopLossOrderTransaction);
			convertJson(j, "guaranteedStopLossOrderCancelTransaction", p.guaranteedStopLossOrderCancelTransaction);
			convertJson(j, "guaranteedStopLossOrderTransaction", p.guaranteedStopLossOrderTransaction);
			convertJson(j, "relatedTransactionIDs", p.relatedTransactionIDs);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace orders */


} /* namespace trade */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */
