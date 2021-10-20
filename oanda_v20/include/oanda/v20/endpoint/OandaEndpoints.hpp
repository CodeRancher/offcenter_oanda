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
 * @file   OandaEndpoints.hpp
 * @author Scott Brauer
 * @date   12-14-2020
 */

#ifndef OANDA_V20_ENDPOINT_OANDAENDPOINTS_HPP_
#define OANDA_V20_ENDPOINT_OANDAENDPOINTS_HPP_

#include <memory>

#include "oanda/v20/endpoint/OandaClient.hpp"
#include "oanda/v20/endpoint/Account.hpp"
#include "oanda/v20/endpoint/Instrument.hpp"
#include "oanda/v20/endpoint/Order.hpp"
#include "oanda/v20/endpoint/Trade.hpp"
#include "oanda/v20/endpoint/Position.hpp"
#include "oanda/v20/endpoint/Transaction.hpp"
#include "oanda/v20/endpoint/Pricing.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {

/**
 *
 */
template<class Response>
class EndpointExecute {
//public:
//	template<class T>
//	using UPtr = std::unique_ptr<EndpointExecute<T>>;

public:
	template<typename ProcessData>
	void sync(ProcessData&& lambda)
	{
		lambda(m_requestTask.get());
	}

	template<typename ProcessData>
	void async(ProcessData&& lambda)
	{
		lambda(m_requestTask);
	}

	void setRequestTask(pplx::task<Response> requestTask) { m_requestTask = requestTask; }

private:
	pplx::task<Response> m_requestTask;
};

/**
 *
 */
template<class Response, class Request>
class EndpointRequest {
public:
	using EndpointRequestPtr = std::unique_ptr<EndpointExecute<Response>>;

public:
	explicit EndpointRequest(
			OandaClient& client,
			const web::http::method method,
			const std::string& v3URI
	):
		m_client(client),
		m_method(method),
		m_v3URI(v3URI) {}

	EndpointRequestPtr operator()(const Request& request, const oanda::v20::endpoint::OandaEndpointParameters& parameters) {
		EndpointRequestPtr execute = std::make_unique<EndpointExecute<Response>>();

		execute->setRequestTask(m_client.executeRequest<Response,Request>(m_method, m_v3URI, request, parameters));
		return execute;
	}

	//void getRequestTask

private:
	OandaClient& m_client;
	const web::http::method m_method;
	const std::string m_v3URI;
	//EndpointExecute<Response> m_execute;
};

/**
 *
 */
template<class DataResponse, class HeartbeatResponse>
class EndpointStreamRequest {
public:
	explicit EndpointStreamRequest(
			OandaClient& client,
			const web::http::method method,
			const std::string& v3URI
	):
		m_client(client),
		m_method(method),
		m_v3URI(v3URI) {}

	template<typename ProcessData, typename ProcessHeartbeat>
	const OandaClient::StreamingRequestID operator()(
			const oanda::v20::endpoint::OandaEndpointParameters& parameters,
			ProcessData&& dataLambda,
			ProcessHeartbeat&& heartbeatLambda)
	{
		return m_client.executeStreamRequest<DataResponse, HeartbeatResponse>(m_method, m_v3URI, parameters, dataLambda, heartbeatLambda);
	}

	void cancel(oanda::v20::endpoint::OandaClient::StreamingRequestID requestID)
	{
		return m_client.cancelStreamRequest(requestID);
	}

private:
	OandaClient& m_client;
	const web::http::method m_method;
	const std::string m_v3URI;
};

/**
 *
 */
class AccountEndpoints {
public:
	explicit AccountEndpoints(OandaClient& client):
		accounts(client,				web::http::methods::GET,	"/v3/accounts"),
		account(client,					web::http::methods::GET,	"/v3/accounts/{accountID}"),
		accountSummary(client,			web::http::methods::GET,	"/v3/accounts/{accountID}/summary"),
		accountInstruments(client,		web::http::methods::GET,	"/v3/accounts/{accountID}/instruments"),
		accountConfiguration(client,	web::http::methods::PATCH,	"/v3/accounts/{accountID}/configuration"),
		accountChanges(client,			web::http::methods::GET,	"/v3/accounts/{accountID}/changes")
	{}

	EndpointRequest<account::accounts::Response, account::accounts::Request> accounts;
	EndpointRequest<account::account::Response, account::account::Request> account;
	EndpointRequest<account::accountsummary::Response, account::accountsummary::Request> accountSummary;
	EndpointRequest<account::accountinstruments::Response, account::accountinstruments::Request> accountInstruments;
	EndpointRequest<account::accountconfiguration::Response, account::accountconfiguration::Request> accountConfiguration;
	EndpointRequest<account::accountchanges::Response, account::accountchanges::Request> accountChanges;
};

/**
 * \namespace oanda::v20::endpoint::
 */
class InstrumentEndpoints {
public:
	explicit InstrumentEndpoints(OandaClient& client):
		candles(client,      web::http::methods::GET, "/v3/instruments/{instrument}/candles"),
		orderBook(client,    web::http::methods::GET, "/v3/instruments/{instrument}/orderBook"),
		positionBook(client, web::http::methods::GET, "/v3/instruments/{instrument}/positionBook")
	{}

	EndpointRequest<instrument::candles::Response, instrument::candles::Request> candles;
	EndpointRequest<instrument::orderbook::Response, instrument::orderbook::Request> orderBook;
	EndpointRequest<instrument::positionbook::Response, instrument::positionbook::Request> positionBook;
};

/**
 *
 */
class OrderEndpoints {
public:
	explicit OrderEndpoints(OandaClient& client):
		marketOrder(client,		 		web::http::methods::POST, "/v3/accounts/{accountID}/orders"),
		limitOrder(client,		 		web::http::methods::POST, "/v3/accounts/{accountID}/orders"),
		stopOrder(client,		 		web::http::methods::POST, "/v3/accounts/{accountID}/orders"),
		marketIfTouchedOrder(client,	web::http::methods::POST, "/v3/accounts/{accountID}/orders"),
		takeProfitOrder(client,		 	web::http::methods::POST, "/v3/accounts/{accountID}/orders"),
		stopLossOrder(client,		 	web::http::methods::POST, "/v3/accounts/{accountID}/orders"),
		guaranteedStopLossOrder(client,	web::http::methods::POST, "/v3/accounts/{accountID}/orders"),
		trailingStopLossOrder(client,	web::http::methods::POST, "/v3/accounts/{accountID}/orders"),

		orders(client,					web::http::methods::GET,  "/v3/accounts/{accountID}/orders"),
		pendingOrders(client,			web::http::methods::GET,  "/v3/accounts/{accountID}/pendingOrders"),
		orderDetails(client,			web::http::methods::GET,  "/v3/accounts/{accountID}/orders/{orderSpecifier}"),

		replaceMarketOrder(client,		web::http::methods::PUT,  "/v3/accounts/{accountID}/orders/{orderSpecifier}"),
		replaceLimitOrder(client,		web::http::methods::PUT,  "/v3/accounts/{accountID}/orders/{orderSpecifier}"),
		replaceStopOrder(client,		web::http::methods::PUT,  "/v3/accounts/{accountID}/orders/{orderSpecifier}"),
		replaceMarketIfTouchedOrder(client,		web::http::methods::PUT,  "/v3/accounts/{accountID}/orders/{orderSpecifier}"),
		replaceTakeProfitOrder(client,		web::http::methods::PUT,  "/v3/accounts/{accountID}/orders/{orderSpecifier}"),
		replaceStopLossOrder(client,		web::http::methods::PUT,  "/v3/accounts/{accountID}/orders/{orderSpecifier}"),
		replaceGuaranteedStopLossOrder(client,		web::http::methods::PUT,  "/v3/accounts/{accountID}/orders/{orderSpecifier}"),
		replaceTrailingStopLossOrder(client,		web::http::methods::PUT,  "/v3/accounts/{accountID}/orders/{orderSpecifier}"),

		cancelOrder(client,				web::http::methods::PUT,  "/v3/accounts/{accountID}/orders/{orderSpecifier}/cancel"),
		clientExtensions(client,		web::http::methods::PUT,  "/v3/accounts/{accountID}/orders/{orderSpecifier}/clientExtensions")
	{}

	EndpointRequest<order::marketorder::Response, order::marketorder::Request> marketOrder;
	EndpointRequest<order::limitorder::Response, order::limitorder::Request> limitOrder;
	EndpointRequest<order::stoporder::Response, order::stoporder::Request> stopOrder;
	EndpointRequest<order::marketiftouchedorder::Response, order::marketiftouchedorder::Request> marketIfTouchedOrder;
	EndpointRequest<order::takeprofitorder::Response, order::takeprofitorder::Request> takeProfitOrder;
	EndpointRequest<order::stoplossorder::Response, order::stoplossorder::Request> stopLossOrder;
	EndpointRequest<order::guaranteedstoplossorder::Response, order::guaranteedstoplossorder::Request> guaranteedStopLossOrder;
	EndpointRequest<order::trailingstoplossorder::Response, order::trailingstoplossorder::Request> trailingStopLossOrder;

	EndpointRequest<order::orders::Response, order::orders::Request> orders;
	EndpointRequest<order::pendingorders::Response, order::pendingorders::Request> pendingOrders;
	EndpointRequest<order::orderdetails::Response, order::orderdetails::Request> orderDetails;

	EndpointRequest<order::replacemarketorder::Response, order::replacemarketorder::Request> replaceMarketOrder;
	EndpointRequest<order::replacelimitorder::Response, order::replacelimitorder::Request> replaceLimitOrder;
	EndpointRequest<order::replacestoporder::Response, order::replacestoporder::Request> replaceStopOrder;
	EndpointRequest<order::replacemarketiftouchedorder::Response, order::replacemarketiftouchedorder::Request> replaceMarketIfTouchedOrder;
	EndpointRequest<order::replacetakeprofitorder::Response, order::replacetakeprofitorder::Request> replaceTakeProfitOrder;
	EndpointRequest<order::replacestoplossorder::Response, order::replacestoplossorder::Request> replaceStopLossOrder;
	EndpointRequest<order::replaceguaranteedstoplossorder::Response, order::replaceguaranteedstoplossorder::Request> replaceGuaranteedStopLossOrder;
	EndpointRequest<order::replacetrailingstoplossorder::Response, order::replacetrailingstoplossorder::Request> replaceTrailingStopLossOrder;

	EndpointRequest<order::cancelorder::Response, order::cancelorder::Request> cancelOrder;
	EndpointRequest<order::clientextensions::Response, order::clientextensions::Request> clientExtensions;

};

/**
 *
 */
class TradeEndpoints {
public:
	explicit TradeEndpoints(OandaClient& client):
		trades(client,				web::http::methods::GET, "/v3/accounts/{accountID}/trades"),
		openTrades(client,			web::http::methods::GET, "/v3/accounts/{accountID}/openTrades"),
		trade(client,				web::http::methods::GET, "/v3/accounts/{accountID}/trades/{tradeSpecifier}"),
		close(client,				web::http::methods::PUT, "/v3/accounts/{accountID}/trades/{tradeSpecifier}/close"),
		clientExtensions(client,    web::http::methods::PUT, "/v3/accounts/{accountID}/trades/{tradeSpecifier}/clientExtensions"),
		orders(client,				web::http::methods::PUT, "/v3/accounts/{accountID}/trades/{tradeSpecifier}/orders")
	{}

	EndpointRequest<trade::trades::Response, trade::trades::Request> trades;
	EndpointRequest<trade::opentrades::Response, trade::opentrades::Request> openTrades;
	EndpointRequest<trade::trade::Response, trade::trade::Request> trade;
	EndpointRequest<trade::close::Response, trade::close::Request> close;
	EndpointRequest<trade::clientextensions::Response, trade::clientextensions::Request> clientExtensions;
	EndpointRequest<trade::orders::Response, trade::orders::Request> orders;
};

/**
 *
 */
class PositionEndpoints {
public:
	explicit PositionEndpoints(OandaClient& client):
		positions(client,		web::http::methods::GET, "/v3/accounts/{accountID}/positions"),
		openPositions(client,	web::http::methods::GET, "/v3/accounts/{accountID}/openPositions"),
		position(client,		web::http::methods::GET, "/v3/accounts/{accountID}/positions/{instrument}"),
		close(client,			web::http::methods::PUT, "/v3/accounts/{accountID}/positions/{instrument}/close")
	{}

	EndpointRequest<position::positions::Response, position::positions::Request> positions;
	EndpointRequest<position::openpositions::Response, position::openpositions::Request> openPositions;
	EndpointRequest<position::position::Response, position::position::Request> position;
	EndpointRequest<position::close::Response, position::close::Request> close;
};

/**
 *
 */
class TransactionEndpoints {
public:
	explicit TransactionEndpoints(OandaClient& client):
		transactions(client,		web::http::methods::GET, "/v3/accounts/{accountID}/transactions"),
		transaction(client,			web::http::methods::GET, "/v3/accounts/{accountID}/transactions/{transactionID}"),
		transactionsRange(client,	web::http::methods::GET, "/v3/accounts/{accountID}/transactions/idrange"),
		transactionsSince(client,	web::http::methods::GET, "/v3/accounts/{accountID}/transactions/sinceid"),
		transactionsStream(client,	web::http::methods::GET, "/v3/accounts/{accountID}/transactions/stream")
	{}

	EndpointRequest<transaction::transactions::Response, transaction::transactions::Request> transactions;
	EndpointRequest<transaction::transaction::Response, transaction::transaction::Request> transaction;
	EndpointRequest<transaction::transactionsrange::Response, transaction::transactionsrange::Request> transactionsRange;
	EndpointRequest<transaction::transactionssince::Response, transaction::transactionssince::Request> transactionsSince;
	EndpointRequest<transaction::transactionsstream::Response, transaction::transactionsstream::Request> transactionsStream;
};

/**
 *
 */
class PricingEndpoints {
public:
	explicit PricingEndpoints(OandaClient& client):
		latest(client,			web::http::methods::GET, "/v3/accounts/{accountID}/candles/latest"),
		pricing(client,			web::http::methods::GET, "/v3/accounts/{accountID}/pricing"),
		pricingStream(client,	web::http::methods::GET, "/v3/accounts/{accountID}/pricing/stream"),
		candles(client,			web::http::methods::GET, "/v3/accounts/{accountID}/instruments/{instrument}/candles")
	{}

	EndpointRequest<pricing::latest::Response, pricing::latest::Request> latest;
	EndpointRequest<pricing::pricing::Response, pricing::pricing::Request> pricing;
	EndpointStreamRequest<pricing::pricingstream::DataResponse, pricing::pricingstream::HeartbeatResponse> pricingStream;
	EndpointRequest<pricing::candles::Response, pricing::candles::Request> candles;
};

/**
 *
 */
class OandaEndpoints : public OandaClient {
public:
	using Ptr = std::shared_ptr<OandaEndpoints>;
	static Ptr factory(const OandaServers& server, const OandaAuthorization& authorization) {
		return std::make_shared<OandaEndpoints>(server, authorization);
	}
	static Ptr instance(const OandaServers& server, const OandaAuthorization& authorization) {
		static OandaServers g_server = server;
		static OandaAuthorization g_authorization = authorization;
		static Ptr g_instance = factory(g_server, g_authorization);
		return g_instance;
	}

public:
	explicit OandaEndpoints(const OandaServers& server, const OandaAuthorization& authorization);
	virtual ~OandaEndpoints();

	AccountEndpoints account;
	InstrumentEndpoints instrument;
	OrderEndpoints order;
	TradeEndpoints trade;
	PositionEndpoints position;
	TransactionEndpoints transaction;
	PricingEndpoints pricing;
};

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */


#endif /* OANDA_V20_ENDPOINT_OANDAENDPOINTS_HPP_ */
