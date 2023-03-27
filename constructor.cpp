#include <new>  // for placement new
#include <iostream>
#include <assert.h>
#include <cstring>

using std::cout;
using std::endl;

class Inner {
public:
	Inner();
	explicit Inner(int rv_i);
	~Inner();
	Inner(const Inner& obj);
	Inner& getThis(void) {
		return *this;
	}
	int i;
};

Inner::Inner() : i(1) {
	cout << "Ctor of Inner"
	     << ": " << i << endl;
}

Inner::Inner(int rv_i) : i(rv_i) {
	cout << "Ctor of Inner"
	     << ": " << i << endl;
	std::cout << "this = " << this << std::endl;
}

Inner::Inner(const Inner& obj) {
	cout << "Copy ctor of Inner" << endl;
	cout << "(*this).i = " << (*this).i << endl;
	cout << "obj.i = " << obj.i << endl;
	std::cout << "&obj = " << &obj << std::endl;
	std::cout << "this = " << this << std::endl;

	this->i = obj.i;
}

Inner::~Inner() {
	cout << "Destruct Inner" << endl;
}

class Outer {
private:
	Inner inner;
	Inner inner2;

public:
	explicit Outer(const Inner& rv_inner);
	~Outer();
	Outer(const Outer& obj) {
		cout << "Copy ctor of Outer" << endl;
	}

	void print(void) {
		cout << __func__ << ": " << this->inner.i << endl;
		cout << __func__ << ": " << this->inner2.i << endl;
	}
};

Outer::Outer(const Inner& rv_inner) : inner(rv_inner), inner2(inner.getThis()) {
	cout << "Ctor of Outer" << endl;
	cout << "&rv_inner = " << &rv_inner << endl;
	cout << "&inner = " << &inner << endl;
}

Outer::~Outer() {
	cout << "Destruct Outer" << endl;
}

Outer o(Inner(2));

int main() {
	o.print();
	return 0;
}
