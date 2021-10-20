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
 * @file   OandaEndpoints.cpp
 * @author Scott Brauer
 * @date   12-14-2020
 */

#include "oanda/v20/endpoint/OandaEndpoints.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {

OandaEndpoints::OandaEndpoints(const OandaServers& server, const OandaAuthorization& authorization):
	OandaClient(server, authorization),
	account(*this),
	instrument(*this),
	order(*this),
	trade(*this),
	position(*this),
	transaction(*this),
	pricing(*this)
{

}

OandaEndpoints::~OandaEndpoints()
{

}

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */
