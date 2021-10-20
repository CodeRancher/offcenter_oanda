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
 * @file   AccountChanges.hpp
 * @author Scott Brauer
 * @date   01-13-2021
 */

#ifndef OANDA_V20_ENDPOINT_ACCOUNT_ACCOUNTCHANGES_ACCOUNTCHANGES_HPP
#define OANDA_V20_ENDPOINT_ACCOUNT_ACCOUNTCHANGES_ACCOUNTCHANGES_HPP

#include "oanda/v20/account/AccountChanges.hpp"
#include "oanda/v20/account/AccountChangesState.hpp"
#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"
#include "oanda/v20/endpoint/OandaEndpointResponses.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {
namespace account {
namespace accountchanges {

/**
 *
 */
class Request: public oanda::v20::endpoint::OandaEndpointParameters
{
public:
	explicit Request():
		OandaEndpointParameters(),
		accountID("accountID", endpoint::ParameterType::PATH, *this),
		acceptDateTimeFormat("Accept-Datetime-Format", endpoint::ParameterType::HEADER, *this),
		sinceTransactionID("TransactionID", endpoint::ParameterType::QUERY, *this) {}
	virtual ~Request() = default;

	Parameter accountID;
	AcceptDatetimeFormatParameter acceptDateTimeFormat;
	Parameter sinceTransactionID;
};

/**
 *
 */
struct Response: public oanda::v20::endpoint::OandaEndpointResponses
{
	explicit Response():
		OandaEndpointResponses() {}

	/**
	 * The changes to the Account’s Orders, Trades and Positions since the
	 * specified Transaction ID. Only provided if the sinceTransactionID is
	 * supplied to the poll request.
	 */
	oanda::v20::account::AccountChanges changes;

	/**
	 * The Account’s current price-dependent state.
	 */
	oanda::v20::account::AccountChangesState  state;

	/**
	 * The ID of the last Transaction created for the Account.  This Transaction
	 * ID should be used for future poll requests, as the client has already
	 * observed all changes up to and including it.
	 */
	oanda::v20::transaction::TransactionID lastTransactionID;
};

} /* namespace accountchanges */
} /* namespace account */
} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_ACCOUNT_ACCOUNTCHANGES_ACCOUNTCHANGES_HPP */
