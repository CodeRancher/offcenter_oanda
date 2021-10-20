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
 * @file   AccountInstruments.hpp
 * @author Scott Brauer
 * @date   12-14-2020  
 */

#ifndef OANDA_V20_ENDPOINT_ACCOUNT_ACCOUNTINSTRUMENTSRESPONSE_HPP
#define OANDA_V20_ENDPOINT_ACCOUNT_ACCOUNTINSTRUMENTSRESPONSE_HPP

#include <vector>

#include "oanda/v20/primitives/Instrument.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"
#include "oanda/v20/endpoint/OandaEndpointResponses.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace account {
namespace accountinstruments {

/**
 *
 */
class Request: public oanda::v20::endpoint::OandaEndpointParameters
{
public:
	explicit Request():
		OandaEndpointParameters(),
		accountID("accountID", endpoint::ParameterType::PATH, *this),
		instruments("instruments", endpoint::ParameterType::QUERY, *this) {}
	virtual ~Request() = default;

	Parameter accountID;
	Parameter instruments;
};

struct Response: public oanda::v20::endpoint::OandaEndpointResponses
{
	explicit Response():
		OandaEndpointResponses() {}

	/**
	 * The requested list of instruments.
	 */
    std::vector<oanda::v20::primitives::Instrument> instruments;

    /**
     * The ID of the most recent Transaction created for the Account.
     */
    oanda::v20::transaction::TransactionID lastTransactionID;
};

} /* namespace accountinstruments */
} /* namespace account */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_ACCOUNT_ACCOUNTINSTRUMENTSRESPONSE_HPP */
