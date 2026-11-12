//
// Created by wangzhiheng on 10/11/2026.
//

#include "leetcode_hw.h"

#include <array>
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

	namespace minimum_cost_to_acquire_required_items {
		long long Solution::minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
			long long total_cost = 0;
			long long min_need   = 0;
			if(cost1 + cost2 > costBoth) {
				min_need = min(need1, need2);
				total_cost += min_need * costBoth;
			}
			total_cost += (need1 - min_need) * (costBoth > cost1 ? cost1 : costBoth);
			total_cost += (need2 - min_need) * (costBoth > cost2 ? cost2 : costBoth);
			return total_cost;
		}
	}// namespace minimum_cost_to_acquire_required_items

	namespace longest_valid_parentheses {
		int Solution::longestValidParentheses(string s) {
			int ans = 0;
			vector<Node *> vec(s.length());
			for(int i = 0; i < s.length(); i++) {
				vec[i]       = new Node();
				vec[i]->c    = s[i];
				vec[i]->pos  = i;
				vec[i]->lend = nullptr;
			}
			for(int i = 1; i < vec.size(); i++) {
				if(vec[i]->c == ')') {
					if(vec[i - 1]->lend == nullptr && vec[i - 1]->c == '(') {
						if(i - 2 > 0 && vec[i - 2]->lend != nullptr) {
							vec[i]->lend     = vec[i - 2]->lend;
							vec[i - 1]->lend = vec[i - 2]->lend;
						} else {
							vec[i]->lend     = vec[i - 1];
							vec[i - 1]->lend = vec[i - 1];
						}
					} else if(vec[i - 1]->lend != nullptr && vec[i - 1]->lend->pos - 1 >= 0 && vec[vec[i - 1]->lend->pos - 1]->c == '(') {
						vec[i]->lend                         = vec[vec[i - 1]->lend->pos - 1];
						vec[vec[i - 1]->lend->pos - 1]->lend = vec[vec[i - 1]->lend->pos - 1];
						if(vec[i - 1]->lend->pos - 2 >= 0 && vec[vec[i - 1]->lend->pos - 2]->lend != nullptr) {
							vec[i]->lend                         = vec[vec[i - 1]->lend->pos - 2]->lend;
							vec[vec[i - 1]->lend->pos - 1]->lend = vec[vec[i - 1]->lend->pos - 2]->lend;
						}
					}
					if(vec[i]->lend != nullptr) {
						ans = max(ans, vec[i]->pos - vec[i]->lend->pos + 1);
					}
				}
			}
			for(int i = 0; i < vec.size(); i++) {
				delete vec[i];
			}
			return ans;
		}
	}// namespace longest_valid_parentheses

	namespace longest_strictly_increasing_or_strictly_decreasing_subarray {
		int Solution::longestMonotonicSubarray(vector<int> &nums) {
			int inc     = 1;
			int dec     = 1;
			int current = 1;
			for(int i = 1; i < nums.size(); i++) {
				if(nums[i] > nums[i - 1]) {
					current++;
					inc = max(inc, current);
				} else {
					current = 1;
				}
			}
			current = 1;
			for(int i = 1; i < nums.size(); i++) {
				if(nums[i] < nums[i - 1]) {
					current++;
					dec = max(dec, current);
				} else {
					current = 1;
				}
			}

			return max(inc, dec);
		}
	}// namespace longest_strictly_increasing_or_strictly_decreasing_subarray

	namespace restore_ip_addresses {
		bool Solution::valid(const string &s, int a, int b) {
			a++;
			if(b > a && s[a] == '0') {
				return false;
			}
			int num = 0;
			while(a <= b) {
				num *= 10;
				num += s[a] - '0';
				a++;
			}
			return num <= 255;
		}
		void Solution::dfs(const string &s, int cur, int remain, vector<string> &res, array<int, 3> his) {
			if(remain == 0 && valid(s, cur, s.length() - 1)) {
				ostringstream oss;
				int his_cur = 0;
				for(int i = 0; i < s.size(); i++) {
					oss << s[i];
					if(his_cur < 3 && his[his_cur] == i) {
						his_cur++;
						oss << '.';
					}
				}
				res.push_back(oss.str());
			} else {
				for(int i = cur + 1; i <= cur + 3 && i < s.length(); i++) {
					int rest = s.length() - i - 1;
					if((3 * remain < rest) || remain > rest) {
						continue;
					}
					if(valid(s, cur, i)) {
						array<int, 3> new_his = his;
						new_his[3 - remain]   = i;
						dfs(s, i, remain - 1, res, new_his);
					}
				}
			}
		}
		vector<string> Solution::restoreIpAddresses(string s) {
			if(s.length() > 12) {
				return {};
			}
			vector<string> ans = {};
			array<int, 3> his  = {-1, -1, -1};
			dfs(s, -1, 3, ans, his);
			return ans;
		}
	}// namespace restore_ip_addresses
}// namespace leetcode::hw