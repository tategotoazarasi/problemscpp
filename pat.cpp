#include "pat.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <map>
#include <set>
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
				int m, n;
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
				string str1, str2;
				cin >> str1 >> str2;
				string day;
				vector<string> days = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
				int hh;
				int mm;
				for(int i = 0; i < str1.length() && i < str2.length(); i++) {
					if(str1[i] == str2[i]) {
						if(day.empty()) {
							if(isupper(str1[i])) {
								day = days[str1[i] - 'A'];
							}
						} else if(isdigit(str1[i]) || ('A' <= str1[i] && str1[i] <= 'N')) {
							if(isdigit(str1[i])) {
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
					if(str1[i] == str2[i] && isalpha(str1[i])) {
						mm = i;
						break;
					}
				}
				cout << day << ' ' << setw(2) << right << setfill('0') << hh << ':' << setw(2) << right << setfill('0') << mm;
				return 0;
			}
		}// namespace b1014
	}    // namespace b

	namespace a {}

	namespace top {}
}// namespace pat
