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
 * @file   CommonDefinitions.hpp
 * @author Scott Brauer
 * @date   01-21-2021
 */

#ifndef OANDA_V20_COMMON_COMMONDEFINITIONS_HPP
#define OANDA_V20_COMMON_COMMONDEFINITIONS_HPP

namespace oanda {
namespace v20 {
namespace common {

/**
 * @brief The type of the Order.
 */
enum class BoolType {
	Undefined = 0,
	True, ///< Boolean true
	False ///< Boolean false
};

} /* namespace common */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_COMMON_COMMONDEFINITIONS_HPP */
