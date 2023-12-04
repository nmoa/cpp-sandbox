#include <iostream>

using namespace std;

int main(void) {
	int              i = 0;
	int              j = 10;
	const int*       p = &i;
	const int* const q = &i;
	*p                 = 1;   // NG。指し示す先を書き換えられない
	p                  = &j;  // OK。ポインタは付け替えられる。
	q                  = &j;  // NG。ポインタの付け替えもできない。

	const int arr[3] = {1, 2, 3};
	arr[0]           = 0;  // NG。constな配列で宣言されているので中身を書き換えられない。
	return 0;
}
