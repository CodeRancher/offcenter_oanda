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
 * @file   OandaServer.hpp
 * @author Scott Brauer
 * @date   12-09-2020
 */

#ifndef OANDA_V20_ENDPOINT_OANDASERVER_HPP_
#define OANDA_V20_ENDPOINT_OANDASERVER_HPP_

#include <string>

#include <cpprest/base_uri.h>
#include <cpprest/http_client.h>

#include "easylogging++.h"

namespace oanda {
namespace v20 {
namespace endpoint {

/**
 * Connection settings for the Oanda servers.
 * This can be used for a non-standard Oanda server.
 */
class OandaServers {
public:
	/** Explicitly create connection settings for the Oanda servers.
	 *
	 *  @param restURI URI for REST Oanda server.
	 *  @param streamingURI URI for streaming Oanda server.
	 */
	explicit OandaServers(const std::string& restURI, const std::string& streamingURI):
		m_restAPI(restURI),
		m_streamingAPI(streamingURI)
	{
		LOG(INFO) << "Oanda REST URI: " << m_restAPI.to_string();
		LOG(INFO) << "Oanda Streaming URI: " << m_streamingAPI.to_string();
	}

	virtual ~OandaServers() = default;

	/** Return the URI for the REST Oanda server.
	 *
	 *  @return Oanda REST server URI.
	 */
	const web::uri& restAPI() const { return m_restAPI; }

	/** Return the URI for the streaming Oanda server.
	 *
	 *  @return Oanda streaming server URI.
	 */
	const web::uri& streamingAPI() const { return m_streamingAPI; }

	template <class T>
	void setTimeout(T timeout) { m_clientConfig.set_timeout(timeout); }

	const web::http::client::http_client_config& clientConfig() { return m_clientConfig; }

private:
	const web::uri m_restAPI;
	const web::uri m_streamingAPI;
	web::http::client::http_client_config m_clientConfig;
};

/**
 * A stable environment; recommended for testing with your fxTrade Practice account and your personal access token.
 */
class OandaPracticeServer : public OandaServers {
public:
	OandaPracticeServer():
		OandaServers("https://api-fxpractice.oanda.com/", "https://stream-fxpractice.oanda.com/") {}
	virtual ~OandaPracticeServer() = default;
};

/**
 * A stable environment; recommended for production-ready code to execute with your fxTrade account and your personal access token.
 */
class OandaLiveServer : public OandaServers {
public:
	OandaLiveServer():
		OandaServers("https://api-fxtrade.oanda.com", "https://stream-fxtrade.oanda.com/") {}
	virtual ~OandaLiveServer() = default;
};

/**
 * Select a server based on the name.
 *
 * If name = fxtrade the live data trade server will be used. Otherwise the practice server will be used.
 */
class OandaServerByName : public OandaServers {
public:
	OandaServerByName(const std::string& name):
		OandaServers(
				(name == "fxtrade") ? "https://api-fxtrade.oanda.com" : "https://api-fxpractice.oanda.com/",
				(name == "fxtrade") ? "https://stream-fxtrade.oanda.com/" : "https://stream-fxpractice.oanda.com/")
	{}
	virtual ~OandaServerByName() = default;
};

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_OANDASERVER_HPP_ */
