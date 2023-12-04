#include <iostream>
#include <cstring>
#include <cstdio>

class String {
private:
	static const int c_length = 10;
	char             m_name[c_length];

public:
	String(const char* rv_name) {
		std::strncpy(m_name, rv_name, c_length);
	}
	const char* getName() const {
		return m_name;
	}
};


int main(void) {
	String str = String("Hello");
	std::printf("%s\n", str.getName());
	return 0;
}
