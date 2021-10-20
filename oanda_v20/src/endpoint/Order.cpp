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

#include "oanda/v20/endpoint/Order.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace order {

namespace order {

	// Request
	template<typename OrderRequest>
	void to_json(nlohmann::json& j, const Request<OrderRequest>& p) {
		j = nlohmann::json {
			{"order", p.order}
		};
	}

	template<typename OrderRequest>
	void from_json(const nlohmann::json& j, Request<OrderRequest>& p) {
		try {
			convertJson(j, "order", p.order);
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
			{"orderReissueTransaction", p.orderReissueTransaction},
			{"orderReissueRejectTransaction", p.orderReissueRejectTransaction},
			{"relatedTransactionIDs", p.relatedTransactionIDs},
			{"lastTransactionID", p.lastTransactionID}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "orderCreateTransaction", p.orderCreateTransaction);
			convertJson(j, "orderFillTransaction", p.orderFillTransaction);
			convertJson(j, "orderCancelTransaction", p.orderCancelTransaction);
			convertJson(j, "orderReissueTransaction", p.orderReissueTransaction);
			convertJson(j, "orderReissueRejectTransaction", p.orderReissueRejectTransaction);
			convertJson(j, "relatedTransactionIDs", p.relatedTransactionIDs);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
		oanda::v20::common::convertHttpHeader(h, "Location", p.location);
	}

} /* namespace accounts */

namespace marketorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { order::from_json(j, p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { order::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { order::parseHeader(h, p); }

} /* namespace marketorder */

namespace limitorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { order::from_json(j, p); }
	//bool isDirty(const Request& p) { return order::isDirty(p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { order::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { order::parseHeader(h, p); }

} /* namespace limitorder */

namespace stoporder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { order::from_json(j, p); }
	//bool isDirty(const Request& p) { return order::isDirty(p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { order::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { order::parseHeader(h, p); }

} /* namespace stoporder */

namespace marketiftouchedorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { order::from_json(j, p); }
	//bool isDirty(const Request& p) { return order::isDirty(p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { order::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { order::parseHeader(h, p); }

} /* namespace marketiftouchedorder */

namespace takeprofitorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { order::from_json(j, p); }
	//bool isDirty(const Request& p) { return order::isDirty(p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { order::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { order::parseHeader(h, p); }

} /* namespace takeprofitorder */

namespace stoplossorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { order::from_json(j, p); }
	//bool isDirty(const Request& p) { return order::isDirty(p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { order::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { order::parseHeader(h, p); }

} /* namespace stoplossorder */

namespace guaranteedstoplossorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { order::from_json(j, p); }
	//bool isDirty(const Request& p) { return order::isDirty(p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { order::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { order::parseHeader(h, p); }

} /* namespace guaranteedstoplossorder */

namespace trailingstoplossorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { order::from_json(j, p); }
	//bool isDirty(const Request& p) { return order::isDirty(p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { order::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { order::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { order::parseHeader(h, p); }

} /* namespace trailingstoplossorder */

namespace orders {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"orders", p.orders},
			{"lastTransactionID", p.lastTransactionID},
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "orders", p.orders);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
		oanda::v20::common::convertHttpHeader(h, "link", p.link);
	}

} /* namespace orders */

namespace pendingorders {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"orders", p.orders},
			{"lastTransactionID", p.lastTransactionID},
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "orders", p.orders);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace pendingorders */

namespace orderdetails {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"order", p.order},
			{"lastTransactionID", p.lastTransactionID},
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "order", p.order);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
		oanda::v20::common::convertHttpHeader(h, "link", p.link);
	}

} /* namespace orderdetails */

namespace cancelorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"orderCancelTransaction", p.orderCancelTransaction},
			{"relatedTransactionIDs", p.relatedTransactionIDs},
			{"lastTransactionID", p.lastTransactionID},
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
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

} /* namespace cancelorder */

namespace replaceorder {

	// Request
	template<typename OrderRequest>
	void to_json(nlohmann::json& j, const Request<OrderRequest>& p) {
		j = nlohmann::json {
			{"order", p.order}
		};
	}

	template<typename OrderRequest>
	void from_json(const nlohmann::json& j, Request<OrderRequest>& p) {
		try {
			convertJson(j, "order", p.order);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"orderCancelTransaction", p.orderCancelTransaction},
			{"orderCreateTransaction", p.orderCreateTransaction},
			{"OrderFillTransaction", p.orderFillTransaction},
			{"orderReissueTransaction", p.orderReissueTransaction},
			{"orderReissueRejectTransaction", p.orderReissueRejectTransaction},
			{"replacingOrderCancelTransaction", p.replacingOrderCancelTransaction},
			{"relatedTransactionIDs", p.relatedTransactionIDs},
			{"lastTransactionID", p.lastTransactionID},
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "orderCancelTransaction", p.orderCancelTransaction);
			convertJson(j, "orderCreateTransaction", p.orderCreateTransaction);
			convertJson(j, "orderFillTransaction", p.orderFillTransaction);
			convertJson(j, "orderReissueTransaction", p.orderReissueTransaction);
			convertJson(j, "orderReissueRejectTransaction", p.orderReissueRejectTransaction);
			convertJson(j, "replacingOrderCancelTransaction", p.replacingOrderCancelTransaction);
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

} /* namespace replaceorder */

namespace replacemarketorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { replaceorder::from_json(j, p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { replaceorder::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { replaceorder::parseHeader(h, p); }

} /* namespace replacemarketorder */

namespace replacelimitorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { replaceorder::from_json(j, p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { replaceorder::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { replaceorder::parseHeader(h, p); }

} /* namespace replacelimitorder */

namespace replacestoporder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { replaceorder::from_json(j, p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { replaceorder::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { replaceorder::parseHeader(h, p); }

} /* namespace replacestoporder */

namespace replacemarketiftouchedorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { replaceorder::from_json(j, p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { replaceorder::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { replaceorder::parseHeader(h, p); }

} /* namespace replacemarketiftouchedorder */

namespace replacetakeprofitorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { replaceorder::from_json(j, p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { replaceorder::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { replaceorder::parseHeader(h, p); }

} /* namespace replacetakeprofitorder */

namespace replacestoplossorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { replaceorder::from_json(j, p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { replaceorder::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { replaceorder::parseHeader(h, p); }

} /* namespace replacestoplossorder */

namespace replaceguaranteedstoplossorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { replaceorder::from_json(j, p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { replaceorder::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { replaceorder::parseHeader(h, p); }

} /* namespace replaceguaranteedstoplossorder */

namespace replacetrailingstoplossorder {

	// Request
	void to_json(nlohmann::json& j, const Request& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Request& p) { replaceorder::from_json(j, p); }

	// Response
	void to_json(nlohmann::json& j, const Response& p) { replaceorder::to_json(j, p); }
	void from_json(const nlohmann::json& j, Response& p) { replaceorder::from_json(j, p); }

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) { replaceorder::parseHeader(h, p); }

} /* namespace replacetrailingstoplossorder */

namespace clientextensions {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {
			{"clientExtensions", p.clientExtensions},
			{"tradeClientExtensions", p.tradeClientExtensions},
		};
	}

	void from_json(const nlohmann::json& j, Request& p) {
		try {
			convertJson(j, "clientExtensions", p.clientExtensions);
			convertJson(j, "tradeClientExtensions", p.tradeClientExtensions);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"orderClientExtensionsModifyTransaction", p.orderClientExtensionsModifyTransaction},
			{"lastTransactionID", p.lastTransactionID},
			{"relatedTransactionIDs", p.relatedTransactionIDs},
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "orderClientExtensionsModifyTransaction", p.orderClientExtensionsModifyTransaction);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
			convertJson(j, "relatedTransactionIDs", p.relatedTransactionIDs);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace clientextensions */

} /* namespace order */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */
