#include "pat.h"
#include "templates.h"
#include <algorithm>
#include <bit>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <map>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
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
				int n;
				int k;
				cin >> address0 >> n >> k;
				unordered_map<string, pair<int, string>> nodes;
				for(int i = 0; i < n; i++) {
					string address;
					string next;
					int data;
					cin >> address >> data >> next;
					nodes.insert(make_pair(address, make_pair(data, next)));
				}
				vector<pair<string, int>> vec;
				string current_addr = address0;
				while(current_addr != "-1") {
					auto [data, next] = nodes[current_addr];
					vec.emplace_back(current_addr, data);
					current_addr = next;
				}
				n = vec.size();
				for(int i = 0; i < n - n % k; i += k) {
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
				unsigned int c1;
				unsigned int c2;
				cin >> c1 >> c2;
				unsigned int d       = (c2 + 50 - c1) / 100;
				const unsigned int h = d / 3600;
				d %= 3600;
				const unsigned int m = d / 60;
				d %= 60;
				const unsigned s = d;
				cout << setw(2) << right << setfill('0') << h << ':' << setw(2) << right << setfill('0') << m << ':' << setw(2) << right << setfill('0') << s;
				return 0;
			}
		}// namespace b1026

		namespace b1027 {
			int main(istream &cin, ostream &cout) {
				unsigned int n;
				char ch;
				cin >> n >> ch;
				int i = 1;
				while((i + 1) * (i + 1) / 2 - 1 <= n) {
					i += 2;
				}
				i -= 2;
				for(int j = 0; j < (i + 1) / 2; ++j) {
					for(int k = 0; k < j; k++) {
						cout << ' ';
					}
					for(int k = 0; k < i - 2 * j; k++) {
						cout << ch;
					}
					cout << endl;
				}
				for(int j = (i + 1) / 2 - 2; j >= 0; --j) {
					for(int k = 0; k < j; k++) {
						cout << ' ';
					}
					for(int k = 0; k < i - 2 * j; k++) {
						cout << ch;
					}
					cout << endl;
				}
				cout << n - ((i + 1) * (i + 1) / 2 - 1);
				return 0;
			}
		}// namespace b1027

		namespace b1028 {
			bool is_valid(int year, int month, int day) {
				if(year > 2014) {
					return false;
				}
				if(year == 2014 && month > 9) {
					return false;
				}
				if(year == 2014 && month == 9 && day > 6) {
					return false;
				}
				if(year < 1814) {
					return false;
				}
				if(year == 1814 && month < 9) {
					return false;
				}
				if(year == 1814 && month == 9 && day < 6) {
					return false;
				}
				return true;
			}

			int main(istream &cin, ostream &cout) {
				int n;
				int count = 0;
				cin >> n;
				auto oldest   = Person(2014, 9, 6);
				auto youngest = Person(1814, 9, 6);
				for(int i = 0; i < n; i++) {
					Person p;
					cin >> p.name >> p.year;
					cin.get();
					cin >> p.month;
					cin.get();
					cin >> p.day;
					if(is_valid(p.year, p.month, p.day)) {
						count++;
						if(p < oldest) {
							oldest = p;
						}
						if(youngest < p) {
							youngest = p;
						}
					}
				}
				if(count > 0) {
					cout << count << ' ' << oldest.name << ' ' << youngest.name;
				} else {
					cout << 0;
				}
				return 0;
			}

			bool Person::operator<(const Person &p) const {
				if(this->year < p.year) {
					return true;
				}
				if(this->year == p.year && this->month < p.month) {
					return true;
				}
				if(this->year == p.year && this->month == p.month && this->day < p.day) {
					return true;
				}
				return false;
			}
		}// namespace b1028

		namespace b1029 {
			int main(istream &cin, ostream &cout) {
				unordered_set<char> bad;
				unordered_set<char> s;
				string good_str;
				string bad_str;
				cin >> good_str;
				cin >> bad_str;
				for(char ch: bad_str) {
					ch = toupper(ch);
					bad.insert(ch);
				}
				for(char ch: good_str) {
					ch = toupper(ch);
					if(!bad.contains(ch) && !s.contains(ch)) {
						cout << ch;
						s.insert(ch);
					}
				}
				return 0;
			}
		}// namespace b1029

		namespace b1030 {
			int main(istream &cin, ostream &cout) {
				unsigned int n;
				unsigned int p;
				cin >> n >> p;
				vector<unsigned int> vec(n);
				for(unsigned int i = 0; i < n; i++) {
					cin >> vec[i];
				}
				sort(vec.begin(), vec.end());
				unsigned int ans = 0;
				for(unsigned i = 0; i < vec.size(); i++) {
					unsigned diff = upper_bound(vec.begin(), vec.end(), vec[i] * p) - (vec.begin() + i);
					ans           = max(ans, diff);
				}
				cout << ans;
				return 0;
			}
		}// namespace b1030

		namespace b1031 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				const char captcha[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
				const int weight[17]   = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
				bool flag              = true;
				for(int i = 0; i < n; i++) {
					string str;
					cin >> str;
					int sum = 0;
					for(int j = 0; j < 17; j++) {
						sum += weight[j] * (str[j] - '0');
					}
					sum %= 11;
					if(str[17] != captcha[sum]) {
						cout << str << endl;
						flag = false;
					}
				}
				if(flag) {
					cout << "All passed";
				}
				return 0;
			}
		}// namespace b1031

		namespace b1032 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				unordered_map<int, unsigned long long> um;
				unsigned long long maximum_score = 0;
				int maximum_id;
				for(int i = 0; i < n; i++) {
					int id;
					int score;
					cin >> id >> score;
					um[id] += score;
					if(um[id] >= maximum_score) {
						maximum_score = um[id];
						maximum_id    = id;
					}
				}
				cout << maximum_id << ' ' << maximum_score;
				return 0;
			}
		}// namespace b1032

		namespace b1033 {
			int main(istream &cin, ostream &cout) {
				unordered_set<char> broken;
				string str1;
				string str2;
				cin >> str1 >> str2;
				if(str2.empty()) {
					cout << str1;
					return 0;
				}
				bool shift = true;
				for(char ch: str1) {
					broken.insert(ch);
					if(ch == '+') {
						shift = false;
					}
				}
				for(const char ch: str2) {
					if(!(broken.contains(toupper(ch)) || !shift && isupper(ch) != 0)) {
						cout << ch;
					}
				}
				return 0;
			}
		}// namespace b1033

		namespace b1034 {
			int main(istream &cin, ostream &cout) {
				long long numerator1;
				long long numerator2;
				long long denominator1;
				long long denominator2;
				char ch;
				cin >> numerator1 >> ch >> denominator1 >> numerator2 >> ch >> denominator2;
				const Fraction frac1(true, numerator1, denominator1);
				const Fraction frac2(true, numerator2, denominator2);
				cout << frac1 << " + " << frac2 << " = " << frac1 + frac2 << endl
				     << frac1 << " - " << frac2 << " = " << frac1 - frac2 << endl
				     << frac1 << " * " << frac2 << " = " << frac1 * frac2 << endl
				     << frac1 << " / " << frac2 << " = " << frac1 / frac2;
				return 0;
			}
		}// namespace b1034

		namespace b1035 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				vector<int> vec1(n);
				vector<int> vec2(n);
				for(int i = 0; i < n; i++) {
					cin >> vec1[i];
				}
				for(int i = 0; i < n; i++) {
					cin >> vec2[i];
				}
				int i = n - 1;
				for(; i >= 0 && vec1[i] == vec2[i]; --i) {}
				vector<int> sorted_vec = vec1;
				sort(sorted_vec.begin(), sorted_vec.begin() + i + 1);
				bool insertion = true;
				for(int j = 0; j <= i; j++) {
					if(sorted_vec[j] != vec2[j]) {
						insertion = false;
						break;
					}
				}
				if(insertion) {
					//插入排序
					cout << "Insertion Sort" << endl;
					int j = n - 1;
					for(; j >= 0; --j) {
						vector vec1_cpy = vec1;
						sort(vec1_cpy.begin(), vec1_cpy.begin() + j);
						if(vec1_cpy == vec2) {
							break;
						}
					}
					sort(vec1.begin(), vec1.begin() + j + 1);
					for(int k = 0; k < n; k++) {
						cout << vec1[k];
						if(k != n - 1) {
							cout << ' ';
						}
					}
					return 0;
				}
				//归并排序
				cout << "Merge Sort" << endl;
				int factor = 1;
				bool flag  = false;
				while(true) {
					factor *= 2;
					int j = 0;
					for(; (j + 1) * factor <= n; j++) {
						sort(vec1.begin() + j * factor, vec1.begin() + (j + 1) * factor);
					}
					if(j * factor < n) {
						sort(vec1.begin() + j * factor, vec1.end());
					}
					if(flag) {
						for(int k = 0; k < n; k++) {
							cout << vec1[k];
							if(k != n - 1) {
								cout << ' ';
							}
						}
						return 0;
					}
					if(vec1 == vec2) {
						flag = true;
					}
				}
			}
		}// namespace b1035

		namespace b1036 {
			int main(istream &cin, ostream &cout) {
				int n;
				char c;
				cin >> n >> c;
				for(int i = 0; i < n; i++) {
					cout << c;
				}
				cout << endl;
				for(int i = 0; i < (n + 1) / 2 - 2; i++) {
					cout << c;
					for(int j = 0; j < n - 2; j++) {
						cout << ' ';
					}
					cout << c << endl;
				}
				for(int i = 0; i < n; i++) {
					cout << c;
				}
				return 0;
			}
		}// namespace b1036

		namespace b1037 {
			int main(istream &cin, ostream &cout) {
				unsigned long long galleon;
				unsigned long long sickle;
				unsigned long long knut;
				char ch;
				unsigned long long sum[2];
				for(int i = 0; i < 2; i++) {
					cin >> galleon >> ch >> sickle >> ch >> knut;
					sum[i] = galleon * 17 * 29 + sickle * 29 + knut;
				}
				const bool positive = sum[0] <= sum[1];
				unsigned long long diff;
				if(positive) {
					diff = sum[1] - sum[0];
				} else {
					diff = sum[0] - sum[1];
				}
				galleon = diff / (17 * 29);
				diff %= 17 * 29;
				sickle = diff / 29;
				diff %= 29;
				knut = diff;
				if(!positive) {
					cout << '-';
				}
				cout << galleon << '.' << sickle << '.' << knut;
				return 0;
			}
		}// namespace b1037

		namespace b1038 {
			int main(istream &cin, ostream &cout) {
				unordered_map<int, int> um;
				int n;
				cin >> n;
				int score;
				for(int i = 0; i < n; i++) {
					cin >> score;
					um[score]++;
				}
				cin >> n;
				for(int i = 0; i < n; i++) {
					cin >> score;
					cout << um[score];
					if(i != n - 1) {
						cout << ' ';
					}
				}
				return 0;
			}
		}// namespace b1038

		namespace b1039 {
			int main(istream &cin, ostream &cout) {
				string str1;
				string str2;
				cin >> str1 >> str2;
				unordered_map<char, int> um;
				for(char ch: str1) {
					um[ch]++;
				}
				bool yes = true;
				for(char ch: str2) {
					um[ch]--;
					if(um[ch] < 0) {
						yes = false;
					}
				}
				int sum = 0;
				for(auto [ch, count]: um) {
					if(yes && count > 0) {
						sum += count;
					} else if(!yes && count < 0) {
						sum -= count;
					}
				}
				cout << (yes ? "Yes " : "No ") << sum;
				return 0;
			}
		}// namespace b1039

		namespace b1040 {
			int main(istream &cin, ostream &cout) {
				string str;
				cin >> str;
				vector<unsigned long long> p(str.length(), 0);
				vector<unsigned long long> t(str.length(), 0);
				unsigned long long current_p = 0;
				for(int i = 0; i < p.size(); ++i) {
					p[i] = current_p;
					if(str[i] == 'P') {
						current_p++;
					}
				}
				unsigned long long current_t = 0;
				for(int i = t.size() - 1; i >= 0; --i) {
					t[i] = current_t;
					if(str[i] == 'T') {
						current_t++;
					}
				}
				unsigned long long ans = 0;
				for(int i = 0; i < p.size(); i++) {
					if(str[i] == 'A') {
						ans += p[i] * t[i] % 1000000007;
						ans %= 1000000007;
					}
				}
				cout << ans;
				return 0;
			}
		}// namespace b1040

		namespace b1041 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				unordered_map<int, student> um;
				for(int i = 0; i < n; i++) {
					student stu;
					cin >> stu.id >> stu.seat1 >> stu.seat2;
					um[stu.seat1] = stu;
				}
				cin >> n;
				int seat1;
				for(int i = 0; i < n; i++) {
					cin >> seat1;
					student stu = um[seat1];
					cout << stu.id << ' ' << stu.seat2 << endl;
				}
				return 0;
			}
		}// namespace b1041

		namespace b1042 {
			int main(istream &cin, ostream &cout) {
				auto *str = new char[1001];
				cin.getline(str, 1001);
				map<char, int> m;
				int maximum = 0;
				for(int i = 0; i < strlen(str); ++i) {
					char ch = tolower(str[i]);
					if(isalpha(ch) != 0) {
						m[ch]++;
						maximum = max(maximum, m[ch]);
					}
				}
				for(auto [ch, cnt]: m) {
					if(cnt == maximum) {
						cout << ch << ' ' << cnt;
						break;
					}
				}
				delete[] str;
				return 0;
			}
		}// namespace b1042

		namespace b1043 {
			int main(istream &cin, ostream &cout) {
				unordered_map<char, unsigned> um;
				const char patest[6] = {'P', 'A', 'T', 'e', 's', 't'};
				um['P']              = 0;
				um['A']              = 0;
				um['T']              = 0;
				um['e']              = 0;
				um['s']              = 0;
				um['t']              = 0;
				string str;
				cin >> str;
				for(char ch: str) {
					if(um.contains(ch)) {
						um[ch]++;
					}
				}
				unsigned minimum = 10000;
				for(const auto &[ch, count]: um) {
					minimum = min(minimum, count);
				}
				for(auto &[ch, count]: um) {
					count -= minimum;
				}
				for(unsigned i = 0; i < minimum; i++) {
					cout << "PATest";
				}
				bool flag = true;
				while(flag) {
					flag = false;
					for(unsigned i = 0; i < 6; i++) {
						if(um[patest[i]] > 0) {
							cout << patest[i];
							um[patest[i]]--;
							flag = true;
						}
					}
				}
				return 0;
			}
		}// namespace b1043

		namespace b1044 {
			int main(istream &cin, ostream &cout) {
				string abc[13]  = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
				string abc2[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
				unordered_map<string, int> um;
				unordered_set<string> us2;
				for(int i = 0; i < 13; i++) {
					us2.insert(abc2[i]);
					um[abc[i]]  = i;
					um[abc2[i]] = i;
				}
				int n;
				cin >> n;
				char cccc[16];
				cin.getline(cccc, 16);
				while(n-- != 0) {
					auto *cstr = new char[1024];
					cin.getline(cstr, 1024);
					stringstream ss;
					ss << cstr;
					if(isdigit(ss.peek()) != 0) {
						// 地球数字
						unsigned long long num;
						ss >> num;
						vector<string> output;
						bool flag = true;
						if(num == 0) {
							cout << "tret";
						} else {
							while(num != 0) {
								if(flag) {
									if(num % 13 != 0) {
										output.push_back(abc[num % 13]);
									}
									flag = false;
								} else {
									output.push_back(abc2[num % 13]);
								}
								num /= 13;
							}
							for(auto it = output.rbegin(); it != output.rend(); ++it) {
								cout << *it;
								if(it + 1 != output.rend()) {
									cout << ' ';
								}
							}
						}
					} else {
						// 火星数字
						int b = 0;
						for(int i = 0; cstr[i] != '\0'; i++) {
							if(cstr[i] == ' ') {
								b++;
							}
						}
						b++;
						string str;
						unsigned long long num = 0;
						while(b != 0) {
							ss >> str;
							num += um[str] * pow(13, --b);
						}
						if(us2.contains(str)) {
							num *= 13;
						}
						cout << num;
					}
					delete[] cstr;
					if(n != 0) {
						cout << endl;
					}
				}
				return 0;
			}
		}// namespace b1044

		namespace b1045 {
			int main(istream &cin, ostream &cout) {
				unsigned n;
				cin >> n;
				vector<unsigned> vec(n);
				vector<unsigned> l_max(n);
				vector<unsigned> r_min(n);
				unsigned current = 0;
				for(unsigned i = 0; i < n; ++i) {
					cin >> vec[i];
					l_max[i] = current;
					current  = max(current, vec[i]);
				}
				current = 1000000001;
				for(int i = n - 1; i >= 0; --i) {
					r_min[i] = current;
					current  = min(current, vec[i]);
				}
				vector<unsigned> ans;
				for(unsigned i = 0; i < n; ++i) {
					if(vec[i] > l_max[i] && vec[i] < r_min[i]) {
						ans.push_back(vec[i]);
					}
				}
				cout << ans.size() << endl;
				for(int i = 0; i < ans.size(); i++) {
					cout << ans[i];
					if(i != ans.size() - 1) {
						cout << ' ';
					}
				}
				cout << endl;
				return 0;
			}
		}// namespace b1045

		namespace b1046 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				int ans1 = 0;
				int ans2 = 0;
				while(n-- != 0) {
					int a1;
					int a2;
					int b1;
					int b2;
					cin >> a1 >> a2 >> b1 >> b2;
					const int sum = a1 + b1;
					if(sum == a2 && sum != b2) {
						ans2++;
					} else if(sum == b2 && sum != a2) {
						ans1++;
					}
				}
				cout << ans1 << ' ' << ans2;
				return 0;
			}
		}// namespace b1046

		namespace b1047 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				unordered_map<int, int> um;
				int maximum = 0;
				while(n-- != 0) {
					int a;
					cin >> a;
					cin.get();
					int b;
					cin >> b >> b;
					um[a] += b;
				}
				for(const auto &[team, score]: um) {
					maximum = max(score, maximum);
				}
				for(const auto &[team, score]: um) {
					if(score == maximum) {
						cout << team << ' ' << score;
						return 0;
					}
				}
				return 1;
			}
		}// namespace b1047

		namespace b1048 {
			int main(istream &cin, ostream &cout) {
				string a;
				string b;
				cin >> a >> b;
				vector<char> ans;
				int i = 1;
				for(; i <= max(b.length(), a.length()); ++i) {
					const int bi = b.length() >= i ? b[b.length() - i] - '0' : 0;
					const int ai = a.length() >= i ? a[a.length() - i] - '0' : 0;
					if(i % 2 != 0) {
						char ret = (ai + bi) % 13;
						switch(ret) {
							case 10:
								ret = 'J';
								break;
							case 11:
								ret = 'Q';
								break;
							case 12:
								ret = 'K';
								break;
							default:
								ret += '0';
								break;
						}
						ans.push_back(ret);
					} else {
						int ret = bi - ai;
						if(ret < 0) {
							ret += 10;
						}
						ans.push_back(ret + '0');
					}
				}
				for(auto it = ans.rbegin(); it != ans.rend(); ++it) {
					cout << *it;
				}
				return 0;
			}
		}// namespace b1048

		namespace b1049 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				long double num;
				long double ans = 0;
				for(int i = 0; i < n; ++i) {
					cin >> num;
					ans += num * (n - i) * (i + 1);
				}
				cout << fixed << setprecision(2) << ans;
				return 0;
			}
		}// namespace b1049

		namespace b1050 {
			int main(istream &cin, ostream &cout) {
				int N;
				cin >> N;
				int m = N;
				int n = 1;
				for(int i = 1; i * i <= N; ++i) {
					if(N % i == 0) {
						n = i;
						m = N / i;
					}
				}
				vector matrix(m, vector(n, 0));
				vector<int> vec(N);
				for(int i = 0; i < N; i++) {
					cin >> vec[i];
				}
				sort(vec.rbegin(), vec.rend());
				int direction = 0;//0 右  1 下  2 左  3 上
				int x         = 0;
				int y         = 0;
				int current   = 0;
				matrix[0][0]  = vec[current];
				--N;
				while(N != 0) {
					int next_x = x;
					int next_y = y;
					switch(direction) {
						case 0:
							next_y += 1;
							break;
						case 1:
							next_x += 1;
							break;
						case 2:
							next_y -= 1;
							break;
						case 3:
							next_x -= 1;
							break;
					}
					if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || matrix[next_x][next_y] != 0) {
						direction += 1;
						direction %= 4;
					} else {
						matrix[next_x][next_y] = vec[++current];
						x                      = next_x;
						y                      = next_y;
						N--;
					}
				}
				for(int i = 0; i < m; i++) {
					for(int j = 0; j < n; j++) {
						cout << matrix[i][j];
						if(j != n - 1) {
							cout << ' ';
						}
					}
					if(i != m - 1) {
						cout << endl;
					}
				}
				return 0;
			}
		}// namespace b1050

		namespace b1051 {
			int main(istream &cin, ostream &cout) {
				long double r1;
				long double p1;
				long double r2;
				long double p2;
				cin >> r1 >> p1 >> r2 >> p2;
				const long double a1 = r1 * cos(p1);
				const long double a2 = r2 * cos(p2);
				const long double b1 = r1 * sin(p1);
				const long double b2 = r2 * sin(p2);
				long double a        = a1 * a2 - b1 * b2;
				long double b        = a1 * b2 + a2 * b1;
				if(a < 0 && a + 0.005 >= 0) {
					a += 0.005;
				}
				if(b < 0 && b + 0.005 >= 0) {
					b += 0.005;
				}
				cout << fixed << setprecision(2) << a << fixed << setprecision(2) << showpos << b << 'i';
				return 0;
			}
		}// namespace b1051

		namespace b1052 {
			int main(istream &cin, ostream &cout) {
				vector<string> vec[3];
				char line[1024];
				for(int a = 0; a < 3; a++) {
					cin.getline(line, sizeof line);
					int i = 0;
					int j = 0;
					while(i < strlen(line) && j < strlen(line)) {
						while(line[i] != '[' && i < strlen(line)) {
							++i;
						}
						while(line[j] != ']' && j < strlen(line)) {
							++j;
						}
						if(i < strlen(line) && j < strlen(line)) {
							ostringstream oss;
							for(int m = i + 1; m < j; ++m) {
								oss << line[m];
							}
							vec[a].push_back(oss.str());
							++i;
							++j;
						}
					}
				}
				int k;
				cin >> k;
				while(k-- != 0) {
					ostringstream oss;
					int a;
					int b;
					int c;
					int d;
					int e;
					cin >> a >> b >> c >> d >> e;
					--a;
					--b;
					--c;
					--d;
					--e;
					if(a < vec[0].size()) {
						oss << vec[0][a];
					} else {
						goto END;
					}
					oss << '(';
					if(b < vec[1].size()) {
						oss << vec[1][b];
					} else {
						goto END;
					}
					if(c < vec[2].size()) {
						oss << vec[2][c];
					} else {
						goto END;
					}
					if(d < vec[1].size()) {
						oss << vec[1][d];
					} else {
						goto END;
					}
					oss << ')';
					if(e < vec[0].size()) {
						oss << vec[0][e];
					} else {
						goto END;
					}
					cout << oss.str() << endl;
					continue;
				END:;
					cout << "Are you kidding me? @\\/@" << endl;
				}
				return 0;
			}
		}// namespace b1052

		namespace b1053 {
			int main(istream &cin, ostream &cout) {
				int n;
				double e;
				int d;
				int cnt1 = 0;
				int cnt2 = 0;
				cin >> n >> e >> d;
				for(int i = 0; i < n; ++i) {
					int k;
					cin >> k;
					int cnt = 0;
					for(int j = 0; j < k; ++j) {
						double E;
						cin >> E;
						if(E < e) {
							cnt++;
						}
					}
					if(2 * cnt > k) {
						if(k > d) {
							cnt2++;
						} else {
							cnt1++;
						}
					}
				}
				double ans1 = static_cast<double>(cnt1) / n * 100;
				double ans2 = static_cast<double>(cnt2) / n * 100;
				cout << fixed << setprecision(1) << ans1 << "% " << fixed << setprecision(1) << ans2 << '%';
				return 0;
			}
		}// namespace b1053

		namespace b1054 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				string x;
				long double sum = 0;
				int k           = 0;
				while(n--) {
					cin >> x;
					bool flag = true;
					int start = 0;
					if(x[0] == '-') {
						if(x.length() > 1) {
							start = 1;
						} else {
							goto ERROR;
						}
					}
					if(x.length() > 8) {
						goto ERROR;
					}
					if(isdigit(x[start])) {
						int pos = -1;
						for(int i = start + 1; i < x.length(); ++i) {
							if(x[i] == '.') {
								if(flag) {
									flag = false;
									pos  = i;
								} else {
									goto ERROR;
								}
							} else if(!isdigit(x[i])) {
								goto ERROR;
							}
						}
						if(!flag) {
							if(pos + 3 < x.length()) {
								goto ERROR;
							}
						}
						stringstream ss;
						ss << x;
						if(flag) {
							int num;
							ss >> num;
							if(num >= -1000 && num <= 1000) {
								sum += num;
								k++;
							} else {
								goto ERROR;
							}
						} else {
							long double num;
							ss >> num;
							if(num >= -1000 && num <= 1000) {
								sum += num;
								k++;
							} else {
								goto ERROR;
							}
						}
					} else {
					ERROR:
						cout << "ERROR: " << x << " is not a legal number" << endl;
					}
				}
				if(k == 0) {
					cout << "The average of 0 numbers is Undefined" << endl;
				} else {
					long double y = sum / k;
					cout << "The average of " << k << " number" << (k == 1 ? "" : "s") << " is " << fixed << setprecision(2) << y << endl;
				}
				return 0;
			}
		}// namespace b1054

		namespace b1055 {
			int main(istream &cin, ostream &cout) {
				int n, k;
				cin >> n >> k;
				vector<Person> vec(n);
				for(int i = 0; i < n; i++) {
					string name;
					int height;
					cin >> name >> height;
					Person p = Person{name, height};
					vec[i]   = p;
				}
				sort(vec.begin(), vec.end());
				vector<deque<Person>> deq(k);
				for(int i = 0; i < n / k + n % k; i++) {
					if(i % 2 == 1) {
						deq[k - 1].push_front(vec.back());
					} else {
						deq[k - 1].push_back(vec.back());
					}
					vec.pop_back();
				}
				for(int i = k - 2; i >= 0; i--) {
					for(int j = 0; j < n / k; j++) {
						if(j % 2 == 1) {
							deq[i].push_front(vec.back());
						} else {
							deq[i].push_back(vec.back());
						}
						vec.pop_back();
					}
				}
				for(int i = k - 1; i >= 0; i--) {
					for(int j = 0; j < deq[i].size(); j++) {
						cout << deq[i][j].name;
						if(j != deq[i].size() - 1) {
							cout << ' ';
						}
					}
					if(i != 0) {
						cout << endl;
					}
				}
				return 0;
			}

			bool Person::operator<(const Person &p) const {
				if(this->height < p.height) {
					return true;
				}
				if(this->height > p.height) {
					return false;
				}
				if(this->name > p.name) {
					return true;
				} else {
					return false;
				}
			}
		}// namespace b1055

		namespace b1056 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				unsigned short num;
				int ans = 0;
				for(int i = 0; i < n; i++) {
					cin >> num;
					ans += num * (n - 1) * 11;
				}
				cout << ans;
				return 0;
			}
		}// namespace b1056

		namespace b1057 {
			int main(istream &cin, ostream &cout) {
				char str[100010];
				cin.getline(str, 100010);
				unsigned n = 0;
				for(int i = 0; str[i] != '\0'; i++) {
					if(isupper(str[i])) {
						n += str[i] - 'A' + 1;
					} else if(islower(str[i])) {
						n += str[i] - 'a' + 1;
					}
				}
				int one  = 0;
				int zero = 0;
				while(n != 0) {
					if((n & 1) == 1) {
						one++;
					} else {
						zero++;
					}
					n >>= 1;
				}
				cout << zero << ' ' << one;
				return 0;
			}
		}// namespace b1057

		namespace b1058 {
			int main(istream &cin, ostream &cout) {
				int n, m;
				cin >> n >> m;
				int max_error = 0;
				vector<Problem> problems(m);
				for(int i = 0; i < m; i++) {
					Problem p;
					cin >> p.score;
					cin >> p.num;
					cin >> p.correct_num;
					p.correct_choices = unordered_set<char>();
					for(int j = 0; j < p.correct_num; j++) {
						char choice;
						cin >> choice;
						p.correct_choices.insert(choice);
					}
					p.error_count = 0;
					problems[i]   = p;
				}
				for(int i = 0; i < n; i++) {
					int score = 0;
					for(int j = 0; j < m; j++) {
						char ch;
						cin >> ch;
						int num;
						cin >> num;
						unordered_set<char> answer;
						for(int k = 0; k < num; k++) {
							char choice;
							cin >> choice;
							answer.insert(choice);
						}
						if(answer == problems[j].correct_choices) {
							score += problems[j].score;
						} else {
							problems[j].error_count++;
							max_error = max(max_error, problems[j].error_count);
						}
						cin >> ch;
					}
					cout << score << endl;
				}
				if(max_error == 0) {
					cout << "Too simple";
				} else {
					vector<int> max_problems;
					cout << max_error << ' ';
					for(int i = 0; i < m; i++) {
						if(problems[i].error_count == max_error) {
							max_problems.push_back(i + 1);
						}
					}
					for(int i = 0; i < max_problems.size(); i++) {
						cout << max_problems[i];
						if(i != max_problems.size() - 1) {
							cout << ' ';
						}
					}
				}
				return 0;
			}
		}// namespace b1058

		namespace b1059 {
			bool is_prime(int n) {
				for(int i = 2; i <= sqrt(n); i++) {
					if(n % i == 0) {
						return false;
					}
				}
				return true;
			}

			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				unordered_map<string, string> um;
				for(int rank = 1; rank <= n; rank++) {
					string id;
					cin >> id;
					if(rank == 1) {
						um[id] = "Mystery Award";
					} else if(is_prime(rank)) {
						um[id] = "Minion";
					} else {
						um[id] = "Chocolate";
					}
				}
				int k;
				cin >> k;
				while(k--) {
					string id;
					cin >> id;
					if(!um.count(id)) {
						cout << id << ": Are you kidding?" << endl;
					} else {
						cout << id << ": " << um[id] << endl;
						um[id] = "Checked";
					}
				}
				return 0;
			}
		}// namespace b1059

		namespace b1060 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				vector<int> vec(n + 1);
				for(int i = 1; i <= n; i++) {
					cin >> vec[i];
				}
				sort(vec.begin(), vec.end());
				int e = 1;
				int i = n;
				while(e <= n && vec[i] > e) {
					e++;
					i--;
				}
				cout << e - 1;
				return 0;
			}
		}// namespace b1060

		namespace b1061 {
			int main(istream &cin, ostream &cout) {
				int n, m;
				cin >> n >> m;
				vector<int> scores(m);
				for(int i = 0; i < m; i++) {
					cin >> scores[i];
				}
				vector<int> correct_answer(m);
				for(int i = 0; i < m; i++) {
					cin >> correct_answer[i];
				}
				for(int i = 0; i < n; i++) {
					int score = 0;
					for(int j = 0; j < m; j++) {
						int answer;
						cin >> answer;
						if(answer == correct_answer[j]) {
							score += scores[j];
						}
					}
					cout << score << endl;
				}
				return 0;
			}
		}// namespace b1061
	}    // namespace b

	namespace a {}

	namespace top {}
}// namespace pat
