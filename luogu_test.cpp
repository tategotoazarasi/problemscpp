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
}// namespace luogu
