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
 * @file   AccountJson.hpp"
 * @author Scott Brauer
 * @date   12-07-2020
 */

#ifndef OANDA_V20_JSON_JSONTOFROM_HPP
#define OANDA_V20_JSON_JSONTOFROM_HPP

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "oanda/v20/trade/CalculatedTradeState.hpp"
#include "oanda/v20/trade/TradeDefinitions.hpp"
#include "oanda/v20/trade/TradeCommon.hpp"
#include "oanda/v20/trade/Trade.hpp"
#include "oanda/v20/trade/TradeSummary.hpp"
#include "oanda/v20/account/CalculatedAccountState.hpp"
#include "oanda/v20/account/AccountChangesState.hpp"
#include "oanda/v20/account/AccumulatedAccountState.hpp"
#include "oanda/v20/account/UserAttributes.hpp"
#include "oanda/v20/account/AccountSummary.hpp"
#include "oanda/v20/account/AccountCommon.hpp"
#include "oanda/v20/account/GuaranteedStopLossOrderParameters.hpp"
#include "oanda/v20/account/AccountChanges.hpp"
#include "oanda/v20/account/AccountDefinitions.hpp"
#include "oanda/v20/account/AccountProperties.hpp"
#include "oanda/v20/account/Account.hpp"
#include "oanda/v20/pricing_common/PriceBucket.hpp"
#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/pricing_common/Pricing_CommonCommon.hpp"
#include "oanda/v20/instrument/OrderBook.hpp"
#include "oanda/v20/instrument/InstrumentDefinitions.hpp"
#include "oanda/v20/instrument/CandlestickResponse.hpp"
#include "oanda/v20/instrument/PositionBookBucket.hpp"
#include "oanda/v20/instrument/Candlestick.hpp"
#include "oanda/v20/instrument/PositionBook.hpp"
#include "oanda/v20/instrument/OrderBookBucket.hpp"
#include "oanda/v20/instrument/CandlestickData.hpp"
#include "oanda/v20/instrument/InstrumentCommon.hpp"
#include "oanda/v20/position/PositionCommon.hpp"
#include "oanda/v20/position/Position.hpp"
#include "oanda/v20/position/CalculatedPositionState.hpp"
#include "oanda/v20/position/PositionDefinitions.hpp"
#include "oanda/v20/position/PositionSide.hpp"
#include "oanda/v20/pricing/PricingHeartbeat.hpp"
#include "oanda/v20/pricing/PricingCommon.hpp"
#include "oanda/v20/pricing/ClientPrice.hpp"
#include "oanda/v20/pricing/PricingDefinitions.hpp"
#include "oanda/v20/pricing/QuoteHomeConversionFactors.hpp"
#include "oanda/v20/pricing/HomeConversions.hpp"
#include "oanda/v20/primitives/FinancingDayOfWeek.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"
#include "oanda/v20/primitives/InstrumentFinancing.hpp"
#include "oanda/v20/primitives/ConversionFactor.hpp"
#include "oanda/v20/primitives/PrimitivesCommon.hpp"
#include "oanda/v20/primitives/HomeConversionFactors.hpp"
#include "oanda/v20/primitives/Instrument.hpp"
#include "oanda/v20/primitives/GuaranteedStopLossOrderLevelRestriction.hpp"
#include "oanda/v20/primitives/InstrumentCommission.hpp"
#include "oanda/v20/primitives/Tag.hpp"
#include "oanda/v20/transaction/MarketOrderMarginCloseout.hpp"
#include "oanda/v20/transaction/TransactionCommon.hpp"
#include "oanda/v20/transaction/FixedPriceOrderTransaction.hpp"
#include "oanda/v20/transaction/OpenTradeFinancing.hpp"
#include "oanda/v20/transaction/Transaction.hpp"
#include "oanda/v20/transaction/MarketOrderDelayedTradeClose.hpp"
#include "oanda/v20/transaction/TransactionHeartbeat.hpp"
#include "oanda/v20/transaction/ClientConfigureRejectTransaction.hpp"
#include "oanda/v20/transaction/MarketIfTouchedOrderTransaction.hpp"
#include "oanda/v20/transaction/StopLossOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/GuaranteedStopLossOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/OpenTradeDividendAdjustment.hpp"
#include "oanda/v20/transaction/DelayedTradeClosureTransaction.hpp"
#include "oanda/v20/transaction/TrailingStopLossDetails.hpp"
#include "oanda/v20/transaction/MarketOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/MarketIfTouchedOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/CreateTransaction.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/transaction/TrailingStopLossOrderTransaction.hpp"
#include "oanda/v20/transaction/TradeClientExtensionsModifyTransaction.hpp"
#include "oanda/v20/transaction/ReopenTransaction.hpp"
#include "oanda/v20/transaction/OrderClientExtensionsModifyRejectTransaction.hpp"
#include "oanda/v20/transaction/LiquidityRegenerationScheduleStep.hpp"
#include "oanda/v20/transaction/TransferFundsRejectTransaction.hpp"
#include "oanda/v20/transaction/StopOrderTransaction.hpp"
#include "oanda/v20/transaction/TrailingStopLossOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/DividendAdjustmentTransaction.hpp"
#include "oanda/v20/transaction/OrderCancelTransaction.hpp"
#include "oanda/v20/transaction/TransferFundsTransaction.hpp"
#include "oanda/v20/transaction/CloseTransaction.hpp"
#include "oanda/v20/transaction/TradeReduce.hpp"
#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/transaction/LiquidityRegenerationSchedule.hpp"
#include "oanda/v20/transaction/GuaranteedStopLossOrderTransaction.hpp"
#include "oanda/v20/transaction/LimitOrderTransaction.hpp"
#include "oanda/v20/transaction/GuaranteedStopLossDetails.hpp"
#include "oanda/v20/transaction/MarketOrderTransaction.hpp"
#include "oanda/v20/transaction/TradeClientExtensionsModifyRejectTransaction.hpp"
#include "oanda/v20/transaction/TakeProfitOrderTransaction.hpp"
#include "oanda/v20/transaction/TakeProfitDetails.hpp"
#include "oanda/v20/transaction/MarketOrderTradeClose.hpp"
#include "oanda/v20/transaction/StopLossOrderTransaction.hpp"
#include "oanda/v20/transaction/TakeProfitOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/MarginCallEnterTransaction.hpp"
#include "oanda/v20/transaction/MarginCallExtendTransaction.hpp"
#include "oanda/v20/transaction/ClientConfigureTransaction.hpp"
#include "oanda/v20/transaction/OrderFillTransaction.hpp"
#include "oanda/v20/transaction/TradeOpen.hpp"
#include "oanda/v20/transaction/StopLossDetails.hpp"
#include "oanda/v20/transaction/OrderCancelRejectTransaction.hpp"
#include "oanda/v20/transaction/OrderClientExtensionsModifyTransaction.hpp"
#include "oanda/v20/transaction/StopOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/DailyFinancingTransaction.hpp"
#include "oanda/v20/transaction/LimitOrderRejectTransaction.hpp"
#include "oanda/v20/transaction/ResetResettablePLTransaction.hpp"
#include "oanda/v20/transaction/MarginCallExitTransaction.hpp"
#include "oanda/v20/transaction/PositionFinancing.hpp"
#include "oanda/v20/transaction/MarketOrderPositionCloseout.hpp"
#include "oanda/v20/order/OrderIdentifier.hpp"
#include "oanda/v20/order/MarketIfTouchedOrder.hpp"
#include "oanda/v20/order/StopOrder.hpp"
#include "oanda/v20/order/LimitOrderRequest.hpp"
#include "oanda/v20/order/MarketOrderRequest.hpp"
#include "oanda/v20/order/TrailingStopLossOrder.hpp"
#include "oanda/v20/order/TakeProfitOrder.hpp"
#include "oanda/v20/order/GuaranteedStopLossOrderRequest.hpp"
#include "oanda/v20/order/FixedPriceOrder.hpp"
#include "oanda/v20/order/TakeProfitOrderRequest.hpp"
#include "oanda/v20/order/StopLossOrderRequest.hpp"
#include "oanda/v20/order/DynamicOrderState.hpp"
#include "oanda/v20/order/TrailingStopLossOrderRequest.hpp"
#include "oanda/v20/order/GuaranteedStopLossOrderEntryData.hpp"
#include "oanda/v20/order/StopLossOrder.hpp"
#include "oanda/v20/order/StopOrderRequest.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/order/Order.hpp"
#include "oanda/v20/order/UnitsAvailable.hpp"
#include "oanda/v20/order/LimitOrder.hpp"
#include "oanda/v20/order/OrderCommon.hpp"
#include "oanda/v20/order/UnitsAvailableDetails.hpp"
#include "oanda/v20/order/MarketOrder.hpp"
#include "oanda/v20/order/GuaranteedStopLossOrder.hpp"
#include "oanda/v20/order/MarketIfTouchedOrderRequest.hpp"

namespace oanda {
namespace v20 {

namespace common {
// GuaranteedStopLossOrderMode
NLOHMANN_JSON_SERIALIZE_ENUM(BoolType, {
	{BoolType::Undefined, nullptr},
	{BoolType::True, "true"},
	{BoolType::False, "false"}
})

}

namespace account {

// Account
void to_json(nlohmann::json& j, const Account& p);
void from_json(const nlohmann::json& j, Account& p);
//bool isDirty(const Account& p);

// AccountChangesState
void to_json(nlohmann::json& j, const AccountChangesState& p);
void from_json(const nlohmann::json& j, AccountChangesState& p);
//bool isDirty(const AccountChangesState& p);

// AccountProperties
void to_json(nlohmann::json& j, const AccountProperties& p);
void from_json(const nlohmann::json& j, AccountProperties& p);
//bool isDirty(const AccountProperties& p);

// GuaranteedStopLossOrderParameters
void to_json(nlohmann::json& j, const GuaranteedStopLossOrderParameters& p);
void from_json(const nlohmann::json& j, GuaranteedStopLossOrderParameters& p);
//bool isDirty(const GuaranteedStopLossOrderParameters& p);

// GuaranteedStopLossOrderMode
//void to_json(nlohmann::json& j, const oanda::v20::account::GuaranteedStopLossOrderMode& e);
//void from_json(const nlohmann::json& j, oanda::v20::account::GuaranteedStopLossOrderMode& e);

// GuaranteedStopLossOrderMutability
//void to_json(nlohmann::json& j, const oanda::v20::account::GuaranteedStopLossOrderMutability& e);
//void from_json(const nlohmann::json& j, oanda::v20::account::GuaranteedStopLossOrderMutability& e);

// GuaranteedStopLossOrderMode
NLOHMANN_JSON_SERIALIZE_ENUM(GuaranteedStopLossOrderMode, {
	{GuaranteedStopLossOrderMode::UNDEFINED, nullptr},
	{GuaranteedStopLossOrderMode::REQUIRED, "REQUIRED"},
	{GuaranteedStopLossOrderMode::DISABLED, "DISABLED"},
	{GuaranteedStopLossOrderMode::ALLOWED, "ALLOWED"}
})

// GuaranteedStopLossOrderMutability
NLOHMANN_JSON_SERIALIZE_ENUM(GuaranteedStopLossOrderMutability, {
	{GuaranteedStopLossOrderMutability::UNDEFINED, nullptr},
	{GuaranteedStopLossOrderMutability::REPLACEABLE, "REPLACEABLE"},
	{GuaranteedStopLossOrderMutability::PRICE_WIDEN_ONLY, "PRICE_WIDEN_ONLY"},
	{GuaranteedStopLossOrderMutability::CANCELABLE, "CANCELABLE"},
	{GuaranteedStopLossOrderMutability::FIXED, "FIXED"}
})

// AccountSummary
void to_json(nlohmann::json& j, const AccountSummary& p);
void from_json(const nlohmann::json& j, AccountSummary& p);
//bool isDirty(const AccountSummary& p);

// AccumulatedAccountState
void to_json(nlohmann::json& j, const AccumulatedAccountState& p);
void from_json(const nlohmann::json& j, AccumulatedAccountState& p);
//bool isDirty(const AccumulatedAccountState& p);

// CalculatedAccountState
void to_json(nlohmann::json& j, const CalculatedAccountState& p);
void from_json(const nlohmann::json& j, CalculatedAccountState& p);
//bool isDirty(const CalculatedAccountState& p);

// AccountChanges
void to_json(nlohmann::json& j, const AccountChanges& p);
void from_json(const nlohmann::json& j, AccountChanges& p);
//bool isDirty(const AccountChanges& p);

// AccountFinancingMode
//void to_json(nlohmann::json& j, const oanda::v20::account::AccountFinancingMode& e);
//void from_json(const nlohmann::json& j, oanda::v20::account::AccountFinancingMode& e);
// AccountFinancingMode
NLOHMANN_JSON_SERIALIZE_ENUM(AccountFinancingMode, {
	{AccountFinancingMode::UNDEFINED, nullptr},
	{AccountFinancingMode::DAILY, "DAILY"},
	{AccountFinancingMode::SECOND_BY_SECOND, "SECOND_BY_SECOND"},
	{AccountFinancingMode::NO_FINANCING, "NO_FINANCING"}
})

// UserAttributes
void to_json(nlohmann::json& j, const UserAttributes& p);
void from_json(const nlohmann::json& j, UserAttributes& p);
//bool isDirty(const UserAttributes& p);

// PositionAggregationMode
//void to_json(nlohmann::json& j, const oanda::v20::account::PositionAggregationMode& e);
//void from_json(const nlohmann::json& j, oanda::v20::account::PositionAggregationMode& e);
// PositionAggregationMode
NLOHMANN_JSON_SERIALIZE_ENUM(PositionAggregationMode, {
	{PositionAggregationMode::UNDEFINED, nullptr},
	{PositionAggregationMode::NET_SUM, "NET_SUM"},
	{PositionAggregationMode::MAXIMAL_SIDE, "MAXIMAL_SIDE"},
	{PositionAggregationMode::ABSOLUTE_SUM, "ABSOLUTE_SUM"}
})

} /* namespace account */

namespace instrument {

// CandlestickGranularity
//void to_json(nlohmann::json& j, const oanda::v20::instrument::CandlestickGranularity& e);
//void from_json(const nlohmann::json& j, oanda::v20::instrument::CandlestickGranularity& e);
// CandlestickGranularity
NLOHMANN_JSON_SERIALIZE_ENUM(CandlestickGranularity, {
	{CandlestickGranularity::UNDEFINED, nullptr},
	{CandlestickGranularity::M5, "M5"},
	{CandlestickGranularity::M10, "M10"},
	{CandlestickGranularity::D, "D"},
	{CandlestickGranularity::M30, "M30"},
	{CandlestickGranularity::H12, "H12"},
	{CandlestickGranularity::H1, "H1"},
	{CandlestickGranularity::H2, "H2"},
	{CandlestickGranularity::S10, "S10"},
	{CandlestickGranularity::H3, "H3"},
	{CandlestickGranularity::M15, "M15"},
	{CandlestickGranularity::S5, "S5"},
	{CandlestickGranularity::H4, "H4"},
	{CandlestickGranularity::S30, "S30"},
	{CandlestickGranularity::W, "W"},
	{CandlestickGranularity::H6, "H6"},
	{CandlestickGranularity::M1, "M1"},
	{CandlestickGranularity::M2, "M2"},
	{CandlestickGranularity::S15, "S15"},
	{CandlestickGranularity::H8, "H8"},
	{CandlestickGranularity::M, "M"},
	{CandlestickGranularity::M4, "M4"}
})

// WeeklyAlignment
//void to_json(nlohmann::json& j, const oanda::v20::instrument::WeeklyAlignment& e);
//void from_json(const nlohmann::json& j, oanda::v20::instrument::WeeklyAlignment& e);
// WeeklyAlignment
NLOHMANN_JSON_SERIALIZE_ENUM(WeeklyAlignment, {
	{WeeklyAlignment::UNDEFINED, nullptr},
	{WeeklyAlignment::Tuesday, "Tuesday"},
	{WeeklyAlignment::Friday, "Friday"},
	{WeeklyAlignment::Sunday, "Sunday"},
	{WeeklyAlignment::Thursday, "Thursday"},
	{WeeklyAlignment::Saturday, "Saturday"},
	{WeeklyAlignment::Monday, "Monday"},
	{WeeklyAlignment::Wednesday, "Wednesday"}
})

// Candlestick
void to_json(nlohmann::json& j, const oanda::v20::instrument::Candlestick& p);
void from_json(const nlohmann::json& j, oanda::v20::instrument::Candlestick& p);

// CandlestickData
void to_json(nlohmann::json& j, const oanda::v20::instrument::CandlestickData& p);
void from_json(const nlohmann::json& j, oanda::v20::instrument::CandlestickData& p);

// CandlestickResponse
void to_json(nlohmann::json& j, const oanda::v20::instrument::CandlestickResponse& p);
void from_json(const nlohmann::json& j, oanda::v20::instrument::CandlestickResponse& p);

// OrderBook
void to_json(nlohmann::json& j, const oanda::v20::instrument::OrderBook& p);
void from_json(const nlohmann::json& j, oanda::v20::instrument::OrderBook& p);

// OrderBookBucket
void to_json(nlohmann::json& j, const oanda::v20::instrument::OrderBookBucket& p);
void from_json(const nlohmann::json& j, oanda::v20::instrument::OrderBookBucket& p);

// PositionBook
void to_json(nlohmann::json& j, const oanda::v20::instrument::PositionBook& p);
void from_json(const nlohmann::json& j, oanda::v20::instrument::PositionBook& p);

// PositionBookBucket
void to_json(nlohmann::json& j, const oanda::v20::instrument::PositionBookBucket& p);
void from_json(const nlohmann::json& j, oanda::v20::instrument::PositionBookBucket& p);

} /* namespace instrument */

namespace order {

// Order
void to_json(nlohmann::json& j, const oanda::v20::order::Order& p);
void from_json(const nlohmann::json& j, oanda::v20::order::Order& p);

// MarketOrder
void to_json(nlohmann::json& j, const oanda::v20::order::MarketOrder& p);
void from_json(const nlohmann::json& j, oanda::v20::order::MarketOrder& p);

// FixedPriceOrder
void to_json(nlohmann::json& j, const oanda::v20::order::FixedPriceOrder& p);
void from_json(const nlohmann::json& j, oanda::v20::order::FixedPriceOrder& p);

// LimitOrder
void to_json(nlohmann::json& j, const oanda::v20::order::LimitOrder& p);
void from_json(const nlohmann::json& j, oanda::v20::order::LimitOrder& p);

// StopOrder
void to_json(nlohmann::json& j, const oanda::v20::order::StopOrder& p);
void from_json(const nlohmann::json& j, oanda::v20::order::StopOrder& p);

// MarketIfTouchedOrder
void to_json(nlohmann::json& j, const oanda::v20::order::MarketIfTouchedOrder& p);
void from_json(const nlohmann::json& j, oanda::v20::order::MarketIfTouchedOrder& p);

// TakeProfitOrder
void to_json(nlohmann::json& j, const oanda::v20::order::TakeProfitOrder& p);
void from_json(const nlohmann::json& j, oanda::v20::order::TakeProfitOrder& p);

// StopLossOrder
void to_json(nlohmann::json& j, const oanda::v20::order::StopLossOrder& p);
void from_json(const nlohmann::json& j, oanda::v20::order::StopLossOrder& p);

// GuaranteedStopLossOrder
void to_json(nlohmann::json& j, const oanda::v20::order::GuaranteedStopLossOrder& p);
void from_json(const nlohmann::json& j, oanda::v20::order::GuaranteedStopLossOrder& p);

// TrailingStopLossOrder
void to_json(nlohmann::json& j, const oanda::v20::order::TrailingStopLossOrder& p);
void from_json(const nlohmann::json& j, oanda::v20::order::TrailingStopLossOrder& p);

// MarketOrderRequest
void to_json(nlohmann::json& j, const oanda::v20::order::MarketOrderRequest& p);
void from_json(const nlohmann::json& j, oanda::v20::order::MarketOrderRequest& p);

// LimitOrderRequest
void to_json(nlohmann::json& j, const oanda::v20::order::LimitOrderRequest& p);
void from_json(const nlohmann::json& j, oanda::v20::order::LimitOrderRequest& p);

// StopOrderRequest
void to_json(nlohmann::json& j, const oanda::v20::order::StopOrderRequest& p);
void from_json(const nlohmann::json& j, oanda::v20::order::StopOrderRequest& p);

// MarketIfTouchedOrderRequest
void to_json(nlohmann::json& j, const oanda::v20::order::MarketIfTouchedOrderRequest& p);
void from_json(const nlohmann::json& j, oanda::v20::order::MarketIfTouchedOrderRequest& p);

// TakeProfitOrderRequest
void to_json(nlohmann::json& j, const oanda::v20::order::TakeProfitOrderRequest& p);
void from_json(const nlohmann::json& j, oanda::v20::order::TakeProfitOrderRequest& p);

// StopLossOrderRequest
void to_json(nlohmann::json& j, const oanda::v20::order::StopLossOrderRequest& p);
void from_json(const nlohmann::json& j, oanda::v20::order::StopLossOrderRequest& p);

// GuaranteedStopLossOrderRequest
void to_json(nlohmann::json& j, const oanda::v20::order::GuaranteedStopLossOrderRequest& p);
void from_json(const nlohmann::json& j, oanda::v20::order::GuaranteedStopLossOrderRequest& p);

// TrailingStopLossOrderRequest
void to_json(nlohmann::json& j, const oanda::v20::order::TrailingStopLossOrderRequest& p);
void from_json(const nlohmann::json& j, oanda::v20::order::TrailingStopLossOrderRequest& p);

// OrderType
//void to_json(nlohmann::json& j, const oanda::v20::order::OrderType& e);
//void from_json(const nlohmann::json& j, oanda::v20::order::OrderType& e);
// OrderType
NLOHMANN_JSON_SERIALIZE_ENUM(OrderType, {
	{OrderType::UNDEFINED, nullptr},
	{OrderType::TAKE_PROFIT, "TAKE_PROFIT"},
	{OrderType::MARKET, "MARKET"},
	{OrderType::LIMIT, "LIMIT"},
	{OrderType::TRAILING_STOP_LOSS, "TRAILING_STOP_LOSS"},
	{OrderType::STOP_LOSS, "STOP_LOSS"},
	{OrderType::FIXED_PRICE, "FIXED_PRICE"},
	{OrderType::GUARANTEED_STOP_LOSS, "GUARANTEED_STOP_LOSS"},
	{OrderType::MARKET_IF_TOUCHED, "MARKET_IF_TOUCHED"},
	{OrderType::STOP, "STOP"}
})

// CancellableOrderType
//void to_json(nlohmann::json& j, const oanda::v20::order::CancellableOrderType& e);
//void from_json(const nlohmann::json& j, oanda::v20::order::CancellableOrderType& e);
// CancellableOrderType
NLOHMANN_JSON_SERIALIZE_ENUM(CancellableOrderType, {
	{CancellableOrderType::UNDEFINED, nullptr},
	{CancellableOrderType::TAKE_PROFIT, "TAKE_PROFIT"},
	{CancellableOrderType::LIMIT, "LIMIT"},
	{CancellableOrderType::TRAILING_STOP_LOSS, "TRAILING_STOP_LOSS"},
	{CancellableOrderType::STOP_LOSS, "STOP_LOSS"},
	{CancellableOrderType::GUARANTEED_STOP_LOSS, "GUARANTEED_STOP_LOSS"},
	{CancellableOrderType::MARKET_IF_TOUCHED, "MARKET_IF_TOUCHED"},
	{CancellableOrderType::STOP, "STOP"}
})

// OrderState
//void to_json(nlohmann::json& j, const oanda::v20::order::OrderState& e);
//void from_json(const nlohmann::json& j, oanda::v20::order::OrderState& e);
// OrderState
NLOHMANN_JSON_SERIALIZE_ENUM(OrderState, {
	{OrderState::UNDEFINED, nullptr},
	{OrderState::FILLED, "FILLED"},
	{OrderState::CANCELLED, "CANCELLED"},
	{OrderState::TRIGGERED, "TRIGGERED"},
	{OrderState::PENDING, "PENDING"}
})

// OrderStateFilter
//void to_json(nlohmann::json& j, const oanda::v20::order::OrderStateFilter& e);
//void from_json(const nlohmann::json& j, oanda::v20::order::OrderStateFilter& e);
// OrderStateFilter
NLOHMANN_JSON_SERIALIZE_ENUM(OrderStateFilter, {
	{OrderStateFilter::UNDEFINED, nullptr},
	{OrderStateFilter::FILLED, "FILLED"},
	{OrderStateFilter::CANCELLED, "CANCELLED"},
	{OrderStateFilter::TRIGGERED, "TRIGGERED"},
	{OrderStateFilter::ALL, "ALL"},
	{OrderStateFilter::PENDING, "PENDING"}
})

// OrderIdentifier
void to_json(nlohmann::json& j, const oanda::v20::order::OrderIdentifier& p);
void from_json(const nlohmann::json& j, oanda::v20::order::OrderIdentifier& p);

// TimeInForce
//void to_json(nlohmann::json& j, const oanda::v20::order::TimeInForce& e);
//void from_json(const nlohmann::json& j, oanda::v20::order::TimeInForce& e);
// TimeInForce
NLOHMANN_JSON_SERIALIZE_ENUM(TimeInForce, {
	{TimeInForce::UNDEFINED, nullptr},
	{TimeInForce::GTD, "GTD"},
	{TimeInForce::IOC, "IOC"},
	{TimeInForce::FOK, "FOK"},
	{TimeInForce::GFD, "GFD"},
	{TimeInForce::GTC, "GTC"}
})

// OrderPositionFill
//void to_json(nlohmann::json& j, const oanda::v20::order::OrderPositionFill& e);
//void from_json(const nlohmann::json& j, oanda::v20::order::OrderPositionFill& e);
// OrderPositionFill
NLOHMANN_JSON_SERIALIZE_ENUM(OrderPositionFill, {
	{OrderPositionFill::UNDEFINED, nullptr},
	{OrderPositionFill::REDUCE_FIRST, "REDUCE_FIRST"},
	{OrderPositionFill::OPEN_ONLY, "OPEN_ONLY"},
	{OrderPositionFill::DEFAULT, "DEFAULT"},
	{OrderPositionFill::REDUCE_ONLY, "REDUCE_ONLY"}
})

// OrderTriggerCondition
//void to_json(nlohmann::json& j, const oanda::v20::order::OrderTriggerCondition& e);
//void from_json(const nlohmann::json& j, oanda::v20::order::OrderTriggerCondition& e);
// OrderTriggerCondition
NLOHMANN_JSON_SERIALIZE_ENUM(OrderTriggerCondition, {
	{OrderTriggerCondition::UNDEFINED, nullptr},
	{OrderTriggerCondition::INVERSE, "INVERSE"},
	{OrderTriggerCondition::ASK, "ASK"},
	{OrderTriggerCondition::BID, "BID"},
	{OrderTriggerCondition::MID, "MID"},
	{OrderTriggerCondition::DEFAULT, "DEFAULT"}
})

// DynamicOrderState
void to_json(nlohmann::json& j, const oanda::v20::order::DynamicOrderState& p);
void from_json(const nlohmann::json& j, oanda::v20::order::DynamicOrderState& p);

// UnitsAvailableDetails
void to_json(nlohmann::json& j, const oanda::v20::order::UnitsAvailableDetails& p);
void from_json(const nlohmann::json& j, oanda::v20::order::UnitsAvailableDetails& p);

// UnitsAvailable
void to_json(nlohmann::json& j, const oanda::v20::order::UnitsAvailable& p);
void from_json(const nlohmann::json& j, oanda::v20::order::UnitsAvailable& p);

// GuaranteedStopLossOrderEntryData
void to_json(nlohmann::json& j, const oanda::v20::order::GuaranteedStopLossOrderEntryData& p);
void from_json(const nlohmann::json& j, oanda::v20::order::GuaranteedStopLossOrderEntryData& p);

} /* namespace order */

namespace position {

// Position
void to_json(nlohmann::json& j, const oanda::v20::position::Position& p);
void from_json(const nlohmann::json& j, oanda::v20::position::Position& p);

// PositionSide
void to_json(nlohmann::json& j, const oanda::v20::position::PositionSide& p);
void from_json(const nlohmann::json& j, oanda::v20::position::PositionSide& p);

// CalculatedPositionState
void to_json(nlohmann::json& j, const oanda::v20::position::CalculatedPositionState& p);
void from_json(const nlohmann::json& j, oanda::v20::position::CalculatedPositionState& p);

} /* namespace position */

namespace pricing {

// ClientPrice
void to_json(nlohmann::json& j, const oanda::v20::pricing::ClientPrice& p);
void from_json(const nlohmann::json& j, oanda::v20::pricing::ClientPrice& p);

// PriceStatus
//void to_json(nlohmann::json& j, const oanda::v20::pricing::PriceStatus& e);
//void from_json(const nlohmann::json& j, oanda::v20::pricing::PriceStatus& e);
// PriceStatus
NLOHMANN_JSON_SERIALIZE_ENUM(PriceStatus, {
	{PriceStatus::UNDEFINED, nullptr},
	{PriceStatus::tradeable, "tradeable"},
	{PriceStatus::invalid, "invalid"},
	{PriceStatus::non_tradeable, "non-tradeable"}
})

// QuoteHomeConversionFactors
void to_json(nlohmann::json& j, const oanda::v20::pricing::QuoteHomeConversionFactors& p);
void from_json(const nlohmann::json& j, oanda::v20::pricing::QuoteHomeConversionFactors& p);

// HomeConversions
void to_json(nlohmann::json& j, const oanda::v20::pricing::HomeConversions& p);
void from_json(const nlohmann::json& j, oanda::v20::pricing::HomeConversions& p);

// PricingHeartbeat
void to_json(nlohmann::json& j, const oanda::v20::pricing::PricingHeartbeat& p);
void from_json(const nlohmann::json& j, oanda::v20::pricing::PricingHeartbeat& p);

} /* namespace pricing */

namespace pricing_common {

// PriceBucket
void to_json(nlohmann::json& j, const oanda::v20::pricing_common::PriceBucket& p);
void from_json(const nlohmann::json& j, oanda::v20::pricing_common::PriceBucket& p);

} /* namespace pricing_common */

namespace primitives {

// Tag
void to_json(nlohmann::json& j, const oanda::v20::primitives::Tag& p);
void from_json(const nlohmann::json& j, oanda::v20::primitives::Tag& p);

// InstrumentType
//void to_json(nlohmann::json& j, const oanda::v20::primitives::InstrumentType& e);
//void from_json(const nlohmann::json& j, oanda::v20::primitives::InstrumentType& e);
// InstrumentType
NLOHMANN_JSON_SERIALIZE_ENUM(InstrumentType, {
	{InstrumentType::UNDEFINED, nullptr},
	{InstrumentType::CFD, "CFD"},
	{InstrumentType::METAL, "METAL"},
	{InstrumentType::CURRENCY, "CURRENCY"}
})

// DayOfWeek
//void to_json(nlohmann::json& j, const oanda::v20::primitives::DayOfWeek& e);
//void from_json(const nlohmann::json& j, oanda::v20::primitives::DayOfWeek& e);
// DayOfWeek
NLOHMANN_JSON_SERIALIZE_ENUM(DayOfWeek, {
	{DayOfWeek::UNDEFINED, nullptr},
	{DayOfWeek::SUNDAY, "SUNDAY"},
	{DayOfWeek::SATURDAY, "SATURDAY"},
	{DayOfWeek::THURSDAY, "THURSDAY"},
	{DayOfWeek::MONDAY, "MONDAY"},
	{DayOfWeek::WEDNESDAY, "WEDNESDAY"},
	{DayOfWeek::TUESDAY, "TUESDAY"},
	{DayOfWeek::FRIDAY, "FRIDAY"}
})

// FinancingDayOfWeek
void to_json(nlohmann::json& j, const oanda::v20::primitives::FinancingDayOfWeek& p);
void from_json(const nlohmann::json& j, oanda::v20::primitives::FinancingDayOfWeek& p);

// InstrumentFinancing
void to_json(nlohmann::json& j, const oanda::v20::primitives::InstrumentFinancing& p);
void from_json(const nlohmann::json& j, oanda::v20::primitives::InstrumentFinancing& p);

// Instrument
void to_json(nlohmann::json& j, const oanda::v20::primitives::Instrument& p);
void from_json(const nlohmann::json& j, oanda::v20::primitives::Instrument& p);

// AcceptDatetimeFormat
//void to_json(nlohmann::json& j, const oanda::v20::primitives::AcceptDatetimeFormat& e);
//void from_json(const nlohmann::json& j, oanda::v20::primitives::AcceptDatetimeFormat& e);
// AcceptDatetimeFormat
NLOHMANN_JSON_SERIALIZE_ENUM(AcceptDatetimeFormat, {
	{AcceptDatetimeFormat::UNDEFINED, nullptr},
	{AcceptDatetimeFormat::UNIX, "UNIX"},
	{AcceptDatetimeFormat::RFC3339, "RFC3339"}
})

// InstrumentCommission
void to_json(nlohmann::json& j, const oanda::v20::primitives::InstrumentCommission& p);
void from_json(const nlohmann::json& j, oanda::v20::primitives::InstrumentCommission& p);

// GuaranteedStopLossOrderModeForInstrument
//void to_json(nlohmann::json& j, const oanda::v20::primitives::GuaranteedStopLossOrderModeForInstrument& e);
//void from_json(const nlohmann::json& j, oanda::v20::primitives::GuaranteedStopLossOrderModeForInstrument& e);
// GuaranteedStopLossOrderModeForInstrument
NLOHMANN_JSON_SERIALIZE_ENUM(GuaranteedStopLossOrderModeForInstrument, {
	{GuaranteedStopLossOrderModeForInstrument::UNDEFINED, nullptr},
	{GuaranteedStopLossOrderModeForInstrument::REQUIRED, "REQUIRED"},
	{GuaranteedStopLossOrderModeForInstrument::DISABLED, "DISABLED"},
	{GuaranteedStopLossOrderModeForInstrument::ALLOWED, "ALLOWED"}
})

// GuaranteedStopLossOrderLevelRestriction
void to_json(nlohmann::json& j, const oanda::v20::primitives::GuaranteedStopLossOrderLevelRestriction& p);
void from_json(const nlohmann::json& j, oanda::v20::primitives::GuaranteedStopLossOrderLevelRestriction& p);

// Direction
//void to_json(nlohmann::json& j, const oanda::v20::primitives::Direction& e);
//void from_json(const nlohmann::json& j, oanda::v20::primitives::Direction& e);
// Direction
NLOHMANN_JSON_SERIALIZE_ENUM(Direction, {
	{Direction::UNDEFINED, nullptr},
	{Direction::SHORT, "SHORT"},
	{Direction::LONG, "LONG"}
})

// ConversionFactor
void to_json(nlohmann::json& j, const oanda::v20::primitives::ConversionFactor& p);
void from_json(const nlohmann::json& j, oanda::v20::primitives::ConversionFactor& p);

// HomeConversionFactors
void to_json(nlohmann::json& j, const oanda::v20::primitives::HomeConversionFactors& p);
void from_json(const nlohmann::json& j, oanda::v20::primitives::HomeConversionFactors& p);

} /* namespace primitives */

namespace trade {

// TradeState
//void to_json(nlohmann::json& j, const oanda::v20::trade::TradeState& e);
//void from_json(const nlohmann::json& j, oanda::v20::trade::TradeState& e);
// TradeState
NLOHMANN_JSON_SERIALIZE_ENUM(TradeState, {
	{TradeState::UNDEFINED, nullptr},
	{TradeState::OPEN, "OPEN"},
	{TradeState::CLOSE_WHEN_TRADEABLE, "CLOSE_WHEN_TRADEABLE"},
	{TradeState::CLOSED, "CLOSED"}
})

// TradeStateFilter
//void to_json(nlohmann::json& j, const oanda::v20::trade::TradeStateFilter& e);
//void from_json(const nlohmann::json& j, oanda::v20::trade::TradeStateFilter& e);
// TradeStateFilter
NLOHMANN_JSON_SERIALIZE_ENUM(TradeStateFilter, {
	{TradeStateFilter::UNDEFINED, nullptr},
	{TradeStateFilter::OPEN, "OPEN"},
	{TradeStateFilter::CLOSE_WHEN_TRADEABLE, "CLOSE_WHEN_TRADEABLE"},
	{TradeStateFilter::ALL, "ALL"},
	{TradeStateFilter::CLOSED, "CLOSED"}
})

// Trade
void to_json(nlohmann::json& j, const oanda::v20::trade::Trade& p);
void from_json(const nlohmann::json& j, oanda::v20::trade::Trade& p);

// TradeSummary
void to_json(nlohmann::json& j, const oanda::v20::trade::TradeSummary& p);
void from_json(const nlohmann::json& j, oanda::v20::trade::TradeSummary& p);

// CalculatedTradeState
void to_json(nlohmann::json& j, const oanda::v20::trade::CalculatedTradeState& p);
void from_json(const nlohmann::json& j, oanda::v20::trade::CalculatedTradeState& p);

// TradePL
//void to_json(nlohmann::json& j, const oanda::v20::trade::TradePL& e);
//void from_json(const nlohmann::json& j, oanda::v20::trade::TradePL& e);
// TradePL
NLOHMANN_JSON_SERIALIZE_ENUM(TradePL, {
	{TradePL::UNDEFINED, nullptr},
	{TradePL::POSITIVE, "POSITIVE"},
	{TradePL::NEGATIVE, "NEGATIVE"},
	{TradePL::ZERO, "ZERO"}
})

} /* namespace trade */

namespace transaction {

// Transaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::Transaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::Transaction& p);

// CreateTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::CreateTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::CreateTransaction& p);

// CloseTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::CloseTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::CloseTransaction& p);

// ReopenTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::ReopenTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::ReopenTransaction& p);

// ClientConfigureTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::ClientConfigureTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::ClientConfigureTransaction& p);

// ClientConfigureRejectTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::ClientConfigureRejectTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::ClientConfigureRejectTransaction& p);

// TransferFundsTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::TransferFundsTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::TransferFundsTransaction& p);

// TransferFundsRejectTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::TransferFundsRejectTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::TransferFundsRejectTransaction& p);

// MarketOrderTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::MarketOrderTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::MarketOrderTransaction& p);

// MarketOrderRejectTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::MarketOrderRejectTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::MarketOrderRejectTransaction& p);

// FixedPriceOrderTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::FixedPriceOrderTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::FixedPriceOrderTransaction& p);

// LimitOrderTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::LimitOrderTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::LimitOrderTransaction& p);

// LimitOrderRejectTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::LimitOrderRejectTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::LimitOrderRejectTransaction& p);

// StopOrderTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::StopOrderTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::StopOrderTransaction& p);

// StopOrderRejectTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::StopOrderRejectTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::StopOrderRejectTransaction& p);

// MarketIfTouchedOrderTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::MarketIfTouchedOrderTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::MarketIfTouchedOrderTransaction& p);

// MarketIfTouchedOrderRejectTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::MarketIfTouchedOrderRejectTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::MarketIfTouchedOrderRejectTransaction& p);

// TakeProfitOrderTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::TakeProfitOrderTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::TakeProfitOrderTransaction& p);

// TakeProfitOrderRejectTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::TakeProfitOrderRejectTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::TakeProfitOrderRejectTransaction& p);

// StopLossOrderTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::StopLossOrderTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::StopLossOrderTransaction& p);

// StopLossOrderRejectTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::StopLossOrderRejectTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::StopLossOrderRejectTransaction& p);

// GuaranteedStopLossOrderTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::GuaranteedStopLossOrderTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::GuaranteedStopLossOrderTransaction& p);

// GuaranteedStopLossOrderRejectTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::GuaranteedStopLossOrderRejectTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::GuaranteedStopLossOrderRejectTransaction& p);

// TrailingStopLossOrderTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::TrailingStopLossOrderTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::TrailingStopLossOrderTransaction& p);

// TrailingStopLossOrderRejectTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::TrailingStopLossOrderRejectTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::TrailingStopLossOrderRejectTransaction& p);

// OrderFillTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::OrderFillTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::OrderFillTransaction& p);

// OrderCancelTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::OrderCancelTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::OrderCancelTransaction& p);

// OrderCancelRejectTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::OrderCancelRejectTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::OrderCancelRejectTransaction& p);

// OrderClientExtensionsModifyTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::OrderClientExtensionsModifyTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::OrderClientExtensionsModifyTransaction& p);

// OrderClientExtensionsModifyRejectTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::OrderClientExtensionsModifyRejectTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::OrderClientExtensionsModifyRejectTransaction& p);

// TradeClientExtensionsModifyTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::TradeClientExtensionsModifyTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::TradeClientExtensionsModifyTransaction& p);

// TradeClientExtensionsModifyRejectTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::TradeClientExtensionsModifyRejectTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::TradeClientExtensionsModifyRejectTransaction& p);

// MarginCallEnterTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::MarginCallEnterTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::MarginCallEnterTransaction& p);

// MarginCallExtendTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::MarginCallExtendTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::MarginCallExtendTransaction& p);

// MarginCallExitTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::MarginCallExitTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::MarginCallExitTransaction& p);

// DelayedTradeClosureTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::DelayedTradeClosureTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::DelayedTradeClosureTransaction& p);

// DailyFinancingTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::DailyFinancingTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::DailyFinancingTransaction& p);

// DividendAdjustmentTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::DividendAdjustmentTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::DividendAdjustmentTransaction& p);

// ResetResettablePLTransaction
void to_json(nlohmann::json& j, const oanda::v20::transaction::ResetResettablePLTransaction& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::ResetResettablePLTransaction& p);

// TransactionType
//void to_json(nlohmann::json& j, const oanda::v20::transaction::TransactionType& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::TransactionType& e);
// TransactionType
NLOHMANN_JSON_SERIALIZE_ENUM(TransactionType, {
	{TransactionType::UNDEFINED, nullptr},
	{TransactionType::DIVIDEND_ADJUSTMENT, "DIVIDEND_ADJUSTMENT"},
	{TransactionType::ORDER_CANCEL, "ORDER_CANCEL"},
	{TransactionType::TRANSFER_FUNDS, "TRANSFER_FUNDS"},
	{TransactionType::RESET_RESETTABLE_PL, "RESET_RESETTABLE_PL"},
	{TransactionType::ORDER_CANCEL_REJECT, "ORDER_CANCEL_REJECT"},
	{TransactionType::TRAILING_STOP_LOSS_ORDER, "TRAILING_STOP_LOSS_ORDER"},
	{TransactionType::TRAILING_STOP_LOSS_ORDER_REJECT, "TRAILING_STOP_LOSS_ORDER_REJECT"},
	{TransactionType::STOP_LOSS_ORDER_REJECT, "STOP_LOSS_ORDER_REJECT"},
	{TransactionType::CREATE, "CREATE"},
	{TransactionType::ORDER_CLIENT_EXTENSIONS_MODIFY, "ORDER_CLIENT_EXTENSIONS_MODIFY"},
	{TransactionType::GUARANTEED_STOP_LOSS_ORDER, "GUARANTEED_STOP_LOSS_ORDER"},
	{TransactionType::CLIENT_CONFIGURE, "CLIENT_CONFIGURE"},
	{TransactionType::ORDER_FILL, "ORDER_FILL"},
	{TransactionType::LIMIT_ORDER, "LIMIT_ORDER"},
	{TransactionType::CLIENT_CONFIGURE_REJECT, "CLIENT_CONFIGURE_REJECT"},
	{TransactionType::ORDER_CLIENT_EXTENSIONS_MODIFY_REJECT, "ORDER_CLIENT_EXTENSIONS_MODIFY_REJECT"},
	{TransactionType::TRADE_CLIENT_EXTENSIONS_MODIFY, "TRADE_CLIENT_EXTENSIONS_MODIFY"},
	{TransactionType::DAILY_FINANCING, "DAILY_FINANCING"},
	{TransactionType::MARKET_ORDER_REJECT, "MARKET_ORDER_REJECT"},
	{TransactionType::CLOSE, "CLOSE"},
	{TransactionType::GUARANTEED_STOP_LOSS_ORDER_REJECT, "GUARANTEED_STOP_LOSS_ORDER_REJECT"},
	{TransactionType::MARGIN_CALL_ENTER, "MARGIN_CALL_ENTER"},
	{TransactionType::MARKET_ORDER, "MARKET_ORDER"},
	{TransactionType::TRADE_CLIENT_EXTENSIONS_MODIFY_REJECT, "TRADE_CLIENT_EXTENSIONS_MODIFY_REJECT"},
	{TransactionType::STOP_LOSS_ORDER, "STOP_LOSS_ORDER"},
	{TransactionType::MARGIN_CALL_EXTEND, "MARGIN_CALL_EXTEND"},
	{TransactionType::REOPEN, "REOPEN"},
	{TransactionType::DELAYED_TRADE_CLOSURE, "DELAYED_TRADE_CLOSURE"},
	{TransactionType::TRANSFER_FUNDS_REJECT, "TRANSFER_FUNDS_REJECT"},
	{TransactionType::STOP_ORDER, "STOP_ORDER"},
	{TransactionType::LIMIT_ORDER_REJECT, "LIMIT_ORDER_REJECT"},
	{TransactionType::MARKET_IF_TOUCHED_ORDER, "MARKET_IF_TOUCHED_ORDER"},
	{TransactionType::TAKE_PROFIT_ORDER_REJECT, "TAKE_PROFIT_ORDER_REJECT"},
	{TransactionType::MARKET_IF_TOUCHED_ORDER_REJECT, "MARKET_IF_TOUCHED_ORDER_REJECT"},
	{TransactionType::FIXED_PRICE_ORDER, "FIXED_PRICE_ORDER"},
	{TransactionType::TAKE_PROFIT_ORDER, "TAKE_PROFIT_ORDER"},
	{TransactionType::MARGIN_CALL_EXIT, "MARGIN_CALL_EXIT"},
	{TransactionType::STOP_ORDER_REJECT, "STOP_ORDER_REJECT"}
})

// FundingReason
//void to_json(nlohmann::json& j, const oanda::v20::transaction::FundingReason& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::FundingReason& e);
// FundingReason
NLOHMANN_JSON_SERIALIZE_ENUM(FundingReason, {
	{FundingReason::UNDEFINED, nullptr},
	{FundingReason::DIVISION_MIGRATION, "DIVISION_MIGRATION"},
	{FundingReason::ACCOUNT_TRANSFER, "ACCOUNT_TRANSFER"},
	{FundingReason::ADJUSTMENT, "ADJUSTMENT"},
	{FundingReason::SITE_MIGRATION, "SITE_MIGRATION"},
	{FundingReason::CLIENT_FUNDING, "CLIENT_FUNDING"}
})

// MarketOrderReason
//void to_json(nlohmann::json& j, const oanda::v20::transaction::MarketOrderReason& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::MarketOrderReason& e);
// MarketOrderReason
NLOHMANN_JSON_SERIALIZE_ENUM(MarketOrderReason, {
	{MarketOrderReason::UNDEFINED, nullptr},
	{MarketOrderReason::CLIENT_ORDER, "CLIENT_ORDER"},
	{MarketOrderReason::DELAYED_TRADE_CLOSE, "DELAYED_TRADE_CLOSE"},
	{MarketOrderReason::POSITION_CLOSEOUT, "POSITION_CLOSEOUT"},
	{MarketOrderReason::TRADE_CLOSE, "TRADE_CLOSE"},
	{MarketOrderReason::MARGIN_CLOSEOUT, "MARGIN_CLOSEOUT"}
})

// FixedPriceOrderReason
//void to_json(nlohmann::json& j, const oanda::v20::transaction::FixedPriceOrderReason& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::FixedPriceOrderReason& e);
// FixedPriceOrderReason
NLOHMANN_JSON_SERIALIZE_ENUM(FixedPriceOrderReason, {
	{FixedPriceOrderReason::UNDEFINED, nullptr},
	{FixedPriceOrderReason::TRADE_CLOSE_DIVISION_ACCOUNT_MIGRATION, "TRADE_CLOSE_DIVISION_ACCOUNT_MIGRATION"},
	{FixedPriceOrderReason::PLATFORM_ACCOUNT_MIGRATION, "PLATFORM_ACCOUNT_MIGRATION"},
	{FixedPriceOrderReason::TRADE_CLOSE_ADMINISTRATIVE_ACTION, "TRADE_CLOSE_ADMINISTRATIVE_ACTION"}
})

// LimitOrderReason
//void to_json(nlohmann::json& j, const oanda::v20::transaction::LimitOrderReason& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::LimitOrderReason& e);
// LimitOrderReason
NLOHMANN_JSON_SERIALIZE_ENUM(LimitOrderReason, {
	{LimitOrderReason::UNDEFINED, nullptr},
	{LimitOrderReason::CLIENT_ORDER, "CLIENT_ORDER"},
	{LimitOrderReason::REPLACEMENT, "REPLACEMENT"}
})

// StopOrderReason
//void to_json(nlohmann::json& j, const oanda::v20::transaction::StopOrderReason& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::StopOrderReason& e);
// StopOrderReason
NLOHMANN_JSON_SERIALIZE_ENUM(StopOrderReason, {
	{StopOrderReason::UNDEFINED, nullptr},
	{StopOrderReason::CLIENT_ORDER, "CLIENT_ORDER"},
	{StopOrderReason::REPLACEMENT, "REPLACEMENT"}
})

// MarketIfTouchedOrderReason
//void to_json(nlohmann::json& j, const oanda::v20::transaction::MarketIfTouchedOrderReason& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::MarketIfTouchedOrderReason& e);
// MarketIfTouchedOrderReason
NLOHMANN_JSON_SERIALIZE_ENUM(MarketIfTouchedOrderReason, {
	{MarketIfTouchedOrderReason::UNDEFINED, nullptr},
	{MarketIfTouchedOrderReason::CLIENT_ORDER, "CLIENT_ORDER"},
	{MarketIfTouchedOrderReason::REPLACEMENT, "REPLACEMENT"}
})

// TakeProfitOrderReason
//void to_json(nlohmann::json& j, const oanda::v20::transaction::TakeProfitOrderReason& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::TakeProfitOrderReason& e);
// TakeProfitOrderReason
NLOHMANN_JSON_SERIALIZE_ENUM(TakeProfitOrderReason, {
	{TakeProfitOrderReason::UNDEFINED, nullptr},
	{TakeProfitOrderReason::CLIENT_ORDER, "CLIENT_ORDER"},
	{TakeProfitOrderReason::ON_FILL, "ON_FILL"},
	{TakeProfitOrderReason::REPLACEMENT, "REPLACEMENT"}
})

// StopLossOrderReason
//void to_json(nlohmann::json& j, const oanda::v20::transaction::StopLossOrderReason& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::StopLossOrderReason& e);
// StopLossOrderReason
NLOHMANN_JSON_SERIALIZE_ENUM(StopLossOrderReason, {
	{StopLossOrderReason::UNDEFINED, nullptr},
	{StopLossOrderReason::CLIENT_ORDER, "CLIENT_ORDER"},
	{StopLossOrderReason::ON_FILL, "ON_FILL"},
	{StopLossOrderReason::REPLACEMENT, "REPLACEMENT"}
})

// GuaranteedStopLossOrderReason
//void to_json(nlohmann::json& j, const oanda::v20::transaction::GuaranteedStopLossOrderReason& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::GuaranteedStopLossOrderReason& e);
// GuaranteedStopLossOrderReason
NLOHMANN_JSON_SERIALIZE_ENUM(GuaranteedStopLossOrderReason, {
	{GuaranteedStopLossOrderReason::UNDEFINED, nullptr},
	{GuaranteedStopLossOrderReason::CLIENT_ORDER, "CLIENT_ORDER"},
	{GuaranteedStopLossOrderReason::ON_FILL, "ON_FILL"},
	{GuaranteedStopLossOrderReason::REPLACEMENT, "REPLACEMENT"}
})

// TrailingStopLossOrderReason
//void to_json(nlohmann::json& j, const oanda::v20::transaction::TrailingStopLossOrderReason& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::TrailingStopLossOrderReason& e);
// TrailingStopLossOrderReason
NLOHMANN_JSON_SERIALIZE_ENUM(TrailingStopLossOrderReason, {
	{TrailingStopLossOrderReason::UNDEFINED, nullptr},
	{TrailingStopLossOrderReason::CLIENT_ORDER, "CLIENT_ORDER"},
	{TrailingStopLossOrderReason::ON_FILL, "ON_FILL"},
	{TrailingStopLossOrderReason::REPLACEMENT, "REPLACEMENT"}
})

// OrderFillReason
//void to_json(nlohmann::json& j, const oanda::v20::transaction::OrderFillReason& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::OrderFillReason& e);
// OrderFillReason
NLOHMANN_JSON_SERIALIZE_ENUM(OrderFillReason, {
	{OrderFillReason::UNDEFINED, nullptr},
	{OrderFillReason::MARKET_ORDER_DELAYED_TRADE_CLOSE, "MARKET_ORDER_DELAYED_TRADE_CLOSE"},
	{OrderFillReason::STOP_ORDER, "STOP_ORDER"},
	{OrderFillReason::FIXED_PRICE_ORDER_ADMINISTRATIVE_ACTION, "FIXED_PRICE_ORDER_ADMINISTRATIVE_ACTION"},
	{OrderFillReason::MARKET_ORDER_MARGIN_CLOSEOUT, "MARKET_ORDER_MARGIN_CLOSEOUT"},
	{OrderFillReason::MARKET_ORDER_POSITION_CLOSEOUT, "MARKET_ORDER_POSITION_CLOSEOUT"},
	{OrderFillReason::MARKET_ORDER, "MARKET_ORDER"},
	{OrderFillReason::FIXED_PRICE_ORDER_DIVISION_ACCOUNT_MIGRATION, "FIXED_PRICE_ORDER_DIVISION_ACCOUNT_MIGRATION"},
	{OrderFillReason::FIXED_PRICE_ORDER_PLATFORM_ACCOUNT_MIGRATION, "FIXED_PRICE_ORDER_PLATFORM_ACCOUNT_MIGRATION"},
	{OrderFillReason::TAKE_PROFIT_ORDER, "TAKE_PROFIT_ORDER"},
	{OrderFillReason::MARKET_IF_TOUCHED_ORDER, "MARKET_IF_TOUCHED_ORDER"},
	{OrderFillReason::LIMIT_ORDER, "LIMIT_ORDER"},
	{OrderFillReason::GUARANTEED_STOP_LOSS_ORDER, "GUARANTEED_STOP_LOSS_ORDER"},
	{OrderFillReason::STOP_LOSS_ORDER, "STOP_LOSS_ORDER"},
	{OrderFillReason::FIXED_PRICE_ORDER, "FIXED_PRICE_ORDER"},
	{OrderFillReason::MARKET_ORDER_TRADE_CLOSE, "MARKET_ORDER_TRADE_CLOSE"},
	{OrderFillReason::TRAILING_STOP_LOSS_ORDER, "TRAILING_STOP_LOSS_ORDER"}
})

// OrderCancelReason
//void to_json(nlohmann::json& j, const oanda::v20::transaction::OrderCancelReason& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::OrderCancelReason& e);
// OrderCancelReason
NLOHMANN_JSON_SERIALIZE_ENUM(OrderCancelReason, {
	{OrderCancelReason::UNDEFINED, nullptr},
	{OrderCancelReason::ACCOUNT_ORDER_FILL_LOCKED, "ACCOUNT_ORDER_FILL_LOCKED"},
	{OrderCancelReason::INSUFFICIENT_MARGIN, "INSUFFICIENT_MARGIN"},
	{OrderCancelReason::TAKE_PROFIT_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED, "TAKE_PROFIT_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED"},
	{OrderCancelReason::GUARANTEED_STOP_LOSS_ON_FILL_ASK_HALTED, "GUARANTEED_STOP_LOSS_ON_FILL_ASK_HALTED"},
	{OrderCancelReason::GUARANTEED_STOP_LOSS_ON_FILL_NOT_ALLOWED, "GUARANTEED_STOP_LOSS_ON_FILL_NOT_ALLOWED"},
	{OrderCancelReason::TRAILING_STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS, "TRAILING_STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS"},
	{OrderCancelReason::FIFO_VIOLATION_SAFEGUARD_VIOLATION, "FIFO_VIOLATION_SAFEGUARD_VIOLATION"},
	{OrderCancelReason::ACCOUNT_NEW_POSITIONS_LOCKED, "ACCOUNT_NEW_POSITIONS_LOCKED"},
	{OrderCancelReason::MIGRATION, "MIGRATION"},
	{OrderCancelReason::GUARANTEED_STOP_LOSS_ON_FILL_LEVEL_RESTRICTION_VOLUME_EXCEEDED, "GUARANTEED_STOP_LOSS_ON_FILL_LEVEL_RESTRICTION_VOLUME_EXCEEDED"},
	{OrderCancelReason::GUARANTEED_STOP_LOSS_ON_FILL_REQUIRED, "GUARANTEED_STOP_LOSS_ON_FILL_REQUIRED"},
	{OrderCancelReason::INSTRUMENT_BID_REDUCE_ONLY, "INSTRUMENT_BID_REDUCE_ONLY"},
	{OrderCancelReason::ORDERS_ON_FILL_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION, "ORDERS_ON_FILL_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION"},
	{OrderCancelReason::STOP_LOSS_ON_FILL_LOSS, "STOP_LOSS_ON_FILL_LOSS"},
	{OrderCancelReason::LINKED_TRADE_CLOSED, "LINKED_TRADE_CLOSED"},
	{OrderCancelReason::ACCOUNT_POSITION_VALUE_LIMIT_EXCEEDED, "ACCOUNT_POSITION_VALUE_LIMIT_EXCEEDED"},
	{OrderCancelReason::FIFO_VIOLATION_SAFEGUARD_PARTIAL_CLOSE_VIOLATION, "FIFO_VIOLATION_SAFEGUARD_PARTIAL_CLOSE_VIOLATION"},
	{OrderCancelReason::POSITION_CLOSEOUT_FAILED, "POSITION_CLOSEOUT_FAILED"},
	{OrderCancelReason::TIME_IN_FORCE_EXPIRED, "TIME_IN_FORCE_EXPIRED"},
	{OrderCancelReason::PENDING_ORDERS_ALLOWED_EXCEEDED, "PENDING_ORDERS_ALLOWED_EXCEEDED"},
	{OrderCancelReason::STOP_LOSS_ON_FILL_GUARANTEED_ASK_HALTED, "STOP_LOSS_ON_FILL_GUARANTEED_ASK_HALTED"},
	{OrderCancelReason::STOP_LOSS_ON_FILL_REQUIRED, "STOP_LOSS_ON_FILL_REQUIRED"},
	{OrderCancelReason::GUARANTEED_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID, "GUARANTEED_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID"},
	{OrderCancelReason::TAKE_PROFIT_ON_FILL_GTD_TIMESTAMP_IN_PAST, "TAKE_PROFIT_ON_FILL_GTD_TIMESTAMP_IN_PAST"},
	{OrderCancelReason::GUARANTEED_STOP_LOSS_ON_FILL_HEDGING_NOT_ALLOWED, "GUARANTEED_STOP_LOSS_ON_FILL_HEDGING_NOT_ALLOWED"},
	{OrderCancelReason::INSTRUMENT_BID_HALTED, "INSTRUMENT_BID_HALTED"},
	{OrderCancelReason::GUARANTEED_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED, "GUARANTEED_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED"},
	{OrderCancelReason::TAKE_PROFIT_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS, "TAKE_PROFIT_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS"},
	{OrderCancelReason::GUARANTEED_STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID, "GUARANTEED_STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID"},
	{OrderCancelReason::GUARANTEED_STOP_LOSS_ON_FILL_BID_HALTED, "GUARANTEED_STOP_LOSS_ON_FILL_BID_HALTED"},
	{OrderCancelReason::STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID, "STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID"},
	{OrderCancelReason::GUARANTEED_STOP_LOSS_ON_FILL_LEVEL_RESTRICTION_PRICE_RANGE_EXCEEDED, "GUARANTEED_STOP_LOSS_ON_FILL_LEVEL_RESTRICTION_PRICE_RANGE_EXCEEDED"},
	{OrderCancelReason::STOP_LOSS_ON_FILL_GUARANTEED_REQUIRED, "STOP_LOSS_ON_FILL_GUARANTEED_REQUIRED"},
	{OrderCancelReason::POSITION_SIZE_EXCEEDED, "POSITION_SIZE_EXCEEDED"},
	{OrderCancelReason::CLIENT_REQUEST_REPLACED, "CLIENT_REQUEST_REPLACED"},
	{OrderCancelReason::GUARANTEED_STOP_LOSS_ON_FILL_MINIMUM_DISTANCE_NOT_MET, "GUARANTEED_STOP_LOSS_ON_FILL_MINIMUM_DISTANCE_NOT_MET"},
	{OrderCancelReason::STOP_LOSS_ON_FILL_GUARANTEED_LEVEL_RESTRICTION_EXCEEDED, "STOP_LOSS_ON_FILL_GUARANTEED_LEVEL_RESTRICTION_EXCEEDED"},
	{OrderCancelReason::OPEN_TRADES_ALLOWED_EXCEEDED, "OPEN_TRADES_ALLOWED_EXCEEDED"},
	{OrderCancelReason::BOUNDS_VIOLATION, "BOUNDS_VIOLATION"},
	{OrderCancelReason::STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED, "STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED"},
	{OrderCancelReason::GUARANTEED_STOP_LOSS_ON_FILL_LOSS, "GUARANTEED_STOP_LOSS_ON_FILL_LOSS"},
	{OrderCancelReason::INTERNAL_SERVER_ERROR, "INTERNAL_SERVER_ERROR"},
	{OrderCancelReason::DIVIDEND_ADJUSTMENT_REPLACED, "DIVIDEND_ADJUSTMENT_REPLACED"},
	{OrderCancelReason::STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS, "STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS"},
	{OrderCancelReason::GUARANTEED_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST, "GUARANTEED_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST"},
	{OrderCancelReason::CLIENT_TRADE_ID_ALREADY_EXISTS, "CLIENT_TRADE_ID_ALREADY_EXISTS"},
	{OrderCancelReason::STOP_LOSS_ON_FILL_GUARANTEED_MINIMUM_DISTANCE_NOT_MET, "STOP_LOSS_ON_FILL_GUARANTEED_MINIMUM_DISTANCE_NOT_MET"},
	{OrderCancelReason::FIFO_VIOLATION, "FIFO_VIOLATION"},
	{OrderCancelReason::STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST, "STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST"},
	{OrderCancelReason::STOP_LOSS_ON_FILL_GUARANTEED_HEDGING_NOT_ALLOWED, "STOP_LOSS_ON_FILL_GUARANTEED_HEDGING_NOT_ALLOWED"},
	{OrderCancelReason::STOP_LOSS_ON_FILL_GUARANTEED_BID_HALTED, "STOP_LOSS_ON_FILL_GUARANTEED_BID_HALTED"},
	{OrderCancelReason::INSTRUMENT_ASK_REDUCE_ONLY, "INSTRUMENT_ASK_REDUCE_ONLY"},
	{OrderCancelReason::HEDGING_GSLO_VIOLATION, "HEDGING_GSLO_VIOLATION"},
	{OrderCancelReason::MARKET_HALTED, "MARKET_HALTED"},
	{OrderCancelReason::STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID, "STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID"},
	{OrderCancelReason::TRAILING_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST, "TRAILING_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST"},
	{OrderCancelReason::GUARANTEED_STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS, "GUARANTEED_STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS"},
	{OrderCancelReason::STOP_LOSS_ON_FILL_GUARANTEED_NOT_ALLOWED, "STOP_LOSS_ON_FILL_GUARANTEED_NOT_ALLOWED"},
	{OrderCancelReason::ACCOUNT_LOCKED, "ACCOUNT_LOCKED"},
	{OrderCancelReason::LOSING_TAKE_PROFIT, "LOSING_TAKE_PROFIT"},
	{OrderCancelReason::TAKE_PROFIT_ON_FILL_LOSS, "TAKE_PROFIT_ON_FILL_LOSS"},
	{OrderCancelReason::INSTRUMENT_ASK_HALTED, "INSTRUMENT_ASK_HALTED"},
	{OrderCancelReason::CLIENT_REQUEST, "CLIENT_REQUEST"},
	{OrderCancelReason::INSUFFICIENT_LIQUIDITY, "INSUFFICIENT_LIQUIDITY"},
	{OrderCancelReason::ACCOUNT_ORDER_CREATION_LOCKED, "ACCOUNT_ORDER_CREATION_LOCKED"}
})

// OpenTradeDividendAdjustment
void to_json(nlohmann::json& j, const oanda::v20::transaction::OpenTradeDividendAdjustment& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::OpenTradeDividendAdjustment& p);

// ClientExtensions
void to_json(nlohmann::json& j, const oanda::v20::transaction::ClientExtensions& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::ClientExtensions& p);

// TakeProfitDetails
void to_json(nlohmann::json& j, const oanda::v20::transaction::TakeProfitDetails& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::TakeProfitDetails& p);

// StopLossDetails
void to_json(nlohmann::json& j, const oanda::v20::transaction::StopLossDetails& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::StopLossDetails& p);

// GuaranteedStopLossDetails
void to_json(nlohmann::json& j, const oanda::v20::transaction::GuaranteedStopLossDetails& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::GuaranteedStopLossDetails& p);

// TrailingStopLossDetails
void to_json(nlohmann::json& j, const oanda::v20::transaction::TrailingStopLossDetails& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::TrailingStopLossDetails& p);

// TradeOpen
void to_json(nlohmann::json& j, const oanda::v20::transaction::TradeOpen& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::TradeOpen& p);

// TradeReduce
void to_json(nlohmann::json& j, const oanda::v20::transaction::TradeReduce& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::TradeReduce& p);

// MarketOrderTradeClose
void to_json(nlohmann::json& j, const oanda::v20::transaction::MarketOrderTradeClose& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::MarketOrderTradeClose& p);

// MarketOrderMarginCloseout
void to_json(nlohmann::json& j, const oanda::v20::transaction::MarketOrderMarginCloseout& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::MarketOrderMarginCloseout& p);

// MarketOrderMarginCloseoutReason
//void to_json(nlohmann::json& j, const oanda::v20::transaction::MarketOrderMarginCloseoutReason& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::MarketOrderMarginCloseoutReason& e);
// MarketOrderMarginCloseoutReason
NLOHMANN_JSON_SERIALIZE_ENUM(MarketOrderMarginCloseoutReason, {
	{MarketOrderMarginCloseoutReason::UNDEFINED, nullptr},
	{MarketOrderMarginCloseoutReason::REGULATORY_MARGIN_CALL_VIOLATION, "REGULATORY_MARGIN_CALL_VIOLATION"},
	{MarketOrderMarginCloseoutReason::REGULATORY_MARGIN_CHECK_VIOLATION, "REGULATORY_MARGIN_CHECK_VIOLATION"},
	{MarketOrderMarginCloseoutReason::MARGIN_CHECK_VIOLATION, "MARGIN_CHECK_VIOLATION"}
})

// MarketOrderDelayedTradeClose
void to_json(nlohmann::json& j, const oanda::v20::transaction::MarketOrderDelayedTradeClose& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::MarketOrderDelayedTradeClose& p);

// MarketOrderPositionCloseout
void to_json(nlohmann::json& j, const oanda::v20::transaction::MarketOrderPositionCloseout& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::MarketOrderPositionCloseout& p);

// LiquidityRegenerationSchedule
void to_json(nlohmann::json& j, const oanda::v20::transaction::LiquidityRegenerationSchedule& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::LiquidityRegenerationSchedule& p);

// LiquidityRegenerationScheduleStep
void to_json(nlohmann::json& j, const oanda::v20::transaction::LiquidityRegenerationScheduleStep& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::LiquidityRegenerationScheduleStep& p);

// OpenTradeFinancing
void to_json(nlohmann::json& j, const oanda::v20::transaction::OpenTradeFinancing& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::OpenTradeFinancing& p);

// PositionFinancing
void to_json(nlohmann::json& j, const oanda::v20::transaction::PositionFinancing& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::PositionFinancing& p);

// TransactionRejectReason
//void to_json(nlohmann::json& j, const oanda::v20::transaction::TransactionRejectReason& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::TransactionRejectReason& e);
// TransactionRejectReason
NLOHMANN_JSON_SERIALIZE_ENUM(TransactionRejectReason, {
	{TransactionRejectReason::UNDEFINED, nullptr},
	{TransactionRejectReason::STOP_LOSS_ORDER_GUARANTEED_MINIMUM_DISTANCE_NOT_MET, "STOP_LOSS_ORDER_GUARANTEED_MINIMUM_DISTANCE_NOT_MET"},
	{TransactionRejectReason::INSUFFICIENT_MARGIN, "INSUFFICIENT_MARGIN"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_PRICE_MISSING, "GUARANTEED_STOP_LOSS_ON_FILL_PRICE_MISSING"},
	{TransactionRejectReason::TAKE_PROFIT_ON_FILL_PRICE_PRECISION_EXCEEDED, "TAKE_PROFIT_ON_FILL_PRICE_PRECISION_EXCEEDED"},
	{TransactionRejectReason::UNITS_PRECISION_EXCEEDED, "UNITS_PRECISION_EXCEEDED"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_PRICE_AND_DISTANCE_BOTH_MISSING, "GUARANTEED_STOP_LOSS_ORDER_PRICE_AND_DISTANCE_BOTH_MISSING"},
	{TransactionRejectReason::STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION, "STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION"},
	{TransactionRejectReason::TAKE_PROFIT_ON_FILL_PRICE_INVALID, "TAKE_PROFIT_ON_FILL_PRICE_INVALID"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ON_FILL_CLIENT_ORDER_TAG_INVALID, "TRAILING_STOP_LOSS_ON_FILL_CLIENT_ORDER_TAG_INVALID"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_CLIENT_ORDER_COMMENT_INVALID, "GUARANTEED_STOP_LOSS_ON_FILL_CLIENT_ORDER_COMMENT_INVALID"},
	{TransactionRejectReason::STOP_LOSS_ORDER_GUARANTEED_PRICE_WITHIN_SPREAD, "STOP_LOSS_ORDER_GUARANTEED_PRICE_WITHIN_SPREAD"},
	{TransactionRejectReason::PRICE_DISTANCE_MAXIMUM_EXCEEDED, "PRICE_DISTANCE_MAXIMUM_EXCEEDED"},
	{TransactionRejectReason::POSITION_AGGREGATION_MODE_INVALID, "POSITION_AGGREGATION_MODE_INVALID"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_NOT_ALLOWED, "GUARANTEED_STOP_LOSS_ON_FILL_NOT_ALLOWED"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_CREATE_VIOLATION, "GUARANTEED_STOP_LOSS_ORDER_CREATE_VIOLATION"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_NOT_REPLACEABLE, "GUARANTEED_STOP_LOSS_ORDER_NOT_REPLACEABLE"},
	{TransactionRejectReason::STOP_LOSS_ORDER_PRICE_AND_DISTANCE_BOTH_MISSING, "STOP_LOSS_ORDER_PRICE_AND_DISTANCE_BOTH_MISSING"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_GSLO_EXCLUDES_OTHERS_VIOLATION, "GUARANTEED_STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_GSLO_EXCLUDES_OTHERS_VIOLATION"},
	{TransactionRejectReason::ACCOUNT_DEPOSIT_LOCKED, "ACCOUNT_DEPOSIT_LOCKED"},
	{TransactionRejectReason::CLIENT_TRADE_TAG_INVALID, "CLIENT_TRADE_TAG_INVALID"},
	{TransactionRejectReason::TAKE_PROFIT_ON_FILL_TIME_IN_FORCE_INVALID, "TAKE_PROFIT_ON_FILL_TIME_IN_FORCE_INVALID"},
	{TransactionRejectReason::TRADE_ID_UNSPECIFIED, "TRADE_ID_UNSPECIFIED"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ORDER_ALREADY_EXISTS, "TRAILING_STOP_LOSS_ORDER_ALREADY_EXISTS"},
	{TransactionRejectReason::STOP_LOSS_ORDER_GUARANTEED_LEVEL_RESTRICTION_EXCEEDED, "STOP_LOSS_ORDER_GUARANTEED_LEVEL_RESTRICTION_EXCEEDED"},
	{TransactionRejectReason::TAKE_PROFIT_ON_FILL_TRIGGER_CONDITION_INVALID, "TAKE_PROFIT_ON_FILL_TRIGGER_CONDITION_INVALID"},
	{TransactionRejectReason::REPLACING_ORDER_INVALID, "REPLACING_ORDER_INVALID"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_INVALID, "GUARANTEED_STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_INVALID"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_PRICE_AND_DISTANCE_BOTH_SPECIFIED, "STOP_LOSS_ON_FILL_PRICE_AND_DISTANCE_BOTH_SPECIFIED"},
	{TransactionRejectReason::CLIENT_TRADE_ID_INVALID, "CLIENT_TRADE_ID_INVALID"},
	{TransactionRejectReason::CLOSE_TRADE_PARTIAL_UNITS_MISSING, "CLOSE_TRADE_PARTIAL_UNITS_MISSING"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_DISTANCE_INVALID, "STOP_LOSS_ON_FILL_DISTANCE_INVALID"},
	{TransactionRejectReason::TRIGGER_CONDITION_INVALID, "TRIGGER_CONDITION_INVALID"},
	{TransactionRejectReason::CLIENT_ORDER_ID_ALREADY_EXISTS, "CLIENT_ORDER_ID_ALREADY_EXISTS"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_PRICE_WITHIN_SPREAD, "GUARANTEED_STOP_LOSS_ORDER_PRICE_WITHIN_SPREAD"},
	{TransactionRejectReason::TIME_IN_FORCE_MISSING, "TIME_IN_FORCE_MISSING"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_LEVEL_RESTRICTION_VOLUME_EXCEEDED, "GUARANTEED_STOP_LOSS_ON_FILL_LEVEL_RESTRICTION_VOLUME_EXCEEDED"},
	{TransactionRejectReason::UNITS_MINIMUM_NOT_MET, "UNITS_MINIMUM_NOT_MET"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_HALTED_TIGHTEN_VIOLATION, "GUARANTEED_STOP_LOSS_ORDER_HALTED_TIGHTEN_VIOLATION"},
	{TransactionRejectReason::UNITS_MISSING, "UNITS_MISSING"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_REQUIRED, "GUARANTEED_STOP_LOSS_ON_FILL_REQUIRED"},
	{TransactionRejectReason::TRADE_DOESNT_EXIST, "TRADE_DOESNT_EXIST"},
	{TransactionRejectReason::PRICE_INVALID, "PRICE_INVALID"},
	{TransactionRejectReason::ORDER_PARTIAL_FILL_OPTION_MISSING, "ORDER_PARTIAL_FILL_OPTION_MISSING"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_MISSING, "TRAILING_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_MISSING"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_TRIGGER_CONDITION_MISSING, "STOP_LOSS_ON_FILL_TRIGGER_CONDITION_MISSING"},
	{TransactionRejectReason::ORDERS_ON_FILL_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION, "ORDERS_ON_FILL_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION"},
	{TransactionRejectReason::ORDER_ID_UNSPECIFIED, "ORDER_ID_UNSPECIFIED"},
	{TransactionRejectReason::MARGIN_RATE_WOULD_TRIGGER_CLOSEOUT, "MARGIN_RATE_WOULD_TRIGGER_CLOSEOUT"},
	{TransactionRejectReason::ORDER_DOESNT_EXIST, "ORDER_DOESNT_EXIST"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_NOT_ALLOWED, "GUARANTEED_STOP_LOSS_ORDER_NOT_ALLOWED"},
	{TransactionRejectReason::STOP_LOSS_ORDER_PRICE_AND_DISTANCE_BOTH_SPECIFIED, "STOP_LOSS_ORDER_PRICE_AND_DISTANCE_BOTH_SPECIFIED"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_DISTANCE_INVALID, "GUARANTEED_STOP_LOSS_ON_FILL_DISTANCE_INVALID"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_LEVEL_RESTRICTION_VOLUME_EXCEEDED, "GUARANTEED_STOP_LOSS_ORDER_LEVEL_RESTRICTION_VOLUME_EXCEEDED"},
	{TransactionRejectReason::ORDER_IDENTIFIER_INCONSISTENCY, "ORDER_IDENTIFIER_INCONSISTENCY"},
	{TransactionRejectReason::PRICE_BOUND_INVALID, "PRICE_BOUND_INVALID"},
	{TransactionRejectReason::CLOSE_TRADE_TYPE_MISSING, "CLOSE_TRADE_TYPE_MISSING"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MINIMUM_NOT_MET, "TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MINIMUM_NOT_MET"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION, "TRAILING_STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_PRICE_AND_DISTANCE_BOTH_MISSING, "GUARANTEED_STOP_LOSS_ON_FILL_PRICE_AND_DISTANCE_BOTH_MISSING"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_PRICE_PRECISION_EXCEEDED, "GUARANTEED_STOP_LOSS_ON_FILL_PRICE_PRECISION_EXCEEDED"},
	{TransactionRejectReason::TAKE_PROFIT_ON_FILL_TIME_IN_FORCE_MISSING, "TAKE_PROFIT_ON_FILL_TIME_IN_FORCE_MISSING"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_CLIENT_ORDER_TAG_INVALID, "GUARANTEED_STOP_LOSS_ON_FILL_CLIENT_ORDER_TAG_INVALID"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_CLIENT_ORDER_TAG_INVALID, "STOP_LOSS_ON_FILL_CLIENT_ORDER_TAG_INVALID"},
	{TransactionRejectReason::TAKE_PROFIT_ON_FILL_TRIGGER_CONDITION_MISSING, "TAKE_PROFIT_ON_FILL_TRIGGER_CONDITION_MISSING"},
	{TransactionRejectReason::ORDER_CANCEL_WOULD_TRIGGER_CLOSEOUT, "ORDER_CANCEL_WOULD_TRIGGER_CLOSEOUT"},
	{TransactionRejectReason::OCA_ORDER_IDS_STOP_LOSS_NOT_ALLOWED, "OCA_ORDER_IDS_STOP_LOSS_NOT_ALLOWED"},
	{TransactionRejectReason::PENDING_ORDERS_ALLOWED_EXCEEDED, "PENDING_ORDERS_ALLOWED_EXCEEDED"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_REQUIRED_FOR_PENDING_ORDER, "STOP_LOSS_ON_FILL_REQUIRED_FOR_PENDING_ORDER"},
	{TransactionRejectReason::STOP_LOSS_ORDER_GUARANTEED_HALTED_TIGHTEN_VIOLATION, "STOP_LOSS_ORDER_GUARANTEED_HALTED_TIGHTEN_VIOLATION"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_GSLO_EXCLUDES_OTHERS_VIOLATION, "TRAILING_STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_GSLO_EXCLUDES_OTHERS_VIOLATION"},
	{TransactionRejectReason::INSTRUMENT_MISSING, "INSTRUMENT_MISSING"},
	{TransactionRejectReason::TRIGGER_CONDITION_MISSING, "TRIGGER_CONDITION_MISSING"},
	{TransactionRejectReason::PRICE_DISTANCE_MINIMUM_NOT_MET, "PRICE_DISTANCE_MINIMUM_NOT_MET"},
	{TransactionRejectReason::TAKE_PROFIT_ON_FILL_GTD_TIMESTAMP_MISSING, "TAKE_PROFIT_ON_FILL_GTD_TIMESTAMP_MISSING"},
	{TransactionRejectReason::TAKE_PROFIT_ON_FILL_PRICE_MISSING, "TAKE_PROFIT_ON_FILL_PRICE_MISSING"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID, "GUARANTEED_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID"},
	{TransactionRejectReason::TAKE_PROFIT_ON_FILL_GTD_TIMESTAMP_IN_PAST, "TAKE_PROFIT_ON_FILL_GTD_TIMESTAMP_IN_PAST"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_HALTED_CREATE_VIOLATION, "GUARANTEED_STOP_LOSS_ORDER_HALTED_CREATE_VIOLATION"},
	{TransactionRejectReason::PRICE_DISTANCE_INVALID, "PRICE_DISTANCE_INVALID"},
	{TransactionRejectReason::MARGIN_RATE_INVALID, "MARGIN_RATE_INVALID"},
	{TransactionRejectReason::PRICE_MISSING, "PRICE_MISSING"},
	{TransactionRejectReason::STOP_LOSS_ORDER_GUARANTEED_HALTED_CREATE_VIOLATION, "STOP_LOSS_ORDER_GUARANTEED_HALTED_CREATE_VIOLATION"},
	{TransactionRejectReason::CLOSEOUT_POSITION_PARTIAL_UNITS_MISSING, "CLOSEOUT_POSITION_PARTIAL_UNITS_MISSING"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_INVALID, "TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_INVALID"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_PRICE_PRECISION_EXCEEDED, "STOP_LOSS_ON_FILL_PRICE_PRECISION_EXCEEDED"},
	{TransactionRejectReason::INSTRUMENT_PRICE_UNKNOWN, "INSTRUMENT_PRICE_UNKNOWN"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED, "GUARANTEED_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED"},
	{TransactionRejectReason::TAKE_PROFIT_ORDER_WOULD_VIOLATE_FIFO_VIOLATION_SAFEGUARD, "TAKE_PROFIT_ORDER_WOULD_VIOLATE_FIFO_VIOLATION_SAFEGUARD"},
	{TransactionRejectReason::CLOSEOUT_POSITION_REJECT, "CLOSEOUT_POSITION_REJECT"},
	{TransactionRejectReason::CLIENT_ORDER_COMMENT_INVALID, "CLIENT_ORDER_COMMENT_INVALID"},
	{TransactionRejectReason::AMOUNT_INVALID, "AMOUNT_INVALID"},
	{TransactionRejectReason::CLOSE_TRADE_UNITS_EXCEED_TRADE_SIZE, "CLOSE_TRADE_UNITS_EXCEED_TRADE_SIZE"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_HALTED_NOT_REPLACEABLE, "GUARANTEED_STOP_LOSS_ORDER_HALTED_NOT_REPLACEABLE"},
	{TransactionRejectReason::TIME_IN_FORCE_GTD_TIMESTAMP_IN_PAST, "TIME_IN_FORCE_GTD_TIMESTAMP_IN_PAST"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID, "GUARANTEED_STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID"},
	{TransactionRejectReason::TAKE_PROFIT_ON_FILL_CLIENT_ORDER_COMMENT_INVALID, "TAKE_PROFIT_ON_FILL_CLIENT_ORDER_COMMENT_INVALID"},
	{TransactionRejectReason::TRADE_IDENTIFIER_INCONSISTENCY, "TRADE_IDENTIFIER_INCONSISTENCY"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_WOULD_VIOLATE_FIFO_VIOLATION_SAFEGUARD, "GUARANTEED_STOP_LOSS_ORDER_WOULD_VIOLATE_FIFO_VIOLATION_SAFEGUARD"},
	{TransactionRejectReason::STOP_LOSS_ORDER_NOT_CANCELABLE, "STOP_LOSS_ORDER_NOT_CANCELABLE"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_PRICE_INVALID, "STOP_LOSS_ON_FILL_PRICE_INVALID"},
	{TransactionRejectReason::TAKE_PROFIT_ORDER_ALREADY_EXISTS, "TAKE_PROFIT_ORDER_ALREADY_EXISTS"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID, "STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID"},
	{TransactionRejectReason::PRICE_BOUND_PRECISION_EXCEEDED, "PRICE_BOUND_PRECISION_EXCEEDED"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_LEVEL_RESTRICTION_PRICE_RANGE_EXCEEDED, "GUARANTEED_STOP_LOSS_ON_FILL_LEVEL_RESTRICTION_PRICE_RANGE_EXCEEDED"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_GUARANTEED_REQUIRED, "STOP_LOSS_ON_FILL_GUARANTEED_REQUIRED"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_CLIENT_ORDER_COMMENT_INVALID, "STOP_LOSS_ON_FILL_CLIENT_ORDER_COMMENT_INVALID"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION, "GUARANTEED_STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION"},
	{TransactionRejectReason::STOP_LOSS_ORDER_WOULD_VIOLATE_FIFO_VIOLATION_SAFEGUARD, "STOP_LOSS_ORDER_WOULD_VIOLATE_FIFO_VIOLATION_SAFEGUARD"},
	{TransactionRejectReason::STOP_LOSS_ORDER_GUARANTEED_NOT_ALLOWED, "STOP_LOSS_ORDER_GUARANTEED_NOT_ALLOWED"},
	{TransactionRejectReason::ORDER_FILL_POSITION_ACTION_INVALID, "ORDER_FILL_POSITION_ACTION_INVALID"},
	{TransactionRejectReason::ACCOUNT_WITHDRAWAL_LOCKED, "ACCOUNT_WITHDRAWAL_LOCKED"},
	{TransactionRejectReason::CLOSEOUT_POSITION_DOESNT_EXIST, "CLOSEOUT_POSITION_DOESNT_EXIST"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_REQUIRED, "GUARANTEED_STOP_LOSS_ORDER_REQUIRED"},
	{TransactionRejectReason::TIME_IN_FORCE_GTD_TIMESTAMP_MISSING, "TIME_IN_FORCE_GTD_TIMESTAMP_MISSING"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_MISSING, "GUARANTEED_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_MISSING"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_DISTANCE_PRECISION_EXCEEDED, "GUARANTEED_STOP_LOSS_ON_FILL_DISTANCE_PRECISION_EXCEEDED"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_MINIMUM_DISTANCE_NOT_MET, "GUARANTEED_STOP_LOSS_ON_FILL_MINIMUM_DISTANCE_NOT_MET"},
	{TransactionRejectReason::CLIENT_ORDER_TAG_INVALID, "CLIENT_ORDER_TAG_INVALID"},
	{TransactionRejectReason::PRICE_DISTANCE_MISSING, "PRICE_DISTANCE_MISSING"},
	{TransactionRejectReason::ORDERS_ON_FILL_DUPLICATE_CLIENT_ORDER_IDS, "ORDERS_ON_FILL_DUPLICATE_CLIENT_ORDER_IDS"},
	{TransactionRejectReason::ADMIN_CONFIGURE_DATA_MISSING, "ADMIN_CONFIGURE_DATA_MISSING"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID, "TRAILING_STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID"},
	{TransactionRejectReason::INVALID_REISSUE_IMMEDIATE_PARTIAL_FILL, "INVALID_REISSUE_IMMEDIATE_PARTIAL_FILL"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_GUARANTEED_LEVEL_RESTRICTION_EXCEEDED, "STOP_LOSS_ON_FILL_GUARANTEED_LEVEL_RESTRICTION_EXCEEDED"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_HEDGING_NOT_ALLOWED, "GUARANTEED_STOP_LOSS_ORDER_HEDGING_NOT_ALLOWED"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_PRICE_AND_DISTANCE_BOTH_MISSING, "STOP_LOSS_ON_FILL_PRICE_AND_DISTANCE_BOTH_MISSING"},
	{TransactionRejectReason::CLOSEOUT_POSITION_INCOMPLETE_SPECIFICATION, "CLOSEOUT_POSITION_INCOMPLETE_SPECIFICATION"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_DISTANCE_PRECISION_EXCEEDED, "STOP_LOSS_ON_FILL_DISTANCE_PRECISION_EXCEEDED"},
	{TransactionRejectReason::STOP_LOSS_ORDER_GUARANTEED_HEDGING_NOT_ALLOWED, "STOP_LOSS_ORDER_GUARANTEED_HEDGING_NOT_ALLOWED"},
	{TransactionRejectReason::MARKUP_GROUP_ID_INVALID, "MARKUP_GROUP_ID_INVALID"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED, "STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED"},
	{TransactionRejectReason::INTERNAL_SERVER_ERROR, "INTERNAL_SERVER_ERROR"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_TIME_IN_FORCE_MISSING, "GUARANTEED_STOP_LOSS_ON_FILL_TIME_IN_FORCE_MISSING"},
	{TransactionRejectReason::STOP_LOSS_ORDER_GUARANTEED_REQUIRED, "STOP_LOSS_ORDER_GUARANTEED_REQUIRED"},
	{TransactionRejectReason::PRICE_DISTANCE_PRECISION_EXCEEDED, "PRICE_DISTANCE_PRECISION_EXCEEDED"},
	{TransactionRejectReason::CLIENT_CONFIGURE_DATA_MISSING, "CLIENT_CONFIGURE_DATA_MISSING"},
	{TransactionRejectReason::PRICE_PRECISION_EXCEEDED, "PRICE_PRECISION_EXCEEDED"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_HALTED_NOT_CANCELABLE, "GUARANTEED_STOP_LOSS_ORDER_HALTED_NOT_CANCELABLE"},
	{TransactionRejectReason::INSTRUMENT_UNKNOWN, "INSTRUMENT_UNKNOWN"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_NOT_CANCELABLE, "GUARANTEED_STOP_LOSS_ORDER_NOT_CANCELABLE"},
	{TransactionRejectReason::ACCOUNT_ORDER_CANCEL_LOCKED, "ACCOUNT_ORDER_CANCEL_LOCKED"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_TIME_IN_FORCE_MISSING, "STOP_LOSS_ON_FILL_TIME_IN_FORCE_MISSING"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_MISSING, "GUARANTEED_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_MISSING"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_TIGHTEN_VIOLATION, "GUARANTEED_STOP_LOSS_ORDER_TIGHTEN_VIOLATION"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MISSING, "TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MISSING"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST, "GUARANTEED_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST"},
	{TransactionRejectReason::TAKE_PROFIT_ON_FILL_CLIENT_ORDER_ID_INVALID, "TAKE_PROFIT_ON_FILL_CLIENT_ORDER_ID_INVALID"},
	{TransactionRejectReason::UNITS_LIMIT_EXCEEDED, "UNITS_LIMIT_EXCEEDED"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_PRICE_AND_DISTANCE_BOTH_SPECIFIED, "GUARANTEED_STOP_LOSS_ON_FILL_PRICE_AND_DISTANCE_BOTH_SPECIFIED"},
	{TransactionRejectReason::STOP_LOSS_ORDER_NOT_REPLACEABLE, "STOP_LOSS_ORDER_NOT_REPLACEABLE"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ORDERS_NOT_SUPPORTED, "TRAILING_STOP_LOSS_ORDERS_NOT_SUPPORTED"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_PRICE_INVALID, "GUARANTEED_STOP_LOSS_ON_FILL_PRICE_INVALID"},
	{TransactionRejectReason::ORDER_FILL_POSITION_ACTION_MISSING, "ORDER_FILL_POSITION_ACTION_MISSING"},
	{TransactionRejectReason::TIME_IN_FORCE_INVALID, "TIME_IN_FORCE_INVALID"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_GTD_TIMESTAMP_MISSING, "STOP_LOSS_ON_FILL_GTD_TIMESTAMP_MISSING"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_GUARANTEED_MINIMUM_DISTANCE_NOT_MET, "STOP_LOSS_ON_FILL_GUARANTEED_MINIMUM_DISTANCE_NOT_MET"},
	{TransactionRejectReason::CLIENT_TRADE_ID_ALREADY_EXISTS, "CLIENT_TRADE_ID_ALREADY_EXISTS"},
	{TransactionRejectReason::CLIENT_ORDER_ID_INVALID, "CLIENT_ORDER_ID_INVALID"},
	{TransactionRejectReason::AMOUNT_MISSING, "AMOUNT_MISSING"},
	{TransactionRejectReason::INSUFFICIENT_FUNDS, "INSUFFICIENT_FUNDS"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST, "STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST"},
	{TransactionRejectReason::CLOSEOUT_POSITION_UNITS_EXCEED_POSITION_SIZE, "CLOSEOUT_POSITION_UNITS_EXCEED_POSITION_SIZE"},
	{TransactionRejectReason::ORDERS_ON_FILL_RMO_MUTUAL_EXCLUSIVITY_GSLO_EXCLUDES_OTHERS_VIOLATION, "ORDERS_ON_FILL_RMO_MUTUAL_EXCLUSIVITY_GSLO_EXCLUDES_OTHERS_VIOLATION"},
	{TransactionRejectReason::CLIENT_TRADE_COMMENT_INVALID, "CLIENT_TRADE_COMMENT_INVALID"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ON_FILL_TIME_IN_FORCE_MISSING, "TRAILING_STOP_LOSS_ON_FILL_TIME_IN_FORCE_MISSING"},
	{TransactionRejectReason::STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_GSLO_EXCLUDES_OTHERS_VIOLATION, "STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_GSLO_EXCLUDES_OTHERS_VIOLATION"},
	{TransactionRejectReason::STOP_LOSS_ORDER_ALREADY_EXISTS, "STOP_LOSS_ORDER_ALREADY_EXISTS"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_PRICE_MISSING, "STOP_LOSS_ON_FILL_PRICE_MISSING"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID, "TRAILING_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID, "STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID"},
	{TransactionRejectReason::ACCOUNT_CONFIGURATION_LOCKED, "ACCOUNT_CONFIGURATION_LOCKED"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_PRICE_AND_DISTANCE_BOTH_SPECIFIED, "GUARANTEED_STOP_LOSS_ORDER_PRICE_AND_DISTANCE_BOTH_SPECIFIED"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ON_FILL_REQUIRED_FOR_PENDING_ORDER, "GUARANTEED_STOP_LOSS_ON_FILL_REQUIRED_FOR_PENDING_ORDER"},
	{TransactionRejectReason::CLIENT_EXTENSIONS_DATA_MISSING, "CLIENT_EXTENSIONS_DATA_MISSING"},
	{TransactionRejectReason::MARGIN_RATE_WOULD_TRIGGER_MARGIN_CALL, "MARGIN_RATE_WOULD_TRIGGER_MARGIN_CALL"},
	{TransactionRejectReason::ACCOUNT_NOT_ACTIVE, "ACCOUNT_NOT_ACTIVE"},
	{TransactionRejectReason::REPLACING_TRADE_ID_INVALID, "REPLACING_TRADE_ID_INVALID"},
	{TransactionRejectReason::ALIAS_INVALID, "ALIAS_INVALID"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_INVALID, "TRAILING_STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_INVALID"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_MISSING, "TRAILING_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_MISSING"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ORDER_WOULD_VIOLATE_FIFO_VIOLATION_SAFEGUARD, "TRAILING_STOP_LOSS_ORDER_WOULD_VIOLATE_FIFO_VIOLATION_SAFEGUARD"},
	{TransactionRejectReason::TAKE_PROFIT_ON_FILL_CLIENT_ORDER_TAG_INVALID, "TAKE_PROFIT_ON_FILL_CLIENT_ORDER_TAG_INVALID"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST, "TRAILING_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED, "TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_PRECISION_EXCEEDED, "TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_PRECISION_EXCEEDED"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_GUARANTEED_NOT_ALLOWED, "STOP_LOSS_ON_FILL_GUARANTEED_NOT_ALLOWED"},
	{TransactionRejectReason::ACCOUNT_LOCKED, "ACCOUNT_LOCKED"},
	{TransactionRejectReason::UNITS_INVALID, "UNITS_INVALID"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_LEVEL_RESTRICTION_PRICE_RANGE_EXCEEDED, "GUARANTEED_STOP_LOSS_ORDER_LEVEL_RESTRICTION_PRICE_RANGE_EXCEEDED"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_MINIMUM_DISTANCE_NOT_MET, "GUARANTEED_STOP_LOSS_ORDER_MINIMUM_DISTANCE_NOT_MET"},
	{TransactionRejectReason::GUARANTEED_STOP_LOSS_ORDER_ALREADY_EXISTS, "GUARANTEED_STOP_LOSS_ORDER_ALREADY_EXISTS"},
	{TransactionRejectReason::ORDER_PARTIAL_FILL_OPTION_INVALID, "ORDER_PARTIAL_FILL_OPTION_INVALID"},
	{TransactionRejectReason::INSTRUMENT_NOT_TRADEABLE, "INSTRUMENT_NOT_TRADEABLE"},
	{TransactionRejectReason::STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_INVALID, "STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_INVALID"},
	{TransactionRejectReason::ACCOUNT_ORDER_CREATION_LOCKED, "ACCOUNT_ORDER_CREATION_LOCKED"},
	{TransactionRejectReason::FUNDING_REASON_MISSING, "FUNDING_REASON_MISSING"},
	{TransactionRejectReason::TRAILING_STOP_LOSS_ON_FILL_CLIENT_ORDER_COMMENT_INVALID, "TRAILING_STOP_LOSS_ON_FILL_CLIENT_ORDER_COMMENT_INVALID"},
	{TransactionRejectReason::TRADE_ON_FILL_CLIENT_EXTENSIONS_NOT_SUPPORTED, "TRADE_ON_FILL_CLIENT_EXTENSIONS_NOT_SUPPORTED"}
})

// TransactionFilter
//void to_json(nlohmann::json& j, const oanda::v20::transaction::TransactionFilter& e);
//void from_json(const nlohmann::json& j, oanda::v20::transaction::TransactionFilter& e);
// TransactionFilter
NLOHMANN_JSON_SERIALIZE_ENUM(TransactionFilter, {
	{TransactionFilter::UNDEFINED, nullptr},
	{TransactionFilter::ORDER_CANCEL, "ORDER_CANCEL"},
	{TransactionFilter::TRANSFER_FUNDS, "TRANSFER_FUNDS"},
	{TransactionFilter::RESET_RESETTABLE_PL, "RESET_RESETTABLE_PL"},
	{TransactionFilter::ONE_CANCELS_ALL_ORDER, "ONE_CANCELS_ALL_ORDER"},
	{TransactionFilter::ORDER_CANCEL_REJECT, "ORDER_CANCEL_REJECT"},
	{TransactionFilter::TRAILING_STOP_LOSS_ORDER, "TRAILING_STOP_LOSS_ORDER"},
	{TransactionFilter::TRAILING_STOP_LOSS_ORDER_REJECT, "TRAILING_STOP_LOSS_ORDER_REJECT"},
	{TransactionFilter::STOP_LOSS_ORDER_REJECT, "STOP_LOSS_ORDER_REJECT"},
	{TransactionFilter::CREATE, "CREATE"},
	{TransactionFilter::ORDER_CLIENT_EXTENSIONS_MODIFY, "ORDER_CLIENT_EXTENSIONS_MODIFY"},
	{TransactionFilter::ONE_CANCELS_ALL_ORDER_REJECT, "ONE_CANCELS_ALL_ORDER_REJECT"},
	{TransactionFilter::GUARANTEED_STOP_LOSS_ORDER, "GUARANTEED_STOP_LOSS_ORDER"},
	{TransactionFilter::CLIENT_CONFIGURE, "CLIENT_CONFIGURE"},
	{TransactionFilter::ORDER_FILL, "ORDER_FILL"},
	{TransactionFilter::LIMIT_ORDER, "LIMIT_ORDER"},
	{TransactionFilter::ONE_CANCELS_ALL_ORDER_TRIGGERED, "ONE_CANCELS_ALL_ORDER_TRIGGERED"},
	{TransactionFilter::CLIENT_CONFIGURE_REJECT, "CLIENT_CONFIGURE_REJECT"},
	{TransactionFilter::ORDER_CLIENT_EXTENSIONS_MODIFY_REJECT, "ORDER_CLIENT_EXTENSIONS_MODIFY_REJECT"},
	{TransactionFilter::TRADE_CLIENT_EXTENSIONS_MODIFY, "TRADE_CLIENT_EXTENSIONS_MODIFY"},
	{TransactionFilter::DAILY_FINANCING, "DAILY_FINANCING"},
	{TransactionFilter::MARKET_ORDER_REJECT, "MARKET_ORDER_REJECT"},
	{TransactionFilter::CLOSE, "CLOSE"},
	{TransactionFilter::GUARANTEED_STOP_LOSS_ORDER_REJECT, "GUARANTEED_STOP_LOSS_ORDER_REJECT"},
	{TransactionFilter::MARGIN_CALL_ENTER, "MARGIN_CALL_ENTER"},
	{TransactionFilter::MARKET_ORDER, "MARKET_ORDER"},
	{TransactionFilter::TRADE_CLIENT_EXTENSIONS_MODIFY_REJECT, "TRADE_CLIENT_EXTENSIONS_MODIFY_REJECT"},
	{TransactionFilter::ORDER, "ORDER"},
	{TransactionFilter::STOP_LOSS_ORDER, "STOP_LOSS_ORDER"},
	{TransactionFilter::MARGIN_CALL_EXTEND, "MARGIN_CALL_EXTEND"},
	{TransactionFilter::ADMIN, "ADMIN"},
	{TransactionFilter::DELAYED_TRADE_CLOSURE, "DELAYED_TRADE_CLOSURE"},
	{TransactionFilter::REOPEN, "REOPEN"},
	{TransactionFilter::TRANSFER_FUNDS_REJECT, "TRANSFER_FUNDS_REJECT"},
	{TransactionFilter::STOP_ORDER, "STOP_ORDER"},
	{TransactionFilter::LIMIT_ORDER_REJECT, "LIMIT_ORDER_REJECT"},
	{TransactionFilter::MARKET_IF_TOUCHED_ORDER, "MARKET_IF_TOUCHED_ORDER"},
	{TransactionFilter::TAKE_PROFIT_ORDER_REJECT, "TAKE_PROFIT_ORDER_REJECT"},
	{TransactionFilter::MARKET_IF_TOUCHED_ORDER_REJECT, "MARKET_IF_TOUCHED_ORDER_REJECT"},
	{TransactionFilter::TAKE_PROFIT_ORDER, "TAKE_PROFIT_ORDER"},
	{TransactionFilter::FUNDING, "FUNDING"},
	{TransactionFilter::MARGIN_CALL_EXIT, "MARGIN_CALL_EXIT"},
	{TransactionFilter::STOP_ORDER_REJECT, "STOP_ORDER_REJECT"}
})

// TransactionHeartbeat
void to_json(nlohmann::json& j, const oanda::v20::transaction::TransactionHeartbeat& p);
void from_json(const nlohmann::json& j, oanda::v20::transaction::TransactionHeartbeat& p);

} /* namespace transaction */

} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_JSON_JSONTOFROM_HPP */
