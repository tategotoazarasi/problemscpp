//
// Created by wangzhiheng on 26/09/2025.
//
#include "comp526.h"
#include "gtest/gtest.h"

namespace comp526 {
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
}// namespace comp526