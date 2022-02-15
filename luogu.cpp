#include "luogu.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
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
		auto fish = new int[n];
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
}// namespace luogu
