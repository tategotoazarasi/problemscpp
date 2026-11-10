//
// Created by wangzhiheng on 10/11/2026.
//

#include "nowcoder.h"
#include <iostream>
#include <string>

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
};// namespace nowcoder