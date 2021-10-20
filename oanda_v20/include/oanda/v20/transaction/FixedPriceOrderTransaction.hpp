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
 * @file   FixedPriceOrderTransaction.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_FIXEDPRICEORDERTRANSACTION_HPP
#define OANDA_V20_TRANSACTION_FIXEDPRICEORDERTRANSACTION_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"
#include "oanda/v20/pricing_common/Pricing_CommonDefinitions.hpp"
#include "oanda/v20/account/AccountDefinitions.hpp"
#include "oanda/v20/transaction/TrailingStopLossDetails.hpp"
#include "oanda/v20/transaction/TakeProfitDetails.hpp"
#include "oanda/v20/transaction/ClientExtensions.hpp"
#include "oanda/v20/order/OrderDefinitions.hpp"
#include "oanda/v20/transaction/StopLossDetails.hpp"
#include "oanda/v20/transaction/GuaranteedStopLossDetails.hpp"
#include "oanda/v20/transaction/TransactionDefinitions.hpp"
#include "oanda/v20/primitives/PrimitivesDefinitions.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * A FixedPriceOrderTransaction represents the creation of a Fixed Price Order in the user’s account. A Fixed Price Order is an Order that is filled immediately at a specified price.
 * FixedPriceOrderTransaction is an application/json object with the following Schema:
 */
struct FixedPriceOrderTransaction {
	FixedPriceOrderTransaction():
		userID(0),
		type(oanda::v20::transaction::TransactionType::UNDEFINED),
		positionFill(oanda::v20::order::OrderPositionFill::UNDEFINED),
		reason(oanda::v20::transaction::FixedPriceOrderReason::UNDEFINED)
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
	 *  The Type of the Transaction. Always set to “FIXED_PRICE_ORDER” in a
	 *  FixedPriceOrderTransaction.
	 */
	oanda::v20::transaction::TransactionType type;

	/**
	 *  The Fixed Price Order’s Instrument.
	 */
	oanda::v20::primitives::InstrumentName instrument;

	/**
	 *  The quantity requested to be filled by the Fixed Price Order. A positive
	 *  number of units results in a long Order, and a negative number of units
	 *  results in a short Order.
	 */
	oanda::v20::primitives::DecimalNumber units;

	/**
	 *  The price specified for the Fixed Price Order. This price is the exact
	 *  price that the Fixed Price Order will be filled at.
	 */
	oanda::v20::pricing_common::PriceValue price;

	/**
	 *  Specification of how Positions in the Account are modified when the Order
	 *  is filled.
	 */
	oanda::v20::order::OrderPositionFill positionFill;

	/**
	 *  The state that the trade resulting from the Fixed Price Order should be
	 *  set to.
	 */
	oanda::v20::common::String tradeState;

	/**
	 *  The reason that the Fixed Price Order was created
	 */
	oanda::v20::transaction::FixedPriceOrderReason reason;

	/**
	 *  The client extensions for the Fixed Price Order.
	 */
	oanda::v20::transaction::ClientExtensions clientExtensions;

	/**
	 *  The specification of the Take Profit Order that should be created for a
	 *  Trade opened when the Order is filled (if such a Trade is created).
	 */
	oanda::v20::transaction::TakeProfitDetails takeProfitOnFill;

	/**
	 *  The specification of the Stop Loss Order that should be created for a
	 *  Trade opened when the Order is filled (if such a Trade is created).
	 */
	oanda::v20::transaction::StopLossDetails stopLossOnFill;

	/**
	 *  The specification of the Trailing Stop Loss Order that should be created
	 *  for a Trade that is opened when the Order is filled (if such a Trade is
	 *  created).
	 */
	oanda::v20::transaction::TrailingStopLossDetails trailingStopLossOnFill;

	/**
	 *  The specification of the Guaranteed Stop Loss Order that should be
	 *  created for a Trade that is opened when the Order is filled (if such a
	 *  Trade is created).
	 */
	oanda::v20::transaction::GuaranteedStopLossDetails guaranteedStopLossOnFill;

	/**
	 *  Client Extensions to add to the Trade created when the Order is filled
	 *  (if such a Trade is created).  Do not set, modify, delete
	 *  tradeClientExtensions if your account is associated with MT4.
	 */
	oanda::v20::transaction::ClientExtensions tradeClientExtensions;
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_FIXEDPRICEORDERTRANSACTION_HPP */
