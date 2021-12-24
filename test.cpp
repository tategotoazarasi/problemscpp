#include "excel_sheet_column_title.h"
#include "gtest/gtest.h"

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