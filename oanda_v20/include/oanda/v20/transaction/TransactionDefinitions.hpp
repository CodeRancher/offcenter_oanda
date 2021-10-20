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
 * distributed under the License is distributed on an  BASIS,	///<
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file   TransactionDefinitions.hpp
 * @author Scott Brauer
 *
 * @date   12-07-2020  
 */

#ifndef OANDA_V20_TRANSACTION_TRANSACTIONDEFINITIONS_HPP
#define OANDA_V20_TRANSACTION_TRANSACTIONDEFINITIONS_HPP

#include <vector>

#include "oanda/v20/common/String.hpp"

namespace oanda {
namespace v20 {
namespace transaction {

/**
 * The unique Transaction identifier within each Account.
 * 1523
 */
using TransactionID = oanda::v20::common::String;

/**
 * The possible types of a Transaction
 */
enum class TransactionType {
	UNDEFINED = 0,	///< Default value allows json to be blank
	DIVIDEND_ADJUSTMENT,					///< Dividend Adjustment Transaction
	ORDER_CANCEL,							///< Order Cancel Transaction
	TRANSFER_FUNDS,							///< Transfer Funds Transaction
	RESET_RESETTABLE_PL,					///< Reset Resettable PL Transaction
	ORDER_CANCEL_REJECT,					///< Order Cancel Reject Transaction
	TRAILING_STOP_LOSS_ORDER,				///< Trailing Stop Loss Order Transaction
	TRAILING_STOP_LOSS_ORDER_REJECT,		///< Trailing Stop Loss Order Reject Transaction
	STOP_LOSS_ORDER_REJECT,					///< Stop Loss Order Reject Transaction
	CREATE,									///< Account Create Transaction
	ORDER_CLIENT_EXTENSIONS_MODIFY,			///< Order Client Extensions Modify Transaction
	GUARANTEED_STOP_LOSS_ORDER,				///< Guaranteed Stop Loss Order Transaction
	CLIENT_CONFIGURE,						///< Client Configuration Transaction
	ORDER_FILL,								///< Order Fill Transaction
	LIMIT_ORDER,							///< Limit Order Transaction
	CLIENT_CONFIGURE_REJECT,				///< Client Configuration Reject Transaction
	ORDER_CLIENT_EXTENSIONS_MODIFY_REJECT,	///< Order Client Extensions Modify Reject Transaction
	TRADE_CLIENT_EXTENSIONS_MODIFY,			///< Trade Client Extensions Modify Transaction
	DAILY_FINANCING,						///< Daily Financing Transaction
	MARKET_ORDER_REJECT,					///< Market Order Reject Transaction
	CLOSE,									///< Account Close Transaction
	GUARANTEED_STOP_LOSS_ORDER_REJECT,		///< Guaranteed Stop Loss Order Reject Transaction
	MARGIN_CALL_ENTER,						///< Margin Call Enter Transaction
	MARKET_ORDER,							///< Market Order Transaction
	TRADE_CLIENT_EXTENSIONS_MODIFY_REJECT,	///< Trade Client Extensions Modify Reject Transaction
	STOP_LOSS_ORDER,						///< Stop Loss Order Transaction
	MARGIN_CALL_EXTEND,						///< Margin Call Extend Transaction
	REOPEN,									///< Account Reopen Transaction
	DELAYED_TRADE_CLOSURE,					///< Delayed Trade Closure Transaction
	TRANSFER_FUNDS_REJECT,					///< Transfer Funds Reject Transaction
	STOP_ORDER,								///< Stop Order Transaction
	LIMIT_ORDER_REJECT,						///< Limit Order Reject Transaction
	MARKET_IF_TOUCHED_ORDER,				///< Market if Touched Order Transaction
	TAKE_PROFIT_ORDER_REJECT,				///< Take Profit Order Reject Transaction
	MARKET_IF_TOUCHED_ORDER_REJECT,			///< Market if Touched Order Reject Transaction
	FIXED_PRICE_ORDER,						///< Fixed Price Order Transaction
	TAKE_PROFIT_ORDER,						///< Take Profit Order Transaction
	MARGIN_CALL_EXIT,						///< Margin Call Exit Transaction
	STOP_ORDER_REJECT						///< Stop Order Reject Transaction
};

/**
 * The reason that an Account is being funded.
 */
enum class FundingReason {
	UNDEFINED = 0,	///< Default value allows json to be blank
	DIVISION_MIGRATION,	///< Funds are being transferred as part of a Division migration
	ACCOUNT_TRANSFER,	///< Funds are being transferred between two Accounts.
	ADJUSTMENT,			///< Funds are being transferred as part of an Account adjustment
	SITE_MIGRATION,		///< Funds are being transferred as part of a Site migration
	CLIENT_FUNDING		///< The client has initiated a funds transfer
};

/**
 * The reason that the Market Order was created
 */
enum class MarketOrderReason {
	UNDEFINED = 0,	///< Default value allows json to be blank
	CLIENT_ORDER,			///< The Market Order was created at the request of a client
	DELAYED_TRADE_CLOSE,	///< The Market Order was created to close a trade marked for delayed closure
	POSITION_CLOSEOUT,		///< The Market Order was created to close a Position at the request of a client
	TRADE_CLOSE,			///< The Market Order was created to close a Trade at the request of a client
	MARGIN_CLOSEOUT			///< The Market Order was created as part of a Margin Closeout
};

/**
 * The reason that the Fixed Price Order was created
 */
enum class FixedPriceOrderReason {
	UNDEFINED = 0,	///< Default value allows json to be blank
	TRADE_CLOSE_DIVISION_ACCOUNT_MIGRATION,	///< The Fixed Price Order was created to close a Trade as part of division account migration
	PLATFORM_ACCOUNT_MIGRATION,				///< The Fixed Price Order was created as part of a platform account migration
	TRADE_CLOSE_ADMINISTRATIVE_ACTION		///< The Fixed Price Order was created to close a Trade administratively
};

/**
 * The reason that the Limit Order was initiated
 */
enum class LimitOrderReason {
	UNDEFINED = 0,	///< Default value allows json to be blank
	CLIENT_ORDER,	///< The Limit Order was initiated at the request of a client
	REPLACEMENT		///< The Limit Order was initiated as a replacement for an existing Order
};

/**
 * The reason that the Stop Order was initiated
 */
enum class StopOrderReason {
	UNDEFINED = 0,	///< Default value allows json to be blank
	CLIENT_ORDER,	///< The Stop Order was initiated at the request of a client
	REPLACEMENT		///< The Stop Order was initiated as a replacement for an existing Order
};

/**
 * The reason that the Market-if-touched Order was initiated
 */
enum class MarketIfTouchedOrderReason {
	UNDEFINED = 0,	///< Default value allows json to be blank
	CLIENT_ORDER,	///< The Market-if-touched Order was initiated at the request of a client
	REPLACEMENT		///< The Market-if-touched Order was initiated as a replacement for an existing Order
};

/**
 * The reason that the Take Profit Order was initiated
 */
enum class TakeProfitOrderReason {
	UNDEFINED = 0,	///< Default value allows json to be blank
	CLIENT_ORDER,	///< The Take Profit Order was initiated at the request of a client
	ON_FILL,		///< The Take Profit Order was initiated automatically when an Order was filled that opened a new Trade requiring a Take Profit Order.
	REPLACEMENT		///< The Take Profit Order was initiated as a replacement for an existing Order
};

/**
 * The reason that the Stop Loss Order was initiated
 */
enum class StopLossOrderReason {
	UNDEFINED = 0,	///< Default value allows json to be blank
	CLIENT_ORDER,	///< The Stop Loss Order was initiated at the request of a client
	ON_FILL,		///< The Stop Loss Order was initiated automatically when an Order was filled that opened a new Trade requiring a Stop Loss Order.
	REPLACEMENT		///< The Stop Loss Order was initiated as a replacement for an existing Order
};

/**
 * The reason that the Guaranteed Stop Loss Order was initiated
 */
enum class GuaranteedStopLossOrderReason {
	UNDEFINED = 0,	///< Default value allows json to be blank
	CLIENT_ORDER,	///< The Guaranteed Stop Loss Order was initiated at the request of a client
	ON_FILL,		///< The Guaranteed Stop Loss Order was initiated automatically when an Order was
					///< filled that opened a new Trade requiring a Guaranteed Stop Loss Order.
	REPLACEMENT		///< The Guaranteed Stop Loss Order was initiated as a replacement for an existing Order
};

/**
 * The reason that the Trailing Stop Loss Order was initiated
 */
enum class TrailingStopLossOrderReason {
	UNDEFINED = 0,	///< Default value allows json to be blank
	CLIENT_ORDER,	///< The Trailing Stop Loss Order was initiated at the request of a client
	ON_FILL,		///< The Trailing Stop Loss Order was initiated automatically when an Order was
					///< filled that opened a new Trade requiring a Trailing Stop Loss Order.
	REPLACEMENT		///< The Trailing Stop Loss Order was initiated as a replacement for an existing Order
};

/**
 * The reason that an Order was filled
 */
enum class OrderFillReason {
	UNDEFINED = 0,	///< Default value allows json to be blank
	MARKET_ORDER_DELAYED_TRADE_CLOSE,				///< The Order filled was a Market Order used for a delayed Trade close
	STOP_ORDER,										///< The Order filled was a Stop Order
	FIXED_PRICE_ORDER_ADMINISTRATIVE_ACTION,		///< The Order filled was a Fixed Price Order created to close a Trade administratively
	MARKET_ORDER_MARGIN_CLOSEOUT,					///< The Order filled was a Market Order used for a Margin Closeout
	MARKET_ORDER_POSITION_CLOSEOUT,					///< The Order filled was a Market Order used to explicitly close a Position
	MARKET_ORDER,									///< The Order filled was a Market Order
	FIXED_PRICE_ORDER_DIVISION_ACCOUNT_MIGRATION,	///< The Order filled was a Fixed Price Order created to close a Trade as part of division account migration
	FIXED_PRICE_ORDER_PLATFORM_ACCOUNT_MIGRATION,	///< The Order filled was a Fixed Price Order created as part of a platform account migration
	TAKE_PROFIT_ORDER,								///< The Order filled was a Take Profit Order
	MARKET_IF_TOUCHED_ORDER,						///< The Order filled was a Market-if-touched Order
	LIMIT_ORDER,									///< The Order filled was a Limit Order
	GUARANTEED_STOP_LOSS_ORDER,						///< The Order filled was a Guaranteed Stop Loss Order
	STOP_LOSS_ORDER,								///< The Order filled was a Stop Loss Order
	FIXED_PRICE_ORDER,								///< The Order filled was a Fixed Price Order
	MARKET_ORDER_TRADE_CLOSE,						///< The Order filled was a Market Order used to explicitly close a Trade
	TRAILING_STOP_LOSS_ORDER						///< The Order filled was a Trailing Stop Loss Order
};

/**
 * The reason that an Order was cancelled.
 */
enum class OrderCancelReason {
	UNDEFINED = 0,	///< Default value allows json to be blank
	ACCOUNT_ORDER_FILL_LOCKED,	///< Filling the Order was not possible because the Account is locked for filling Orders.
	INSUFFICIENT_MARGIN,	///< Filling the Order wasn’t possible because the Account had insufficient margin.
	TAKE_PROFIT_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED,	///< Filling the Order would result in the creation of a
															///< Take Profit Order whose price would be zero or negative due to the specified distance.
	GUARANTEED_STOP_LOSS_ON_FILL_ASK_HALTED,	///< Filling the Order would result in the creation of a Guaranteed Stop Loss Order (GSLO).
												///< Since the trade is short the GSLO would be long, however the ask side is currently halted.
												///< GSLOs cannot be created in this situation.
	GUARANTEED_STOP_LOSS_ON_FILL_NOT_ALLOWED,	///< Filling the Order would result in the creation of a Guaranteed Stop Loss Order,
												///< however the Account’s configuration does not allow Guaranteed Stop Loss Orders.
	TRAILING_STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS,	///< Filling the Order would have resulted in the creation of a Trailing Stop Loss Order with a client Order ID that is already in use.
	FIFO_VIOLATION_SAFEGUARD_VIOLATION,	///< Filling the Order would have resulted in a new Trade that violates the FIFO violation safeguard constraints.
	ACCOUNT_NEW_POSITIONS_LOCKED,	///< The order was to be filled, however the account is configured to not allow new positions to be created.
	MIGRATION,	///< The Order cancelled because it is being migrated to another account.
	GUARANTEED_STOP_LOSS_ON_FILL_LEVEL_RESTRICTION_VOLUME_EXCEEDED,	///< Filling the Order would result in the creation of a Guaranteed Stop Loss Order
																	///< with trigger number of units that violates the account’s Guaranteed Stop Loss Order level restriction volume.
	GUARANTEED_STOP_LOSS_ON_FILL_REQUIRED,	///< Filling the Order would not result in the creation of a Guaranteed Stop Loss Order,
											///< however the Account’s configuration requires that all Trades have a Guaranteed Stop Loss Order attached to them.
	INSTRUMENT_BID_REDUCE_ONLY,	///< Filling the order would require the creation of a short trade, however the instrument is configured
								///< such that orders being filled using bid prices can only reduce existing positions.
								///< New short positions cannot be created, but existing long positions may be reduced or closed.
	ORDERS_ON_FILL_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION,	///< The Orders on fill would be in violation of the risk management
																		///< Order mutual exclusivity configuration specifying that only one
																		///< risk management Order can be attached to a Trade.
	STOP_LOSS_ON_FILL_LOSS,	///< Filling the Order would result in the creation of a Stop Loss Order that
							///< would have been filled immediately, closing the new Trade at a loss.
	LINKED_TRADE_CLOSED,	///< The Order is linked to an open Trade that was closed.
	ACCOUNT_POSITION_VALUE_LIMIT_EXCEEDED,	///< Filling the order would cause the maximum position value allowed for the account
											///< to be exceeded. The Order has been cancelled as a result.
	FIFO_VIOLATION_SAFEGUARD_PARTIAL_CLOSE_VIOLATION,	///< Filling the Order would have reduced an existing Trade such that the reduced Trade violates the FIFO violation safeguard constraints.
	POSITION_CLOSEOUT_FAILED,	///< Closing out a position wasn’t fully possible.
	TIME_IN_FORCE_EXPIRED,	///< The time in force specified for this order has passed.
	PENDING_ORDERS_ALLOWED_EXCEEDED,	///< Filling the Order would have resulted in exceeding the number of pending Orders allowed for the Account.
	STOP_LOSS_ON_FILL_GUARANTEED_ASK_HALTED,	///< Filling the Order would result in the creation of a Guaranteed Stop Loss Order (GSLO).
												///< Since the trade is short the GSLO would be long, however the ask side is currently halted.
												///< GSLOs cannot be created in this situation.
	STOP_LOSS_ON_FILL_REQUIRED,	///< Filling the Order would not result in the creation of Stop Loss Order,
								///< however the Account’s configuration requires that all Trades have a Stop Loss Order attached to them.
	GUARANTEED_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID,	///< Filling the Order would result in the creation of a Guaranteed Stop Loss Order
															///< whose TriggerCondition value is invalid. A likely cause would be the TimeInForce
															///< is not TRIGGER_DEFAULT or TRIGGER_BID for a long trade,
															///< or not TRIGGER_DEFAULT or TRIGGER_ASK for a short trade.
	TAKE_PROFIT_ON_FILL_GTD_TIMESTAMP_IN_PAST,	///< Filling the Order would have resulted in the creation of a Take Profit Order with a GTD time in the past.
	GUARANTEED_STOP_LOSS_ON_FILL_HEDGING_NOT_ALLOWED,	///< Filling the Order would result in the creation of a Guaranteed Stop Loss Order for a hedged Trade,
														///< however the Account’s configuration does not allow Guaranteed Stop Loss Orders for hedged Trades/Positions.
	INSTRUMENT_BID_HALTED,	///< Filling the order would require using the bid, however the instrument
							///< is configured such that the bids are halted, and so no short orders may be filled.
	GUARANTEED_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED,	///< Filling the Order would result in the creation of a Guaranteed Stop Loss
																	///< Order whose price would be zero or negative due to the specified distance.
	TAKE_PROFIT_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS,	///< Filling the Order would have resulted in the creation of a Take Profit
														///< Order with a client Order ID that is already in use.

	/**
	 * Filling the Order would result in the creation of a Guaranteed Stop Loss Order whose TimeInForce value is invalid. A likely cause would be if the Account requires guaranteed stop loss orders and the TimeInForce value were not GTC.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID,	///<

	/**
	 * Filling the Order would result in the creation of a Guaranteed Stop Loss Order (GSLO). Since the trade is long the GSLO would be short, however the bid side is currently halted. GSLOs cannot be created in this situation.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_BID_HALTED,	///<

	/**
	 * Filling the Order would result in the creation of a Stop Loss Order whose TimeInForce value is invalid. A likely cause would be if the Account requires guaranteed stop loss orders and the TimeInForce value were not GTC.
	 */
	STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID,	///<

	/**
	 * Filling the Order would result in the creation of a Guaranteed Stop Loss Order with trigger price that violates the account’s Guaranteed Stop Loss Order level restriction price range.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_LEVEL_RESTRICTION_PRICE_RANGE_EXCEEDED,	///<

	/**
	 * Filling the Order would not result in the creation of a guaranteed Stop Loss Order, however the Account’s configuration requires that all Trades have a guaranteed Stop Loss Order attached to them.
	 */
	STOP_LOSS_ON_FILL_GUARANTEED_REQUIRED,	///<

	/**
	 * Filling the Order would have resulted in the Account’s maximum position size limit being exceeded for the Order’s instrument.
	 */
	POSITION_SIZE_EXCEEDED,	///<

	/**
	 * The Order was cancelled for replacement at the request of the client.
	 */
	CLIENT_REQUEST_REPLACED,	///<

	/**
	 * Filling the Order would result in the creation of a Guaranteed Stop Loss Order with a distance smaller than the configured minimum distance.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_MINIMUM_DISTANCE_NOT_MET,	///<

	/**
	 * Filling the Order would result in the creation of a guaranteed Stop Loss Order with trigger price and number of units that that violates the account’s guaranteed Stop Loss Order level restriction.
	 */
	STOP_LOSS_ON_FILL_GUARANTEED_LEVEL_RESTRICTION_EXCEEDED,	///<

	/**
	 * Filling the Order would cause the maximum open trades allowed for the Account to be exceeded.
	 */
	OPEN_TRADES_ALLOWED_EXCEEDED,	///<

	/**
	 * Filling the Order would have violated the Order’s price bound.
	 */
	BOUNDS_VIOLATION,	///<

	/**
	 * Filling the Order would result in the creation of a Stop Loss Order whose price would be zero or negative due to the specified distance.
	 */
	STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED,	///<

	/**
	 * Filling the Order would result in the creation of a Guaranteed Stop Loss Order that would have been filled immediately, closing the new Trade at a loss.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_LOSS,	///<

	/**
	 * The Order was cancelled because at the time of filling, an unexpected internal server error occurred.
	 */
	INTERNAL_SERVER_ERROR,	///<

	/**
	 * The Order was cancelled for replacement with an adjusted fillPrice to accommodate for the price movement caused by a dividendAdjustment.
	 */
	DIVIDEND_ADJUSTMENT_REPLACED,	///<

	/**
	 * Filling the Order would have resulted in the creation of a Stop Loss Order with a client Order ID that is already in use.
	 */
	STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS,	///<

	/**
	 * Filling the Order would have resulted in the creation of a Guaranteed Stop Loss Order with a GTD time in the past.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST,	///<

	/**
	 * Filling the Order would result in the creation of a new Open Trade with a client Trade ID already in use.
	 */
	CLIENT_TRADE_ID_ALREADY_EXISTS,	///<

	/**
	 * Filling the Order would result in the creation of a guaranteed Stop Loss Order with a distance smaller than the configured minimum distance.
	 */
	STOP_LOSS_ON_FILL_GUARANTEED_MINIMUM_DISTANCE_NOT_MET,	///<

	/**
	 * Filling the Order would have resulted in a a FIFO violation.
	 */
	FIFO_VIOLATION,	///<

	/**
	 * Filling the Order would have resulted in the creation of a Stop Loss Order with a GTD time in the past.
	 */
	STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST,	///<

	/**
	 * Filling the Order would result in the creation of a guaranteed Stop Loss Order for a hedged Trade, however the Account’s configuration does not allow guaranteed Stop Loss Orders for hedged Trades/Positions.
	 */
	STOP_LOSS_ON_FILL_GUARANTEED_HEDGING_NOT_ALLOWED,	///<

	/**
	 * Filling the Order would result in the creation of a Guaranteed Stop Loss Order (GSLO). Since the trade is long the GSLO would be short, however the bid side is currently halted. GSLOs cannot be created in this situation.
	 */
	STOP_LOSS_ON_FILL_GUARANTEED_BID_HALTED,	///<

	/**
	 * Filling the order would require the creation of a long trade, however the instrument is configured such that orders being filled using ask prices can only reduce existing positions. New long positions cannot be created, but existing short positions may be reduced or closed.
	 */
	INSTRUMENT_ASK_REDUCE_ONLY,	///<

	/**
	 * Filling the Order would result in the creation of a Trade, however there already exists an opposing (hedged) Trade that has a guaranteed Stop Loss Order attached to it. Guaranteed Stop Loss Orders cannot be combined with hedged positions.
	 */
	HEDGING_GSLO_VIOLATION,	///<

	/**
	 * Filling the Order wasn’t possible because the Order’s instrument was halted.
	 */
	MARKET_HALTED,	///<

	/**
	 * Filling the Order would result in the creation of a Stop Loss Order whose TriggerCondition value is invalid. A likely cause would be if the stop loss order is guaranteed and the TimeInForce is not TRIGGER_DEFAULT or TRIGGER_BID for a long trade, or not TRIGGER_DEFAULT or TRIGGER_ASK for a short trade.
	 */
	STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID,	///<

	/**
	 * Filling the Order would have resulted in the creation of a Trailing Stop Loss Order with a GTD time in the past.
	 */
	TRAILING_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST,	///<

	/**
	 * Filling the Order would have resulted in the creation of a Guaranteed Stop Loss Order with a client Order ID that is already in use.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS,	///<

	/**
	 * Filling the Order would result in the creation of a guaranteed Stop Loss Order, however the Account’s configuration does not allow guaranteed Stop Loss Orders.
	 */
	STOP_LOSS_ON_FILL_GUARANTEED_NOT_ALLOWED,	///<

	/**
	 * The Order was cancelled because at the time of filling the account was locked.
	 */
	ACCOUNT_LOCKED,	///<

	/**
	 * Filling the Order would result in the creation of a Take Profit Loss Order that would close the new Trade at a loss when filled.
	 */
	LOSING_TAKE_PROFIT,	///<

	/**
	 * Filling the Order would result in the creation of a Take Profit Order that would have been filled immediately, closing the new Trade at a loss.
	 */
	TAKE_PROFIT_ON_FILL_LOSS,	///<

	/**
	 * Filling the order would require using the ask, however the instrument is configured such that the asks are halted, and so no long orders may be filled.
	 */
	INSTRUMENT_ASK_HALTED,	///<

	/**
	 * The Order was cancelled explicitly at the request of the client.
	 */
	CLIENT_REQUEST,	///<

	/**
	 * Filling the Order wasn’t possible because enough liquidity available.
	 */
	INSUFFICIENT_LIQUIDITY,	///<

	/**
	 * Filling the Order wasn’t possible because it required the creation of a dependent Order and the Account is locked for Order creation.
	 */
	ACCOUNT_ORDER_CREATION_LOCKED	///<
};

/**
 * A client-provided identifier, used by clients to refer to their Orders or Trades with an identifier that they have provided.
 * my_order_id
 */
using ClientID = oanda::v20::common::String;

/**
 * A client-provided tag that can contain any data and may be assigned to their Orders or Trades. Tags are typically used to associate groups of Trades and/or Orders together.
 * client_tag_1
 */
using ClientTag = oanda::v20::common::String;

/**
 * A client-provided comment that can contain any data and may be assigned to their Orders or Trades. Comments are typically used to provide extra context or meaning to an Order or Trade.
 * This is a client comment
 */
using ClientComment = oanda::v20::common::String;

/**
 * The reason that the Market Order was created to perform a margin closeout
 */
enum class MarketOrderMarginCloseoutReason {
	UNDEFINED = 0,	///< Default value allows json to be blank
	REGULATORY_MARGIN_CALL_VIOLATION,	///< Trade closures came from a margin closeout event resulting from regulatory conditions placed on the Account’s margin call
	REGULATORY_MARGIN_CHECK_VIOLATION,	///< Trade closures resulted from violating the margin policy imposed by regulatory requirements
	MARGIN_CHECK_VIOLATION				///< Trade closures resulted from violating OANDA’s margin policy
};

/**
 * The request identifier.
 * 
 */
using RequestID = oanda::v20::common::String;

/**
 * A client provided request identifier.
 * my_request_id
 */
using ClientRequestID = oanda::v20::common::String;

/**
 * The reason that a Transaction was rejected.
 */
enum class TransactionRejectReason {
	UNDEFINED = 0,	///< Default value allows json to be blank

	/**
	 * An attempt was made to create a guaranteed Stop Loss Order, however the distance between the current price and the trigger price does not meet the Account’s configured minimum Guaranteed Stop Loss distance.
	 */
	STOP_LOSS_ORDER_GUARANTEED_MINIMUM_DISTANCE_NOT_MET,	///<

	/**
	 * The Account had insufficient margin to perform the action specified. One possible reason for this is due to the creation or modification of a guaranteed StopLoss Order.
	 */
	INSUFFICIENT_MARGIN,	///<

	/**
	 * The Guaranteed Stop Loss on fill specified does not provide a price
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_PRICE_MISSING,	///<

	/**
	 * The Take Profit on fill specified contains a price with more precision than is allowed by the Order’s instrument
	 */
	TAKE_PROFIT_ON_FILL_PRICE_PRECISION_EXCEEDED,	///<

	/**
	 * The units specified contain more precision than is allowed for the Order’s instrument
	 */
	UNITS_PRECISION_EXCEEDED,	///<

	/**
	 * The Guaranteed Stop Loss Order request contains neither the price nor distance fields.
	 */
	GUARANTEED_STOP_LOSS_ORDER_PRICE_AND_DISTANCE_BOTH_MISSING,	///<

	/**
	 * The Stop Loss Order would be in violation of the risk management Order mutual exclusivity configuration specifying that only one risk management order can be attached to a Trade.
	 */
	STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION,	///<

	/**
	 * The Take Profit on fill specified contains an invalid price
	 */
	TAKE_PROFIT_ON_FILL_PRICE_INVALID,	///<

	/**
	 * The Trailing Stop Loss on fill client Order tag specified is invalid
	 */
	TRAILING_STOP_LOSS_ON_FILL_CLIENT_ORDER_TAG_INVALID,	///<

	/**
	 * The Guaranteed Stop Loss on fill client Order comment specified is invalid.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_CLIENT_ORDER_COMMENT_INVALID,	///<

	/**
	 * An attempt to create a guaranteed stop loss order with a price that is within the current tradeable spread.
	 */
	STOP_LOSS_ORDER_GUARANTEED_PRICE_WITHIN_SPREAD,	///<

	/**
	 * The price distance exceeds that maximum allowed amount
	 */
	PRICE_DISTANCE_MAXIMUM_EXCEEDED,	///<

	/**
	 * The PositionAggregationMode provided is not supported/valid.
	 */
	POSITION_AGGREGATION_MODE_INVALID,	///<

	/**
	 * An attempt to create a pending Order was made with a Guaranteed Stop Loss Order on fill that was explicitly configured to be guaranteed, however the Account’s configuration does not allow guaranteed Stop Loss Orders.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_NOT_ALLOWED,	///<

	/**
	 * An attempt was made to create a Guaranteed Stop Loss Order when the market was open.
	 */
	GUARANTEED_STOP_LOSS_ORDER_CREATE_VIOLATION,	///<

	/**
	 * An attempt was made to cancel and replace a Guaranteed Stop Loss Order when the market is open, however the Account’s configuration prevents the modification of Guaranteed Stop Loss Orders.
	 */
	GUARANTEED_STOP_LOSS_ORDER_NOT_REPLACEABLE,	///<

	/**
	 * The Stop Loss Order request contains neither the price nor distance fields.
	 */
	STOP_LOSS_ORDER_PRICE_AND_DISTANCE_BOTH_MISSING,	///<

	/**
	 * The Guaranteed Stop Loss Order would be in violation of the risk management Order mutual exclusivity configuration specifying that if a GSLO is already attached to a Trade, no other risk management Order can be attached to the same Trade.
	 */
	GUARANTEED_STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_GSLO_EXCLUDES_OTHERS_VIOLATION,	///<

	/**
	 * The Account is locked for deposits
	 */
	ACCOUNT_DEPOSIT_LOCKED,	///<

	/**
	 * The client Trade tag specified is invalid
	 */
	CLIENT_TRADE_TAG_INVALID,	///<

	/**
	 * The Take Profit on fill specifies an invalid TimeInForce
	 */
	TAKE_PROFIT_ON_FILL_TIME_IN_FORCE_INVALID,	///<

	/**
	 * Neither the Trade ID nor client Trade ID are specified
	 */
	TRADE_ID_UNSPECIFIED,	///<

	/**
	 * A Trailing Stop Loss Order for the specified Trade already exists
	 */
	TRAILING_STOP_LOSS_ORDER_ALREADY_EXISTS,	///<

	/**
	 * An attempt was made to create a guaranteed Stop Loss Order, however doing so would exceed the Account’s configured guaranteed StopLoss Order level restriction volume.
	 */
	STOP_LOSS_ORDER_GUARANTEED_LEVEL_RESTRICTION_EXCEEDED,	///<

	/**
	 * The Take Profit on fill specifies an invalid TriggerCondition
	 */
	TAKE_PROFIT_ON_FILL_TRIGGER_CONDITION_INVALID,	///<

	/**
	 * The Order to be replaced has a different type than the replacing Order.
	 */
	REPLACING_ORDER_INVALID,	///<

	/**
	 * The Guaranteed Stop Loss on fill client Order ID specified is invalid
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_INVALID,	///<

	/**
	 * The Stop Loss on fill contains both the price and distance fields.
	 */
	STOP_LOSS_ON_FILL_PRICE_AND_DISTANCE_BOTH_SPECIFIED,	///<

	/**
	 * The client Trade ID specified is invalid
	 */
	CLIENT_TRADE_ID_INVALID,	///<

	/**
	 * The request to close a Trade partially did not specify the number of units to close
	 */
	CLOSE_TRADE_PARTIAL_UNITS_MISSING,	///<

	/**
	 * The Stop Loss on fill distance is invalid
	 */
	STOP_LOSS_ON_FILL_DISTANCE_INVALID,	///<

	/**
	 * The TriggerCondition specified is invalid
	 */
	TRIGGER_CONDITION_INVALID,	///<

	/**
	 * The client Order ID specified is already assigned to another pending Order
	 */
	CLIENT_ORDER_ID_ALREADY_EXISTS,	///<

	/**
	 * An attempt to create a guaranteed stop loss order with a price that is within the current tradeable spread.
	 */
	GUARANTEED_STOP_LOSS_ORDER_PRICE_WITHIN_SPREAD,	///<

	/**
	 * The TimeInForce field has not been specified
	 */
	TIME_IN_FORCE_MISSING,	///<

	/**
	 * Filling the Order would result in the creation of a Guaranteed Stop Loss Order with trigger number of units that violates the account’s Guaranteed Stop Loss Order level restriction volume.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_LEVEL_RESTRICTION_VOLUME_EXCEEDED,	///<

	/**
	 * The units specified is less than the minimum number of units required
	 */
	UNITS_MINIMUM_NOT_MET,	///<

	/**
	 * An attempt was made to re-create a Guaranteed Stop Loss Order with a tighter fill price when the market was halted.
	 */
	GUARANTEED_STOP_LOSS_ORDER_HALTED_TIGHTEN_VIOLATION,	///<

	/**
	 * Order units have not been not specified
	 */
	UNITS_MISSING,	///<

	/**
	 * An attempt to create a pending Order was made with a Guaranteed Stop Loss Order on fill that was explicitly configured to be not guaranteed, however the Account’s configuration requires Guaranteed Stop Loss Orders.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_REQUIRED,	///<

	/**
	 * The Trade specified does not exist
	 */
	TRADE_DOESNT_EXIST,	///<

	/**
	 * The price specified is invalid
	 */
	PRICE_INVALID,	///<

	/**
	 * The OrderFillPositionAction field has not been specified
	 */
	ORDER_PARTIAL_FILL_OPTION_MISSING,	///<

	/**
	 * The Trailing Stop Loss on fill specified does not provide a TriggerCondition
	 */
	TRAILING_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_MISSING,	///<

	/**
	 * The Stop Loss on fill specified does not provide a TriggerCondition
	 */
	STOP_LOSS_ON_FILL_TRIGGER_CONDITION_MISSING,	///<

	/**
	 * The Orders on fill would be in violation of the risk management Order mutual exclusivity configuration specifying that only one risk management Order can be attached to a Trade.
	 */
	ORDERS_ON_FILL_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION,	///<

	/**
	 * Neither the Order ID nor client Order ID are specified
	 */
	ORDER_ID_UNSPECIFIED,	///<

	/**
	 * The margin rate provided would cause an immediate margin closeout
	 */
	MARGIN_RATE_WOULD_TRIGGER_CLOSEOUT,	///<

	/**
	 * The Order specified does not exist
	 */
	ORDER_DOESNT_EXIST,	///<

	/**
	 * An attempt was made to create a Guaranteed Stop Loss Order, however the Account’s configuration does not allow Guaranteed Stop Loss Orders.
	 */
	GUARANTEED_STOP_LOSS_ORDER_NOT_ALLOWED,	///<

	/**
	 * The Stop Loss Order request contains both the price and distance fields.
	 */
	STOP_LOSS_ORDER_PRICE_AND_DISTANCE_BOTH_SPECIFIED,	///<

	/**
	 * The Guaranteed Stop Loss on fill distance is invalid
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_DISTANCE_INVALID,	///<

	/**
	 * An attempt was made to create a Guaranteed Stop Loss Order, however doing so would exceed the Account’s configured guaranteed StopLoss Order level restriction volume.
	 */
	GUARANTEED_STOP_LOSS_ORDER_LEVEL_RESTRICTION_VOLUME_EXCEEDED,	///<

	/**
	 * The Order ID and client Order ID specified do not identify the same Order
	 */
	ORDER_IDENTIFIER_INCONSISTENCY,	///<

	/**
	 * The price bound specified is invalid
	 */
	PRICE_BOUND_INVALID,	///<

	/**
	 * The request to close a Trade does not specify a full or partial close
	 */
	CLOSE_TRADE_TYPE_MISSING,	///<

	/**
	 * The Trailing Stop Loss on fill price distance does not meet the minimum allowed amount
	 */
	TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MINIMUM_NOT_MET,	///<

	/**
	 * The Trailing Stop Loss Order would be in violation of the risk management Order mutual exclusivity configuration specifying that only one risk management order can be attached to a Trade.
	 */
	TRAILING_STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION,	///<

	/**
	 * The Guaranteed Stop Loss on fill contains neither the price nor distance fields.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_PRICE_AND_DISTANCE_BOTH_MISSING,	///<

	/**
	 * The Guaranteed Stop Loss on fill specifies a price with more precision than is allowed by the Order’s instrument
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_PRICE_PRECISION_EXCEEDED,	///<

	/**
	 * The Take Profit on fill specified does not provide a TimeInForce
	 */
	TAKE_PROFIT_ON_FILL_TIME_IN_FORCE_MISSING,	///<

	/**
	 * The Guaranteed Stop Loss on fill client Order tag specified is invalid
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_CLIENT_ORDER_TAG_INVALID,	///<

	/**
	 * The Stop Loss on fill client Order tag specified is invalid
	 */
	STOP_LOSS_ON_FILL_CLIENT_ORDER_TAG_INVALID,	///<

	/**
	 * The Take Profit on fill specified does not provide a TriggerCondition
	 */
	TAKE_PROFIT_ON_FILL_TRIGGER_CONDITION_MISSING,	///<

	/**
	 * Canceling the order would cause an immediate margin closeout.
	 */
	ORDER_CANCEL_WOULD_TRIGGER_CLOSEOUT,	///<

	/**
	 * The list of Order Identifiers provided for a One Cancels All Order contains an Order Identifier that refers to a Stop Loss Order. OCA groups cannot contain Stop Loss Orders.
	 */
	OCA_ORDER_IDS_STOP_LOSS_NOT_ALLOWED,	///<

	/**
	 * Creating the Order would result in the maximum number of allowed pending Orders being exceeded
	 */
	PENDING_ORDERS_ALLOWED_EXCEEDED,	///<

	/**
	 * An attempt to create a pending Order was made with no Stop Loss Order on fill specified and the Account’s configuration requires that every Trade have an associated Stop Loss Order.
	 */
	STOP_LOSS_ON_FILL_REQUIRED_FOR_PENDING_ORDER,	///<

	/**
	 * An attempt was made to re-create a guaranteed Stop Loss Order with a tighter fill price when the market was halted.
	 */
	STOP_LOSS_ORDER_GUARANTEED_HALTED_TIGHTEN_VIOLATION,	///<

	/**
	 * The Trailing Stop Loss Order would be in violation of the risk management Order mutual exclusivity configuration specifying that if a GSLO is already attached to a Trade, no other risk management Order can be attached to the same Trade.
	 */
	TRAILING_STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_GSLO_EXCLUDES_OTHERS_VIOLATION,	///<

	/**
	 * Order instrument has not been specified
	 */
	INSTRUMENT_MISSING,	///<

	/**
	 * The TriggerCondition field has not been specified
	 */
	TRIGGER_CONDITION_MISSING,	///<

	/**
	 * The price distance does not meet the minimum allowed amount
	 */
	PRICE_DISTANCE_MINIMUM_NOT_MET,	///<

	/**
	 * The Take Profit on fill specifies a GTD TimeInForce but does not provide a GTD timestamp
	 */
	TAKE_PROFIT_ON_FILL_GTD_TIMESTAMP_MISSING,	///<

	/**
	 * The Take Profit on fill specified does not provide a price
	 */
	TAKE_PROFIT_ON_FILL_PRICE_MISSING,	///<

	/**
	 * The Guaranteed Stop Loss on fill specifies an invalid TriggerCondition.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID,	///<

	/**
	 * The Take Profit on fill specifies a GTD timestamp that is in the past
	 */
	TAKE_PROFIT_ON_FILL_GTD_TIMESTAMP_IN_PAST,	///<

	/**
	 * An attempt was made to create a Guaranteed Stop Loss Order when the market was halted.
	 */
	GUARANTEED_STOP_LOSS_ORDER_HALTED_CREATE_VIOLATION,	///<

	/**
	 * The price distance specified is invalid
	 */
	PRICE_DISTANCE_INVALID,	///<

	/**
	 * The margin rate provided is invalid
	 */
	MARGIN_RATE_INVALID,	///<

	/**
	 * The price has not been specified
	 */
	PRICE_MISSING,	///<

	/**
	 * An attempt was made to create a guaranteed Stop Loss Order when the market was halted.
	 */
	STOP_LOSS_ORDER_GUARANTEED_HALTED_CREATE_VIOLATION,	///<

	/**
	 * The request to partially closeout a Position did not specify the number of units to close.
	 */
	CLOSEOUT_POSITION_PARTIAL_UNITS_MISSING,	///<

	/**
	 * The Trailing Stop Loss on fill distance is invalid
	 */
	TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_INVALID,	///<

	/**
	 * The Stop Loss on fill specifies a price with more precision than is allowed by the Order’s instrument
	 */
	STOP_LOSS_ON_FILL_PRICE_PRECISION_EXCEEDED,	///<

	/**
	 * The system was unable to determine the current price for the Order’s instrument
	 */
	INSTRUMENT_PRICE_UNKNOWN,	///<

	/**
	 * The Guaranteed Stop Loss on fill price distance exceeds the maximum allowed amount.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED,	///<

	/**
	 * The Take Profit Order would cause the associated Trade to be in violation of the FIFO violation safeguard constraints.
	 */
	TAKE_PROFIT_ORDER_WOULD_VIOLATE_FIFO_VIOLATION_SAFEGUARD,	///<

	/**
	 * The request to closeout a Position could not be fully satisfied
	 */
	CLOSEOUT_POSITION_REJECT,	///<

	/**
	 * The client Order comment specified is invalid
	 */
	CLIENT_ORDER_COMMENT_INVALID,	///<

	/**
	 * Funding is not possible because the requested transfer amount is invalid
	 */
	AMOUNT_INVALID,	///<

	/**
	 * The request to partially close a Trade specifies a number of units that exceeds the current size of the given Trade
	 */
	CLOSE_TRADE_UNITS_EXCEED_TRADE_SIZE,	///<

	/**
	 * An attempt was made to cancel and replace a Guaranteed Stop Loss Order when the market is halted, however the Account’s configuration prevents the modification of Guaranteed Stop Loss Orders.
	 */
	GUARANTEED_STOP_LOSS_ORDER_HALTED_NOT_REPLACEABLE,	///<

	/**
	 * The TimeInForce is GTD but the GTD timestamp is in the past
	 */
	TIME_IN_FORCE_GTD_TIMESTAMP_IN_PAST,	///<

	/**
	 * The Guaranteed Stop Loss on fill specifies an invalid TimeInForce
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID,	///<

	/**
	 * The Take Profit on fill client Order comment specified is invalid
	 */
	TAKE_PROFIT_ON_FILL_CLIENT_ORDER_COMMENT_INVALID,	///<

	/**
	 * The Trade ID and client Trade ID specified do not identify the same Trade
	 */
	TRADE_IDENTIFIER_INCONSISTENCY,	///<

	/**
	 * The Guaranteed Stop Loss Order would cause the associated Trade to be in violation of the FIFO violation safeguard constraints
	 */
	GUARANTEED_STOP_LOSS_ORDER_WOULD_VIOLATE_FIFO_VIOLATION_SAFEGUARD,	///<

	/**
	 * An attempt was made to cancel a Stop Loss Order, however the Account’s configuration requires every Trade have an associated Stop Loss Order.
	 */
	STOP_LOSS_ORDER_NOT_CANCELABLE,	///<

	/**
	 * The Stop Loss on fill specifies an invalid price
	 */
	STOP_LOSS_ON_FILL_PRICE_INVALID,	///<

	/**
	 * A Take Profit Order for the specified Trade already exists
	 */
	TAKE_PROFIT_ORDER_ALREADY_EXISTS,	///<

	/**
	 * The Stop Loss on fill specifies an invalid TimeInForce
	 */
	STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID,	///<

	/**
	 * The price bound specified contains more precision than is allowed for the Order’s instrument
	 */
	PRICE_BOUND_PRECISION_EXCEEDED,	///<

	/**
	 * Filling the Order would result in the creation of a Guaranteed Stop Loss Order with trigger price that violates the account’s Guaranteed Stop Loss Order level restriction price range.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_LEVEL_RESTRICTION_PRICE_RANGE_EXCEEDED,	///<

	/**
	 * An attempt to create a pending Order was made with a Stop Loss Order on fill that was explicitly configured to be not guaranteed, however the Account’s configuration requires guaranteed Stop Loss Orders.
	 */
	STOP_LOSS_ON_FILL_GUARANTEED_REQUIRED,	///<

	/**
	 * The Stop Loss on fill client Order comment specified is invalid
	 */
	STOP_LOSS_ON_FILL_CLIENT_ORDER_COMMENT_INVALID,	///<

	/**
	 * The Guaranteed Stop Loss Order would be in violation of the risk management Order mutual exclusivity configuration specifying that only one risk management order can be attached to a Trade.
	 */
	GUARANTEED_STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_MUTUALLY_EXCLUSIVE_VIOLATION,	///<

	/**
	 * The Stop Loss Order would cause the associated Trade to be in violation of the FIFO violation safeguard constraints
	 */
	STOP_LOSS_ORDER_WOULD_VIOLATE_FIFO_VIOLATION_SAFEGUARD,	///<

	/**
	 * An attempt was made to create a guaranteed Stop Loss Order, however the Account’s configuration does not allow guaranteed Stop Loss Orders.
	 */
	STOP_LOSS_ORDER_GUARANTEED_NOT_ALLOWED,	///<

	/**
	 * The OrderFillPositionAction specified is invalid
	 */
	ORDER_FILL_POSITION_ACTION_INVALID,	///<

	/**
	 * The Account is locked for withdrawals
	 */
	ACCOUNT_WITHDRAWAL_LOCKED,	///<

	/**
	 * The Position requested to be closed out does not exist
	 */
	CLOSEOUT_POSITION_DOESNT_EXIST,	///<

	/**
	 * An attempt was made to to create a non-guaranteed stop loss order in an account that requires all stop loss orders to be guaranteed.
	 */
	GUARANTEED_STOP_LOSS_ORDER_REQUIRED,	///<

	/**
	 * The TimeInForce is GTD but no GTD timestamp is provided
	 */
	TIME_IN_FORCE_GTD_TIMESTAMP_MISSING,	///<

	/**
	 * The Guaranteed Stop Loss on fill specified does not provide a TriggerCondition.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_MISSING,	///<

	/**
	 * The Guaranteed Stop Loss on fill distance contains more precision than is allowed by the instrument
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_DISTANCE_PRECISION_EXCEEDED,	///<

	/**
	 * An attempt to create a pending Order was made with the distance between the Guaranteed Stop Loss Order on fill’s price and the pending Order’s price is less than the Account’s configured minimum guaranteed stop loss distance.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_MINIMUM_DISTANCE_NOT_MET,	///<

	/**
	 * The client Order tag specified is invalid
	 */
	CLIENT_ORDER_TAG_INVALID,	///<

	/**
	 * The price distance has not been specified
	 */
	PRICE_DISTANCE_MISSING,	///<

	/**
	 * Multiple Orders on fill share the same client Order ID
	 */
	ORDERS_ON_FILL_DUPLICATE_CLIENT_ORDER_IDS,	///<

	/**
	 * No configuration parameters provided
	 */
	ADMIN_CONFIGURE_DATA_MISSING,	///<

	/**
	 * The Trailing Stop Loss on fill specifies an invalid TimeInForce
	 */
	TRAILING_STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID,	///<

	/**
	 * When attempting to reissue an order (currently only a MarketIfTouched) that was immediately partially filled, it is not possible to create a correct pending Order.
	 */
	INVALID_REISSUE_IMMEDIATE_PARTIAL_FILL,	///<

	/**
	 * An attempt to create a pending Order was made with a guaranteed Stop Loss Order on fill configured, and the Order’s units exceed the Account’s configured guaranteed StopLoss Order level restriction volume.
	 */
	STOP_LOSS_ON_FILL_GUARANTEED_LEVEL_RESTRICTION_EXCEEDED,	///<

	/**
	 * An attempt was made to create a Guaranteed Stop Loss Order on a hedged Trade (ie there is an existing open Trade in the opposing direction), however the Account’s configuration does not allow Guaranteed Stop Loss Orders for hedged Trades/Positions.
	 */
	GUARANTEED_STOP_LOSS_ORDER_HEDGING_NOT_ALLOWED,	///<

	/**
	 * The Stop Loss on fill contains neither the price nor distance fields.
	 */
	STOP_LOSS_ON_FILL_PRICE_AND_DISTANCE_BOTH_MISSING,	///<

	/**
	 * The request to closeout a Position was specified incompletely
	 */
	CLOSEOUT_POSITION_INCOMPLETE_SPECIFICATION,	///<

	/**
	 * The Stop Loss on fill distance contains more precision than is allowed by the instrument
	 */
	STOP_LOSS_ON_FILL_DISTANCE_PRECISION_EXCEEDED,	///<

	/**
	 * An attempt was made to create a guaranteed Stop Loss Order on a hedged Trade (ie there is an existing open Trade in the opposing direction), however the Account’s configuration does not allow guaranteed Stop Loss Orders for hedged Trades/Positions.
	 */
	STOP_LOSS_ORDER_GUARANTEED_HEDGING_NOT_ALLOWED,	///<

	/**
	 * The markup group ID provided is invalid
	 */
	MARKUP_GROUP_ID_INVALID,	///<

	/**
	 * The Stop Loss on fill price distance exceeds the maximum allowed amount
	 */
	STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED,	///<

	/**
	 * An unexpected internal server error has occurred
	 */
	INTERNAL_SERVER_ERROR,	///<

	/**
	 * The Guaranteed Stop Loss on fill specified does not provide a TimeInForce
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_TIME_IN_FORCE_MISSING,	///<

	/**
	 * An attempt was made to to create a non-guaranteed stop loss order in an account that requires all stop loss orders to be guaranteed.
	 */
	STOP_LOSS_ORDER_GUARANTEED_REQUIRED,	///<

	/**
	 * The price distance specified contains more precision than is allowed for the instrument
	 */
	PRICE_DISTANCE_PRECISION_EXCEEDED,	///<

	/**
	 * No configuration parameters provided
	 */
	CLIENT_CONFIGURE_DATA_MISSING,	///<

	/**
	 * The price specified contains more precision than is allowed for the instrument
	 */
	PRICE_PRECISION_EXCEEDED,	///<

	/**
	 * An attempt was made to cancel a Guaranteed Stop Loss Order when the market is halted, however the Account’s configuration requires every Trade have an associated Guaranteed Stop Loss Order.
	 */
	GUARANTEED_STOP_LOSS_ORDER_HALTED_NOT_CANCELABLE,	///<

	/**
	 * The instrument specified is unknown
	 */
	INSTRUMENT_UNKNOWN,	///<

	/**
	 * An attempt was made to cancel a Guaranteed Stop Loss Order when the market is open, however the Account’s configuration requires every Trade have an associated Guaranteed Stop Loss Order.
	 */
	GUARANTEED_STOP_LOSS_ORDER_NOT_CANCELABLE,	///<

	/**
	 * The Account is locked for Order cancellation
	 */
	ACCOUNT_ORDER_CANCEL_LOCKED,	///<

	/**
	 * The Stop Loss on fill specified does not provide a TimeInForce
	 */
	STOP_LOSS_ON_FILL_TIME_IN_FORCE_MISSING,	///<

	/**
	 * The Guaranteed Stop Loss on fill specifies a GTD TimeInForce but does not provide a GTD timestamp
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_MISSING,	///<

	/**
	 * An attempt was made to re-create a Guaranteed Stop Loss Order with a tighter fill price when the market was open.
	 */
	GUARANTEED_STOP_LOSS_ORDER_TIGHTEN_VIOLATION,	///<

	/**
	 * The Trailing Stop Loss on fill specified does not provide a distance
	 */
	TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MISSING,	///<

	/**
	 * The Guaranteed Stop Loss on fill specifies a GTD timestamp that is in the past.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST,	///<

	/**
	 * The Take Profit on fill client Order ID specified is invalid
	 */
	TAKE_PROFIT_ON_FILL_CLIENT_ORDER_ID_INVALID,	///<

	/**
	 * The units specified exceeds the maximum number of units allowed
	 */
	UNITS_LIMIT_EXCEEDED,	///<

	/**
	 * The Guaranteed Stop Loss on fill contains both the price and distance fields.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_PRICE_AND_DISTANCE_BOTH_SPECIFIED,	///<

	/**
	 * An attempt was made to cancel and replace a Stop Loss Order, however the Account’s configuration prevents the modification of Stop Loss Orders.
	 */
	STOP_LOSS_ORDER_NOT_REPLACEABLE,	///<

	/**
	 * A client attempted to create either a Trailing Stop Loss order or an order with a Trailing Stop Loss On Fill specified, which may not yet be supported.
	 */
	TRAILING_STOP_LOSS_ORDERS_NOT_SUPPORTED,	///<

	/**
	 * The Guaranteed Stop Loss on fill specifies an invalid price
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_PRICE_INVALID,	///<

	/**
	 * The OrderFillPositionAction field has not been specified
	 */
	ORDER_FILL_POSITION_ACTION_MISSING,	///<

	/**
	 * The TimeInForce specified is invalid
	 */
	TIME_IN_FORCE_INVALID,	///<

	/**
	 * The Stop Loss on fill specifies a GTD TimeInForce but does not provide a GTD timestamp
	 */
	STOP_LOSS_ON_FILL_GTD_TIMESTAMP_MISSING,	///<

	/**
	 * An attempt to create a pending Order was made with the distance between the guaranteed Stop Loss Order on fill’s price and the pending Order’s price is less than the Account’s configured minimum guaranteed stop loss distance.
	 */
	STOP_LOSS_ON_FILL_GUARANTEED_MINIMUM_DISTANCE_NOT_MET,	///<

	/**
	 * The client Trade ID specified is already assigned to another open Trade
	 */
	CLIENT_TRADE_ID_ALREADY_EXISTS,	///<

	/**
	 * The client Order ID specified is invalid
	 */
	CLIENT_ORDER_ID_INVALID,	///<

	/**
	 * Funding amount has not been specified
	 */
	AMOUNT_MISSING,	///<

	/**
	 * The Account does not have sufficient balance to complete the funding request
	 */
	INSUFFICIENT_FUNDS,	///<

	/**
	 * The Stop Loss on fill specifies a GTD timestamp that is in the past
	 */
	STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST,	///<

	/**
	 * A partial Position closeout request specifies a number of units that exceeds the current Position
	 */
	CLOSEOUT_POSITION_UNITS_EXCEED_POSITION_SIZE,	///<

	/**
	 * The Orders on fill would be in violation of the risk management Order mutual exclusivity configuration specifying that if a GSLO is already attached to a Trade, no other risk management Order can be attached to a Trade.
	 */
	ORDERS_ON_FILL_RMO_MUTUAL_EXCLUSIVITY_GSLO_EXCLUDES_OTHERS_VIOLATION,	///<

	/**
	 * The client Trade comment is invalid
	 */
	CLIENT_TRADE_COMMENT_INVALID,	///<

	/**
	 * The Trailing Stop Loss on fill specified does not provide a TimeInForce
	 */
	TRAILING_STOP_LOSS_ON_FILL_TIME_IN_FORCE_MISSING,	///<

	/**
	 * The Stop Loss Order would be in violation of the risk management Order mutual exclusivity configuration specifying that if a GSLO is already attached to a Trade, no other risk management Order can be attached to the same Trade.
	 */
	STOP_LOSS_ORDER_RMO_MUTUAL_EXCLUSIVITY_GSLO_EXCLUDES_OTHERS_VIOLATION,	///<

	/**
	 * A Stop Loss Order for the specified Trade already exists
	 */
	STOP_LOSS_ORDER_ALREADY_EXISTS,	///<

	/**
	 * The Stop Loss on fill specified does not provide a price
	 */
	STOP_LOSS_ON_FILL_PRICE_MISSING,	///<

	/**
	 * The Tailing Stop Loss on fill specifies an invalid TriggerCondition
	 */
	TRAILING_STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID,	///<

	/**
	 * The Stop Loss on fill specifies an invalid TriggerCondition
	 */
	STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID,	///<

	/**
	 * The Account is locked for configuration
	 */
	ACCOUNT_CONFIGURATION_LOCKED,	///<

	/**
	 * The Guaranteed Stop Loss Order request contains both the price and distance fields.
	 */
	GUARANTEED_STOP_LOSS_ORDER_PRICE_AND_DISTANCE_BOTH_SPECIFIED,	///<

	/**
	 * An attempt to create a pending Order was made with no Guaranteed Stop Loss Order on fill specified and the Account’s configuration requires that every Trade have an associated Guaranteed Stop Loss Order.
	 */
	GUARANTEED_STOP_LOSS_ON_FILL_REQUIRED_FOR_PENDING_ORDER,	///<

	/**
	 * Neither Order nor Trade on Fill client extensions were provided for modification
	 */
	CLIENT_EXTENSIONS_DATA_MISSING,	///<

	/**
	 * The margin rate provided would cause the Account to enter a margin call state.
	 */
	MARGIN_RATE_WOULD_TRIGGER_MARGIN_CALL,	///<

	/**
	 * The Account is not active
	 */
	ACCOUNT_NOT_ACTIVE,	///<

	/**
	 * The replacing Order refers to a different Trade than the Order that is being replaced.
	 */
	REPLACING_TRADE_ID_INVALID,	///<

	/**
	 * The account alias string provided is invalid
	 */
	ALIAS_INVALID,	///<

	/**
	 * The Trailing Stop Loss on fill client Order ID specified is invalid
	 */
	TRAILING_STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_INVALID,	///<

	/**
	 * The Trailing Stop Loss on fill TimeInForce is specified as GTD but no GTD timestamp is provided
	 */
	TRAILING_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_MISSING,	///<

	/**
	 * The Trailing Stop Loss Order would cause the associated Trade to be in violation of the FIFO violation safeguard constraints
	 */
	TRAILING_STOP_LOSS_ORDER_WOULD_VIOLATE_FIFO_VIOLATION_SAFEGUARD,	///<

	/**
	 * The Take Profit on fill client Order tag specified is invalid
	 */
	TAKE_PROFIT_ON_FILL_CLIENT_ORDER_TAG_INVALID,	///<

	/**
	 * The Trailing Stop Loss on fill GTD timestamp is in the past
	 */
	TRAILING_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST,	///<

	/**
	 * The Trailing Stop Loss on fill price distance exceeds the maximum allowed amount
	 */
	TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED,	///<

	/**
	 * The Trailing Stop Loss on fill distance contains more precision than is allowed by the instrument
	 */
	TRAILING_STOP_LOSS_ON_FILL_PRICE_DISTANCE_PRECISION_EXCEEDED,	///<

	/**
	 * An attempt to create a pending Order was made with a Stop Loss Order on fill that was explicitly configured to be guaranteed, however the Account’s configuration does not allow guaranteed Stop Loss Orders.
	 */
	STOP_LOSS_ON_FILL_GUARANTEED_NOT_ALLOWED,	///<

	/**
	 * The Account is locked
	 */
	ACCOUNT_LOCKED,	///<

	/**
	 * Order units specified are invalid
	 */
	UNITS_INVALID,	///<

	/**
	 * An attempt was made to create a Guaranteed Stop Loss Order, however doing so would exceed the Account’s configured guaranteed StopLoss Order level restriction price range.
	 */
	GUARANTEED_STOP_LOSS_ORDER_LEVEL_RESTRICTION_PRICE_RANGE_EXCEEDED,	///<

	/**
	 * An attempt was made to create a Guaranteed Stop Loss Order, however the distance between the current price and the trigger price does not meet the Account’s configured minimum Guaranteed Stop Loss distance.
	 */
	GUARANTEED_STOP_LOSS_ORDER_MINIMUM_DISTANCE_NOT_MET,	///<
	GUARANTEED_STOP_LOSS_ORDER_ALREADY_EXISTS,	///< A Guaranteed Stop Loss Order for the specified Trade already exists
	ORDER_PARTIAL_FILL_OPTION_INVALID,	///< The OrderFillPositionAction specified is invalid.
	INSTRUMENT_NOT_TRADEABLE,	///< The instrument specified is not tradeable by the Account
	STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_INVALID,	///< The Stop Loss on fill client Order ID specified is invalid
	ACCOUNT_ORDER_CREATION_LOCKED,	///< The Account is locked for Order creation
	FUNDING_REASON_MISSING,	///< Funding reason has not been specified
	TRAILING_STOP_LOSS_ON_FILL_CLIENT_ORDER_COMMENT_INVALID,	///< The Trailing Stop Loss on fill client Order comment specified is invalid
	TRADE_ON_FILL_CLIENT_EXTENSIONS_NOT_SUPPORTED	///< The Order does not support Trade on fill client extensions because it cannot create a new Trade
};

/**
 * A filter that can be used when fetching Transactions
 */
enum class TransactionFilter {
	UNDEFINED = 0,	///< Default value allows json to be blank
	ORDER_CANCEL,							///< Order Cancel Transaction
	TRANSFER_FUNDS,							///< Transfer Funds Transaction
	RESET_RESETTABLE_PL,					///< Reset Resettable PL Transaction
	ONE_CANCELS_ALL_ORDER,					///< One Cancels All Order Transaction
	ORDER_CANCEL_REJECT,					///< Order Cancel Reject Transaction
	TRAILING_STOP_LOSS_ORDER,				///< Trailing Stop Loss Order Transaction
	TRAILING_STOP_LOSS_ORDER_REJECT,		///< Trailing Stop Loss Order Reject Transaction
	STOP_LOSS_ORDER_REJECT,					///< Stop Loss Order Reject Transaction
	CREATE,									///< Account Create Transaction
	ORDER_CLIENT_EXTENSIONS_MODIFY,			///< Order Client Extensions Modify Transaction
	ONE_CANCELS_ALL_ORDER_REJECT,			///< One Cancels All Order Reject Transaction
	GUARANTEED_STOP_LOSS_ORDER,				///< Guaranteed Stop Loss Order Transaction
	CLIENT_CONFIGURE,						///< Client Configuration Transaction
	ORDER_FILL,								///< Order Fill Transaction
	LIMIT_ORDER,							///< Limit Order Transaction
	ONE_CANCELS_ALL_ORDER_TRIGGERED,		///< One Cancels All Order Trigger Transaction
	CLIENT_CONFIGURE_REJECT,				///< Client Configuration Reject Transaction
	ORDER_CLIENT_EXTENSIONS_MODIFY_REJECT,	///< Order Client Extensions Modify Reject Transaction
	TRADE_CLIENT_EXTENSIONS_MODIFY,			///< Trade Client Extensions Modify Transaction
	DAILY_FINANCING,						///< Daily Financing Transaction
	MARKET_ORDER_REJECT,					///< Market Order Reject Transaction
	CLOSE,									///< Account Close Transaction
	GUARANTEED_STOP_LOSS_ORDER_REJECT,		///< Guaranteed Stop Loss Order Reject Transaction
	MARGIN_CALL_ENTER,						///< Margin Call Enter Transaction
	MARKET_ORDER,							///< Market Order Transaction
	TRADE_CLIENT_EXTENSIONS_MODIFY_REJECT,	///< Trade Client Extensions Modify Reject Transaction
	ORDER,									///< Order-related Transactions. These are the Transactions that create, cancel, fill or trigger Orders
	STOP_LOSS_ORDER,						///< Stop Loss Order Transaction
	MARGIN_CALL_EXTEND,						///< Margin Call Extend Transaction
	ADMIN,									///< Administrative Transactions
	DELAYED_TRADE_CLOSURE,					///< Delayed Trade Closure Transaction
	REOPEN,									///< Account Reopen Transaction
	TRANSFER_FUNDS_REJECT,					///< Transfer Funds Reject Transaction
	STOP_ORDER,								///< Stop Order Transaction
	LIMIT_ORDER_REJECT,						///< Limit Order Reject Transaction
	MARKET_IF_TOUCHED_ORDER,				///< Market if Touched Order Transaction
	TAKE_PROFIT_ORDER_REJECT,				///< Take Profit Order Reject Transaction
	MARKET_IF_TOUCHED_ORDER_REJECT,			///< Market if Touched Order Reject Transaction
	TAKE_PROFIT_ORDER,						///< Take Profit Order Transaction
	FUNDING,								///< Funding-related Transactions
	MARGIN_CALL_EXIT,						///< Margin Call Exit Transaction
	STOP_ORDER_REJECT						///< Stop Order Reject Transaction
};

} /* namespace transaction */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_TRANSACTION_TRANSACTIONDEFINITIONS_HPP */
