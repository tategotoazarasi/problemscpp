#include "gtest/gtest.h"
#include "excel_sheet_column_title.h"
#include "majority_element.h"

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