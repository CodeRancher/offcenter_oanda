/**
 * Copyright 2021 Scott Brauer
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
 * @file   OandaEndpointResponses.hpp
 * @author Scott Brauer
 * @date   01-14-2021
 */

#ifndef OANDA_V20_ENDPOINT_OANDAENDPOINTRESPONSES_HPP_
#define OANDA_V20_ENDPOINT_OANDAENDPOINTRESPONSES_HPP_

#include <string>
#include <map>

#include "oanda/v20/endpoint/OandaParameter.hpp"

namespace oanda {
namespace v20 {
namespace endpoint {

class OandaEndpointResponses
{
public:
	using Parameters = std::map<std::string, std::string>;

	class Parameter {
	public:
		explicit Parameter(const std::string name, Parameters& parameters):
			m_name(name),
			m_parameters(parameters) {}

		// Copy constructor
//		explicit Parameter(const Parameter& other) {
//			set(other.get());
//		}

		const std::string name() const { return m_name; }
		const std::string value() { return get(); }

		const std::string get() {
			std::string tmp = m_parameters[m_name];
			return tmp;
		}
		void set(const std::string& value) { m_parameters[m_name] = value; }

		const std::string operator()() { return get(); }
		void operator()(const std::string& value) { set(value); }
		void operator=(const std::string& value) { set(value); }

	private:
		std::string m_name;
		Parameters& m_parameters;
	};

public:
	explicit OandaEndpointResponses():
		requestID("RequestID", m_headers),
		m_headers() {}
	virtual ~OandaEndpointResponses() = default;

	Parameter requestID;

protected:
	Parameters m_headers;
};

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_ENDPOINT_OANDAENDPOINTRESPONSES_HPP_ */
