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

	TEST(P5726, case1) {
		istringstream in("5\n9 5 6 8 9");
		auto out = ostringstream();
		P5726::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("7.67", ans);
	}

	TEST(P1089, case1) {
		istringstream in("290\n"
		                 "230\n"
		                 "280\n"
		                 "200\n"
		                 "300\n"
		                 "170\n"
		                 "340\n"
		                 "50 \n"
		                 "90 \n"
		                 "80 \n"
		                 "200\n"
		                 "60 ");
		auto out = ostringstream();
		P1089::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("-7", ans);
	}

	TEST(P1089, case2) {
		istringstream in("290 \n"
		                 "230 \n"
		                 "280 \n"
		                 "200 \n"
		                 "300 \n"
		                 "170 \n"
		                 "330 \n"
		                 "50 \n"
		                 "90 \n"
		                 "80 \n"
		                 "200 \n"
		                 "60 ");
		auto out = ostringstream();
		P1089::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1580", ans);
	}

	TEST(P1428, case1) {
		istringstream in("6\n"
		                 "4 3 0 5 1 2");
		auto out = ostringstream();
		P1428::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0 0 0 3 1 2 ", ans);
	}

	TEST(P1427, case1) {
		istringstream in("3 65 23 5 34 1 30 0");
		auto out = ostringstream();
		P1427::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("30 1 34 5 23 65 3 ", ans);
	}

	TEST(P5727, case1) {
		istringstream in("20");
		auto out = ostringstream();
		P5727::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 2 4 8 16 5 10 20 ", ans);
	}

	TEST(P1047, case1) {
		istringstream in("500 3\n"
		                 "150 300\n"
		                 "100 200\n"
		                 "470 471");
		auto out = ostringstream();
		P1047::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("298", ans);
	}

	TEST(P5728, case1) {
		istringstream in("3\n"
		                 "90 90 90\n"
		                 "85 95 90\n"
		                 "80 100 91");
		auto out = ostringstream();
		P5728::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(P5729, case1) {
		istringstream in("4 4 4\n"
		                 "1\n"
		                 "1 1 1 2 2 2");
		auto out = ostringstream();
		P5729::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("56", ans);
	}

	TEST(P2550, case1) {
		istringstream in("2\n"
		                 "23 31 1 14 19 17 18\n"
		                 "12 8 9 23 1 16 7\n"
		                 "11 7 10 21 2 9 31");
		auto out = ostringstream();
		P2550::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0 0 0 0 0 1 1 ", ans);
	}

	TEST(P2615, case1) {
		istringstream in("3");
		auto out = ostringstream();
		P2615::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("8 1 6 \n"
		          "3 5 7 \n"
		          "4 9 2 \n",
		          ans);
	}

	TEST(P5730, case1) {
		istringstream in("10\n"
		                 "0123456789");
		auto out = ostringstream();
		P5730::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX\n"
		          "X.X...X...X...X.X.X.X...X.....X.X.X.X.X\n"
		          "X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX\n"
		          "X.X...X.X.....X...X...X.X.X...X.X.X...X\n"
		          "XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX\n",
		          ans);
	}

	TEST(P1554, case1) {
		istringstream in("129 137");
		auto out = ostringstream();
		P1554::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 10 2 9 1 1 1 1 0 1 ", ans);
	}

	TEST(P2141, case1) {
		istringstream in("4\n"
		                 "1 2 3 4");
		auto out = ostringstream();
		P2141::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(P2141, case2) {
		istringstream in("100\n"
		                 "6094 106 5958 877 3352 8959 292 9253 3860 448 5709 8295 4667 2588 3663 2486 1129 8870 3126 6203 727 4316 6541 9689 8818 2119 7331 7598 1879 7303 1100 8740 4567 2649 2373 7505 5848 4337 9953 4436 8395 8273 1028 4449 3363 6254 7856 6710 8422 3833 5690 6664 6326 2550 119 2075 3475 9024 3239 8889 807 543 8103 1441 9731 3873 5194 9557 3256 6245 3266 2777 4552 2390 8550 4777 9701 5694 9133 6736 2586 298 3695 1992 2958 3831 6905 8134 989 6292 8967 118 8442 1765 931 4760 5945 1703 6262 1671");
		auto out = ostringstream();
		P2141::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("22", ans);
	}

	TEST(P1614, case1) {
		istringstream in("8 3\n"
		                 "1\n"
		                 "4\n"
		                 "7\n"
		                 "3\n"
		                 "1\n"
		                 "2\n"
		                 "4\n"
		                 "3");
		auto out = ostringstream();
		P1614::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6", ans);
	}

	TEST(P2911, case1) {
		istringstream in("3 2 3");
		auto out = ostringstream();
		P2911::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(P1161, case1) {
		istringstream in("3\n"
		                 "1.618034 13\n"
		                 "2.618034 7\n"
		                 "1.000000 21");
		auto out = ostringstream();
		P1161::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("20", ans);
	}

	TEST(P5731, case1) {
		istringstream in("4");
		auto out = ostringstream();
		P5731::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("  1  2  3  4\n"
		          " 12 13 14  5\n"
		          " 11 16 15  6\n"
		          " 10  9  8  7\n",
		          ans);
	}

	TEST(P5732, case1) {
		istringstream in("6");
		auto out = ostringstream();
		P5732::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 \n"
		          "1 1 \n"
		          "1 2 1 \n"
		          "1 3 3 1 \n"
		          "1 4 6 4 1 \n"
		          "1 5 10 10 5 1 \n",
		          ans);
	}

	TEST(P1789, case1) {
		istringstream in("5 1 0\n"
		                 "3 3");
		auto out = ostringstream();
		P1789::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("12", ans);
	}

	TEST(P1319, case1) {
		istringstream in("7 3 1 6 1 6 4 3 1 6 1 6 1 3 7");
		auto out = ostringstream();
		P1319::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0001000\n"
		          "0001000\n"
		          "0001111\n"
		          "0001000\n"
		          "0001000\n"
		          "0001000\n"
		          "1111111\n",
		          ans);
	}

	TEST(P1319, case2) {
		istringstream in("5 0 5 2 1 2 5 2 1 2 5");
		auto out = ostringstream();
		P1319::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("11111\n"
		          "00100\n"
		          "11111\n"
		          "00100\n"
		          "11111\n",
		          ans);
	}

	TEST(P1320, case1) {
		istringstream in("0001000\n"
		                 "0001000\n"
		                 "0001111\n"
		                 "0001000\n"
		                 "0001000\n"
		                 "0001000\n"
		                 "1111111");
		auto out = ostringstream();
		P1320::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("7 3 1 6 1 6 4 3 1 6 1 6 1 3 7 ", ans);
	}

	TEST(P1205, case1) {
		istringstream in("3\n"
		                 "@-@\n"
		                 "---\n"
		                 "@@-\n"
		                 "@-@\n"
		                 "@--\n"
		                 "--@");
		auto out = ostringstream();
		auto sol = P1205();
		P1205::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(P1205, case2) {
		istringstream in("5\n"
		                 "-@@@-\n"
		                 "-@@--\n"
		                 "-@---\n"
		                 "-----\n"
		                 "-----\n"
		                 "-----\n"
		                 "----@\n"
		                 "---@@\n"
		                 "--@@@\n"
		                 "-----");
		auto out = ostringstream();
		auto sol = P1205();
		P1205::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(P5733, case1) {
		istringstream in("Luogu4!");
		auto out = ostringstream();
		P5733::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("LUOGU4!", ans);
	}

	TEST(P1914, case1) {
		istringstream in("1\n"
		                 "qwe");
		auto out = ostringstream();
		P1914::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("rxf", ans);
	}

	TEST(P1125, case1) {
		istringstream in("error");
		auto out = ostringstream();
		P1125::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Lucky Word\n"
		          "2",
		          ans);
	}

	TEST(P1125, case2) {
		istringstream in("olympic");
		auto out = ostringstream();
		P1125::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("No Answer\n"
		          "0",
		          ans);
	}

	TEST(P1125, case3) {
		istringstream in("ubuntuubuntuubuntuubuntuubuntuu");
		auto out = ostringstream();
		P1125::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Lucky Word\n"
		          "11",
		          ans);
	}

	TEST(P1957, case1) {
		istringstream in("4\na 64 46\n275 125\nc 11 99\nb 46 64\n");
		auto out = ostringstream();
		P1957::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("64+46=110\n9\n275+125=400\n11\n11*99=1089\n10\n46-64=-18\n9\n", ans);
	}

	TEST(P1957, case2) {
		istringstream in("1\na 99 999");
		auto out = ostringstream();
		P1957::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("99+999=1098\n11\n", ans);
	}

	TEST(P5015, case1) {
		istringstream in("234");
		auto out = ostringstream();
		P5015::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(P5015, case2) {
		istringstream in("Ca 45");
		auto out = ostringstream();
		P5015::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(P5734, case1) {
		istringstream in("4\n"
		                 "ILove\n"
		                 "1 Luogu\n"
		                 "2 5 5\n"
		                 "3 3 guGugu\n"
		                 "4 gu");
		auto out = ostringstream();
		P5734::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("ILoveLuogu\n"
		          "Luogu\n"
		          "LuoguGugugu\n"
		          "3\n",
		          ans);
	}

	TEST(P5734, case2) {
		istringstream in("5\n"
		                 "ILove\n"
		                 "1 Luogu\n"
		                 "2 5 5\n"
		                 "3 3 guGugu\n"
		                 "4 gu\n"
		                 "4 fafa");
		auto out = ostringstream();
		P5734::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("ILoveLuogu\n"
		          "Luogu\n"
		          "LuoguGugugu\n"
		          "3\n"
		          "-1\n",
		          ans);
	}

	TEST(P1308, case1) {
		istringstream in("To\n"
		                 "to be or not to be is a question");
		auto out = ostringstream();
		P1308::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2 0", ans);
	}

	TEST(P1308, case2) {
		istringstream in("to\n"
		                 "Did the Ottoman Empire lose its power at that time");
		auto out = ostringstream();
		P1308::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("-1", ans);
	}

	TEST(P1308, case3) {
		istringstream in("td\n"
		                 "  Td tLWCsrmt");
		auto out = ostringstream();
		P1308::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 2", ans);
	}

	TEST(P1765, case1) {
		istringstream in("i have a dream");
		auto out = ostringstream();
		P1765::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("23", ans);
	}

	TEST(P3741, case1) {
		istringstream in("2\n"
		                 "VK");
		auto out = ostringstream();
		P3741::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(P3741, case2) {
		istringstream in("2\n"
		                 "VV");
		auto out = ostringstream();
		P3741::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(P3741, case3) {
		istringstream in("1\n"
		                 "V");
		auto out = ostringstream();
		P3741::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(P3741, case4) {
		istringstream in("20\n"
		                 "VKKKKKKKKKVVVVVVVVVK");
		auto out = ostringstream();
		P3741::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(P3741, case5) {
		istringstream in("4\n"
		                 "KVKV");
		auto out = ostringstream();
		P3741::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(P3741, case6) {
		istringstream in("23\n"
		                 "KKVVKVVKVVKKVVKKVKVVKKV");
		auto out = ostringstream();
		P3741::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(P1321, case1) {
		istringstream in("......boyogirlyy......girl.......");
		auto out = ostringstream();
		P1321::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4\n"
		          "2\n",
		          ans);
	}

	TEST(P1553, case1) {
		istringstream in("5087462");
		auto out = ostringstream();
		P1553::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2647805", ans);
	}

	TEST(P1553, case2) {
		istringstream in("600.084");
		auto out = ostringstream();
		P1553::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6.48", ans);
	}

	TEST(P1553, case3) {
		istringstream in("700/27");
		auto out = ostringstream();
		P1553::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("7/72", ans);
	}

	TEST(P1553, case4) {
		istringstream in("8670%");
		auto out = ostringstream();
		P1553::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("768%", ans);
	}

	TEST(P1553, case5) {
		istringstream in("0");
		auto out = ostringstream();
		P1553::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(P1603, case1) {
		istringstream in("Black Obama is two five zero .");
		auto out = ostringstream();
		P1603::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("425", ans);
	}

	TEST(P1200, case1) {
		istringstream in("COMETQ\n"
		                 "HVNGAT");
		auto out = ostringstream();
		P1200::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("GO", ans);
	}

	TEST(P1200, case2) {
		istringstream in("ABSTAR\n"
		                 "USACO");
		auto out = ostringstream();
		P1200::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("STAY", ans);
	}

	TEST(P1597, case1) {
		istringstream in("a:=3;b:=4;c:=5;");
		auto out = ostringstream();
		P1597::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3 4 5", ans);
	}

	TEST(P1597, case2) {
		istringstream in("c:=5;a:=b;b:=c;c:=a;a:=a;b:=b;c:=c;a:=c;c:=a;a:=b;b:=c;c:=a;a:=a;b:=b;c:=c;a:=c;b:=a;a:=c;c:=b;a:=2;c:=a;b:=9;\n");
		auto out = ostringstream();
		P1597::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2 9 2", ans);
	}

	TEST(P1598, case1) {
		istringstream in("THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.\n"
		                 "THIS IS AN EXAMPLE TO TEST FOR YOUR\n"
		                 "HISTOGRAM PROGRAM.\n"
		                 "HELLO!");
		auto out = ostringstream();
		P1598::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("                            *                       \n"
		          "                            *                       \n"
		          "        *                   *                       \n"
		          "        *                   *     *   *             \n"
		          "        *                   *     *   *             \n"
		          "*       *     *             *     *   *             \n"
		          "*       *     * *     * *   *     * * *             \n"
		          "*       *   * * *     * *   * *   * * * *           \n"
		          "*     * * * * * *     * * * * *   * * * *     * *   \n"
		          "* * * * * * * * * * * * * * * * * * * * * * * * * * \n"
		          "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z ",
		          ans);
	}

	TEST(P5735, case1) {
		istringstream in("0 0\n"
		                 "0 3\n"
		                 "4 0");
		auto out = ostringstream();
		P5735::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("12.00", ans);
	}
}// namespace luogu
