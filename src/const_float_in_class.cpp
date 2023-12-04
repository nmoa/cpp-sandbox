#include <iostream>

using std::cout;
using std::endl;

class Hoge {
private:
	static const int   n = 3;
	static const float f;
	static const float array[n];

public:
	Hoge(/* args */);
	~Hoge();
	void get(void);
};

Hoge::Hoge(/* args */) {}

Hoge::~Hoge() {}

const float Hoge::f              = 1.0f;
const float Hoge::array[Hoge::n] = {1.0f, 2.0f, 3.0f};

void Hoge::get(void) {
	cout << this->f << endl;
	cout << this->array[0] << endl;
}

int main(void) {
	Hoge hoge;
	hoge.get();
	return 0;
}
