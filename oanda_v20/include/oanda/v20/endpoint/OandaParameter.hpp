/**
 * @file OandaParameter.hpp
 * @author Scott Brauer
 * @date 01-14-2021
 */

#ifndef OANDA_V20_INCLUDE_OANDA_V20_ENDPOINT_OANDAPARAMETER_HPP_
#define OANDA_V20_INCLUDE_OANDA_V20_ENDPOINT_OANDAPARAMETER_HPP_

#include <string>
#include <map>

namespace oanda {
namespace v20 {
namespace endpoint {

using Parameters = std::map<std::string, std::string>;

class OandaParameter {
public:
	explicit OandaParameter(const std::string name, Parameters& parameters):
		m_name(name),
		m_parameters(parameters) {}

	const std::string name() const { return m_name; }
	const std::string value() { return get(); }

	const std::string get() {
		std::string tmp = m_parameters[m_name];
		return tmp;
	}
	void set(const std::string value) { m_parameters[m_name] = value; }

	const std::string operator()() { return get(); }
	void operator()(const std::string value) { set(value); }
	void operator=(const std::string value) { set(value); }

private:
	std::string m_name;
	Parameters& m_parameters;
};

} /* namespace endpoint */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_INCLUDE_OANDA_V20_ENDPOINT_OANDAPARAMETER_HPP_ */
