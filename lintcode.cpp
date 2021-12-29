//
// Created by tategotoazarasi on 2021/12/29.
//

#include "lintcode.h"

#include <string>
#include <sstream>

using namespace std;

namespace lintcode {
    namespace lintcode1214 {
        string Solution::licenseKeyFormatting(string &S, int K) {
            ostringstream S2 = ostringstream();
            ostringstream output = ostringstream();
            int len = 0;
            for (char c: S) {
                if (isalnum(c)) {
                    len++;
                    if (isdigit(c) || isupper(c)) {
                        S2 << c;
                    } else if (islower(c)) {
                        S2 << static_cast<char>(toupper(c));
                    }
                }
            }
            string str = S2.str();
            int first = len % K;
            int average = len / K;
            if (first == 0) {
                first = K;
            }
            string str1 = str.substr(0, first);
            string str2 = str.substr(first);
            for (char c: str1) {
                output << c;
            }
            int count = 0;
            for (char c: str2) {
                if (count == 0) {
                    output << '-';
                }
                output << c;
                count++;
                count %= K;
            }
            return output.str();
        }
    }
}