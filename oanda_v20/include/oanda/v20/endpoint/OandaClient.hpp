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
 * @file   OandaClient.hpp
 * @author Scott Brauer
 * @date   12-09-2020
 */

#ifndef OANDA_V20_ENDPOINT_OANDACLIENT_HPP_
#define OANDA_V20_ENDPOINT_OANDACLIENT_HPP_

#include <memory>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <initializer_list>
#include <thread>
#include <typeinfo>
#include <type_traits>
#include <typeindex>
#include <functional>
#include <map>

#include <cpprest/http_client.h>
#include <cpprest/http_msg.h>
#include <cpprest/filestream.h>
#include <cpprest/containerstream.h>
#include <cpprest/filestream.h>
//#include <cpprest/json.h>
#include <cpprest/producerconsumerstream.h>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams
using namespace ::pplx;
using namespace utility;
using namespace concurrency::streams;

#include <nlohmann/json.hpp>

#ifdef LOG_V20_ACCESS
	#include "easylogging++.h"
#endif

#include "oanda/v20/endpoint/OandaServer.hpp"
#include "oanda/v20/endpoint/OandaAuthorization.hpp"
#include "oanda/v20/common/Utility.hpp"
#include "oanda/v20/endpoint/OandaConnectionException.hpp"
#include "oanda/v20/endpoint/OandaExceptionFactory.hpp"
#include "oanda/v20/endpoint/OandaEndpointParameters.hpp"

#include "oanda/v20/endpoint/Account.hpp"
#include "oanda/v20/endpoint/Instrument.hpp"
#include "oanda/v20/endpoint/Order.hpp"
#include "oanda/v20/endpoint/Trade.hpp"
#include "oanda/v20/endpoint/Position.hpp"
#include "oanda/v20/endpoint/Transaction.hpp"
#include "oanda/v20/endpoint/Pricing.hpp"

using namespace oanda::v20;

namespace oanda {
namespace v20 {
namespace endpoint {

enum class Synchronicity {
	Synchronous,
	Asynchronous
};

class OandaClient {
public:
	using StreamingRequestID = int;

	struct StreamingTask {
		pplx::cancellation_token_source tokenSource;
		pplx::task<void> task;
	};

public:
	explicit OandaClient(const OandaServers& server, const OandaAuthorization& authorization);
	virtual ~OandaClient();

	/**
	 *
	 */
	template<class Response, class Request>
	pplx::task<Response> executeRequest(
			const web::http::method method,
			const std::string& v3URI,
			const Request& request,
			const endpoint::OandaEndpointParameters& parameters)
	{
		web::uri uri = parameters.buildURI(v3URI);
		web::http::http_request httpRequest;
		httpRequest.set_method(method);
		httpRequest.set_request_uri(uri);
		httpRequest.headers().set_content_type("application/json");
		httpRequest.headers().add("Authorization", "Bearer " + m_authorization.bearerToken());

		for (const OandaEndpointParameters::ParameterElement& parameterElement : parameters.headers()) {
			httpRequest.headers().add(parameterElement.first, parameterElement.second);
		}

		nlohmann::json jsonRequest = request;
		recurseAndFilterNullValues(jsonRequest);

		#ifdef LOG_V20_ACCESS
			LOG(INFO) << "*** Begin V20 Access *************************************************************";
			LOG(INFO) << "URL: " << httpRequest.request_uri().to_string();
		#endif

		if (!jsonRequest.empty()) {
			httpRequest.set_body(jsonRequest.dump());
			#ifdef LOG_V20_ACCESS
				LOG(INFO) << "Request: " << jsonRequest.dump(4);
			#endif
		}

		pplx::task<Response> requestTask = m_restClient.request(httpRequest)
		.then([](http_response response) -> pplx::task<Response> {
			// If successful http call, extract string
			if ((response.status_code() == status_codes::OK) || (response.status_code() == status_codes::Created)) {
				Response jsonResponse;
				try {
					std::string bodyText = response.extract_string().get();
					auto jsonParse = nlohmann::json::parse(bodyText);
					// Convert parsed json to class
					jsonResponse = jsonParse.get<Response>();
					parseHeader(response.headers(), jsonResponse);

					#ifdef LOG_V20_ACCESS
						LOG(INFO) << "Status: " << response.status_code();
						//LOG(INFO) << "Response: " << jsonParse.dump(4);
						LOG(INFO) << "*** End V20 Access *************************************************************";
					#endif
				} catch(const std::exception& e) {
					LOG(ERROR) << "Cannot process body text: " << e.what();
					throw;
				}

				return pplx::task_from_result(jsonResponse);
			}
			// http failure, throw exception
			std::string bodyText = response.extract_string().get();

			#ifdef LOG_V20_ACCESS
				LOG(INFO) << "Error Status: " << response.status_code();
				LOG(INFO) << "Error Response: " << bodyText;
				LOG(INFO) << "*** End V20 Access after Error *************************************************";
			#endif

			oandaExceptionFactory(response.status_code(), bodyText);
			return pplx::task_from_result(Response());
		});

		return requestTask;
	}

	/**
	 *
	 */
	template<class HeartbeatResponse, typename ProcessHeartbeat>
	pplx::task<void> createHeartbeatTask(nlohmann::json& json, ProcessHeartbeat&& heartbeatLambda, const pplx::cancellation_token token) {
		return pplx::create_task([=] {
			//LOG(INFO) << "Execute heartbeat" << std::endl;
			try {
				heartbeatLambda(json.get<HeartbeatResponse>());
			} catch(nlohmann::json::exception& e) {
				#ifdef LOG_V20_ACCESS
					LOG(ERROR) <<
						"*** Error processing streaming heartbeat ***************************************************" << std::endl <<
						"JSON:   " << json.dump(4) << std::endl <<
						"********************************************************************************************";
				#endif
			}
		}, token);
	}

	/**
	 *
	 */
	template<class DataResponse, typename ProcessData>
	pplx::task<void> createDataTask(nlohmann::json& json, ProcessData&& dataLambda, const pplx::cancellation_token token) {
		return pplx::create_task([=] {
			//LOG(INFO) << "Execute data" << std::endl;
			try {
				dataLambda(json.get<DataResponse>());
			} catch(nlohmann::json::exception& e) {
				#ifdef LOG_V20_ACCESS
					LOG(ERROR) <<
						"*** Error processing streaming data ********************************************************" << std::endl <<
						"JSON:   " << json.dump(4) << std::endl <<
						"********************************************************************************************";
				#endif
			}
        }, token);
	}

	/**
	 *
	 */
	template<class DataResponse, class HeartbeatResponse, typename ProcessData, typename ProcessHeartbeat>
	void processBodyStream(
			Concurrency::streams::istream& bodyStream,
			ProcessData&& dataLambda,
			ProcessHeartbeat&& heartbeatLambda,
			pplx::cancellation_token_source& cts)
	{
    	pplx::cancellation_token token = cts.get_token();
        while (!bodyStream.is_eof() && !token.is_canceled()) {
    	    Concurrency::streams::container_buffer<std::string> buffer;
			///LOG(INFO) << "Before read_to_delim";
	        bodyStream.read_to_delim(buffer, '\n')
	        .then([buffer, token](pplx::task<size_t> bufferSize) -> pplx::task<nlohmann::json> {
	        	if (bufferSize.get() > 0) {
	    			///LOG(INFO) << "Before parse: " << buffer.collection();
	        		try {
	        			return pplx::task_from_result(nlohmann::json::parse(buffer.collection()), token);
	        		} catch(nlohmann::json::exception& e) {
						#ifdef LOG_V20_ACCESS
	        				LOG(ERROR) << "Parse Error: " << buffer.collection();
						#endif
	        			throw;
	        		}
	        	}
	        	cancel_current_task();
    			return pplx::task_from_result(nlohmann::json(), token);
	        }).then([&, heartbeatLambda, dataLambda, token](pplx::task<nlohmann::json> parsedJson) -> pplx::task<void> {
	        	auto json = parsedJson.get();
    			auto type = json.value("type", "not_recognized");
    			if (type.compare("HEARTBEAT") == 0) {
    				return createHeartbeatTask<HeartbeatResponse>(json, heartbeatLambda, token);
    			} else if (type.compare("not_recognized") != 0) {
    				return createDataTask<DataResponse>(json, dataLambda, token);
    			}
	        	cancel_current_task();
    			return pplx::create_task([]{}, token);
	    	}).wait();
        }
	}

	/**
	 *
	 */
	void cancelStreamRequest(const StreamingRequestID& requestID)
	{
		m_streamingTasks[requestID].tokenSource.cancel();
		m_streamingTasks[requestID].task.wait();
		m_streamingTasks.erase(requestID);
	}

	/**
	 *
	 */
	template<class DataResponse, class HeartbeatResponse, typename ProcessData, typename ProcessHeartbeat>
	const StreamingRequestID executeStreamRequest(
			const web::http::method method,
			const std::string& v3URI,
			const endpoint::OandaEndpointParameters& parameters,
			ProcessData&& dataLambda,
			ProcessHeartbeat&& heartbeatLambda)
	{
		// Generate an ID for this request
		static std::atomic_int streamingRequestID;
		StreamingRequestID requestID = streamingRequestID++;

		web::uri uri = parameters.buildURI(v3URI);
		web::http::http_request httpRequest;
		httpRequest.set_method(method);
		httpRequest.set_request_uri(uri);
		httpRequest.headers().set_content_type("application/json");
		httpRequest.headers().add("Authorization", "Bearer " + m_authorization.bearerToken());

		for (const OandaEndpointParameters::ParameterElement& parameterElement : parameters.headers()) {
			httpRequest.headers().add(parameterElement.first, parameterElement.second);
		}

		#ifdef LOG_V20_ACCESS
			LOG(INFO) << std::endl <<
					"*** Begin V20 Streaming Access *************************************************************" << std::endl <<
					"URL: " << httpRequest.request_uri().to_string();
		#endif

		//m_streamingTasks[requestID].tokenSource = cancellation_token_source();

		m_streamingTasks[requestID].task = std::move(m_streamingClient.request(httpRequest)
		.then([=](web::http::http_response response) {
			if(response.status_code() == web::http::status_codes::OK) {
				concurrency::streams::istream bodyStream = response.body();
				if (bodyStream.is_valid()) {
					///LOG(INFO) << "Before processBodyStream: " << requestID << ":" << httpRequest.request_uri().to_string();
					processBodyStream<DataResponse, HeartbeatResponse>(bodyStream, dataLambda, heartbeatLambda, m_streamingTasks[requestID].tokenSource);
					///LOG(INFO) << "After processBodyStream: " << requestID;
				} else {
					std::cout << "Invalid stream" << std::endl;
				}
			} else {
				// http failure, throw exception
				pplx::task<utility::string_t> bodyText = response.extract_string();

				#ifdef LOG_V20_ACCESS
					LOG(INFO) << std::endl <<
							"Status: " << response.status_code() << std::endl <<
							"Response: " << bodyText.get() << std::endl <<
							"*** End V20 Access (Error) ******************************************************";
				#endif

				oandaExceptionFactory(response.status_code(), bodyText.get());
			}
		}));

		///LOG(INFO) << "Created Stream Request: " << requestID;
		return requestID;
	}

	template<class Response, class Request, typename ResponseLambda>
	void executeRequestSync(
			const web::http::method method,
			const std::string v3URI,
			const Request& request,
			const endpoint::OandaEndpointParameters& parameters,
			ResponseLambda&& responseLambda)
	{
		pplx::task<Response> requestTask = executeRequest<Response>(method, v3URI, request, parameters);
		responseLambda(requestTask.get());
	}

	template<class Response, class Request, typename ResponseLambda>
	void executeRequestAsync(
			const web::http::method method,
			const std::string v3URI,
			const Request& request,
			const endpoint::OandaEndpointParameters& parameters,
			ResponseLambda&& responseLambda)
	{
		pplx::task<Response> requestTask = executeRequest<Response>(method, v3URI, request, parameters);
		responseLambda(requestTask);
	}

	void initializeHttpRequest(web::http::http_request& request, const web::http::method method, const web::uri& uri) const;

	template<class Request>
	void initializeHttpRequestWithBody(
			web::http::http_request& httpRequest,
			const web::http::method method,
			const web::uri& uri,
			const Request& requestData) const
	{
		httpRequest.set_method(method);
		httpRequest.set_request_uri(uri);
		httpRequest.headers().set_content_type("application/json");
		httpRequest.headers().add("Authorization", "Bearer " + m_authorization.bearerToken());
		nlohmann::json jsonRequest = requestData;
		if (!requestData.empty()) {
			httpRequest.set_body(jsonRequest.dump());
		}
	}

private:
	// Make an http request
	pplx::task<utility::string_t> extractResponse(http_response response)
	{
		// If successful http call, extract string
		if (response.status_code() == status_codes::OK) {
			return response.extract_string();
		}
		// http failure, throw exception
		pplx::task<utility::string_t> bodyText = response.extract_string();
		///std::cout << bodyText.get() << std::endl;
		oandaExceptionFactory(response.status_code(), bodyText.get());
		return bodyText;
	};

	template<class T>
	pplx::task<T> parseJson(pplx::task<utility::string_t> bodyText) {
		// Convert http body to parsed json
		auto jsonParse = nlohmann::json::parse(bodyText.get());
		// Convert parsed json to class
		return pplx::task_from_result(jsonParse.get<T>());

	}

	// Make an http request
	template<class T>
	pplx::task<T> extractResponse2(http_response response)
	{
		// If successful http call, extract string
		if (response.status_code() == status_codes::OK) {
			pplx::task< utility::string_t > bodyText = response.extract_string();
			auto jsonParse = nlohmann::json::parse(bodyText.get());
			// Convert parsed json to class
			return pplx::task_from_result(jsonParse.get<T>());
		}
		// http failure, throw exception
		pplx::task<utility::string_t> bodyText = response.extract_string();
		///std::cout << bodyText.get() << std::endl;
		oandaExceptionFactory(response.status_code(), bodyText.get());
		return bodyText;
	};

	void recurseAndFilterNullValues(nlohmann::json & jsonObject, std::string indent = "") {
	    if (!jsonObject.is_object() && !jsonObject.is_array()) {
	    	//std::cout << indent << "Skipping object" << std::endl;
	        return;
	    }

	    std::vector<nlohmann::json::object_t::key_type> keysToRemove;
	    for (auto &it : jsonObject.items()) {
	    	//std::cout << indent << "Recurse object: " << it.key() << std::endl;
	    	recurseAndFilterNullValues(it.value(), indent + "\t");
	        if (it.value().is_null() || (it.value().size() == 0)) {
		    	//std::cout << indent << "Staging object: " << it.key() << std::endl;
	            keysToRemove.push_back(it.key());
	        }
	    }

	    for (auto key : keysToRemove) {
	    	//std::cout << indent << "Erasing object: " << key << std::endl;
	        jsonObject.erase(key);
	    }
	}

private:
	OandaServers m_server;
	OandaAuthorization m_authorization;

	http_client m_restClient;
	http_client m_streamingClient;

	std::map<StreamingRequestID, StreamingTask> m_streamingTasks;
};

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_OANDACLIENT_HPP_ */
