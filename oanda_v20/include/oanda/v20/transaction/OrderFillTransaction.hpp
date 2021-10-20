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
 * @file   OrderFillTransaction.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_ORDERFILLTRANSACTION_HPP
#define OANDA_V20_TRANSACTION_ORDERFILLTRANSACTION_HPP

#include <string>
#include <vector>

#include "oanda/v20/account/AccountDefinitions.hpp"
#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/primitives/HomeConversionFactors.hpp"
#include "oanda/v20/transaction/TradeReduce.hpp"
#include "oanda/v20/transaction/TradeOpen.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/pricing/ClientPrice.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * An OrderFillTransaction represents the filling of an Order in the client’s Account.
 * OrderFillTransaction is an application/json object with the following Schema:
 */
struct OrderFillTransaction {
	OrderFillTransaction():
		userID(0),
		type(oanda::v20::transaction::TransactionType::UNDEFINED),
		reason(oanda::v20::transaction::OrderFillReason::UNDEFINED)
	{}

	/**
	 *  The Transaction’s Identifier.
	 */
	oanda::v20::transaction::TransactionID id;

	/**
	 *  The date/time when the Transaction was created.
	 */
	oanda::v20::primitives::DateTime time;

	/**
	 *  The ID of the user that initiated the creation of the Transaction.
	 */
	int userID;

	/**
	 *  The ID of the Account the Transaction was created for.
	 */
	oanda::v20::account::AccountID accountID;

	/**
	 *  The ID of the “batch” that the Transaction belongs to. Transactions in
	 *  the same batch are applied to the Account simultaneously.
	 */
	oanda::v20::transaction::TransactionID batchID;

	/**
	 *  The Request ID of the request which generated the transaction.
	 */
	oanda::v20::transaction::RequestID requestID;

	/**
	 *  The Type of the Transaction. Always set to “ORDER_FILL” for an
	 *  OrderFillTransaction.
	 */
	oanda::v20::transaction::TransactionType type;

	/**
	 *  The ID of the Order filled.
	 */
	oanda::v20::order::OrderID orderID;

	/**
	 *  The client Order ID of the Order filled (only provided if the client has
	 *  assigned one).
	 */
	oanda::v20::transaction::ClientID clientOrderID;

	/**
	 *  The name of the filled Order’s instrument.
	 */
	oanda::v20::primitives::InstrumentName instrument;

	/**
	 *  The number of units filled by the OrderFill.
	 */
	oanda::v20::primitives::DecimalNumber units;

	/**
	 *  This is the conversion factor in effect for the Account at the time of
	 *  the OrderFill for converting any gains realized in Instrument quote units
	 *  into units of the Account’s home currency.
	 *  <b>Deprecated</b>: Will be removed in a future API update.
	 */
	oanda::v20::primitives::DecimalNumber gainQuoteHomeConversionFactor;

	/**
	 *  This is the conversion factor in effect for the Account at the time of
	 *  the OrderFill for converting any losses realized in Instrument quote
	 *  units into units of the Account’s home currency.
	 *  <b>Deprecated</b>: Will be removed in a future API update.
	 */
	oanda::v20::primitives::DecimalNumber lossQuoteHomeConversionFactor;

	/**
	 *  The HomeConversionFactors in effect at the time of the OrderFill.
	 */
	oanda::v20::primitives::HomeConversionFactors homeConversionFactors;

	/**
	 *  This field is now deprecated and should no longer be used. The individual
	 *  tradesClosed, tradeReduced and tradeOpened fields contain the
	 *  exact/official price each unit was filled at.
	 *  <b>Deprecated</b>: Will be removed in a future API update.
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 *  The price that all of the units of the OrderFill should have been filled
	 *  at, in the absence of guaranteed price execution. This factors in the
	 *  Account’s current ClientPrice, used liquidity and the units of the
	 *  OrderFill only. If no Trades were closed with their price clamped for
	 *  guaranteed stop loss enforcement, then this value will match the price
	 *  fields of each Trade opened, closed, and reduced, and they will all be
	 *  the exact same.
	 */
	oanda::v20::pricing_common::PriceValue fullVWAP;

	/**
	 *  The price in effect for the account at the time of the Order fill.
	 */
	oanda::v20::pricing::ClientPrice fullPrice;

	/**
	 *  The reason that an Order was filled
	 */
	oanda::v20::transaction::OrderFillReason reason;

	/**
	 *  The profit or loss incurred when the Order was filled.
	 */
	oanda::v20::primitives::AccountUnits pl;

	/**
	 *  The profit or loss incurred when the Order was filled, in the
	 *  Instrument’s quote currency.
	 */
	oanda::v20::primitives::DecimalNumber quotePL;

	/**
	 *  The financing paid or collected when the Order was filled.
	 */
	oanda::v20::primitives::AccountUnits financing;

	/**
	 *  The financing paid or collected when the Order was filled, in the
	 *  Instrument’s base currency.
	 */
	oanda::v20::primitives::DecimalNumber baseFinancing;

	/**
	 *  The financing paid or collected when the Order was filled, in the
	 *  Instrument’s quote currency.
	 */
	oanda::v20::primitives::DecimalNumber quoteFinancing;

	/**
	 *  The commission charged in the Account’s home currency as a result of
	 *  filling the Order. The commission is always represented as a positive
	 *  quantity of the Account’s home currency, however it reduces the balance
	 *  in the Account.
	 */
	oanda::v20::primitives::AccountUnits commission;

	/**
	 *  The total guaranteed execution fees charged for all Trades opened, closed
	 *  or reduced with guaranteed Stop Loss Orders.
	 */
	oanda::v20::primitives::AccountUnits guaranteedExecutionFee;

	/**
	 *  The total guaranteed execution fees charged for all Trades opened, closed
	 *  or reduced with guaranteed Stop Loss Orders, expressed in the
	 *  Instrument’s quote currency.
	 */
	oanda::v20::primitives::DecimalNumber quoteGuaranteedExecutionFee;

	/**
	 *  The Account’s balance after the Order was filled.
	 */
	oanda::v20::primitives::AccountUnits accountBalance;

	/**
	 *  The Trade that was opened when the Order was filled (only provided if
	 *  filling the Order resulted in a new Trade).
	 */
	oanda::v20::transaction::TradeOpen tradeOpened;

	/**
	 *  The Trades that were closed when the Order was filled (only provided if
	 *  filling the Order resulted in a closing open Trades).
	 */
	std::vector<oanda::v20::transaction::TradeReduce> tradesClosed;

	/**
	 *  The Trade that was reduced when the Order was filled (only provided if
	 *  filling the Order resulted in reducing an open Trade).
	 */
	oanda::v20::transaction::TradeReduce tradeReduced;

	/**
	 *  The half spread cost for the OrderFill, which is the sum of the
	 *  halfSpreadCost values in the tradeOpened, tradesClosed and tradeReduced
	 *  fields. This can be a positive or negative value and is represented in
	 *  the home currency of the Account.
	 */
	oanda::v20::primitives::AccountUnits halfSpreadCost;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_ORDERFILLTRANSACTION_HPP */
