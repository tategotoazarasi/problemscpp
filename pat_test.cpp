//
// Created by tategotoazarasi on 2022/3/14.
//
#include "pat.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;

namespace pat {
	namespace b {
		namespace b1001 {
			TEST(b1001, case1) {
				istringstream in("3");
				auto out = ostringstream();
				b1001::main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("5", ans);
			}
		}// namespace b1001
	}    // namespace b

	namespace a {

	}

	namespace top {

	}
}// namespace pat