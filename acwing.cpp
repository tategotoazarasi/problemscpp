//
// Created by tategotoazarasi on 2021/12/28.
//

#include "acwing.h"
#include<iostream>
#include<vector>
#include<cmath>
#include <iomanip>

using namespace std;

namespace acwing {
    int acwing1::main(istream &cin, ostream &cout) {
        int a, b;
        cin >> a >> b;
        cout << a + b;
        return 0;
    }

    int acwing4200::main(istream &cin, ostream &cout) {
        int p1, p2, p3, p4, a, b;
        cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
        int min = p1;
        min = p2 < min ? p2 : min;
        min = p3 < min ? p3 : min;
        min = p4 < min ? p4 : min;
        int ans = (min - a) < (b - a + 1) ? min - a : b - a + 1;
        cout << (ans < 0 ? 0 : ans);
        return 0;
    }

    int acwing4201::main(istream &cin, ostream &cout) {
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
        return 0;
    }

    int acwing610::main(istream &cin, ostream &cout) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << "DIFERENCA = " << a * b - c * d;
        return 0;
    }

    int acwing604::main(istream &cin, ostream &cout) {
        const double pi = 3.14159;
        double r;
        cin >> r;
        cout << "A=" << setiosflags(ios::fixed) << setprecision(4) << pi * r * r;
        return 0;
    }

    int acwing606::main(istream &cin, ostream &cout) {
        double a, b;
        cin >> a >> b;
        cout << "MEDIA = " << setiosflags(ios::fixed) << setprecision(5) << (a * 3.5 + b * 7.5) / 11;
        return 0;
    }
}