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
}// namespace luogu
