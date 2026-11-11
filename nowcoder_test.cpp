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
};// namespace nowcoder