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
 * @file   PricingHeartbeat.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRICING_PRICINGHEARTBEAT_HPP
#define OANDA_V20_PRICING_PRICINGHEARTBEAT_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace pricing {

/** A PricingHeartbeat object is injected into the Pricing stream to ensure that the HTTP connection remains active.
 *
 *  PricingHeartbeat is an application/json object with the following Schema:
 */
struct PricingHeartbeat {

	/// The string “HEARTBEAT”
	oanda::v20::common::String type;

	/// The date/time when the Heartbeat was created.
	oanda::v20::primitives::DateTime time;
};

} /* namespace pricing */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRICING_PRICINGHEARTBEAT_HPP */
