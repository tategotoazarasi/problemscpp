//
// Created by wangzhiheng on 10/11/2026.
//

#include "leetcode_hw.h"
#include <iostream>
#include <limits.h>
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

	namespace climbing_stairs_ii {
		int Solution::climbStairs(int n, vector<int> &costs) {
			vector<int> dp(n + 1, INT_MAX);
			vector<int> new_cost(n + 1);
			new_cost[0] = 0;
			for(int i = 0; i < costs.size(); i++) {
				new_cost[i + 1] = costs[i];
			}
			dp[0] = 0;
			for(int i = 0; i <= n; i++) {
				for(int j = 1; j <= 3 && i + j < n + 1; j++) {
					dp[i + j] = min(dp[i + j], dp[i] + new_cost[i + j] + j * j);
				}
			}
			return dp[n];
		}
	}// namespace climbing_stairs_ii
}// namespace leetcode::hw