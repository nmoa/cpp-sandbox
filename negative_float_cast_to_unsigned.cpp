#include <iostream>

using namespace std;

int main(void) {
	float        f  = -123.45;
	unsigned int ui = static_cast<unsigned int>(f);
	int          i  = static_cast<int>(f);

	cout << ui << endl;
	cout << i << endl;
	cout << hex << ui << endl;
	cout << hex << i << endl;

	return 0;
}
