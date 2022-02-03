#include "luogu.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <unordered_set>
#include <vector>

using namespace std;

namespace luogu {
	int P1001::main(istream &cin, ostream &cout) {
		unsigned int a;
		unsigned int b;
		cin >> a >> b;
		cout << a + b;
		return 0;
	}

	int P1000::main(istream & /*cin*/, ostream &cout) {
		cout << "                ********\n"
		        "               ************\n"
		        "               ####....#.\n"
		        "             #..###.....##....\n"
		        "             ###.......######              ###            ###\n"
		        "                ...........               #...#          #...#\n"
		        "               ##*#######                 #.#.#          #.#.#\n"
		        "            ####*******######             #.#.#          #.#.#\n"
		        "           ...#***.****.*###....          #...#          #...#\n"
		        "           ....**********##.....           ###            ###\n"
		        "           ....****    *****....\n"
		        "             ####        ####\n"
		        "           ######        ######\n"
		        "##############################################################\n"
		        "#...#......#.##...#......#.##...#......#.##------------------#\n"
		        "###########################################------------------#\n"
		        "#..#....#....##..#....#....##..#....#....#####################\n"
		        "##########################################    #----------#\n"
		        "#.....#......##.....#......##.....#......#    #----------#\n"
		        "##########################################    #----------#\n"
		        "#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#\n"
		        "##########################################    ############";
		return 0;
	}

	int P1008::main(istream & /*cin*/, ostream &cout) {
		for(unsigned short i = 1; i <= 3; i++) {
			for(unsigned short j = 1; j <= 9; j++) {
				if(j == i) {
					continue;
				}
				for(unsigned short k = 1; k <= 9; k++) {
					if(k == i || k == j || k * 2 % 10 == j || k * 2 % 10 == i || k * 3 % 10 == j || k * 3 % 10 == i || k == 5) {
						continue;
					}
					const unsigned short num = 100 * i + 10 * j + k;
					if(num > 333) {
						continue;
					}
					unsigned short num2 = 2 * num;
					unsigned short num3 = 3 * num;
					auto um             = unordered_set<unsigned short>();
					um.insert(i);
					um.insert(j);
					um.insert(k);
					unsigned short n = num2 % 10;

					if(um.contains(n) || n == 0) {
						continue;
					}
					um.insert(n);
					num2 /= 10;
					n = num2 % 10;
					if(um.contains(n) || n == 0) {
						continue;
					}
					um.insert(n);
					num2 /= 10;
					n = num2 % 10;
					if(um.contains(n) || n == 0) {
						continue;
					}
					um.insert(n);

					n = num3 % 10;
					if(um.contains(n) || n == 0) {
						continue;
					}
					um.insert(n);
					num3 /= 10;
					n = num3 % 10;
					if(um.contains(n) || n == 0) {
						continue;
					}
					um.insert(n);
					num3 /= 10;
					n = num3 % 10;
					if(um.contains(n) || n == 0) {
						continue;
					}
					um.insert(n);
					cout << num << " " << num * 2 << " " << num * 3 << endl;
				}
			}
		}
		return 0;
	}

	int P1002::main(istream &cin, ostream &cout) {
		int n;
		int m;
		int cx;
		int cy;
		cin >> n >> m >> cx >> cy;
		unsigned long long board[21][21] = {};
		board[0][0]                      = 1;
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= m; j++) {
				if(abs(cx - i) * abs(cy - j) == 2 || i == cx && j == cy) {
					board[i][j] = 0;
					continue;
				}
				if(i - 1 >= 0) {
					board[i][j] += board[i - 1][j];
				}
				if(j - 1 >= 0) {
					board[i][j] += board[i][j - 1];
				}
			}
		}
		cout << board[n][m];
		return 0;
	}

	int P1003::main(istream &cin, ostream &cout) {
		auto as = vector<unsigned int>();
		auto bs = vector<unsigned int>();
		auto gs = vector<unsigned int>();
		auto ks = vector<unsigned int>();
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			unsigned int a;
			unsigned int b;
			unsigned int g;
			unsigned int k;
			cin >> a >> b >> g >> k;
			as.push_back(a);
			bs.push_back(b);
			gs.push_back(g);
			ks.push_back(k);
		}
		unsigned int x;
		unsigned int y;
		cin >> x >> y;
		for(int i = n - 1; i >= 0; i--) {
			if(as[i] <= x && x <= as[i] + gs[i] && bs[i] <= y && y <= bs[i] + ks[i]) {
				cout << i + 1;
				return 0;
			}
		}
		cout << -1;
		return 0;
	}

	int P5703::main(istream &cin, ostream &cout) {
		unsigned long a;
		unsigned long b;
		cin >> a >> b;
		cout << a * b;
		return 0;
	}

	int P5704::main(istream &cin, ostream &cout) {
		char ch;
		cin >> ch;
		cout << static_cast<char>(toupper(ch));
		return 0;
	}

	int P5705::main(istream &cin, ostream &cout) {
		string s;
		cin >> s;
		for(int i = s.length() - 1; i >= 0; i--) {
			cout << s[i];
		}
		return 0;
	}

	int P5706::main(istream &cin, ostream &cout) {
		double t;
		int n;
		cin >> t >> n;
		cout << setiosflags(ios::fixed) << setprecision(3) << t / n << endl
		     << n * 2;
		return 0;
	}

	int P1425::main(istream &cin, ostream &cout) {
		int a;
		int b;
		int c;
		int d;
		cin >> a >> b >> c >> d;
		const int diff = (c - a) * 60 + d - b;
		cout << diff / 60 << " " << diff % 60;
		return 0;
	}

	int P2433::main(istream &cin, ostream &cout) {
		int T;
		cin >> T;
		if(T == 1) {
			cout << "I love Luogu!";
		} else if(T == 2) {
			cout << 2 + 4 << " " << 10 - 2 - 4;
		} else if(T == 3) {
			cout << 14 / 4 << endl
			     << 14 / 4 * 4 << endl
			     << 14 % 4;
		} else if(T == 4) {
			cout << setiosflags(ios::fixed) << setprecision(3) << 500.0 / 3.0;
		} else if(T == 5) {
			cout << (260 + 220) / (12 + 20);
		} else if(T == 6) {
			cout << sqrt(6 * 6 + 9 * 9);
		} else if(T == 7) {
			int deposit = 100;
			deposit += 10;
			cout << deposit << endl;
			deposit -= 20;
			cout << deposit << endl;
			deposit = 0;
			cout << deposit << endl;
		} else if(T == 8) {
			cout << 2 * 5 * 3.141593 << endl;
			cout << 5 * 5 * 3.141593 << endl;
			cout << 4 * 5 * 5 * 5 * 3.141593 / 3 << endl;
		} else if(T == 9) {
			const int peach = 1;
			cout << (((peach + 1) * 2 + 1) * 2 + 1) * 2;
		} else if(T == 10) {
			cout << 90 / 10;
		} else if(T == 11) {
			cout << 100.0 / 3.0;
		} else if(T == 12) {
			cout << 'M' - 'A' + 1 << endl;
			cout << static_cast<char>('A' - 1 + 18);
		} else if(T == 13) {
			const double r1 = 4;
			const double r2 = 10;
			const double v1 = 4 * r1 * r1 * r1 * 3.141593 / 3;
			const double v2 = 4 * r2 * r2 * r2 * 3.141593 / 3;
			cout << static_cast<int>(pow(v1 + v2, 1.0 / 3.0));
		} else if(T == 14) {
			cout << 50;
		}
		return 0;
	}

	int P5708::main(istream &cin, ostream &cout) {
		double a;
		double b;
		double c;
		cin >> a >> b >> c;
		const double p = (a + b + c) / 2;
		cout << setiosflags(ios::fixed) << setprecision(1) << sqrt(p * (p - a) * (p - b) * (p - c));
		return 0;
	}

	int P1421::main(istream &cin, ostream &cout) {
		int a;
		int b;
		cin >> a >> b;
		cout << (10 * a + b) / 19;
		return 0;
	}

	int P5709::main(istream &cin, ostream &cout) {
		int m;
		int t;
		int s;
		cin >> m >> t >> s;
		if(t == 0) {
			cout << 0;
			return 0;
		}
		int eaten = s / t;
		if(t * eaten != s) {
			eaten++;
		}
		cout << max(0, m - eaten);
		return 0;
	}

	int P2181::main(istream &cin, ostream &cout) {
		unsigned long long n;
		unsigned long long count = 0;
		cin >> n;
		for(long long i = 1; i <= n - 2; i++) {
			count += i * (n - 2 - i);
		}
		count *= n;
		count /= 4;
		cout << count;
		return 0;
	}

	int P5707::main(istream &cin, ostream &cout) {
		unsigned int s;
		unsigned int v;
		cin >> s >> v;
		double t = 8 * 60 - (static_cast<double>(s) / static_cast<double>(v) + 10);
		if(t < 0) {
			t += 24 * 60;
		}
		const int h = static_cast<int>(t / 60);
		const int m = static_cast<int>(t) % 60;
		if(h < 10) {
			cout << 0;
		}
		cout << h << ":";
		if(m < 10) {
			cout << 0;
		}
		cout << m;
		return 0;
	}

	int P3954::main(istream &cin, ostream &cout) {
		unsigned short a;
		unsigned short b;
		unsigned short c;
		cin >> a >> b >> c;
		cout << (a * 2 + b * 3 + c * 5) / 10;
		return 0;
	}

	int P5710::main(istream &cin, ostream &cout) {
		unsigned short x;
		cin >> x;
		const bool b1 = x % 2 == 0;
		const bool b2 = x > 4 && x <= 12;
		cout << static_cast<int>(b1 && b2) << " " << static_cast<int>(b1 || b2) << " " << (b1 xor b2) << " " << static_cast<int>(!b1 && !b2);
		return 0;
	}

	int P5711::main(istream &cin, ostream &cout) {
		unsigned int year;
		cin >> year;
		if(year % 4 == 0) {
			//是4的倍数
			if(year % 100 == 0) {
				//是100的倍数
				if(year % 400 == 0) {
					//是400的倍数
					cout << "1";
					return 0;
				}
				//不是400的倍数
				cout << "0";
				return 0;
			}
			//不是100的倍数
			cout << "1";
			return 0;
		}
		//不是4的倍数
		cout << "0";
		return 0;
	}

	int P5712::main(istream &cin, ostream &cout) {
		unsigned short x;
		cin >> x;
		cout << "Today, I ate " << x << " apple";
		if(x > 1) {
			cout << "s";
		}
		cout << ".";
		return 0;
	}

	int P5713::main(istream &cin, ostream &cout) {
		unsigned int n;
		cin >> n;
		const unsigned int local = n * 5;
		const unsigned int luogu = 11 + 3 * n;
		if(local < luogu) {
			cout << "Local";
		} else {
			cout << "Luogu";
		}
		return 0;
	}

	int P5715::main(istream &cin, ostream &cout) {
		unsigned int abc[3];
		cin >> abc[0] >> abc[1] >> abc[2];
		sort(abc, abc + 3);
		for(const auto i: abc) {
			cout << i << " ";
		}
		return 0;
	}

	int P5714::main(istream &cin, ostream &cout) {
		double m;
		double n;
		cin >> m >> n;
		const double bmi = m / (n * n);
		if(bmi < 18.5) {
			cout << "Underweight";
		} else if(bmi >= 18.5 && bmi < 24) {
			cout << "Normal";
		} else {
			cout << bmi << endl
			     << "Overweight";
		}
		return 0;
	}

	int P5716::main(istream &cin, ostream &cout) {
		int year;
		int month;
		cin >> year >> month;
		const bool bissextile = year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
		if(month == 4 || month == 6 || month == 9 || month == 11) {
			cout << 30;
		} else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			cout << 31;
		} else if(bissextile) {
			cout << 29;
		} else {
			cout << 28;
		}
		return 0;
	}

	int P1085::main(istream &cin, ostream &cout) {
		unsigned short a;
		unsigned short b;
		unsigned int maximum   = 0;
		unsigned int maximum_i = 0;
		unsigned int i         = 0;
		while(cin >> a && cin >> b) {
			i++;
			if(a + b > 8 && a + b > maximum) {
				maximum_i = i;
				maximum   = a + b;
			}
		}
		cout << maximum_i;
		return 0;
	}

	int P1909::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		int num;
		int price;
		int minimum = -1;
		for(int i = 0; i < 3; i++) {
			cin >> num >> price;
			int count = n / num;
			if(n % num != 0) {
				count++;
			}
			int sum = count * price;
			minimum = minimum == -1 ? sum : min(minimum, sum);
		}
		cout << minimum;
		return 0;
	}

	int P1055::main(istream &cin, ostream &cout) {
		string isbn;
		cin >> isbn;
		const string isbn_prefix = isbn.substr(0, isbn.length() - 1);
		int sum                  = 0;
		int count                = 1;
		for(const char ch: isbn_prefix) {
			if(isdigit(ch) != 0) {
				sum += (ch - '0') * count++;
				sum %= 11;
			}
		}
		sum %= 11;
		int end = *isbn.rbegin() - '0';
		if(end == 'X' - '0') {
			end = 10;
		}
		if(sum == end) {
			cout << "Right";
		} else {
			end = sum;
			if(sum == 10) {
				end = 'X' - '0';
			}
			cout << isbn_prefix << static_cast<char>(end + '0');
		}
		return 0;
	}

	int P1422::main(istream &cin, ostream &cout) {
		double fee = 0;
		int power;
		cin >> power;
		cout << setiosflags(ios::fixed) << setprecision(1);
		if(power <= 150) {
			fee = power * 0.4463;
		} else if(power <= 400) {
			fee = 150 * 0.4463 + (power - 150) * 0.4663;
		} else {
			fee = 150 * 0.4463 + (400 - 150) * 0.4663 + (power - 400) * 0.5663;
		}
		cout << floor(fee * 10 + 0.5) / 10;
		return 0;
	}

	int P1424::main(istream &cin, ostream &cout) {
		unsigned short x;
		unsigned int n;
		cin >> x >> n;
		x--;
		unsigned int count = n / 7 * 5 * 250;
		n %= 7;
		for(unsigned int i = 0; i < n; i++) {
			if((x + i) % 7 < 5) {
				count += 250;
			}
		}
		cout << count;
		return 0;
	}

	int P1888::main(istream &cin, ostream &cout) {
		int a;
		int b;
		int c;
		cin >> a >> b >> c;
		int maximum = a;
		int minimum = a;
		maximum     = max(maximum, b);
		maximum     = max(maximum, c);
		minimum     = min(minimum, b);
		minimum     = min(minimum, c);
		const int g = gcd(maximum, minimum);
		cout << minimum / g << "/" << maximum / g;
		return 0;
	}

	int P1888::gcd(int m, int n) {
		int r = m;
		while(r != 0) {
			r = m % n;
			m = n;
			n = r;
		}
		return m;
	}

	int P1046::main(istream &cin, ostream &cout) {
		int h[10];
		for(int &i: h) {
			cin >> i;
		}
		int t;
		cin >> t;
		t += 30;
		int count = 0;
		for(const int i: h) {
			if(t >= i) {
				count++;
			}
		}
		cout << count;
		return 0;
	}

	int P5717::main(istream &cin, ostream &cout) {
		unsigned int e[3];
		cin >> e[0] >> e[1] >> e[2];
		sort(e, e + 3);
		if(e[0] + e[1] <= e[2]) {
			cout << "Not triangle" << endl;
		} else {
			unsigned int e02 = e[0] * e[0];
			unsigned int e12 = e[1] * e[1];
			unsigned int e22 = e[2] * e[2];
			if(e02 + e12 == e[2] * e[2]) {
				cout << "Right triangle" << endl;
			} else if(e02 + e12 > e22) {
				cout << "Acute triangle" << endl;
			} else if(e02 + e12 < e22) {
				cout << "Obtuse triangle" << endl;
			}
			if(e[0] == e[1]) {
				cout << "Isosceles triangle" << endl;
				if(e[1] == e[2]) {
					cout << "Equilateral triangle" << endl;
				}
			}
		}
		return 0;
	}

	int P4414::main(istream &cin, ostream &cout) {
		unsigned int num[3];
		cin >> num[0] >> num[1] >> num[2];
		unsigned a = 100, b, c = 0;
		for(unsigned int i: num) {
			if(a > i) {
				a = i;
			}
			if(c < i) {
				c = i;
			}
		}
		for(unsigned int i: num) {
			if(i != a && i != c) {
				b = i;
			}
		}
		char ch;
		for(int i = 0; i < 3; i++) {
			cin >> ch;
			if(ch == 'A') {
				cout << a << " ";
			} else if(ch == 'B') {
				cout << b << " ";
			} else {
				cout << c << " ";
			}
		}
		return 0;
	}
}// namespace luogu
