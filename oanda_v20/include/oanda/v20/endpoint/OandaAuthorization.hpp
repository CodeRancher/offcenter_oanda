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
 * @file   OandaAuthorization.hpp
 * @author Scott Brauer
 * @date   12-09-2020
 */

#ifndef OANDA_V20_ENDPOINT_OANDAAUTHORIZATION_HPP_
#define OANDA_V20_ENDPOINT_OANDAAUTHORIZATION_HPP_

#include <string>

namespace oanda {
namespace v20 {
namespace endpoint {

/**
 * Required authorization for an Oanda server.
 */
class OandaAuthorization {
public:
	/**
	 * Create required authorization for an Oanda server.
	 *
	 * @param bearerToken Authorization Bearer token.
	 */
	explicit OandaAuthorization(const std::string bearerToken);
	virtual ~OandaAuthorization();

	/**
	 * Bearer token.
	 *
	 * @return Bearer token.
	 */
	const std::string bearerToken() const { return m_bearerToken; }

private:
	std::string m_bearerToken;
};

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_OANDAAUTHORIZATION_HPP_ */
