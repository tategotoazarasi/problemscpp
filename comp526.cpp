//
// Created by wangzhiheng on 26/09/2025.
//
#include "comp526.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

using namespace std;

namespace comp526 {
	namespace stable_matching {
		vector<int> Solution::match(vector<vector<int>> s2c, vector<vector<int>> c2s) {
			int N     = s2c.size();
			students  = vector<Student *>();
			companies = vector<Company *>();
			for(int i = 0; i < N; i++) {
				Student *stu    = new Student(i);
				stu->c_priority = unordered_map<Company *, int>();
				stu->priority_c = unordered_map<int, Company *>();
				students.emplace_back(stu);
				Company *com  = new Company(i);
				com->priority = unordered_map<Student *, int>();
				companies.emplace_back(com);
			}
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					students[i]->c_priority[companies[j]] = s2c[i][j];
					students[i]->priority_c[s2c[i][j]]    = companies[j];
					companies[i]->priority[students[j]]   = c2s[i][j];
				}
			}
			bool flag = true;
			while(flag) {
				flag = false;
				for(int i = 0; i < N; i++) {
					auto stu = students[i];
					if(stu->matched_company == nullptr) {
						flag = true;
						stu->priority_c[stu->current_priority++]->proposed_students.insert(stu);
					}
				}

				for(int i = 0; i < N; i++) {
					auto com                         = companies[i];
					Student *current_matched_student = com->matched_student;
					if(com->proposed_students.size() > 0) {
						int min_priority       = com->matched_student ? com->priority[com->matched_student] : INT_MAX;
						Student *max_p_student = com->matched_student;
						for(auto stu: com->proposed_students) {
							if(com->priority[stu] < min_priority) {
								min_priority  = com->priority[stu];
								max_p_student = stu;
								flag          = true;
							}
						}
						if(flag) {
							if(current_matched_student != nullptr) {
								current_matched_student->matched_company = nullptr;
							}
							com->matched_student           = max_p_student;
							max_p_student->matched_company = com;
						}
						com->proposed_students.clear();
					}
				}
			}
			vector<int> ans = vector<int>(N, -1);
			for(int i = 0; i < N; i++) {
				ans[i] = students[i]->matched_company->id;
			}
			return ans;
		}
	}// namespace stable_matching

	namespace oddecho {
		int main(istream &cin, ostream &cout) {
			string str;
			int cnt = 0;
			while(cin >> str) {
				if(cnt % 2 == 1) {
					cout << str << endl;
				}
				cnt++;
			}
			return 0;
		}
	}// namespace oddecho

	namespace recount {
		int main(istream &cin, ostream &cout) {
			unordered_map<string, unsigned long> m = unordered_map<string, unsigned long>();
			string line;
			while(std::getline(cin, line)) {
				if(line == "***") {
					break;
				}
				m[line]++;
			}

			string ans             = "***";
			unsigned long max_vote = 0;
			for(const auto &[k, v]: m) {
				max_vote = max(max_vote, v);
			}
			for(const auto &[k, v]: m) {
				if(v == max_vote) {
					if(ans != "***") {
						cout << "Runoff!";
						return 0;
					}
					ans = k;
				}
			}
			cout << ans;

			return 0;
		}
	}// namespace recount

	namespace set {
		vector<vector<int>> ans = {};
		cardset::cardset(card *c) {
			this->cards.insert(c);
			this->cnt = 1;
		}

		unsigned short calc_mask(card *c1, card *c2) {
			unsigned short mask = 0;
			for(int i = 0; i < 4; i++) {
				mask <<= 1;
				mask |= c1->f[i] == c2->f[i];
			}
			return mask;
		}
		card::card(int id, string s) {
			this->id = id;
			istringstream iss(s);
			iss >> this->f[0] >> this->f[1] >> this->f[2] >> this->f[3];
		}

		void cardset::insert(card *c) {
			if(this->mask == (unsigned short) (-1)) {
				this->mask = calc_mask(c, *this->cards.begin());
			}
			this->cards.insert(c);
			this->cnt++;
			if(this->cnt == 3) {
				vector<int> vec = {};
				for(auto &c: this->cards) {
					vec.emplace_back(c->id);
				}
				std::sort(vec.begin(), vec.end());
				ans.emplace_back(vec);
			}
		}

		bool fit(card *c, const cardset *s) {
			if(s->mask == (unsigned short) (-1)) {
				return true;
			}
			for(auto &sc: s->cards) {
				if(calc_mask(sc, c) != s->mask) {
					return false;
				}
			}
			return true;
		}

		int main(istream &cin, ostream &cout) {
			cardset sets[1 << 10] = {};
			int sets_cnt          = 0;
			string input;
			for(int i = 1; i <= 12; i++) {
				cin >> input;
				card *newcard = new card(i, input);
				for(int j = 0; j < sets_cnt; j++) {
					if(fit(newcard, &sets[j])) {
						cardset newset = sets[j];
						newset.insert(newcard);
						sets[sets_cnt++] = (newset);
					}
				}
				cardset newset   = cardset(newcard);
				sets[sets_cnt++] = (newset);
			}
			if(ans.size() == 0) {
				cout << "no sets";
				return 0;
			}
			std::sort(ans.begin(), ans.end(), [](const vector<int> &a, const vector<int> &b) {
				if(a[0] != b[0]) {
					return a[0] < b[0];
				} else if(a[1] != b[1]) {
					return a[1] < b[1];
				} else {
					return a[2] < b[2];
				}
			});
			for(const auto &s: ans) {
				cout << s[0] << ' ' << s[1] << ' ' << s[2] << endl;
			}
			return 0;
		}
	}// namespace set

	namespace plantingtrees {
		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			vector<int> vec(n);
			for(int i = 0; i < n; i++) {
				cin >> vec[i];
			}
			sort(vec.rbegin(), vec.rend());
			int ans = 0;
			for(int i = 0; i < n; i++) {
				ans = max(ans, i + vec[i] + 2);
			}
			cout << ans;

			return 0;
		}
	}// namespace plantingtrees

	namespace snowflakes {
		int main(istream &cin, ostream &cout) {
			int testCases;
			cin >> testCases;
			while(testCases--) {
				int n;
				cin >> n;
				if(n == 0) {
					cout << 0 << endl;
					break;
				}
				vector<int> snowflakes(n);
				for(int i = 0; i < n; ++i) {
					cin >> snowflakes[i];
				}
				unordered_map<int, int> lastSeen;
				int left      = 0;
				int maxLength = 0;
				for(int right = 0; right < n; ++right) {
					int currentSnowflake = snowflakes[right];
					if(lastSeen.count(currentSnowflake)) {
						left = max(left, lastSeen[currentSnowflake] + 1);
					}
					lastSeen[currentSnowflake] = right;
					maxLength                  = max(maxLength, right - left + 1);
				}
				cout << maxLength;
			}

			return 0;
		}
	}// namespace snowflakes
}// namespace comp526
