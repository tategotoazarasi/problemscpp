//
// Created by wangzhiheng on 17/10/2025.
//
#include "codeforces.h"
#include "gtest/gtest.h"

namespace codeforces {
	namespace beautiful_average {
		TEST(beautiful_average, case1) {
			istringstream in("3\n4\n3 3 3 3\n5\n7 1 6 9 9\n5\n3 4 4 4 3\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3\n9\n4\n", ans);
		}
	}// namespace beautiful_average

	namespace your_name {
		TEST(your_name, case1) {
			istringstream in("5\n7\nhumitsa mitsuha\n4\norhi hori\n6\naakima makima\n6\nnezuqo nezuko\n6\nmisaka mikasa\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("YES\nYES\nNO\nNO\nYES\n", ans);
		}
	}
}// namespace codeforces