//
// Created by tategotoazarasi on 2022/3/14.
//

#include "pat.h"
#include <bit>
#include <iostream>

using namespace std;

namespace pat {
	namespace b {
		namespace b1001 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				int ans = 0;
				while(n != 1) {
					if(n % 2 == 0) {
						n /= 2;
					} else {
						n = (3 * n + 1) / 2;
					}
					ans++;
				}
				cout << ans;
				return 0;
			}
		}// namespace b1001
	}    // namespace b

	namespace a {

	}

	namespace top {

	}
}// namespace pat