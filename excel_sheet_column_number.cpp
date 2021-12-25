//
// Created by tategotoazarasi on 2021/12/25.
//

#include "excel_sheet_column_number.h"
#include<string>
#include<cmath>

using namespace excel_sheet_column_number;

namespace excel_sheet_column_number {
    int Solution::titleToNumber(const std::string &columnTitle) {
        int sum = 0;
        int length = static_cast<int>(columnTitle.length());
        for (char c: columnTitle) {
            sum += static_cast<int>(static_cast<double>(c - 'A' + 1) * pow(26, length-- - 1));
        }
        return sum;
    }
}

