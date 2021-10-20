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
 * File: PositionBook.cpp
 * Author: Scott Brauer
 *
 * Mon 07 Dec 2020 07:45:08 PM MST
 */

#include "oanda/v20/json/JsonConversion.hpp"

#include "oanda/v20/json/JsonToFrom.hpp"
#include "oanda/v20/json/exception/OutOfRange.hpp"

namespace oanda {
namespace v20 {
namespace instrument {

void to_json(nlohmann::json& j, const PositionBook& p) {
	j = nlohmann::json {
		{"instrument", p.instrument},
		{"time", p.time},
		{"price", p.price},
		{"bucketWidth", p.bucketWidth},
		{"buckets", p.buckets}
	};
}

void from_json(const nlohmann::json& j, PositionBook& p) {
	try {
		oanda::v20::json::convertJson(j, "instrument", p.instrument);
		oanda::v20::json::convertJson(j, "time", p.time);
		oanda::v20::json::convertJson(j, "price", p.price);
		oanda::v20::json::convertJson(j, "bucketWidth", p.bucketWidth);
		oanda::v20::json::convertJson(j, "buckets", p.buckets);
	} catch(nlohmann::json::exception& e) {
		throw oanda::v20::json::exception::OutOfRange(e, __FILE__, __LINE__, __FUNCTION__);
	}
}

} /* namespace instrument */
} /* namespace v20 */
} /* namespace oanda */
