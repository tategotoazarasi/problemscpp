//
// Created by tategotoazarasi on 2021/12/28.
//

#include "acwing.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

namespace acwing {
	int acwing1::main(istream &cin, ostream &cout) {
		int a, b;
		cin >> a >> b;
		cout << a + b;
		return 0;
	}

	int acwing4200::main(istream &cin, ostream &cout) {
		int p1, p2, p3, p4, a, b;
		cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
		int min = p1;
		min = p2 < min ? p2 : min;
		min = p3 < min ? p3 : min;
		min = p4 < min ? p4 : min;
		int ans = (min - a) < (b - a + 1) ? min - a : b - a + 1;
		cout << (ans < 0 ? 0 : ans);
		return 0;
	}

	int acwing4201::main(istream &cin, ostream &cout) {
		int number;
		cin >> number;
		int copy = number;
		int len = 0;
		while(copy != 0) {
			copy /= 10;
			len++;
		}
		auto arr = vector<int>(len);
		copy = number;
		for(int i = len - 1; i >= 0; i--) {
			arr[i] = copy % 10;
			copy /= 10;
		}

		int sum = static_cast<int>(pow(2, len));
		for(int i = 0; i < len; i++) {
			if(arr[i] > 1) { break; }
			if(arr[i] == 0) { sum -= static_cast<int>(pow(2, len - i - 1)); }
		}
		cout << --sum;
		return 0;
	}

	int acwing608::main(istream &cin, ostream &cout) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << "DIFERENCA = " << a * b - c * d;
		return 0;
	}

	int acwing604::main(istream &cin, ostream &cout) {
		const double pi = 3.14159;
		double r;
		cin >> r;
		cout << "A=" << setiosflags(ios::fixed) << setprecision(4) << pi * r * r;
		return 0;
	}

	int acwing606::main(istream &cin, ostream &cout) {
		double a, b;
		cin >> a >> b;
		cout << "MEDIA = " << setiosflags(ios::fixed) << setprecision(5) << (a * 3.5 + b * 7.5) / 11;
		return 0;
	}

	int acwing609::main(istream &cin, ostream &cout) {
		int a;
		double b, c;
		cin >> a >> b >> c;
		cout << "NUMBER = " << a << endl
		     << "SALARY = U$ " << setiosflags(ios::fixed) << setprecision(2) << b * c;
		return 0;
	}

	int acwing615::main(istream &cin, ostream &cout) {
		int x;
		float y;
		cin >> x >> y;
		cout << setiosflags(ios::fixed) << setprecision(3) << static_cast<float>(x) / y << " km/l";
		return 0;
	}

	int acwing616::main(istream &cin, ostream &cout) {
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << setiosflags(ios::fixed) << setprecision(4) << sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		return 0;
	}

	int acwing653::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		cout << n << endl;
		int arr[] = {100, 50, 20, 10, 5, 2, 1};
		for(int i: arr) {
			cout << n / i << " nota(s) de R$ " << i << ",00";
			if(i != 1) { cout << endl; }
			n %= i;
		}
		return 0;
	}

	int acwing4203::main(istream &cin, ostream &cout) {
		string str;
		cin >> str;
		int count0 = 0;
		int count1 = 0;
		for(char c: str) {
			if(c == '1') {
				count1++;
				count0 = 0;
			} else {
				count0++;
				count1 = 0;
			}
			if(count1 == 7 || count0 == 7) {
				cout << "YES";
				return 0;
			}
		}
		cout << "NO";
		return 0;
	}

	int acwing4204::main(istream &cin, ostream &cout) {
		int n;
		const int N = 1010;
		auto g = new int *[N];
		for(int i = 0; i < N; i++) {
			g[i] = new int[N];
			for(int j = 0; j < N; j++) { g[i][j] = 0; }
		}
		cin >> n;
		for(int i = 1; i <= n; i++) {
			g[1][i] = i - 1;
			g[i][1] = i - 1;
		}
		for(int i = 2; i < n; i++) {
			for(int j = 2; j < n; j++) {
				if(i == j) {
					g[i][j] = 0;//对角线为0
				} else {
					if(g[i][j - 1] == 0) {
						//在0后面一格
						g[i][j] = g[i - 1][j] + 1;//上面一格的值+1
					} else {
						//否则
						g[i][j] = g[i][j - 1] + 1;//前面一格的值+1
					}
					if(g[i][j] == n) {
						//达到上限
						g[i][j] = 1;//回归到1
					}
				}
			}
		}
		for(int i = 1; i < n; i++) {
			set<int> s;
			for(int j = 1; j < n; j++) { s.insert(g[i][j]); }
			for(int j = 0; j < n; j++) {
				if(!s.contains(j)) {
					g[i][n] = g[n][i] = j;//补最后一列和最后一行的值
				}
			}
		}

		//输出
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				cout << g[i][j];
				if(j != n) { cout << " "; }
			}
			if(i != n) { cout << endl; }
		}
		return 0;
	}

	int acwing2058::main(istream &cin, ostream &cout) {
		string n2, n3;
		cin >> n2 >> n3;
		auto s = set<long long>();

		for(int i = 0; i < n2.length(); i++) {
			long long val = 0;
			for(int j = 0; j < n2.length(); j++) {
				bool bit = n2[j] != '0';
				if(j == i) { bit = !bit; }
				if(bit) { val += static_cast<long long>(pow(2, n2.size() - j - 1)); }
			}
			s.insert(val);
		}

		for(int n = 1; n <= 2; n++) {
			for(int i = 0; i < n3.length(); i++) {
				long long val = 0;
				for(int j = 0; j < n3.length(); j++) {
					int v = n3[j] - '0';
					if(i == j) {
						v += n;
						v %= 3;
					}
					val += static_cast<long long>(v * pow(3, n3.size() - j - 1));
				}
				if(s.contains(val)) {
					cout << val;
					return 0;
				}
				s.insert(val);
			}
		}
		return 0;
	}

	int acwing654::main(istream &cin, ostream &cout) {
		int n;
		int h, m, s;
		cin >> n;
		s = n % 60;
		n /= 60;
		m = n % 60;
		n /= 60;
		h = n;
		cout << h << ":" << m << ":" << s;
		return 0;
	}

	int acwing605::main(istream &cin, ostream &cout) {
		int a, b;
		cin >> a >> b;
		cout << "PROD = " << a * b;
		return 0;
	}

	int acwing2041::main(istream &cin, ostream &cout) {
		auto haystack = new int[1000010];
		memset(haystack, 0, 1000010 * sizeof *haystack);
		int n, k;
		cin >> n >> k;
		for(int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			haystack[a]++;
			haystack[b + 1]--;
		}
		for(int i = 1; i <= n; i++) { haystack[i] += haystack[i - 1]; }
		sort(haystack + 1, haystack + n + 1);
		cout << haystack[(n + 1) / 2];
		return 0;
	}

	namespace acwing2060 {
		int acwing2060::main(istream &cin, ostream &cout) {
			char cowhide[55][55]{};
			bool occupy[55][55]{};
			auto edge = unordered_set<point, pointhash, pointequal>();
			int n, m;
			cin >> n >> m;
			bool flag = true;
			point first;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					cin >> cowhide[i][j];
					if(flag && cowhide[i][j] == 'X') {
						occupy[i][j] = true;
						first = point(i, j);
						flag = false;
					} else {
						occupy[i][j] = false;
					}
				}
			}

			flood(first, occupy, &edge, cowhide, n, m);

			int count = 0;
			auto nextedge = unordered_set<point, pointhash, pointequal>();
			while(true) {
				for(auto p: edge) {
					point nexts[] = {
					        point(p.x + 1, p.y), point(p.x - 1, p.y), point(p.x, p.y + 1),
					        point(p.x, p.y - 1)};
					for(auto next: nexts) {
						if(0 <= next.x && next.x <= n && 0 <= next.y && next.y <= m && !occupy[next.x][next.y]) {
							if(cowhide[next.x][next.y] == 'X') {
								cout << count;
								return 0;
							}
							cowhide[next.x][next.y] = 'X';
							occupy[next.x][next.y] = true;
							nextedge.insert(next);
						}
					}
				}
				count++;
				edge = nextedge;
				nextedge = unordered_set<point, pointhash, pointequal>();
			}
			return 0;
		}

		size_t pointhash::operator()(const point &p) const { return p.x * 50 + p.y; }

		bool pointequal::operator()(const point &p1, const point &p2) const { return p1.x == p2.x && p1.y == p2.y; }

		void
		flood(point first, bool occupy[55][55], unordered_set<point, pointhash, pointequal> *edge, char cowhide[55][55],
		      int n, int m) {
			auto que = queue<point>();
			auto eq = pointequal();
			que.push(first);
			while(!que.empty()) {
				auto p = que.front();
				if(!eq(p, first) && occupy[p.x][p.y]) {
					que.pop();
					continue;
				}
				occupy[p.x][p.y] = true;
				point nexts[] = {point(p.x + 1, p.y), point(p.x - 1, p.y), point(p.x, p.y + 1), point(p.x, p.y - 1)};
				for(auto next: nexts) {
					if(0 <= next.x && next.x <= n && 0 <= next.y && next.y <= m && !occupy[next.x][next.y]) {
						if(cowhide[next.x][next.y] == 'X') {
							que.push(next);
						} else {
							edge->insert(p);
						}
					}
				}
				que.pop();
			}
		}
	}// namespace acwing2060

	namespace acwing2019 {
		int acwing2019::main(istream &cin, ostream &cout) {
			int n, start_x, start_y;
			auto field = new int *[N + 10];
			for(int i = 0; i < N + 10; i++) {
				field[i] = new int[N + 10];
				memset(field[i], 0, (N + 10) * sizeof(int));
			}
			//int field[N + 10][N + 10];   //记录状态。0=没有 1=墙 2=已经被搜索过

			cin >> n >> start_x >> start_y;
			//memset(field, 0, sizeof field);
			int max_x = 0;
			int max_y = 0;
			for(int i = 0; i < n; i++) {
				int x, y;
				cin >> x >> y;
				if(max_x < x) { max_x = x; }
				if(max_y < y) { max_y = y; }
				field[x][y] = 1;
			}

			cout << bfs(point(start_x, start_y, 0), field, max_x, max_y);
			return 0;
		}

		int bfs(point start, int **field, int max_x, int max_y) {
			auto que = deque<point>();
			que.push_front(start);
			while(!que.empty()) {
				auto p = que.front();
				que.pop_front();
				point nexts[] = {
				        point(p.x + 1, p.y, p.step), point(p.x - 1, p.y, p.step),
				        point(p.x, p.y + 1, p.step), point(p.x, p.y - 1, p.step)};
				for(auto next: nexts) {
					if(next.x == 0 && next.y == 0) { return next.step; }
					if(0 <= next.x && next.x <= max_x + 2 && 0 <= next.y && next.y <= max_y + 2 &&
					   field[next.x][next.y] != 2) {
						if(field[next.x][next.y] == 0) {
							que.push_front(next);
						} else {
							//field[nexts.first][nexts.second]==1
							next.step++;
							que.push_back(next);
						}
						field[next.x][next.y] = 2;
					}
				}
			}
			return start.step;
		}
	}// namespace acwing2019

	int acwing611::main(istream &cin, ostream &cout) {
		int a1, b1, a2, b2;
		double c1, c2;
		cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
		cout << "VALOR A PAGAR: R$ " << setiosflags(ios::fixed) << setprecision(2) << b1 * c1 + b2 * c2;
		return 0;
	}

	int acwing612::main(istream &cin, ostream &cout) {
		double r;
		cin >> r;
		cout << "VOLUME = " << setiosflags(ios::fixed) << setprecision(3) << 4.0 / 3.0 * 3.14159 * r * r * r;
		return 0;
	}

	int acwing2014::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto above = new bool[n];
		auto heights = set<unsigned int>();
		auto m = map<unsigned int, vector<unsigned int>>();
		for(int i = 0; i < n; i++) {
			int height;
			cin >> height;
			heights.insert(height);
			above[i] = true;//露出水面
			if(!m.contains(height)) { m[height] = vector<unsigned int>(); }
			m[height].push_back(i);
		}
		int count = 1;
		int max = count;
		for(auto height: heights) {
			for(auto index: m[height]) {
				above[index] = false;
				if(0 < index && index + 1 < n) {
					if(above[index - 1] && above[index + 1]) {
						count++;
					} else if(!above[index - 1] && !above[index + 1]) {
						count--;
					}
				} else if((index == 0 && !above[1]) || (index == n - 1 && !above[n - 2])) {
					count--;
				}
			}
			if(max < count) { max = count; }
		}
		cout << max;
		return 0;
	}

	int acwing607::main(istream &cin, ostream &cout) {
		double a, b, c;
		cin >> a >> b >> c;
		cout << "MEDIA = " << setiosflags(ios::fixed) << setprecision(1) << (a * 2 + b * 3 + c * 5) / 10;
		return 0;
	}

	int acwing613::main(istream &cin, ostream &cout) {
		double a, b, c;
		cin >> a >> b >> c;
		cout << "TRIANGULO: " << setiosflags(ios::fixed) << setprecision(3) << a * c / 2 << endl;
		cout << "CIRCULO: " << setiosflags(ios::fixed) << setprecision(3) << c * c * 3.14159 << endl;
		cout << "TRAPEZIO: " << setiosflags(ios::fixed) << setprecision(3) << (a + b) * c / 2 << endl;
		cout << "QUADRADO: " << setiosflags(ios::fixed) << setprecision(3) << b * b << endl;
		cout << "RETANGULO: " << setiosflags(ios::fixed) << setprecision(3) << a * b;
		return 0;
	}

	int acwing610::main(istream &cin, ostream &cout) {
		string name;
		double b, m;
		cin >> name >> b >> m;
		cout << "TOTAL = R$ " << setiosflags(ios::fixed) << setprecision(2) << b + 0.15 * m;
		return 0;
	}

	int acwing614::main(istream &cin, ostream &cout) {
		int a, b, c;
		cin >> a >> b >> c;
		int maxab = (a + b + abs(a - b)) / 2;
		cout << (maxab + c + abs(maxab - c)) / 2 << " eh o maior";
		return 0;
	}

	int acwing2005::main(istream &cin, ostream &cout) {
		char horseshoes[5][5];
		bool picked[5][5];
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) { cin >> horseshoes[i][j]; }
		}
		memset(picked, false, sizeof picked);
		if(horseshoes[0][0] == ')') {
			cout << 0;
			return 0;
		}
		cout << dfs(true, horseshoes, picked, 1, 1, 0, 0, n);
		return 0;
	}

	int acwing2005::dfs(bool stage, char horseshoes[5][5], const bool picked[5][5], int count, int level, int x, int y,
	                    int n) {
		if(level == 0 && !stage) {
			if(count == 13) { printf("13"); }
			return count;
		}

		pair<int, int> nexts[4] = {pair<int, int>(x - 1, y), pair<int, int>(x + 1, y), pair<int, int>(x, y - 1),
		                           pair<int, int>(x, y + 1)};
		//复制状态
		bool picked_cpy[5][5];
		memcpy(picked_cpy, picked, sizeof picked_cpy);

		int max = 0;
		picked_cpy[x][y] = true;

		for(auto next: nexts) {
			if(0 <= next.first && next.first < n && 0 <= next.second && next.second < n &&
			   !picked_cpy[next.first][next.second]) {
				int res = 0;
				if(stage && horseshoes[next.first][next.second] == '(') {
					res = dfs(true, horseshoes, picked_cpy, count + 1, level + 1, next.first, next.second, n);
				} else if(stage && horseshoes[next.first][next.second] == ')') {
					res = dfs(false, horseshoes, picked_cpy, count + 1, level - 1, next.first, next.second, n);
				} else if(!stage && horseshoes[next.first][next.second] == ')') {
					res = dfs(false, horseshoes, picked_cpy, count + 1, level - 1, next.first, next.second, n);
				}
				if(max < res) { max = res; }
			}
		}
		return max;
	}

	int acwing617::main(istream &cin, ostream &cout) {
		int l;
		cin >> l;
		cout << 2 * l << " minutos";
		return 0;
	}

	int acwing618::main(istream &cin, ostream &cout) {
		long t, s;
		cin >> t >> s;
		cout << setiosflags(ios::fixed) << setprecision(3) << static_cast<double>(t * s) / 12;
		return 0;
	}

	int acwing4206::main(istream &cin, ostream &cout) {
		string str;
		cin >> str;
		int count = 0;
		for(char ch: str) {
			if(ch == '4' || ch == '7') { count++; }
		}
		if(count == 4 || count == 7) {
			cout << "YES";
		} else {
			cout << "NO";
		}
		return 0;
	}

	int acwing4207::main(istream &cin, ostream &cout) {
		string str;
		cin >> str;
		auto in_sub = new bool[str.length()];
		int count = 0;
		memset(in_sub, false, str.length() * sizeof(bool));

		int prev_left = -1;
		for(int i = 0; i < str.length(); i++) {
			if(str[i] == '(') {
				prev_left = i;
				break;
			}
		}
		for(int i = prev_left; i < str.length(); i++) {
			if(str[i] == ')' && prev_left != -1) {
				count += 2;
				in_sub[prev_left] = true;
				in_sub[i] = true;
				for(int j = prev_left + 1; j < i; j++) {
					if(str[j] == '(') {
						prev_left = j;
						break;
					}
				}
				if(in_sub[prev_left]) { prev_left = -1; }
			} else if(prev_left == -1 && str[i] == '(') {
				prev_left = i;
			}
		}
		cout << count;
		return 0;
	}

	namespace acwing4208 {
		int acwing4208::main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			auto records = map<string, trie_node *>();
			for(int i = 0; i < n; i++) {
				string name;
				cin >> name;
				if(!records.contains(name)) {
					//不存在记录
					records[name] = new trie_node(-1, nullptr);
				}
				int n2;
				cin >> n2;
				for(int j = 0; j < n2; j++) {
					string phone_number;
					cin >> phone_number;
					string phone_number_trim_left;
					for(int k = 0; k < phone_number.length(); k++) {
						if(phone_number[k] != '0') {
							phone_number_trim_left = phone_number.substr(k);
							break;
						}
					}
					reverse(phone_number_trim_left.begin(), phone_number_trim_left.end());
					records[name]->insert(phone_number_trim_left);
				}
			}
			cout << records.size();
			for(auto it: records) {
				cout << it.first << " ";
				cout << it.second->count() << " ";
				it.second->display();
			}
			return 0;
		}

		void trie_node::insert(string str) {
			if(str.length() == 0) { return; }
			if(this->nexts[str[0] - '0'] == nullptr) { this->nexts[str[0] - '0'] = new trie_node(str[0] - '0', this); }
			this->nexts[str[0] - '0']->insert(str.substr(1));
		}

		void trie_node::display() {
			bool flag = true;
			for(auto next: this->nexts) {
				if(next != nullptr) {
					flag = false;
					next->display();
				}
			}
			if(flag) {
				auto current = this;
				while(current->val != -1) {
					cout << static_cast<char>(current->val + '0');
					current = current->father;
				}
				cout << " ";
			}
		}

		int trie_node::count() {
			int count = 0;
			bool flag = true;
			for(auto next: this->nexts) {
				if(next != nullptr) {
					flag = false;
					count += next->count();
				}
			}
			if(flag) { return 1; }
			return count;
		}
	}// namespace acwing4208
}// namespace acwing
