#include<vector>
#include "gtest/gtest.h"
#include "leetcode.h"
#include "acwing.h"
#include "lintcode.h"

using namespace std;

namespace leetcode {
    namespace excel_sheet_column_title {
        TEST(excel_sheet_column_title, case1) { ASSERT_EQ(std::string("A"), Solution::convertToTitle(1)); }

        TEST(excel_sheet_column_title, case2) { ASSERT_EQ(std::string("AB"), Solution::convertToTitle(28)); }

        TEST(excel_sheet_column_title, case3) { ASSERT_EQ(std::string("ZY"), Solution::convertToTitle(701)); }

        TEST(excel_sheet_column_title, case4) {
            ASSERT_EQ(std::string("FXSHRXW"), Solution::convertToTitle(2147483647));
        }

        TEST(excel_sheet_column_title, case5) { ASSERT_EQ(std::string("AZ"), Solution::convertToTitle(52)); }
    }

    namespace majority_element {
        TEST(majority_element, case1) {
            Solution sol = Solution();
            int arr[] = {3, 2, 3};
            auto vec = std::vector<int>(arr, arr + 3);
            ASSERT_EQ(3, sol.majorityElement(vec));
        }

        TEST(majority_element, case2) {
            Solution sol = Solution();
            int arr[] = {2, 2, 1, 1, 1, 2, 2};
            auto vec = std::vector<int>(arr, arr + 7);
            ASSERT_EQ(2, sol.majorityElement(vec));
        }

        TEST(majority_element, case3) {
            Solution sol = Solution();
            int arr[] = {3, 2, 3};
            auto vec = std::vector<int>(arr, arr + 3);
            ASSERT_EQ(3, sol.majorityElement(vec));
        }
    }

    namespace excel_sheet_column_number {
        TEST(excel_sheet_column_number, case1) { ASSERT_EQ(1, Solution::titleToNumber("A")); }

        TEST(excel_sheet_column_number, case2) { ASSERT_EQ(28, Solution::titleToNumber("AB")); }

        TEST(excel_sheet_column_number, case3) { ASSERT_EQ(701, Solution::titleToNumber("ZY")); }

        TEST(excel_sheet_column_number, case4) { ASSERT_EQ(2147483647, Solution::titleToNumber("FXSHRXW")); }
    }

    namespace concatenated_words {
        TEST(concatenated_words, case1) {
            vector<basic_string<char>> input = vector<basic_string<char >>();
            input.emplace_back("cat");
            input.emplace_back("cats");
            input.emplace_back("catsdogcats");
            input.emplace_back("dog");
            input.emplace_back("dogcatsdog");
            input.emplace_back("hippopotamuses");
            input.emplace_back("rat");
            input.emplace_back("ratcatdogcat");
            auto ans = Solution::findAllConcatenatedWordsInADict(input);
            vector<string> output = vector<string>();
            output.emplace_back("catsdogcats");
            output.emplace_back("dogcatsdog");
            output.emplace_back("ratcatdogcat");
            for (const string &str: ans) {
                ASSERT_TRUE(find(output.cbegin(), output.cend(), str) != output.cend());
            }
            for (const string &str: output) {
                ASSERT_TRUE(find(ans.cbegin(), ans.cend(), str) != ans.cend());
            }
            ASSERT_EQ(ans.size(), output.size());
        }

        TEST(concatenated_words, case2) {
            vector<basic_string<char>> input = vector<basic_string<char >>();
            input.emplace_back("cat");
            input.emplace_back("dog");
            input.emplace_back("catdog");
            auto ans = Solution::findAllConcatenatedWordsInADict(input);
            vector<string> output = vector<string>();
            output.emplace_back("catdog");
            for (const string &str: ans) {
                ASSERT_TRUE(find(output.cbegin(), output.cend(), str) != output.cend());
            }
            for (const string &str: output) {
                ASSERT_TRUE(find(ans.cbegin(), ans.cend(), str) != ans.cend());
            }
            ASSERT_EQ(ans.size(), output.size());
        }

        TEST(concatenated_words, case4) {
            vector<basic_string<char>> input = vector<basic_string<char >>();
            input.emplace_back("nuqhmfj");
            input.emplace_back("mf");
            input.emplace_back("jf");
            input.emplace_back("n");
            input.emplace_back("u");
            input.emplace_back("q");
            input.emplace_back("h");
            auto ans = Solution::findAllConcatenatedWordsInADict(input);
            vector<string> output = vector<string>();
            for (const string &str: ans) {
                ASSERT_TRUE(find(output.cbegin(), output.cend(), str) != output.cend());
            }
            for (const string &str: output) {
                ASSERT_TRUE(find(ans.cbegin(), ans.cend(), str) != ans.cend());
            }
            ASSERT_EQ(ans.size(), output.size());
        }
    }

    namespace count_special_quadruplets {
        TEST(count_special_quadruplets, case1) {
            vector<int> vec = vector<int>();
            vec.push_back(1);
            vec.push_back(2);
            vec.push_back(3);
            vec.push_back(6);
            ASSERT_EQ(1, Solution::countQuadruplets(vec));
        }

        TEST(count_special_quadruplets, case2) {
            vector<int> vec = vector<int>();
            vec.push_back(3);
            vec.push_back(3);
            vec.push_back(6);
            vec.push_back(4);
            vec.push_back(5);
            ASSERT_EQ(0, Solution::countQuadruplets(vec));
        }

        TEST(count_special_quadruplets, case3) {
            vector<int> vec = vector<int>();
            vec.push_back(1);
            vec.push_back(1);
            vec.push_back(1);
            vec.push_back(3);
            vec.push_back(5);
            ASSERT_EQ(4, Solution::countQuadruplets(vec));
        }

        TEST(count_special_quadruplets, case4) {
            vector<int> vec = vector<int>();
            vec.push_back(28);
            vec.push_back(8);
            vec.push_back(49);
            vec.push_back(85);
            vec.push_back(37);
            vec.push_back(90);
            vec.push_back(20);
            vec.push_back(8);
            ASSERT_EQ(1, Solution::countQuadruplets(vec));
        }
    }

    namespace hand_of_straights {
        TEST(hand_of_straights, case1) {
            int input[] = {1, 2, 3, 6, 2, 3, 4, 7, 8};
            vector<int> vec = vector<int>(begin(input), end(input));
            ASSERT_TRUE(Solution::isNStraightHand(vec, 3));
        }

        TEST(hand_of_straights, case2) {
            int input[] = {1, 2, 3, 4, 5};
            vector<int> vec = vector<int>(begin(input), end(input));
            ASSERT_FALSE(Solution::isNStraightHand(vec, 4));
        }

        TEST(hand_of_straights, case3) {
            int input[] = {1, 2, 3, 4, 5, 6};
            vector<int> vec = vector<int>(begin(input), end(input));
            ASSERT_TRUE(Solution::isNStraightHand(vec, 2));
        }

        TEST(hand_of_straights, case4) {
            int input[] = {9, 13, 15, 23, 22, 25, 4, 4, 29, 15, 8, 23, 12, 19, 24, 17, 18, 11, 22, 24, 17, 17, 10, 23,
                           21, 18, 14, 18, 7, 6, 3, 6, 19, 11, 16, 11, 12, 13, 8, 26, 17, 20, 13, 19, 22, 21, 27, 9, 20,
                           15, 20, 27, 8, 13, 25, 23, 22, 15, 9, 14, 20, 10, 6, 5, 14, 12, 7, 16, 21, 18, 21, 24, 23,
                           10, 21, 16, 18, 16, 18, 5, 20, 19, 20, 10, 14, 26, 2, 9, 19, 12, 28, 17, 5, 7, 25, 22, 16,
                           17, 21, 11};
            vector<int> vec = vector<int>(begin(input), end(input));
            ASSERT_FALSE(Solution::isNStraightHand(vec, 10));
        }
    }
}

namespace acwing {
    TEST(acwing1, case1) {
        istringstream in("3 4");
        ostringstream out;
        acwing1::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("7", ans);
    }

    TEST(acwing4200, case1) {
        istringstream in("2 7 1 8 2 8");
        ostringstream out;
        acwing4200::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("0", ans);
    }

    TEST(acwing4200, case2) {
        istringstream in("20 30 40 50 0 100");
        ostringstream out;
        acwing4200::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("20", ans);
    }

    TEST(acwing4200, case3) {
        istringstream in("31 41 59 26 17 43");
        ostringstream out;
        acwing4200::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("9", ans);
    }

    TEST(acwing4201, case1) {
        istringstream in("10");
        ostringstream out;
        acwing4201::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("2", ans);
    }

    TEST(acwing4201, case2) {
        istringstream in("20");
        ostringstream out;
        acwing4201::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("3", ans);
    }

    TEST(acwing4201, case3) {
        istringstream in("100");
        ostringstream out;
        acwing4201::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("4", ans);
    }

    TEST(acwing4201, case4) {
        istringstream in("1000");
        ostringstream out;
        acwing4201::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("8", ans);
    }

    TEST(acwing4201, case5) {
        istringstream in("10000");
        ostringstream out;
        acwing4201::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("16", ans);
    }

    TEST(acwing4201, case6) {
        istringstream in("200");
        ostringstream out;
        acwing4201::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("7", ans);
    }

    TEST(acwing4201, case7) {
        istringstream in("101");
        ostringstream out;
        acwing4201::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("5", ans);
    }

    TEST(acwing4201, case8) {
        istringstream in("1");
        ostringstream out;
        acwing4201::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("1", ans);
    }

    TEST(acwing4201, case9) {
        istringstream in("102");
        ostringstream out;
        acwing4201::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("5", ans);
    }

    TEST(acwing4201, case10) {
        istringstream in("111");
        ostringstream out;
        acwing4201::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("7", ans);
    }

    TEST(acwing4201, case11) {
        istringstream in("110");
        ostringstream out;
        acwing4201::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("6", ans);
    }

    TEST(acwing610, case1) {
        istringstream in("5\n6\n7\n8");
        ostringstream out;
        acwing610::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("DIFERENCA = -26", ans);
    }

    TEST(acwing604, case1) {
        istringstream in("2.00");
        ostringstream out;
        acwing604::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("A=12.5664", ans);
    }

    TEST(acwing606, case1) {
        istringstream in("5.0\n7.1");
        ostringstream out;
        acwing606::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("MEDIA = 6.43182", ans);
    }
}

namespace lintcode {
    namespace lintcode1214 {
        TEST(lintcode1214, case1) {
            string s = string("5F3Z-2e-9-w");
            ASSERT_EQ("5F3Z-2E9W", Solution::licenseKeyFormatting(s, 4));
        }

        TEST(lintcode1214, case2) {
            string s = string("2-5g-3-J");
            ASSERT_EQ("2-5G-3J", Solution::licenseKeyFormatting(s, 2));
        }
    }

    namespace lintcode1163 {
        TEST(lintcode1163, case1) {
            vector<int> input = vector<int>();
            input.push_back(1);
            input.push_back(1);
            input.push_back(2);
            input.push_back(2);
            input.push_back(3);
            input.push_back(3);
            ASSERT_EQ(3, Solution::distributeCandies(input));
        }

        TEST(lintcode1163, case2) {
            vector<int> input = vector<int>();
            input.push_back(1);
            input.push_back(1);
            input.push_back(2);
            input.push_back(2);
            input.push_back(3);
            input.push_back(3);
            input.push_back(4);
            input.push_back(5);
            input.push_back(6);
            input.push_back(6);
            input.push_back(7);
            input.push_back(8);
            ASSERT_EQ(6, Solution::distributeCandies(input));
        }
    }
}
