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

/*
 * @file   OutOfRange.hpp
 * @author Scott Brauer
 * @date   12-11-2020
 */

#ifndef OANDA_V20_JSON_EXCEPTION_OUTOFRANGE_HPP_
#define OANDA_V20_JSON_EXCEPTION_OUTOFRANGE_HPP_

#include <string>
#include <stdexcept>
#include <sstream>

#include <nlohmann/json.hpp>

namespace oanda {
namespace v20 {
namespace json {
namespace exception {

class OutOfRange : public std::out_of_range
{
public:
	explicit OutOfRange(const std::string& what_arg):
		std::out_of_range(what_arg) {}

	explicit OutOfRange(const char* what_arg):
		std::out_of_range(what_arg) {}

	explicit OutOfRange(nlohmann::json::exception& e,
			const std::string& file = "",
			int line = 0,
			const std::string& function = ""):
		std::out_of_range(OutOfRange::join({
			e.what(), ":id(", std::to_string(e.id), ") ",
			"File(", file, ") ",
			"Line(", std::to_string(line), ") ",
			"Function(", function, ") "
		})) {}

	virtual ~OutOfRange() = default;

	static std::string join(std::initializer_list<std::string> elements)
	{
		std::ostringstream ss;
		for (auto element : elements)
			ss << element;
		return ss.str();
	}

};

} /* namespace exception */
} /* namespace json */
} /* namespace rest */
} /* namespace oanda */

#endif /* OANDA_V20_JSON_EXCEPTION_OUTOFRANGE_HPP_ */
