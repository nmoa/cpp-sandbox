#include <iostream>

using namespace std;

struct SFmWind {
    static const int c_times = 2;
    unsigned int     address;
    unsigned int     value[3][c_times];
};

enum EADJUSTED_COLOR {
    eNotAdjusted   = 0,
    eAdjustedRed   = 1,
    eAdjustedGreen = 2,
    eAdjustedBlue  = 3,
};

const SFmWind fmwindset1 = {0x580BC, {{0x3A, 0xBA}, {0x0A, 0x8A}, {0x3A, 0xBA}}};
const SFmWind fmwindset2 = {0x580BD, {{0x0F, 0x1C}, {0x00, 0x0D}, {0x0F, 0x1C}}};
const SFmWind fmwindrst1 = {0x580BE, {{0xBA, 0x6A}, {0x8A, 0x3A}, {0xBA, 0x6A}}};
const SFmWind fmwindrst2 = {0x580BF, {{0x1C, 0x1E}, {0x0D, 0x0F}, {0x1C, 0x1E}}};

int main() {
    cout << hex << fmwindset1.address << endl;
    for(int cis = 0; cis < 3; cis++) {
        for(int num = 0; num < SFmWind::c_times; num++) {
            cout << hex << fmwindset1.value[cis][num] << endl;
        }
    }
    int array[4] = {1, 2, 3, 4};
    cout << array[eNotAdjusted] << endl;
}
