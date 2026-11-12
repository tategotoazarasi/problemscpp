//
// Created by wangzhiheng on 10/11/2026.
//

#ifndef PROBLEMSCPP_NOWCODER_H
#define PROBLEMSCPP_NOWCODER_H
#include <climits>
#include <iosfwd>
#include <istream>
#include <unordered_set>
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

	namespace realhw236 {
		struct Product {
			string id;
			int category;
			int price;
			int fulfillment;
		};
		void dfs(int budget, int n, const vector<Product> &vec, int cur, int fulfillment, int total_price, const unordered_set<int> &categories, int discount, int *ans);
		int main(std::istream &cin, std::ostream &cout);
	}// namespace realhw236

	namespace hj3 {
		int main(std::istream &cin, std::ostream &cout);
	}

	namespace realhw167 {
		class SemVer {
		private:
			int ver1 = -1;
			int ver2 = -1;
			int ver3 = -1;
			int ver4 = -1;
			int beta = INT_MAX;

		public:
			string str = "";
			SemVer()   = default;
			SemVer(string str);
			bool operator==(const SemVer &b) const;
			bool operator<(const SemVer &b) const;
		};
		int main(std::istream &cin, std::ostream &cout);
	}// namespace realhw167
};// namespace nowcoder


#endif//PROBLEMSCPP_NOWCODER_H
