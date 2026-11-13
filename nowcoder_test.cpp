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
};// namespace nowcoder