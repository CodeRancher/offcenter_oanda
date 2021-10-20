/**
 * Copyright 2020 Scott Brauer
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
	 * @brief    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an  BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file   UserAttributes.hpp
 * @author Scott Brauer
 * @date   12-07-2020
 */

#ifndef OANDA_V20_ACCOUNT_USERATTRIBUTES_HPP
#define OANDA_V20_ACCOUNT_USERATTRIBUTES_HPP

#include "oanda/v20/common/String.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace account {

/**
 * Contains the attributes of a user.
 * UserAttributes is an application/json object with the following Schema:
 */
struct UserAttributes {
	UserAttributes():
		userID(0)
	{}

	/**
	 * @brief The user’s OANDA-assigned user ID.
	 */
	int userID;

	/**
	 * @brief The user-provided username.
	 */
	oanda::v20::common::String username;

	/**
	 * @brief The user’s title.
	 */
	oanda::v20::common::String title;

	/**
	 * @brief The user’s name.
	 */
	oanda::v20::common::String name;

	/**
	 * @brief The user’s email address.
	 */
	oanda::v20::common::String email;

	/**
	 * @brief The OANDA division the user belongs to.
	 */
	oanda::v20::common::String divisionAbbreviation;

	/**
	 * @brief The user’s preferred language.
	 */
	oanda::v20::common::String languageAbbreviation;

	/**
	 * @brief The home currency of the Account.
	 */
	oanda::v20::primitives::Currency homeCurrency;
};

} /* namespace account */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ACCOUNT_USERATTRIBUTES_HPP */
