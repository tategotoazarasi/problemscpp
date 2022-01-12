#include "luogu.h"
#include <iostream>

using namespace std;

namespace luogu {
	int T210229::main(istream &cin, ostream &cout) {
		int n;
		int len = 0;
		string s[1000010];
		cin >> n;
		int _max    = 0;
		int max_cnt = 0;
		int k       = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> s[i];
			len += s[i].size();
			int cnt = 1;
			for(int j = 1; j < s[i].size(); ++j) {
				if(s[i][j] != s[i][j - 1]) {
					++cnt;
				}
			}
			if(cnt == _max && s[i] != s[k]) {
				++max_cnt;
			} else if(_max < cnt) {
				_max    = cnt;
				max_cnt = 0;
				k       = i;
			}
		}
		if(max_cnt != 0) {
			++_max;
		}
		cout << len - _max << endl;
		return 0;
	}
}// namespace luogu
