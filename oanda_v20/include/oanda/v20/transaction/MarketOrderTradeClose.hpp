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
 * @file   MarketOrderTradeClose.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_MARKETORDERTRADECLOSE_HPP
#define OANDA_V20_TRANSACTION_MARKETORDERTRADECLOSE_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"
#include "oanda/v20/trade/TradeDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * A MarketOrderTradeClose specifies the extensions to a Market Order that has been created specifically to close a Trade.
 * MarketOrderTradeClose is an application/json object with the following Schema:
 */
struct MarketOrderTradeClose {

	/**
	 *  The ID of the Trade requested to be closed
	 */
	oanda::v20::trade::TradeID tradeID;

	/**
	 *  The client ID of the Trade requested to be closed
	 */
	oanda::v20::common::String clientTradeID;

	/**
	 *  Indication of how much of the Trade to close. Either “ALL”, or a
	 *  DecimalNumber reflection a partial close of the Trade.
	 */
	oanda::v20::common::String units;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_MARKETORDERTRADECLOSE_HPP */
