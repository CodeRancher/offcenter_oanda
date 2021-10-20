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
 * @file   Tag.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_PRIMATIVES_TAG_HPP
#define OANDA_V20_PRIMATIVES_TAG_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"

namespace oanda {
namespace v20 {
namespace primitives {

/**
 * A tag associated with an entity.
 * Tag is an application/json object with the following Schema:
 */
struct Tag {

	/**
	 *  The type of the tag.
	 */
	oanda::v20::common::String type;

	/**
	 *  The name of the tag.
	 */
	oanda::v20::common::String name;
};

} /* namespace primitives */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_PRIMATIVES_TAG_HPP */
