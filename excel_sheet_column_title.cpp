#include "excel_sheet_column_title.h"

using namespace excel_sheet_column_title;
using std::string;

namespace excel_sheet_column_title {
    string Solution::convertToTitle(int columnNumber) {
        string ans = string();
        bool round = false;
        while (columnNumber != 0) {
            char ch;
            if (round) {
                ch = static_cast<char>(columnNumber % 26 + 63);
                round = false;
            } else ch = static_cast<char>(columnNumber % 26 + 64);
            if (ch == '@' && columnNumber >= 26) {
                ch = 'Z';
                round = true;
            } else if (ch == '?' && columnNumber >= 26) {
                ch = 'Y';
                round = true;
            }
            if ('A' <= ch && ch <= 'Z') {
                ans.insert(0, 1, ch);
            }
            columnNumber /= 26;
        }
        return ans;
    }
}