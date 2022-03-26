#include "pat.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <map>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

namespace pat {
	namespace b {
		namespace b1001 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				int ans = 0;
				while(n != 1) {
					if(n % 2 == 0) {
						n /= 2;
					} else {
						n = (3 * n + 1) / 2;
					}
					ans++;
				}
				cout << ans;
				return 0;
			}
		}// namespace b1001

		namespace b1002 {
			int main(istream &cin, ostream &cout) {
				unsigned int sum = 0;
				char ch;
				while(cin >> ch) {
					sum += ch - '0';
				}
				stringstream ss;
				ss << sum;
				string str;
				ss >> str;
				for(int i = 0; i < str.length(); i++) {
					ch = str[i];
					switch(ch) {
						case '0':
							cout << "ling";
							break;
						case '1':
							cout << "yi";
							break;
						case '2':
							cout << "er";
							break;
						case '3':
							cout << "san";
							break;
						case '4':
							cout << "si";
							break;
						case '5':
							cout << "wu";
							break;
						case '6':
							cout << "liu";
							break;
						case '7':
							cout << "qi";
							break;
						case '8':
							cout << "ba";
							break;
						case '9':
							cout << "jiu";
							break;
					}
					if(i != str.length() - 1) {
						cout << ' ';
					}
				}
				return 0;
			}
		}// namespace b1002

		namespace b1003 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				for(int _ = 0; _ < n; _++) {
					string str;
					cin >> str;
					int p      = -1;
					int t      = -1;
					int pref_a = 0;
					int mid_a  = 0;
					int suf_a  = 0;
					for(int i = 0; i < str.length(); i++) {
						const char ch = str[i];
						switch(ch) {
							case 'P':
								if(p != -1 || t != -1) {
									goto NO;
								}
								p = i;
								break;
							case 'A':
								if(p == -1 && t == -1) {
									pref_a++;
								} else if(p != -1 && t == -1) {
									mid_a++;
								} else if(p != -1 && t != -1) {
									suf_a++;
								} else {
									goto NO;
								}
								break;
							case 'T':
								if(p == -1 || t != -1) {
									goto NO;
								}
								t = i;
								break;
							default: goto NO;
						}
					}
					if(p == -1 || t == -1) {
						goto NO;
					}
					if(mid_a < 1) {
						goto NO;
					}
					if(suf_a != mid_a * pref_a) {
						goto NO;
					}
					cout << "YES" << endl;
					continue;
				NO:
					cout << "NO" << endl;
				}
				return 0;
			}
		}// namespace b1003

		namespace b1004 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				vector<tuple<string, string, unsigned short>> vec(n);
				for(int i = 0; i < n; i++) {
					string name;
					string id;
					int grade;
					cin >> name >> id >> grade;
					vec[i] = make_tuple(name, id, grade);
				}
				sort(vec.begin(), vec.end(), [](const tuple<string, string, unsigned short> &a, const tuple<string, string, unsigned short> &b) -> bool {
					const auto &[a_name, a_id, a_grade] = a;
					const auto &[b_name, b_id, b_grade] = b;
					return a_grade < b_grade;
				});
				auto [highest_name, highest_id, highest_grade] = vec.back();
				auto [lowest_name, lowest_id, lowest_grade]    = vec.front();
				cout << highest_name << ' ' << highest_id << endl
				     << lowest_name << ' ' << lowest_id;
				return 0;
			}
		}// namespace b1004

		namespace b1005 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				unordered_map<int, int> in(n);
				for(int i = 0; i < n; i++) {
					int num;
					cin >> num;
					in[num] = 0;
				}
				for(auto [num, deg]: in) {
					int cpy = num;
					if(deg == 0) {
						while(cpy != 1) {
							if(cpy % 2 == 0) {
								cpy /= 2;
							} else {
								cpy = (cpy * 3 + 1) / 2;
							}
							if(in.contains(cpy)) {
								in[cpy]++;
							}
						}
					}
				}
				vector<int> ans;
				for(auto [num, deg]: in) {
					if(deg == 0) {
						ans.push_back(num);
					}
				}
				sort(ans.rbegin(), ans.rend());
				for(int i = 0; i < ans.size(); i++) {
					cout << ans[i];
					if(i != ans.size() - 1) {
						cout << ' ';
					}
				}
				return 0;
			}
		}// namespace b1005

		namespace b1006 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				const int b = n / 100;
				for(int i = 0; i < b; i++) {
					cout << 'B';
				}
				n %= 100;
				const int s = n / 10;
				for(int i = 0; i < s; i++) {
					cout << 'S';
				}
				n %= 10;
				for(int i = 1; i <= n; i++) {
					cout << i;
				}
				return 0;
			}
		}// namespace b1006

		namespace b1007 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				auto *is_prime = new bool[n + 1];
				memset(is_prime, 1, (n + 1) * sizeof(bool));
				for(int i = 2; i <= n / 2; i++) {
					for(int j = 2; i * j <= n; j++) {
						is_prime[i * j] = false;
					}
				}
				int ans = 0;
				for(int i = 2; i + 2 <= n; i++) {
					if(is_prime[i] && is_prime[i + 2]) {
						ans++;
					}
				}
				cout << ans;
				delete[] is_prime;
				return 0;
			}
		}// namespace b1007

		namespace b1008 {
			int main(istream &cin, ostream &cout) {
				int n;
				int m;
				cin >> n >> m;
				vector<int> vec(n);
				for(int i = 0; i < n; i++) {
					cin >> vec[(i + m) % n];
				}
				for(int i = 0; i < n; i++) {
					cout << vec[i];
					if(i != n - 1) {
						cout << ' ';
					}
				}
				return 0;
			}
		}// namespace b1008

		namespace b1009 {
			int main(istream &cin, ostream &cout) {
				string str;
				vector<string> strs;
				while(cin >> str) {
					strs.push_back(str);
				}
				for(int i = strs.size() - 1; i > 0; i--) {
					cout << strs[i] << ' ';
				}
				cout << strs[0];
				return 0;
			}
		}// namespace b1009

		namespace b1010 {
			int main(istream &cin, ostream &cout) {
				int num;
				vector<int> vec;
				ostringstream oss;
				while(cin >> num) {
					vec.push_back(num);
				}
				for(int i = 0; i + 1 < vec.size(); i += 2) {
					const int a = vec[i] * vec[i + 1];
					const int b = vec[i + 1] - 1;
					if(vec[i + 1] != 0) {
						oss << a << ' ' << b << ' ';
					}
				}
				if(vec.size() == 2 && vec[1] == 0) {
					oss << "0 0 ";
				}
				string ans = oss.str();
				ans        = ans.substr(0, ans.length() - 1);
				cout << ans;
				return 0;
			}
		}// namespace b1010

		namespace b1011 {
			int main(istream &cin, ostream &cout) {
				long long a;
				long long b;
				long long c;
				int n;
				cin >> n;
				for(int i = 1; i <= n; i++) {
					cin >> a >> b >> c;
					cout << "Case #" << i << ": " << (a + b > c ? "true" : "false") << endl;
				}
				return 0;
			}
		}// namespace b1011

		namespace b1012 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				int a1       = 0;
				int a2       = 0;
				bool a2_flag = true;
				int a2_count = 0;
				int a3       = 0;
				int a4_sum   = 0;
				int a4_count = 0;
				int a5       = 0;
				for(int i = 0; i < n; i++) {
					int num;
					cin >> num;
					const int remainder = num % 5;
					switch(remainder) {
						case 0:
							if(num % 2 == 0) {
								a1 += num;
							}
							break;
						case 1:
							if(a2_flag) {
								a2 += num;
							} else {
								a2 -= num;
							}
							a2_flag = !a2_flag;
							a2_count++;
							break;
						case 2:
							a3++;
							break;
						case 3:
							a4_sum += num;
							a4_count++;
							break;
						case 4:
							a5 = max(a5, num);
							break;
					}
				}
				const double a4 = static_cast<double>(a4_sum) / a4_count;
				if(a1 == 0) {
					cout << 'N';
				} else {
					cout << a1;
				}
				cout << ' ';
				if(a2_count == 0) {
					cout << 'N';
				} else {
					cout << a2;
				}
				cout << ' ';
				if(a3 == 0) {
					cout << 'N';
				} else {
					cout << a3;
				}
				cout << ' ';
				if(a4_count == 0) {
					cout << 'N';
				} else {
					cout << fixed << setprecision(1) << a4;
				}
				cout << ' ';
				if(a5 == 0) {
					cout << 'N';
				} else {
					cout << a5;
				}
				return 0;
			}
		}// namespace b1012

		namespace b1013 {
			int main(istream &cin, ostream &cout) {
				int m;
				int n;
				cin >> m >> n;
				int count          = 0;
				vector<int> primes = {};
				for(int i = 2; count <= n; i++) {
					bool is_prime = true;
					for(int factor = 2; factor <= sqrt(i); factor++) {
						if(i % factor == 0) {
							is_prime = false;
							break;
						}
					}
					if(is_prime) {
						primes.push_back(i);
						count++;
					}
				}
				count = 0;
				for(int i = m - 1; i < n; i++) {
					cout << primes[i];
					count++;
					if(count == 10) {
						count = 0;
						cout << endl;
					} else if(i != n - 1) {
						cout << ' ';
					}
				}
				return 0;
			}
		}// namespace b1013

		namespace b1014 {
			int main(istream &cin, ostream &cout) {
				string str1;
				string str2;
				cin >> str1 >> str2;
				string day;
				const vector<string> days = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
				int hh;
				int mm;
				for(int i = 0; i < str1.length() && i < str2.length(); i++) {
					if(str1[i] == str2[i]) {
						if(day.empty()) {
							if(isupper(str1[i]) != 0) {
								day = days[str1[i] - 'A'];
							}
						} else if(isdigit(str1[i]) != 0 || 'A' <= str1[i] && str1[i] <= 'N') {
							if(isdigit(str1[i]) != 0) {
								hh = str1[i] - '0';
							} else {
								hh = 10 + str1[i] - 'A';
							}
							break;
						}
					}
				}
				cin >> str1 >> str2;
				for(int i = 0; i < str1.length() && i < str2.length(); i++) {
					if(str1[i] == str2[i] && isalpha(str1[i]) != 0) {
						mm = i;
						break;
					}
				}
				cout << day << ' ' << setw(2) << right << setfill('0') << hh << ':' << setw(2) << right << setfill('0') << mm;
				return 0;
			}
		}// namespace b1014

		namespace b1015 {
			int main(istream &cin, ostream &cout) {
				unsigned int n;
				unsigned int l;
				unsigned int h;
				cin >> n >> l >> h;
				vector<student> sector[4] = {vector<student>(), vector<student>(), vector<student>(), vector<student>()};
				int sum                   = 0;
				for(int i = 0; i < n; i++) {
					auto stu = student();
					cin >> stu.id >> stu.morality >> stu.ability;
					if(stu.morality >= l && stu.ability >= l) {
						sum++;
						if(stu.morality >= h && stu.ability >= h) {
							sector[0].push_back(stu);
						} else if(stu.morality >= h) {
							sector[1].push_back(stu);
						} else if(stu.morality < h && stu.ability < h && stu.morality >= stu.ability) {
							sector[2].push_back(stu);
						} else {
							sector[3].push_back(stu);
						}
					}
				}
				cout << sum << endl;
				for(int i = 0; i < 4; i++) {
					sort(sector[i].begin(), sector[i].end());
					for(auto it = sector[i].begin(); it != sector[i].end(); ++it) {
						auto stu = *it;
						cout << stu.id << ' ' << stu.morality << ' ' << stu.ability << endl;
					}
				}
				return 0;
			}

			bool student::operator<(const student &stu) const {
				if(this->ability + this->morality == stu.ability + stu.morality) {
					if(this->morality == stu.morality) {
						return this->id < stu.id;
					}
					return this->morality > stu.morality;
				}
				return this->ability + this->morality > stu.ability + stu.morality;
			}
		}// namespace b1015

		namespace b1016 {
			int main(istream &cin, ostream &cout) {
				string a;
				string b;
				int da;
				int db;
				cin >> a >> da >> b >> db;
				stringstream ssa;
				stringstream ssb;
				int count_a = 0;
				int count_b = 0;
				for(const char ch: a) {
					if(ch - '0' == da) {
						count_a++;
						ssa << ch;
					}
				}
				for(const char ch: b) {
					if(ch - '0' == db) {
						count_b++;
						ssb << ch;
					}
				}
				int pa = 0;
				int pb = 0;
				if(count_a != 0) {
					ssa >> pa;
				}
				if(count_b != 0) {
					ssb >> pb;
				}
				cout << pa + pb;
				return 0;
			}
		}// namespace b1016

		namespace b1018 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				int a_win          = 0;
				int b_win          = 0;
				int a_win_count[3] = {};
				int b_win_count[3] = {};
				int tie            = 0;
				for(int i = 0; i < n; i++) {
					char a;
					char b;
					cin >> a >> b;
					if(a == b) {
						tie++;
					} else if(a == 'C' && b == 'J' || a == 'J' && b == 'B' || a == 'B' && b == 'C') {
						a_win++;
						switch(a) {
							case 'B':
								a_win_count[0]++;
								break;
							case 'C':
								a_win_count[1]++;
								break;
							case 'J':
								a_win_count[2]++;
								break;
						}
					} else {
						b_win++;
						switch(b) {
							case 'B':
								b_win_count[0]++;
								break;
							case 'C':
								b_win_count[1]++;
								break;
							case 'J':
								b_win_count[2]++;
								break;
						}
					}
				}
				cout << a_win << ' ' << tie << ' ' << b_win << endl
				     << b_win << ' ' << tie << ' ' << a_win << endl;
				int a_win_max = 0;
				int b_win_max = 0;
				for(int i = 0; i < 3; i++) {
					a_win_max = max(a_win_max, a_win_count[i]);
					b_win_max = max(b_win_max, b_win_count[i]);
				}
				for(int i = 0; i < 3; i++) {
					if(a_win_count[i] == a_win_max) {
						switch(i) {
							case 0:
								cout << 'B';
								break;
							case 1:
								cout << 'C';
								break;
							case 2:
								cout << 'J';
								break;
						}
						cout << ' ';
						break;
					}
				}
				for(int i = 0; i < 3; i++) {
					if(b_win_count[i] == b_win_max) {
						switch(i) {
							case 0:
								cout << 'B';
								break;
							case 1:
								cout << 'C';
								break;
							case 2:
								cout << 'J';
								break;
						}
						break;
					}
				}
				return 0;
			}
		}// namespace b1018

		namespace b1019 {
			int main(istream &cin, ostream &cout) {
				string num;
				cin >> num;
				int a = 0;
				int b = 0;
				while(num.length() < 4) {
					num = num + '0';
				}
				if(num == "0000") {
					cout << "0000 - 0000 = 0000";
					return 0;
				}
				while(num != "0000" && a - b != 6174) {
					stringstream ssa;
					stringstream ssb;
					stringstream ss;
					sort(num.rbegin(), num.rend());
					ssa << num;
					ssa >> a;
					sort(num.begin(), num.end());
					ssb << num;
					ssb >> b;
					ss << setw(4) << right << setfill('0') << a - b;
					num = "";
					ss >> num;
					cout << setw(4) << right << setfill('0') << a << " - " << setw(4) << right << setfill('0') << b << " = " << setw(4) << right << setfill('0') << a - b << endl;
				}
				return 0;
			}
		}// namespace b1019

		namespace b1020 {
			int main(istream &cin, ostream &cout) {
				int n;
				int d;
				cin >> n >> d;
				vector<long double> storage(n);
				vector<long double> sales(n);
				vector<pair<long double, int>> unit_price(n);
				for(int i = 0; i < n; i++) {
					cin >> storage[i];
				}
				for(int i = 0; i < n; i++) {
					cin >> sales[i];
				}
				for(int i = 0; i < n; i++) {
					unit_price[i] = make_pair(sales[i] / storage[i], i);
				}
				sort(unit_price.begin(), unit_price.end(), [](const pair<long double, int> &a, const pair<long double, int> &b) { return a.first > b.first; });
				int current_amount = 0;
				long double ans    = 0;
				for(int i = 0; i < n && current_amount < d; i++) {
					int amount = 0;
					if(current_amount + storage[unit_price[i].second] > d) {
						amount         = d - current_amount;
						current_amount = d;
						ans += amount * sales[unit_price[i].second] / storage[unit_price[i].second];
					} else {
						amount = storage[unit_price[i].second];
						ans += sales[unit_price[i].second];
						current_amount += storage[unit_price[i].second];
					}
				}
				cout << fixed << setprecision(2) << ans;
				return 0;
			}
		}// namespace b1020

		namespace b1021 {
			int main(istream &cin, ostream &cout) {
				map<char, int> dm;
				char ch;
				while(cin >> ch) {
					if(isdigit(ch) != 0) {
						dm[ch]++;
					}
				}
				for(auto [d, m]: dm) {
					cout << d << ':' << m << endl;
				}
				return 0;
			}
		}// namespace b1021

		namespace b1022 {
			int main(istream &cin, ostream &cout) {
				int a;
				int b;
				int d;
				cin >> a >> b >> d;
				int sum = a + b;
				if(sum == 0) {
					cout << 0;
					return 0;
				}
				vector<unsigned short> vec;
				while(sum != 0) {
					vec.push_back(sum % d);
					sum /= d;
				}
				for(auto it = vec.rbegin(); it != vec.rend(); ++it) {
					cout << *it;
				}
				return 0;
			}
		}// namespace b1022

		namespace b1023 {
			int main(istream &cin, ostream &cout) {
				vector<int> vec(10);
				for(int i = 0; i < 10; i++) {
					cin >> vec[i];
				}
				for(int i = 1; i < 10; i++) {
					if(vec[i] > 0) {
						cout << i;
						vec[i]--;
						break;
					}
				}
				for(int i = 0; i < 10; i++) {
					while(vec[i] > 0) {
						cout << i;
						vec[i]--;
					}
				}
				return 0;
			}
		}// namespace b1023

		namespace b1024 {
			int main(istream &cin, ostream &cout) {
				string str;
				cin >> str;
				const char op         = str[0];
				const char num1       = str[1];
				const auto pos_e      = str.find('E');
				const string num2     = str.substr(3, pos_e - 3);
				const string num3_str = str.substr(pos_e + 1);
				stringstream ss;
				ss << num3_str;
				int num3;
				ss >> num3;
				if(op == '-') {
					cout << op;
				}
				if(num3 < 0) {
					cout << 0 << '.';
					for(int i = 1; i < abs(num3); i++) {
						cout << 0;
					}
					cout << num1 << num2;
				} else {
					cout << num1;
					int i = 0;
					for(; i < num3 && i < num2.length(); i++) {
						cout << num2[i];
					}
					if(i < num2.length()) {
						cout << '.';
						for(; i < num2.length(); i++) {
							cout << num2[i];
						}
					}
					if(i < num3) {
						for(; i < num3; i++) {
							cout << 0;
						}
					}
				}
				return 0;
			}
		}// namespace b1024

		namespace b1025 {
			int main(istream &cin, ostream &cout) {
				string address0;
				int n, k;
				cin >> address0 >> n >> k;
				unordered_map<string, pair<int, string>> nodes;
				for(int i = 0; i < n; i++) {
					string address, next;
					int data;
					cin >> address >> data >> next;
					nodes.insert(make_pair(address, make_pair(data, next)));
				}
				vector<pair<string, int>> vec;
				string current_addr = address0;
				while(current_addr != "-1") {
					auto [data, next] = nodes[current_addr];
					vec.push_back(make_pair(current_addr, data));
					current_addr = next;
				}
				n = vec.size();
				for(int i = 0; i < (n - n % k); i += k) {
					reverse(vec.begin() + i, vec.begin() + i + k);
				}
				for(int i = 0; i < n; i++) {
					cout << vec[i].first << ' ' << vec[i].second << ' ' << (i + 1 < n ? vec[i + 1].first : "-1") << endl;
				}
				return 0;
			}
		}// namespace b1025

		namespace b1026 {
			int main(istream &cin, ostream &cout) {
				unsigned int c1, c2;
				cin >> c1 >> c2;
				unsigned int d = (c2 + 50 - c1) / 100;
				unsigned int h = d / 3600;
				d %= 3600;
				unsigned int m = d / 60;
				d %= 60;
				unsigned s = d;
				cout << setw(2) << right << setfill('0') << h << ':' << setw(2) << right << setfill('0') << m << ':' << setw(2) << right << setfill('0') << s;
				return 0;
			}
		}// namespace b1026
	}    // namespace b

	namespace a {}

	namespace top {}
}// namespace pat
