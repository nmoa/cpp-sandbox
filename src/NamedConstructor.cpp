#include <iostream>
#include <string>

class Person {
public:
	static Person create() {
		return Person();
	}
	static Person withName(const std::string& name) {
		Person p;
		p.name_ = name;
		return p;
	}
	Person& withAge(int age) {
		age_ = age;
		return *this;
	}
	Person& withAddress(const std::string& address) {
		address_ = address;
		return *this;
	}
	void describe() const {
		std::cout << "Name: " << name_ << std::endl;
		std::cout << "Age: " << age_ << std::endl;
		std::cout << "Address: " << address_ << std::endl;
	}

private:
	std::string name_;
	int         age_ = 0;
	std::string address_;
};

int main() {
	Person p1 = Person::create();
	p1.describe();

	Person p2 = Person::withName("John");
	p2.describe();

	Person p3 = Person::create().withAge(30).withAddress("123 Main St.");
	p3.describe();

	return 0;
}
