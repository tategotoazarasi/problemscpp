//
// Created by wangzhiheng on 10/11/2026.
//

#include "nowcoder.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream>
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

	namespace hj3 {
		int main(std::istream &cin, std::ostream &cout) {
			int n;
			cin >> n;
			unordered_set<int> us = {};
			int a;
			while(n--) {
				cin >> a;
				us.insert(a);
			}
			vector<int> vec = vector<int>(us.size());
			int cur         = 0;
			for(auto i: us) {
				vec[cur++] = i;
			}
			sort(vec.begin(), vec.end());
			for(auto i: vec) {
				cout << i << endl;
			}
			return 0;
		}
	}// namespace hj3

	namespace realhw167 {
		SemVer::SemVer(string str) {
			this->str = str;
			int l     = 0;
			int r     = 0;
			while(true) {
				if(r >= str.length() || !isdigit(str[r])) {
					stringstream ss;
					for(int i = l; i < r; i++) {
						ss << str[i];
					}
					if(this->ver1 == -1) {
						ss >> this->ver1;
					} else if(this->ver2 == -1) {
						ss >> this->ver2;
					} else if(this->ver3 == -1) {
						ss >> this->ver3;
					} else if(this->ver4 == -1) {
						ss >> this->ver4;
					}
					l = r + 1;
				}
				if(r >= str.length() || str[r] == ' ') {
					break;
				}
				r++;
			}
			l = r;
			while(l < str.length() && !isdigit(str[l]))
				l++;
			r        = l;
			int beta = 0;
			while(r < str.length() && isdigit(str[r])) {
				beta *= 10;
				beta += str[r++] - '0';
				this->beta = beta;
			}
		}

		bool SemVer::operator==(const SemVer &b) const {
			return this->ver1 == b.ver1 && this->ver2 == b.ver2 && this->ver3 == b.ver3 && this->ver4 == b.ver4 && this->beta == b.beta;
		}

		bool SemVer::operator<(const SemVer &b) const {
			if(this->ver1 != b.ver1) {
				return this->ver1 < b.ver1;
			}
			if(this->ver2 != b.ver2) {
				return this->ver2 < b.ver2;
			}
			if(this->ver3 != b.ver3) {
				return this->ver3 < b.ver3;
			}
			if(this->ver4 != b.ver4) {
				return this->ver4 < b.ver4;
			}
			return this->beta < b.beta;
		}

		int main(std::istream &cin, std::ostream &cout) {
			int n;
			cin >> n;
			vector<SemVer> vec(n);
			string str;
			getline(cin, str);
			for(int i = 0; i < n; i++) {
				getline(cin, str);
				vec[i] = SemVer(str);
			}
			sort(vec.begin(), vec.end());
			for(int i = 0; i < n; i++) {
				cout << vec[i].str << endl;
			}
			return 0;
		}
	}// namespace realhw167
};// namespace nowcoder