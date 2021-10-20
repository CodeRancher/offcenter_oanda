/**
 * @file String2.cpp
 * @author Scott Brauer
 * @date 01-21-2021
 */

#include <iostream>
#include <exception>

#include "oanda/v20/common/String.hpp"

namespace oanda {
namespace v20 {
namespace common {

String::String():
	std::string(),
	m_isDirty(false),
	m_isNull(false)
{}

String::String(const std::string& str):
	std::string(str),
	m_isDirty(false),
	m_isNull(false)
{}

String::String(const String& str):
	std::string(str),
	m_isDirty(str.m_isDirty),
	m_isNull(str.m_isNull)
{}

String::String(const std::string& str, size_t pos, size_t len):
	std::string(str, pos, len),
	m_isDirty(false),
	m_isNull(false)
{}

String::String(const char* s):
	std::string(s),
	m_isDirty(false),
	m_isNull(s == nullptr)
{}

String::String(const char* s, size_t n):
	std::string(s, n),
	m_isDirty(false),
	m_isNull(s == nullptr)
{}

String::String(size_t n, char c):
	std::string(n, c),
	m_isDirty(false),
	m_isNull(false)
{}

template <class InputIterator>
String::String (InputIterator first, InputIterator last):
	std::string(first, last),
	m_isDirty(false),
	m_isNull(false)
{}

String::String(std::initializer_list<char> il):
	std::string(il),
	m_isDirty(false),
	m_isNull(false)
{}

String::String(std::string&& str) noexcept:
	std::string(str),
	m_isDirty(false),
	m_isNull(false)
{}

String::String(const std::nullptr_t& str) noexcept:
	std::string(""),
	m_isDirty(false),
	m_isNull(true)
{}

String::~String() {
}

String& String::operator= (const std::string& str) {
	m_isDirty = (m_isDirty || (str != *this));
	m_isNull = false;
	std::string::operator=(str);
	return *this;
}

String& String::operator= (const String& str) {
	m_isDirty = (m_isDirty || (str != *this));
	m_isNull = str.m_isNull;
	std::string::operator=(str);
	return *this;
}

String& String::operator= (const char* s) {
	m_isNull = (s == nullptr);
	m_isDirty = (m_isDirty || (s != *this));
	std::string::operator=(s);
	return *this;
}

String& String::operator= (char c) {
	std::string tmp(1, c);
	m_isDirty = (m_isDirty || (tmp != *this));
	m_isNull = false;
	std::string::operator=(tmp);
	return *this;
}

String& String::operator= (std::initializer_list<char> il) {
	std::string tmp(il);
	m_isDirty = (m_isDirty || (tmp != *this));
	m_isNull = false;
	std::string::operator=(tmp);
	return *this;
}

String& String::operator= (std::string&& str) noexcept {
	m_isDirty = (m_isDirty || (str != *this));
	m_isNull = false;
	std::string::operator=(str);
	return *this;
}

String& String::operator= (String&& str) noexcept {
	m_isDirty = (m_isDirty || (str != *this));
	m_isNull = str.m_isNull;
	std::string::operator=(str);
	return *this;
}

String& String::operator= (const std::nullptr_t& jsonValue) noexcept {
	m_isDirty = (m_isDirty || (m_isNull == false));
	std::string::operator=("");
	m_isNull = true;
	return *this;
}

double String::asDouble(double defValue)
{
	try {
		if (m_isNull) {
			return defValue;
		} else {
			return std::stod(*this);
		}
	} catch(const std::exception& e) {
		return defValue;
	}
}

bool isDirty(const String& p) {
	return p.isDirty();
}

void to_json(nlohmann::json& j, const String& p)
{
	if (p.isDirty()) {
		nlohmann::detail::external_constructor<nlohmann::detail::value_t::string>::construct(j, p);
	}
}

} /* namespace common */
} /* namespace v20 */
} /* namespace oanda */
