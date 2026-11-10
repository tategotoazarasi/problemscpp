//
// Created by wangzhiheng on 10/11/2026.
//

#include "leetcode_hw.h"
#include <iostream>
#include <sstream>

using namespace std;

namespace leetcode::hw {
	namespace maximum_binary_string_after_change {
		string Solution::maximumBinaryString(string binary) {
			int start = 0;
			while(binary[start] == '1') {
				start++;
			}
			bool have_0 = false;
			;
			int cnt_1 = 0;
			for(int i = start; i < binary.length(); i++) {
				if(binary[i] == '1') {
					cnt_1++;
				} else {
					have_0 = true;
				}
			}
			ostringstream oss;
			for(int i = 0; i < start; i++) {
				oss << '1';
			}
			for(int i = start; i < binary.length() - 1 - cnt_1; i++) {
				oss << '1';
			}
			if(have_0)
				oss << '0';
			for(int i = 0; i < cnt_1; i++) {
				oss << '1';
			}
			return oss.str();
		}
	}// namespace maximum_binary_string_after_change
}// namespace leetcode::hw