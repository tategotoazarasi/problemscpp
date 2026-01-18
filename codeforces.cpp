//
// Created by wangzhiheng on 17/10/2025.
//
#include "codeforces.h"

#include <algorithm>
#include <array>
#include <cstdint>
#include <iosfwd>
#include <iostream>
#include <limits.h>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
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

	namespace rae_taylor_and_trees {
		int main(istream &cin, ostream &cout) {
			int t;
			cin >> t;
			while(t--) {
				int n;
				cin >> n;
				vector<int> p(n);
				vector<int> lmin(n, n);
				vector<int> rmax(n, 1);
				for(int i = 0; i < n; i++) {
					cin >> p[i];
				}
				for(int i = 1; i < n; i++) {
					lmin[i] = min(lmin[i - 1], p[i - 1]);
				}
				for(int i = n - 2; i >= 0; i--) {
					rmax[i] = max(rmax[i + 1], p[i + 1]);
				}
				if(p[0] > rmax[0] || p[n - 1] < lmin[n - 1]) {
					cout << "No" << endl;
					continue;
				}
				bool flag = true;
				for(int i = 1; i < n - 1; i++) {
					if(lmin[i] > rmax[i]) {
						cout << "No" << endl;
						flag = false;
						break;
					}
				}
				if(flag) {
					cout << "Yes" << endl;
				}
			}
			return 0;
		}
	}// namespace rae_taylor_and_trees

	namespace perfect_root {
		int main(istream &cin, ostream &cout) {
			int t;
			cin >> t;
			while(t--) {
				int n;
				cin >> n;
				for(int i = 1; i <= n; i++) {
					cout << i << ' ';
				}
				cout << endl;
			}
			return 0;
		}
	}// namespace perfect_root

	namespace prefix_max {
		int main(istream &cin, ostream &cout) {
			int t;
			cin >> t;
			while(t--) {
				int n;
				cin >> n;
				vector<int> vec(n);
				for(int i = 0; i < n; i++) {
					cin >> vec[i];
				}
				vector<int> pref_max(n);
				int maximuim = vec[0];
				for(int i = 0; i < n; i++) {
					maximuim    = max(vec[i], maximuim);
					pref_max[i] = maximuim;
				}
				vector<int> pref_sum(n);
				int sum = 0;
				for(int i = 0; i < n; i++) {
					sum += pref_max[i];
					pref_sum[i] = sum;
				}
				int ans = pref_sum[n - 1];
				for(int i = 1; i < n; i++) {
					int j = 0;
					while(pref_max[j] < vec[i]) {
						j++;
					}
					int val = vec[j] * j + (pref_sum[n - 1] - ((j - 1 >= 0) ? pref_sum[j - 1] : 0));
					ans     = max(ans, val);
				}
				cout << ans << endl;
			}
			return 0;
		}
	}// namespace prefix_max

	namespace shifted_mex {
		int main(istream &cin, ostream &cout) {
			int t;
			cin >> t;
			while(t--) {
				int n;
				cin >> n;
				unordered_set<int> nums;
				while(n--) {
					int a;
					cin >> a;
					nums.insert(a);
				}
				vector<int> vec(nums.begin(), nums.end());
				sort(vec.begin(), vec.end());
				int prev        = vec[0];
				int current_len = 1;
				int max_len     = 1;
				for(int i = 1; i < vec.size(); i++) {
					if(vec[i] == prev + 1) {
						current_len++;
					} else {
						current_len = 1;
					}
					max_len = max(max_len, current_len);
					prev    = vec[i];
				}
				max_len = max(max_len, current_len);
				cout << max_len << endl;
			}
			return 0;
		}
	}// namespace shifted_mex

	namespace out_of_memory_error {
		int main(istream &cin, ostream &cout) {
			int t;
			cin >> t;
			while(t--) {
				int n, m, h;
				cin >> n >> m >> h;
				vector<int> a(n + 1);
				for(int i = 1; i <= n; i++) {
					cin >> a[i];
				}
				unordered_map<int, int> um = {};
				while(m--) {
					int b, c;
					cin >> b >> c;
					if(!um.contains(b)) {
						um[b] = a[b];
					}
					um[b] += c;
					if(um[b] > h) {
						um.clear();
					}
				}
				for(const auto &[k, v]: um) {
					a[k] = v;
				}
				for(int i = 1; i <= n; i++) {
					cout << a[i] << ' ';
				}
				cout << endl;
			}
			return 0;
		}
	}// namespace out_of_memory_error

	namespace the_robotic_rush {
		int main(istream &cin, ostream &cout) {
			int t;
			cin >> t;
			while(t--) {
				int n, m, k;
				cin >> n >> m >> k;
				vector<int> a(n);
				vector<int> b(m);
				vector<node> nodes(n + m);
				int nodes_i = 0;
				string instructions;
				for(int i = 0; i < n; i++) {
					cin >> a[i];
					nodes[nodes_i++] = node{true, a[i]};
				}
				for(int i = 0; i < m; i++) {
					cin >> b[i];
					nodes[nodes_i++] = node{false, b[i]};
				}
				ranges::sort(nodes, [](const node &a, const node &b) {
					return a.pos < b.pos;
				});
				int lmax = INT_MIN;
				int rmin = INT_MAX;
				for(auto &node: nodes) {
					if(!node.robot) {
						lmax = max(lmax, node.pos);
					}
					node.lmax = lmax;
				}
				for(int i = nodes.size() - 1; i >= 0; i--) {
					if(!nodes[i].robot) {
						rmin = min(rmin, nodes[i].pos);
					}
					nodes[i].rmin = rmin;
				}
				cin >> instructions;
				vector<int> r_max(k);
				int rmax = 0;
				lmax     = 0;
				vector<int> l_max(k);
				int pos = 0;
				for(int i = 0; i < instructions.size(); i++) {
					if(instructions[i] == 'L') {
						pos--;
					} else {
						pos++;
					}
					rmax     = max(rmax, pos);
					lmax     = max(lmax, -pos);
					r_max[i] = rmax;
					l_max[i] = lmax;
				}
				vector<int> drop(k, 0);
				for(auto &node: nodes) {
					if(node.robot) {
						int dist_to_right = (node.rmin == INT_MAX) ? INT_MAX : (node.rmin - node.pos);
						int dist_to_left  = (node.lmax == INT_MIN) ? INT_MAX : (node.pos - node.lmax);
						auto r_exceed     = std::lower_bound(r_max.begin(), r_max.end(), dist_to_right);
						auto l_exceed     = std::lower_bound(l_max.begin(), l_max.end(), dist_to_left);
						int min_d         = min(std::distance(r_max.begin(), r_exceed), std::distance(l_max.begin(), l_exceed));
						if(min_d < drop.size()) {
							drop[min_d]++;
						}
					}
				}
				int current = n;
				for(int i = 0; i < k; i++) {
					current -= drop[i];
					cout << current << ' ';
				}
				cout << endl;
			}
			return 0;
		}
	}// namespace the_robotic_rush
}// namespace codeforces