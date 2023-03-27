#include <cstring>

class String {
public:
	String(const char* str = "") {
		std::size_t len = std::strlen(str);
		if(len >= MAX_SIZE) {
			len = MAX_SIZE - 1;
		}
		std::memcpy(m_data, str, len);
		m_data[len] = '\0';
	}

	std::size_t length() const {
		return std::strlen(m_data);
	}

	const char* c_str() const {
		return m_data;
	}

	bool operator==(const String& other) const {
		return std::strcmp(m_data, other.m_data) == 0;
	}

	bool operator!=(const String& other) const {
		return !(*this == other);
	}

	String operator+(const String& other) const {
		String result = *this;
		result += other;
		return result;
	}

	String& operator+=(const String& other) {
		std::size_t len1 = std::strlen(m_data);
		std::size_t len2 = std::strlen(other.m_data);
		if(len1 + len2 >= MAX_SIZE) {
			len2 = MAX_SIZE - 1 - len1;
		}
		std::memcpy(m_data + len1, other.m_data, len2);
		m_data[len1 + len2] = '\0';
		return *this;
	}

private:
	static const std::size_t MAX_SIZE = 256;
	char                     m_data[MAX_SIZE];
};
