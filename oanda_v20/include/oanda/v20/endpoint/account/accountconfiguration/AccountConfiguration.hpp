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
 * @file   AccountConfiguration.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ENDPOINT_ACCOUNT_ACCOUNTCONFIGURATION_ACCOUNTCONFIGURATION_HPP
#define OANDA_V20_ENDPOINT_ACCOUNT_ACCOUNTCONFIGURATION_ACCOUNTCONFIGURATION_HPP

#include "oanda/v20/transaction/ClientConfigureTransaction.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"
#include "oanda/v20/endpoint/OandaEndpointResponses.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace account {
namespace accountconfiguration {

/**
 *
 */
struct Request: public oanda::v20::endpoint::OandaEndpointParameters
{
	explicit Request():
		OandaEndpointParameters(),
		accountID("accountID", endpoint::ParameterType::PATH, *this),
		acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this) {}
	virtual ~Request() = default;

	Parameter accountID;
	AcceptDatetimeFormatParameter acceptDateTimeFormat;

	/**
	 * Client-defined alias (name) for the Account
	 */
    std::string alias;

    /**
     * The string representation of a decimal number.
     */
    oanda::v20::primitives::DecimalNumber marginRate;
};

/**
 *
 */
struct Response: public oanda::v20::endpoint::OandaEndpointResponses
{
	explicit Response():
		OandaEndpointResponses() {}

	/**
	 * The transaction that configures the Account.
	 */
	oanda::v20::transaction::ClientConfigureTransaction clientConfigureTransaction;

    /**
     * The ID of the last Transaction created for the Account.
     */
    oanda::v20::transaction::TransactionID lastTransactionID;
};

} /* namespace accountconfiguration */
} /* namespace account */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_ACCOUNT_ACCOUNTCONFIGURATION_ACCOUNTCONFIGURATION_HPP */
