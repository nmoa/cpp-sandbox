#include <cstring>



/**
 * @brief ŒÅ’è’·‚Ì•¶š—ñ‚ğˆµ‚¤‚½‚ß‚ÌƒNƒ‰ƒX
 * 
 */
class FixedString {
private:
	/* data */
	char* m_str;
	int   m_len;

public:
	/**
     * @brief Construct a new Fixed String object
     * 
     */
	FixedString();

	/**
     * @brief Construct a new Fixed String object
     * 
     * @param str 
     */
	FixedString(const char* str);

	/**
     * @brief Construct a new Fixed String object
     * 
     * @param str 
     */
	FixedString(const FixedString& str);

	/**
     * @brief Destroy the Fixed String object
     * 
     */
	~FixedString();

	/**
     * @brief •¶š—ñ‚Ì’·‚³‚ğ•Ô‚·
     * 
     * @return int 
     */
	int length(void) const;

	/**
     * @brief •¶š—ñ‚ğ•Ô‚·
     * 
     * @return const char* 
     */
	const char* c_str(void) const;

	/**
     * @brief •¶š—ñ‚ğİ’è‚·‚é
     * 
     * @param str 
     */

	void set(const char* str);

	/**
     * @brief •¶š—ñ‚ğİ’è‚·‚é
     * 
     * @param str 
     */
	void set(const FixedString& str);

	/**
     * @brief •¶š—ñ‚ğİ’è‚·‚é
     * 
     * @param str 
     */
	void set(const char* str, int len);

	/**
     * @brief •¶š—ñ‚ğ’Ç‰Á‚·‚é
     * 
     * @param str 
     */
	void append(const char* str);

	/**
     * @brief •¶š—ñ‚ğ’Ç‰Á‚·‚é
     * 
     * @param str 
     */
	void append(const FixedString& str);

	/**
     * @brief •¶š—ñ‚ğ’Ç‰Á‚·‚é
     * 
     * @param str 
     */
	void append(const char* str, int len);

	/**
     * @brief •¶š—ñ‚ğ”äŠr‚·‚é
     * 
     * @param str 
     * @return true 
     * @return false 
     */
	bool equals(const char* str) const;

	/**
     * @brief •¶š—ñ‚ğ”äŠr‚·‚é
     * 
     * @param str 
     * @return true 
     * @return false 
     */
	bool equals(const FixedString& str) const;

	/**
     * @brief •¶š—ñ‚ğ”äŠr‚·‚é
     * 
     * @param str 
     * @return true 
     * @return false 
     */
	bool equals(const char* str, int len) const;

	/**
     * @brief •¶š—ñ‚ğ”äŠr‚·‚é
     * 
     * @param str 
     * @return true 
     * @return false 
     */
	bool operator==(const char* str) const;

	/**
     * @brief •¶š—ñ‚ğ”äŠr‚·‚é
     * 
     * @param str 
     * @return true 
     * @return false 
     */
	bool operator==(const FixedString& str) const;

	/**
     * @brief •¶š—ñ‚ğ”äŠr‚·‚é
     * 
     * @param str 
     * @return true 
     * @return false 
     */
	bool operator!=(const char* str) const;

	/**
     * @brief •¶š—ñ‚ğ”äŠr‚·‚é
     * 
     * @param str 
     * @return true 
     * @return false 
     */
	bool operator!=(const FixedString& str) const;

	/**
     * @brief •¶š—ñ‚ğ”äŠr‚·‚é
     * 
     * @param str 
     * @return true 
     * @return false 
     */
	bool operator<(const char* str) const;

	/**
     * @brief •¶š—ñ‚ğ”äŠr‚·‚é
     * 
     * @param str
     * @return true
     * @return false
     */
	bool operator<(const FixedString& str) const;
};

// FixedString‚ÌÀ‘•
FixedString::FixedString() {
	m_str = nullptr;
	m_len = 0;
}

FixedString::FixedString(const char* str) {
	m_str = nullptr;
	m_len = 0;

	set(str);
}

FixedString::FixedString(const FixedString& str) {
	m_str = nullptr;
	m_len = 0;

	set(str);
}

FixedString::~FixedString() {
	if(m_str != nullptr) {
		delete[] m_str;
		m_str = nullptr;
	}

	m_len = 0;
}

int FixedString::length(void) const {
	return m_len;
}

const char* FixedString::c_str(void) const {
	return m_str;
}

void FixedString::set(const char* str) {
	if(m_str != nullptr) {
		delete[] m_str;
		m_str = nullptr;
	}

	m_len = strlen(str);
	m_str = new char[m_len + 1];
	strcpy(m_str, str);
}

void FixedString::set(const FixedString& str) {
	set(str.c_str());
}

void FixedString::set(const char* str, int len) {
	if(m_str != nullptr) {
		delete[] m_str;
		m_str = nullptr;
	}

	m_len = len;
	m_str = new char[m_len + 1];
	strncpy(m_str, str, m_len);
	m_str[m_len] = '\0';
}

void FixedString::append(const char* str) {
	int   len     = strlen(str);
	int   new_len = m_len + len;
	char* new_str = new char[new_len + 1];

	strncpy(new_str, m_str, m_len);
	strncpy(new_str + m_len, str, len);
	new_str[new_len] = '\0';

	if(m_str != nullptr) {
		delete[] m_str;
	}

	m_len = new_len;
	m_str = new_str;
}

void FixedString::append(const FixedString& str) {
	append(str.c_str());
}

void FixedString::append(const char* str, int len) {
	int   new_len = m_len + len;
	char* new_str = new char[new_len + 1];

	strncpy(new_str, m_str, m_len);
	strncpy(new_str + m_len, str, len);
	new_str[new_len] = '\0';

	if(m_str != nullptr) {
		delete[] m_str;
	}

	m_len = new_len;
	m_str = new_str;
}

bool FixedString::equals(const char* str) const {
	return (strcmp(m_str, str) == 0);
}

bool FixedString::equals(const FixedString& str) const {
	return equals(str.c_str());
}

bool FixedString::equals(const char* str, int len) const {
	return (strncmp(m_str, str, len) == 0);
}

bool FixedString::operator==(const char* str) const {
	return equals(str);
}

bool FixedString::operator==(const FixedString& str) const {
	return equals(str);
}

bool FixedString::operator!=(const char* str) const {
	return !equals(str);
}

bool FixedString::operator!=(const FixedString& str) const {
	return !equals(str);
}

bool FixedString::operator<(const char* str) const {
	return (strcmp(m_str, str) < 0);
}

bool FixedString::operator<(const FixedString& str) const {
	return (strcmp(m_str, str.c_str()) < 0);
}

// Path: main.cpp
// #include <iostream>
// #include "fixed-string.hpp"
//
// using namespace std;
//
// int main(void) {
// 	FixedString str1("abc");
// 	FixedString str2("def");
// 	FixedString str3(str1);
//
// 	cout << str1.c_str() << endl;
// 	cout << str2.c_str() << endl;
// 	cout << str3.c_str() << endl;
//
// 	str1.set("xyz");
// 	cout << str1.c_str() << endl;
// 	cout << str2.c_str() << endl;
// 	cout << str3.c_str() << endl;
//
// 	str1.append("abc");
// 	cout << str1.c_str() << endl;
// 	cout << str2.c_str() << endl;
// 	cout << str3.c_str() << endl;
//
// 	str1.append(str2);
// 	cout << str1.c_str() << endl;
// 	cout << str2.c_str() << endl;
// 	cout << str3.c_str() << endl;
//
// 	str1.append("1234567890", 5);
// 	cout << str1.c_str() << endl;
// 	cout << str2.c_str() << endl;
// 	cout << str3.c_str() << endl;
//
// 	cout << boolalpha
