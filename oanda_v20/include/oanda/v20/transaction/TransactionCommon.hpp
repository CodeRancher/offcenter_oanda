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
 * @file   TransactionCommon.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_TRANSACTIONCOMMON_HPP
#define OANDA_V20_TRANSACTION_TRANSACTIONCOMMON_HPP

#include "oanda/v20/transaction/Transaction.hpp"
#include "oanda/v20/transaction/CreateTransaction.hpp"
#include "oanda/v20/transaction/CloseTransaction.hpp"
#include "oanda/v20/transaction/ReopenTransaction.hpp"
#include "oanda/v20/transaction/ClientConfigureTransaction.hpp"
#include "oanda/v20/transaction/ClientConfigureRejectTransaction.hpp"
#include "oanda/v20/transaction/TransferFundsTransaction.hpp"
#include "oanda/v20/transaction/TransferFundsRejectTransaction.hpp"
#include "oanda/v20/transaction/MarketOrderTransaction.hpp"
#include "oanda/v20/transaction/MarketOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/FixedPriceOrderTransaction.hpp"
#include "oanda/v20/transaction/LimitOrderTransaction.hpp"
#include "oanda/v20/transaction/LimitOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/StopOrderTransaction.hpp"
#include "oanda/v20/transaction/StopOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/MarketIfTouchedOrderTransaction.hpp"
#include "oanda/v20/transaction/MarketIfTouchedOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/TakeProfitOrderTransaction.hpp"
#include "oanda/v20/transaction/TakeProfitOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/StopLossOrderTransaction.hpp"
#include "oanda/v20/transaction/StopLossOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/GuaranteedStopLossOrderTransaction.hpp"
#include "oanda/v20/transaction/GuaranteedStopLossOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/TrailingStopLossOrderTransaction.hpp"
#include "oanda/v20/transaction/TrailingStopLossOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/OrderFillTransaction.hpp"
#include "oanda/v20/transaction/OrderCancelTransaction.hpp"
#include "oanda/v20/transaction/OrderCancelRejectTransaction.hpp"
#include "oanda/v20/transaction/OrderClientExtensionsModifyTransaction.hpp"
#include "oanda/v20/transaction/OrderClientExtensionsModifyRejectTransaction.hpp"
#include "oanda/v20/transaction/TradeClientExtensionsModifyTransaction.hpp"
#include "oanda/v20/transaction/TradeClientExtensionsModifyRejectTransaction.hpp"
#include "oanda/v20/transaction/MarginCallEnterTransaction.hpp"
#include "oanda/v20/transaction/MarginCallExtendTransaction.hpp"
#include "oanda/v20/transaction/MarginCallExitTransaction.hpp"
#include "oanda/v20/transaction/DelayedTradeClosureTransaction.hpp"
#include "oanda/v20/transaction/DailyFinancingTransaction.hpp"
#include "oanda/v20/transaction/DividendAdjustmentTransaction.hpp"
#include "oanda/v20/transaction/ResetResettablePLTransaction.hpp"
#include "oanda/v20/transaction/OpenTradeDividendAdjustment.hpp"
#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/transaction/TakeProfitDetails.hpp"
#include "oanda/v20/transaction/StopLossDetails.hpp"
#include "oanda/v20/transaction/GuaranteedStopLossDetails.hpp"
#include "oanda/v20/transaction/TrailingStopLossDetails.hpp"
#include "oanda/v20/transaction/TradeOpen.hpp"
#include "oanda/v20/transaction/TradeReduce.hpp"
#include "oanda/v20/transaction/MarketOrderTradeClose.hpp"
#include "oanda/v20/transaction/MarketOrderMarginCloseout.hpp"
#include "oanda/v20/transaction/MarketOrderDelayedTradeClose.hpp"
#include "oanda/v20/transaction/MarketOrderPositionCloseout.hpp"
#include "oanda/v20/transaction/LiquidityRegenerationSchedule.hpp"
#include "oanda/v20/transaction/LiquidityRegenerationScheduleStep.hpp"
#include "oanda/v20/transaction/OpenTradeFinancing.hpp"
#include "oanda/v20/transaction/PositionFinancing.hpp"
#include "oanda/v20/transaction/TransactionHeartbeat.hpp"

#endif /* OANDA_V20_TRANSACTION_TRANSACTIONCOMMON_HPP */
