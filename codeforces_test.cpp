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
}// namespace codeforces