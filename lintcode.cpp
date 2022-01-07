//
// Created by tategotoazarasi on 2021/12/29.
//

#include "lintcode.h"

#include <string>
#include <sstream>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;

namespace lintcode {
    namespace license_key_formatting {
        string Solution::licenseKeyFormatting(string &S, int K) {
            auto S2 = ostringstream();
            auto output = ostringstream();
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

    namespace distribute_candies {
        int Solution::distributeCandies(vector<int> &candies) {
            auto m = map<long, int>();
            auto ans = set<int>();
            int n = static_cast<int>(candies.size()) / 2;
            int sum = 0;
            for (auto candy: candies) {
                m[candy]++;
            }
            while (sum < n) {
                for (auto candy: m) {
                    if (candy.second != 0) {
                        if (!ans.contains(static_cast<int>(candy.first))) {
                            ans.insert(static_cast<int>(candy.first));
                            if (ans.size() == m.size()) {
                                return static_cast<int>(ans.size());
                            }
                        }
                        candy.second--;
                        sum++;
                    }
                    if (sum >= n) {
                        break;
                    }
                }
            }
            return static_cast<int>(ans.size());
        }
    }

    namespace remove_extra {
        string Solution::removeExtra(string &s) {
            auto output = ostringstream();
            bool start = true;
            bool flag = false;
            for (char c: s) {
                if (c != ' ') {
                    if (flag && !start) {
                        output << ' ';
                    }
                    output << c;
                    start = false;
                    flag = false;
                } else {
                    flag = true;
                }
            }
            return output.str();
        }
    }

    namespace fibonacci {
        int Solution::fibonacci(int n) {
            auto arr = new int[n];
            arr[0] = 0;
            arr[1] = 1;
            for (int i = 2; i < n; i++) {
                arr[i] = arr[i - 1] + arr[i - 2];
            }
            return arr[n - 1];
        }
    }

    namespace character_deletion {
        string Solution::CharacterDeletion(string &str, string &sub) {
            auto oss = ostringstream();
            auto us = unordered_set<char>();
            for (auto ch: sub) {
                us.insert(ch);
            }
            for (auto ch: str) {
                if (!us.contains(ch)) {
                    oss << ch;
                }
            }
            return oss.str();
        }
    }

    namespace judge_circle {
        bool Solution::judgeCircle(string &moves) {
            int x = 0;
            int y = 0;
            for (char ch: moves) {
                switch (ch) {
                    case 'R':
                        x--;
                        break;
                    case 'L':
                        x++;
                        break;
                    case 'U':
                        y--;
                        break;
                    case 'D':
                        y++;
                        break;
                    default:
                        break;
                }
            }
            return x == 0 && y == 0;
        }
    }
}
