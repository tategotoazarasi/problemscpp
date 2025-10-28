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
	}// namespace your_name

	namespace isamatdin_and_his_magic_wand {
		TEST(isamatdin_and_his_magic_wand, case1) {
			istringstream in("7\n4\n2 3 1 4\n5\n3 2 1 3 4\n4\n3 7 5 1\n2\n1000000000 2\n3\n1 3 5\n5\n2 5 3 1 7\n4\n2 4 8 6\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1 2 3 4 \n1 2 3 3 4 \n3 7 5 1 \n1000000000 2 \n1 3 5 \n1 2 3 5 7 \n2 4 8 6 \n", ans);
		}
	}// namespace isamatdin_and_his_magic_wand

	namespace yet_another_array_problem {
		TEST(yet_another_array_problem, case1) {
			istringstream in("4\n1\n1\n4\n6 6 12 12\n3\n24 120 210\n4\n2 4 6 10\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2\n5\n5\n3\n", ans);
		}
	}// namespace yet_another_array_problem
}// namespace codeforces