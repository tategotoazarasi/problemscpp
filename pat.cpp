#include "pat.h"
#include "templates.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
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
				const double ans1 = static_cast<double>(cnt1) / n * 100;
				const double ans2 = static_cast<double>(cnt2) / n * 100;
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
				while(n-- != 0) {
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
					if(isdigit(x[start]) != 0) {
						int pos = -1;
						for(int i = start + 1; i < x.length(); ++i) {
							if(x[i] == '.') {
								if(flag) {
									flag = false;
									pos  = i;
								} else {
									goto ERROR;
								}
							} else if(isdigit(x[i]) == 0) {
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
					const long double y = sum / k;
					cout << "The average of " << k << " number" << (k == 1 ? "" : "s") << " is " << fixed << setprecision(2) << y << endl;
				}
				return 0;
			}
		}// namespace b1054

		namespace b1055 {
			int main(istream &cin, ostream &cout) {
				int n;
				int k;
				cin >> n >> k;
				vector<Person> vec(n);
				for(int i = 0; i < n; i++) {
					string name;
					int height;
					cin >> name >> height;
					const auto p = Person{name, height};
					vec[i]       = p;
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
				return this->name > p.name;
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
					if(isupper(str[i]) != 0) {
						n += str[i] - 'A' + 1;
					} else if(islower(str[i]) != 0) {
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
				int n;
				int m;
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
				while(k-- != 0) {
					string id;
					cin >> id;
					if(static_cast<unsigned int>(um.contains(id)) == 0U) {
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
				int n;
				int m;
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

		namespace b1062 {
			int main(istream &cin, ostream &cout) {
				char ch;
				double n1;
				double n2;
				int m1;
				int m2;
				int k;
				cin >> n1 >> ch >> m1 >> n2 >> ch >> m2 >> k;
				n1 *= k;
				n1 /= m1;
				n2 *= k;
				n2 /= m2;
				if(n1 > n2) {
					swap(n1, n2);
				}
				bool flag = true;
				for(int i = ceil(n1) == n1 ? n1 + 1 : ceil(n1); i < n2; i++) {
					const int f = gcd(i, k);
					if(f == 1) {
						if(flag) {
							cout << i / f << '/' << k;
							flag = false;
						} else {
							cout << ' ' << i / f << '/' << k;
						}
					}
				}
				return 0;
			}
		}// namespace b1062

		namespace b1063 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				double ans = 0;
				while(n-- != 0) {
					int a;
					int b;
					cin >> a >> b;
					ans = max(ans, sqrt(a * a + b * b));
				}
				cout << fixed << setprecision(2) << ans;
				return 0;
			}
		}// namespace b1063

		namespace b1064 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				set<int> s;
				while(n-- != 0) {
					string str;
					cin >> str;
					int sum = 0;
					for(const char ch: str) {
						sum += ch - '0';
					}
					s.insert(sum);
				}
				cout << s.size() << endl;
				for(auto i = s.begin(); i != s.end(); ++i) {
					cout << *i;
					if(*i != *s.rbegin()) {
						cout << ' ';
					}
				}
				return 0;
			}
		}// namespace b1064

		namespace b1066 {
			int main(istream &cin, ostream &cout) {
				int m;
				int n;
				int a;
				int b;
				int g;
				cin >> m >> n >> a >> b >> g;
				for(int i = 0; i < m; i++) {
					for(int j = 0; j < n; j++) {
						int v;
						cin >> v;
						if(a <= v && v <= b) {
							cout << setw(3) << right << setfill('0') << g;
						} else {
							cout << setw(3) << right << setfill('0') << v;
						}
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
		}// namespace b1066

		namespace b1065 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				unordered_map<string, string> um;
				set<string> s;
				for(int i = 0; i < n; i++) {
					string id1;
					string id2;
					cin >> id1 >> id2;
					um[id1] = id2;
					um[id2] = id1;
				}
				int m;
				cin >> m;
				for(int i = 0; i < m; i++) {
					string id;
					cin >> id;
					if(um.contains(id)) {
						s.erase(um[id]);
					} else {
						s.insert(id);
					}
				}
				cout << s.size() << endl;
				for(auto it = s.begin(); it != s.end(); ++it) {
					cout << *it;
					if(*it != *s.rbegin()) {
						cout << ' ';
					}
				}
				return 0;
			}
		}// namespace b1065

		namespace b1067 {
			int main(istream &cin, ostream &cout) {
				string pwd;
				int n;
				cin >> pwd >> n;
				int cnt = 0;
				char s[1024];
				cin.getline(s, 1024);
				while(true) {
					cin.getline(s, 1024);
					auto str = string(s);
					if(str == "#") {
						return 0;
					}
					if(cnt == n) {
						cout << "Account locked";
						return 0;
					}
					if(str != pwd) {
						cout << "Wrong password: " << str << endl;
						cnt++;
						if(cnt == n) {
							cout << "Account locked";
							return 0;
						}
					} else {
						cout << "Welcome in";
						return 0;
					}
				}
			}
		}// namespace b1067

		namespace b1068 {
			int main(istream &cin, ostream &cout) {
				long m;
				long n;
				long tol;
				cin >> m >> n >> tol;
				vector grid(n, vector<long>(m));
				unordered_map<long, unsigned long> um_cnt;
				unordered_map<long, long> um_x;
				unordered_map<long, long> um_y;
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < m; j++) {
						cin >> grid[i][j];
						um_cnt[grid[i][j]]++;
						um_x[grid[i][j]] = i;
						um_y[grid[i][j]] = j;
					}
				}
				long ans_x;
				long ans_y;
				long ans_v;
				bool has_ans = false;
				for(auto [v, cnt]: um_cnt) {
					if(cnt == 1) {
						long x                           = um_x[v];
						long y                           = um_y[v];
						pair<long, long> surroundings[8] = {make_pair(x - 1, y - 1), make_pair(x - 1, y), make_pair(x - 1, y + 1),
						                                    make_pair(x, y - 1), make_pair(x, y + 1),
						                                    make_pair(x + 1, y - 1), make_pair(x + 1, y), make_pair(x + 1, y + 1)};
						bool flag                        = true;
						for(auto [s_x, s_y]: surroundings) {
							if(s_x >= 0 && s_x < n && s_y >= 0 && s_y < m) {
								const long dist = abs(v - grid[s_x][s_y]);
								if(dist <= tol) {
									flag = false;
									break;
								}
							}
						}
						if(flag) {
							if(!has_ans) {
								ans_x   = x + 1;
								ans_y   = y + 1;
								ans_v   = v;
								has_ans = true;
							} else {
								cout << "Not Unique";
								return 0;
							}
						}
					}
				}
				if(has_ans) {
					cout << '(' << ans_y << ", " << ans_x << "): " << ans_v;
				} else {
					cout << "Not Exist";
				}
				return 0;
			}
		}// namespace b1068

		namespace b1069 {
			int main(istream &cin, ostream &cout) {
				int m;
				int n;
				int s;
				cin >> m >> n >> s;
				string name;
				unordered_set<string> names;
				vector<string> list(m);
				int cnt = 0;
				for(int i = 0; i < m; i++) {
					cin >> list[i];
				}
				for(int i = s - 1; i < m;) {
					if(names.contains(list[i])) {
						i++;
						continue;
					}
					names.insert(list[i]);
					cout << list[i] << endl;
					cnt++;
					i += n;
				}
				if(cnt == 0) {
					cout << "Keep going...";
				}
				return 0;
			}
		}// namespace b1069

		namespace b1070 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				vector<int> vec(n);
				for(int i = 0; i < n; i++) {
					cin >> vec[i];
				}
				sort(vec.begin(), vec.end());
				int current = vec[0];
				for(int i = 1; i < n; i++) {
					current = (current + vec[i]) / 2;
				}
				cout << current;
				return 0;
			}
		}// namespace b1070

		namespace b1071 {
			int main(istream &cin, ostream &cout) {
				int t;
				int k;
				cin >> t >> k;
				while(k-- != 0) {
					int n1;
					int b;
					int tt;
					int n2;
					cin >> n1 >> b >> tt >> n2;
					if(tt > t) {
						cout << "Not enough tokens.  Total = " << t << '.' << endl;
						continue;
					}
					if(static_cast<int>(n2 > n1) == b) {
						t += tt;
						cout << "Win " << tt << "!  Total = " << t << '.' << endl;
					} else {
						t -= tt;
						cout << "Lose " << tt << ".  Total = " << t << '.' << endl;
					}
					if(t == 0) {
						cout << "Game Over.";
						return 0;
					}
				}
				return 0;
			}
		}// namespace b1071

		namespace b1072 {
			int main(istream &cin, ostream &cout) {
				int n;
				int m;
				cin >> n >> m;
				unordered_set<string> items;
				int stu_cnt  = 0;
				int item_cnt = 0;
				while(m-- != 0) {
					string item;
					cin >> item;
					items.insert(item);
				}
				for(int i = 0; i < n; i++) {
					string name;
					int k;
					cin >> name >> k;
					vector<string> vec;
					for(int j = 0; j < k; j++) {
						string item;
						cin >> item;
						if(items.contains(item)) {
							vec.push_back(item);
						}
					}
					item_cnt += vec.size();
					if(!vec.empty()) {
						stu_cnt++;
						cout << name << ':';
						for(const auto &item: vec) {
							cout << ' ' << item;
						}
						cout << endl;
					}
				}
				cout << stu_cnt << ' ' << item_cnt;
				return 0;
			}
		}// namespace b1072

		namespace b1073 {
			int main(istream &cin, ostream &cout) {
				int n;
				int m;
				cin >> n >> m;
				vector<problem> problems(m);
				map<pair<int, char>, int> noe;
				int max_cnt = 0;
				for(int i = 0; i < m; i++) {
					problem p;
					p.id = i + 1;
					cin >> p.score >> p.noa >> p.noca;
					p.ca = unordered_set<char>();
					for(int j = 0; j < p.noca; j++) {
						char ca;
						cin >> ca;
						p.ca.insert(ca);
					}
					problems[i] = p;
				}
				char ch;
				for(int i = 0; i < n; i++) {
					double score = 0;
					for(int j = 0; j < m; j++) {
						unordered_set<char> as;
						cin >> ch;
						int noa;
						cin >> noa;
						bool flag = true;
						for(int k = 0; k < noa; k++) {
							char a;
							cin >> a;
							as.insert(a);
							if(!problems[j].ca.contains(a)) {
								noe[make_pair(problems[j].id, a)]++;
								max_cnt = max(max_cnt, noe[make_pair(problems[j].id, a)]);
								flag    = false;
							}
						}
						cin >> ch;
						for(auto a: problems[j].ca) {
							if(!as.contains(a)) {
								noe[make_pair(problems[j].id, a)]++;
								max_cnt = max(max_cnt, noe[make_pair(problems[j].id, a)]);
							}
						}
						if(!flag) {
							continue;
						}
						if(noa == problems[j].noca) {
							score += problems[j].score;
						} else {
							score += static_cast<double>(problems[j].score) / 2;
						}
					}
					cout << fixed << setprecision(1) << score << endl;
				}
				if(noe.empty()) {
					cout << "Too simple";
				} else {
					for(const auto &[k, cnt]: noe) {
						if(cnt == max_cnt) {
							const auto &[id, a] = k;
							cout << cnt << ' ' << id << '-' << a << endl;
						}
					}
				}
				return 0;
			}
		}// namespace b1073

		namespace b1074 {
			int main(istream &cin, ostream &cout) {
				string str_n;
				string str_a;
				string str_b;
				cin >> str_n >> str_a >> str_b;
				vector<int> n;
				vector<int> a;
				vector<int> b;
				vector<int> ans;
				for(int i = str_n.length() - 1; i >= 0; i--) {
					if(str_n[i] == '0') {
						n.push_back(10);
					} else {
						n.push_back(str_n[i] - '0');
					}
				}
				for(int i = str_a.length() - 1; i >= 0; i--) {
					a.push_back(str_a[i] - '0');
				}
				for(int i = str_b.length() - 1; i >= 0; i--) {
					b.push_back(str_b[i] - '0');
				}
				int carry = 0;
				for(int i = 0; i < max(a.size(), b.size()) || carry != 0; i++) {
					const int radix = i < n.size() ? n[i] : 10;
					const int num_a = i < a.size() ? a[i] : 0;
					const int num_b = i < b.size() ? b[i] : 0;
					const int sum   = num_a + num_b + carry;
					ans.push_back(sum % radix);
					carry = sum / radix;
				}
				int i = ans.size() - 1;
				while(ans[i] == 0 && i > 0) {
					i--;
				}
				for(; i >= 0; i--) {
					cout << ans[i];
				}
				return 0;
			}
		}// namespace b1074

		namespace b1075 {
			int main(istream &cin, ostream &cout) {
				string current;
				int n;
				int k;
				cin >> current >> n >> k;
				unordered_map<string, Node> um;
				for(int i = 0; i < n; i++) {
					Node node;
					cin >> node.addr;
					cin >> node.data;
					cin >> node.next;
					um[node.addr] = node;
				}
				vector<Node> vec1;
				vector<Node> vec2;
				vector<Node> vec3;
				while(current != "-1") {
					Node node = um[current];
					if(node.data < 0) {
						vec1.push_back(node);
					} else if(node.data <= k) {
						vec2.push_back(node);
					} else {
						vec3.push_back(node);
					}
					current = node.next;
				}
				vector<Node> vec;
				vec.insert(vec.end(), vec1.begin(), vec1.end());
				vec.insert(vec.end(), vec2.begin(), vec2.end());
				vec.insert(vec.end(), vec3.begin(), vec3.end());
				for(int i = 0; i < vec.size(); i++) {
					Node node = vec[i];
					cout << node.addr << ' ' << node.data << ' ' << (i + 1 < vec.size() ? vec[i + 1].addr : "-1") << endl;
				}
				return 0;
			}
		}// namespace b1075

		namespace b1076 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				stringstream ss;
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < 4; j++) {
						char a;
						char b;
						char c;
						cin >> a >> b >> c;
						if(c == 'T') {
							ss << a - 'A' + 1;
						}
					}
				}
				cout << ss.str();
				return 0;
			}
		}// namespace b1076

		namespace b1078 {
			int main(istream &cin, ostream &cout) {
				char op;
				cin >> op;
				char str[1024];
				cin.getline(str, 1024);
				cin.getline(str, 1024);
				if(op == 'C') {
					for(int i = 0; i < strlen(str); i++) {
						int n = 1;
						while(i + 1 < strlen(str) && str[i] == str[i + 1]) {
							n++;
							i++;
						}
						if(n > 1) {
							cout << n;
						}
						cout << str[i];
					}
				} else {
					//op=='D'
					for(int i = 0; i < strlen(str); i++) {
						if(isdigit(str[i]) != 0) {
							stringstream ss;
							for(; i < strlen(str); i++) {
								if(isdigit(str[i]) != 0) {
									ss << str[i];
								} else {
									break;
								}
							}
							int n;
							ss >> n;
							for(int j = 0; j < n; j++) {
								cout << str[i];
							}
						} else {
							cout << str[i];
						}
					}
				}
				return 0;
			}
		}// namespace b1078

		namespace b1077 {
			int main(istream &cin, ostream &cout) {
				int n;
				int m;
				cin >> n >> m;
				for(int i = 0; i < n; i++) {
					int s_teacher;
					cin >> s_teacher;
					vector<int> scores;
					for(int j = 1; j < n; j++) {
						int score;
						cin >> score;
						if(0 <= score && score <= m) {
							scores.push_back(score);
						}
					}
					sort(scores.begin(), scores.end());
					scores.erase(scores.begin());
					scores.erase(--scores.end());
					int sum = 0;
					for(int j = 0; j < scores.size(); j++) {
						sum += scores[j];
					}
					const double avg = static_cast<double>(sum) / scores.size();
					const int final  = static_cast<int>((avg + s_teacher) / 2 + 0.5);
					cout << final << endl;
				}
				return 0;
			}
		}// namespace b1077

		namespace b1079 {
			bool is_palindromic(string str) {
				for(int i = 0; i < str.length() / 2; i++) {
					if(str[i] != str[str.length() - 1 - i]) {
						return false;
					}
				}
				return true;
			}

			int main(istream &cin, ostream &cout) {
				string str;
				cin >> str;
				BigInt bi(str);
				for(int i = 0; i < 10; i++) {
					stringstream ss;
					ss << bi;
					str = ss.str();
					if(is_palindromic(str)) {
						cout << bi << " is a palindromic number.";
						return 0;
					}
					auto str_b = string(str.rbegin(), str.rend());
					BigInt bi_b(str_b);
					BigInt c = bi + bi_b;
					cout << str << " + " << str_b << " = " << c << endl;
					bi = c;
				}
				cout << "Not found in 10 iterations.";
				return 0;
			}
		}// namespace b1079

		namespace b1080 {
			int main(istream &cin, ostream &cout) {
				int p;
				int m;
				int n;
				cin >> p >> m >> n;
				unordered_map<string, student> um;
				for(int i = 0; i < p; i++) {
					string id;
					cin >> id >> um[id].p;
				}
				for(int i = 0; i < m; i++) {
					string id;
					cin >> id >> um[id].mid_term;
				}
				for(int i = 0; i < n; i++) {
					string id;
					cin >> id >> um[id].final;
				}
				vector<student> vec;
				for(auto &[id, stu]: um) {
					stu.id    = id;
					stu.score = stu.get_score();
					if(stu.p >= 200 && stu.score >= 60) {
						vec.push_back(stu);
					}
				}
				sort(vec.begin(), vec.end());
				for(const auto &stu: vec) {
					cout << stu.id << ' ' << stu.p << ' ' << stu.mid_term << ' ' << stu.final << ' ' << stu.score << endl;
				}
				return 0;
			}

			int student::get_score() const {
				const int mt = mid_term == -1 ? 0 : mid_term;
				const int f  = final == -1 ? 0 : final;
				if(mt > f) {
					return static_cast<int>(mt * 0.4 + f * 0.6 + 0.5);
				}
				return f;
			}

			bool student::operator<(const student &stu) const {
				if(this->score != stu.score) {
					return this->score > stu.score;
				}
				return this->id < stu.id;
			}
		}// namespace b1080

		namespace b1081 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				char str[1024];
				cin.getline(str, 1024);
				while(n-- != 0) {
					cin.getline(str, 1024);
					auto password = string(str);
					bool alpha    = false;
					bool digit    = false;
					bool ok       = true;
					if(password.length() < 6) {
						cout << "Your password is tai duan le." << endl;
					} else {
						for(const char ch: password) {
							if(isdigit(ch) != 0) {
								digit = true;
							} else if(isalpha(ch) != 0) {
								alpha = true;
							} else if(ch != '.') {
								ok = false;
								cout << "Your password is tai luan le." << endl;
								break;
							}
						}
						if(!ok) {
							continue;
						}
						if(alpha && !digit) {
							cout << "Your password needs shu zi." << endl;
						} else if(!alpha && digit) {
							cout << "Your password needs zi mu." << endl;
						} else if(alpha && digit) {
							cout << "Your password is wan mei." << endl;
						} else {
							return 1;
						}
					}
				}
				return 0;
			}
		}// namespace b1081

		namespace b1082 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				vector<player> vec(n);
				for(int i = 0; i < n; i++) {
					cin >> vec[i].id >> vec[i].x >> vec[i].y;
				}
				sort(vec.begin(), vec.end());
				cout << (*vec.begin()).id << ' ' << (*vec.rbegin()).id;
				return 0;
			}

			int player::get_dist() const { return x * x + y * y; }

			bool player::operator<(const player &p) const { return this->get_dist() < p.get_dist(); }
		}// namespace b1082

		namespace b1083 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				map<int, int, greater<>> m;
				for(int i = 1; i <= n; i++) {
					int val;
					cin >> val;
					m[abs(i - val)]++;
				}
				for(auto [k, v]: m) {
					if(v > 1) {
						cout << k << ' ' << v << endl;
					}
				}
				return 0;
			}
		}// namespace b1083

		namespace b1084 {
			int main(istream &cin, ostream &cout) {
				string str;
				int n;
				cin >> str >> n;
				for(int i = 1; i < n; i++) {
					char ch = str[0];
					ostringstream oss;
					int count = 1;
					for(int j = 1; j < str.length(); j++) {
						if(str[j] == ch) {
							count++;
						} else {
							oss << ch << count;
							count = 1;
							ch    = str[j];
						}
					}
					oss << ch << count;
					str = oss.str();
				}
				cout << str;
				return 0;
			}
		}// namespace b1084

		namespace b1085 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				unordered_map<string, school> schools;
				for(int i = 0; i < n; i++) {
					string id;
					string sc;
					int score;
					cin >> id >> score >> sc;
					stringstream ss;
					for(char ch: sc) {
						ss << static_cast<char>(tolower(ch));
					}
					sc = ss.str();
					if(!schools.contains(sc)) {
						schools[sc] = school(sc);
					}
					schools[sc].count++;
					switch(id[0]) {
						case 'A':
							schools[sc].a_sum += score;
							break;
						case 'B':
							schools[sc].b_sum += score;
							break;
						case 'T':
							schools[sc].t_sum += score;
							break;
						default: return 1;
					}
				}
				vector<school> vec;
				vec.reserve(schools.size());
				for(const auto &[id, sc]: schools) {
					vec.push_back(sc);
				}
				sort(vec.rbegin(), vec.rend());
				unordered_map<int, int> score_rank;
				for(int i = vec.size() - 1; i >= 0; i--) {
					score_rank[vec[i].get_score()] = i + 1;
				}
				cout << vec.size() << endl;
				for(int i = 0; i < vec.size(); i++) {
					const auto &sc = vec[i];
					cout << score_rank[sc.get_score()] << ' ' << sc.id << ' ' << sc.get_score() << ' ' << sc.count << endl;
				}
				return 0;
			}

			int school::get_score() const { return static_cast<int>(a_sum + b_sum / 1.5 + t_sum * 1.5); }

			bool school::operator<(const school &sc) const {
				const int score1 = this->get_score();
				const int score2 = sc.get_score();
				if(score1 != score2) {
					return score1 < score2;
				}
				if(count != sc.count) {
					return count > sc.count;
				}
				return id > sc.id;
			}
		}// namespace b1085

		namespace b1086 {
			int main(istream &cin, ostream &cout) {
				unsigned a;
				unsigned b;
				cin >> a >> b;
				ostringstream oss;
				oss << a * b;
				string str = oss.str();
				stringstream ss;
				for(auto it = str.rbegin(); it != str.rend(); ++it) {
					ss << *it;
				}
				unsigned ans;
				ss >> ans;
				cout << ans;
				return 0;
			}
		}// namespace b1086

		namespace b1087 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				cout << n / 2 + n / 3 + n / 5 - n / 6 - n / 10 - n / 15 + n / 30 + 1;
				return 0;
			}
		}// namespace b1087

		namespace b1088 {
			int main(istream &cin, ostream &cout) {
				int m;
				int x;
				int y;
				cin >> m >> x >> y;
				int a;
				int b;
				int a_f;
				int b_f;
				double c_f;
				bool no_solution = true;
				for(int a = 10; a <= 99; a++) {
					ostringstream oss;
					oss << a;
					string str_a = oss.str();
					stringstream ss;
					for(auto it = str_a.rbegin(); it != str_a.rend(); ++it) {
						ss << *it;
					}
					ss >> b;
					const double c = static_cast<double>(b) / y;
					if(c * x == abs(a - b)) {
						no_solution = false;
						a_f         = a;
						b_f         = b;
						c_f         = c;
					}
				}
				if(no_solution) {
					cout << "No Solution";
					return 0;
				}
				cout << a_f << ' ';
				if(a_f < m) {
					cout << "Gai ";
				} else if(a_f == m) {
					cout << "Ping ";
				} else {
					cout << "Cong ";
				}
				if(b_f < m) {
					cout << "Gai ";
				} else if(b_f == m) {
					cout << "Ping ";
				} else {
					cout << "Cong ";
				}
				if(c_f < m) {
					cout << "Gai";
				} else if(c_f == m) {
					cout << "Ping";
				} else {
					cout << "Cong";
				}
				return 0;
			}
		}// namespace b1088

		namespace b1089 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				vector<int> vec(n);
				for(int i = 0; i < n; i++) {
					cin >> vec[i];
				}
				for(int i = 0; i + 1 < n; i++) {
					for(int j = i + 1; j < n; j++) {
						if(is_true(vec, i, j)) {
							cout << i + 1 << ' ' << j + 1;
							return 0;
						}
					}
				}
				cout << "No Solution";
				return 0;
			}

			bool is_true(const vector<int> &vec, int wolf1, int wolf2) {
				int lie_count = 0;
				bool wolf_lie = false;
				for(int i = 0; i < vec.size(); i++) {
					const bool is_wolf = vec[i] < 0;
					const int target   = abs(vec[i]) - 1;
					if(is_wolf && !(target == wolf1 || target == wolf2) || !is_wolf && (target == wolf1 || target == wolf2)) {
						lie_count++;
						if(i == wolf1 || i == wolf2) {
							if(wolf_lie) {
								return false;
							}
							wolf_lie = true;
						}
					}
					if(lie_count > 2) {
						return false;
					}
				}
				return wolf_lie;
			}
		}// namespace b1089

		namespace b1090 {
			int main(istream &cin, ostream &cout) {
				int n;
				int m;
				cin >> n >> m;
				unordered_map<string, unordered_set<string>> um;
				for(int i = 0; i < n; i++) {
					string a;
					string b;
					cin >> a >> b;
					um[a].insert(b);
					um[b].insert(a);
				}
				for(int i = 0; i < m; i++) {
					int k;
					cin >> k;
					bool ok = true;
					unordered_set<string> us;
					for(int j = 0; j < k; j++) {
						string g;
						cin >> g;
						us.insert(g);
					}
					for(const auto &g: us) {
						for(const auto &nc: um[g]) {
							if(static_cast<unsigned int>(us.contains(nc)) != 0U) {
								ok = false;
								break;
							}
						}
						if(!ok) {
							break;
						}
					}
					if(ok) {
						cout << "Yes" << endl;
					} else {
						cout << "No" << endl;
					}
				}
				return 0;
			}
		}// namespace b1090

		namespace b1091 {
			int main(istream &cin, ostream &cout) {
				int m;
				cin >> m;
				while(m-- != 0) {
					unsigned k;
					cin >> k;
					const unsigned k2 = k * k;
					unsigned q        = 1;
					while(k / q != 0) {
						q *= 10;
					}
					bool ok = false;
					for(unsigned n = 1; n < 10; n++) {
						const unsigned nk2 = n * k2;
						if(nk2 % q == k) {
							ok = true;
							cout << n << ' ' << nk2 << endl;
							break;
						}
					}
					if(!ok) {
						cout << "No" << endl;
					}
				}
				return 0;
			}
		}// namespace b1091

		namespace b1092 {
			int main(istream &cin, ostream &cout) {
				int n;
				int m;
				cin >> n >> m;
				vector sales(n, 0);
				for(int j = 0; j < m; j++) {
					for(int i = 0; i < n; i++) {
						unsigned sale;
						cin >> sale;
						sales[i] += sale;
					}
				}
				int maximum = 0;
				for(auto sale: sales) {
					maximum = max(maximum, sale);
				}
				cout << maximum << endl;
				int i = 0;
				for(i = 0; i < n; i++) {
					if(sales[i] == maximum) {
						cout << i + 1;
						break;
					}
				}
				i++;
				for(; i < n; i++) {
					if(sales[i] == maximum) {
						cout << ' ' << i + 1;
					}
				}
				return 0;
			}
		}// namespace b1092

		namespace b1093 {
			int main(istream &cin, ostream &cout) {
				char a[1000010];
				char b[1000010];
				cin.getline(a, 1000010);
				cin.getline(b, 1000010);
				bool has[127];
				unordered_set<char> us;
				for(int i = 0; i < strlen(a); i++) {
					const char ch = a[i];
					if(!has[ch]) {
						cout << ch;
						has[ch] = true;
					}
				}
				for(int i = 0; i < strlen(b); i++) {
					const char ch = b[i];
					if(!has[ch]) {
						cout << ch;
						has[ch] = true;
					}
				}
				return 0;
			}
		}// namespace b1093

		namespace b1094 {
			int main(istream &cin, ostream &cout) {
				int l;
				int k;
				cin >> l >> k;
				vector<char> n(l);
				for(int i = 0; i < l; i++) {
					cin >> n[i];
					n[i] -= '0';
				}
				for(int i = 0, j = k - 1; j < l; i++, j++) {
					unsigned int ans = 0;
					for(int m = i; m <= j; m++) {
						ans *= 10;
						ans += n[m];
					}
					if(is_prime(ans)) {
						for(int m = i; m <= j; m++) {
							cout << static_cast<char>(n[m] + '0');
						}
						return 0;
					}
				}
				cout << 404;
				return 0;
			}

			bool is_prime(unsigned int n) {
				if(n < 2) {
					return false;
				}
				for(int i = 2; i <= sqrt(n); i++) {
					if(n % i == 0) {
						return false;
					}
				}
				return true;
			}
		}// namespace b1094

		namespace b1095 {
			int main(istream &cin, ostream &cout) {
				int n;
				int m;
				cin >> n >> m;
				unordered_map<string, room> rooms;
				unordered_map<char, unordered_set<student *>> levels;
				unordered_map<string, unordered_map<string, int>> dates;
				for(int i = 0; i < n; i++) {
					auto *stu = new student();
					cin >> stu->id >> stu->grade;
					stu->level = stu->id[0];
					stu->room  = stu->id.substr(1, 3);
					stu->date  = stu->id.substr(4, 6);
					rooms[stu->room].sum += stu->grade;
					rooms[stu->room].count++;
					levels[stu->level].insert(stu);
					dates[stu->date][stu->room]++;
				}
				for(int i = 0; i < m; i++) {
					int typ;
					cin >> typ;
					cout << "Case " << i + 1 << ": " << typ << ' ';
					if(typ == 1) {
						char l;
						cin >> l;
						cout << l << endl;
						if(static_cast<unsigned int>(levels.contains(l)) != 0U) {
							vector<student *> vec;
							for(auto *const pstu: levels[l]) {
								vec.emplace_back(pstu);
							}
							sort(vec.begin(), vec.end(), p_stu_comp());
							for(auto *stu: vec) {
								cout << stu->id << ' ' << stu->grade << endl;
							}
						} else {
							cout << "NA" << endl;
						}
					} else if(typ == 2) {
						string room_id;
						cin >> room_id;
						cout << room_id << endl;
						if(static_cast<unsigned int>(rooms.contains(room_id)) != 0U) {
							cout << rooms[room_id].count << ' ' << rooms[room_id].sum << endl;
						} else {
							cout << "NA" << endl;
						}
					} else if(typ == 3) {
						string date;
						cin >> date;
						cout << date << endl;
						if(dates[date].empty()) {
							cout << "NA" << endl;
							continue;
						}
						vector<pair<string, int>> vec;
						for(const auto &room_cnt: dates[date]) {
							vec.emplace_back(room_cnt);
						}
						sort(vec.begin(), vec.end(), room_cnt_comp());
						for(const auto &[id, cnt]: vec) {
							cout << id << ' ' << cnt << endl;
						}
					} else {
						string op;
						cout << op << endl;
						cout << "NA" << endl;
					}
				}
				return 0;
			}

			bool p_stu_comp::operator()(const student *stu1, const student *stu2) const {
				if(stu1->grade != stu2->grade) {
					return stu1->grade > stu2->grade;
				}
				return stu1->id < stu2->id;
			}

			bool room_cnt_comp::operator()(const pair<string, int> &p1, const pair<string, int> &p2) const {
				if(p1.second != p2.second) {
					return p1.second > p2.second;
				}
				return p1.first < p2.first;
			}
		}// namespace b1095

		namespace b1096 {
			int main(istream &cin, ostream &cout) {
				int k;
				cin >> k;
				for(int i = 0; i < k; i++) {
					unsigned num;
					cin >> num;
					unordered_set<unsigned> fs;
					for(unsigned f = 1; f <= num; f++) {
						if(num % f == 0) {
							fs.insert(f);
						}
					}
					vector<unsigned> vec(fs.size());
					int fi = 0;
					for(const auto f: fs) {
						vec[fi++] = f;
					}
					if(vec.size() < 4) {
						cout << "No" << endl;
						continue;
					}
					bool ok = false;
					for(auto i1 = 0; i1 + 3 < vec.size(); i1++) {
						for(auto i2 = i1 + 1; i2 + 2 < vec.size(); i2++) {
							for(auto i3 = i2 + 1; i3 + 1 < vec.size(); i3++) {
								for(auto i4 = i3 + 1; i4 < vec.size(); i4++) {
									if((vec[i1] + vec[i2] + vec[i3] + vec[i4]) % num == 0) {
										ok = true;
										goto LOOP_END;
									}
								}
							}
						}
					}
				LOOP_END:
					if(ok) {
						cout << "Yes" << endl;
					} else {
						cout << "No" << endl;
					}
				}
				return 0;
			}
		}// namespace b1096

		namespace b1097 {
			int main(istream &cin, ostream &cout) {
				int n;
				int k;
				int x;
				cin >> n >> k >> x;
				vector grid(n, vector<int>(n));
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < n; j++) {
						cin >> grid[i][j];
					}
				}
				int indent = 1;
				for(int i = 0; i < n; i += 2) {
					for(int j = n - 1; j >= 0; j--) {
						grid[i][j] = j - indent >= 0 ? grid[i][j - indent] : x;
					}
					indent++;
					if(indent == k + 1) {
						indent = 1;
					}
				}
				for(int j = 0; j < n; j++) {
					int sum = 0;
					for(int i = 0; i < n; i++) {
						sum += grid[i][j];
					}
					cout << sum;
					if(j != n - 1) {
						cout << ' ';
					}
				}
				return 0;
			}
		}// namespace b1097

		namespace b1098 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				int top    = 1000;
				int bottom = 0;
				for(int i = 0; i < n; i++) {
					int v;
					cin >> v;
					top = min(top, v);
				}
				for(int i = 0; i < n; i++) {
					int v;
					cin >> v;
					bottom = max(bottom, v);
				}
				if(top <= bottom) {
					cout << "No " << bottom - top + 1;
				} else {
					cout << "Yes " << top - bottom;
				}
				return 0;
			}
		}// namespace b1098

		namespace b1099 {
			int main(istream &cin, ostream &cout) {
				unsigned int n;
				cin >> n;
				if(is_prime(n)) {
					if(n > 7 && is_prime(n - 6)) {
						cout << "Yes" << endl
						     << n - 6;
						return 0;
					} else if(is_prime(n + 6)) {
						cout << "Yes" << endl
						     << n + 6;
						return 0;
					}
				}
				for(unsigned int i = n + 1;; i++) {
					if(is_prime(i)) {
						if(i > 7 && is_prime(i - 6)) {
							cout << "No" << endl
							     << i;
							return 0;
						} else if(is_prime(i + 6)) {
							cout << "No" << endl
							     << i;
							return 0;
						}
					}
				}
				return 0;
			}

			bool is_prime(unsigned int n) {
				if(n == 1) {
					return false;
				}
				for(unsigned int i = 2; i <= sqrt(n); i++) {
					if(n % i == 0) {
						return false;
					}
				}
				return true;
			}
		}// namespace b1099

		namespace b1100 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				unordered_set<string> alumnuses;
				for(int i = 0; i < n; i++) {
					string id;
					cin >> id;
					alumnuses.insert(id);
				}
				int m;
				cin >> m;
				unsigned cnt = 0;
				unordered_set<string> guests;
				for(int i = 0; i < m; i++) {
					string id;
					cin >> id;
					cnt += alumnuses.count(id);
					guests.insert(id);
				}
				cout << cnt << endl;
				vector<string> vec;
				if(cnt > 0) {
					for(const auto &id: guests) {
						if(alumnuses.count(id)) {
							vec.emplace_back(id);
						}
					}
				} else {
					vec = vector<string>(guests.begin(), guests.end());
				}
				sort(vec.begin(), vec.end(), comp());
				cout << *vec.begin();
				return 0;
			}

			bool comp::operator()(const string &s1, const string &s2) const {
				return s1.substr(6, 8) < s2.substr(6, 8);
			}
		}// namespace b1100

		namespace b1101 {
			int main(istream &cin, ostream &cout) {
				string a;
				int d;
				cin >> a >> d;
				stringstream ss;
				ss << a.substr(a.length() - d, d) << a.substr(0, a.length() - d);
				double b;
				ss >> b;
				cout << fixed << setprecision(2) << b / stoi(a);
				return 0;
			}
		}// namespace b1101

		namespace b1102 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				vector<paper> vec(n);
				for(int i = 0; i < n; i++) {
					cin >> vec[i].id;
					cin >> vec[i].price;
					cin >> vec[i].sale;
				}
				sort(vec.rbegin(), vec.rend(), comp_sale());
				cout << vec.begin()->id << ' ' << vec.begin()->sale << endl;
				sort(vec.rbegin(), vec.rend(), comp_total());
				cout << vec.begin()->id << ' ' << vec.begin()->price * vec.begin()->sale;
				return 0;
			}

			bool comp_sale::operator()(const paper &p1, const paper &p2) const {
				return p1.sale < p2.sale;
			}

			bool comp_total::operator()(const paper &p1, const paper &p2) const {
				return p1.sale * p1.price < p2.sale * p2.price;
			}
		}// namespace b1102

		namespace b1103 {
			int main(istream &cin, ostream &cout) {
				unsigned m, n;
				cin >> m >> n;
				unordered_map<unsigned, unsigned> c2a;
				unsigned max_c2 = 0;
				for(unsigned a = m; a <= n; a++) {
					unsigned c2 = 3 * a * (a - 1) + 1;
					max_c2      = c2;
					c2a[c2]     = a;
				}
				bool ok     = false;
				unsigned c2 = 0;
				for(unsigned b = 1; c2 <= max_c2; b++) {
					c2 = (b * b + (b - 1) * (b - 1)) * (b * b + (b - 1) * (b - 1));
					if(c2a.count(c2) && c2a[c2] != b) {
						ok = true;
						cout << c2a[c2] << ' ' << b << endl;
					}
				}
				if(!ok) {
					cout << "No Solution";
				}
				return 0;
			}
		}// namespace b1103

		namespace b1104 {
			int main(istream &cin, ostream &cout) {
				int N;
				cin >> N;
				vector<int> diff(10);
				for(int i = 0; i < 10; i++) {
					diff[i] = 1 - i * 9;
				}
				for(int i = 1; i <= N; i++) {
					bool ok = false;
					int k, m;
					cin >> k >> m;
					cout << "Case " << i << endl;
					for(int j = k; j >= 1; j--) {
						int n = m + diff[j];
						int g = gcd(m, n);
						if(n > 0 && g > 2 && is_prime(gcd(m, n))) {
							vector<string> ans;
							dfs("", 1, m, k, 0, j, ans);
							if(!ans.empty()) {
								ok = true;
								for(const auto &str: ans) {
									cout << m + diff[j] << ' ' << str << endl;
								}
							}
						}
					}
					if(!ok) {
						cout << "No Solution" << endl;
					}
				}
				return 0;
			}

			bool is_prime(int n) {
				if(n == 1) {
					return false;
				}
				for(int i = 2; i <= sqrt(n); i++) {
					if(n % i == 0) {
						return false;
					}
				}
				return true;
			}

			void dfs(string str, const int current_i, const int m, const int k, const int current_sum, const int cnt9, vector<string> &ans) {
				if(current_i + cnt9 == k) {
					if(int r = m - current_sum - cnt9 * 9; ((current_i > 1 && r >= 0) || (current_i == 1 && r > 0)) && r < 9) {
						str += char(r + '0');
					} else {
						return;
					}
					for(int i = 0; i < cnt9; i++) {
						str += '9';
					}
					ans.emplace_back(str);
					return;
				}
				for(int i = current_i == 1 ? 1 : 0; i <= 9; i++) {
					if(!((current_sum + i + cnt9 * 9 > m) || (current_sum + i + (k - current_i) * 9 - 1 < m))) {
						dfs(str + char(i + '0'), current_i + 1, m, k, current_sum + i, cnt9, ans);
					}
				}
			}
		}// namespace b1104

		namespace b1105 {
			int main(istream &cin, ostream &cout) {
				string h1, h2;
				int n;
				cin >> h1 >> h2 >> n;
				unordered_map<string, node> um;
				for(int i = 0; i < n; i++) {
					string address;
					cin >> address;
					um[address].address = address;
					cin >> um[address].data >> um[address].next;
				}
				vector<node> l1, l2;
				for(string addr = h1; addr != "-1"; addr = um[addr].next) {
					l1.push_back(um[addr]);
				}
				for(string addr = h2; addr != "-1"; addr = um[addr].next) {
					l2.push_back(um[addr]);
				}
				if(l1.size() < l2.size()) {
					swap(l1, l2);
				}
				l2 = vector<node>(l2.rbegin(), l2.rend());
				vector<node> ans;
				for(int cnt = 0, i1 = 0, i2 = 0; i1 < l1.size() || i2 < l2.size(); cnt++, cnt %= 3) {
					if(cnt <= 1) {
						if(i1 < l1.size()) {
							ans.push_back(l1[i1++]);
						}
					} else {
						if(i2 < l2.size()) {
							ans.push_back(l2[i2++]);
						}
					}
				}
				for(int i = 0; i < ans.size(); i++) {
					cout << ans[i].address << ' ' << ans[i].data << ' ' << ((i + 1 < ans.size()) ? ans[i + 1].address : "-1") << endl;
				}
				return 0;
			}
		}// namespace b1105

		namespace b1106 {
			int main(istream &cin, ostream &cout) {
				int n;
				cin >> n;
				vector<unsigned> vec(n);
				vec[0]           = 2;
				vec[1]           = 0;
				vec[2]           = 1;
				vec[3]           = 9;
				unsigned current = 2 + 0 + 1 + 9;
				for(int i = 4; i < n; i++) {
					vec[i] = current % 10;
					current -= vec[i - 4];
					current += vec[i];
				}
				for(auto num: vec) {
					cout << num;
				}
				return 0;
			}
		}// namespace b1106

		namespace b1107 {
			int main(istream &cin, ostream &cout) {
				int n, m;
				cin >> n >> m;
				int champion = 0;
				for(int i = 0; i < n; i++) {
					int maximum = 0;
					for(int j = 0; j < m; j++) {
						int weight;
						cin >> weight;
						maximum = max(maximum, weight);
					}
					cout << maximum;
					if(i != n - 1) {
						cout << ' ';
					}
					champion = max(champion, maximum);
				}
				cout << endl
				     << champion;
				return 0;
			}
		}// namespace b1107

		namespace b1108 {
			int main(istream &cin, ostream &cout) {
				unordered_map<char, int> um;
				char ch;
				while(cin >> ch) {
					um[ch]++;
				}
				char word[6] = {'S', 't', 'r', 'i', 'n', 'g'};
				int cnt      = 0;
				for(int i = 0; cnt < 6; i++, i %= 6) {
					if(um[word[i]] > 0) {
						cout << word[i];
						um[word[i]]--;
						cnt = 0;
					} else {
						cnt++;
					}
				}
				return 0;
			}
		}// namespace b1108

		namespace b1109 {
			int main(istream &cin, ostream &cout) {
				char matrix[26][7][5];
				for(int i = 0; i < 26; i++) {
					for(int j = 0; j < 7; j++) {
						for(int k = 0; k < 5; k++) {
							cin >> matrix[i][j][k];
						}
					}
				}
				vector<string> vec;
				ostringstream oss;
				char ch;
				cin >> noskipws;
				while(cin >> ch) {
					if(isupper(ch)) {
						oss << ch;
					} else {
						if(!oss.str().empty()) {
							vec.emplace_back(oss.str());
						}
						oss = ostringstream();
					}
				}
				if(!oss.str().empty()) {
					vec.emplace_back(oss.str());
				}
				int cnt = 0;
				for(const auto &str: vec) {
					int w = str.length() * 6 - 1;
					vector<vector<char>> output(7, vector<char>(w, ' '));
					for(int i = 0; i < str.length(); i++) {
						char c = str[i];
						for(int j = 0; j < 7; j++) {
							for(int k = 0; k < 5; k++) {
								output[j][i * 6 + k] = matrix[c - 'A'][j][k];
							}
						}
					}
					for(int i = 0; i < 7; i++) {
						for(int j = 0; j < w; j++) {
							cout << output[i][j];
						}
						if(i != 6) {
							cout << endl;
						}
					}
					if(cnt++ != vec.size() - 1) {
						cout << endl
						     << endl;
					}
				}
				return 0;
			}
		}// namespace b1109
	}    // namespace b

	namespace a {}

	namespace top {}
}// namespace pat
