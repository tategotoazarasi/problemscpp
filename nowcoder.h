//
// Created by wangzhiheng on 10/11/2026.
//

#ifndef PROBLEMSCPP_NOWCODER_H
#define PROBLEMSCPP_NOWCODER_H
#include <iosfwd>
#include <istream>
#include <vector>
using namespace std;

namespace nowcoder {
	namespace hj1 {
		int main(std::istream & /*cin*/, std::ostream & /*cout*/);
	}

	namespace realhw235 {
		int main(std::istream & /*cin*/, std::ostream & /*cout*/);
		unsigned long get_cost(const vector<int> &vec, int c, int f, int u, int target);
	}// namespace realhw235

	namespace hj2 {
		int main(std::istream &cin, std::ostream &cout);
	}
};// namespace nowcoder


#endif//PROBLEMSCPP_NOWCODER_H
