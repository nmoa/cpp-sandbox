#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::strtoul;

int main(void) {
	char s[256];
	cout << "input: ";
	cin >> s;
	unsigned int ui = strtoul(s, NULL, 10);
	cout << ui << endl;
	return 0;
}
