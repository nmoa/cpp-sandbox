#include <iostream>

using namespace std;

template<typename T>
unsigned int minIdx(const T* rv_array, std::size_t rv_array_size) {
    unsigned int at_min_idx = 0;
    for(std::size_t i = 0; i < rv_array_size; i++) {
        if(rv_array[i] < rv_array[at_min_idx]) {
            at_min_idx = i;
        }
    }
    return at_min_idx;
}

int main() {
    const int array[4] = {1, 2, 3, 4};
    cout << sizeof(array) / sizeof(array[0]) << endl;
    cout << minIdx(array, sizeof(array) / sizeof(array[0])) << endl;
}
