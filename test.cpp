#include "gtest/gtest.h"
#include "excel_sheet_column_title.h"
#include "majority_element.h"
#include "excel_sheet_column_number.h"
#include "acwing4200.h"
#include "acwing4201.h"

using namespace std;

namespace excel_sheet_column_title {
    TEST(excel_sheet_column_title, case1) {
        ASSERT_EQ(std::string("A"), Solution::convertToTitle(1));
    }

    TEST(excel_sheet_column_title, case2) {
        ASSERT_EQ(std::string("AB"), Solution::convertToTitle(28));
    }

    TEST(excel_sheet_column_title, case3) {
        ASSERT_EQ(std::string("ZY"), Solution::convertToTitle(701));
    }

    TEST(excel_sheet_column_title, case4) {
        ASSERT_EQ(std::string("FXSHRXW"), Solution::convertToTitle(2147483647));
    }

    TEST(excel_sheet_column_title, case5) {
        ASSERT_EQ(std::string("AZ"), Solution::convertToTitle(52));
    }
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
    TEST(excel_sheet_column_number, case1) {
        ASSERT_EQ(1, Solution::titleToNumber("A"));
    }

    TEST(excel_sheet_column_number, case2) {
        ASSERT_EQ(28, Solution::titleToNumber("AB"));
    }

    TEST(excel_sheet_column_number, case3) {
        ASSERT_EQ(701, Solution::titleToNumber("ZY"));
    }

    TEST(excel_sheet_column_number, case4) {
        ASSERT_EQ(2147483647, Solution::titleToNumber("FXSHRXW"));
    }
}

namespace acwing4200 {
    TEST(acwing4200, case1) {
        ASSERT_EQ(0, Solution::main(2, 7, 1, 8, 2, 8));
    }

    TEST(acwing4200, case2) {
        ASSERT_EQ(20, Solution::main(20, 30, 40, 50, 0, 100));
    }

    TEST(acwing4200, case3) {
        ASSERT_EQ(9, Solution::main(31, 41, 59, 26, 17, 43));
    }
}

namespace acwing4201 {
    TEST(acwing4201, case1) { ASSERT_EQ(2, Solution::main(10)); }

    TEST(acwing4201, case2) { ASSERT_EQ(3, Solution::main(20)); }

    TEST(acwing4201, case3) { ASSERT_EQ(4, Solution::main(100)); }

    TEST(acwing4201, case4) { ASSERT_EQ(8, Solution::main(1000)); }

    TEST(acwing4201, case5) { ASSERT_EQ(16, Solution::main(10000)); }

    TEST(acwing4201, case6) { ASSERT_EQ(7, Solution::main(200)); }

    TEST(acwing4201, case7) { ASSERT_EQ(5, Solution::main(101)); }

    TEST(acwing4201, case8) { ASSERT_EQ(1, Solution::main(1)); }

    TEST(acwing4201, case9) { ASSERT_EQ(5, Solution::main(102)); }

    TEST(acwing4201, case10) { ASSERT_EQ(7, Solution::main(111)); }

    TEST(acwing4201, case11) { ASSERT_EQ(6, Solution::main(110)); }
}