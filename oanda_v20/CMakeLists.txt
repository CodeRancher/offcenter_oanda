#
# Copyright 2022 Scott Brauer
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an  BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
#
#
# @file   CMakeLists.txt
# @author Scott Brauer
# @date   05-27-2019
#

include(OffcenterBuild)

offcenter_cxx()
offcenter_elpp()
offcenter_lib_setup(oanda_v20 oanda_v20)

set(version 0.0.1)

add_library(${LIB_NAME} STATIC)

add_compile_definitions(HAS_UNCAUGHT_EXCEPTIONS=1)

target_sources(${LIB_NAME}
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/src/account/Account.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/account/AccountChanges.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/account/AccountChangesState.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/account/AccountProperties.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/account/AccountSummary.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/account/AccumulatedAccountState.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/account/CalculatedAccountState.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/account/GuaranteedStopLossOrderParameters.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/account/UserAttributes.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/endpoint/OandaAuthorization.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/endpoint/OandaClient.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/endpoint/OandaEndpoints.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/endpoint/OandaEndpointParameters.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/endpoint/OandaConnectionException.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/endpoint/OandaExceptionFactory.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/endpoint/Utility.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/instrument/Candlestick.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/instrument/CandlestickData.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/instrument/CandlestickResponse.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/instrument/OrderBook.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/instrument/OrderBookBucket.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/instrument/PositionBook.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/instrument/PositionBookBucket.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/instrument/InstrumentDefinitions.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/json/AccountJson.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/json/InstrumentJson.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/json/JsonConversion.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/json/OrderJson.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/json/PositionJson.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/json/Pricing_CommonJson.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/json/PricingJson.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/json/PrimitivesJson.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/json/TradeJson.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/json/TransactionJson.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/DynamicOrderState.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/FixedPriceOrder.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/GuaranteedStopLossOrder.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/GuaranteedStopLossOrderEntryData.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/GuaranteedStopLossOrderRequest.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/LimitOrder.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/LimitOrderRequest.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/MarketIfTouchedOrder.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/MarketIfTouchedOrderRequest.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/MarketOrder.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/MarketOrderRequest.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/Order.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/OrderIdentifier.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/StopLossOrder.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/StopLossOrderRequest.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/StopOrder.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/StopOrderRequest.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/TakeProfitOrder.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/TakeProfitOrderRequest.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/TrailingStopLossOrder.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/TrailingStopLossOrderRequest.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/UnitsAvailable.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/order/UnitsAvailableDetails.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/position/CalculatedPositionState.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/position/Position.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/position/PositionSide.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/pricing/ClientPrice.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/pricing/HomeConversions.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/pricing/PriceBucket.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/pricing/PricingHeartbeat.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/pricing/QuoteHomeConversionFactors.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/primitives/ConversionFactor.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/primitives/FinancingDayOfWeek.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/primitives/GuaranteedStopLossOrderLevelRestriction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/primitives/HomeConversionFactors.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/primitives/Instrument.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/primitives/InstrumentCommission.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/primitives/InstrumentFinancing.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/primitives/PrimitivesDefinitions.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/primitives/Tag.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/trade/CalculatedTradeState.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/trade/Trade.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/trade/TradeSummary.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/ClientConfigureRejectTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/ClientConfigureTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/ClientExtensions.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/CloseTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/CreateTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/DailyFinancingTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/DelayedTradeClosureTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/DividendAdjustmentTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/FixedPriceOrderTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/GuaranteedStopLossDetails.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/GuaranteedStopLossOrderRejectTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/GuaranteedStopLossOrderTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/LimitOrderRejectTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/LimitOrderTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/LiquidityRegenerationSchedule.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/LiquidityRegenerationScheduleStep.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/MarginCallEnterTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/MarginCallExitTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/MarginCallExtendTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/MarketIfTouchedOrderRejectTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/MarketIfTouchedOrderTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/MarketOrderDelayedTradeClose.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/MarketOrderMarginCloseout.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/MarketOrderPositionCloseout.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/MarketOrderRejectTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/MarketOrderTradeClose.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/MarketOrderTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/OpenTradeDividendAdjustment.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/OpenTradeFinancing.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/OrderCancelRejectTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/OrderCancelTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/OrderClientExtensionsModifyRejectTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/OrderClientExtensionsModifyTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/OrderFillTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/PositionFinancing.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/ReopenTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/ResetResettablePLTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/StopLossDetails.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/StopLossOrderRejectTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/StopLossOrderTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/StopOrderRejectTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/StopOrderTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/TakeProfitDetails.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/TakeProfitOrderRejectTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/TakeProfitOrderTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/TradeClientExtensionsModifyRejectTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/TradeClientExtensionsModifyTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/TradeOpen.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/TradeReduce.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/TrailingStopLossDetails.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/TrailingStopLossOrderRejectTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/TrailingStopLossOrderTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/Transaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/TransactionHeartbeat.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/TransferFundsRejectTransaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/transaction/TransferFundsTransaction.cpp

		${CMAKE_CURRENT_LIST_DIR}/src/common/String.cpp
		
		${CMAKE_CURRENT_LIST_DIR}/src/endpoint/Account.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/endpoint/Instrument.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/endpoint/Order.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/endpoint/Trade.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/endpoint/Position.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/endpoint/Transaction.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/endpoint/Pricing.cpp
		
	PUBLIC
		# /include/oanda/v20/account
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/account/Account.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/account/Account.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/account/AccountChanges.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/account/AccountChanges.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/account/AccountChangesState.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/account/AccountChangesState.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/account/AccountCommon.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/account/AccountCommon.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/account/AccountDefinitions.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/account/AccountDefinitions.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/account/AccountProperties.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/account/AccountProperties.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/account/AccountSummary.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/account/AccountSummary.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/account/AccumulatedAccountState.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/account/AccumulatedAccountState.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/account/CalculatedAccountState.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/account/CalculatedAccountState.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/account/GuaranteedStopLossOrderParameters.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/account/GuaranteedStopLossOrderParameters.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/account/UserAttributes.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/account/UserAttributes.hpp>
	
		# /include/oanda/v20/common
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/common/CommonDefinitions.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/common/CommonDefinitions.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/common/OandaCommonException.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/common/OandaCommonException.hpp>
		
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/common/String.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/common/String.hpp>
		
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/common/Utility.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/common/Utility.hpp>
	
		# /include/oanda/v20/endpoint
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/Account.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/Account.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/Instrument.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/Instrument.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/OandaAuthorization.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/OandaAuthorization.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/OandaClient.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/OandaClient.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/OandaConnectionException.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/OandaConnectionException.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/OandaEndpointParameters.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/OandaEndpointParameters.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/OandaEndpointResponses.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/OandaEndpointResponses.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/OandaEndpoints.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/OandaEndpoints.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/OandaExceptionFactory.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/OandaExceptionFactory.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/OandaParameter.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/OandaParameter.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/OandaServer.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/OandaServer.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/Order.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/Order.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/Position.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/Position.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/Pricing.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/Pricing.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/Trade.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/Trade.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/endpoint/Transaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/endpoint/Transaction.hpp>
	
		# /include/oanda/v20/instrument
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/instrument/Candlestick.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/instrument/Candlestick.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/instrument/CandlestickData.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/instrument/CandlestickData.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/instrument/CandlestickResponse.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/instrument/CandlestickResponse.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/instrument/InstrumentCommon.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/instrument/InstrumentCommon.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/instrument/InstrumentDefinitions.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/instrument/InstrumentDefinitions.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/instrument/OrderBook.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/instrument/OrderBook.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/instrument/OrderBookBucket.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/instrument/OrderBookBucket.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/instrument/PositionBook.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/instrument/PositionBook.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/instrument/PositionBookBucket.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/instrument/PositionBookBucket.hpp>
	
		# /include/oanda/v20/json/exception
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/json/exception/OutOfRange.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/json/exception/OutOfRange.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/json/exception/UnhandledNull.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/json/exception/UnhandledNull.hpp>

		# /include/oanda/v20/json
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/json/JsonConversion.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/json/JsonConversion.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/json/JsonToFrom.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/json/JsonToFrom.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/json/RequestJsonToFrom.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/json/RequestJsonToFrom.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/json/ResponseJsonToFrom.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/json/ResponseJsonToFrom.hpp>
	
		# /include/oanda/v20/order
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/DynamicOrderState.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/DynamicOrderState.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/FixedPriceOrder.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/FixedPriceOrder.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/GuaranteedStopLossOrder.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/GuaranteedStopLossOrder.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/GuaranteedStopLossOrderEntryData.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/GuaranteedStopLossOrderEntryData.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/GuaranteedStopLossOrderRequest.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/GuaranteedStopLossOrderRequest.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/LimitOrder.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/LimitOrder.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/LimitOrderRequest.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/LimitOrderRequest.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/MarketIfTouchedOrder.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/MarketIfTouchedOrder.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/MarketIfTouchedOrderRequest.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/MarketIfTouchedOrderRequest.hpp>	
		
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/MarketOrder.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/MarketOrder.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/MarketOrderRequest.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/MarketOrderRequest.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/Order.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/Order.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/OrderCommon.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/OrderCommon.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/OrderDefinitions.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/OrderDefinitions.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/OrderIdentifier.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/OrderIdentifier.hpp>

		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/StopLossOrder.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/StopLossOrder.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/StopLossOrderRequest.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/StopLossOrderRequest.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/StopOrder.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/StopOrder.hpp>

		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/StopOrderRequest.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/StopOrderRequest.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/TakeProfitOrder.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/TakeProfitOrder.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/TakeProfitOrderRequest.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/TakeProfitOrderRequest.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/TrailingStopLossOrder.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/TrailingStopLossOrder.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/TrailingStopLossOrderRequest.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/TrailingStopLossOrderRequest.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/UnitsAvailable.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/UnitsAvailable.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/order/UnitsAvailableDetails.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/order/UnitsAvailableDetails.hpp>
	
		# /include/oanda/v20/position
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/position/CalculatedPositionState.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/position/CalculatedPositionState.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/position/Position.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/position/Position.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/position/PositionCommon.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/position/PositionCommon.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/position/PositionDefinitions.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/position/PositionDefinitions.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/position/PositionSide.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/position/PositionSide.hpp>
	
		# /include/oanda/v20/pricing
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/pricing/ClientPrice.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/pricing/ClientPrice.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/pricing/HomeConversions.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/pricing/HomeConversions.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/pricing/PricingCommon.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/pricing/PricingCommon.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/pricing/PricingDefinitions.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/pricing/PricingDefinitions.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/pricing/PricingHeartbeat.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/pricing/PricingHeartbeat.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/pricing/QuoteHomeConversionFactors.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/pricing/QuoteHomeConversionFactors.hpp>
	
		#
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/pricing_common/PriceBucket.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/pricing_common/PriceBucket.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/pricing_common/Pricing_CommonCommon.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/pricing_common/Pricing_CommonCommon.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp>
	
		# /include/oanda/v20/primitives
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/primitives/ConversionFactor.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/primitives/ConversionFactor.hpp>

		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/primitives/FinancingDayOfWeek.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/primitives/FinancingDayOfWeek.hpp>

		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/primitives/GuaranteedStopLossOrderLevelRestriction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/primitives/GuaranteedStopLossOrderLevelRestriction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/primitives/HomeConversionFactors.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/primitives/HomeConversionFactors.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/primitives/Instrument.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/primitives/Instrument.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/primitives/InstrumentCommission.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/primitives/InstrumentCommission.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/primitives/InstrumentFinancing.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/primitives/InstrumentFinancing.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/primitives/PrimitivesCommon.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/primitives/PrimitivesCommon.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/primitives/PrimitivesDefinitions.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/primitives/PrimitivesDefinitions.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/primitives/Tag.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/primitives/Tag.hpp>

		# /include/oanda/v20/trade
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/trade/CalculatedTradeState.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/trade/CalculatedTradeState.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/trade/Trade.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/trade/Trade.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/trade/TradeCommon.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/trade/TradeCommon.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/trade/TradeDefinitions.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/trade/TradeDefinitions.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/trade/TradeSummary.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/trade/TradeSummary.hpp>
	
		# /include/oanda/v20/transaction
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/ClientConfigureRejectTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/ClientConfigureRejectTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/ClientConfigureTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/ClientConfigureTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/ClientExtensions.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/ClientExtensions.hpp>

		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/CloseTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/CloseTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/CreateTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/CreateTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/DailyFinancingTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/DailyFinancingTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/DelayedTradeClosureTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/DelayedTradeClosureTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/DividendAdjustmentTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/DividendAdjustmentTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/FixedPriceOrderTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/FixedPriceOrderTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/GuaranteedStopLossDetails.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/GuaranteedStopLossDetails.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/GuaranteedStopLossOrderRejectTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/GuaranteedStopLossOrderRejectTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/GuaranteedStopLossOrderTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/GuaranteedStopLossOrderTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/LimitOrderRejectTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/LimitOrderRejectTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/LimitOrderTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/LimitOrderTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/LiquidityRegenerationSchedule.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/LiquidityRegenerationSchedule.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/LiquidityRegenerationScheduleStep.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/LiquidityRegenerationScheduleStep.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/MarginCallEnterTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/MarginCallEnterTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/MarginCallExitTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/MarginCallExitTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/MarginCallExtendTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/MarginCallExtendTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/MarketIfTouchedOrderRejectTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/MarketIfTouchedOrderRejectTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/MarketIfTouchedOrderTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/MarketIfTouchedOrderTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/MarketOrderDelayedTradeClose.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/MarketOrderDelayedTradeClose.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/MarketOrderMarginCloseout.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/MarketOrderMarginCloseout.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/MarketOrderPositionCloseout.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/MarketOrderPositionCloseout.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/MarketOrderRejectTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/MarketOrderRejectTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/MarketOrderTradeClose.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/MarketOrderTradeClose.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/MarketOrderTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/MarketOrderTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/OpenTradeDividendAdjustment.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/OpenTradeDividendAdjustment.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/OpenTradeFinancing.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/OpenTradeFinancing.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/OrderCancelRejectTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/OrderCancelRejectTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/OrderCancelTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/OrderCancelTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/OrderClientExtensionsModifyRejectTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/OrderClientExtensionsModifyRejectTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/OrderClientExtensionsModifyTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/OrderClientExtensionsModifyTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/OrderFillTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/OrderFillTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/PositionFinancing.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/PositionFinancing.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/ReopenTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/ReopenTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/ResetResettablePLTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/ResetResettablePLTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/StopLossDetails.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/StopLossDetails.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/StopLossOrderRejectTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/StopLossOrderRejectTransaction.hpp>

		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/StopLossOrderTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/StopLossOrderTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/StopOrderRejectTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/StopOrderRejectTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/StopOrderTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/StopOrderTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TakeProfitDetails.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TakeProfitDetails.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TakeProfitOrderRejectTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TakeProfitOrderRejectTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TakeProfitOrderTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TakeProfitOrderTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TradeClientExtensionsModifyRejectTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TradeClientExtensionsModifyRejectTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TradeClientExtensionsModifyTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TradeClientExtensionsModifyTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TradeOpen.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TradeOpen.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TradeReduce.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TradeReduce.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TrailingStopLossDetails.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TrailingStopLossDetails.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TrailingStopLossOrderRejectTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TrailingStopLossOrderRejectTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TrailingStopLossOrderTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TrailingStopLossOrderTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/Transaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/Transaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TransactionCommon.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TransactionCommon.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TransactionDefinitions.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TransactionDefinitions.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TransactionHeartbeat.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TransactionHeartbeat.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TransferFundsRejectTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TransferFundsRejectTransaction.hpp>
	
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/oanda/v20/transaction/TransferFundsTransaction.hpp>
		$<INSTALL_INTERFACE:include/oanda/v20/transaction/TransferFundsTransaction.hpp>
)

target_include_directories(${LIB_NAME} 
	SYSTEM PRIVATE
		${EASYLOGGINGPP_INCLUDE_DIR}
)

target_include_directories(${LIB_NAME}
	PUBLIC
		"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
		"$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

include(OffcenterInstall)
offcenter_lib_install()

if(ENABLE_UNIT_TESTS)
    add_subdirectory(test)
endif()

