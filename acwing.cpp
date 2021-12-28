//
// Created by tategotoazarasi on 2021/12/28.
//

#include "acwing.h"
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

namespace acwing {
    void acwing1::main(istream &cin, ostream &cout) {
        int a, b;
        cin >> a >> b;
        cout << a + b;
    }

    void acwing4200::main(istream &cin, ostream &cout) {
        int p1, p2, p3, p4, a, b;
        cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
        int min = p1;
        min = p2 < min ? p2 : min;
        min = p3 < min ? p3 : min;
        min = p4 < min ? p4 : min;
        int ans = (min - a) < (b - a + 1) ? min - a : b - a + 1;
        cout << (ans < 0 ? 0 : ans);
    }

    void acwing4201::main(istream &cin, ostream &cout) {
        int number;
        cin >> number;
        int copy = number;
        int len = 0;
        while (copy != 0) {
            copy /= 10;
            len++;
        }
        vector<int> arr = vector<int>(len);
        copy = number;
        for (int i = len - 1; i >= 0; i--) {
            arr[i] = copy % 10;
            copy /= 10;
        }

        int sum = static_cast<int>(pow(2, len));
        for (int i = 0; i < len; i++) {
            if (arr[i] > 1) {
                break;
            } else if (arr[i] == 0) {
                sum -= static_cast<int>(pow(2, len - i - 1));
            }
        }
        cout << --sum;
    }

    void acwing610::main(istream &cin, ostream &cout) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << "DIFERENCA = " << a * b - c * d;
    }
}