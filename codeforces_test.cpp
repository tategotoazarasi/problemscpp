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

	namespace shizuku_hoshikawa_and_farm_legs {
		TEST(shizuku_hoshikawa_and_farm_legs, case1) {
			istringstream in("5\n2\n3\n4\n6\n100\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1\n0\n2\n2\n26\n", ans);
		}
	}// namespace shizuku_hoshikawa_and_farm_legs

	namespace yuu_koito_and_minimum_absolute_sum {
		TEST(yuu_koito_and_minimum_absolute_sum, case1) {
			istringstream in("6\n4\n2 -1 7 1\n4\n-1 2 4 -1\n8\n2 -1 1 5 11 12 1 -1\n3\n-1 -1 -1\n3\n2 5 4\n2\n-1 5\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1\n2 0 7 1 \n0\n0 2 4 0 \n0\n2 0 1 5 11 12 1 2 \n0\n0 0 0 \n2\n2 5 4 \n0\n5 5 \n", ans);
		}
	}// namespace yuu_koito_and_minimum_absolute_sum

	namespace renako_amaori_and_xor_game {
		TEST(renako_amaori_and_xor_game, case1) {
			istringstream in("6\n4\n1 0 0 1\n1 0 1 1\n6\n0 1 1 1 1 0\n0 0 1 0 1 1\n4\n0 0 1 0\n1 0 1 1\n5\n1 0 1 1 1\n0 1 1 1 0\n6\n1 1 1 1 1 1\n1 1 1 1 1 1\n5\n0 1 0 0 1\n1 0 0 1 1\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("Ajisai\nMai\nTie\nAjisai\nTie\nMai\n", ans);
		}
	}// namespace renako_amaori_and_xor_game

	namespace rae_taylor_and_trees {
		TEST(rae_taylor_and_trees, case1) {
			istringstream in("9\n6\n1 3 4 5 2 6\n4\n3 4 1 2\n5\n4 3 5 1 2\n4\n1 2 3 4\n7\n4 3 5 7 6 2 1\n6\n2 4 6 1 3 5\n3\n2 1 3\n4\n2 4 1 3\n6\n4 2 6 5 1 3\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("Yes\nNo\nNo\nYes\nNo\nYes\nYes\nYes\nYes\n", ans);
		}
	}// namespace rae_taylor_and_trees

	namespace prefix_max {
		TEST(prefix_max, case1) {
			istringstream in("1\n5\n2 1 4 5 3\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("25\n", ans);
		}

		TEST(prefix_max, case2) {
			istringstream in("1\n2\n5 1\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("10\n", ans);
		}

		TEST(prefix_max, case3) {
			istringstream in("1\n3\n3 2 1\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("9\n", ans);
		}

		TEST(prefix_max, case4) {
			istringstream in("1\n2\n6 7\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("14\n", ans);
		}
	}// namespace prefix_max

	namespace shifted_mex {
		TEST(shifted_mex, case1) {
			istringstream in("6\n1\n4\n5\n0 1 1 2 3\n2\n1 1\n4\n4 2 3 6\n5\n2 4 1 0 -1\n6\n-1 1 2 3 5 6\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1\n4\n1\n3\n4\n3\n", ans);
		}
	}// namespace shifted_mex

	namespace out_of_memory_error {
		TEST(out_of_memory_error, case1) {
			istringstream in("3\n3 4 5\n1 2 1\n1 4\n2 4\n3 3\n2 0\n5 3 1\n1 1 1 1 1\n1 1\n1 1\n2 1\n4 4 1\n1 0 0 0\n1 1\n4 4\n3 3\n4 4\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1 2 4 \n1 1 1 1 1 \n1 0 0 0 \n", ans);
		}
	}// namespace out_of_memory_error

	namespace the_robotic_rush {
		TEST(the_robotic_rush, case1) {
			istringstream in("3\n2 1 3\n0 1\n2\nLRR\n2 3 3\n2 4\n1 3 5\nLRL\n3 2 3\n1 3 7\n9 6\nRRL\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2 2 1 \n0 0 0 \n3 2 2 \n", ans);
		}
	}// namespace the_robotic_rush
}// namespace codeforces