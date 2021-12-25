//
// Created by tategotoazarasi on 2021/12/25.
//

#include "majority_element.h"
#include<map>

using namespace std;
using namespace majority_element;

namespace majority_element {
    Solution::Solution() {
        this->map = std::map<int, int>();
    }

    int Solution::majorityElement(vector<int> &nums) {
        for (int i: nums) {
            if (map.contains(i)) {
                map[i] = map[i] + 1;
                if (map[i] > nums.size() / 2) {
                    return i;
                }
            } else {
                map[i] = 1;
            }
        }
    }
}