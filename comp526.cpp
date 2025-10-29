//
// Created by wangzhiheng on 26/09/2025.
//
#include "comp526.h"

#include "templates.h"
#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
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

	namespace amalgram {
		int main(istream &cin, ostream &cout) {
			string a, b;
			cin >> a >> b;
			vector<int> cnt1 = vector<int>(26, 0);
			vector<int> cnt2 = vector<int>(26, 0);
			for(char c: a) {
				cnt1[c - 'a']++;
			}
			for(char c: b) {
				cnt2[c - 'a']++;
			}
			for(int i = 0; i < 26; i++) {
				for(int j = 0; j < max(cnt1[i], cnt2[i]); j++) {
					cout << (char) ('a' + i);
				}
			}
			return 0;
		}
	}// namespace amalgram

	namespace wheresmyinternet {
		int main(istream &cin, ostream &cout) {
			int N, M;
			int a, b;
			cin >> N >> M;
			UnionFind uf = UnionFind(N + 1);
			while(M--) {
				cin >> a >> b;
				uf.unite(a, b);
			}
			bool flag = false;
			for(int i = 2; i <= N; i++) {
				if(!uf.same(i, 1)) {
					cout << i << endl;
					flag = true;
				}
			}
			if(!flag) {
				cout << "Connected";
			}
			return 0;
		}
	}// namespace wheresmyinternet

	namespace oddities {
		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			while(n--) {
				int x;
				cin >> x;
				cout << x << " is " << ((abs(x) % 2 == 1) ? "odd" : "even") << endl;
			}
			return 0;
		}
	}// namespace oddities

	namespace countingchocolate {
		bool solve(const vector<int> &a, int john, int sam, int sp, int target) {
			if(sp == a.size()) {
				return false;
			}
			if(john == target || sam == target) {
				return true;
			}
			if(john > target || sam > target) {
				return false;
			}
			return solve(a, john + a[sp], sam, sp + 1, target) || solve(a, john, sam + a[sp], sp + 1, target);
		}

		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			vector<int> a = vector<int>(n);
			int sum       = 0;
			for(int i = 0; i < n; i++) {
				cin >> a[i];
				sum += a[i];
			}
			if(sum % 2 == 1) {
				cout << "NO";
				return 0;
			}
			if(solve(a, 0, 0, 0, sum / 2)) {
				cout << "YES";
			} else {
				cout << "NO";
			}
			return 0;
		}
	}// namespace countingchocolate

	namespace grid {

		int n, m;
		struct pair_hash {
			size_t operator()(const pair<int, int> &p) const {
				return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
			}
		};
		struct pair_equal {
			bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
				return a.first == b.first && a.second == b.second;
			}
		};
		int main(istream &cin, ostream &cout) {
			cin >> n >> m;
			vector<vector<int>> grid(n, vector<int>(m));
			for(int i = 0; i < n; i++) {
				string line;
				cin >> line;
				istringstream iss(line);
				for(int j = 0; j < m; j++) {
					char c;
					iss >> c;
					grid[i][j] = c - '0';
				}
			}
			unordered_set<pair<int, int>, pair_hash, pair_equal> visited{};
			auto comp = [](const state &a, const state &b) {
				if(a.step != b.step) {
					return a.step > b.step;
				}
				int dist_a = (n - a.x - 1) + (m - a.y - 1);
				int dist_b = (n - b.x - 1) + (m - b.y - 1);
				return dist_a > dist_b;
			};
			priority_queue<state, vector<state>, decltype(comp)> pq{};
			pq.push(state{0, 0, 0});
			while(!pq.empty()) {
				auto top = pq.top();
				pq.pop();
				int x = top.x;
				int y = top.y;
				if(visited.count({x, y})) {
					continue;
				}
				visited.insert(make_pair(x, y));
				if(x == n - 1 && y == m - 1) {
					cout << top.step;
					return 0;
				}
				int step               = grid[x][y];
				pair<int, int> next[4] = {
				        make_pair(x + step, y),
				        make_pair(x - step, y),
				        make_pair(x, y + step),
				        make_pair(x, y - step)};
				for(auto [next_x, next_y]: next) {
					if(next_x == n - 1 && next_y == m - 1) {
						cout << top.step + 1;
						return 0;
					}
					if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && grid[next_x][next_y] != 0) {
						pq.push(state{next_x, next_y, top.step + 1});
					}
				}
			}
			cout << -1;
			return 0;
		}
	}// namespace grid

	namespace allpairspath {

		int main(istream &cin, ostream &cout) {
			int n, m, q;
			while(cin >> n >> m >> q) {
				if(n == 0 && m == 0 && q == 0) {
					return 0;
				}

				vector<vector<int>> dist = vector(n, vector<int>(n, INT_MAX / 2));
				vector<edge> edges       = vector<edge>(m);
				for(int i = 0; i < n; i++) {
					dist[i][i] = 0;
				}
				unordered_set<int> calced{};

				for(int i = 0; i < m; i++) {
					int u, v, w;
					cin >> u >> v >> w;
					edges[i] = edge{u, v, w};
				}

				while(q--) {
					int u, v;
					cin >> u >> v;
					if(calced.contains(u)) {
						if(dist[u][v] >= INT_MAX / 2) {
							cout << "Impossible" << endl;
						} else {
							cout << dist[u][v] << endl;
						}
						continue;
					}

					for(int i = 0; i < n; i++) {
						for(int j = 0; j < m; j++) {
							int from = edges[j].u;
							int to   = edges[j].v;
							int w    = edges[j].w;
							if(dist[u][to] > dist[u][from] + w) {
								dist[u][to] = dist[u][from] + w;
							}
						}
					}
					if(dist[u][v] >= INT_MAX / 2) {
						cout << "Impossible" << endl;
					} else {
						cout << dist[u][v] << endl;
					}

					calced.insert(u);
				}

				cout << endl;
			}
			return 0;
		}
	}// namespace allpairspath

	namespace weakvertices {
		int main(istream &cin, ostream &cout) {
			int n;
			while(cin >> n) {
				if(n == -1)
					return 0;
				vector<vector<int>> siblings = vector(n, vector<int>());
				vector<vector<bool>> graph   = vector(n, vector<bool>(n, false));
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < n; j++) {
						int x;
						cin >> x;
						if(x == 1) {
							siblings[i].push_back(j);
							//siblings[j].push_back(j);
							graph[i][j] = true;
							graph[j][i] = true;
						}
					}
				}
				for(int i = 0; i < n; i++) {
					bool flag = true;
					for(int j = 0; j < siblings[i].size(); j++) {
						for(int k = j + 1; k < siblings[i].size(); k++) {
							if(graph[siblings[i][j]][siblings[i][k]]) {
								flag = false;
								break;
							}
						}
						if(!flag) {
							break;
						}
					}
					if(flag) {
						cout << i << ' ';
					}
				}
				cout << endl;
			}

			return 0;
		}
	}// namespace weakvertices

	namespace clockpictures {
		struct match_subarr {
			int start_index;
			int len;
		};
		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			vector<int> a1(n);
			vector<int> a2(n);
			vector<int> space1(n);
			vector<int> space2(n);
			for(int i = 0; i < n; i++) {
				cin >> a1[i];
			}
			for(int i = 0; i < n; i++) {
				cin >> a2[i];
			}
			sort(a1.begin(), a1.end());
			sort(a2.begin(), a2.end());
			for(int i = 0; i < n; i++) {
				space1[i] = ((i + 1 < n) ? a1[i + 1] : (a1[0] + 360000)) - a1[i];
				space2[i] = ((i + 1 < n) ? a2[i + 1] : (a2[0] + 360000)) - a2[i];
			}
			queue<match_subarr> candidates = {};
			for(int i = 0; i < n; i++) {
				candidates.push(match_subarr{i, 0});
			}
			while(!candidates.empty()) {
				auto subarr = candidates.front();
				candidates.pop();
				if(space1[(subarr.start_index + subarr.len + n) % n] == space2[subarr.len]) {
					subarr.len++;
					if(subarr.len + 1 == n) {
						cout << "possible";
						return 0;
					}
					candidates.push(subarr);
				}
			}

			cout << "impossible";

			return 0;
		}
	}// namespace clockpictures

	namespace ceremony {
		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			deque<int> floors;
			for(int i = 0; i < n; i++) {
				int h;
				cin >> h;
				floors.push_back(h);
			}
			sort(floors.begin(), floors.end());
			int ans        = 0;
			int demolished = 0;
			while(!floors.empty()) {
				ans++;
				if(floors.size() > floors.back() - demolished) {
					demolished++;
					while(!floors.empty() && floors.front() - demolished == 0) {
						floors.pop_front();
					}
				} else {
					floors.pop_back();
				}
			}
			cout << ans;
			return 0;
		}
	}// namespace ceremony
}// namespace comp526
