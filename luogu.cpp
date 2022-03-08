#include "luogu.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <numeric>
#include <set>
#include <sstream>
#include <unordered_map>
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
			const unsigned int e02 = e[0] * e[0];
			const unsigned int e12 = e[1] * e[1];
			const unsigned int e22 = e[2] * e[2];
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
		unsigned a = 100;
		unsigned b;
		unsigned c = 0;
		for(const unsigned int i: num) {
			if(a > i) {
				a = i;
			}
			if(c < i) {
				c = i;
			}
		}
		for(const unsigned int i: num) {
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

	int P5718::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		int minimum = 1000;
		int a;
		for(int i = 0; i < n; i++) {
			cin >> a;
			minimum = min(minimum, a);
		}
		cout << minimum;
		return 0;
	}

	int P5719::main(istream &cin, ostream &cout) {
		int n;
		int k;
		cin >> n >> k;
		int sum_a   = 0;
		int count_a = 0;
		int sum_b   = 0;
		int count_b = 0;
		for(int i = 1; i <= n; i++) {
			if(i % k == 0) {
				sum_a += i;
				count_a++;
			} else {
				sum_b += i;
				count_b++;
			}
		}
		cout << fixed << setprecision(1) << static_cast<double>(sum_a) / static_cast<double>(count_a) << " " << static_cast<double>(sum_b) / static_cast<double>(count_b);
		return 0;
	}

	int P5720::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		int i = 1;
		while(n != 1) {
			n >>= 1;
			i++;
		}
		cout << i;
		return 0;
	}

	int P5721::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		int count = 1;
		for(int i = n; i >= 1; i--) {
			for(int j = 0; j < i; j++) {
				cout << setw(2) << setfill('0') << right << count++;
			}
			cout << endl;
		}
		return 0;
	}

	int P1009::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		const string ans[] = {"", "1", "3", "9", "33", "153", "873", "5913", "46233", "409113", "4037913", "43954713", "522956313", "6749977113", "93928268313", "1401602636313", "22324392524313", "378011820620313", "6780385526348313", "128425485935180313", "2561327494111820313", "53652269665821260313", "1177652997443428940313", "27029669736328405580313", "647478071469567844940313", "16158688114800553828940313", "419450149241406189412940313", "11308319599659758350180940313", "316196664211373618851684940313", "9157958657951075573395300940313", "274410818470142134209703780940313", "8497249472648064951935266660940313", "271628086406341595119153278820940313", "8954945705218228090637347680100940313", "304187744744822368938255957323620940313", "10637335711130967298604907294846820940313", "382630662501032184766604355445682020940313", "14146383753727377231082583937026584420940313", "537169001220328488991089808037100875620940313", "20935051082417771847631371547939998232420940313", "836850334330315506193242641144055892504420940313", "34289376947494122614363304694584807557656420940313", "1439295494700374021157505910939096377494040420940313", "61854558558074209658512637979453093884758552420940313", "2720126133346522977702138448994068984204397080420940313", "122342346998826717539665299944651784048588130840420940313", "5624964506810915667389970728744906677010239883800420940313", "264248206017979096310354325882356886646207872272920420940313", "12678163798554051767172643373255731925167694226950680420940313", "620960027832821612639424806694551108812720525606160920420940313", "31035053229546199656252032972759319953190362094566672920420940313"};
		cout << ans[n];
		return 0;
	}

	int P1980::main(istream &cin, ostream &cout) {
		int n;
		char x;
		cin >> n >> x;
		auto oss = ostringstream();
		for(int i = 1; i <= n; i++) {
			oss << i;
		}
		const string str = oss.str();
		int ans          = 0;
		for(const char ch: str) {
			if(ch == x) {
				ans++;
			}
		}
		cout << ans;
		return 0;
	}

	int P1035::main(istream &cin, ostream &cout) {
		int k;
		cin >> k;
		int n    = 1;
		double s = 0;
		while(s <= k) {
			s += 1.0 / static_cast<double>(n++);
		}
		cout << n - 1;
		return 0;
	}

	int P2669::main(istream &cin, ostream &cout) {
		unsigned int k;
		unsigned int coin = 0;
		unsigned current  = 1;
		unsigned rest     = 1;
		cin >> k;
		for(unsigned int i = 0; i < k; i++) {
			if(rest == 0) {
				current++;
				rest = current;
			}
			coin += current;
			rest--;
		}
		cout << coin;
		return 0;
	}

	int P5722::main(istream &cin, ostream &cout) {
		unsigned int n;
		cin >> n;
		unsigned int ans = 0;
		for(unsigned int i = 1; i <= n; i++) {
			ans += i;
		}
		cout << ans;
		return 0;
	}

	int P5723::main(istream &cin, ostream &cout) {
		unsigned int l;
		unsigned int sum = 0;
		int count        = 0;
		cin >> l;
		for(unsigned int i = 2; i <= l; i++) {
			bool is_prime = true;
			for(unsigned int j = 2; j <= sqrt(i); j++) {
				if(i % j == 0) {
					is_prime = false;
					break;
				}
			}
			if(is_prime) {
				sum += i;
				if(sum <= l) {
					cout << i << endl;
					count++;
				} else {
					break;
				}
			}
		}
		cout << count << endl;
		return 0;
	}

	int P1217::main(istream &cin, ostream &cout) {
		unsigned int a;
		unsigned int b;
		cin >> a >> b;
		auto palindromes = set<unsigned int>();
		if(a <= 2 && 2 <= b) {
			palindromes.insert(2);
		}
		if(a <= 10 && b >= 0) {
			for(unsigned int d1 = 3; d1 <= 9; d1 += 2) {
				//1 [0,10]
				unsigned int palindrome = d1;
				if(a <= palindrome && palindrome <= b) {
					palindromes.insert(palindrome);
				}
			}
		}
		if(a <= 100 && b >= 10) {
			for(unsigned int d1 = 1; d1 <= 9; d1 += 2) {
				//2 [10,100]
				unsigned int palindrome = d1 * 10 + d1;
				if(a <= palindrome && palindrome <= b) {
					palindromes.insert(palindrome);
				}
			}
		}
		if(a <= 1000 && b >= 100) {
			for(unsigned int d1 = 1; d1 <= 9; d1 += 2) {
				//3 [100,1000]
				for(unsigned int d2 = 0; d2 <= 9; d2++) {
					unsigned int palindrome = d1 * 100 + d2 * 10 + d1;
					if(a <= palindrome && palindrome <= b) {
						palindromes.insert(palindrome);
					}
				}
			}
		}
		if(a <= 10000 && b >= 1000) {
			for(unsigned int d1 = 1; d1 <= 9; d1 += 2) {
				//4 [1000,10000]
				for(unsigned int d2 = 0; d2 <= 9; d2++) {
					unsigned int palindrome = d1 * 1000 + d2 * 100 + d2 * 10 + d1;
					if(a <= palindrome && palindrome <= b) {
						palindromes.insert(palindrome);
					}
				}
			}
		}
		if(a <= 100000 && b >= 10000) {
			for(unsigned int d1 = 1; d1 <= 9; d1 += 2) {
				//5 [10000,100000]
				for(unsigned int d2 = 0; d2 <= 9; d2++) {
					for(unsigned int d3 = 0; d3 <= 9; d3++) {
						unsigned int palindrome = d1 * 10000 + 1000 * d2 + 100 * d3 + 10 * d2 + d1;
						if(a <= palindrome && palindrome <= b) {
							palindromes.insert(palindrome);
						}
					}
				}
			}
		}
		if(a <= 1000000 && b >= 100000) {
			for(unsigned int d1 = 1; d1 <= 9; d1 += 2) {
				//6 [100000,1000000]
				for(unsigned int d2 = 0; d2 <= 9; d2++) {
					for(unsigned int d3 = 0; d3 <= 9; d3++) {
						unsigned int palindrome = d1 * 100000 + d2 * 10000 + d3 * 1000 + d3 * 100 + d2 * 10 + d1;
						if(a <= palindrome && palindrome <= b) {
							palindromes.insert(palindrome);
						}
					}
				}
			}
		}
		if(a <= 10000000 && b >= 1000000) {
			for(unsigned int d1 = 1; d1 <= 9; d1 += 2) {
				//7 [1000000,10000000]
				for(unsigned int d2 = 0; d2 <= 9; d2++) {
					for(unsigned int d3 = 0; d3 <= 9; d3++) {
						for(unsigned int d4 = 0; d4 <= 9; d4++) {
							unsigned int palindrome = d1 * 1000000 + d2 * 100000 + d3 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
							if(a <= palindrome && palindrome <= b) {
								palindromes.insert(palindrome);
							}
						}
					}
				}
			}
		}
		if(a <= 100000000 && b >= 10000000) {
			for(unsigned int d1 = 1; d1 <= 9; d1 += 2) {
				//8 [10000000,100000000]
				for(unsigned int d2 = 0; d2 <= 9; d2++) {
					for(unsigned int d3 = 0; d3 <= 9; d3++) {
						for(unsigned int d4 = 0; d4 <= 9; d4++) {
							unsigned int palindrome = d1 * 10000000 + d2 * 1000000 + d3 * 100000 + d4 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
							if(a <= palindrome && palindrome <= b) {
								palindromes.insert(palindrome);
							}
						}
					}
				}
			}
		}
		for(const auto palindrome: palindromes) {
			bool is_prime = true;
			for(unsigned int i = 3; i <= sqrt(palindrome); i++) {
				if(palindrome % i == 0) {
					is_prime = false;
					break;
				}
			}
			if(is_prime) {
				cout << palindrome << endl;
			}
		}
		return 0;
	}

	int P1423::main(istream &cin, ostream &cout) {
		double x;
		cin >> x;
		double sn = 2;
		for(int i = 1; sn < x; i++) {
			sn = 100 * (1 - pow(0.98, i));
			if(sn >= x) {
				cout << i;
				return 0;
			}
		}
		return 0;
	}

	int P1307::main(istream &cin, ostream &cout) {
		bool negative = false;
		int n;
		int ans = 0;
		cin >> n;
		if(n < 0) {
			n        = -n;
			negative = true;
		}
		while(n != 0) {
			ans *= 10;
			ans += n % 10;
			n /= 10;
		}
		if(negative) {
			ans = -ans;
		}
		cout << ans;
		return 0;
	}

	int P1720::main(istream &cin, ostream &cout) {
		double n;
		cin >> n;
		cout << fixed << setprecision(2) << (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5);
		return 0;
	}

	int P5724::main(istream &cin, ostream &cout) {
		unsigned short n;
		cin >> n;
		unsigned int a;
		unsigned int maximum = 0;
		unsigned int minimum = 1000;
		for(unsigned short i = 0; i < n; i++) {
			cin >> a;
			maximum = max(maximum, a);
			minimum = min(minimum, a);
		}
		cout << maximum - minimum;
		return 0;
	}

	int P1420::main(istream &cin, ostream &cout) {
		unsigned int n;
		cin >> n;
		unsigned int prev;
		cin >> prev;
		unsigned int a;
		unsigned int len = 1;
		unsigned int ans = 1;
		for(unsigned int i = 1; i < n; i++, prev = a, ans = max(ans, len)) {
			cin >> a;
			if(a == prev + 1) {
				len++;
			} else {
				len = 1;
			}
		}
		cout << ans;
		return 0;
	}

	int P1075::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		for(int i = 2; i <= sqrt(n); i++) {
			if(n % i == 0) {
				cout << n / i;
				return 0;
			}
		}
		return 0;
	}

	int P5725::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << setw(2) << setfill('0') << right << i * n + j + 1;
			}
			cout << endl;
		}
		int count = 1;
		cout << endl;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n - i - 1; j++) {
				cout << "  ";
			}
			for(int j = 0; j < i + 1; j++) {
				cout << setw(2) << setfill('0') << right << count++;
			}
			cout << endl;
		}
		return 0;
	}

	int P4956::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		for(int k = 1; 1092 * k <= n; k++) {
			if((n - 1092 * k) % 364 == 0) {
				const int x = (n - 1092 * k) / 364;
				if(x < 1 || 100 < x) {
					continue;
				}
				cout << x << endl
				     << k;
				break;
			}
		}
		return 0;
	}

	int P5726::main(istream &cin, ostream &cout) {
		int n;
		int maximum = 0;
		int minimum = 10;
		int sum     = 0;
		cin >> n;
		int score;
		for(int i = 0; i < n; i++) {
			cin >> score;
			sum += score;
			maximum = max(maximum, score);
			minimum = min(minimum, score);
		}
		sum -= maximum;
		sum -= minimum;
		cout << fixed << setprecision(2) << static_cast<double>(sum) / (n - 2);
		return 0;
	}

	int P1089::main(istream &cin, ostream &cout) {
		int budget;
		int saving  = 0;
		int current = 0;
		for(int i = 0; i < 12; i++) {
			current += 300;
			cin >> budget;
			if(current < budget) {
				cout << -(i + 1);
				return 0;
			}
			current -= budget;
			saving += current / 100 * 100;
			current %= 100;
		}
		cout << current + saving / 5 * 6;
		return 0;
	}


	int P1428::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto *fish = new int[n];
		for(int i = 0; i < n; i++) {
			cin >> fish[i];
		}
		for(int i = 0; i < n; i++) {
			int count = 0;
			for(int j = 0; j < i; j++) {
				if(fish[j] < fish[i]) {
					count++;
				}
			}
			cout << count << " ";
		}
		delete[] fish;
		return 0;
	}

	int P1427::main(istream &cin, ostream &cout) {
		unsigned int n;
		auto vec = vector<unsigned int>();
		while(true) {
			cin >> n;
			if(n == 0) {
				break;
			}
			vec.push_back(n);
		}
		for(auto i = vec.rbegin(); i != vec.rend(); ++i) {
			cout << *i << " ";
		}
		return 0;
	}

	int P5727::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto vec = vector<int>();
		while(n != 1) {
			vec.push_back(n);
			if(n % 2 != 0) {
				n = n * 3 + 1;
			} else {
				n /= 2;
			}
		}
		vec.push_back(n);
		for(auto i = vec.rbegin(); i != vec.rend(); ++i) {
			cout << *i << " ";
		}
		return 0;
	}

	int P1047::main(istream &cin, ostream &cout) {
		int l;
		int m;
		cin >> l >> m;
		auto *tree = new bool[l + 1];
		memset(tree, 1, (l + 1) * sizeof(bool));
		for(int i = 0; i < m; i++) {
			int u;
			int v;
			cin >> u >> v;
			for(int j = u; j <= v; j++) {
				tree[j] = false;
			}
		}
		int ans = 0;
		for(int i = 0; i <= l; i++) {
			if(tree[i]) {
				ans++;
			}
		}
		cout << ans;
		delete[] tree;
		return 0;
	}

	int P5728::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto *students = new int *[n];
		for(int i = 0; i < n; i++) {
			students[i] = new int[3];
			cin >> students[i][0] >> students[i][1] >> students[i][2];
		}
		int ans = 0;
		for(int i = 0; i + 1 < n; i++) {
			int sum_i = 0;
			for(int k = 0; k < 3; k++) {
				sum_i += students[i][k];
			}
			for(int j = i + 1; j < n; j++) {
				bool flag = true;
				int sum_j = 0;
				for(int k = 0; k < 3; k++) {
					sum_j += students[j][k];
					if(abs(students[i][k] - students[j][k]) > 5) {
						flag = false;
						break;
					}
				}
				if(flag && abs(sum_i - sum_j) <= 10) {
					ans++;
				}
			}
		}
		cout << ans;
		for(int i = 0; i < n; i++) {
			delete[] students[i];
		}
		delete[] students;
		return 0;
	}

	int P5729::main(istream &cin, ostream &cout) {
		int w;
		int x;
		int h;
		cin >> w >> x >> h;
		bool block[21][21][21] = {};
		memset(block, 1, sizeof block);
		int q;
		cin >> q;
		while(q-- != 0) {
			int x1;
			int y1;
			int z1;
			int x2;
			int y2;
			int z2;
			cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
			for(int i = x1; i <= x2; i++) {
				for(int j = y1; j <= y2; j++) {
					for(int k = z1; k <= z2; k++) {
						block[i][j][k] = false;
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= w; i++) {
			for(int j = 1; j <= x; j++) {
				for(int k = 1; k <= h; k++) {
					if(block[i][j][k]) {
						ans++;
					}
				}
			}
		}
		cout << ans;
		return 0;
	}

	int P2550::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		bool winning_numbers[34];
		memset(winning_numbers, 0, sizeof winning_numbers);
		int prize_numbers[7];
		memset(prize_numbers, 0, sizeof prize_numbers);
		for(int i = 0; i < 7; i++) {
			int winning_number;
			cin >> winning_number;
			winning_numbers[winning_number] = true;
		}
		for(int i = 0; i < n; i++) {
			int prize_number = 7;
			for(int j = 0; j < 7; j++) {
				int lottery_number;
				cin >> lottery_number;
				if(winning_numbers[lottery_number]) {
					prize_number--;
				}
			}
			prize_numbers[prize_number]++;
		}
		for(int i = 0; i < 7; i++) {
			cout << prize_numbers[i] << " ";
		}
		return 0;
	}

	int P2615::main(istream &cin, ostream &cout) {
		int n;
		int square[40][40];
		memset(square, 0, sizeof square);
		auto um = unordered_map<int, pair<int, int>>();
		cin >> n;
		square[0][n / 2] = 1;
		um[1]            = make_pair(0, n / 2);
		for(int k = 2; k <= n * n; k++) {
			auto [prev_x, prev_y] = um[k - 1];
			if(prev_x == 0 && prev_y != n - 1) {
				//若 (K−1) 在第一行但不在最后一列，则将 K 填在最后一行， (K−1) 所在列的右一列；
				square[n - 1][prev_y + 1] = k;
				um[k]                     = make_pair(n - 1, prev_y + 1);
			} else if(prev_y == n - 1 && prev_x != 0) {
				//若 (K−1) 在最后一列但不在第一行，则将 K 填在第一列， (K−1) 所在行的上一行；
				square[prev_x - 1][0] = k;
				um[k]                 = make_pair(prev_x - 1, 0);
			} else if(prev_x == 0 && prev_y == n - 1) {
				//若 (K−1) 在第一行最后一列，则将 K 填在 (K−1) 的正下方；
				square[1][prev_y] = k;
				um[k]             = make_pair(1, prev_y);
			} else if(prev_x != 0 && prev_y != n - 1) {
				//若 (K−1) 既不在第一行，也不在最后一列，如果 (K−1) 的右上方还未填数，则将 K 填在 (K−1) 的右上方，否则将 K 填在 (K−1) 的正下方。
				if(square[prev_x - 1][prev_y + 1] == 0) {
					square[prev_x - 1][prev_y + 1] = k;
					um[k]                          = make_pair(prev_x - 1, prev_y + 1);
				} else {
					square[prev_x + 1][prev_y] = k;
					um[k]                      = make_pair(prev_x + 1, prev_y);
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << square[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}

	int P5730::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		char screen[5][400];
		memset(screen, '.', sizeof screen);
		const char nums[10][5][3] = {
		        {{'X', 'X', 'X'},
		         {'X', '.', 'X'},
		         {'X', '.', 'X'},
		         {'X', '.', 'X'},
		         {'X', 'X', 'X'}},
		        {{'.', '.', 'X'},
		         {'.', '.', 'X'},
		         {'.', '.', 'X'},
		         {'.', '.', 'X'},
		         {'.', '.', 'X'}},
		        {{'X', 'X', 'X'},
		         {'.', '.', 'X'},
		         {'X', 'X', 'X'},
		         {'X', '.', '.'},
		         {'X', 'X', 'X'}},
		        {{'X', 'X', 'X'},
		         {'.', '.', 'X'},
		         {'X', 'X', 'X'},
		         {'.', '.', 'X'},
		         {'X', 'X', 'X'}},
		        {{'X', '.', 'X'},
		         {'X', '.', 'X'},
		         {'X', 'X', 'X'},
		         {'.', '.', 'X'},
		         {'.', '.', 'X'}},
		        {{'X', 'X', 'X'},
		         {'X', '.', '.'},
		         {'X', 'X', 'X'},
		         {'.', '.', 'X'},
		         {'X', 'X', 'X'}},
		        {{'X', 'X', 'X'},
		         {'X', '.', '.'},
		         {'X', 'X', 'X'},
		         {'X', '.', 'X'},
		         {'X', 'X', 'X'}},
		        {{'X', 'X', 'X'},
		         {'.', '.', 'X'},
		         {'.', '.', 'X'},
		         {'.', '.', 'X'},
		         {'.', '.', 'X'}},
		        {{'X', 'X', 'X'},
		         {'X', '.', 'X'},
		         {'X', 'X', 'X'},
		         {'X', '.', 'X'},
		         {'X', 'X', 'X'}},
		        {{'X', 'X', 'X'},
		         {'X', '.', 'X'},
		         {'X', 'X', 'X'},
		         {'.', '.', 'X'},
		         {'X', 'X', 'X'}}};
		for(int i = 0; i < n; i++) {
			char num;
			cin >> num;
			num -= '0';
			for(int j = 0; j < 5; j++) {
				for(int k = 0; k < 3; k++) {
					screen[j][k + i * 4] = nums[num][j][k];
				}
			}
		}
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 4 * n - 1; j++) {
				cout << screen[i][j];
			}
			cout << endl;
		}
		return 0;
	}

	int P1554::main(istream &cin, ostream &cout) {
		int nums[10] = {};
		int m;
		int n;
		cin >> m >> n;
		auto ss = stringstream();
		for(int i = m; i <= n; i++) {
			ss << i;
		}
		char ch;
		while(ss >> ch) {
			nums[ch - '0']++;
		}
		for(int i = 0; i < 10; i++) {
			cout << nums[i] << " ";
		}
		return 0;
	}

	int P2141::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto s = set<int>();
		for(int i = 0; i < n; i++) {
			int num;
			cin >> num;
			s.insert(num);
		}
		int ans = 0;
		for(auto i = s.begin(); i != s.end(); ++i) {
			for(auto j = s.begin(); j != i; ++j) {
				int sub = *i - *j;
				if(sub != *j && s.contains(sub)) {
					ans++;
					break;
				}
			}
		}
		cout << ans;
		return 0;
	}

	int P1614::main(istream &cin, ostream &cout) {
		int n;
		int m;
		cin >> n >> m;
		auto *a = new int[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int ans = 100 * m;
		for(int i = 0; i + m <= n; i++) {
			int sum = 0;
			for(int j = i; j < i + m; j++) {
				sum += a[j];
			}
			ans = min(ans, sum);
		}
		cout << ans;
		delete[] a;
		return 0;
	}

	int P2911::main(istream &cin, ostream &cout) {
		int s1;
		int s2;
		int s3;
		cin >> s1 >> s2 >> s3;
		const int n = s1 + s2 + s3 + 1;
		auto *sum   = new int[n];
		memset(sum, 0, n * sizeof(int));
		for(int i = 1; i <= s1; i++) {
			for(int j = 1; j <= s2; j++) {
				for(int k = 1; k <= s3; k++) {
					sum[i + j + k]++;
				}
			}
		}
		int maximum = 0;
		int ans     = 0;
		for(int i = 3; i < n; i++) {
			if(maximum < sum[i]) {
				maximum = sum[i];
				ans     = i;
			}
		}
		cout << ans;
		delete[] sum;
		return 0;
	}

	int P1161::main(istream &cin, ostream &cout) {
		int n;
		auto *lamp = new bool[2000001];
		memset(lamp, 0, 2000001 * sizeof(bool));
		cin >> n;
		for(int i = 0; i < n; i++) {
			double a;
			int t;
			cin >> a >> t;
			for(int j = 1; j <= t; j++) {
				const int at = a * j;
				lamp[at]     = !lamp[at];
			}
		}
		for(int i = 0; i < 2000001; i++) {
			if(lamp[i]) {
				cout << i;
				break;
			}
		}
		delete[] lamp;
		return 0;
	}

	int P5731::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		int square[9][9] = {};
		int dir          = 0;///< Direction 0 = R, 1 = D, 2 = L, 3 = U
		int current_x    = 0;
		int current_y    = 0;
		for(int i = 1; i <= n * n; i++) {
			square[current_x][current_y] = i;
			auto [next_x, next_y]        = move_forward(dir, current_x, current_y);
			if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || square[next_x][next_y] != 0) {
				dir = (dir + 1) % 4;
			}
			const auto next = move_forward(dir, current_x, current_y);
			current_x       = next.first;
			current_y       = next.second;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << setw(3) << right << setfill(' ') << square[i][j];
			}
			cout << endl;
		}
		return 0;
	}

	pair<int, int> P5731::move_forward(int dir, int current_x, int current_y) {
		int next_x = current_x;
		int next_y = current_y;
		switch(dir) {
			case 0:///< R
				next_y++;
				break;
			case 1:///< D
				next_x++;
				break;
			case 2:///< L
				next_y--;
				break;
			case 3:///< U
				next_x--;
				break;
		}
		return make_pair(next_x, next_y);
	}

	int P5732::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto *triangle = new int *[n];
		for(int i = 0; i < n; i++) {
			triangle[i] = new int[i + 1];
			for(int j = 0; j <= i; j++) {
				if(j == 0 || j == i) {
					triangle[i][j] = 1;
				} else {
					triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
				}
				cout << triangle[i][j] << " ";
			}
			cout << endl;
		}
		for(int i = 0; i < n; i++) {
			delete[] triangle[i];
		}
		delete[] triangle;
		return 0;
	}

	int P1789::main(istream &cin, ostream &cout) {
		int n;
		int m;
		int k;
		cin >> n >> m >> k;
		bool space[101][101] = {};
		memset(space, 0, sizeof space);
		for(int i = 0; i < m; i++) {
			int x;
			int y;
			cin >> x >> y;
			pair<int, int> lights[13] = {
			        make_pair(x - 2, y),
			        make_pair(x - 1, y - 1),
			        make_pair(x - 1, y),
			        make_pair(x - 1, y + 1),
			        make_pair(x, y - 2),
			        make_pair(x, y - 1),
			        make_pair(x, y),
			        make_pair(x, y + 1),
			        make_pair(x, y + 2),
			        make_pair(x + 1, y - 1),
			        make_pair(x + 1, y),
			        make_pair(x + 1, y + 1),
			        make_pair(x + 2, y),
			};
			for(auto [light_x, light_y]: lights) {
				if(0 < light_x && light_x <= n && 0 < light_y && light_y <= n) {
					space[light_x][light_y] = true;
				}
			}
		}
		for(int i = 0; i < k; i++) {
			int o;
			int p;
			cin >> o >> p;
			for(int light_x = o - 2; light_x <= o + 2; light_x++) {
				for(int light_y = p - 2; light_y <= p + 2; light_y++) {
					if(0 < light_x && light_x <= n && 0 < light_y && light_y <= n) {
						space[light_x][light_y] = true;
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(!space[i][j]) {
					ans++;
				}
			}
		}
		cout << ans;
		return 0;
	}

	int P1319::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		bool zero = false;
		int count = 0;
		for(int i = 0; i < n * n; i++) {
			while(count == 0) {
				cin >> count;
				zero = !zero;
			}
			if(zero) {
				cout << 0;
			} else {
				cout << 1;
			}
			count--;
			if((i + 1) % n == 0) {
				cout << endl;
			}
		}
		return 0;
	}

	int P1320::main(istream &cin, ostream &cout) {
		char ch;
		int current = 0;
		int count   = 0;
		vector<int> ans;
		int n = 0;
		while(cin >> ch) {
			if(isdigit(ch) == 0) {
				continue;
			}
			n++;
			if(ch - '0' == current) {
				count++;
			} else {
				ans.push_back(count);
				current = (current + 1) % 2;
				count   = 1;
			}
		}
		ans.push_back(count);
		cout << static_cast<int>(sqrt(n)) << " ";
		for(const auto i: ans) {
			cout << i << " ";
		}
		return 0;
	}

	int P1205::main(istream &cin, ostream &cout) {
		int ans = -1;
		int n;
		cin >> n;
		auto *start = new char *[n];
		auto *end   = new char *[n];
		for(int i = 0; i < n; i++) {
			start[i] = new char[n];
			for(int j = 0; j < n; j++) {
				cin >> start[i][j];
			}
		}
		for(int i = 0; i < n; i++) {
			end[i] = new char[n];
			for(int j = 0; j < n; j++) {
				cin >> end[i][j];
			}
		}
		auto *const r90   = rorate90(n, start);
		auto *const r180  = rorate180(n, start);
		auto *const r270  = rorate270(n, start);
		auto *const r     = reflect(n, start);
		auto *const rr90  = reflect(n, r90);
		auto *const rr180 = reflect(n, r180);
		auto *const rr270 = reflect(n, r270);
		if(equal(n, r90, end)) {
			ans = 1;
		} else if(equal(n, r180, end)) {
			ans = 2;
		} else if(equal(n, r270, end)) {
			ans = 3;
		} else if(equal(n, r, end)) {
			ans = 4;
		} else if(equal(n, rr90, end)) {
			ans = 5;
		} else if(equal(n, rr180, end)) {
			ans = 5;
		} else if(equal(n, rr270, end)) {
			ans = 5;
		} else if(equal(n, start, end)) {
			ans = 6;
		} else {
			ans = 7;
		}
		cout << ans;
		for(int i = 0; i < n; i++) {
			delete[] start[i];
			delete[] end[i];
			delete[] r90[i];
			delete[] r180[i];
			delete[] r270[i];
			delete[] r[i];
			delete[] rr90[i];
			delete[] rr180[i];
			delete[] rr270[i];
		}
		delete[] start;
		delete[] end;
		delete[] r90;
		delete[] r180;
		delete[] r270;
		delete[] r;
		delete[] rr90;
		delete[] rr180;
		delete[] rr270;
		return 0;
	}

	char **P1205::rorate90(int n, char **start) {
		auto *const cpy = new char *[n];
		for(int i = 0; i < n; i++) {
			cpy[i] = new char[n];
		}
		for(int i1 = 0, j2 = 0; i1 < n && j2 < n; i1++, j2++) {
			for(int j1 = 0, i2 = n - 1; j1 < n && i2 >= 0; j1++, i2--) {
				cpy[i1][j1] = start[i2][j2];
			}
		}
		return cpy;
	}

	char **P1205::rorate180(int n, char **start) {
		auto *const cpy = new char *[n];
		for(int i = 0; i < n; i++) {
			cpy[i] = new char[n];
		}
		for(int i1 = 0, i2 = n - 1; i1 < n && i2 >= 0; i1++, i2--) {
			for(int j1 = 0, j2 = n - 1; j1 < n && j2 >= 0; j1++, j2--) {
				cpy[i1][j1] = start[i2][j2];
			}
		}
		return cpy;
	}

	char **P1205::rorate270(int n, char **start) {
		auto *const cpy = new char *[n];
		for(int i = 0; i < n; i++) {
			cpy[i] = new char[n];
		}
		for(int i1 = 0, j2 = n - 1; i1 < n && j2 >= 0; i1++, j2--) {
			for(int j1 = 0, i2 = 0; j1 < n && i2 < n; j1++, i2++) {
				cpy[i1][j1] = start[i2][j2];
			}
		}
		return cpy;
	}

	char **P1205::reflect(int n, char **start) {
		auto *const cpy = new char *[n];
		for(int i = 0; i < n; i++) {
			cpy[i] = new char[n];
		}
		for(int i1 = 0, i2 = 0; i1 < n && i2 < n; i1++, i2++) {
			for(int j1 = 0, j2 = n - 1; j1 < n && j2 >= 0; j1++, j2--) {
				cpy[i1][j1] = start[i2][j2];
			}
		}
		return cpy;
	}

	bool P1205::equal(int n, char **start, char **end) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(start[i][j] != end[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	int P5733::main(istream &cin, ostream &cout) {
		string str;
		cin >> str;
		for(const char ch: str) {
			if(islower(ch) != 0) {
				cout << static_cast<char>(toupper(ch));
			} else {
				cout << ch;
			}
		}
		return 0;
	}

	int P1914::main(istream &cin, ostream &cout) {
		string str;
		int n;
		cin >> n >> str;
		for(const char ch: str) {
			cout << static_cast<char>((ch - 'a' + n) % 26 + 'a');
		}
		return 0;
	}

	int P1125::main(istream &cin, ostream &cout) {
		string str;
		cin >> str;
		int freq[26] = {};
		int maxn     = 0;
		int minn     = 100;
		for(const char ch: str) {
			freq[ch - 'a']++;
		}
		for(int i = 0; i < 26; i++) {
			if(freq[i] > 0) {
				maxn = max(maxn, freq[i]);
				minn = min(minn, freq[i]);
			}
		}
		bool is_prime = true;
		for(int i = 2; i <= sqrt(maxn - minn); i++) {
			if((maxn - minn) % i == 0) {
				is_prime = false;
				break;
			}
		}
		if(maxn - minn < 2) {
			is_prime = false;
		}
		if(is_prime) {
			cout << "Lucky Word" << endl
			     << maxn - minn;
		} else {
			cout << "No Answer" << endl
			     << 0;
			return 0;
		}
		return 0;
	}

	int P1957::main(istream &cin, ostream &cout) {
		int i;
		cin >> i;
		char op;
		for(int _ = 0; _ < i; _++) {
			int num1;
			int num2;
			string pos1;
			cin >> pos1;
			if(isalpha(pos1[0]) != 0) {
				op = pos1[0];
				cin >> num1 >> num2;
			} else {
				auto ss = stringstream();
				ss << pos1;
				ss >> num1;
				cin >> num2;
			}
			auto oss = ostringstream();
			switch(op) {
				case 'a':
					oss << num1 << '+' << num2 << '=' << num1 + num2;
					break;
				case 'b':
					oss << num1 << '-' << num2 << '=' << num1 - num2;
					break;
				case 'c':
					oss << num1 << '*' << num2 << '=' << num1 * num2;
					break;
				default:
					cerr << "Unknown Op:\t" << op;
					return 1;
			}
			string str = oss.str();
			cout << str << endl
			     << str.length() << endl;
		}
		return 0;
	}

	int P5015::main(istream &cin, ostream &cout) {
		int ans = 0;
		char ch;
		while((ch = cin.get()) != EOF) {
			if(isalnum(ch) != 0) {
				ans++;
			}
		}
		cout << ans;
		return 0;
	}

	int P5734::main(istream &cin, ostream &cout) {
		string doc;
		int n;
		cin >> n >> doc;
		int op;
		for(int i = 0; i < n; i++) {
			cin >> op;
			switch(op) {
				case 1: {
					string str;
					cin >> str;
					doc.insert(doc.end(), str.begin(), str.end());
					cout << doc << endl;
					break;
				}
				case 2: {
					int a;
					int b;
					cin >> a >> b;
					doc = doc.substr(a, b);
					cout << doc << endl;
					break;
				}
				case 3: {
					int a;
					string str;
					cin >> a >> str;
					doc.insert(doc.begin() + a, str.begin(), str.end());
					cout << doc << endl;
					break;
				}
				case 4: {
					string str;
					cin >> str;
					const auto ans = doc.find(str);
					if(ans == string::npos) {
						cout << -1 << endl;
					} else {
						cout << ans << endl;
					}
					break;
				}
			}
		}
		return 0;
	}

	int P1308::main(istream &cin, ostream &cout) {
		int sum       = 0;
		int pos       = -1;
		auto *target  = new char[11];
		auto *article = new char[1000001];
		cin.getline(target, 11);
		for(int i = 0; i < strlen(target); i++) {
			target[i] = tolower(target[i]);
		}
		cin.getline(article, 1000001);

		for(int i = 0; i + strlen(target) <= strlen(article); i++) {
			if(!((i == 0 || article[i - 1] == ' ') && (i + strlen(target) == strlen(article) || article[i + strlen(target)] == ' '))) {
				continue;
			}
			bool ok = true;
			for(int j = 0; j < strlen(target); j++) {
				if(target[j] != tolower(article[i + j])) {
					ok = false;
					break;
				}
			}
			if(ok) {
				sum++;
				if(pos == -1) {
					pos = i;
				}
			}
		}
		if(sum == 0) {
			cout << -1;
		} else {
			cout << sum << " " << pos;
		}
		delete[] target;
		delete[] article;
		return 0;
	}

	int P1765::main(istream &cin, ostream &cout) {
		int ans            = 0;
		const int nums[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
		char ch;
		while((ch = cin.get()) != EOF) {
			if(ch == ' ') {
				ans++;
			} else if(isalpha(ch) != 0) {
				ans += nums[ch - 'a'];
			}
		}
		cout << ans;
		return 0;
	}

	int P3741::main(istream &cin, ostream &cout) {
		int n;
		bool flag = false;
		int ans   = 0;
		cin >> n;
		string str;
		cin >> str;
		for(int i = 0; i < n - 1; i++) {
			if(str[i] == 'V') {
				if(str[i + 1] == 'K') {
					ans++;
				} else if(i + 2 == n || i + 2 < n && str[i + 2] != 'K') {
					flag = true;
				}
			} else if(str[i + 1] == 'K' && (i - 1 >= 0 && str[i - 1] != 'V' || i == 0)) {
				flag = true;
			}
		}
		if(flag) {
			ans++;
		}
		cout << ans;
		return 0;
	}

	int P1321::main(istream &cin, ostream &cout) {
		string str;
		string boygirl[] = {"boy", "girl"};
		cin >> str;
		for(auto word: boygirl) {
			int count = 0;
			for(int i = 0; i + word.length() - 1 < str.length(); i++) {
				for(int j = 0; j < word.length(); j++) {
					if(word[j] == str[i + j]) {
						count++;
						break;
					}
				}
			}
			cout << count << endl;
		}
		return 0;
	}

	int P1553::main(istream &cin, ostream &cout) {
		deque<char> dq[2];
		stringstream ss[2];
		int current = 0;
		int limit   = 1;
		char op     = 'N';
		char ch;
		while(cin >> ch) {
			if(isdigit(ch) != 0) {
				bool flag = false;
				dq[current].push_front(ch);
			} else {
				op = ch;
				current++;
			}
		}
		if(op == '.' || op == '/') {
			limit = 2;
		}
		for(int i = 0; i < limit; i++) {
			while(dq[i].size() > 1 && dq[i].front() == '0') {
				dq[i].pop_front();
			}
			if(op == '.' && i == 1) {
				while(dq[i].size() > 1 && dq[i].back() == '0') {
					dq[i].pop_back();
				}
			}
			while(!dq[i].empty()) {
				ss[i] << dq[i].front();
				dq[i].pop_front();
			}
		}
		cout << ss[0].str();
		if(op != 'N') {
			cout << op;
			if(op != '%') {
				cout << ss[1].str();
			}
		}
		return 0;
	}

	int P1603::main(istream &cin, ostream &cout) {
		unordered_map<string, int> um;
		um["one"]       = 1;
		um["two"]       = 2;
		um["three"]     = 3;
		um["four"]      = 4;
		um["five"]      = 5;
		um["six"]       = 6;
		um["seven"]     = 7;
		um["eight"]     = 8;
		um["nine"]      = 9;
		um["ten"]       = 10;
		um["eleven"]    = 11;
		um["twelve"]    = 12;
		um["thirteen"]  = 13;
		um["fourteen"]  = 14;
		um["fifteen"]   = 15;
		um["sixteen"]   = 16;
		um["seventeen"] = 17;
		um["eighteen"]  = 18;
		um["nineteen"]  = 19;
		um["twenty"]    = 20;
		um["a"]         = 1;
		um["both"]      = 2;
		um["another"]   = 1;
		um["first"]     = 1;
		um["second"]    = 2;
		um["third"]     = 3;
		multiset<int> ms;
		string word;
		for(int i = 0; i < 6; i++) {
			cin >> word;
			if(um.contains(word)) {
				ms.insert(um[word] * um[word] % 100);
			}
		}
		if(ms.empty()) {
			cout << 0;
			return 0;
		}
		stringstream ss;
		for(const auto i: ms) {
			if(i < 10) {
				ss << '0';
			}
			ss << i;
		}
		unsigned long long ans;
		ss >> ans;
		cout << ans;
		return 0;
	}

	int P1200::main(istream &cin, ostream &cout) {
		string comet;
		string team;
		cin >> comet >> team;
		unsigned int comet_int = 1;
		unsigned int team_int  = 1;
		for(const char ch: comet) {
			comet_int *= ch - 'A' + 1;
			comet_int %= 47;
		}
		for(const char ch: team) {
			team_int *= ch - 'A' + 1;
			team_int %= 47;
		}
		cout << (comet_int == team_int ? "GO" : "STAY");
		return 0;
	}

	int P1597::main(istream &cin, ostream &cout) {
		int a = 0;
		int b = 0;
		int c = 0;
		while(true) {
			char var;
			int *p = nullptr;
			int val;
			char ref;
			if(!(cin >> var) || isalpha(var) == 0) {
				break;
			}
			switch(var) {
				case 'a':
					p = &a;
					break;
				case 'b':
					p = &b;
					break;
				case 'c':
					p = &c;
					break;
			}
			cin.get();
			cin.get();
			if(isdigit(cin.peek()) != 0) {
				cin >> val;
				*p = val;
			} else {
				cin >> ref;
				switch(ref) {
					case 'a':
						*p = a;
						break;
					case 'b':
						*p = b;
						break;
					case 'c':
						*p = c;
						break;
					default: break;
				}
			}
			cin.get();
		}
		cout << a << " " << b << " " << c;
		return 0;
	}

	int P1598::main(istream &cin, ostream &cout) {
		char ch;
		int count[26] = {};
		int maximum   = 0;
		while(cin >> ch) {
			if(isupper(ch) != 0) {
				count[ch - 'A']++;
				maximum = max(maximum, count[ch - 'A']);
			}
		}
		for(int i = maximum; i > 0; i--) {
			for(int j = 0; j < 26; j++) {
				if(count[j] >= i) {
					cout << '*';
				} else {
					cout << ' ';
				}
				cout << ' ';
			}
			cout << endl;
		}
		for(char ch = 'A'; ch <= 'Z'; ch++) {
			cout << ch << ' ';
		}
		return 0;
	}

	int P5735::main(istream &cin, ostream &cout) {
		double x1;
		double y1;
		double x2;
		double y2;
		double x3;
		double y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		const double d12 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		const double d23 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
		const double d13 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
		cout << fixed << setprecision(2) << d12 + d23 + d13;
		return 0;
	}

	int P5736::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		bool notprime[100001];
		memset(notprime, 1, sizeof notprime);
		notprime[0] = false;
		notprime[1] = false;
		notprime[2] = true;
		for(unsigned int i = 2; i <= 50000; i++) {
			for(unsigned int j = 2; i * j <= 100000; j++) {
				notprime[i * j] = false;
			}
		}
		unsigned int num;
		for(int _ = 0; _ < n; _++) {
			cin >> num;
			if(notprime[num]) {
				cout << num << " ";
			}
		}
		return 0;
	}

	int P5737::main(istream &cin, ostream &cout) {
		int x;
		int y;
		cin >> x >> y;
		ostringstream oss;
		int sum = 0;
		for(int year = x; year <= y; year++) {
			if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				oss << year << ' ';
				sum++;
			}
		}
		cout << sum << endl
		     << oss.str();
		return 0;
	}

	int P5738::main(istream &cin, ostream &cout) {
		int n;
		int m;
		cin >> n >> m;
		double ans = 0;
		for(int i = 0; i < n; i++) {
			vector<int> vec(m);
			for(int j = 0; j < m; j++) {
				cin >> vec[j];
			}
			sort(vec.begin(), vec.end());
			ans = max(ans, static_cast<double>(accumulate(vec.begin() + 1, vec.end() - 1, 0)) / (m - 2));
		}
		cout << fixed << setprecision(2) << ans;
		return 0;
	}

	int P5739::main(istream &cin, ostream &cout) {
		unsigned int n;
		cin >> n;
		unsigned int ans = 1;
		for(unsigned int i = 1; i <= n; i++) {
			ans *= i;
		}
		cout << ans;
		return 0;
	}

	int P5461::main(istream &cin, ostream &cout) {
		unsigned int n;
		cin >> n;
		n             = 1 << n;
		bool **matrix = new bool *[n];
		for(int i = 0; i < n; i++) {
			matrix[i] = new bool[n];
			memset(matrix[i], true, n * sizeof(bool));
		}
		pardon(matrix, 0, 0, n);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
			delete[] matrix[i];
		}
		delete[] matrix;
		return 0;
	}

	void P5461::pardon(bool **matrix, int x0, int y0, int n) {
		if(n == 2) {
			matrix[x0][y0] = false;
			return;
		}
		for(int i = 0; i < n / 2; i++) {
			for(int j = 0; j < n / 2; j++) {
				matrix[x0 + i][y0 + j] = false;
			}
		}
		pardon(matrix, x0, y0 + n / 2, n / 2);
		pardon(matrix, x0 + n / 2, y0, n / 2);
		pardon(matrix, x0 + n / 2, y0 + n / 2, n / 2);
	}

	int P5740::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		string max_name;
		int max_1   = 0;
		int max_2   = 0;
		int max_3   = 0;
		int max_sum = -1;
		for(int i = 0; i < n; i++) {
			string name;
			int grade1;
			int grade2;
			int grade3;
			cin >> name >> grade1 >> grade2 >> grade3;
			int sum = grade1 + grade2 + grade3;
			if(max_sum < sum) {
				max_sum  = sum;
				max_name = name;
				max_1    = grade1;
				max_2    = grade2;
				max_3    = grade3;
			}
		}
		cout << max_name << ' ' << max_1 << ' ' << max_2 << ' ' << max_3;
		return 0;
	}
}// namespace luogu
