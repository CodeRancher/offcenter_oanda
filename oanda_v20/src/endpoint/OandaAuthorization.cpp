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
 * @file   OandaAuthorization.cpp
 * @author Scott Brauer
 * @date   12-09-2020
 */

#include "oanda/v20/endpoint/OandaAuthorization.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {

OandaAuthorization::OandaAuthorization(const std::string bearerToken):
		m_bearerToken(bearerToken)
{
	// TODO Auto-generated constructor stub

}

OandaAuthorization::~OandaAuthorization() {
	// TODO Auto-generated destructor stub
}

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */
