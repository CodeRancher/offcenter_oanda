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
 * @file   OandaException.cpp
 * @author Scott Brauer
 * @date   12-21-2020
 */

#ifndef OANDA_V20_ENDPOINT_OANDAEXCEPTIONFACTORY_HPP_
#define OANDA_V20_ENDPOINT_OANDAEXCEPTIONFACTORY_HPP_

#include <cpprest/http_msg.h>

namespace oanda {
namespace v20 {
namespace endpoint {

extern void oandaExceptionFactory(const web::http::status_code statusCode, const utility::string_t& responseText);

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_OANDAEXCEPTIONFACTORY_HPP_ */
