//
// Created by tategotoazarasi on 2021/12/25.
//

#include "acwing4200.h"

namespace acwing4200 {
    int Solution::main(int p1, int p2, int p3, int p4, int a, int b) {
        int min = p1;
        min = p2 < min ? p2 : min;
        min = p3 < min ? p3 : min;
        min = p4 < min ? p4 : min;
        int ans = (min - a) < (b - a + 1) ? min - a : b - a + 1;
        return ans < 0 ? 0 : ans;
    }
}
