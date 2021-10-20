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
 * @file   OrderCommon.hpp
 * @author Scott Brauer
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_ORDER_ORDERCOMMON_HPP
#define OANDA_V20_ORDER_ORDERCOMMON_HPP

#include "oanda/v20/order/Order.hpp"
#include "oanda/v20/order/MarketOrder.hpp"
#include "oanda/v20/order/FixedPriceOrder.hpp"
#include "oanda/v20/order/LimitOrder.hpp"
#include "oanda/v20/order/StopOrder.hpp"
#include "oanda/v20/order/MarketIfTouchedOrder.hpp"
#include "oanda/v20/order/TakeProfitOrder.hpp"
#include "oanda/v20/order/StopLossOrder.hpp"
#include "oanda/v20/order/GuaranteedStopLossOrder.hpp"
#include "oanda/v20/order/TrailingStopLossOrder.hpp"
#include "oanda/v20/order/MarketOrderRequest.hpp"
#include "oanda/v20/order/LimitOrderRequest.hpp"
#include "oanda/v20/order/StopOrderRequest.hpp"
#include "oanda/v20/order/MarketIfTouchedOrderRequest.hpp"
#include "oanda/v20/order/TakeProfitOrderRequest.hpp"
#include "oanda/v20/order/StopLossOrderRequest.hpp"
#include "oanda/v20/order/GuaranteedStopLossOrderRequest.hpp"
#include "oanda/v20/order/TrailingStopLossOrderRequest.hpp"
#include "oanda/v20/order/OrderIdentifier.hpp"
#include "oanda/v20/order/DynamicOrderState.hpp"
#include "oanda/v20/order/UnitsAvailableDetails.hpp"
#include "oanda/v20/order/UnitsAvailable.hpp"
#include "oanda/v20/order/GuaranteedStopLossOrderEntryData.hpp"

#endif /* OANDA_V20_ORDER_ORDERCOMMON_HPP */
