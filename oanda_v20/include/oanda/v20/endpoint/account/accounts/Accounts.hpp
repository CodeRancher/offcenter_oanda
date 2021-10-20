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
 * @file   Accounts.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ENDPOINT_ACCOUNT_ACCOUNTS_ACCOUNTS_HPP
#define OANDA_V20_ENDPOINT_ACCOUNT_ACCOUNTS_ACCOUNTS_HPP

#include <vector>

#include "oanda/v20/account/AccountProperties.hpp"
#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"
#include "oanda/v20/endpoint/OandaEndpointResponses.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace account {
namespace accounts {

/**
 *
 */
class Request: public oanda::v20::endpoint::OandaEndpointParameters
{
public:
	explicit Request():
		OandaEndpointParameters() {}
	virtual ~Request() = default;
};

/**
 *
 */
struct Response: public oanda::v20::endpoint::OandaEndpointResponses
{
	explicit Response():
		OandaEndpointResponses() {}

	/**
	 * The list of Accounts the client is authorized to access and their
	 * associated properties.
	 */
    std::vector<oanda::v20::account::AccountProperties> accounts;
};

} /* namespace accounts */
} /* namespace account */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_ACCOUNT_ACCOUNTS_ACCOUNTS_HPP */
