//
// Created by tategotoazarasi on 2022/3/14.
//

#include "pat.h"
#include <bit>
#include <iostream>
#include <sstream>

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
						char ch = str[i];
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
							default:
								goto NO;
								break;
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
	}    // namespace b

	namespace a {

	}

	namespace top {

	}
}// namespace pat