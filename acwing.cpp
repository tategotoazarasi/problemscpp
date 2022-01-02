//
// Created by tategotoazarasi on 2021/12/28.
//

#include "acwing.h"
#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<set>

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

    int acwing609::main(istream &cin, ostream &cout) {
        int a;
        double b, c;
        cin >> a >> b >> c;
        cout << "NUMBER = " << a << endl << "SALARY = U$ " << setiosflags(ios::fixed) << setprecision(2) << b * c;
        return 0;
    }

    int acwing615::main(istream &cin, ostream &cout) {
        int x;
        float y;
        cin >> x >> y;
        cout << setiosflags(ios::fixed) << setprecision(3) << static_cast<float>(x) / y << " km/l";
        return 0;
    }

    int acwing616::main(istream &cin, ostream &cout) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << setiosflags(ios::fixed) << setprecision(4) << sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        return 0;
    }

    int acwing653::main(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        cout << n << endl;
        int arr[] = {100, 50, 20, 10, 5, 2, 1};
        for (int i: arr) {
            cout << n / i << " nota(s) de R$ " << i << ",00";
            if (i != 1) {
                cout << endl;
            }
            n %= i;
        }
        return 0;
    }

    int acwing4203::main(istream &cin, ostream &cout) {
        string str;
        cin >> str;
        int count0 = 0;
        int count1 = 0;
        for (char c: str) {
            if (c == '1') {
                count1++;
                count0 = 0;
            } else {
                count0++;
                count1 = 0;
            }
            if (count1 == 7 || count0 == 7) {
                cout << "YES";
                return 0;
            }
        }
        cout << "NO";
        return 0;
    }

    int acwing4204::main(istream &cin, ostream &cout) {
        int n;
        const int N = 1010;
        int g[N][N];
        cin >> n;
        for (int i = 1; i <= n; i++) {
            g[1][i] = i - 1;
            g[i][1] = i - 1;
        }
        for (int i = 2; i < n; i++) {
            for (int j = 2; j < n; j++) {
                if (i == j) {
                    g[i][j] = 0;//对角线为0
                } else {
                    if (g[i][j - 1] == 0) {//在0后面一格
                        g[i][j] = g[i - 1][j] + 1;//上面一格的值+1
                    } else {//否则
                        g[i][j] = g[i][j - 1] + 1;  //前面一格的值+1
                    }
                    if (g[i][j] == n) {//达到上限
                        g[i][j] = 1;//回归到1
                    }
                }
            }
        }
        for (int i = 1; i < n; i++) {
            set<int> s;
            for (int j = 1; j < n; j++) {
                s.insert(g[i][j]);
            }
            for (int j = 0; j < n; j++) {
                if (!s.count(j)) {
                    g[i][n] = g[n][i] = j;  //补最后一列和最后一行的值
                }
            }
        }

        //输出
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << g[i][j];
                if (j != n) {
                    cout << " ";
                }
            }
            if (i != n) {
                cout << endl;
            }
        }
        return 0;
    }

    int acwing2058::main(istream &cin, ostream &cout) {
        string n2, n3;
        cin >> n2 >> n3;
        auto s = set<long long>();

        for (int i = 0; i < n2.length(); i++) {
            long long val = 0;
            for (int j = 0; j < n2.length(); j++) {
                bool bit = n2[j] != '0';
                if (j == i) {
                    bit = !bit;
                }
                if (bit) {
                    val += static_cast<long long>(pow(2, n2.size() - j - 1));
                }
            }
            s.insert(val);
        }

        for (int n = 1; n <= 2; n++) {
            for (int i = 0; i < n3.length(); i++) {
                long long val = 0;
                for (int j = 0; j < n3.length(); j++) {
                    int v = n3[j] - '0';
                    if (i == j) {
                        v += n;
                        v %= 3;
                    }
                    val += static_cast<long long>(v * pow(3, n3.size() - j - 1));
                }
                if (s.find(val) != s.end()) {
                    cout << val;
                    return 0;
                }
                s.insert(val);
            }
        }
        return 0;
    }

    int acwing654::main(istream &cin, ostream &cout) {
        int n;
        int h, m, s;
        cin >> n;
        s = n % 60;
        n /= 60;
        m = n % 60;
        n /= 60;
        h = n;
        cout << h << ":" << m << ":" << s;
        return 0;
    }

    int acwing605::main(istream &cin, ostream &cout) {
        int a, b;
        cin >> a >> b;
        cout << "PROD = " << a * b;
        return 0;
    }
}