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
 * @file   OandaClient.cpp
 * @author Scott Brauer
 * @date   12-09-2020
 */

#include "oanda/v20/endpoint/OandaClient.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {

OandaClient::OandaClient(const OandaServers& server, const OandaAuthorization& authorization):
		m_server(server),
		m_authorization(authorization),
		m_restClient(m_server.restAPI(), m_server.clientConfig()),
		m_streamingClient(m_server.streamingAPI())
{
	// TODO Auto-generated constructor stub

}

OandaClient::~OandaClient()
{
	for (std::pair<StreamingRequestID, StreamingTask> element : m_streamingTasks) {
		m_streamingTasks[element.first].tokenSource.cancel();
		m_streamingTasks[element.first].task.wait();
	}
}

void OandaClient::initializeHttpRequest(http_request &request, const web::http::method method, const web::uri& uri) const
{
	request.set_method(method);
	request.set_request_uri(uri);
	request.headers().set_content_type("application/json");
	request.headers().add("Authorization", "Bearer " + m_authorization.bearerToken());
}

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */
