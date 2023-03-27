#include <iostream>
#include "const.h"

const int   c_number_of_velos                      = 3;
const float c_ctrl_cycle_sec                       = 5e-4f;
const float c_major_velo_ref_mm[c_number_of_velos] = {1, 2, 3};

int main(void) {
    std::cout << c_major_velo_ref_mm[0] << std::endl;
    return 0;
}
