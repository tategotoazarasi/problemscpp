#include "pat.h"
#include "gtest/gtest.h"

using namespace std;

namespace pat {
	namespace b {
		namespace b1001 {
			TEST(b1001, case1) {
				istringstream in("3");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("5", ans);
			}
		}// namespace b1001

		namespace b1002 {
			TEST(b1002, case1) {
				istringstream in("1234567890987654321123456789");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("yi san wu", ans);
			}
		}// namespace b1002

		namespace b1003 {
			TEST(b1003, case1) {
				istringstream in("10\n"
				                 "PAT\n"
				                 "PAAT\n"
				                 "AAPATAA\n"
				                 "AAPAATAAAA\n"
				                 "xPATx\n"
				                 "PT\n"
				                 "Whatever\n"
				                 "APAAATAA\n"
				                 "APT\n"
				                 "APATTAA");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("YES\n"
				          "YES\n"
				          "YES\n"
				          "YES\n"
				          "NO\n"
				          "NO\n"
				          "NO\n"
				          "NO\n"
				          "NO\n"
				          "NO\n",
				          ans);
			}
		}// namespace b1003

		namespace b1004 {
			TEST(b1004, case1) {
				istringstream in("3\n"
				                 "Joe Math990112 89\n"
				                 "Mike CS991301 100\n"
				                 "Mary EE990830 95");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Mike CS991301\n"
				          "Joe Math990112",
				          ans);
			}
		}// namespace b1004

		namespace b1005 {
			TEST(b1005, case1) {
				istringstream in("6\n"
				                 "3 5 6 7 8 11");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("7 6", ans);
			}
		}// namespace b1005

		namespace b1006 {
			TEST(b1006, case1) {
				istringstream in("234");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("BBSSS1234", ans);
			}

			TEST(b1006, case2) {
				istringstream in("23");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("SS123", ans);
			}
		}// namespace b1006

		namespace b1007 {
			TEST(b1007, case1) {
				istringstream in("20");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("4", ans);
			}
		}// namespace b1007

		namespace b1008 {
			TEST(b1008, case1) {
				istringstream in("6 2\n"
				                 "1 2 3 4 5 6");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("5 6 1 2 3 4", ans);
			}
		}// namespace b1008

		namespace b1009 {
			TEST(b1009, case1) {
				istringstream in("Hello World Here I Come");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Come I Here World Hello", ans);
			}
		}// namespace b1009

		namespace b1010 {
			TEST(b1010, case1) {
				istringstream in("3 4 -5 2 6 1 -2 0");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("12 3 -10 1 6 0", ans);
			}
		}// namespace b1010

		namespace b1011 {
			TEST(b1011, case1) {
				istringstream in("4\n"
				                 "1 2 3\n"
				                 "2 3 4\n"
				                 "2147483647 0 2147483646\n"
				                 "0 -2147483648 -2147483647");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Case #1: false\n"
				          "Case #2: true\n"
				          "Case #3: true\n"
				          "Case #4: false\n",
				          ans);
			}
		}// namespace b1011

		namespace b1012 {
			TEST(b1012, case1) {
				istringstream in("13 1 2 3 4 5 6 7 8 9 10 20 16 18");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("30 11 2 9.7 9", ans);
			}

			TEST(b1012, case2) {
				istringstream in("8 1 2 4 5 6 7 9 16");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("N 11 2 N 9", ans);
			}
		}// namespace b1012

		namespace b1013 {
			TEST(b1013, case1) {
				istringstream in("5 27");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("11 13 17 19 23 29 31 37 41 43\n"
				          "47 53 59 61 67 71 73 79 83 89\n"
				          "97 101 103",
				          ans);
			}
		}// namespace b1013

		namespace b1014 {
			TEST(b1014, case1) {
				istringstream in("3485djDkxh4hhGE \n"
				                 "2984akDfkkkkggEdsb \n"
				                 "s&hgsfdk \n"
				                 "d&Hyscvnm");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("THU 14:04", ans);
			}
		}// namespace b1014

		namespace b1015 {
			TEST(b1015, case1) {
				istringstream in("14 60 80\n"
				                 "10000001 64 90\n"
				                 "10000002 90 60\n"
				                 "10000011 85 80\n"
				                 "10000003 85 80\n"
				                 "10000004 80 85\n"
				                 "10000005 82 77\n"
				                 "10000006 83 76\n"
				                 "10000007 90 78\n"
				                 "10000008 75 79\n"
				                 "10000009 59 90\n"
				                 "10000010 88 45\n"
				                 "10000012 80 100\n"
				                 "10000013 90 99\n"
				                 "10000014 66 60");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("12\n"
				          "10000013 90 99\n"
				          "10000012 80 100\n"
				          "10000003 85 80\n"
				          "10000011 85 80\n"
				          "10000004 80 85\n"
				          "10000007 90 78\n"
				          "10000006 83 76\n"
				          "10000005 82 77\n"
				          "10000002 90 60\n"
				          "10000014 66 60\n"
				          "10000008 75 79\n"
				          "10000001 64 90\n",
				          ans);
			}
		}// namespace b1015

		namespace b1016 {
			TEST(b1016, case1) {
				istringstream in("3862767 6 13530293 3");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("399", ans);
			}

			TEST(b1016, case2) {
				istringstream in("3862767 1 13530293 8");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("0", ans);
			}
		}// namespace b1016

		namespace b1018 {
			TEST(b1018, case1) {
				istringstream in("10\n"
				                 "C J\n"
				                 "J B\n"
				                 "C B\n"
				                 "B B\n"
				                 "B C\n"
				                 "C C\n"
				                 "C B\n"
				                 "J B\n"
				                 "B C\n"
				                 "J J");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("5 3 2\n"
				          "2 3 5\n"
				          "B B",
				          ans);
			}
		}// namespace b1018

		namespace b1019 {
			TEST(b1019, case1) {
				istringstream in("6767");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("7766 - 6677 = 1089\n9810 - 0189 = 9621\n9621 - 1269 = 8352\n8532 - 2358 = 6174\n", ans);
			}

			TEST(b1019, case2) {
				istringstream in("2222");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("2222 - 2222 = 0000\n", out.str());
			}
		}// namespace b1019

		namespace b1020 {
			TEST(b1020, case1) {
				istringstream in("3 20\n18 15 10\n75 72 45\n");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("94.50", out.str());
			}
		}// namespace b1020

		namespace b1021 {
			TEST(b1021, case1) {
				istringstream in("100311");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("0:2\n"
				          "1:3\n"
				          "3:1\n",
				          out.str());
			}
		}// namespace b1021

		namespace b1022 {
			TEST(b1022, case1) {
				istringstream in("123 456 8");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("1103", out.str());
			}

			TEST(b1022, case2) {
				istringstream in("20 30 10");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("50", out.str());
			}
		}// namespace b1022
	}    // namespace b

	namespace a {}

	namespace top {}
}// namespace pat
