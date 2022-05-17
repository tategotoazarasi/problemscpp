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
				          "1 4 5\n",
				          out.str());
			}
		}// namespace b1045

		namespace b1046 {
			TEST(b1046, case1) {
				istringstream in("5\n"
				                 "8 10 9 12\n"
				                 "5 10 5 10\n"
				                 "3 8 5 12\n"
				                 "12 18 1 13\n"
				                 "4 16 12 15");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("1 2", out.str());
			}
		}// namespace b1046

		namespace b1047 {
			TEST(b1047, case1) {
				istringstream in("6\n"
				                 "3-10 99\n"
				                 "11-5 87\n"
				                 "102-1 0\n"
				                 "102-3 100\n"
				                 "11-9 89\n"
				                 "3-2 61");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("11 176", out.str());
			}
		}// namespace b1047

		namespace b1048 {
			TEST(b1048, case1) {
				istringstream in("1234567 368782971");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("3695Q8118", out.str());
			}
		}// namespace b1048

		namespace b1049 {
			TEST(b1049, case1) {
				istringstream in("4\n0.1 0.2 0.3 0.4\n");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("5.00", out.str());
			}
		}// namespace b1049

		namespace b1050 {
			TEST(b1050, case1) {
				istringstream in("12\n37 76 20 98 76 42 53 95 60 81 58 93\n");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("98 95 93\n42 37 81\n53 20 76\n58 60 76", out.str());
			}
		}// namespace b1050

		namespace b1051 {
			TEST(b1051, case1) {
				istringstream in("2.3 3.5 5.2 0.4");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("-8.68-8.23i", out.str());
			}
		}// namespace b1051

		namespace b1052 {
			TEST(b1052, case1) {
				istringstream in("[�r][�q][o][~\\][/~]  [<][>]\n [�s][�t][^][-][=][>][<][@][��]\n[��][��][_][��][^]  ...\n4\n1 1 2 2 2\n6 8 1 5 5\n3 3 4 3 3\n2 10 3 9 3\n");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("�r(�s���t)�q\n<(@��=)/~\no(^��^)o\nAre you kidding me? @\\/@\n", out.str());
			}
		}// namespace b1052

		namespace b1053 {
			TEST(b1053, case1) {
				istringstream in("5 0.5 10\n"
				                 "6 0.3 0.4 0.5 0.2 0.8 0.6\n"
				                 "10 0.0 0.1 0.2 0.3 0.0 0.8 0.6 0.7 0.0 0.5\n"
				                 "5 0.4 0.3 0.5 0.1 0.7\n"
				                 "11 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1\n"
				                 "11 2 2 2 1 1 0.1 1 0.1 0.1 0.1 0.1");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("40.0% 20.0%", out.str());
			}
		}// namespace b1053

		namespace b1054 {
			TEST(b1054, case1) {
				istringstream in("7\n"
				                 "5 -3.2 aaa 9999 2.3.4 7.123 2.35");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("ERROR: aaa is not a legal number\n"
				          "ERROR: 9999 is not a legal number\n"
				          "ERROR: 2.3.4 is not a legal number\n"
				          "ERROR: 7.123 is not a legal number\n"
				          "The average of 3 numbers is 1.38\n",
				          out.str());
			}

			TEST(b1054, case2) {
				istringstream in("2\n"
				                 "aaa -9999");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("ERROR: aaa is not a legal number\n"
				          "ERROR: -9999 is not a legal number\n"
				          "The average of 0 numbers is Undefined\n",
				          out.str());
			}
		}// namespace b1054

		namespace b1055 {
			TEST(b1055, case1) {
				istringstream in("10 3\n"
				                 "Tom 188\n"
				                 "Mike 170\n"
				                 "Eva 168\n"
				                 "Tim 160\n"
				                 "Joe 190\n"
				                 "Ann 168\n"
				                 "Bob 175\n"
				                 "Nick 186\n"
				                 "Amy 160\n"
				                 "John 159");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Bob Tom Joe Nick\n"
				          "Ann Mike Eva\n"
				          "Tim Amy John",
				          out.str());
			}
		}// namespace b1055

		namespace b1056 {
			TEST(b1056, case1) {
				istringstream in("3 2 8 5");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("330", out.str());
			}
		}// namespace b1056

		namespace b1057 {
			TEST(b1057, case1) {
				istringstream in("PAT (Basic)");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("3 4", out.str());
			}
		}// namespace b1057

		namespace b1058 {
			TEST(b1058, case1) {
				istringstream in("3 4 \n"
				                 "3 4 2 a c\n"
				                 "2 5 1 b\n"
				                 "5 3 2 b c\n"
				                 "1 5 4 a b d e\n"
				                 "(2 a c) (2 b d) (2 a c) (3 a b e)\n"
				                 "(2 a c) (1 b) (2 a b) (4 a b d e)\n"
				                 "(2 b d) (1 e) (2 b c) (4 a b c d)");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("3\n"
				          "6\n"
				          "5\n"
				          "2 2 3 4",
				          out.str());
			}
		}// namespace b1058

		namespace b1059 {
			TEST(b1059, case1) {
				istringstream in("6\n"
				                 "1111\n"
				                 "6666\n"
				                 "8888\n"
				                 "1234\n"
				                 "5555\n"
				                 "0001\n"
				                 "6\n"
				                 "8888\n"
				                 "0001\n"
				                 "1111\n"
				                 "2222\n"
				                 "8888\n"
				                 "2222");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("8888: Minion\n"
				          "0001: Chocolate\n"
				          "1111: Mystery Award\n"
				          "2222: Are you kidding?\n"
				          "8888: Checked\n"
				          "2222: Are you kidding?\n",
				          out.str());
			}
		}// namespace b1059

		namespace b1060 {
			TEST(b1060, case1) {
				istringstream in("10\n"
				                 "6 7 6 9 3 10 8 2 7 8");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("6", out.str());
			}
		}// namespace b1060

		namespace b1061 {
			TEST(b1061, case1) {
				istringstream in("3 6\n"
				                 "2 1 3 3 4 5\n"
				                 "0 0 1 0 1 1\n"
				                 "0 1 1 0 0 1\n"
				                 "1 0 1 0 1 0\n"
				                 "1 1 0 0 1 1");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("13\n"
				          "11\n"
				          "12\n",
				          out.str());
			}
		}// namespace b1061

		namespace b1062 {
			TEST(b1062, case1) {
				istringstream in("7/18 13/20 12");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("5/12 7/12", out.str());
			}

			TEST(b1062, case2) {
				istringstream in("26/5 7/20 13");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("5/13 6/13 7/13 8/13 9/13 10/13 11/13 12/13 14/13 15/13 16/13 17/13 18/13 19/13 20/13 21/13 22/13 23/13 24/13 25/13 27/13 28/13 29/13 30/13 31/13 32/13 33/13 34/13 35/13 36/13 37/13 38/13 40/13 41/13 42/13 43/13 44/13 45/13 46/13 47/13 48/13 49/13 50/13 51/13 53/13 54/13 55/13 56/13 57/13 58/13 59/13 60/13 61/13 62/13 63/13 64/13 66/13 67/13", out.str());
			}
		}// namespace b1062

		namespace b1063 {
			TEST(b1063, case1) {
				istringstream in("5\n"
				                 "0 1\n"
				                 "2 0\n"
				                 "-1 0\n"
				                 "3 3\n"
				                 "0 -3");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("4.24", out.str());
			}
		}// namespace b1063

		namespace b1064 {
			TEST(b1064, case1) {
				istringstream in("8\n"
				                 "123 899 51 998 27 33 36 12");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("4\n"
				          "3 6 9 26",
				          out.str());
			}
		}// namespace b1064

		namespace b1066 {
			TEST(b1066, case1) {
				istringstream in("3 5 100 150 0\n"
				                 "3 189 254 101 119\n"
				                 "150 233 151 99 100\n"
				                 "88 123 149 0 255");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("003 189 254 000 000\n"
				          "000 233 151 099 000\n"
				          "088 000 000 000 255",
				          out.str());
			}
		}// namespace b1066

		namespace b1067 {
			TEST(b1067, case1) {
				istringstream in("Correct%pw 3\n"
				                 "correct%pw\n"
				                 "Correct@PW\n"
				                 "whatisthepassword!\n"
				                 "Correct%pw\n"
				                 "#");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Wrong password: correct%pw\n"
				          "Wrong password: Correct@PW\n"
				          "Wrong password: whatisthepassword!\n"
				          "Account locked",
				          out.str());
			}

			TEST(b1067, case2) {
				istringstream in("cool@gplt 3\n"
				                 "coolman@gplt\n"
				                 "coollady@gplt\n"
				                 "cool@gplt\n"
				                 "try again\n"
				                 "#");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Wrong password: coolman@gplt\n"
				          "Wrong password: coollady@gplt\n"
				          "Welcome in",
				          out.str());
			}
		}// namespace b1067

		namespace b1068 {
			TEST(b1068, case1) {
				istringstream in("8 6 200\n"
				                 "0 \t 0 \t  0 \t   0\t    0 \t     0 \t      0        0\n"
				                 "65280 \t 65280    65280    16711479 65280    65280    65280    65280\n"
				                 "16711479 65280    65280    65280    16711680 65280    65280    65280\n"
				                 "65280 \t 65280    65280    65280    65280    65280    165280   165280\n"
				                 "65280 \t 65280 \t  16777015 65280    65280    165280   65480    165280\n"
				                 "16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("(5, 3): 16711680", out.str());
			}

			TEST(b1068, case2) {
				istringstream in("4 5 2\n"
				                 "0 0 0 0\n"
				                 "0 0 3 0\n"
				                 "0 0 0 0\n"
				                 "0 5 0 0\n"
				                 "0 0 0 0");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Not Unique", out.str());
			}

			TEST(b1068, case3) {
				istringstream in("3 3 5\n"
				                 "1 2 3\n"
				                 "3 4 5\n"
				                 "5 6 7");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Not Exist", out.str());
			}
		}// namespace b1068

		namespace b1069 {
			TEST(b1069, case1) {
				istringstream in("9 3 2\n"
				                 "Imgonnawin!\n"
				                 "PickMe\n"
				                 "PickMe\n"
				                 "LookHere\n"
				                 "Imgonnawin!\n"
				                 "TryAgainAgain\n"
				                 "TryAgainAgain\n"
				                 "Imgonnawin!\n"
				                 "TryAgainAgain");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("PickMe\n"
				          "Imgonnawin!\n"
				          "TryAgainAgain\n",
				          out.str());
			}

			TEST(b1069, case2) {
				istringstream in("2 3 5\n"
				                 "Imgonnawin!\n"
				                 "PickMe\n");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Keep going...", out.str());
			}
		}// namespace b1069

		namespace b1070 {
			TEST(b1070, case1) {
				istringstream in("8\n"
				                 "10 15 12 3 4 13 1 15");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("14", out.str());
			}
		}// namespace b1070

		namespace b1071 {
			TEST(b1071, case1) {
				istringstream in("100 4\n"
				                 "8 0 100 2\n"
				                 "3 1 50 1\n"
				                 "5 1 200 6\n"
				                 "7 0 200 8");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Win 100!  Total = 200.\n"
				          "Lose 50.  Total = 150.\n"
				          "Not enough tokens.  Total = 150.\n"
				          "Not enough tokens.  Total = 150.\n",
				          out.str());
			}

			TEST(b1071, case2) {
				istringstream in("100 4\n"
				                 "8 0 100 2\n"
				                 "3 1 200 1\n"
				                 "5 1 200 6\n"
				                 "7 0 200 8");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Win 100!  Total = 200.\n"
				          "Lose 200.  Total = 0.\n"
				          "Game Over.",
				          out.str());
			}
		}// namespace b1071

		namespace b1072 {
			TEST(b1071, case1) {
				istringstream in("4 2\n"
				                 "2333 6666\n"
				                 "CYLL 3 1234 2345 3456\n"
				                 "U 4 9966 6666 8888 6666\n"
				                 "GG 2 2333 7777\n"
				                 "JJ 3 0012 6666 2333");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("U: 6666 6666\n"
				          "GG: 2333\n"
				          "JJ: 6666 2333\n"
				          "3 5",
				          out.str());
			}
		}// namespace b1072

		namespace b1073 {
			TEST(b1073, case1) {
				istringstream in("3 4 \n"
				                 "3 4 2 a c\n"
				                 "2 5 1 b\n"
				                 "5 3 2 b c\n"
				                 "1 5 4 a b d e\n"
				                 "(2 a c) (3 b d e) (2 a c) (3 a b e)\n"
				                 "(2 a c) (1 b) (2 a b) (4 a b d e)\n"
				                 "(2 b d) (1 e) (1 c) (4 a b c d)");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("3.5\n"
				          "6.0\n"
				          "2.5\n"
				          "2 2-e\n"
				          "2 3-a\n"
				          "2 3-b\n",
				          out.str());
			}

			TEST(b1073, case2) {
				istringstream in("2 2 \n"
				                 "3 4 2 a c\n"
				                 "2 5 1 b\n"
				                 "(2 a c) (1 b)\n"
				                 "(2 a c) (1 b)");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("5.0\n"
				          "5.0\n"
				          "Too simple",
				          out.str());
			}
		}// namespace b1073

		namespace b1074 {
			TEST(b1074, case1) {
				istringstream in("30527\n"
				                 "06203\n"
				                 "415");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("7201", out.str());
			}
		}// namespace b1074

		namespace b1075 {
			TEST(b1075, case1) {
				istringstream in("00100 9 10\n"
				                 "23333 10 27777\n"
				                 "00000 0 99999\n"
				                 "00100 18 12309\n"
				                 "68237 -6 23333\n"
				                 "33218 -4 00000\n"
				                 "48652 -2 -1\n"
				                 "99999 5 68237\n"
				                 "27777 11 48652\n"
				                 "12309 7 33218");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("33218 -4 68237\n"
				          "68237 -6 48652\n"
				          "48652 -2 12309\n"
				          "12309 7 00000\n"
				          "00000 0 99999\n"
				          "99999 5 23333\n"
				          "23333 10 00100\n"
				          "00100 18 27777\n"
				          "27777 11 -1\n",
				          out.str());
			}
		}// namespace b1075

		namespace b1076 {
			TEST(b1076, case1) {
				istringstream in("8\n"
				                 "A-T B-F C-F D-F\n"
				                 "C-T B-F A-F D-F\n"
				                 "A-F D-F C-F B-T\n"
				                 "B-T A-F C-F D-F\n"
				                 "B-F D-T A-F C-F\n"
				                 "A-T C-F B-F D-F\n"
				                 "D-T B-F C-F A-F\n"
				                 "C-T A-F B-F D-F");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("13224143", out.str());
			}
		}// namespace b1076

		namespace b1078 {
			TEST(b1078, case1) {
				istringstream in("C\n"
				                 "TTTTThhiiiis isssss a   tesssst CAaaa as");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("5T2h4is i5s a3 te4st CA3a as", out.str());
			}

			TEST(b1078, case2) {
				istringstream in("D\n"
				                 "5T2h4is i5s a3 te4st CA3a as10Z");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ", out.str());
			}
		}// namespace b1078

		namespace b1077 {
			TEST(b1077, case1) {
				istringstream in("6 50\n"
				                 "42 49 49 35 38 41\n"
				                 "36 51 50 28 -1 30\n"
				                 "40 36 41 33 47 49\n"
				                 "30 250 -25 27 45 31\n"
				                 "48 0 0 50 50 1234\n"
				                 "43 41 36 29 42 29");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("42\n"
				          "33\n"
				          "41\n"
				          "31\n"
				          "37\n"
				          "39\n",
				          out.str());
			}
		}// namespace b1077

		namespace b1079 {
			TEST(b1079, case1) {
				istringstream in("97152");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("97152 + 25179 = 122331\n"
				          "122331 + 133221 = 255552\n"
				          "255552 is a palindromic number.",
				          out.str());
			}

			TEST(b1079, case2) {
				istringstream in("196");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("196 + 691 = 887\n"
				          "887 + 788 = 1675\n"
				          "1675 + 5761 = 7436\n"
				          "7436 + 6347 = 13783\n"
				          "13783 + 38731 = 52514\n"
				          "52514 + 41525 = 94039\n"
				          "94039 + 93049 = 187088\n"
				          "187088 + 880781 = 1067869\n"
				          "1067869 + 9687601 = 10755470\n"
				          "10755470 + 07455701 = 18211171\n"
				          "Not found in 10 iterations.",
				          out.str());
			}

			TEST(is_palindromic, case1) {
				ASSERT_TRUE(is_palindromic("12321"));
			}

			TEST(is_palindromic, case2) {
				ASSERT_TRUE(is_palindromic("123321"));
			}

			TEST(is_palindromic, case3) {
				ASSERT_FALSE(is_palindromic("1233210"));
			}

			TEST(is_palindromic, case4) {
				ASSERT_FALSE(is_palindromic("123421"));
			}
		}// namespace b1079

		namespace b1080 {
			TEST(b1080, case1) {
				istringstream in("6 6 7\n"
				                 "01234 880\n"
				                 "a1903 199\n"
				                 "ydjh2 200\n"
				                 "wehu8 300\n"
				                 "dx86w 220\n"
				                 "missing 400\n"
				                 "ydhfu77 99\n"
				                 "wehu8 55\n"
				                 "ydjh2 98\n"
				                 "dx86w 88\n"
				                 "a1903 86\n"
				                 "01234 39\n"
				                 "ydhfu77 88\n"
				                 "a1903 66\n"
				                 "01234 58\n"
				                 "wehu8 84\n"
				                 "ydjh2 82\n"
				                 "missing 99\n"
				                 "dx86w 81");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("missing 400 -1 99 99\n"
				          "ydjh2 200 98 82 88\n"
				          "dx86w 220 88 81 84\n"
				          "wehu8 300 55 84 84\n",
				          out.str());
			}
		}// namespace b1080

		namespace b1081 {
			TEST(b1081, case1) {
				istringstream in("5\n"
				                 "123s\n"
				                 "zheshi.wodepw\n"
				                 "1234.5678\n"
				                 "WanMei23333\n"
				                 "pass*word.6");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Your password is tai duan le.\n"
				          "Your password needs shu zi.\n"
				          "Your password needs zi mu.\n"
				          "Your password is wan mei.\n"
				          "Your password is tai luan le.\n",
				          out.str());
			}
		}// namespace b1081

		namespace b1082 {
			TEST(b1082, case1) {
				istringstream in("3\n"
				                 "0001 5 7\n"
				                 "1020 -1 3\n"
				                 "0233 0 -1");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("0233 0001", out.str());
			}
		}// namespace b1082

		namespace b1083 {
			TEST(b1083, case1) {
				istringstream in("8\n"
				                 "3 5 8 6 2 1 4 7");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("5 2\n"
				          "3 3\n"
				          "2 2\n",
				          out.str());
			}
		}// namespace b1083

		namespace b1084 {
			TEST(b1084, case1) {
				istringstream in("1 8");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("1123123111", out.str());
			}
		}// namespace b1084

		namespace b1085 {
			TEST(b1085, case1) {
				istringstream in("10\n"
				                 "A57908 85 Au\n"
				                 "B57908 54 LanX\n"
				                 "A37487 60 au\n"
				                 "T28374 67 CMU\n"
				                 "T32486 24 hypu\n"
				                 "A66734 92 cmu\n"
				                 "B76378 71 AU\n"
				                 "A47780 45 lanx\n"
				                 "A72809 100 pku\n"
				                 "A03274 45 hypu");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("5\n"
				          "1 cmu 192 2\n"
				          "1 au 192 3\n"
				          "3 pku 100 1\n"
				          "4 hypu 81 2\n"
				          "4 lanx 81 2\n",
				          out.str());
			}
		}// namespace b1085

		namespace b1086 {
			TEST(b1086, case1) {
				istringstream in("5 7");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("53", out.str());
			}
		}// namespace b1086

		namespace b1087 {
			TEST(b1087, case1) {
				istringstream in("2017");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("1480", out.str());
			}
		}// namespace b1087

		namespace b1088 {
			TEST(b1088, case1) {
				istringstream in("48 3 7");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("48 Ping Cong Gai", out.str());
			}

			TEST(b1088, case2) {
				istringstream in("48 11 6");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("No Solution", out.str());
			}
		}// namespace b1088

		namespace b1089 {
			TEST(b1089, case1) {
				istringstream in("5\n"
				                 "-2\n"
				                 "+3\n"
				                 "-4\n"
				                 "+5\n"
				                 "+4");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("1 4", out.str());
			}

			TEST(b1089, case2) {
				istringstream in("6\n"
				                 "+6\n"
				                 "+3\n"
				                 "+1\n"
				                 "-5\n"
				                 "-2\n"
				                 "+4");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("1 5", out.str());
			}

			TEST(b1089, case3) {
				istringstream in("5\n"
				                 "-2\n"
				                 "-3\n"
				                 "-4\n"
				                 "-5\n"
				                 "-1");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("No Solution", out.str());
			}
		}// namespace b1089

		namespace b1090 {
			TEST(b1089, case1) {
				istringstream in("6 3\n"
				                 "20001 20002\n"
				                 "20003 20004\n"
				                 "20005 20006\n"
				                 "20003 20001\n"
				                 "20005 20004\n"
				                 "20004 20006\n"
				                 "4 00001 20004 00002 20003\n"
				                 "5 98823 20002 20003 20006 10010\n"
				                 "3 12345 67890 23333");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("No\n"
				          "Yes\n"
				          "Yes\n",
				          out.str());
			}
		}// namespace b1090

		namespace b1091 {
			TEST(b1091, case3) {
				istringstream in("3\n"
				                 "92 5 233");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("3 25392\n"
				          "1 25\n"
				          "No\n",
				          out.str());
			}
		}// namespace b1091

		namespace b1092 {
			TEST(b1092, case1) {
				istringstream in("5 3\n"
				                 "1001 992 0 233 6\n"
				                 "8 0 2018 0 2008\n"
				                 "36 18 0 1024 4");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("2018\n"
				          "3 5",
				          out.str());
			}
		}// namespace b1092

		namespace b1094 {
			TEST(b1094, case1) {
				istringstream in("20 5\n"
				                 "23654987725541023819");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("49877", out.str());
			}

			TEST(b1094, case2) {
				istringstream in("10 3\n"
				                 "2468001680");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("404", out.str());
			}
		}// namespace b1094

		namespace b1095 {
			TEST(b1095, case1) {
				istringstream in("8 4\n"
				                 "B123180908127 99\n"
				                 "B102180908003 86\n"
				                 "A112180318002 98\n"
				                 "T107150310127 62\n"
				                 "A107180908108 100\n"
				                 "T123180908010 78\n"
				                 "B112160918035 88\n"
				                 "A107180908021 98\n"
				                 "1 A\n"
				                 "2 107\n"
				                 "3 180908\n"
				                 "2 999");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Case 1: 1 A\n"
				          "A107180908108 100\n"
				          "A107180908021 98\n"
				          "A112180318002 98\n"
				          "Case 2: 2 107\n"
				          "3 260\n"
				          "Case 3: 3 180908\n"
				          "107 2\n"
				          "123 2\n"
				          "102 1\n"
				          "Case 4: 2 999\n"
				          "NA\n",
				          out.str());
			}
		}// namespace b1095

		namespace b1096 {
			TEST(b1096, case1) {
				istringstream in("3\n"
				                 "18 29 40");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Yes\n"
				          "No\n"
				          "Yes\n",
				          out.str());
			}
		}// namespace b1096

		namespace b1097 {
			TEST(b1097, case1) {
				istringstream in("7 2 99\n"
				                 "11 87 23 67 20 75 89\n"
				                 "37 94 27 91 63 50 11\n"
				                 "44 38 50 26 40 26 24\n"
				                 "73 85 63 28 62 18 68\n"
				                 "15 83 27 97 88 25 43\n"
				                 "23 78 98 20 30 81 99\n"
				                 "77 36 48 59 25 34 22");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("529 481 479 263 417 342 343", out.str());
			}
		}// namespace b1097

		namespace b1098 {
			TEST(b1098, case1) {
				istringstream in("11\n"
				                 "7 6 5 5 6 5 4 5 5 4 4\n"
				                 "3 2 2 2 2 3 3 2 1 2 3");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Yes 1", out.str());
			}

			TEST(b1098, case2) {
				istringstream in("11\n"
				                 "7 6 5 5 6 5 4 5 5 4 4\n"
				                 "3 2 2 2 3 4 3 2 1 2 3");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("No 1", out.str());
			}
		}// namespace b1098

		namespace b1099 {
			TEST(b1099, case1) {
				istringstream in("47");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("Yes\n"
				          "41",
				          out.str());
			}

			TEST(b1099, case2) {
				istringstream in("21");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("No\n"
				          "23",
				          out.str());
			}
		}// namespace b1099

		namespace b1100 {
			TEST(b1100, case1) {
				istringstream in("5\n"
				                 "372928196906118710\n"
				                 "610481197806202213\n"
				                 "440684198612150417\n"
				                 "13072819571002001X\n"
				                 "150702193604190912\n"
				                 "6\n"
				                 "530125197901260019\n"
				                 "150702193604190912\n"
				                 "220221196701020034\n"
				                 "610481197806202213\n"
				                 "440684198612150417\n"
				                 "370205198709275042");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("3\n"
				          "150702193604190912",
				          out.str());
			}
		}// namespace b1100

		namespace b1101 {
			TEST(b1101, case1) {
				istringstream in("12345 2");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("3.66", out.str());
			}

			TEST(b1101, case2) {
				istringstream in("12345 5");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("1.00", out.str());
			}
		}// namespace b1101

		namespace b1102 {
			TEST(b1102, case1) {
				istringstream in("4\n"
				                 "zju007 39 10\n"
				                 "pku2019 9 332\n"
				                 "pat2018 95 79\n"
				                 "qdu106 19 38");
				auto out = ostringstream();
				main(in, out);
				const auto ans = out.str();
				ASSERT_EQ("pku2019 332\n"
				          "pat2018 7505",
				          out.str());
			}
		}// namespace b1102
	}    // namespace b

	namespace a {}

	namespace top {}
}// namespace pat
