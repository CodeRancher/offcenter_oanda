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

#include "oanda/v20/endpoint/Account.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace account {

namespace accounts {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"accounts", p.accounts}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "accounts", p.accounts);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace accounts */

namespace account {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"account", p.account},
			{"lastTransactionID", p.lastTransactionID},
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "account", p.account);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace account */

namespace accountsummary {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"account", p.account},
			{"lastTransactionID", p.lastTransactionID},
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "account", p.account);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace accountsummary */

namespace accountinstruments {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"instruments", p.instruments},
			{"lastTransactionID", p.lastTransactionID},
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "instruments", p.instruments);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace accountinstruments */

namespace accountconfiguration {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {
			{"alias", p.alias},
			{"marginRate", p.marginRate},
		};
	}

	void from_json(const nlohmann::json& j, Request& p) {
		try {
			convertJson(j, "alias", p.alias);
			convertJson(j, "marginRate", p.marginRate);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"clientConfigureTransaction", p.clientConfigureTransaction},
			{"lastTransactionID", p.lastTransactionID},
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "clientConfigureTransaction", p.clientConfigureTransaction);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace accountconfiguration */

namespace accountchanges {

	// Request
	void to_json(nlohmann::json& j, const Request& p) {
		j = nlohmann::json {};
	}

	void from_json(const nlohmann::json& j, Request& p) {
	}

	// Response
	void to_json(nlohmann::json& j, const Response& p) {
		j = nlohmann::json {
			{"changes", p.changes},
			{"state", p.state},
			{"lastTransactionID", p.lastTransactionID}
		};
	}

	void from_json(const nlohmann::json& j, Response& p) {
		try {
			convertJson(j, "changes", p.changes);
			convertJson(j, "state", p.state);
			convertJson(j, "lastTransactionID", p.lastTransactionID);
		} catch(nlohmann::json::exception& e) {
			throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
		}
	}

	// Http Response
	void parseHeader(const web::http::http_headers& h, Response& p) {
		oanda::v20::common::convertHttpHeader(h, "RequestID", p.requestID);
	}

} /* namespace accountchanges */

} /* namespace account */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */
