//
// Created by wangzhiheng on 17/10/2025.
//
#include "codeforces.h"

#include <algorithm>
#include <iosfwd>
#include <iostream>
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
}// namespace codeforces