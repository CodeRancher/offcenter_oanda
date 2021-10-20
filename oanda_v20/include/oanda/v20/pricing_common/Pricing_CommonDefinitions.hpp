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
 * @file   Pricing_CommonDefinitions.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRICING_COMMON_PRICING_COMMONDEFINITIONS_HPP
#define OANDA_V20_PRICING_COMMON_PRICING_COMMONDEFINITIONS_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"

namespace oanda {
namespace v20 {
namespace pricing_common {

/**
 * The string representation of a Price for a Bucket.
 * A decimal number encodes as a string. The amount of precision provided depends on the Instrument.
 */
using PriceValue = oanda::v20::common::String;

} /* namespace pricing_common */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRICING_COMMON_PRICING_COMMONDEFINITIONS_HPP */
