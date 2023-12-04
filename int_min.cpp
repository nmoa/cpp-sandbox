#include <iostream>
#include <climits>

using namespace std;

unsigned int g_ui;

void increment(void) {
	if(g_ui < UINT_MAX) {
		g_ui++;
	}
}

int main(void) {
	g_ui = UINT_MAX - 3;
	cout << g_ui << endl;

	increment();
	cout << g_ui << endl;

	increment();
	cout << g_ui << endl;

	increment();
	cout << g_ui << endl;

	increment();
	cout << g_ui << endl;

	return 0;
}
