#include "luogu.h"
#include "gtest/gtest.h"

using namespace std;

namespace luogu {
	TEST(P1001, case1) {
		istringstream in("20 30");
		auto out = ostringstream();
		P1001::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("50", ans);
	}

	TEST(P1000, case1) {
		istringstream in("");
		auto out = ostringstream();
		P1000::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("                ********\n"
		          "               ************\n"
		          "               ####....#.\n"
		          "             #..###.....##....\n"
		          "             ###.......######              ###            ###\n"
		          "                ...........               #...#          #...#\n"
		          "               ##*#######                 #.#.#          #.#.#\n"
		          "            ####*******######             #.#.#          #.#.#\n"
		          "           ...#***.****.*###....          #...#          #...#\n"
		          "           ....**********##.....           ###            ###\n"
		          "           ....****    *****....\n"
		          "             ####        ####\n"
		          "           ######        ######\n"
		          "##############################################################\n"
		          "#...#......#.##...#......#.##...#......#.##------------------#\n"
		          "###########################################------------------#\n"
		          "#..#....#....##..#....#....##..#....#....#####################\n"
		          "##########################################    #----------#\n"
		          "#.....#......##.....#......##.....#......#    #----------#\n"
		          "##########################################    #----------#\n"
		          "#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#\n"
		          "##########################################    ############",
		          ans);
	}

	TEST(P1008, case1) {
		istringstream in("");
		auto out = ostringstream();
		P1008::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("192 384 576\n219 438 657\n273 546 819\n327 654 981\n", ans);
	}

	TEST(P1002, case1) {
		istringstream in("6 6 3 3");
		auto out = ostringstream();
		P1002::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6", ans);
	}

	TEST(P1003, case1) {
		istringstream in("3\n1 0 2 3\n0 2 3 3\n2 1 3 3\n2 2");
		auto out = ostringstream();
		P1003::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(P1003, case2) {
		istringstream in("3\n1 0 2 3\n0 2 3 3\n2 1 3 3\n4 5");
		auto out = ostringstream();
		P1003::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("-1", ans);
	}

	TEST(P5703, case1) {
		istringstream in("5 3");
		auto out = ostringstream();
		P5703::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("15", ans);
	}

	TEST(P5704, case1) {
		istringstream in("q");
		auto out = ostringstream();
		P5704::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Q", ans);
	}

	TEST(P5705, case1) {
		istringstream in("123.4");
		auto out = ostringstream();
		P5705::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4.321", ans);
	}

	TEST(P5706, case1) {
		istringstream in("500.0 3");
		auto out = ostringstream();
		P5706::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("166.667\n"
		          "6",
		          ans);
	}

	TEST(P1425, case1) {
		istringstream in("12 50 19 10");
		auto out = ostringstream();
		P1425::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6 20", ans);
	}

	TEST(P2433, case1) {
		istringstream in("2");
		auto out = ostringstream();
		P2433::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6 4", ans);
	}

	TEST(P5708, case1) {
		istringstream in("3 4 5");
		auto out = ostringstream();
		P5708::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6.0", ans);
	}

	TEST(P1421, case1) {
		istringstream in("10 3");
		auto out = ostringstream();
		P1421::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(P5709, case1) {
		istringstream in("50 10 200");
		auto out = ostringstream();
		P5709::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("30", ans);
	}

	TEST(P2181, case1) {
		istringstream in("3");
		auto out = ostringstream();
		P2181::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(P2181, case2) {
		istringstream in("6");
		auto out = ostringstream();
		P2181::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("15", ans);
	}

	TEST(P2181, case3) {
		istringstream in("4");
		auto out = ostringstream();
		P2181::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(P2181, case4) {
		istringstream in("5");
		auto out = ostringstream();
		P2181::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(P5707, case1) {
		istringstream in("100 99");
		auto out = ostringstream();
		P5707::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("07:48", ans);
	}

	TEST(P3954, case1) {
		istringstream in("100 100 80");
		auto out = ostringstream();
		P3954::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("90", ans);
	}

	TEST(P3954, case2) {
		istringstream in("60 90 80");
		auto out = ostringstream();
		P3954::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("79", ans);
	}

	TEST(P5710, case1) {
		istringstream in("12");
		auto out = ostringstream();
		P5710::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 1 0 0", ans);
	}

	TEST(P5711, case1) {
		istringstream in("1926");
		auto out = ostringstream();
		P5711::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(P5711, case2) {
		istringstream in("1900");
		auto out = ostringstream();
		P5711::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(P5711, case3) {
		istringstream in("2000");
		auto out = ostringstream();
		P5711::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(P5711, case4) {
		istringstream in("1996");
		auto out = ostringstream();
		P5711::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(P5712, case1) {
		istringstream in("1");
		auto out = ostringstream();
		P5712::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Today, I ate 1 apple.", ans);
	}

	TEST(P5712, case3) {
		istringstream in("3");
		auto out = ostringstream();
		P5712::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Today, I ate 3 apples.", ans);
	}

	TEST(P5713, case1) {
		istringstream in("2");
		auto out = ostringstream();
		P5713::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Local", ans);
	}

	TEST(P5713, case2) {
		istringstream in("50");
		auto out = ostringstream();
		P5713::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Luogu", ans);
	}

	TEST(P5715, case1) {
		istringstream in("1 14 5");
		auto out = ostringstream();
		P5715::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 5 14 ", ans);
	}

	TEST(P5715, case2) {
		istringstream in("2 2 2");
		auto out = ostringstream();
		P5715::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2 2 2 ", ans);
	}

	TEST(P5714, case1) {
		istringstream in("70 1.72");
		auto out = ostringstream();
		P5714::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Normal", ans);
	}

	TEST(P5716, case1) {
		istringstream in("1926 8");
		auto out = ostringstream();
		P5716::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("31", ans);
	}

	TEST(P5716, case2) {
		istringstream in("2000 2");
		auto out = ostringstream();
		P5716::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("29", ans);
	}

	TEST(P1085, case1) {
		istringstream in("5 3\n"
		                 "6 2\n"
		                 "7 2\n"
		                 "5 3\n"
		                 "5 4\n"
		                 "0 4\n"
		                 "0 6");
		auto out = ostringstream();
		P1085::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(P1909, case1) {
		istringstream in("57\n2 2\n50 30\n30 27");
		auto out = ostringstream();
		P1909::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("54", ans);
	}

	TEST(P1909, case2) {
		istringstream in("9998\n128 233\n128 2333\n128 666");
		auto out = ostringstream();
		P1909::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("18407", ans);
	}

	TEST(P1909, case3) {
		istringstream in("9999\n101 1111\n1 9999\n1111 9999");
		auto out = ostringstream();
		P1909::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("89991", ans);
	}

	TEST(P1055, case1) {
		istringstream in("0-670-82162-4");
		auto out = ostringstream();
		P1055::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Right", ans);
	}

	TEST(P1055, case2) {
		istringstream in("0-670-82162-0");
		auto out = ostringstream();
		P1055::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0-670-82162-4", ans);
	}

	TEST(P1422, case1) {
		istringstream in("267");
		auto out = ostringstream();
		P1422::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("121.5", ans);
	}

	TEST(P1424, case1) {
		istringstream in("3 10");
		auto out = ostringstream();
		P1424::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2000", ans);
	}

	TEST(P1888, case1) {
		istringstream in("3 5 4");
		auto out = ostringstream();
		P1888::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3/5", ans);
	}

	TEST(P1046, case1) {
		istringstream in("100 200 150 140 129 134 167 198 200 111\n"
		                 "110");
		auto out = ostringstream();
		P1046::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(P4414, case1) {
		istringstream in("1 5 3\n"
		                 "ABC");
		auto out = ostringstream();
		P4414::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 3 5 ", ans);
	}

	TEST(P4414, case2) {
		istringstream in("6 4 2\n"
		                 "CAB");
		auto out = ostringstream();
		P4414::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6 2 4 ", ans);
	}

	TEST(P5718, case1) {
		istringstream in("8\n"
		                 "1 9 2 6 0 8 1 7");
		auto out = ostringstream();
		P5718::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(P5719, case1) {
		istringstream in("100 16");
		auto out = ostringstream();
		P5719::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("56.0 50.1", ans);
	}

	TEST(P5720, case1) {
		istringstream in("100");
		auto out = ostringstream();
		P5720::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(P5721, case1) {
		istringstream in("5");
		auto out = ostringstream();
		P5721::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0102030405\n"
		          "06070809\n"
		          "101112\n"
		          "1314\n"
		          "15\n",
		          ans);
	}

	TEST(P1009, case1) {
		istringstream in("3");
		auto out = ostringstream();
		P1009::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("9", ans);
	}

	TEST(P1980, case1) {
		istringstream in("11 1");
		auto out = ostringstream();
		P1980::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(P1035, case1) {
		istringstream in("1");
		auto out = ostringstream();
		P1035::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(P2669, case1) {
		istringstream in("6");
		auto out = ostringstream();
		P2669::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("14", ans);
	}

	TEST(P2669, case2) {
		istringstream in("1000");
		auto out = ostringstream();
		P2669::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("29820", ans);
	}

	TEST(P5722, case1) {
		istringstream in("100");
		auto out = ostringstream();
		P5722::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("5050", ans);
	}

	TEST(P5723, case1) {
		istringstream in("100");
		auto out = ostringstream();
		P5723::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2\n"
		          "3\n"
		          "5\n"
		          "7\n"
		          "11\n"
		          "13\n"
		          "17\n"
		          "19\n"
		          "23\n"
		          "9\n",
		          ans);
	}

	TEST(P1217, case1) {
		istringstream in("5 500");
		auto out = ostringstream();
		P1217::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("5\n"
		          "7\n"
		          "11\n"
		          "101\n"
		          "131\n"
		          "151\n"
		          "181\n"
		          "191\n"
		          "313\n"
		          "353\n"
		          "373\n"
		          "383\n",
		          ans);
	}

	TEST(P1423, case1) {
		istringstream in("4.3");
		auto out = ostringstream();
		P1423::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(P1307, case1) {
		istringstream in("123");
		auto out = ostringstream();
		P1307::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("321", ans);
	}

	TEST(P1307, case2) {
		istringstream in("-380");
		auto out = ostringstream();
		P1307::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("-83", ans);
	}

	TEST(P1720, case1) {
		istringstream in("6");
		auto out = ostringstream();
		P1720::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("8.00", ans);
	}

	TEST(P5724, case1) {
		istringstream in("6\n1 1 4 5 1 4");
		auto out = ostringstream();
		P5724::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(P1420, case1) {
		istringstream in("10\n1 5 6 2 3 4 5 6 8 9");
		auto out = ostringstream();
		P1420::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(P1075, case1) {
		istringstream in("21");
		auto out = ostringstream();
		P1075::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(P5725, case1) {
		istringstream in("4");
		auto out = ostringstream();
		P5725::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("01020304\n"
		          "05060708\n"
		          "09101112\n"
		          "13141516\n"
		          "\n"
		          "      01\n"
		          "    0203\n"
		          "  040506\n"
		          "07080910\n",
		          ans);
	}

	TEST(P4956, case1) {
		istringstream in("1456");
		auto out = ostringstream();
		P4956::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1\n1", ans);
	}

	TEST(P4956, case2) {
		istringstream in("6188");
		auto out = ostringstream();
		P4956::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("14\n1", ans);
	}

	TEST(P4956, case3) {
		istringstream in("40404");
		auto out = ostringstream();
		P4956::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("99\n4", ans);
	}
}// namespace luogu
