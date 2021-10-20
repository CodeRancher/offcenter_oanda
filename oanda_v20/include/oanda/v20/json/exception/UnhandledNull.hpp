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
 * @file   UnhandledNull.hpp
 * @author Scott Brauer
 * @date   02-01-2021
 */

#ifndef OANDA_V20_JSON_EXCEPTION_UNHANDLEDNULL_HPP_
#define OANDA_V20_JSON_EXCEPTION_UNHANDLEDNULL_HPP_

#include <stdexcept>

namespace oanda {
namespace v20 {
namespace json {
namespace exception {

/**
 * Defines a type of object to be thrown as exception. It reports errors that are due to a null not being handled
 * during processing of json.
 */
class UnhandledNull : public std::runtime_error
{
public:
	/** constructs a new UnhandledNull object with the given message
	 *  @param what_arg explanatory string
	 */
	explicit UnhandledNull(const std::string& what_arg):
		std::runtime_error(what_arg) {}

	/** constructs a new UnhandledNull object with the given message
	 *  @param what_arg explanatory string
	 */
	explicit UnhandledNull(const char* what_arg):
		std::runtime_error(what_arg) {}

	/** destroys the exception object
	 */
	virtual ~UnhandledNull() = default;

};

} /* namespace exception */
} /* namespace json */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_JSON_EXCEPTION_UNHANDLEDNULL_HPP_ */
