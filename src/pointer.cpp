#include <iostream>

using namespace std;

int main(void) {
	int              i = 0;
	int              j = 10;
	const int*       p = &i;
	const int* const q = &i;
	*p                 = 1;   // NG�B�w��������������������Ȃ�
	p                  = &j;  // OK�B�|�C���^�͕t���ւ�����B
	q                  = &j;  // NG�B�|�C���^�̕t���ւ����ł��Ȃ��B

	const int arr[3] = {1, 2, 3};
	arr[0]           = 0;  // NG�Bconst�Ȕz��Ő錾����Ă���̂Œ��g�������������Ȃ��B
	return 0;
}
