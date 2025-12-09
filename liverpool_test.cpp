//
// Created by wangzhiheng on 26/09/2025.
//
#include "liverpool.h"
#include "gtest/gtest.h"

namespace liverpool {
	namespace stable_matching {

		// Helper function to convert from standard ranked-list preferences
		// to the priority-matrix format the solution expects.
		// Input: prefs[i] is a vector of partner IDs, ranked from most to least preferred.
		// Output: matrix[i][j] is the priority rank student i gives to company j.
		vector<vector<int>> convert_prefs_to_matrix(const vector<vector<int>> &prefs) {
			int n = prefs.size();
			vector<vector<int>> matrix(n, vector<int>(n));
			for(int i = 0; i < n; ++i) {
				for(int rank = 0; rank < n; ++rank) {
					int partner_id        = prefs[i][rank];
					matrix[i][partner_id] = rank;
				}
			}
			return matrix;
		}

		TEST(StableMatchingTest, Simple2x2) {
			// A simple case where both students prefer Company 0.
			// Students:
			//  S0: C0 > C1
			//  S1: C0 > C1
			// Companies:
			//  C0: S1 > S0
			//  C1: S0 > S1
			// Expected Student-Optimal Matching: (S0, C1), (S1, C0)
			// S0 proposes to C0, S1 proposes to C0. C0 prefers S1 and rejects S0.
			// S0 then proposes to C1, who is free and accepts.
			vector<vector<int>> s_prefs = {{0, 1}, {0, 1}};
			vector<vector<int>> c_prefs = {{1, 0}, {0, 1}};

			vector<vector<int>> s2c = convert_prefs_to_matrix(s_prefs);
			vector<vector<int>> c2s = convert_prefs_to_matrix(c_prefs);

			Solution sol;
			vector<int> expected_matches = {1, 0};// ans[0]=C1, ans[1]=C0
			ASSERT_EQ(sol.match(s2c, c2s), expected_matches);
		}

		TEST(StableMatchingTest, Wikipedia3x3Example) {
			// This is the classic example from the Stable Marriage Problem Wikipedia page.
			// Students (Men): A=0, B=1, C=2
			// Companies (Women): X=0, Y=1, Z=2
			// Prefs:
			//  A: Y > X > Z  -> {1, 0, 2}
			//  B: Z > Y > X  -> {2, 1, 0}
			//  C: X > Z > Y  -> {0, 2, 1}
			//  X: B > A > C  -> {1, 0, 2}
			//  Y: C > B > A  -> {2, 1, 0}
			//  Z: A > C > B  -> {0, 2, 1}
			// Expected Student-Optimal (Men-Optimal) Matching: (A,Y), (B,Z), (C,X)
			vector<vector<int>> s_prefs = {{1, 0, 2}, {2, 1, 0}, {0, 2, 1}};
			vector<vector<int>> c_prefs = {{1, 0, 2}, {2, 1, 0}, {0, 2, 1}};

			vector<vector<int>> s2c = convert_prefs_to_matrix(s_prefs);
			vector<vector<int>> c2s = convert_prefs_to_matrix(c_prefs);

			Solution sol;
			vector<int> expected_matches = {1, 2, 0};// ans[0]=C1, ans[1]=C2, ans[2]=C0
			ASSERT_EQ(sol.match(s2c, c2s), expected_matches);
		}

		TEST(StableMatchingTest, MultiRound3x3) {
			// A case designed to require multiple rounds of proposals and rejections.
			// Students:
			//  S0: C0 > C1 > C2
			//  S1: C1 > C0 > C2
			//  S2: C0 > C1 > C2
			// Companies:
			//  C0: S1 > S2 > S0
			//  C1: S0 > S1 > S2
			//  C2: S0 > S1 > S2
			// Expected Student-Optimal Matching: (S0, C1), (S1, C0), (S2, C2)
			// Trace:
			// 1. S0->C0, S1->C1, S2->C0. C0 keeps S2 (better rank), rejects S0. Matches: (S2,C0), (S1,C1).
			// 2. S0 (free) -> C1. C1 has S1, prefers S0. C1 keeps S0, rejects S1. Matches: (S2,C0), (S0,C1).
			// 3. S1 (free) -> C0. C0 has S2, prefers S1. C0 keeps S1, rejects S2. Matches: (S1,C0), (S0,C1).
			// 4. S2 (free) -> C1. C1 has S0, prefers S0. Rejects S2.
			// 5. S2 (free) -> C2. C2 is free, accepts S2.
			// Final: (S0,C1), (S1,C0), (S2,C2)
			vector<vector<int>> s_prefs = {{0, 1, 2}, {1, 0, 2}, {0, 1, 2}};
			vector<vector<int>> c_prefs = {{1, 2, 0}, {0, 1, 2}, {0, 1, 2}};

			vector<vector<int>> s2c = convert_prefs_to_matrix(s_prefs);
			vector<vector<int>> c2s = convert_prefs_to_matrix(c_prefs);

			Solution sol;
			vector<int> expected_matches = {1, 0, 2};// ans[0]=C1, ans[1]=C0, ans[2]=C2
			ASSERT_EQ(sol.match(s2c, c2s), expected_matches);
		}

		TEST(StableMatchingTest, WorstCaseForStudents) {
			// A case where every student gets their last choice.
			// Students:
			//  S0: C0 > C1
			//  S1: C0 > C1
			// Companies:
			//  C0: S1 > S0
			//  C1: S1 > S0
			// Expected Student-Optimal Matching: (S0, C1), (S1, C0)
			// S0 proposes to C0, S1 proposes to C0. C0 takes S1, rejects S0.
			// S0 proposes to C1. C1 takes S0. Final: (S0,C1), (S1,C0).
			// S0 gets 2nd choice. S1 gets 1st choice.
			vector<vector<int>> s_prefs = {{0, 1}, {0, 1}};
			vector<vector<int>> c_prefs = {{1, 0}, {1, 0}};

			vector<vector<int>> s2c = convert_prefs_to_matrix(s_prefs);
			vector<vector<int>> c2s = convert_prefs_to_matrix(c_prefs);

			Solution sol;
			vector<int> expected_matches = {1, 0};
			ASSERT_EQ(sol.match(s2c, c2s), expected_matches);
		}

	}// namespace stable_matching
	namespace recount {
		TEST(recout, case1) {
			istringstream in("Penny Franklin\n"
			                 "Connie Froggatt\n"
			                 "Barbara Skinner\n"
			                 "Connie Froggatt\n"
			                 "Jose Antonio Gomez-Iglesias\n"
			                 "Connie Froggatt\n"
			                 "Bruce Stanger\n"
			                 "Barbara Skinner\n"
			                 "Barbara Skinner\n"
			                 "***");
			auto out = ostringstream();
			recount::main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("Runoff!", ans);
		}
	}// namespace recount

	namespace set {
		TEST(set, case1) {
			istringstream in("3DTG 3DOP 2DSG\n1SOP 1DTG 2OTR\n3DOR 3STG 2DSP\n3SSP 3OTG 1DTP\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1 8 11\n2 9 12\n3 7 12\n5 7 9\n6 8 12\n7 10 11\n", ans);
		}
	}// namespace set

	namespace plantingtrees {
		TEST(plantingtrees, case1) {
			istringstream in("4\n2 3 4 3\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("7", ans);
		}

		TEST(plantingtrees, case2) {
			istringstream in("6\n39 38 9 35 39 20\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("42", ans);
		}
	}// namespace plantingtrees

	namespace snowflakes {
		TEST(snowflakes, case1) {
			istringstream in("1\n5\n1\n2\n3\n2\n1\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}
	}// namespace snowflakes

	namespace amalgram {
		TEST(amalgram, case1) {
			istringstream in("hello\nworld");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("dehllorw", ans);
		}

		TEST(amalgram, case2) {
			istringstream in("unclear\ninstructions");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("aceiilnnorssttu", ans);
		}

		TEST(amalgram, case3) {
			istringstream in("boring\nboring");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("bginor", ans);
		}
	}// namespace amalgram

	namespace wheresmyinternet {
		TEST(wheresmyinternet, case1) {
			istringstream in("6 4\n1 2\n2 3\n3 4\n5 6\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("5\n6\n", ans);
		}

		TEST(wheresmyinternet, case2) {
			istringstream in("2 1\n2 1\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("Connected", ans);
		}

		TEST(wheresmyinternet, case3) {
			istringstream in("4 3\n2 3\n4 2\n3 4\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2\n3\n4\n", ans);
		}
	}// namespace wheresmyinternet

	namespace oddities {
		TEST(oddities, case1) {
			istringstream in("3\n10\n9\n-5\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("10 is even\n9 is odd\n-5 is odd\n", ans);
		}
	}// namespace oddities

	namespace countingchocolate {
		TEST(countingchocolate, case1) {
			istringstream in("6\n1 4 3 12 13 1\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("YES", ans);
		}

		TEST(countingchocolate, case2) {
			istringstream in("6\n1 1 1 3 4 11\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("NO", ans);
		}
	}// namespace countingchocolate

	namespace grid {
		TEST(grid, case1) {
			istringstream in("2 2\n11\n11\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2", ans);
		}

		TEST(grid, case2) {
			istringstream in("2 2\n22\n22\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("-1", ans);
		}

		TEST(grid, case3) {
			istringstream in("5 4\n2120\n1203\n3113\n1120\n1110\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("6", ans);
		}
	}// namespace grid

	namespace allpairspath {
		TEST(grid, case1) {
			istringstream in("4 3 4\n0 1 2\n1 2 2\n3 3 1\n0 2\n1 2\n3 0\n3 3\n2 1 2\n0 1 100\n0 1\n1 0\n0 0 0\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("4\n2\nImpossible\n0\n\n100\nImpossible\n\n", ans);
		}
	}// namespace allpairspath

	namespace weakvertices {
		TEST(weakvertices, case1) {
			istringstream in("9\n0 1 1 1 0 0 0 0 0\n1 0 0 0 0 0 1 0 0\n1 0 0 1 0 1 0 0 0\n1 0 1 0 0 1 1 0 0\n0 0 0 0 0 0 1 1 0\n0 0 1 1 0 0 0 0 0\n0 1 0 1 1 0 0 1 0\n0 0 0 0 1 0 1 0 1\n0 0 0 0 0 0 0 1 0\n1\n0\n-1\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1 8 \n0 \n", ans);
		}
	}// namespace weakvertices

	namespace clockpictures {
		TEST(clockpictures, case1) {
			istringstream in("6\n1 2 3 4 5 6\n7 6 5 4 3 1\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("impossible", ans);
		}

		TEST(clockpictures, case2) {
			istringstream in("2\n0 270000\n180000 270000\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("possible", ans);
		}

		TEST(clockpictures, case3) {
			istringstream in("7\n140 130 110 120 125 100 105\n235 205 215 220 225 200 240\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("impossible", ans);
		}
	}// namespace clockpictures

	namespace ceremony {
		TEST(ceremony, case1) {
			istringstream in("6\n2 1 8 8 2 3\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("5", ans);
		}

		TEST(ceremony, case2) {
			istringstream in("5\n1 1 1 1 10\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2", ans);
		}
	}// namespace ceremony

	namespace doctorkattis {
		TEST(doctorkattis, case1) {
			istringstream in("15\n0 LUNA 31\n0 NALA 55\n0 BELLA 42\n3\n0 KITTY 77\n3\n1 LUNA 24\n2 KITTY\n3\n2 BELLA\n3\n2 LUNA\n3\n2 NALA\n3\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("NALA\nKITTY\nLUNA\nLUNA\nNALA\nThe clinic is empty\n", ans);
		}
	}// namespace doctorkattis

	namespace lobby {
		TEST(lobby, case2_0) {
			istringstream in("987654321111111\n811111111111119\n234234234234278\n818181911112111");
			auto out = ostringstream();
			main_2(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3121910778619", ans);
		}
	}// namespace lobby

	namespace printing_department {
		TEST(printing_department, case1_0) {
			istringstream in("..@@.@@@@.\n@@@.@.@.@@\n@@@@@.@.@@\n@.@@@@..@.\n@@.@@@@.@@\n.@@@@@@@.@\n.@.@.@.@@@\n@.@@@.@@@@\n.@@@@@@@@.\n@.@.@@@.@.");
			auto out = ostringstream();
			main_1(in, out);
			const auto ans = out.str();
			ASSERT_EQ("13", ans);
		}

		TEST(printing_department, case2_0) {
			istringstream in("..@@.@@@@.\n@@@.@.@.@@\n@@@@@.@.@@\n@.@@@@..@.\n@@.@@@@.@@\n.@@@@@@@.@\n.@.@.@.@@@\n@.@@@.@@@@\n.@@@@@@@@.\n@.@.@@@.@.");
			auto out = ostringstream();
			main_2(in, out);
			const auto ans = out.str();
			ASSERT_EQ("43", ans);
		}
	}// namespace printing_department

	namespace secret_entrance {
		TEST(secret_entrance, case1_0) {
			istringstream in("L68\nL30\nR48\nL5\nR60\nL55\nL1\nL99\nR14\nL82\n");
			auto out = ostringstream();
			main_1(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}

		TEST(secret_entrance, case2_0) {
			istringstream in("L68\nL30\nR48\nL5\nR60\nL55\nL1\nL99\nR14\nL82\n");
			auto out = ostringstream();
			main_2(in, out);
			const auto ans = out.str();
			ASSERT_EQ("6", ans);
		}
	}// namespace secret_entrance

	namespace cafeteria {
		TEST(cafeteria, case1_0) {
			istringstream in("3-5\n10-14\n16-20\n12-18\n\n1\n5\n8\n11\n17\n32\n");
			auto out = ostringstream();
			main_1(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}

		TEST(cafeteria, case2_0) {
			istringstream in("3-5\n10-14\n16-20\n12-18");
			auto out = ostringstream();
			main_2(in, out);
			const auto ans = out.str();
			ASSERT_EQ("14", ans);
		}
	}// namespace cafeteria

	namespace gift_shop {
		TEST(gift_shop, case1_0) {
			istringstream in("11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124");
			auto out = ostringstream();
			main_1(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1227775554", ans);
		}

		TEST(gift_shop, case2_0) {
			istringstream in("11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124");
			auto out = ostringstream();
			main_2(in, out);
			const auto ans = out.str();
			ASSERT_EQ("4174379265", ans);
		}
	}// namespace gift_shop

	namespace trash_compactor {
		TEST(trash_compactor, case1_0) {
			istringstream in("123 328  51 64 \n 45 64  387 23 \n  6 98  215 314\n*   +   *   +  \n");
			auto out = ostringstream();
			main_1(in, out, 4, 3);
			const auto ans = out.str();
			ASSERT_EQ("4277556", ans);
		}

		TEST(trash_compactor, case2_0) {
			istringstream in("123 328  51 64 \n 45 64  387 23 \n  6 98  215 314\n*   +   *   +  \n");
			auto out = ostringstream();
			main_2(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3263827", ans);
		}
	}// namespace trash_compactor

	namespace movie_theater {
		TEST(movie_theater, case1_0) {
			istringstream in("7,1\n11,1\n11,7\n9,7\n9,5\n2,5\n2,3\n7,3");
			auto out = ostringstream();
			main_1(in, out);
			const auto ans = out.str();
			ASSERT_EQ("50", ans);
		}
	}
}// namespace liverpool