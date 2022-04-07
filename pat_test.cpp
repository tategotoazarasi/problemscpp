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

		namespace b1023 {
			TEST(b1023, case1) {
				istringstream in("2 2 0 0 0 3 0 0 1 0");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("10015558", out.str());
			}
		}// namespace b1023

		namespace b1024 {
			TEST(b1024, case1) {
				istringstream in("+1.23400E-03");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("0.00123400", out.str());
			}

			TEST(b1024, case2) {
				istringstream in("-1.2E+10");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("-12000000000", out.str());
			}
		}// namespace b1024

		namespace b1025 {
			TEST(b1025, case1) {
				istringstream in("00100 6 4\n"
				                 "00000 4 99999\n"
				                 "00100 1 12309\n"
				                 "68237 6 -1\n"
				                 "33218 3 00000\n"
				                 "99999 5 68237\n"
				                 "12309 2 33218");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("00000 4 33218\n"
				          "33218 3 12309\n"
				          "12309 2 00100\n"
				          "00100 1 99999\n"
				          "99999 5 68237\n"
				          "68237 6 -1\n",
				          out.str());
			}
		}// namespace b1025

		namespace b1026 {
			TEST(b1026, case1) {
				istringstream in("123 4577973");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("12:42:59", out.str());
			}
		}// namespace b1026

		namespace b1027 {
			TEST(b1027, case1) {
				istringstream in("19 *");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("*****\n ***\n  *\n ***\n*****\n2", out.str());
			}
		}// namespace b1027

		namespace b1028 {
			TEST(b1028, case1) {
				istringstream in("5\nJohn 2001/05/12\nTom 1814/09/06\nAnn 2121/01/30\nJames 1814/09/05\nSteve 1967/11/20");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("3 Tom John", out.str());
			}
		}// namespace b1028

		namespace b1029 {
			TEST(b1029, case1) {
				istringstream in("7_This_is_a_test\n"
				                 "_hs_s_a_es");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("7TI", out.str());
			}
		}// namespace b1029

		namespace b1030 {
			TEST(b1030, case1) {
				istringstream in("10 8\n"
				                 "2 3 20 4 5 1 6 7 8 9");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("8", out.str());
			}
		}// namespace b1030

		namespace b1031 {
			TEST(b1032, case1) {
				istringstream in("4\n"
				                 "320124198808240056\n"
				                 "12010X198901011234\n"
				                 "110108196711301866\n"
				                 "37070419881216001X");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("12010X198901011234\n"
				          "110108196711301866\n"
				          "37070419881216001X\n",
				          out.str());
			}

			TEST(b1032, case2) {
				istringstream in("2\n"
				                 "320124198808240056\n"
				                 "110108196711301862");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("All passed",
				          out.str());
			}
		}// namespace b1031

		namespace b1032 {
			TEST(b1032, case1) {
				istringstream in("6\n"
				                 "3 65\n"
				                 "2 80\n"
				                 "1 100\n"
				                 "2 70\n"
				                 "3 40\n"
				                 "3 0");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("2 150", out.str());
			}
		}// namespace b1032

		namespace b1033 {
			TEST(b1033, case1) {
				istringstream in("7+IE.\n"
				                 "7_This_is_a_test.");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("_hs_s_a_tst", out.str());
			}
		}// namespace b1033

		namespace b1034 {
			TEST(b1034, case1) {
				istringstream in("2/3 -4/2");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("2/3 + (-2) = (-1 1/3)\n"
				          "2/3 - (-2) = 2 2/3\n"
				          "2/3 * (-2) = (-1 1/3)\n"
				          "2/3 / (-2) = (-1/3)",
				          out.str());
			}

			TEST(b1034, case2) {
				istringstream in("5/3 0/6");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("1 2/3 + 0 = 1 2/3\n"
				          "1 2/3 - 0 = 1 2/3\n"
				          "1 2/3 * 0 = 0\n"
				          "1 2/3 / 0 = Inf",
				          out.str());
			}
		}// namespace b1034

		namespace b1035 {
			TEST(b1035, case1) {
				istringstream in("10\n"
				                 "3 1 2 8 7 5 9 4 6 0\n"
				                 "1 2 3 7 8 5 9 4 6 0");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Insertion Sort\n"
				          "1 2 3 5 7 8 9 4 6 0",
				          out.str());
			}

			TEST(b1035, case2) {
				istringstream in("10\n"
				                 "3 1 2 8 7 5 9 4 0 6\n"
				                 "1 3 2 8 5 7 4 9 0 6");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Merge Sort\n"
				          "1 2 3 8 4 5 7 9 0 6",
				          out.str());
			}
		}// namespace b1035

		namespace b1036 {
			TEST(b1036, case1) {
				istringstream in("10 a");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("aaaaaaaaaa\n"
				          "a        a\n"
				          "a        a\n"
				          "a        a\n"
				          "aaaaaaaaaa",
				          out.str());
			}
		}// namespace b1036

		namespace b1037 {
			TEST(b1037, case1) {
				istringstream in("10.16.27 14.1.28");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("3.2.1", out.str());
			}

			TEST(b1037, case2) {
				istringstream in("14.1.28 10.16.27");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("-3.2.1", out.str());
			}
		}// namespace b1037

		namespace b1038 {
			TEST(b1038, case2) {
				istringstream in("10\n"
				                 "60 75 90 55 75 99 82 90 75 50\n"
				                 "3 75 90 88");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("3 2 0", out.str());
			}
		}// namespace b1038

		namespace b1039 {
			TEST(b1039, case1) {
				istringstream in("ppRYYGrrYBR2258\n"
				                 "YrR8RrY");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Yes 8", out.str());
			}

			TEST(b1039, case2) {
				istringstream in("ppRYYGrrYB225\n"
				                 "YrR8RrY");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("No 2", out.str());
			}
		}// namespace b1039

		namespace b1040 {
			TEST(b1040, case1) {
				istringstream in("APPAPT");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("2", out.str());
			}
		}// namespace b1040

		namespace b1041 {
			TEST(b1041, case1) {
				istringstream in("4\n"
				                 "3310120150912233 2 4\n"
				                 "3310120150912119 4 1\n"
				                 "3310120150912126 1 3\n"
				                 "3310120150912002 3 2\n"
				                 "2\n"
				                 "3 4");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("3310120150912002 2\n"
				          "3310120150912119 1\n",
				          out.str());
			}
		}// namespace b1041

		namespace b1042 {
			TEST(b1042, case1) {
				istringstream in("This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("e 7", out.str());
			}
		}// namespace b1042

		namespace b1043 {
			TEST(b1043, case1) {
				istringstream in("redlesPayBestPATTopTeePHPereatitAPPT");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("PATestPATestPTetPTePePee", out.str());
			}
		}// namespace b1043

		namespace b1044 {
			TEST(b1044, case1) {
				istringstream in("4\n"
				                 "29\n"
				                 "5\n"
				                 "elo nov\n"
				                 "tam");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("hel mar\n"
				          "may\n"
				          "115\n"
				          "13",
				          out.str());
			}

			TEST(b1044, case2) {
				istringstream in("1\n"
				                 "tret tret\n");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("0", out.str());
			}

			TEST(b1044, case3) {
				istringstream in("1\n"
				                 "0\n");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("tret", out.str());
			}
		}// namespace b1044

		namespace b1045 {
			TEST(b1045, case1) {
				istringstream in("5\n"
				                 "1 3 2 4 5");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("3\n"
				          "1 4 5",
				          out.str());
			}
		}// namespace b1045
	}    // namespace b

	namespace a {}

	namespace top {}
}// namespace pat
