/**
 * @file String.hpp
 * @author Scott Brauer
 * @date 01-21-2021
 */

#ifndef OANDA_V20_COMMON_STRING_HPP_
#define OANDA_V20_COMMON_STRING_HPP_

#include <string>

#include <nlohmann/json.hpp>

namespace oanda {
namespace v20 {
namespace common {

class String: public std::string
{
public:
	String();
	String(const std::string& str);
	String(const String& str);
	String(const std::string& str, size_t pos, size_t len = npos);
	String(const char* s);
	String(const char* s, size_t n);
	String(size_t n, char c);
	template <class InputIterator>
	String (InputIterator first, InputIterator last);
	String(std::initializer_list<char> il);
	String(std::string&& str) noexcept;
	String(const std::nullptr_t& jsonValue) noexcept;

	virtual ~String();

	String& operator= (const std::string& str);
	String& operator= (const String& str);
	String& operator= (const char* s);
	String& operator= (char c);
	String& operator= (std::initializer_list<char> il);
	String& operator= (std::string&& str) noexcept;
	String& operator= (String&& str) noexcept;
	String& operator= (const std::nullptr_t& jsonValue) noexcept;

	double asDouble(double defValue = 0.0);

	bool isDirty() const { return m_isDirty; }
	bool isNull() const { return m_isNull; }

private:
	bool m_isDirty;
	bool m_isNull;
};

bool isDirty(const String& p);
void to_json(nlohmann::json& j, const String& p);
//void from_json(const nlohmann::json& j, String& p);

} /* namespace common */
} /* namespace v20 */
} /* namespace oanda */

#endif /* OANDA_V20_COMMON_STRING_HPP_ */
