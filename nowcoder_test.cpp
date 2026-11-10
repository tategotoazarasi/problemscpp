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
};// namespace nowcoder