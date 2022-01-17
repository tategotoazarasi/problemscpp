#include "luogu.h"
#include "gtest/gtest.h"

using namespace std;

namespace luogu {
	TEST(P1001, case1) {
		istringstream in("20 30");
		ostringstream out = ostringstream();
		P1001::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("50", ans);
	}
}// namespace luogu
