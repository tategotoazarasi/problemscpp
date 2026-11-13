//
// Created by wangzhiheng on 10/11/2026.
//
#include "nowcoder.h"
#include "gtest/gtest.h"

namespace nowcoder {
	namespace hj1 {
		TEST(hj1, case1) {
			std::istringstream in("HelloNowcoder");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("13", ans);
		}

		TEST(hj1, case2) {
			std::istringstream in("ABSIB T");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1", ans);
		}
	}// namespace hj1

	namespace realhw235 {
		TEST(realhw235, case1) {
			std::istringstream in("100\n10\n5\n2\n5\n1 2 5 3 4");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("11", ans);
		}

		TEST(realhw235, case2) {
			std::istringstream in("50\n10\n10\n1\n10\n1 2 5 3 4 5 4 1 1 1");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("4", ans);
		}
	}// namespace realhw235

	namespace hj2 {
		TEST(hj2, case1) {
			std::istringstream in("HELLONowcoder123\no");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}

		TEST(hj2, case2) {
			std::istringstream in("H E L L O Nowcoder123\n1");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1", ans);
		}
	}// namespace hj2

	namespace realhw236 {
		TEST(realhw236, case1) {
			std::istringstream in("100\n3\n10001 1 100 90\n10002 2 100 100\n10003 3 100 110");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("110", ans);
		}

		TEST(realhw236, case2) {
			std::istringstream in("200\n4\n10001 1 200 200\n10002 2 10 10\n10003 3 10 10\n10004 3 10 10");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("230", ans);
		}
	}// namespace realhw236

	namespace hj3 {
		TEST(hj3, case1) {
			std::istringstream in("3 2 2 1");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1\n2\n", ans);
		}
	}// namespace hj3

	namespace realhw167 {
		TEST(realhw167, case1) {
			std::istringstream in("5\n1.0.1.0\n1.0.0.0 beta3\n1.0.0.1 beta1\n1.0.0.0 beta2\n1.0.0.1");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1.0.0.0 beta2\n1.0.0.0 beta3\n1.0.0.1 beta1\n1.0.0.1\n1.0.1.0\n", ans);
		}

		TEST(realhw167, case2) {
			std::istringstream in("100\n0.1000.0.1000 beta1\n1000.0.1000 beta985\n1000.0.1000.0 beta966\n1000.0.1000.0\n1000\n1000.1000 beta1000\n1000.1000.1000.1000 beta1\n0\n0.0.0.0 beta500\n1000.1000.1000 beta1000\n1000.0.1000.0\n1000.0.1000.0\n1000.0\n1000 beta923\n1000.0.1000 beta859\n1000.0\n1000.0.1000\n1000.0 beta24\n1000.0.1000.0 beta440\n1000.1000.1000 beta1\n1000.1000.1000.1000 beta1000\n1000.1000\n1000.0.1000.0\n1000.0.1000.0 beta712\n1000.0.1000.0\n1000.0\n0.0.0.0 beta1000\n0.1000.0.1000 beta1000\n0\n1000.0.1000.0 beta614\n0.0.0 beta1\n1000\n1000.0.1000\n1000.0.1000 beta593\n1000.1000.1000\n0 beta1\n0.0.0.0 beta1\n1000.0.1000.0 beta625\n1000\n1000.1000.1000.1000 beta500\n1000 beta1\n0.0\n1000.0.1000.0 beta297\n1000.1000 beta1\n0 beta1\n0.1000.0 beta1\n1000 beta790\n1000\n1000.0.1000 beta707\n1000.0 beta906\n1000.0.1000 beta854\n1000 beta1000\n0 beta1000\n1000 beta500\n1000 beta37\n0.0 beta1\n0.0 beta500\n0.1000\n1000.0.1000.0 beta977\n1000.0.1000.0 beta646\n1000.0.1000.0 beta114\n1000 beta542\n1000.0.1000 beta995\n0.1000.0.1000\n0.1000 beta1000\n1000.0\n0.1000.0\n1000\n0.0.0 beta500\n1000.0.1000\n1000.0\n1000.0.1000\n0.0.0\n1000.1000 beta500\n1000\n1000.0 beta149\n1000.0.1000 beta56\n1000.0.1000.0 beta572\n1000.0\n1000.0\n0.0.0 beta1000\n1000.0.1000.0 beta303\n1000.0.1000 beta605\n1000\n0.1000.0 beta1000\n1000.0.1000 beta844\n1000.0.1000.0 beta858\n1000.0.1000 beta524\n0 beta500\n1000 beta985\n1000.0.1000.0 beta822\n1000.1000.1000 beta500\n1000 beta808\n1000.1000.1000.1000\n1000 beta607\n1000.0\n0.0.0.0\n0.0 beta1000\n0 beta1000\n0.1000 beta1");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("0 beta1\n0 beta1\n0 beta500\n0 beta1000\n0 beta1000\n0\n0\n0.0 beta1\n0.0 beta500\n0.0 beta1000\n0.0\n0.0.0 beta1\n0.0.0 beta500\n0.0.0 beta1000\n0.0.0\n0.0.0.0 beta1\n0.0.0.0 beta500\n0.0.0.0 beta1000\n0.0.0.0\n0.1000 beta1\n0.1000 beta1000\n0.1000\n0.1000.0 beta1\n0.1000.0 beta1000\n0.1000.0\n0.1000.0.1000 beta1\n0.1000.0.1000 beta1000\n0.1000.0.1000\n1000 beta1\n1000 beta37\n1000 beta500\n1000 beta542\n1000 beta607\n1000 beta790\n1000 beta808\n1000 beta923\n1000 beta985\n1000 beta1000\n1000\n1000\n1000\n1000\n1000\n1000\n1000\n1000.0 beta24\n1000.0 beta149\n1000.0 beta906\n1000.0\n1000.0\n1000.0\n1000.0\n1000.0\n1000.0\n1000.0\n1000.0\n1000.0.1000 beta56\n1000.0.1000 beta524\n1000.0.1000 beta593\n1000.0.1000 beta605\n1000.0.1000 beta707\n1000.0.1000 beta844\n1000.0.1000 beta854\n1000.0.1000 beta859\n1000.0.1000 beta985\n1000.0.1000 beta995\n1000.0.1000\n1000.0.1000\n1000.0.1000\n1000.0.1000\n1000.0.1000.0 beta114\n1000.0.1000.0 beta297\n1000.0.1000.0 beta303\n1000.0.1000.0 beta440\n1000.0.1000.0 beta572\n1000.0.1000.0 beta614\n1000.0.1000.0 beta625\n1000.0.1000.0 beta646\n1000.0.1000.0 beta712\n1000.0.1000.0 beta822\n1000.0.1000.0 beta858\n1000.0.1000.0 beta966\n1000.0.1000.0 beta977\n1000.0.1000.0\n1000.0.1000.0\n1000.0.1000.0\n1000.0.1000.0\n1000.0.1000.0\n1000.1000 beta1\n1000.1000 beta500\n1000.1000 beta1000\n1000.1000\n1000.1000.1000 beta1\n1000.1000.1000 beta500\n1000.1000.1000 beta1000\n1000.1000.1000\n1000.1000.1000.1000 beta1\n1000.1000.1000.1000 beta500\n1000.1000.1000.1000 beta1000\n1000.1000.1000.1000\n", ans);
		}
	}// namespace realhw167

	namespace hj4 {
		TEST(hj4, case1) {
			std::istringstream in("hellonowcoder");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("hellonow\ncoder000\n", ans);
		}

		TEST(hj4, case2) {
			std::istringstream in("0");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("00000000\n", ans);
		}
	}// namespace hj4

	namespace realhw168 {
		TEST(realhw168, case1) {
			std::istringstream in("5 3\n0 1 10\n1 2 20\n3 4 40\n3\n0 2\n0 3\n3 4");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("30\n0\n40\n", ans);
		}

		TEST(realhw168, case2) {
			std::istringstream in("8 62\n0 1 56\n6 4 1\n0 0 67\n3 3 88\n2 1 11\n2 7 38\n1 7 86\n7 6 55\n6 2 93\n1 0 11\n2 7 99\n0 4 75\n1 2 76\n5 2 65\n4 5 14\n4 7 81\n2 3 29\n5 5 4\n7 5 83\n6 1 60\n3 1 85\n0 3 60\n2 0 79\n3 6 71\n0 3 6\n4 0 19\n4 4 4\n4 4 65\n5 2 87\n5 2 69\n1 3 34\n2 5 20\n2 5 91\n4 1 67\n5 5 92\n2 5 4\n3 0 12\n0 3 21\n4 6 19\n4 2 60\n3 3 86\n3 5 47\n5 2 16\n4 1 100\n6 3 65\n1 4 29\n4 4 78\n1 3 87\n5 3 9\n0 7 93\n1 1 16\n1 3 65\n1 5 24\n0 7 23\n6 2 29\n5 7 54\n7 0 90\n6 7 32\n1 7 86\n0 5 67\n1 5 53\n1 4 65\n1\n4 1");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("29\n", ans);
		}

		TEST(realhw168, case3) {
			std::istringstream in("8 35\n3 0 94\n4 2 59\n0 0 35\n4 5 75\n1 5 6\n4 0 94\n2 5 3\n2 5 76\n2 0 73\n1 2 44\n0 6 68\n4 6 4\n2 1 83\n3 5 95\n6 2 65\n5 2 97\n4 7 9\n3 3 72\n7 4 59\n6 5 92\n3 4 75\n0 5 61\n7 6 64\n4 2 23\n6 7 68\n0 4 94\n0 6 9\n1 7 27\n0 0 70\n3 2 53\n6 6 82\n7 4 45\n7 4 5\n3 4 48\n6 4 93\n7\n3 6\n1 7\n5 6\n3 3\n7 7\n4 4\n2 1");
			auto out = std::ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("52\n27\n30\n0\n0\n0\n9\n", ans);
		}
	}// namespace realhw168
};// namespace nowcoder