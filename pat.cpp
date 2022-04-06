#include "pat.h"
#include "templates.h"
#include <algorithm>
#include <cmath>
#include <cstring>
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
				char *str = new char[1001];
				cin.getline(str, 1001);
				map<char, int> m;
				int maximum = 0;
				for(int i = 0; i < strlen(str); ++i) {
					char ch = tolower(str[i]);
					if(isalpha(ch)) {
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
				char patest[6] = {'P', 'A', 'T', 'e', 's', 't'};
				um['P']        = 0;
				um['A']        = 0;
				um['T']        = 0;
				um['e']        = 0;
				um['s']        = 0;
				um['t']        = 0;
				string str;
				cin >> str;
				for(char ch: str) {
					if(um.count(ch) > 0) {
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
	}    // namespace b

	namespace a {}

	namespace top {}
}// namespace pat
