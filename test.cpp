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
            basic_string<char> input[] = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat",
                                          "ratcatdogcat"};
            vector<basic_string<char>> vec = vector<basic_string<char >>(begin(input), end(input));
            auto ans = Solution::findAllConcatenatedWordsInADict(vec);
            string outputstr[] = {"catsdogcats", "dogcatsdog", "ratcatdogcat"};
            vector<string> output = vector<string>(begin(outputstr), end(outputstr));
            for (const string &str: ans) {
                ASSERT_TRUE(find(output.cbegin(), output.cend(), str) != output.cend());
            }
            for (const string &str: output) {
                ASSERT_TRUE(find(ans.cbegin(), ans.cend(), str) != ans.cend());
            }
            ASSERT_EQ(ans.size(), output.size());
        }

        TEST(concatenated_words, case2) {
            basic_string<char> input[] = {"cat", "dog", "catdog"};
            vector<basic_string<char>> vec = vector<basic_string<char >>(begin(input), end(input));
            auto ans = Solution::findAllConcatenatedWordsInADict(vec);
            string outputstr[] = {"catdog"};
            vector<string> output = vector<string>(begin(outputstr), end(outputstr));
            for (const string &str: ans) {
                ASSERT_TRUE(find(output.cbegin(), output.cend(), str) != output.cend());
            }
            for (const string &str: output) {
                ASSERT_TRUE(find(ans.cbegin(), ans.cend(), str) != ans.cend());
            }
            ASSERT_EQ(ans.size(), output.size());
        }

        TEST(concatenated_words, case4) {
            basic_string<char> input[] = {"nuqhmfj", "mf", "jf", "n", "u", "q", "h"};
            vector<basic_string<char>> vec = vector<basic_string<char >>(begin(input), end(input));
            auto ans = Solution::findAllConcatenatedWordsInADict(vec);
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
            int input[] = {1, 2, 3, 6};
            vector<int> vec = vector<int>(begin(input), end(input));
            ASSERT_EQ(1, Solution::countQuadruplets(vec));
        }

        TEST(count_special_quadruplets, case2) {
            int input[] = {3, 3, 6, 4, 5};
            vector<int> vec = vector<int>(begin(input), end(input));
            ASSERT_EQ(0, Solution::countQuadruplets(vec));
        }

        TEST(count_special_quadruplets, case3) {
            int input[] = {1, 1, 1, 3, 5};
            vector<int> vec = vector<int>(begin(input), end(input));
            ASSERT_EQ(4, Solution::countQuadruplets(vec));
        }

        TEST(count_special_quadruplets, case4) {
            int input[] = {28, 8, 49, 85, 37, 90, 20, 8};
            vector<int> vec = vector<int>(begin(input), end(input));
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

    namespace perfect_number {
        TEST(perfect_number, case1) {
            ASSERT_TRUE(Solution::checkPerfectNumber(28));
        }

        TEST(perfect_number, case2) {
            ASSERT_TRUE(Solution::checkPerfectNumber(6));
        }

        TEST(perfect_number, case3) {
            ASSERT_TRUE(Solution::checkPerfectNumber(496));
        }

        TEST(perfect_number, case4) {
            ASSERT_TRUE(Solution::checkPerfectNumber(8128));
        }

        TEST(perfect_number, case5) {
            ASSERT_FALSE(Solution::checkPerfectNumber(2));
        }
    }

    namespace convert_bst_to_greater_tree {
        TEST(convert_bst_to_greater_tree, case1) {
            auto input = new TreeNode(4, new TreeNode(1, new TreeNode(0), new TreeNode(2, nullptr, new TreeNode(3))),
                                      new TreeNode(6, new TreeNode(5), new TreeNode(7, nullptr, new TreeNode(8))));
            auto ans = new TreeNode(30, new TreeNode(36, new TreeNode(36), new TreeNode(35, nullptr, new TreeNode(33))),
                                    new TreeNode(21, new TreeNode(26), new TreeNode(15, nullptr, new TreeNode(8))));
            auto output = Solution::convertBST(input);
            ASSERT_TRUE((*ans) == (*output));
        }
    }

    namespace convert_1d_array_into_2d_array {
        TEST(convert_1d_array_into_2d_array, case1) {
            int input[4] = {1, 2, 3, 4};
            auto vec = vector<int>(begin(input), end(input));
            auto ans = Solution::construct2DArray(vec, 2, 2);
            int output1[] = {1, 2};
            int output2[] = {3, 4};
            auto vec1 = vector<int>(begin(output1), end(output1));
            auto vec2 = vector<int>(begin(output2), end(output2));
            auto vec_output = vector<vector<int>>();
            vec_output.push_back(vec1);
            vec_output.push_back(vec2);
            ASSERT_EQ(vec_output, ans);
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

    TEST(acwing609, case1) {
        istringstream in("25\n100\n5.50");
        ostringstream out;
        acwing609::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("NUMBER = 25\n"
                  "SALARY = U$ 550.00", ans);
    }

    TEST(acwing615, case1) {
        istringstream in("500\n35.0");
        ostringstream out;
        acwing615::main(in, out);
        auto ans = out.str();
        ASSERT_EQ("14.286 km/l", ans);
    }
}

namespace lintcode {
    namespace license_key_formatting {
        TEST(license_key_formatting, case1) {
            string s = string("5F3Z-2e-9-w");
            ASSERT_EQ("5F3Z-2E9W", Solution::licenseKeyFormatting(s, 4));
        }

        TEST(license_key_formatting, case2) {
            string s = string("2-5g-3-J");
            ASSERT_EQ("2-5G-3J", Solution::licenseKeyFormatting(s, 2));
        }
    }

    namespace distribute_candies {
        TEST(distribute_candies, case1) {
            int input[] = {1, 1, 2, 2, 3, 3,};
            vector<int> vec = vector<int>(begin(input), end(input));
            ASSERT_EQ(3, Solution::distributeCandies(vec));
        }

        TEST(distribute_candies, case2) {
            int input[] = {1, 1, 2, 2, 3, 3, 4, 5, 6, 6, 7, 8};
            vector<int> vec = vector<int>(begin(input), end(input));
            ASSERT_EQ(6, Solution::distributeCandies(vec));
        }
    }

    namespace remove_extra {
        TEST(remove_extra, case1) {
            string input = "The  sky   is blue";
            ASSERT_EQ("The sky is blue", Solution::removeExtra(input));
        }

        TEST(remove_extra, case2) {
            string input = "  low               ercase  ";
            ASSERT_EQ("low ercase", Solution::removeExtra(input));
        }
    }
}
