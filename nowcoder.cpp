//
// Created by wangzhiheng on 10/11/2026.
//

#include "nowcoder.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

namespace nowcoder {
	namespace hj1 {
		int main(std::istream &cin, std::ostream &cout) {
			string input;
			getline(cin, input);
			int cnt = 0;
			int c   = input.length() - 1;
			while(c >= 0 && !isalpha(input[c])) {
				c--;
			}
			while(c >= 0 && isalpha(input[c])) {
				c--;
				cnt++;
			}
			cout << cnt;
			return 0;
		}
	}// namespace hj1

	namespace realhw235 {
		unsigned long get_cost(const vector<unsigned long> &vec, unsigned long c, unsigned long f, unsigned long u, unsigned long target) {
			unsigned long cnt  = 0;
			unsigned long cost = 0;
			for(const auto &i: vec) {
				if(target > i) {
					cnt += target - i;
				}
			}
			cost += cnt * u;
			cost += (cnt / c) * f;
			if(cnt % c != 0) {
				cost += f;
			}
			return cost;
		}
		int main(std::istream &cin, std::ostream &cout) {
			unsigned long b, c, f, u, n;
			cin >> b >> c >> f >> u >> n;
			unsigned long l = -1;
			vector<unsigned long> vec(n);
			for(unsigned long i = 0; i < n; i++) {
				cin >> vec[i];
				l = min(vec[i], l);
			}
			unsigned long r = 2e6;
			while(l < r) {
				unsigned long mid  = (l + r) / 2;
				unsigned long cost = get_cost(vec, c, f, u, mid);
				if(cost < b) {
					l = mid;
				} else if(cost > b) {
					r = mid - 1;
				} else {
					cout << mid;
					return 0;
				}
				if(l == r) {
					cout << l;
					return 0;
				}
				if(l + 1 == r) {
					cost = get_cost(vec, c, f, u, r);
					if(cost <= b) {
						cout << r;
					} else {
						cout << l;
					}
					return 0;
				}
			}
			return 0;
		}
	}// namespace realhw235

	namespace hj2 {
		int main(std::istream &cin, std::ostream &cout) {
			string str;
			string str2;
			getline(cin, str);
			getline(cin, str2);
			char c  = str2[0];
			int ans = 0;
			for(char cc: str) {
				if(isdigit(c) && c == cc) {
					ans++;
				} else if(tolower(cc) == tolower(c)) {
					ans++;
				}
			}
			cout << ans;
			return 0;
		}
	}// namespace hj2

	namespace realhw236 {
		void dfs(int budget, int n, const vector<Product> &vec, int cur, int fulfillment, int total_price, const unordered_set<int> &categories, int discount, int *ans) {
			total_price += vec[cur].price;
			unordered_set<int> new_cate = categories;
			new_cate.insert(vec[cur].category);
			if(new_cate.size() >= 3) {
				discount = 30;
			}
			int final_price = total_price - (total_price / 200) * discount;
			fulfillment += vec[cur].fulfillment;
			if(final_price <= budget) {
				*ans = max(*ans, fulfillment);
			}
			for(int i = cur + 1; i < n; i++) {
				dfs(budget, n, vec, i, fulfillment, total_price, new_cate, discount, ans);
			}
		}
		int main(std::istream &cin, std::ostream &cout) {
			int budget, n;
			cin >> budget >> n;
			vector<Product> vec(n);
			for(int i = 0; i < n; i++) {
				cin >> vec[i].id >> vec[i].category >> vec[i].price >> vec[i].fulfillment;
			}
			int ans = 0;
			for(int i = 0; i < n; i++) {
				dfs(budget, n, vec, i, 0, 0, unordered_set<int>(), 20, &ans);
			}
			cout << ans;
			return 0;
		}
	}// namespace realhw236
};// namespace nowcoder