//
// Created by tategotoazarasi on 2021/12/25.
//

#ifndef PROBLEMSCPP_MAJORITY_ELEMENT_H
#define PROBLEMSCPP_MAJORITY_ELEMENT_H

#include<vector>
#include<map>

namespace majority_element {
    class Solution {
    private:
        std::map<int, int> map;
    public:
        Solution();

        int majorityElement(std::vector<int> &nums);
    };
}


#endif //PROBLEMSCPP_MAJORITY_ELEMENT_H
