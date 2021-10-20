/**
 * Copyright 2020 Scott Brauer
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an  BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file   AccountProperties.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ACCOUNT_ACCOUNTPROPERTIES_HPP
#define OANDA_V20_ACCOUNT_ACCOUNTPROPERTIES_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"
#include "oanda/v20/account/AccountDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace account {

/**
 * @brief Properties related to an Account.
 *
 * AccountProperties is an application/json object with the following Schema:
 */
struct AccountProperties {

	/**
	 * @brief The Account’s identifier
	 */
	oanda::v20::account::AccountID id;

	/**
	 * @brief The Account’s associated MT4 Account ID. This field will not be present
	 *		  if the Account is not an MT4 account.
	 */
	int mt4AccountID;

	/**
	 * @brief The Account’s tags
	 */
	std::vector<oanda::v20::common::String> tags;
};

} /* namespace account */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ACCOUNT_ACCOUNTPROPERTIES_HPP */
