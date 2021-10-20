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
 * @file   OandaCommonException.hpp
 * @author Scott Brauer
 * @date   02-17-2021
 */

#ifndef OANDA_V20_COMMON_OANDACOMMONEXCEPTION_HPP_
#define OANDA_V20_COMMON_OANDACOMMONEXCEPTION_HPP_

#include <string>
#include <stdexcept>

namespace oanda {
namespace v20 {
namespace common {

/// Oanda runtime exception
class OandaRuntimeException: public std::runtime_error
{
public:
	explicit OandaRuntimeException(const std::string& what_arg): runtime_error(what_arg) {}
	explicit OandaRuntimeException(const char* what_arg): runtime_error(what_arg) {}
};

/// Oanda Invalid Type exception
class OandaInvalidType: public OandaRuntimeException
{
public:
	explicit OandaInvalidType(const std::string& what_arg): OandaRuntimeException(what_arg) {}
	explicit OandaInvalidType(const char* what_arg): OandaRuntimeException(what_arg) {}
};

/// Oanda Invalid Value exception
class OandaInvalidValue: public OandaRuntimeException
{
public:
	explicit OandaInvalidValue(const std::string& what_arg): OandaRuntimeException(what_arg) {}
	explicit OandaInvalidValue(const char* what_arg): OandaRuntimeException(what_arg) {}
};


} /* namespace common */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_COMMON_OANDACOMMONEXCEPTION_HPP_ */
