//
// Created by wangzhiheng on 17/10/2025.
//
#include "codeforces.h"

#include <algorithm>
#include <array>
#include <cstdint>
#include <iosfwd>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

namespace codeforces {
	namespace beautiful_average {
		int main(istream &cin, ostream &cout) {
			int t;
			cin >> t;
			while(t--) {
				int n;
				cin >> n;
				vector<int> arr(n);
				vector<int> pref_sum(n + 1, 0);
				for(int i = 0; i < n; i++) {
					cin >> arr[i];
					pref_sum[i + 1] = pref_sum[i] + arr[i];
				}
				int ans = -1;
				for(int i = 0; i < n; i++) {
					for(int j = i; j < n; j++) {
						int sum = pref_sum[j + 1] - pref_sum[i];
						int avg = sum / (j - i + 1);
						ans     = max(avg, ans);
					}
				}
				cout << ans << endl;
			}
			return 0;
		}
	}// namespace beautiful_average

	namespace beautiful_string {
		int main(istream &cin, ostream &cout) {
			int t;
			cin >> t;
			while(t--) {
				int k;
				string s;
				cin >> k >> s;
				int cnt         = 0;
				vector<int> ans = vector<int>();
				for(int i = 0; i < k; i++) {
					if(s[i] == '0') {
						cnt++;
						ans.push_back(i + 1);
					}
				}
				cout << cnt << endl;
				bool first = true;
				for(int i = 0; i < ans.size(); i++) {
					if(first) {
						cout << ans[i];
						first = false;
					} else {
						cout << " " << ans[i];
					}
				}
				cout << endl;
			}
			return 0;
		}
	}// namespace beautiful_string

	namespace your_name {
		int main(istream &cin, ostream &cout) {
			int q;
			cin >> q;
			while(q--) {
				int n;
				cin >> n;
				string s, t;
				cin >> s >> t;
				char a[26] = {};
				char b[26] = {};
				for(char c: s) {
					a[c - 'a']++;
				}
				for(char c: t) {
					b[c - 'a']++;
				}
				bool flag = true;
				for(int i = 0; i < 26; i++) {
					if(a[i] != b[i]) {
						cout << "NO" << endl;
						flag = false;
						break;
					}
				}
				if(flag) {
					cout << "YES" << endl;
				}
			}
			return 0;
		}
	}// namespace your_name

	namespace isamatdin_and_his_magic_wand {
		int main(istream &cin, ostream &cout) {
			int t;
			cin >> t;
			while(t--) {
				int n;
				cin >> n;
				bool all_even   = true;
				bool all_odd    = true;
				vector<int> vec = vector<int>(n);
				for(int i = 0; i < n; i++) {
					cin >> vec[i];
					if(vec[i] % 2 == 0) {
						all_odd = false;
					} else {
						all_even = false;
					}
				}
				if(!all_odd && !all_even) {
					sort(vec.begin(), vec.end());
				}
				for(int i = 0; i < n; i++) {
					cout << vec[i] << ' ';
				}
				cout << endl;
			}
			return 0;
		}
	}// namespace isamatdin_and_his_magic_wand

	namespace yet_another_array_problem {

		uint64_t gcd(uint64_t a1, uint64_t a2) {
			while(a2) {
				uint64_t temp = a2;
				a2            = a1 % a2;
				a1            = temp;
			}
			return a1;
		}

		int main(istream &cin, ostream &cout) {
			const uint64_t N = 1000000000000000000;
			int t;
			cin >> t;
			while(t--) {
				int n;
				cin >> n;
				uint64_t smallest = -1;
				while(n--) {
					uint64_t a;
					cin >> a;
					for(uint64_t x = 2; x < smallest && x <= N; x++) {
						if(gcd(x, a) == 1) {
							smallest = x;
							break;
						}
					}
				}
				if(smallest == -1) {
					cout << -1;
				} else {
					cout << smallest;
				}
				cout << endl;
			}
			return 0;
		}
	}// namespace yet_another_array_problem

	namespace shizuku_hoshikawa_and_farm_legs {
		int main(istream &cin, ostream &cout) {
			int t = 0;
			cin >> t;
			while(t--) {
				int n;
				int cnt = 0;
				cin >> n;
				for(int i = 0; i <= n / 2; i++) {
					if((n - 2 * i) % 4 == 0) {
						cnt++;
					}
				}
				cout << cnt << endl;
			}
			return 0;
		}
	}// namespace shizuku_hoshikawa_and_farm_legs

	namespace yuu_koito_and_minimum_absolute_sum {
		int main(istream &cin, ostream &cout) {
			int t;
			cin >> t;
			while(t--) {
				int n;
				cin >> n;
				int sum = 0;
				vector<int> a(n);
				for(int i = 0; i < n; i++) {
					cin >> a[i];
					if(a[i] == -1 && i > 0 && i < n - 1) {
						a[i] = 0;
					}
					if(a[i] != -1 && i > 0 && a[i - 1] != -1) {
						sum += a[i] - a[i - 1];
					}
				}
				if(n == 2 && a[0] == -1 && a[1] == -1) {
					cout << 0 << endl
					     << "0 0" << endl;
					continue;
				}
				if(a[n - 1] == -1) {
					if(a[0] == -1) {
						a[0] = 0;
						sum += a[1];
					}
					a[n - 1] = a[n - 2] - sum;
					sum      = 0;
				} else if(a[0] == -1) {
					a[0] = a[1] + sum;
					sum  = 0;
				}
				cout << abs(sum) << endl;
				for(int i = 0; i < n; i++) {
					cout << a[i] << " ";
				}
				cout << endl;
			}
			return 0;
		}
	}// namespace yuu_koito_and_minimum_absolute_sum

	namespace renako_amaori_and_xor_game {
		int main(istream &cin, ostream &cout) {
			int t;
			cin >> t;
			while(t--) {
				int n;
				cin >> n;
				vector<int> a(n);
				vector<int> b(n);

				int res_a = 0;
				for(int i = 0; i < n; i++) {
					cin >> a[i];
					res_a ^= a[i];
				}

				int res_b     = 0;
				int last_diff = -1;

				for(int i = 0; i < n; i++) {
					cin >> b[i];
					res_b ^= b[i];
					if(a[i] != b[i]) {
						last_diff = i;
					}
				}

				if(res_a == res_b) {
					cout << "Tie" << endl;
				} else {
					if(last_diff % 2 == 0) {
						cout << "Ajisai" << endl;
					} else {
						cout << "Mai" << endl;
					}
				}
			}
			return 0;
		}
	}// namespace renako_amaori_and_xor_game
}// namespace codeforces