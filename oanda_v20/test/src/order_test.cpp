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
 * @file   order_test.cpp
 * @author Scott Brauer
 * @date   01-20-2021
 */

#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>

#include <gtest/gtest.h>

#include "../../include/oanda/v20/endpoint/OandaConnectionException.hpp"
#include "OandaEndpointsFixture.hpp"

#include "oanda/v20/endpoint/Order.hpp"
#include "WaitForMessage.hpp"
#include "GlobalVariables.hpp"

TEST_F (OandaEndpointsFixture, DISABLED_MarketOrder)
{
	oanda::v20::endpoint::order::marketorder::Request request;
	EXPECT_EQ(request.order.type, oanda::v20::order::OrderType::MARKET);
	EXPECT_EQ(request.order.timeInForce, oanda::v20::order::TimeInForce::FOK);
	EXPECT_EQ(request.order.positionFill, oanda::v20::order::OrderPositionFill::DEFAULT);


	oanda::v20::endpoint::order::marketorder::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	request.order.instrument = "EUR_USD";
	request.order.units = "100";

	oandaEndpoints().order.marketOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::marketorder::Response marketOrder) -> void {
		EXPECT_NE(marketOrder.requestID, "");

		// Close trade here
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_MarketOrderNoUnits)
{
	oanda::v20::endpoint::order::marketorder::Request request;
	oanda::v20::endpoint::order::marketorder::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	request.order.instrument = "EUR_USD";
	//request.order.units = "100";

	EXPECT_THROW({
		oandaEndpoints().order.marketOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::marketorder::Response marketOrder) -> void {
		});
	}, oanda::v20::endpoint::BadRequest);
}

TEST_F (OandaEndpointsFixture, DISABLED_LimitOrder)
{
	oanda::v20::endpoint::order::limitorder::Request request;
	EXPECT_EQ(request.order.type, oanda::v20::order::OrderType::LIMIT);
	EXPECT_EQ(request.order.timeInForce, oanda::v20::order::TimeInForce::GTC);
	EXPECT_EQ(request.order.positionFill, oanda::v20::order::OrderPositionFill::DEFAULT);

	oanda::v20::endpoint::order::limitorder::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	request.order.instrument = "EUR_USD";
	request.order.units = "100";
	request.order.price = "1.04482";
	request.order.takeProfitOnFill.price = "1.08000";
	request.order.stopLossOnFill.price = "1.03328";

	oandaEndpoints().order.limitOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::limitorder::Response limitOrder) -> void {
		EXPECT_GT(limitOrder.requestID, "");

		oanda::v20::endpoint::order::cancelorder::Request request;
		oanda::v20::endpoint::order::cancelorder::Parameters parameters;
		parameters.accountID = g_oandaAccountID;
		parameters.orderSpecifier = limitOrder.orderCreateTransaction.id;
		std::this_thread::sleep_for (std::chrono::microseconds(500));
		oandaEndpoints().order.cancelOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::cancelorder::Response cancelOrder) -> void {

		});
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_StopOrder)
{
	oanda::v20::endpoint::order::stoporder::Request request;
	EXPECT_EQ(request.order.type, oanda::v20::order::OrderType::STOP);
	EXPECT_EQ(request.order.timeInForce, oanda::v20::order::TimeInForce::GTC);
	EXPECT_EQ(request.order.positionFill, oanda::v20::order::OrderPositionFill::DEFAULT);
	EXPECT_EQ(request.order.triggerCondition, oanda::v20::order::OrderTriggerCondition::DEFAULT);

	oanda::v20::endpoint::order::stoporder::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	request.order.instrument = "EUR_USD";
	request.order.units = "100";
	request.order.price = "1.04482";
	request.order.takeProfitOnFill.price = "1.08000";
	request.order.stopLossOnFill.price = "1.03328";

	oandaEndpoints().order.stopOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::limitorder::Response stopOrder) -> void {
		EXPECT_GT(stopOrder.requestID, "");
		/*
		oanda::v20::endpoint::order::cancelOrder::Request request;
		oanda::v20::endpoint::order::cancelOrder::Parameters parameters;
		parameters.accountID = g_oandaAccountID;
		parameters.orderSpecifier = stopOrder.orderFillTransaction.tradeOpened.tradeID;
		std::this_thread::sleep_for (std::chrono::microseconds(500));
		oandaEndpoints().order.cancelOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::cancelOrder::Response cancelOrder) -> void {

		});
		*/
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_MarketIfTouchedOrder)
{
	oanda::v20::endpoint::order::marketiftouchedorder::Request request;
	EXPECT_EQ(request.order.type, oanda::v20::order::OrderType::MARKET_IF_TOUCHED);
	EXPECT_EQ(request.order.timeInForce, oanda::v20::order::TimeInForce::GTC);
	EXPECT_EQ(request.order.positionFill, oanda::v20::order::OrderPositionFill::DEFAULT);

	oanda::v20::endpoint::order::marketiftouchedorder::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	request.order.instrument = "EUR_USD";
	request.order.units = "100";
	request.order.price = "1.04482";
	request.order.takeProfitOnFill.price = "1.08000";
	request.order.stopLossOnFill.price = "1.03328";

	oandaEndpoints().order.marketIfTouchedOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::marketiftouchedorder::Response marketIfTouchedOrder) -> void {
		EXPECT_GT(marketIfTouchedOrder.requestID, "");

		oanda::v20::endpoint::order::cancelorder::Request request;
		oanda::v20::endpoint::order::cancelorder::Parameters parameters;
		parameters.accountID = g_oandaAccountID;
		parameters.orderSpecifier = marketIfTouchedOrder.orderCreateTransaction.id;
		std::this_thread::sleep_for(std::chrono::microseconds(500));
		oandaEndpoints().order.cancelOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::cancelorder::Response cancelOrder) -> void {

		});
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_TakeProfitOrder)
{
	oanda::v20::endpoint::order::marketorder::Request request;
	oanda::v20::endpoint::order::marketorder::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	request.order.instrument = "EUR_USD";
	request.order.units = "100";

	oandaEndpoints().order.marketOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::marketorder::Response marketOrder) -> void {
		oanda::v20::endpoint::order::takeprofitorder::Request request;
		EXPECT_EQ(request.order.type, oanda::v20::order::OrderType::TAKE_PROFIT);
		EXPECT_EQ(request.order.timeInForce, oanda::v20::order::TimeInForce::GTC);
		EXPECT_EQ(request.order.triggerCondition, oanda::v20::order::OrderTriggerCondition::DEFAULT);
		request.order.tradeID = marketOrder.orderFillTransaction.tradeOpened.tradeID;
		request.order.price = std::to_string(std::stod(marketOrder.orderFillTransaction.tradeOpened.price) + 0.01);

		oanda::v20::endpoint::order::takeprofitorder::Parameters parameters;
		parameters.accountID = g_oandaAccountID;

		oandaEndpoints().order.takeProfitOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::takeprofitorder::Response takeProfitOrder) -> void {
			EXPECT_NE(takeProfitOrder.requestID, "");

			oanda::v20::endpoint::order::stoplossorder::Request request;
			EXPECT_EQ(request.order.type, oanda::v20::order::OrderType::STOP_LOSS);
			EXPECT_EQ(request.order.timeInForce, oanda::v20::order::TimeInForce::GTC);
			EXPECT_EQ(request.order.triggerCondition, oanda::v20::order::OrderTriggerCondition::DEFAULT);
			request.order.tradeID = marketOrder.orderFillTransaction.tradeOpened.tradeID;
			request.order.price = std::to_string(std::stod(marketOrder.orderFillTransaction.tradeOpened.price) - 0.01);

			oanda::v20::endpoint::order::stoplossorder::Parameters parameters;
			parameters.accountID = g_oandaAccountID;

			oandaEndpoints().order.stopLossOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::stoplossorder::Response stopLossOrder) -> void {
				EXPECT_NE(stopLossOrder.requestID, "");

				// Close trade here
			});
		});
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_GuaranteedStopLossOrder)
{
	oanda::v20::endpoint::order::marketorder::Request request;
	oanda::v20::endpoint::order::marketorder::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	request.order.instrument = "EUR_USD";
	request.order.units = "100";

	oandaEndpoints().order.marketOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::marketorder::Response marketOrder) -> void {
		EXPECT_GT(marketOrder.requestID, "");

		oanda::v20::endpoint::order::guaranteedstoplossorder::Request request;
		EXPECT_EQ(request.order.type, oanda::v20::order::OrderType::GUARANTEED_STOP_LOSS);
		EXPECT_EQ(request.order.timeInForce, oanda::v20::order::TimeInForce::GTC);
		EXPECT_EQ(request.order.triggerCondition, oanda::v20::order::OrderTriggerCondition::DEFAULT);

		oanda::v20::endpoint::order::guaranteedstoplossorder::Parameters parameters;
		parameters.accountID = g_oandaAccountID;
		request.order.tradeID = marketOrder.orderFillTransaction.id;
		request.order.price = "1.09";

		oandaEndpoints().order.guaranteedStopLossOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::guaranteedstoplossorder::Response guaranteedStopLossOrder) -> void {
		});
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_TrailingStopLossOrder)
{
	oanda::v20::endpoint::order::marketorder::Request request;
	oanda::v20::endpoint::order::marketorder::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	request.order.instrument = "EUR_USD";
	request.order.units = "100";

	oandaEndpoints().order.marketOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::marketorder::Response marketOrder) -> void {
		EXPECT_GT(marketOrder.requestID, "");

		oanda::v20::endpoint::order::trailingstoplossorder::Request request;
		EXPECT_EQ(request.order.type, oanda::v20::order::OrderType::GUARANTEED_STOP_LOSS);
		EXPECT_EQ(request.order.timeInForce, oanda::v20::order::TimeInForce::GTC);
		EXPECT_EQ(request.order.triggerCondition, oanda::v20::order::OrderTriggerCondition::DEFAULT);

		oanda::v20::endpoint::order::trailingstoplossorder::Parameters parameters;
		parameters.accountID = g_oandaAccountID;
		request.order.tradeID = marketOrder.orderFillTransaction.id;
		request.order.distance = "0.001";

		oandaEndpoints().order.trailingStopLossOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::trailingstoplossorder::Response guaranteedStopLossOrder) -> void {
		});
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_CancelOrder)
{
	oanda::v20::endpoint::order::cancelorder::Request request;
	oanda::v20::endpoint::order::cancelorder::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	parameters.orderSpecifier = "151";

	oandaEndpoints().order.cancelOrder(request, parameters)->sync([&](oanda::v20::endpoint::order::cancelorder::Response cancelOrder) -> void {

	});
}

TEST_F (OandaEndpointsFixture, DISABLED_Orders)
{
	oanda::v20::endpoint::order::orders::Request request;
	oanda::v20::endpoint::order::orders::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	parameters.state = "ALL";

	oandaEndpoints().order.orders(request, parameters)->sync([&](oanda::v20::endpoint::order::orders::Response orders) -> void {

	});
}

TEST_F (OandaEndpointsFixture, DISABLED_PendingOrders)
{
	oanda::v20::endpoint::order::pendingorders::Request request;
	oanda::v20::endpoint::order::pendingorders::Parameters parameters;
	parameters.accountID = g_oandaAccountID;

	oandaEndpoints().order.pendingOrders(request, parameters)->sync([&](oanda::v20::endpoint::order::pendingorders::Response orders) -> void {

	});
}

TEST_F (OandaEndpointsFixture, DISABLED_OrderDetails)
{
	oanda::v20::endpoint::order::orders::Request request;
	oanda::v20::endpoint::order::orders::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	parameters.state = "ALL";

	oandaEndpoints().order.orders(request, parameters)->sync([&](oanda::v20::endpoint::order::orders::Response orders) -> void {
		ASSERT_GT(orders.orders.size(), 0);

		oanda::v20::endpoint::order::orderdetails::Request request;
		oanda::v20::endpoint::order::orderdetails::Parameters parameters;
		parameters.accountID = g_oandaAccountID;
		parameters.orderSpecifier = orders.orders[0].id;

		oandaEndpoints().order.orderDetails(request, parameters)->sync([&](oanda::v20::endpoint::order::orderdetails::Response orderDetail) -> void {
			//std::cout << "Order Detail: " << orderDetail.order.id << std::endl;
		});
	});
}

TEST_F (OandaEndpointsFixture, DISABLED_ReplaceMarketOrder)
{
	oanda::v20::endpoint::order::orders::Request request;
	oanda::v20::endpoint::order::orders::Parameters parameters;
	parameters.accountID = g_oandaAccountID;
	parameters.state = "ALL";

	oandaEndpoints().order.orders(request, parameters)->sync([&](oanda::v20::endpoint::order::orders::Response orders) -> void {
		ASSERT_GT(orders.orders.size(), 0);

		oanda::v20::endpoint::order::orderdetails::Request request;
		oanda::v20::endpoint::order::orderdetails::Parameters parameters;
		parameters.accountID = g_oandaAccountID;
		parameters.orderSpecifier = orders.orders[0].id;

		oandaEndpoints().order.orderDetails(request, parameters)->sync([&](oanda::v20::endpoint::order::orderdetails::Response orderDetail) -> void {
			//std::cout << "Order Detail: " << orderDetail.order.id << std::endl;
		});
	});
}
