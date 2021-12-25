//
// Created by tategotoazarasi on 2021/12/25.
//

#include "acwing4201.h"
#include<cmath>
#include<vector>

using namespace std;

namespace acwing4201 {
    int acwing4201::Solution::main(int number) {
        int copy = number;
        int len = 0;
        while (copy != 0) {
            copy /= 10;
            len++;
        }
        vector<int> arr = vector<int>(len);
        copy = number;
        for (int i = len - 1; i >= 0; i--) {
            arr[i] = copy % 10;
            copy /= 10;
        }

        int sum = static_cast<int>(pow(2, len));
        for (int i = 0; i < len; i++) {
            if (arr[i] > 1) {
                break;
            } else if (arr[i] == 0) {
                sum -= static_cast<int>(pow(2, len - i - 1));
            }
        }
        sum--;
        return sum;
    }
}