#include "acwing.h"
#include "templates.h"

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

namespace acwing {
	int acwing1::main(istream &cin, ostream &cout) {
		int a;
		int b;
		cin >> a >> b;
		cout << a + b;
		return 0;
	}

	int acwing4200::main(istream &cin, ostream &cout) {
		int p1;
		int p2;
		int p3;
		int p4;
		int a;
		int b;
		cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
		int min       = p1;
		min           = p2 < min ? p2 : min;
		min           = p3 < min ? p3 : min;
		min           = p4 < min ? p4 : min;
		const int ans = min - a < b - a + 1 ? min - a : b - a + 1;
		cout << (ans < 0 ? 0 : ans);
		return 0;
	}

	int acwing4201::main(istream &cin, ostream &cout) {
		int number;
		cin >> number;
		int copy = number;
		int len  = 0;
		while(copy != 0) {
			copy /= 10;
			len++;
		}
		auto arr = vector<int>(len);
		copy     = number;
		for(int i = len - 1; i >= 0; i--) {
			arr[i] = copy % 10;
			copy /= 10;
		}

		int sum = static_cast<int>(pow(2, len));
		for(int i = 0; i < len; i++) {
			if(arr[i] > 1) {
				break;
			}
			if(arr[i] == 0) {
				sum -= static_cast<int>(pow(2, len - i - 1));
			}
		}
		cout << --sum;
		return 0;
	}

	int acwing608::main(istream &cin, ostream &cout) {
		int a;
		int b;
		int c;
		int d;
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
		double a;
		double b;
		cin >> a >> b;
		cout << "MEDIA = " << setiosflags(ios::fixed) << setprecision(5) << (a * 3.5 + b * 7.5) / 11;
		return 0;
	}

	int acwing609::main(istream &cin, ostream &cout) {
		int a;
		double b;
		double c;
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
		double x1;
		double y1;
		double x2;
		double y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << setiosflags(ios::fixed) << setprecision(4) << sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		return 0;
	}

	int acwing653::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		cout << n << endl;
		int arr[] = {100, 50, 20, 10, 5, 2, 1};
		for(const int i: arr) {
			cout << n / i << " nota(s) de R$ " << i << ",00";
			if(i != 1) {
				cout << endl;
			}
			n %= i;
		}
		return 0;
	}

	int acwing4203::main(istream &cin, ostream &cout) {
		string str;
		cin >> str;
		int count0 = 0;
		int count1 = 0;
		for(const char c: str) {
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
		auto *g     = new int *[N];
		for(int i = 0; i < N; i++) {
			g[i] = new int[N];
			for(int j = 0; j < N; j++) {
				g[i][j] = 0;
			}
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
			for(int j = 1; j < n; j++) {
				s.insert(g[i][j]);
			}
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
				if(j != n) {
					cout << " ";
				}
			}
			if(i != n) {
				cout << endl;
			}
		}
		for(int i = 0; i < N; i++) {
			delete[] g[i];
		}
		delete[] g;
		return 0;
	}

	int acwing2058::main(istream &cin, ostream &cout) {
		string n2;
		string n3;
		cin >> n2 >> n3;
		auto s = set<long long>();

		for(int i = 0; i < n2.length(); i++) {
			long long val = 0;
			for(int j = 0; j < n2.length(); j++) {
				bool bit = n2[j] != '0';
				if(j == i) {
					bit = !bit;
				}
				if(bit) {
					val += static_cast<long long>(pow(2, n2.size() - j - 1));
				}
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
		cin >> n;
		const int s = n % 60;
		n /= 60;
		const int m = n % 60;
		n /= 60;
		const int h = n;
		cout << h << ":" << m << ":" << s;
		return 0;
	}

	int acwing605::main(istream &cin, ostream &cout) {
		int a;
		int b;
		cin >> a >> b;
		cout << "PROD = " << a * b;
		return 0;
	}

	int acwing2041::main(istream &cin, ostream &cout) {
		auto *haystack = new int[1000010];
		memset(haystack, 0, 1000010 * sizeof *haystack);
		int n;
		int k;
		cin >> n >> k;
		for(int i = 0; i < k; i++) {
			int a;
			int b;
			cin >> a >> b;
			haystack[a]++;
			haystack[b + 1]--;
		}
		for(int i = 1; i <= n; i++) {
			haystack[i] += haystack[i - 1];
		}
		sort(haystack + 1, haystack + n + 1);
		cout << haystack[(n + 1) / 2];
		delete[] haystack;
		return 0;
	}

	namespace acwing2060 {
		int acwing2060::main(istream &cin, ostream &cout) {
			char cowhide[55][55]{};
			bool occupy[55][55]{};
			auto edge = unordered_set<point, pointhash, pointequal>();
			int n;
			int m;
			cin >> n >> m;
			bool flag = true;
			point first{};
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					cin >> cowhide[i][j];
					if(flag && cowhide[i][j] == 'X') {
						occupy[i][j] = true;
						first        = point(i, j);
						flag         = false;
					} else {
						occupy[i][j] = false;
					}
				}
			}

			flood(first, occupy, &edge, cowhide, n, m);

			int count     = 0;
			auto nextedge = unordered_set<point, pointhash, pointequal>();
			while(true) {
				for(const auto p: edge) {
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
							occupy[next.x][next.y]  = true;
							nextedge.insert(next);
						}
					}
				}
				count++;
				edge     = nextedge;
				nextedge = unordered_set<point, pointhash, pointequal>();
			}
		}

		size_t pointhash::operator()(const point &p) const { return p.x * 50 + p.y; }

		bool pointequal::operator()(const point &p1, const point &p2) const { return p1.x == p2.x && p1.y == p2.y; }

		void
		flood(point first, bool occupy[55][55], unordered_set<point, pointhash, pointequal> *edge, char cowhide[55][55],
		      int n, int m) {
			auto que      = queue<point>();
			const auto eq = pointequal();
			que.push(first);
			while(!que.empty()) {
				auto p = que.front();
				if(!eq(p, first) && occupy[p.x][p.y]) {
					que.pop();
					continue;
				}
				occupy[p.x][p.y] = true;
				point nexts[]    = {point(p.x + 1, p.y), point(p.x - 1, p.y), point(p.x, p.y + 1), point(p.x, p.y - 1)};
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
			int n;
			int start_x;
			int start_y;
			auto *field = new int *[N + 10];
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
				int x;
				int y;
				cin >> x >> y;
				if(max_x < x) {
					max_x = x;
				}
				if(max_y < y) {
					max_y = y;
				}
				field[x][y] = 1;
			}
			cout << bfs(point(start_x, start_y, 0), field, max_x, max_y);
			for(int i = 0; i < N + 10; i++) {
				delete[] field[i];
			}
			delete[] field;
			return 0;
		}

		int bfs(point start, int **field, int max_x, int max_y) {
			auto que = deque<point>();
			que.push_front(start);
			while(!que.empty()) {
				const auto p = que.front();
				que.pop_front();
				point nexts[] = {
				        point(p.x + 1, p.y, p.step), point(p.x - 1, p.y, p.step),
				        point(p.x, p.y + 1, p.step), point(p.x, p.y - 1, p.step)};
				for(auto next: nexts) {
					if(next.x == 0 && next.y == 0) {
						return next.step;
					}
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
		int a1;
		int b1;
		int a2;
		int b2;
		double c1;
		double c2;
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
		auto *above  = new bool[n];
		auto heights = set<unsigned int>();
		auto m       = map<unsigned int, vector<unsigned int>>();
		for(int i = 0; i < n; i++) {
			int height;
			cin >> height;
			heights.insert(height);
			above[i] = true;//露出水面
			if(!m.contains(height)) {
				m[height] = vector<unsigned int>();
			}
			m[height].push_back(i);
		}
		int count = 1;
		int max   = count;
		for(auto height: heights) {
			for(const auto index: m[height]) {
				above[index] = false;
				if(0 < index && index + 1 < n) {
					if(above[index - 1] && above[index + 1]) {
						count++;
					} else if(!above[index - 1] && !above[index + 1]) {
						count--;
					}
				} else if(index == 0 && !above[1] || index == n - 1 && !above[n - 2]) {
					count--;
				}
			}
			if(max < count) {
				max = count;
			}
		}
		cout << max;
		delete[] above;
		return 0;
	}

	int acwing607::main(istream &cin, ostream &cout) {
		double a;
		double b;
		double c;
		cin >> a >> b >> c;
		cout << "MEDIA = " << setiosflags(ios::fixed) << setprecision(1) << (a * 2 + b * 3 + c * 5) / 10;
		return 0;
	}

	int acwing613::main(istream &cin, ostream &cout) {
		double a;
		double b;
		double c;
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
		double b;
		double m;
		cin >> name >> b >> m;
		cout << "TOTAL = R$ " << setiosflags(ios::fixed) << setprecision(2) << b + 0.15 * m;
		return 0;
	}

	int acwing614::main(istream &cin, ostream &cout) {
		int a;
		int b;
		int c;
		cin >> a >> b >> c;
		const int maxab = (a + b + abs(a - b)) / 2;
		cout << (maxab + c + abs(maxab - c)) / 2 << " eh o maior";
		return 0;
	}

	int acwing2005::main(istream &cin, ostream &cout) {
		char horseshoes[5][5];
		bool picked[5][5];
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> horseshoes[i][j];
			}
		}
		memset(picked, 0, sizeof picked);
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
			if(count == 13) {
				printf("13");
			}
			return count;
		}

		pair<int, int> nexts[4] = {pair(x - 1, y), pair(x + 1, y), pair(x, y - 1),
		                           pair(x, y + 1)};
		//复制状态
		bool picked_cpy[5][5];
		memcpy(picked_cpy, picked, sizeof picked_cpy);

		int max          = 0;
		picked_cpy[x][y] = true;

		for(const auto next: nexts) {
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
				if(max < res) {
					max = res;
				}
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
		long t;
		long s;
		cin >> t >> s;
		cout << setiosflags(ios::fixed) << setprecision(3) << static_cast<double>(t * s) / 12;
		return 0;
	}

	int acwing4206::main(istream &cin, ostream &cout) {
		string str;
		cin >> str;
		int count = 0;
		for(const char ch: str) {
			if(ch == '4' || ch == '7') {
				count++;
			}
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
		auto *in_sub = new bool[str.length()];
		int count    = 0;
		memset(in_sub, 0, str.length() * sizeof(bool));

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
				in_sub[i]         = true;
				for(int j = prev_left + 1; j < i; j++) {
					if(str[j] == '(') {
						prev_left = j;
						break;
					}
				}
				if(in_sub[prev_left]) {
					prev_left = -1;
				}
			} else if(prev_left == -1 && str[i] == '(') {
				prev_left = i;
			}
		}
		cout << count;
		delete[] in_sub;
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
			if(str.length() == 0) {
				return;
			}
			if(this->nexts[str[0] - '0'] == nullptr) {
				this->nexts[str[0] - '0'] = new trie_node(str[0] - '0', this);
			}
			this->nexts[str[0] - '0']->insert(str.substr(1));
		}

		void trie_node::display() {
			bool flag = true;
			for(auto *next: this->nexts) {
				if(next != nullptr) {
					flag = false;
					next->display();
				}
			}
			if(flag) {
				const auto *current = this;
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
			for(auto *next: this->nexts) {
				if(next != nullptr) {
					flag = false;
					count += next->count();
				}
			}
			if(flag) {
				return 1;
			}
			return count;
		}
	}// namespace acwing4208

	int acwing1996::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto names = vector<string>();
		names.resize(n);
		auto min_names = vector<string>();
		auto max_names = vector<string>();
		min_names.resize(n);
		max_names.resize(n);
		for(int i = 0; i < n; i++) {
			cin >> names[i];
			const auto *min_name_const_c_str = names[i].c_str();
			const auto *max_name_const_c_str = names[i].c_str();
			auto *min_name_c_str             = new char[names[i].length() + 1];
			auto *max_name_c_str             = new char[names[i].length() + 1];
			strcpy(min_name_c_str, min_name_const_c_str);
			strcpy(max_name_c_str, max_name_const_c_str);
			sort(min_name_c_str, min_name_c_str + names[i].length() * sizeof(char));
			sort(max_name_c_str, max_name_c_str + names[i].length() * sizeof(char), cmp);
			const auto min_name = string(min_name_c_str);
			const auto max_name = string(max_name_c_str);
			min_names[i]        = min_name;
			max_names[i]        = max_name;
			delete[] min_name_c_str;
			delete[] max_name_c_str;
		}
		auto min_names_sorted = vector(min_names);
		auto max_names_sorted = vector(max_names);
		sort(min_names_sorted.begin(), min_names_sorted.end());
		sort(max_names_sorted.begin(), max_names_sorted.end());
		for(int i = 0; i < n; i++) {
			auto min_name = min_names[i];
			auto max_name = max_names[i];
			cout << lower_bound(max_names_sorted.begin(), max_names_sorted.end(), min_name) - max_names_sorted.begin() +
			                1
			     << " "
			     << upper_bound(min_names_sorted.begin(), min_names_sorted.end(), max_name) - min_names_sorted.begin()
			     << endl;
		}
		return 0;
	}

	bool acwing1996::cmp(char x, char y) { return x > y; }

	int acwing656::main(istream &cin, ostream &cout) {
		double n;
		cin >> n;
		int total                 = static_cast<int>(n * static_cast<double>(100));
		const int denominations[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
		int count[12];
		for(int i = 0; i < 12; i++) {
			count[i] = total / denominations[i];
			total %= denominations[i];
		}
		cout << "NOTAS:" << endl
		     << count[0] << " nota(s) de R$ 100.00" << endl
		     << count[1] << " nota(s) de R$ 50.00" << endl
		     << count[2] << " nota(s) de R$ 20.00" << endl
		     << count[3] << " nota(s) de R$ 10.00" << endl
		     << count[4] << " nota(s) de R$ 5.00" << endl
		     << count[5] << " nota(s) de R$ 2.00" << endl
		     << "MOEDAS:" << endl
		     << count[6] << " moeda(s) de R$ 1.00" << endl
		     << count[7] << " moeda(s) de R$ 0.50" << endl
		     << count[8] << " moeda(s) de R$ 0.25" << endl
		     << count[9] << " moeda(s) de R$ 0.10" << endl
		     << count[10] << " moeda(s) de R$ 0.05" << endl
		     << count[11] << " moeda(s) de R$ 0.01";
		return 0;
	}

	int acwing655::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		cout << n / 365 << " ano(s)" << endl;
		n %= 365;
		cout << n / 30 << " mes(es)" << endl;
		n %= 30;
		cout << n << " dia(s)";
		return 0;
	}

	int acwing665::main(istream &cin, ostream &cout) {
		int a;
		int b;
		cin >> a >> b;
		if(a % b == 0 || b % a == 0) {
			cout << "Sao Multiplos";
		} else {
			cout << "Nao sao Multiplos";
		}
		return 0;
	}

	int acwing657::main(istream &cin, ostream &cout) {
		int a;
		int b;
		int c;
		int d;
		cin >> a >> b >> c >> d;
		if(b > c && d > a && c + d > a + b && c > 0 && d > 0 && a % 2 == 0) {
			cout << "Valores aceitos";
		} else {
			cout << "Valores nao aceitos";
		}
		return 0;
	}

	int acwing1987::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto m      = map<int, int>();
		int current = 0;
		for(int i = 0; i < n; i++) {
			int length;
			char direction;
			cin >> length >> direction;
			if(direction == 'R') {
				if(!m.contains(current)) {
					m.insert(pair(current, 1));
				} else {
					m[current]++;
				}
				if(!m.contains(current + length)) {
					m.insert(pair(current + length, -1));
				} else {
					m[current + length]--;
				}
				current += length;
			} else {
				if(!m.contains(current)) {
					m.insert(pair(current, -1));
				} else {
					m[current]--;
				}
				if(!m.contains(current - length)) {
					m.insert(pair(current - length, 1));
				} else {
					m[current - length]++;
				}
				current -= length;
			}
		}
		unsigned int layer_count = 0;
		unsigned int count       = 0;
		bool above2              = false;
		int prev;
		for(const auto p: m) {
			layer_count += p.second;
			if(layer_count >= 2) {
				if(above2) {
					count += p.first - prev;
				}
				above2 = true;
				prev   = p.first;
			} else {
				if(above2) {
					count += p.first - prev;
				}
				above2 = false;
			}
		}
		cout << count;
		return 0;
	}

	int acwing660::main(istream &cin, ostream &cout) {
		const double snacks[] = {4, 4.5, 5, 2, 1.5};
		int x;
		int y;
		cin >> x >> y;
		cout << "Total: R$ " << setiosflags(ios::fixed) << setprecision(2) << snacks[x - 1] * y;
		return 0;
	}

	int acwing671::main(istream &cin, ostream &cout) {
		auto cities = unordered_map<unsigned int, string>();
		cities[61]  = "Brasilia";
		cities[71]  = "Salvador";
		cities[11]  = "Sao Paulo";
		cities[21]  = "Rio de Janeiro";
		cities[32]  = "Juiz de Fora";
		cities[19]  = "Campinas";
		cities[27]  = "Vitoria";
		cities[31]  = "Belo Horizonte";
		int number;
		cin >> number;
		if(cities.contains(number)) {
			cout << cities[number];
		} else {
			cout << "DDD nao cadastrado";
		}
		return 0;
	}

	namespace acwing1978 {
		int acwing1978::main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			auto *maximum = new int[n];
			auto *minimum = new int[n];
			memset(maximum, 0, n * sizeof(int));
			memset(minimum, 0, n * sizeof(int));
			auto *paths = new path[n];
			for(int i = 0; i < n; i++) {
				int a;
				int b;
				cin >> a >> b;
				paths[i] = path(a, b);
			}
			sort(paths, paths + n);
			maximum[0]     = paths[0].b;    //i以前b的最大值
			minimum[n - 1] = paths[n - 1].b;//i以后b的最小值
			for(int i = 1; i < n; i++) {
				maximum[i] = max(maximum[i - 1], paths[i].b);
			}
			for(int i = n - 2; i >= 0; i--) {
				minimum[i] = min(minimum[i + 1], paths[i].b);
			}
			int ans = n;
			for(int i = 0; i < n; i++) {
				if(maximum[i] > paths[i].b || minimum[i] < paths[i].b) {
					ans--;
				}
			}
			cout << ans;
			delete[] paths;
			delete[] minimum;
			delete[] maximum;
			return 0;
		}

		bool path::operator<(const path &p) const { return this->a < p.a; }
	}// namespace acwing1978

	int acwing659::main(istream &cin, ostream &cout) {
		double x;
		const string output[] = {"[0,25]", "(25,50]", "(50,75]", "(75,100]"};
		cin >> x;
		if(x < 0.0 || x > 100.0) {
			cout << "Fora de intervalo";
		} else if(x > 75.0) {
			cout << "Intervalo " << output[3];
		} else if(x > 50.0) {
			cout << "Intervalo " << output[2];
		} else if(x > 25.0) {
			cout << "Intervalo " << output[1];
		} else {
			cout << "Intervalo " << output[0];
		}
		return 0;
	}

	int acwing662::main(istream &cin, ostream &cout) {
		float x;
		float y;
		cin >> x >> y;
		if(x == 0 && y == 0) {
			cout << "Origem";
		} else if(x == 0) {
			cout << "Eixo Y";
		} else if(y == 0) {
			cout << "Eixo X";
		} else if(x > 0 && y > 0) {
			cout << "Q1";
		} else if(x < 0 && y > 0) {
			cout << "Q2";
		} else if(x < 0 && y < 0) {
			cout << "Q3";
		} else {
			cout << "Q4";
		}
		return 0;
	}

	int acwing1969::main(istream &cin, ostream &cout) {
		unsigned int n;
		unsigned int k;
		cin >> n >> k;
		auto um           = unordered_map<unsigned int, unsigned int>();
		auto overcrowding = set<unsigned int>();
		for(unsigned int i = 0; i < n; i++) {
			unsigned int id;
			cin >> id;
			if(!um.contains(id)) {
				um.insert(pair(id, i));
			} else if(!overcrowding.contains(id)) {
				if(i - um[id] > k) {
					um[id] = i;
				} else {
					overcrowding.insert(id);
				}
			}
		}
		if(overcrowding.empty()) {
			cout << -1;
		} else {
			cout << *--overcrowding.end();
		}
		return 0;
	}

	int acwing664::main(istream &cin, ostream &cout) {
		double a;
		double b;
		double c;
		cin >> a >> b >> c;
		cout << setiosflags(ios::fixed) << setprecision(1);
		if(a + b <= c || a + c <= b || b + c <= a) {
			cout << "Area = " << (a + b) * c / 2;
		} else {
			cout << "Perimetro = " << a + b + c;
		}
		return 0;
	}

	int acwing666::main(istream &cin, ostream &cout) {
		double arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3);
		const double a = arr[2];
		const double b = arr[1];
		const double c = arr[0];
		if(a >= b + c) {
			cout << "NAO FORMA TRIANGULO";
		} else {
			if(a * a == b * b + c * c) {
				cout << "TRIANGULO RETANGULO" << endl;
			}
			if(a * a > b * b + c * c) {
				cout << "TRIANGULO OBTUSANGULO" << endl;
			}
			if(a * a < b * b + c * c) {
				cout << "TRIANGULO ACUTANGULO" << endl;
			}
			if(a == b && b == c) {
				cout << "TRIANGULO EQUILATERO" << endl;
			}
			if(a == b && b != c || b == c && a != b || a == c && a != b) {
				cout << "TRIANGULO ISOSCELES" << endl;
			}
		}
		return 0;
	}

	int acwing1960::main(istream &cin, ostream &cout) {
		memset(fsm, -2, sizeof fsm);
		unsigned long long b;
		cin >> n >> b;
		unsigned int status = 0;
		for(int i = 0; i < n; i++) {
			unsigned int bulb;
			cin >> bulb;
			status += bulb;
			status <<= 1;
		}
		status >>= 1;
		fsm[status] = -1;

		int count          = 0;
		int round          = 0;
		unsigned int index = 0;
		for(int i = 0; i < b; i++) {
			if(fsm[status] >= 0) {
				if(round == 0) {
					round = 1;
					index = status;
				} else if(round == 1 && status == index) {
					b     = (b - i) % count + i;
					round = 2;
				}
			}
			if(round == 1) {
				count++;
			}
			status = get_next(status);
		}
		const auto *const ans = decompress(status);
		for(int i = 0; i < n; i++) {
			cout << static_cast<int>(ans[i]) << endl;
		}
		delete[] ans;
		return 0;
	}

	unsigned int acwing1960::get_next(unsigned int status) {
		if(fsm[status] >= 0) {
			return fsm[status];
		}
		const bool *bulbs      = decompress(status);
		auto *const next_bulbs = new bool[n];
		for(int i = 0; i < n; i++) {
			if(bulbs[(i - 1 + n) % n]) {
				next_bulbs[i] = !bulbs[i];
			} else {
				next_bulbs[i] = bulbs[i];
			}
		}
		const int next_status = compress(next_bulbs);
		fsm[status]           = next_status;
		delete[] next_bulbs;
		delete[] bulbs;
		return next_status;
	}

	bool *acwing1960::decompress(unsigned int status) const {
		auto *const bulbs = new bool[n];
		for(int i = n - 1; i >= 0; i--) {
			bulbs[i] = (status & 1) != 0U;
			status >>= 1;
		}
		return bulbs;
	}

	unsigned int acwing1960::compress(const bool *bulbs) const {
		int status = 0;
		for(int i = 0; i < n; i++) {
			status += static_cast<int>(bulbs[i]);
			status <<= 1;
		}
		status >>= 1;
		return status;
	}

	int acwing667::main(istream &cin, ostream &cout) {
		unsigned int a;
		unsigned int b;
		cin >> a >> b;
		int t = (b - a + 24) % 24;
		if(t == 0) {
			t = 24;
		}
		cout << "O JOGO DUROU " << t << " HORA(S)";
		return 0;
	}

	int acwing668::main(istream &cin, ostream &cout) {
		unsigned int a;
		unsigned int b;
		unsigned int c;
		unsigned int d;
		cin >> a >> b >> c >> d;
		unsigned int t = (c * 60 + d - (a * 60 + b) + 24 * 60) % (24 * 60);
		if(t == 0) {
			t = 24 * 60;
		}
		cout << "O JOGO DUROU " << t / 60 << " HORA(S) E " << t % 60 << " MINUTO(S)";
		return 0;
	}

	int acwing1952::main(istream &cin, ostream &cout) {
		unsigned short n;
		unsigned short x;
		unsigned short y;
		unsigned short z;
		cin >> n >> x >> y >> z;
		auto as    = unordered_map<unsigned int, unsigned int>();
		auto bs    = unordered_map<unsigned int, unsigned int>();
		auto edges = set<unsigned int>();
		for(unsigned short i = 0; i < n; i++) {
			unsigned int a;
			unsigned int b;
			cin >> a >> b;
			if(!as.contains(a)) {
				as.insert(pair<unsigned int, unsigned int>(a, 1));
				edges.insert(a);
			} else {
				as[a]++;
			}
			if(!bs.contains(b)) {
				bs.insert(pair<unsigned int, unsigned int>(b, 1));
				edges.insert(b);
			} else {
				bs[b]++;
			}
		}
		unsigned int count = x * n;
		unsigned int max   = count;
		for(unsigned int edge: edges) {
			if(as.contains(edge)) {
				count += (y - x) * as[edge];
			}
			if(max < count) {
				max = count;
			}
			if(bs.contains(edge)) {
				count -= (y - z) * bs[edge];
			}
		}
		cout << max;
		return 0;
	}

	int acwing669::main(istream &cin, ostream &cout) {
		double salary;
		cin >> salary;
		unsigned short percentual = 0;
		if(salary <= 400) {
			percentual = 15;
		} else if(salary <= 800) {
			percentual = 12;
		} else if(salary <= 1200) {
			percentual = 10;
		} else if(salary <= 2000) {
			percentual = 7;
		} else {
			percentual = 4;
		}
		const double new_salary = salary * (100 + percentual) / 100;
		cout << setiosflags(ios::fixed) << setprecision(2);
		cout << "Novo salario: " << new_salary << endl;
		cout << "Reajuste ganho: " << new_salary - salary << endl;
		cout << "Em percentual: " << percentual << " %";
		return 0;
	}

	int acwing672::main(istream &cin, ostream &cout) {
		double income;
		cin >> income;
		double tax = 0;
		if(income <= 2000) {
			tax = 0;
		} else if(2000 < income && income <= 3000) {
			income -= 2000;
			tax += income * 0.08;
		} else if(income <= 4500) {
			tax = 80;
			income -= 3000;
			tax += income * 0.18;
		} else {
			tax = 350;
			income -= 4500;
			tax += income * 0.28;
		}
		if(tax == 0) {
			cout << "Isento";
		} else {
			cout << setiosflags(ios::fixed) << setprecision(2) << "R$ " << tax;
		}
		return 0;
	}

	int acwing1945::main(istream &cin, ostream &cout) {
		unsigned int count = 0;
		unsigned short n;
		cin >> n;
		auto cows = vector<unsigned int>();
		cows.resize(n);
		for(int i = 0; i < n; i++) {
			unsigned int cow;
			cin >> cow;
			cows[i] = cow;
		}
		sort(cows.begin(), cows.end());
		for(auto i = cows.begin(); i != cows.end(); ++i) {
			for(auto j = i + 1; j != cows.end(); ++j) {
				const unsigned int xy = *j - *i;
				auto min              = lower_bound(j, cows.end(), *j + xy);
				auto max              = upper_bound(j, cows.end(), *j + 2 * xy);
				count += max - min;
			}
		}
		cout << count;
		return 0;
	}

	int acwing4209::main(istream &cin, ostream &cout) {
		unsigned int n;
		cin >> n;
		int x = 0;
		int y = 0;
		int z = 0;
		for(int i = 0; i < n; i++) {
			int xi;
			int yi;
			int zi;
			cin >> xi >> yi >> zi;
			x += xi;
			y += yi;
			z += zi;
		}
		if(x == 0 && y == 0 && z == 0) {
			cout << "YES";
		} else {
			cout << "NO";
		}
		return 0;
	}

	int acwing4210::main(istream &cin, ostream &cout) {
		unsigned short a;
		cin >> a;
		unsigned int count = 0;
		for(int i = 2; i <= a - 1; i++) {
			unsigned short cpy = a;
			while(cpy != 0) {
				count += cpy % i;
				cpy /= i;
			}
		}
		unsigned int denominator = a - 2;
		unsigned int molecular   = count;
		while(denominator % molecular != 0) {
			const unsigned int temp = denominator;
			denominator             = molecular;
			molecular               = temp % molecular;
		}
		cout << count / molecular << "/" << (a - 2) / molecular;
		return 0;
	}

	int acwing4211::main(istream &cin, ostream &cout) {
		unsigned short n;
		cin >> n;
		auto vec = vector<unsigned long long>();
		for(unsigned short i = 0; i < n; i++) {
			unsigned long long a;
			cin >> a;
			vec.push_back(a);
		}
		sort(vec.begin(), vec.end(), cmp);
		for(const auto i: vec) {
			cout << i << " ";
		}
		return 0;
	}

	unsigned int acwing4211::no2(unsigned long long a) {
		unsigned int count = 0;
		while(a % 2 == 0) {
			count++;
			a /= 2;
		}
		return count;
	}

	unsigned int acwing4211::no3(unsigned long long a) {
		unsigned int count = 0;
		while(a % 3 == 0) {
			count++;
			a /= 3;
		}
		return count;
	}

	bool acwing4211::cmp(unsigned long long a, unsigned long long b) {
		const unsigned a3 = no3(a);
		const unsigned b3 = no3(b);
		if(a3 == b3) {
			const unsigned a2 = no2(a);
			const unsigned b2 = no2(b);
			return a2 < b2;
		}
		return a3 > b3;
	}

	int acwing670::main(istream &cin, ostream &cout) {
		string str1;
		string str2;
		string str3;
		cin >> str1 >> str2 >> str3;
		if(str1 == "vertebrado") {
			if(str2 == "ave") {
				if(str3 == "carnivoro") {
					cout << "aguia";
				} else {
					cout << "pomba";
				}
			} else {
				if(str3 == "onivoro") {
					cout << "homem";
				} else {
					cout << "vaca";
				}
			}
		} else {
			if(str2 == "inseto") {
				if(str3 == "hematofago") {
					cout << "pulga";
				} else {
					cout << "lagarta";
				}
			} else {
				if(str3 == "hematofago") {
					cout << "sanguessuga";
				} else {
					cout << "minhoca";
				}
			}
		}
		return 0;
	}

	int acwing633::main(istream &cin, ostream &cout) {
		auto vec = vector<short>();
		vec.resize(3);
		cin >> vec[0];
		cin >> vec[1];
		cin >> vec[2];
		auto sorted = vector(vec);
		sort(sorted.begin(), sorted.end());
		for(const auto num: sorted) {
			cout << num << endl;
		}
		cout << endl;
		for(const auto num: vec) {
			cout << num << endl;
		}
		return 0;
	}

	int acwing1934::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto t = vector<int>();
		auto d = vector<int>();
		for(int i = 0; i < n; i++) {
			char op;
			int x;
			cin >> op >> x;
			if(op == 'T') {
				t.push_back(x);
			} else {
				d.push_back(x);
			}
		}
		sort(t.begin(), t.end());
		sort(d.begin(), d.end());
		double current_d     = 0;
		double current_t     = 0;
		double decelerations = 1;
		auto it_d            = d.begin();
		auto it_t            = t.begin();
		while(true) {
			int next_d = 1000;
			if(it_d != d.end()) {
				next_d = *it_d;
			}
			const auto t_for_next_d = (next_d - current_d) * decelerations;//到下一个D的时间
			bool next_is_d          = true;
			if(it_t != t.end()) {
				next_is_d = t_for_next_d < *it_t - current_t;
			}
			if(next_is_d) {
				//先到D
				current_d = next_d;
				++it_d;
				current_t += t_for_next_d;
			} else if(it_t != t.end()) {
				//先到T
				current_d += (*it_t - current_t) * (1.0 / decelerations);
				current_t = *it_t;
				++it_t;
			}
			decelerations++;
			if(it_d == d.end() && it_t == t.end()) {
				current_t += (1000 - current_d) * decelerations;
				break;
			}
		}
		cout << lround(current_t);
		return 0;
	}

	int acwing658::main(istream &cin, ostream &cout) {
		double a;
		double b;
		double c;
		cin >> a >> b >> c;
		if(b * b - 4 * a * c < 0 || a == 0) {
			cout << "Impossivel calcular";
			return 0;
		}
		const auto r1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		const auto r2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		cout << setiosflags(ios::fixed) << setprecision(5)
		     << "R1 = " << r1 << endl
		     << "R2 = " << r2;
		return 0;
	}

	int acwing661::main(istream &cin, ostream &cout) {
		double n1;
		double n2;
		double n3;
		double n4;
		cin >> n1 >> n2 >> n3 >> n4;
		const double x = (2 * n1 + 3 * n2 + 4 * n3 + n4) / 10;
		cout << setiosflags(ios::fixed) << setprecision(1);
		cout << "Media: " << x << endl;
		if(x >= 7.0) {
			cout << "Aluno aprovado.";
		} else if(x <= 5.0) {
			cout << "Aluno reprovado.";
		} else {
			cout << "Aluno em exame." << endl;
			double y;
			cin >> y;
			cout << "Nota do exame: " << y << endl;
			const double z = (x + y) / 2;
			if(z >= 5.0) {
				cout << "Aluno aprovado." << endl;
			} else {
				cout << "Aluno reprovado." << endl;
			}
			cout << "Media final: " << z;
		}
		return 0;
	}

	namespace acwing1929 {
		int Solution::main(istream &cin, ostream &cout) {
			cin >> n >> m;
			for(unsigned short i = 0; i < n; i++) {
				for(unsigned short j = 0; j < m; j++) {
					cin >> mirrors[i][j];
				}
			}
			int maximum = -1;
			for(unsigned short j = 0; j < m; j++) {
				maximum = max(maximum, static_cast<int>(count_reflect(down, 0, j)));
			}
			for(unsigned short j = 0; j < m; j++) {
				maximum = max(maximum, static_cast<int>(count_reflect(up, n - 1, j)));
			}
			for(unsigned short i = 0; i < n; i++) {
				maximum = max(maximum, static_cast<int>(count_reflect(right, i, 0)));
			}
			for(unsigned short i = 0; i < n; i++) {
				maximum = max(maximum, static_cast<int>(count_reflect(left, i, m - 1)));
			}
			cout << maximum;
			return 0;
		}

		unsigned int Solution::count_reflect(direction d, unsigned int x, unsigned int y) {
			if(x == 0 || y == 0 || x == n - 1 || y == m - 1) {
				unsigned int count  = 0;
				int current_x       = x;
				int current_y       = y;
				direction current_d = d;
				auto path           = unordered_set<step, step_hash, step_equal>();
				while(0 <= current_x && current_x < n && 0 <= current_y && current_y < m) {
					auto s = step(current_d, current_x, current_y);
					if(!path.contains(s)) {
						path.insert(s);
					} else {
						return -1;
					}

					const auto *record = get_record(d);
					if((*record)[x][y] != 0) {
						return count + (*record)[x][y];
					}
					current_d = reflect(current_d, mirrors[current_x][current_y]);
					count++;
					(*get_record(!current_d))[current_x][current_y] = count;
					switch(current_d) {
						case left: {
							current_y--;
							break;
						}
						case right: {
							current_y++;
							break;
						}
						case up: {
							current_x--;
							break;
						}
						case down: {
							current_x++;
							break;
						}
					}
				}
				return count;
			}
			return -1;
		}

		unsigned int (*Solution::get_record(direction d))[1000][1000] {
			switch(d) {
				case left: {
					return &left_map;
				}
				case right: {
					return &right_map;
				}
				case up: {
					return &up_map;
				}
				case down: {
					return &down_map;
				}
			}
			return nullptr;
		}

		direction reflect(direction d, char mirror) {
			switch(d) {
				case left: {
					if(mirror == '/') {
						return down;
					}
					if(mirror == '\\') {
						return up;
					}
					break;
				}
				case right: {
					if(mirror == '/') {
						return up;
					}
					if(mirror == '\\') {
						return down;
					}
					break;
				}
				case up: {
					if(mirror == '/') {
						return right;
					}
					if(mirror == '\\') {
						return left;
					}
					break;
				}
				case down: {
					if(mirror == '/') {
						return left;
					}
					if(mirror == '\\') {
						return right;
					}
					break;
				}
			}
			return {};
		}

		direction operator!(const direction &d) {
			switch(d) {
				case left: {
					return right;
				}
				case right: {
					return left;
				}
				case up: {
					return down;
				}
				case down: {
					return up;
				}
			}
			return {};
		}

		unsigned long step_hash::operator()(const step &s) const { return s.d * 1000 * 1000 + s.x * 1000 + s.y; }

		bool step_equal::operator()(const step &s1, const step &s2) const { return s1.d == s2.d && s1.x == s2.x && s1.y == s2.y; }
	}// namespace acwing1929

	int acwing708::main(istream & /*cin*/, ostream &cout) {
		for(int i = 1; i <= 100; i++) {
			if(i % 2 == 0) {
				cout << i << endl;
			}
		}
		return 0;
	}

	int acwing715::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		for(int i = 2; i < 10000; i += n) {
			cout << i << endl;
		}
		return 0;
	}

	int acwing1922::main(istream &cin, ostream &cout) {
		unsigned int n;
		unsigned int k;
		cin >> n >> k;
		auto um            = unordered_map<unsigned int, unsigned int>();
		unsigned int max_x = 0;
		for(unsigned int i = 0; i < n; i++) {
			unsigned int g;
			unsigned int x;
			cin >> g >> x;
			max_x = max(max_x, x);
			um.insert(pair(x, g));
		}
		unsigned int count = 0;
		for(int i = 0; i < 2 * k; i++) {
			if(um.contains(i)) {
				count += um[i];
			}
		}
		unsigned int maximum = count;
		for(int i = 1; i + 2 * k <= max_x; i++) {
			if(um.contains(i - 1)) {
				count -= um[i - 1];
			}
			if(um.contains(i + 2 * k)) {
				count += um[i + 2 * k];
			}
			maximum = max(maximum, count);
		}
		cout << maximum;
		return 0;
	}

	int acwing709::main(istream &cin, ostream &cout) {
		int x;
		cin >> x;
		for(int i = 1; i <= x; i += 2) {
			cout << i << endl;
		}
		return 0;
	}

	int acwing710::main(istream &cin, ostream &cout) {
		int x;
		cin >> x;
		if(x % 2 == 0) {
			x++;
		}
		for(int i = 0; i < 6; i++) {
			cout << x + i * 2 << endl;
		}
		return 0;
	}

	int acwing1913::main(istream &cin, ostream &cout) {
		unsigned int n;
		cin >> n;
		auto cows    = map<unsigned int, int>();
		auto indexes = vector<unsigned int>();
		auto sum     = unordered_map<int, set<unsigned int>>();
		for(unsigned int i = 0; i < n; i++) {
			unsigned int x;
			char b;
			cin >> x >> b;
			indexes.push_back(x);
			if(b == 'G') {
				cows.insert(pair(x, 1));
			} else {
				cows.insert(pair(x, -1));
			}
		}
		sort(indexes.begin(), indexes.end());

		unsigned int g_count = 0;
		unsigned int h_count = 0;
		unsigned int g_max   = 0;
		unsigned int h_max   = 0;
		int g_start          = -1;
		int h_start          = -1;
		int count            = 0;
		for(auto &cow: cows) {
			if(cow.second == 1) {
				//G
				h_count = 0;
				h_start = -1;
				if(g_start == -1) {
					g_start = cow.first;
				} else {
					g_count = cow.first - g_start;
				}
				g_max = max(g_max, g_count);
			} else {
				//H
				g_count = 0;
				g_start = -1;
				if(h_start == -1) {
					h_start = cow.first;
				} else {
					h_count = cow.first - h_start;
				}
				h_max = max(h_max, h_count);
			}
			count += cow.second;
			cow.second = count;
			if(!sum.contains(cow.second)) {
				auto s = set<unsigned int>();
				s.insert(cow.first);
				sum.insert(pair(cow.second, s));
			} else {
				sum[cow.second].insert(cow.first);
			}
		}
		unsigned int maximum = 0;
		for(const auto &i: sum) {
			if(i.first == 0) {
				maximum = max(maximum, *i.second.rbegin() - indexes[0]);
			} else if(i.second.size() >= 2) {
				maximum = max(maximum, *i.second.rbegin() - *upper_bound(indexes.begin(), indexes.end(), *i.second.begin()));
			}
		}
		cout << max(maximum, max(g_max, h_max));
		return 0;
	}

	int acwing712::main(istream &cin, ostream &cout) {
		int count = 0;
		for(int i = 0; i < 6; i++) {
			double x;
			cin >> x;
			if(x > 0) {
				count++;
			}
		}
		cout << count << " positive numbers";
		return 0;
	}

	int acwing711::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		for(int i = 1; i <= 10; i++) {
			cout << i << " x " << n << " = " << i * n << endl;
		}
		return 0;
	}

	int acwing1904::main(istream &cin, ostream &cout) {
		unsigned int n;
		cin >> n;
		auto speeds = map<unsigned int, unsigned int>();
		for(unsigned int i = 0; i < n; i++) {
			unsigned int pos;
			unsigned int speed;
			cin >> pos >> speed;
			speeds.insert(pair(pos, speed));
		}
		unsigned int current_min = 1000000000;
		unsigned int count       = 0;
		for(auto i = speeds.rbegin(); i != speeds.rend(); ++i) {
			if((*i).second <= current_min) {
				current_min = (*i).second;
				count++;
			}
		}
		cout << count;
		return 0;
	}

	int acwing714::main(istream &cin, ostream &cout) {
		short x;
		short y;
		cin >> x >> y;
		if(y < x) {
			const auto temp = x;
			x               = y;
			y               = temp;
		}
		int count = 0;
		for(int i = x + 1; i < y; i++) {
			if(i % 2 != 0) {
				count += i;
			}
		}
		cout << count;
		return 0;
	}

	int acwing718::main(istream &cin, ostream &cout) {
		unsigned short n;
		cin >> n;
		unsigned int c_count = 0;
		unsigned int r_count = 0;
		unsigned int f_count = 0;
		for(unsigned short i = 0; i < n; i++) {
			unsigned short a;
			char t;
			cin >> a >> t;
			switch(t) {
				case 'C':
					c_count += a;
					break;
				case 'R':
					r_count += a;
					break;
				case 'F':
					f_count += a;
					break;
			}
		}
		const unsigned int count = c_count + r_count + f_count;
		cout << setiosflags(ios::fixed) << setprecision(2) << "Total: " << count << " animals" << endl
		     << "Total coneys: " << c_count << endl
		     << "Total rats: " << r_count << endl
		     << "Total frogs: " << f_count << endl
		     << "Percentage of coneys: " << static_cast<double>(c_count) / static_cast<double>(count) * 100
		     << " %" << endl
		     << "Percentage of rats: " << static_cast<double>(r_count) / static_cast<double>(count) * 100
		     << " %" << endl
		     << "Percentage of frogs: " << static_cast<double>(f_count) / static_cast<double>(count) * 100
		     << " %";
		return 0;
	}

	int acwing1884::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto *cow = new char[n];
		auto *c   = new int[n];//当前项左边有多少个C
		auto *w   = new int[n];//当前项右边有多少个W
		c[0]      = 0;
		w[n - 1]  = 0;
		for(int i = 0; i < n; i++) {
			cin >> cow[i];
			if(i >= 1) {
				c[i] = c[i - 1];
				if(cow[i - 1] == 'C') {
					c[i]++;
				}
			}
		}
		for(int i = n - 2; i >= 0; i--) {
			w[i] = w[i + 1];
			if(cow[i + 1] == 'W') {
				w[i]++;
			}
		}
		unsigned long count = 0;
		for(int i = 0; i < n; i++) {
			if(cow[i] == 'O') {
				count += c[i] * w[i];
			}
		}
		cout << count;
		delete[] w;
		delete[] c;
		delete[] cow;
		return 0;
	}

	int acwing4212::main(istream &cin, ostream &cout) {
		string a;
		string b;
		cin >> a >> b;
		auto ossa = ostringstream();
		auto ossb = ostringstream();
		for(char ch: a) {
			if(isupper(ch) != 0) {
				ch = tolower(ch);
			}
			ossa << ch;
		}
		for(char ch: b) {
			if(isupper(ch) != 0) {
				ch = tolower(ch);
			}
			ossb << ch;
		}
		a = ossa.str();
		b = ossb.str();
		if(a > b) {
			cout << 1;
		} else if(a < b) {
			cout << -1;
		} else {
			cout << 0;
		}
		return 0;
	}

	int acwing4213::main(istream &cin, ostream &cout) {
		unsigned int num[4];
		cin >> num[0] >> num[1] >> num[2] >> num[3];
		vector<char> ops;
		char op;
		for(int i = 0; i < 3; i++) {
			cin >> op;
			ops.push_back(op);
		}
		cout << get_min(ops, vector<unsigned long long>(begin(num), end(num)));
		return 0;
	}

	unsigned long long acwing4213::get_min(vector<char> ops, vector<unsigned long long> vec) {
		const char op = ops[0];
		if(vec.size() == 2) {
			if(op == '+') {
				return vec[0] + vec[1];
			}
			return vec[0] * vec[1];
		}
		const auto next_ops        = vector(ops.begin() + 1, ops.end());
		unsigned long long minimum = 1000000000000;
		for(int i = 0; i < vec.size() - 1; i++) {
			for(int j = i + 1; j < vec.size(); j++) {
				unsigned long long new_num;
				if(op == '+') {
					new_num = vec[i] + vec[j];
				} else {
					new_num = vec[i] * vec[j];
				}
				auto new_vec = vector<unsigned long long>();
				new_vec.push_back(new_num);
				for(int k = 0; k < vec.size(); k++) {
					if(k != i && k != j) {
						new_vec.push_back(vec[k]);
					}
				}
				const auto ret = get_min(next_ops, new_vec);
				if(minimum > ret) {
					minimum = ret;
				}
			}
		}
		return minimum;
	}

	int acwing4214::main(istream &cin, ostream &cout) {
		unsigned short n;
		cin >> n;
		auto *s = new unsigned int[n];
		auto *c = new unsigned int[n];
		for(unsigned short i = 0; i < n; i++) {
			cin >> s[i];
		}
		for(unsigned short i = 0; i < n; i++) {
			cin >> c[i];
		}
		unsigned int minimum = 300000001;
		for(int j = 1; j < n - 1; j++) {
			unsigned int min_left  = 100000001;
			unsigned int min_right = 100000001;
			for(int i = 0; i < j; i++) {
				if(s[i] < s[j]) {
					if(c[i] < min_left) {
						min_left = c[i];
					}
				}
			}
			for(int k = j + 1; k < n; k++) {
				if(s[j] < s[k]) {
					if(c[k] < min_right) {
						min_right = c[k];
					}
				}
			}
			if(min_left != 100000001 && min_right != 100000001 && minimum > min_left + c[j] + min_right) {
				minimum = min_left + c[j] + min_right;
			}
		}
		if(minimum != 300000001) {
			cout << minimum;
		} else {
			cout << -1;
		}
		return 0;
	}

	int acwing716::main(istream &cin, ostream &cout) {
		int maximum = 0;
		int max_i   = 0;
		for(int i = 1; i <= 100; i++) {
			int num;
			cin >> num;
			if(num > maximum) {
				maximum = num;
				max_i   = i;
			}
		}
		cout << maximum << endl
		     << max_i;
		return 0;
	}

	int acwing713::main(istream &cin, ostream &cout) {
		int n;
		unsigned int in  = 0;
		unsigned int out = 0;
		cin >> n;
		for(int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if(10 <= num && num <= 20) {
				in++;
			} else {
				out++;
			}
		}
		cout << in << " in" << endl
		     << out << " out";
		return 0;
	}

	int acwing721::main(istream &cin, ostream &cout) {
		unsigned short x;
		while(cin >> x) {
			if(x == 0) {
				return 0;
			}
			for(int i = 1; i <= x; i++) {
				cout << i << " ";
			}
			cout << endl;
		}
		return 0;
	}

	int acwing719::main(istream &cin, ostream &cout) {
		unsigned short n;
		cin >> n;
		for(unsigned short i = 0; i < n; i++) {
			int count = 0;
			int x;
			int y;
			cin >> x >> y;
			if(x > y) {
				const int temp = y;
				y              = x;
				x              = temp;
			}
			if(x % 2 == 0) {
				x++;
			} else {
				x += 2;
			}
			for(int j = x; j < y; j += 2) {
				count += j;
			}
			cout << count << endl;
		}
		return 0;
	}

	int acwing1875::main(istream &cin, ostream &cout) {
		auto b = vector<int>();
		auto e = vector<int>();
		auto s = vector<int>();
		auto i = vector<int>();
		auto g = vector<int>();
		auto o = vector<int>();
		auto m = vector<int>();
		unsigned short n;
		cin >> n;
		for(unsigned short j = 0; j < n; j++) {
			char ch;
			int val;
			cin >> ch >> val;
			switch(ch) {
				case 'B':
					b.push_back(val);
					break;
				case 'E':
					e.push_back(val);
					break;
				case 'S':
					s.push_back(val);
					break;
				case 'I':
					i.push_back(val);
					break;
				case 'G':
					g.push_back(val);
					break;
				case 'O':
					o.push_back(val);
					break;
				case 'M':
					m.push_back(val);
					break;
				default: return 1;
			}
		}
		unsigned int count_a = 0;
		for(const auto ms: m) {
			if(ms % 2 != 0) {
				count_a++;
			}
		}
		unsigned int count_b = 0;
		for(const auto bs: b) {
			for(const auto is: i) {
				if((bs + is) % 2 != 0) {
					count_b++;
				}
			}
		}
		unsigned int count_c = 0;
		for(const auto gs: g) {
			for(const auto os: o) {
				for(const auto es: e) {
					for(const auto ss: s) {
						if((gs + os + es + ss) % 2 != 0) {
							count_c++;
						}
					}
				}
			}
		}
		const unsigned long long count = b.size() * e.size() * s.size() * i.size() * g.size() * o.size() * m.size();
		cout << count - count_a * count_b * count_c;
		return 0;
	}

	int acwing720::main(istream &cin, ostream &cout) {
		int a;
		int count = 0;
		cin >> a;
		int n;
		do {
			cin >> n;
		} while(n <= 0);
		for(int i = 0; i < n; i++) {
			count += a + i;
		}
		cout << count;
		return 0;
	}

	int acwing717::main(istream &cin, ostream &cout) {
		unsigned short n;
		cin >> n;
		auto fibb = vector<unsigned int>();
		fibb.resize(n);
		fibb[0] = 0;
		fibb[1] = 1;
		for(unsigned short i = 2; i < n; i++) {
			fibb[i] = fibb[i - 1] + fibb[i - 2];
		}
		for(const auto num: fibb) {
			cout << num << " ";
		}
		return 0;
	}

	int acwing1855::main(istream &cin, ostream &cout) {
		unsigned short n;
		cin >> n;
		auto hay = vector<unsigned int>();
		for(unsigned short i = 0; i < n; i++) {
			unsigned int x;
			cin >> x;
			hay.push_back(x);
		}
		sort(hay.begin(), hay.end());
		unsigned int maximum = 0;
		for(auto start = hay.begin(); start != hay.end(); ++start) {
			bool left_end  = false;
			bool right_end = false;
			auto left      = start;
			auto right     = start;
			for(int i = 1;; i++) {
				if(!left_end) {
					auto l = lower_bound(hay.begin(), hay.end(), *left - i);
					if(l == hay.end() || l == left) {
						left_end = true;
					} else {
						left = l;
					}
				}
				if(!right_end) {
					auto r = upper_bound(hay.begin(), hay.end(), *right + i) - 1;
					if(r == hay.end() || r == right) {
						right_end = true;
					} else {
						right = r;
					}
				}
				if(left_end && right_end) {
					maximum = max(maximum, static_cast<unsigned int>(right - left) + 1);
					break;
				}
			}
		}
		cout << maximum;
		return 0;
	}

	int acwing724::main(istream &cin, ostream &cout) {
		unsigned short n;
		cin >> n;
		cout << 1 << endl;
		for(unsigned short i = 2; i < n; i++) {
			if(n % i == 0) {
				cout << i << endl;
			}
		}
		if(n != 1) {
			cout << n;
		}
		return 0;
	}

	int acwing722::main(istream &cin, ostream &cout) {
		int count = 0;
		int m;
		int n;
		cin >> m >> n;
		while(n > 0 && m > 0) {
			if(m > n) {
				swap(m, n);
			}
			for(int i = m; i <= n; i++) {
				cout << i << " ";
			}
			count += 2 * (m + n);
			cout << "Sum=" << (n - m + 1) * (m + n) / 2 << endl;
			cin >> m >> n;
		}
		return 0;
	}

	int acwing1843::main(istream &cin, ostream &cout) {
		unsigned short n;
		unsigned int min = 0;
		cin >> n;
		auto *r = new unsigned short[n];
		for(unsigned short i = 0; i < n; i++) {
			cin >> r[i];
		}
		for(unsigned short i = 0; i < n; i++) {
			unsigned int count = 0;
			for(unsigned short j = 0; j < n - 1; j++) {
				count += r[(i - j + n) % n] * (n - j - 1);
			}
			if(min == 0 || min > count) {
				min = count;
			}
		}
		cout << min;
		delete[] r;
		return 0;
	}

	int acwing723::main(istream &cin, ostream &cout) {
		unsigned short n;
		unsigned short m;
		cin >> n >> m;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(j != m - 1) {
					cout << i * m + j + 1 << " ";
				} else {
					cout << "PUM" << endl;
				}
			}
		}
		return 0;
	}

	int acwing725::main(istream &cin, ostream &cout) {
		unsigned short n;
		cin >> n;
		unsigned int x;
		for(unsigned short i = 0; i < n; i++) {
			cin >> x;
			unsigned int count = 1;
			const auto max     = static_cast<unsigned int>(sqrt(static_cast<double>(x)));
			for(unsigned int j = 2; j <= max; j++) {
				if(x % j == 0) {
					count += j;
					count += x / j;
					if(j == x / j) {
						count -= j;
					}
				}
			}
			cout << x;
			if(x == 1 || count != x) {
				cout << " is not perfect";
			} else {
				cout << " is perfect";
			}
			cout << endl;
		}
		return 0;
	}

	namespace acwing1826 {
		int acwing1826::main(istream &cin, ostream &cout) {
			unsigned int n;
			unsigned int x;
			unsigned int y;
			cin >> n;
			multiset<pair<unsigned int, unsigned int>, cmprow> row;
			multiset<pair<unsigned int, unsigned int>, cmpcol> col;
			for(unsigned int i = 0; i < n; i++) {
				cin >> x >> y;
				row.insert(pair(x, y));
				col.insert(pair(x, y));
			}
			unsigned int minimum = ((*row.rbegin()).first - (*row.begin()).first) * ((*col.rbegin()).second - (*col.begin()).second);

			auto row_cpy = multiset(row);
			auto col_cpy = multiset(col);
			auto r_pair  = *row_cpy.begin();
			row_cpy.erase(row_cpy.find(r_pair));
			col_cpy.erase(col_cpy.find(r_pair));
			minimum = min(minimum, ((*row_cpy.rbegin()).first - (*row_cpy.begin()).first) * ((*col_cpy.rbegin()).second - (*col_cpy.begin()).second));

			row_cpy = multiset(row);
			col_cpy = multiset(col);
			r_pair  = *row_cpy.rbegin();
			row_cpy.erase(row_cpy.find(r_pair));
			col_cpy.erase(col_cpy.find(r_pair));
			minimum = min(minimum, ((*row_cpy.rbegin()).first - (*row_cpy.begin()).first) * ((*col_cpy.rbegin()).second - (*col_cpy.begin()).second));

			row_cpy     = multiset(row);
			col_cpy     = multiset(col);
			auto c_pair = *col_cpy.begin();
			row_cpy.erase(row_cpy.find(c_pair));
			col_cpy.erase(col_cpy.find(c_pair));
			minimum = min(minimum, ((*row_cpy.rbegin()).first - (*row_cpy.begin()).first) * ((*col_cpy.rbegin()).second - (*col_cpy.begin()).second));

			row_cpy = multiset(row);
			col_cpy = multiset(col);
			c_pair  = *col_cpy.rbegin();
			row_cpy.erase(row_cpy.find(c_pair));
			col_cpy.erase(col_cpy.find(c_pair));
			minimum = min(minimum, ((*row_cpy.rbegin()).first - (*row_cpy.begin()).first) * ((*col_cpy.rbegin()).second - (*col_cpy.begin()).second));

			cout << minimum;
			return 0;
		}

		bool cmprow::operator()(const pair<unsigned int, unsigned int> &left, const pair<unsigned int, unsigned int> &right) const { return left.first < right.first; }

		bool cmpcol::operator()(const pair<unsigned int, unsigned int> &left, const pair<unsigned int, unsigned int> &right) const { return left.second < right.second; }
	}// namespace acwing1826

	int acwing1813::main(istream &cin, ostream &cout) {
		int n;
		int charmap[26] = {};
		cin >> n;
		for(int i = 0; i < n; i++) {
			int charmap_a[26] = {};
			int charmap_b[26] = {};
			string a;
			string b;
			cin >> a >> b;
			for(const char ch: a) {
				charmap_a[ch - 'a']++;
			}
			for(const char ch: b) {
				charmap_b[ch - 'a']++;
			}
			for(int j = 0; j < 26; j++) {
				charmap[j] += max(charmap_a[j], charmap_b[j]);
			}
		}
		for(const int i: charmap) {
			cout << i << endl;
		}
		return 0;
	}

	int acwing726::main(istream &cin, ostream &cout) {
		int n;
		int x;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> x;
			for(int j = 2; j <= sqrt(x); j++) {
				if(x % j == 0) {
					cout << x << " is not prime" << endl;
					goto next;
				}
			}
			cout << x << " is prime" << endl;
		next:;
		}
		return 0;
	}

	int acwing727::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		for(int i = 0; i <= n / 2; i++) {
			for(int j = 0; j < n / 2 - i; j++) {
				cout << ' ';
			}
			for(int k = 0; k < 1 + 2 * i; k++) {
				cout << '*';
			}
			cout << endl;
		}
		for(int i = n / 2 + 1; i < n; i++) {
			for(int j = 0; j < i - n / 2; j++) {
				cout << ' ';
			}
			for(int k = 0; k < 1 + 2 * (n - i - 1); k++) {
				cout << '*';
			}
			cout << endl;
		}
		return 0;
	}

	int acwing737::main(istream &cin, ostream &cout) {
		short x;
		for(int i = 0; i < 10; i++) {
			cin >> x;
			if(x <= 0) {
				x = 1;
			}
			cout << "X[" << i << "] = " << x << endl;
		}
		return 0;
	}

	int acwing740::main(istream &cin, ostream &cout) {
		short n[20];
		for(int i = 0; i < 20; i++) {
			cin >> n[20 - i - 1];
		}
		for(int i = 0; i < 20; i++) {
			cout << "N[" << i << "] = " << n[i] << endl;
		}
		return 0;
	}

	int acwing1801::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		int count_123 = 0;///< 1剪刀 2石头 3布
		int count_132 = 0;///< 1剪刀 2布   3石头
		int count_213 = 0;///< 1石头 2剪刀 3布
		int count_231 = 0;///< 1布   2剪刀 3石头
		int count_312 = 0;///< 1石头 2布   3剪刀
		int count_321 = 0;///< 1布   2石头 3剪刀
		for(int i = 0; i < n; i++) {
			int a;
			int b;
			cin >> a >> b;
			if(a == 1 && b == 2) {
				count_132++;
				count_213++;
				count_321++;
			} else if(a == 1 && b == 3) {
				count_123++;
				count_231++;
				count_312++;
			} else if(a == 2 && b == 1) {
				count_123++;
				count_231++;
				count_312++;
			} else if(a == 2 && b == 3) {
				count_132++;
				count_213++;
				count_321++;
			} else if(a == 3 && b == 1) {
				count_132++;
				count_213++;
				count_321++;
			} else if(a == 3 && b == 2) {
				count_123++;
				count_231++;
				count_312++;
			}
		}
		int maximum = count_123;
		maximum     = max(maximum, count_132);
		maximum     = max(maximum, count_213);
		maximum     = max(maximum, count_231);
		maximum     = max(maximum, count_312);
		maximum     = max(maximum, count_321);
		cout << maximum;
		return 0;
	}

	int acwing4215::main(istream &cin, ostream &cout) {
		char ch;
		while(cin >> ch) {
			if(isupper(ch) != 0) {
				ch = tolower(ch);
			}
			if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
				continue;
			}
			cout << '.' << ch;
		}
		return 0;
	}

	int acwing4216::main(istream &cin, ostream &cout) {
		unsigned short n;
		unsigned short m;
		unsigned short a;
		unsigned short b;
		cin >> n >> m;
		auto flag = vector(n, false);
		auto edge = vector(n, unordered_set<unsigned short>());
		for(unsigned short i = 0; i < m; i++) {
			cin >> a >> b;
			edge[a - 1].insert(b - 1);
			edge[b - 1].insert(a - 1);
		}
		int circle = 0;
		auto que   = queue<pair<unsigned short, unsigned short>>();
		que.push(pair(0, 0));
		flag[0] = true;
		while(!que.empty()) {
			auto [prev, current] = que.front();
			que.pop();
			for(auto next: edge[current]) {
				if(next != prev) {
					if(flag[next]) {
						if(circle == 2) {
							cout << "NO";
							return 0;
						}
						circle += 1;
					} else {
						que.push(pair(current, next));
						flag[next] = true;
					}
				}
			}
		}
		for(unsigned short i = 0; i < n; i++) {
			if(!flag[i]) {
				cout << "NO";
				return 0;
			}
		}
		if(circle != 2) {
			cout << "NO";
			return 0;
		}
		cout << "YES";
		return 0;
	}

	int acwing4217::main(istream &cin, ostream &cout) {
		cin >> n;
		ops   = vector<char>();
		forth = vector<pair<int, int>>();
		back  = vector<pair<int, int>>();
		ops.resize(n);
		forth.emplace_back(0, 0);
		for(int i = 0; i < n; i++) {
			cin >> ops[i];
			switch(ops[i]) {
				case 'U': {
					forth.emplace_back(forth.back().first, forth.back().second + 1);
					break;
				}
				case 'D': {
					forth.emplace_back(forth.back().first, forth.back().second - 1);
					break;
				}
				case 'L': {
					forth.emplace_back(forth.back().first - 1, forth.back().second);
					break;
				}
				case 'R': {
					forth.emplace_back(forth.back().first + 1, forth.back().second);
					break;
				}
			}
		}
		cin >> a >> b;
		if(forth.back().first == a && forth.back().second == b) {
			cout << 0;
			return 0;
		}
		if(n < abs(a) + abs(b) || (n - (abs(a) + abs(b))) % 2 != 0) {
			cout << -1;
			return 0;
		}
		back.emplace_back(a, b);
		for(int i = n - 1; i >= 0; i--) {
			switch(ops[i]) {
				case 'U': {
					back.emplace_back(back.back().first, back.back().second - 1);
					break;
				}
				case 'D': {
					back.emplace_back(back.back().first, back.back().second + 1);
					break;
				}
				case 'L': {
					back.emplace_back(back.back().first + 1, back.back().second);
					break;
				}
				case 'R': {
					back.emplace_back(back.back().first - 1, back.back().second);
					break;
				}
			}
		}
		back  = vector(back.rbegin(), back.rend());
		int l = 1;
		int r = n;
		while(l < r) {
			const int mid = (l + r) / 2;
			if(check(mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		cout << l;
		return 0;
	}

	bool acwing4217::check(int len) const {
		for(int i = 0; i + len < n + 1; i++) {
			const auto s    = forth[i];
			const auto e    = back[i + len];
			const auto dist = abs(s.first - e.first) + abs(s.second - e.second);
			if(len - dist >= 0 && (len - dist) % 2 == 0) {
				return true;
			}
		}
		return false;
	}

	int acwing738::main(istream &cin, ostream &cout) {
		unsigned int v;
		cin >> v;
		for(int i = 0; i < 10; i++) {
			cout << "N[" << i << "] = " << v * static_cast<unsigned int>(pow(2, i)) << endl;
		}
		return 0;
	}

	int acwing741::main(istream &cin, ostream &cout) {
		unsigned int t;
		unsigned short n;
		cin >> t;
		unsigned int fib[60];
		fib[0] = 0;
		fib[1] = 1;
		for(int i = 2; i < 60; i++) {
			fib[i] = fib[i - 1] + fib[i - 2];
		}
		for(unsigned i = 0; i < t; i++) {
			cin >> n;
			cout << "Fib(" << n << ") = " << fib[n] << endl;
		}
		return 0;
	}

	int acwing1789::main(istream &cin, ostream &cout) {
		char str[52];
		int count  = 0;
		auto poses = vector(26, vector<int>());
		for(int i = 0; i < 52; i++) {
			char ch;
			cin >> ch;
			str[i] = ch;
			poses[ch - 'A'].push_back(i);
		}
		for(auto pos: poses) {
			auto um = unordered_map<int, int>();
			for(int i = pos[0] + 1; i < pos[1]; i++) {
				if(!um.contains(str[i])) {
					um.insert(pair(str[i], 1));
				} else {
					um[str[i]] = 0;
				}
			}
			for(const auto p: um) {
				if(p.second == 1) {
					count++;
				}
			}
			um = unordered_map<int, int>();
			for(int i = pos[1] + 1; i < pos[0] + 52; i++) {
				if(!um.contains(str[i % 52])) {
					um.insert(pair(str[i % 52], 1));
				} else {
					um[str[i % 52]] = 0;
				}
			}
			for(const auto p: um) {
				if(p.second == 1) {
					count++;
				}
			}
		}
		cout << count / 4;
		return 0;
	}

	int acwing739::main(istream &cin, ostream &cout) {
		double a;
		cout << setiosflags(ios::fixed) << setprecision(1);
		for(int i = 0; i < 100; i++) {
			cin >> a;
			if(a <= 10) {
				cout << "A[" << i << "] = " << a << endl;
			}
		}
		return 0;
	}

	int acwing742::main(istream &cin, ostream &cout) {
		unsigned short n;
		cin >> n;
		unsigned short minimum_i = 0;
		short minimum            = 1000;
		short x;
		for(unsigned short i = 0; i < n; i++) {
			cin >> x;
			if(minimum > x) {
				minimum   = x;
				minimum_i = i;
			}
		}
		cout << "Minimum value: " << minimum << endl
		     << "Position: " << minimum_i;
		return 0;
	}

	int acwing1776::main(istream &cin, ostream &cout) {
		int n;
		int m;
		cin >> n >> m;
		char ch;
		auto *dot = new int[m];
		memset(dot, 0, m * sizeof(int));
		auto *normal = new int[m];
		memset(normal, 0, m * sizeof(int));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> ch;
				dot[j] |= 1 << ch - 'A';
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> ch;
				normal[j] |= 1 << ch - 'A';
			}
		}
		int count = 0;
		for(int i = 0; i < m; i++) {
			if((dot[i] & normal[i]) == 0) {
				count++;
			}
		}
		cout << count;
		delete[] normal;
		delete[] dot;
		return 0;
	}

	int acwing743::main(istream &cin, ostream &cout) {
		int l;
		char op;
		double m[12][12];
		cin >> l >> op;
		for(auto &i: m) {
			for(auto &j: i) {
				cin >> j;
			}
		}
		double ans = 0;
		for(int j = 0; j < 12; j++) {
			ans += m[l][j];
		}
		if(op == 'M') {
			ans /= 12;
		}
		cout << fixed << setprecision(1) << ans;
		return 0;
	}

	int acwing744::main(istream &cin, ostream &cout) {
		int l;
		char op;
		double m[12][12];
		cin >> l >> op;
		for(auto &i: m) {
			for(auto &j: i) {
				cin >> j;
			}
		}
		double ans = 0;
		for(const auto &j: m) {
			ans += j[l];
		}
		if(op == 'M') {
			ans /= 12;
		}
		cout << fixed << setprecision(1) << ans;
		return 0;
	}

	int acwing745::main(istream &cin, ostream &cout) {
		char op;
		cin >> op;
		double sum = 0;
		int count  = 0;
		double m[12][12];
		for(int i = 0; i < 12; i++) {
			for(int j = 0; j < 12; j++) {
				cin >> m[i][j];
				if(j > i) {
					sum += m[i][j];
					count++;
				}
			}
		}
		if(op == 'M') {
			sum /= count;
		}
		cout << fixed << setprecision(1) << sum;
		return 0;
	}

	int acwing748::main(istream &cin, ostream &cout) {
		char op;
		cin >> op;
		double sum = 0;
		int count  = 0;
		double m[12][12];
		for(int i = 0; i < 12; i++) {
			for(int j = 0; j < 12; j++) {
				cin >> m[i][j];
				if(i + j >= 12) {
					sum += m[i][j];
					count++;
				}
			}
		}
		if(op == 'M') {
			sum /= count;
		}
		cout << fixed << setprecision(1) << sum;
		return 0;
	}

	int acwing1762::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto *a  = new int[n + 1];
		auto *id = new string[n + 1];
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++) {
			cin >> id[i];
		}
		for(int i = 1; i <= n; i++) {
			cout << id[a[a[a[i]]]] << endl;
		}
		delete[] a;
		delete[] id;
		return 0;
	}

	int acwing1750::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto start  = unordered_set<int>();
		auto end    = unordered_set<int>();
		auto t      = vector<pair<int, int>>();
		auto levels = vector<int>();
		levels.resize(1000);
		for(int i = 0; i < n; i++) {
			int t1;
			int t2;
			cin >> t1 >> t2;
			start.insert(t1);
			end.insert(t2);
			t.emplace_back(make_pair(t1, t2));
		}
		int level   = 0;
		int maximum = 0;
		for(int i = 0; i < 1000; i++) {
			if(start.count(i) == 1) {
				level++;
			}
			if(end.count(i) == 1) {
				level--;
			}
			levels[i] = level;
			if(level > 0) {
				maximum++;
			}
		}
		int ans = 0;
		for(auto [t1, t2]: t) {
			int len = maximum;
			for(int i = t1; i < t2; i++) {
				if(levels[i] == 1) {
					len--;
				}
			}
			ans = max(ans, len);
		}
		cout << ans;
		return 0;
	}

	int acwing747::main(istream &cin, ostream &cout) {
		char op;
		cin >> op;
		double sum = 0;
		int count  = 0;
		double m[12][12];
		for(int i = 0; i < 12; i++) {
			for(int j = 0; j < 12; j++) {
				cin >> m[i][j];
				if(i + j < 11) {
					sum += m[i][j];
					count++;
				}
			}
		}
		if(op == 'M') {
			sum /= count;
		}
		cout << fixed << setprecision(1) << sum;
		return 0;
	}

	int acwing746::main(istream &cin, ostream &cout) {
		char op;
		cin >> op;
		double sum = 0;
		int count  = 0;
		double m[12][12];
		for(int i = 0; i < 12; i++) {
			for(int j = 0; j < 12; j++) {
				cin >> m[i][j];
				if(j < i) {
					sum += m[i][j];
					count++;
				}
			}
		}
		if(op == 'M') {
			sum /= count;
		}
		cout << fixed << setprecision(1) << sum;
		return 0;
	}

	int acwing1738::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		if(n == 1 || n == 2) {
			cout << 1;
			return 0;
		}
		auto *x   = new int[n];
		auto *jmp = new int[n];
		auto *in  = new int[n];
		memset(in, 0, n * sizeof(int));
		for(int i = 0; i < n; i++) {
			cin >> x[i];
		}
		sort(x, x + n);
		in[1]      = 1;
		in[n - 2]  = 1;
		jmp[0]     = 1;
		jmp[n - 1] = n - 2;
		for(int i = 1; i < n - 1; i++) {
			if(x[i + 1] - x[i] < x[i] - x[i - 1]) {
				in[i + 1]++;
				jmp[i] = i + 1;
			} else {
				in[i - 1]++;
				jmp[i] = i - 1;
			}
		}
		int circle_count = 0;
		int ans          = 0;
		for(int i = 0; i < n; i++) {
			if(in[i] == 0) {
				ans++;
			}
			if(jmp[jmp[i]] == i && in[i] == 1 && in[jmp[i]] == 1) {
				circle_count++;
			}
		}
		circle_count /= 2;
		cout << ans + circle_count;
		delete[] x;
		delete[] in;
		delete[] jmp;
		return 0;
	}

	int acwing4296::main(istream &cin, ostream &cout) {
		int n;
		int a;
		int b;
		cin >> n >> a >> b;
		for(int i = 0; a * i <= n; i++) {
			for(int j = 0; a * i + b * j <= n; j++) {
				if(a * i + b * j == n) {
					cout << "YES" << endl
					     << i << endl
					     << j;
					return 0;
				}
			}
		}
		cout << "NO";
		return 0;
	}

	int acwing4297::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		unsigned int d[200000];
		unsigned long long left[200001];
		unsigned long long right[200001];
		for(int i = 0; i < n; i++) {
			cin >> d[i];
		}
		left[0] = 0;
		auto us = unordered_map<unsigned long long, unsigned int>();
		us.insert(make_pair(0, 0));
		for(int i = 1; i <= n; i++) {
			left[i] = left[i - 1] + d[i - 1];
			us.insert(make_pair(left[i], i));
		}
		right[n]               = 0;
		unsigned long long ans = 0;
		for(int i = n - 1; i >= 0; i--) {
			right[i] = right[i + 1] + d[i];
			if(us.count(right[i]) == 1) {
				if(us[right[i]] <= i) {
					ans = max(ans, right[i]);
				}
			}
		}
		cout << ans;
		return 0;
	}

	int acwing4298::main(istream &cin, ostream &cout) {
		cin >> n;
		a = new int[n];
		memset(a, 0, n * sizeof(int));
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cin >> m;
		b     = new int[m];
		found = new bool[m];
		match = new int[m];
		memset(b, 0, m * sizeof(int));
		memset(found, 0, m * sizeof(bool));
		memset(match, -1, m * sizeof(int));
		for(int i = 0; i < m; i++) {
			cin >> b[i];
		}
		connected = new bool *[n];
		for(int i = 0; i < n; i++) {
			connected[i] = new bool[m];
			for(int j = 0; j < m; j++) {
				if(abs(a[i] - b[j]) <= 1) {
					connected[i][j] = true;
				} else {
					connected[i][j] = false;
				}
			}
		}

		int ans = 0;
		for(int i = 0; i < n; i++) {
			memset(found, 0, m * sizeof(bool));
			if(find(i)) {
				ans++;
			}
		}
		cout << ans;
		for(int i = 0; i < n; i++) {
			delete[] connected[i];
		}
		delete[] connected;
		delete[] a;
		delete[] b;
		delete[] found;
		delete[] match;
		return 0;
	}

	bool acwing4298::find(int i) {
		for(int j = 0; j < m; j++) {
			if(connected[i][j] && !found[j]) {
				//可以配对且女孩未被找到
				found[j] = true;
				if(match[j] == -1 || find(match[j])) {
					//女孩没有配对的对象或女孩配对的对象可以找到其他对象去配对
					match[j] = i;//设置女孩j和男孩i配对
					return true;
				}
			}
		}
		return false;
	}

	int acwing749::main(istream &cin, ostream &cout) {
		char op;
		cin >> op;
		double sum = 0;
		int count  = 0;
		double m[12][12];
		for(int i = 0; i < 12; i++) {
			for(int j = 0; j < 12; j++) {
				cin >> m[i][j];
				if(j > i && i + j < 11) {
					sum += m[i][j];
					count++;
				}
			}
		}
		if(op == 'M') {
			sum /= count;
		}
		cout << fixed << setprecision(1) << sum;
		return 0;
	}

	int acwing750::main(istream &cin, ostream &cout) {
		char op;
		cin >> op;
		double sum = 0;
		int count  = 0;
		double m[12][12];
		for(int i = 0; i < 12; i++) {
			for(int j = 0; j < 12; j++) {
				cin >> m[i][j];
				if(i + j > 11 && i > j) {
					sum += m[i][j];
					count++;
				}
			}
		}
		if(op == 'M') {
			sum /= count;
		}
		cout << fixed << setprecision(1) << sum;
		return 0;
	}

	int acwing751::main(istream &cin, ostream &cout) {
		char op;
		cin >> op;
		double sum = 0;
		int count  = 0;
		double m[12][12];
		for(int i = 0; i < 12; i++) {
			for(int j = 0; j < 12; j++) {
				cin >> m[i][j];
				if(i + j < 11 && i > j) {
					sum += m[i][j];
					count++;
				}
			}
		}
		if(op == 'M') {
			sum /= count;
		}
		cout << fixed << setprecision(1) << sum;
		return 0;
	}

	int acwing752::main(istream &cin, ostream &cout) {
		char op;
		cin >> op;
		double sum = 0;
		int count  = 0;
		double m[12][12];
		for(int i = 0; i < 12; i++) {
			for(int j = 0; j < 12; j++) {
				cin >> m[i][j];
				if(i + j > 11 && i < j) {
					sum += m[i][j];
					count++;
				}
			}
		}
		if(op == 'M') {
			sum /= count;
		}
		cout << fixed << setprecision(1) << sum;
		return 0;
	}

	int acwing1726::main(istream &cin, ostream &cout) {
		int N;
		int M;
		int K;
		cin >> N >> M >> K;
		unordered_set<int> ms;
		auto *const m = new int[M];
		auto *const n = new int[N + 1];
		memset(n, -1, (N + 1) * sizeof(int));
		for(int i = 0; i < M; i++) {
			cin >> m[i];
			ms.insert(m[i]);
		}
		auto cp = unordered_map<int, int>();
		for(int i = 0; i < K; i++) {
			int c;
			int p;
			cin >> c >> p;
			n[p] = c;
			cp.insert(make_pair(c, p));
		}
		if(cp.contains(1)) {
			//固定
			cout << cp[1];
			delete[] n;
			delete[] m;
			return 0;
		}
		if(ms.contains(1)) {
			//在阶级中
			int current = 1;
			for(int i = 0; i < M; i++) {
				//对所有阶级
				if(cp.contains(m[i])) {
					//是固定的
					current = cp[m[i]];
					continue;
				}
				//不是固定的
				while(n[current] != -1) {
					current++;
				}
				n[current] = m[i];
				if(m[i] == 1) {
					cout << current;
					delete[] n;
					delete[] m;
					return 0;
				}
			}
		}
		//不在阶级中
		int current = N;
		for(int i = M - 1; i >= 0; i--) {
			if(cp.contains(m[i])) {
				//是固定的
				current = cp[m[i]];
				continue;
			}
			//不是固定的
			while(n[current] != -1) {
				current--;
			}
			n[current] = m[i];
		}
		for(int i = 1; i <= N; i++) {
			if(n[i] == -1) {
				cout << i;
				break;
			}
		}
		delete[] n;
		delete[] m;
		return 0;
	}

	int acwing753::main(istream &cin, ostream &cout) {
		int n;
		while(true) {
			cin >> n;
			if(n == 0) {
				break;
			}
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					cout << min(min(i, j), min(n - i - 1, n - j - 1)) + 1 << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		return 0;
	}

	int acwing754::main(istream &cin, ostream &cout) {
		int n;
		while(true) {
			cin >> n;
			if(n == 0) {
				break;
			}
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					cout << abs(j - i) + 1 << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		return 0;
	}

	int acwing1715::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto sb = unordered_map<int, int>();
		auto tb = unordered_map<int, int>();
		for(int i = 0; i < n; i++) {
			int s;
			int t;
			int b;
			cin >> s >> t >> b;
			sb.insert(make_pair(s, b));
			tb.insert(make_pair(t, b));
		}
		int ans     = 0;
		int current = 0;
		for(int i = 1; i <= 1000; i++) {
			if(sb.count(i) == 1) {
				current += sb[i];
			} else if(tb.count(i) == 1) {
				current -= tb[i];
			}
			ans = max(ans, current);
		}
		cout << ans;
		return 0;
	}

	int acwing755::main(istream &cin, ostream &cout) {
		int n;
		while(true) {
			cin >> n;
			if(n == 0) {
				break;
			}
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					cout << static_cast<int>(pow(2, i + j)) << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		return 0;
	}

	int acwing756::main(istream &cin, ostream &cout) {
		int n;
		int m;
		int arr[100][100] = {};
		int x             = 0;
		int y             = 0;
		int v             = 1;
		int dir           = 1;//0 上 1 右 2 下 3 左
		cin >> n >> m;
		while(v <= n * m) {
			arr[x][y] = v++;
		move:;
			if(v > m * n) {
				break;
			}
			switch(dir) {
				case 3://左
				{
					const int next_y = y - 1;
					if(arr[x][next_y] != 0 || next_y < 0) {
						//不能向上
						dir = (dir + 1) % 4;
						goto move;
					}
					y--;
					break;
				}
				case 2://下
				{
					const int next_x = x + 1;
					if(arr[next_x][y] != 0 || next_x >= n) {
						dir = (dir + 1) % 4;
						goto move;
					}
					x++;
					break;
				}
				case 1://右
				{
					const int next_y = y + 1;
					if(arr[x][next_y] != 0 || next_y >= m) {
						dir = (dir + 1) % 4;
						goto move;
					}
					y++;
					break;
				}
				case 0://上
				{
					const int next_x = x - 1;
					if(arr[next_x][y] != 0 || next_x < 0) {
						dir = (dir + 1) % 4;
						goto move;
					}
					x--;
					break;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}

	int acwing1696::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto *const p = new int[n];
		for(int i = 0; i < n; i++) {
			cin >> p[i];
		}
		int i = n - 1;
		for(int j = i - 1; j >= 0 && p[j] < p[i]; i--, j--) {}
		cout << i;
		delete[] p;
		return 0;
	}

	int acwing760::main(istream &cin, ostream &cout) {
		auto *str = new char[101];
		cin.getline(str, 101);
		for(int i = 0; i < 101; i++) {
			if(str[i] == '\0') {
				cout << i;
				break;
			}
		}
		return 0;
	}

	int acwing762::main(istream &cin, ostream &cout) {
		double k;
		string a;
		string b;
		int match = 0;
		cin >> k >> a >> b;
		for(int i = 0; i < a.length(); i++) {
			if(a[i] == b[i]) {
				match++;
			}
		}
		cout << (match >= k * a.length() ? "yes" : "no");
		return 0;
	}

	int acwing1684::main(istream &cin, ostream &cout) {
		int n;
		int m;
		cin >> n >> m;
		bitset<151> ns[101] = {};
		bitset<151> ans[4]  = {};
		for(int i = 1; i <= m; i++) {
			int m1;
			int m2;
			cin >> m1 >> m2;
			ns[m1].set(i);
			ns[m2].set(i);
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < 4; j++) {
				if((ns[i] & ans[j]) == 0) {
					cout << j + 1;
					ans[j] |= ns[i];
					break;
				}
			}
		}
		return 0;
	}

	int acwing761::main(istream &cin, ostream &cout) {
		auto *str = new char[101];
		cin.getline(str, 101);
		unsigned short ans = 0;
		for(unsigned short i = 0; str[i] != '\0'; i++) {
			if(isdigit(str[i]) != 0) {
				ans++;
			}
		}
		cout << ans;
		delete[] str;
		return 0;
	}

	int acwing768::main(istream &cin, ostream &cout) {
		auto *a = new char[81];
		auto *b = new char[81];
		cin.getline(a, 81);
		cin.getline(b, 81);
		for(int i = 0;; i++) {
			if(isupper(a[i]) != 0) {
				a[i] = tolower(a[i]);
			}
			if(isupper(b[i]) != 0) {
				b[i] = tolower(b[i]);
			}
			if(a[i] == '\0' && b[i] == '\0') {
				cout << '=';
				break;
			}
			if(a[i] < b[i]) {
				cout << '<';
				break;
			}
			if(a[i] > b[i]) {
				cout << '>';
				break;
			}
		}
		delete[] a;
		delete[] b;
		return 0;
	}

	int acwing1471::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto *in  = new int[n];
		auto *out = new int[n];
		memset(in, 0, n * sizeof(int));
		memset(out, 0, n * sizeof(int));
		int a;
		int b;
		for(int i = 0; i < n - 1; i++) {
			cin >> a >> b;
			out[a - 1]++;
			in[b - 1]++;
		}
		bool ok = true;
		int ans = -1;
		for(int i = 0; i < n; i++) {
			if(in[i] > 0 && out[i] == 0) {
				if(ans != -1) {
					ok = false;
					break;
				}
				ans = i;
			}
			if(in[i] == 0 && out[i] > 1) {
				ok = false;
				break;
			}
		}
		if(ok) {
			cout << ans + 1;
		} else {
			cout << -1;
		}
		delete[] in;
		delete[] out;
		return 0;
	}

	int acwing763::main(istream &cin, ostream &cout) {
		int t;
		cin >> t;
		for(int i = 0; i < t; i++) {
			string str1;
			string str2;
			cin >> str1 >> str2;
			if(str1 == str2) {
				cout << "Tie";
			} else if(str1 == "Hunter" && str2 == "Gun" || str1 == "Gun" && str2 == "Bear" || str1 == "Bear" && str2 == "Hunter") {
				cout << "Player1";
			} else {
				cout << "Player2";
			}
			cout << endl;
		}
		return 0;
	}

	int acwing766::main(istream &cin, ostream &cout) {
		auto *str = new char[201];
		cin.getline(str, 201);
		bool flag = false;
		for(int i = 0; str[i] != '\0'; i++) {
			if(str[i] != ' ') {
				cout << str[i];
				flag = false;
			} else if(!flag) {
				cout << ' ';
				flag = true;
			}
		}
		return 0;
	}

	int acwing1460::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		for(int k = 1; k <= n; k++) {
			auto us = unordered_set<string>();
			bool ok = true;
			for(int i = 0; i + k <= n; i++) {
				string nstr = str.substr(i, k);
				if(!us.contains(nstr)) {
					us.insert(nstr);
				} else {
					ok = false;
					break;
				}
			}
			if(ok) {
				cout << k;
				break;
			}
		}
		return 0;
	}

	int acwing4299::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		int pos = 0;
		int neg = 0;
		for(int i = 0; i < n; i++) {
			int x;
			int y;
			cin >> x >> y;
			if(x > 0) {
				pos++;
			} else {
				neg++;
			}
		}
		if(pos <= 1 || neg <= 1) {
			cout << "Yes";
		} else {
			cout << "No";
		}
		return 0;
	}

	int acwing4300::main(istream &cin, ostream &cout) {
		int n;
		int m;
		cin >> n >> m;
		auto um  = unordered_set<int>();
		auto que = queue<pair<int, int>>();
		que.push(make_pair(n, 0));
		um.insert(n);
		while(!que.empty()) {
			auto [current, step] = que.front();
			que.pop();
			if(current == m) {
				cout << step;
				return 0;
			}
			int k              = 1;
			const int nexts[2] = {current - 1, current * 2};
			if(current < m) {
				k = 2;
			}
			for(int i = 0; i < k; i++) {
				auto next = nexts[i];
				if(next == m) {
					cout << step + 1;
					return 0;
				}
				if(next > 0 && !um.contains(next)) {
					que.push(make_pair(next, step + 1));
					um.insert(next);
				}
			}
		}
		return 0;
	}

	int acwing4301::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto vec     = vector<int>();
		auto targets = unordered_set<int>();
		int sum      = 0;
		int maximum  = 0;
		char ch;
		vec.resize(n);
		for(int i = 0; i < n; i++) {
			cin >> ch;
			int a  = ch - '0';
			vec[i] = a;
			sum += a;
			maximum = max(maximum, a);
		}
		if(sum == 0) {
			cout << "YES";
			return 0;
		}
		for(int i = maximum; i <= sum / 2; i++) {
			if(sum % i == 0) {
				targets.insert(i);
			}
		}
		for(const auto target: targets) {
			int current = 0;
			bool ok     = true;
			for(int i = 0; i < n; i++) {
				current += vec[i];
				if(current == target) {
					current = 0;
				} else if(current > target) {
					ok = false;
					break;
				}
			}
			if(ok && current == 0) {
				cout << "YES";
				return 0;
			}
		}
		cout << "NO";
		return 0;
	}

	int acwing765::main(istream &cin, ostream &cout) {
		auto *str = new char[101];
		cin.getline(str, 101);
		for(int i = 0; str[i] != '\0'; i++) {
			cout << str[i] << " ";
		}
		delete[] str;
		return 0;
	}

	int acwing767::main(istream &cin, ostream &cout) {
		auto *str = new char[101];
		cin.getline(str, 101);
		for(int i = 0; str[i] != '\0'; i++) {
			if(isupper(str[i]) != 0) {
				str[i] = (str[i] - 'A' + 1) % 26 + 'A';
			} else if(islower(str[i]) != 0) {
				str[i] = (str[i] - 'a' + 1) % 26 + 'a';
			}
			cout << str[i];
		}
		delete[] str;
		return 0;
	}

	int acwing769::main(istream &cin, ostream &cout) {
		string str;
		cin >> str;
		char ch;
		cin >> ch;
		for(char c: str) {
			if(c == ch) {
				c = '#';
			}
			cout << c;
		}
		return 0;
	}

	int acwing764::main(istream &cin, ostream &cout) {
		auto *a = new char[101];
		cin.getline(a, 101);
		const int len = strlen(a);
		for(int i = 1; i <= len; i++) {
			cout << static_cast<char>(a[(i - 1) % len] + a[i % len]);
		}
		delete[] a;
		return 0;
	}

	int acwing1443::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto *a = new int[n];
		auto *b = new int[n - 1];
		for(int i = 0; i < n - 1; i++) {
			cin >> b[i];
		}
		for(int i = 1; i <= n; i++) {
			auto us   = unordered_set<int>();
			bool flag = true;
			a[0]      = i;
			for(int j = 1; j < n; j++) {
				a[j] = b[j - 1] - a[j - 1];
				if(us.contains(a[j]) || a[j] <= 0) {
					flag = false;
					break;
				}
				us.insert(a[j]);

				us.insert(a[j]);
			}
			if(flag) {
				for(int j = 0; j < n; j++) {
					cout << a[j] << " ";
				}
				break;
			}
		}
		delete[] b;
		delete[] a;
		return 0;
	}

	int acwing773::main(istream &cin, ostream &cout) {
		string str;
		string substr;
		while(cin >> str) {
			cin >> substr;
			auto oss  = ostringstream();
			int max_i = 0;
			for(int i = 0; i < str.length(); i++) {
				if(str[i] > str[max_i]) {
					max_i = i;
				}
			}
			oss << str.substr(0, max_i + 1);
			oss << substr;
			oss << str.substr(max_i + 1);
			cout << oss.str() << endl;
		}
		return 0;
	}

	int acwing770::main(istream &cin, ostream &cout) {
		auto *str            = new char[101];
		auto *to_be_replaced = new char[101];
		auto *replacement    = new char[101];
		cin.getline(str, 101);
		cin.getline(to_be_replaced, 101);
		cin.getline(replacement, 101);
		for(const char *word = strtok(str, " "); word != nullptr; word = strtok(nullptr, " ")) {
			if(strcmp(word, to_be_replaced) == 0) {
				cout.write(replacement, strlen(replacement));
			} else {
				cout.write(word, strlen(word));
			}
			cout << " ";
		}
		delete[] str;
		delete[] to_be_replaced;
		delete[] replacement;
		return 0;
	}

	int acwing1672::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		string a;
		string b;
		cin >> a >> b;
		bool prev_eq = true;
		int ans      = 0;
		for(int i = 0; i < n; i++) {
			if(a[i] == b[i]) {
				if(!prev_eq) {
					ans++;
				}
				prev_eq = true;
			} else {
				prev_eq = false;
			}
		}
		if(!prev_eq) {
			ans++;
		}
		cout << ans;
		return 0;
	}

	int acwing772::main(istream &cin, ostream &cout) {
		string str;
		cin >> str;
		int charset[26] = {};
		for(const char ch: str) {
			charset[ch - 'a']++;
		}
		for(const char ch: str) {
			if(charset[ch - 'a'] == 1) {
				cout << ch;
				return 0;
			}
		}
		cout << "no";
		return 0;
	}

	int acwing771::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			string str;
			cin >> str;
			char ch_max   = str[0];
			int count_max = 1;
			char ch       = str[0];
			int count     = 1;
			for(int j = 1; j < str.length(); j++) {
				if(str[j] == str[j - 1]) {
					count++;
				} else {
					if(count > count_max) {
						count_max = count;
						ch_max    = ch;
					}
					ch    = str[j];
					count = 1;
				}
			}
			if(count > count_max) {
				count_max = count;
				ch_max    = ch;
			}
			cout << ch_max << " " << count_max << endl;
		}
		return 0;
	}

	namespace acwing1660 {
		int acwing1660::main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			auto cows = vector<cow>();
			for(int i = 0; i < n; i++) {
				int x;
				bool infected;
				cin >> x >> infected;
				cows.push_back(cow{x, infected});
			}
			sort(cows.begin(), cows.end());
			int r = 1000000;
			for(int i = 0; i < n; i++) {
				if(i - 1 >= 0 && cows[i].infected != cows[i - 1].infected) {
					r = min(r, abs(cows[i].x - cows[i - 1].x));
				}
				if(i + 1 < n && cows[i].infected != cows[i + 1].infected) {
					r = min(r, abs(cows[i].x - cows[i + 1].x));
				}
			}
			for(int i = 0; i + 1 < n; i++) {
				if(cows[i].infected && cows[i + 1].infected && abs(cows[i].x - cows[i + 1].x) < r) {
					cows[i].infected = false;
				}
			}
			int ans = 0;
			for(int i = 0; i < n; i++) {
				if(cows[i].infected) {
					ans++;
				}
			}
			cout << ans;
			return 0;
		}

		bool cow::operator<(const cow &c) const { return this->x < c.x; }
	}// namespace acwing1660

	int acwing774::main(istream &cin, ostream &cout) {
		auto *str = new char[501];
		cin.getline(str, 501);
		str[strlen(str) - 1]     = '\0';
		const char *longest_word = nullptr;
		int max_len              = 0;
		for(const char *word = strtok(str, " "); word != nullptr; word = strtok(nullptr, " ")) {
			if(max_len < strlen(word)) {
				max_len      = strlen(word);
				longest_word = word;
			}
		}
		cout << longest_word;
		delete[] str;
		return 0;
	}

	int acwing775::main(istream &cin, ostream &cout) {
		auto *str     = new char[101];
		auto *str_rev = new char *[101];
		int i         = 0;
		cin.getline(str, 101);
		for(char *word = strtok(str, " "); word != nullptr; word = strtok(nullptr, " ")) {
			str_rev[i++] = word;
		}
		for(int j = i - 1; j >= 0; j--) {
			cout << str_rev[j] << " ";
		}
		delete[] str;
		delete[] str_rev;
		return 0;
	}

	int acwing3347::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto *flowers    = new int[n];
		auto *prefix_sum = new int[n];
		auto location    = unordered_map<int, unordered_set<int>>();
		int sum          = 0;
		for(int i = 0; i < n; i++) {
			cin >> flowers[i];
			sum += flowers[i];
			prefix_sum[i] = sum;
			location[flowers[i]].insert(i);
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i; j < n; j++) {
				const int len = j - i + 1;
				sum           = prefix_sum[j] - (i - 1 >= 0 ? prefix_sum[i - 1] : 0);
				if(sum % len == 0) {
					int avg = sum / len;
					for(const auto flower: location[avg]) {
						if(i <= flower && flower <= j) {
							ans++;
							break;
						}
					}
				}
			}
		}
		cout << ans;
		delete[] flowers;
		delete[] prefix_sum;
		return 0;
	}

	int acwing777::main(istream &cin, ostream &cout) {
		string str;
		cin >> str;
		while(str != ".") {
			for(int i = 1; i <= str.length(); i++) {
				if(str.length() % i == 0) {
					bool ok       = true;
					string substr = str.substr(0, i);
					for(int j = i; j < str.length(); j += i) {
						if(str.substr(j, i) != substr) {
							ok = false;
							break;
						}
					}
					if(ok) {
						cout << str.length() / i << endl;
						break;
					}
				}
			}
			cin >> str;
		}
		return 0;
	}

	int acwing776::main(istream &cin, ostream &cout) {
		string s1;
		string s2;
		cin >> s1 >> s2;
		const string s11 = s1 + s1;
		const string s22 = s2 + s2;
		cout << boolalpha << (s11.find(s2) != string::npos || s22.find(s1) != string::npos);
		return 0;
	}

	int acwing4302::main(istream &cin, ostream &cout) {
		int sum_b = 0;
		int sum_c = 0;
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if(a > 0) {
				sum_b += a;
			} else {
				sum_c -= a;
			}
		}
		cout << sum_b + sum_c;
		return 0;
	}

	int acwing4303::main(istream &cin, ostream &cout) {
		int q;
		cin >> q;
		auto um = unordered_map<string, vector<string> *>();
		for(int i = 0; i < q; i++) {
			string str1;
			string str2;
			cin >> str1 >> str2;
			if(!um.contains(str1)) {
				auto *vec = new vector<string>();
				vec->push_back(str1);
				vec->push_back(str2);
				um.insert(make_pair(str2, vec));
			} else {
				um[str1]->push_back(str2);
				um[str2] = um[str1];
				um[str1] = nullptr;
			}
		}
		int count = 0;
		for(auto [k, v]: um) {
			if(v != nullptr) {
				count++;
			}
		}
		cout << count << endl;
		for(auto [k, v]: um) {
			if(v != nullptr) {
				cout << *v->begin() << " " << k << endl;
				delete v;
			}
		}
		return 0;
	}

	int acwing4304::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto vec = vector<unsigned int>();
		for(int i = 0; i < n; i++) {
			string str;
			cin >> str;
			auto ui   = str2int(str);
			bool flag = false;
			for(int j = 0; j < vec.size(); j++) {
				if((vec[j] & ui) != 0) {
					vec[j] |= ui;
					flag = true;
				}
			}
			if(!flag) {
				vec.push_back(ui);
			}
		}
		bool ok = true;
		while(ok) {
			ok = false;
			for(int i = 0; i + 1 < vec.size(); i++) {
				for(int j = i + 1; j < vec.size(); j++) {
					if((vec[i] & vec[j]) != 0) {
						vec[i] |= vec[j];
						vec.erase(vec.begin() + j);
						ok = true;
					}
				}
			}
		}
		cout << vec.size();
		return 0;
	}

	unsigned int acwing4304::str2int(const string &str) {
		unsigned int ans = 0;
		for(const char ch: str) {
			ans |= 1 << ch - 'a';
		}
		return ans;
	}

	int acwing778::main(istream &cin, ostream &cout) {
		auto *input = new char[323];
		auto strs   = vector<string>();
		cin.getline(input, 323);
		for(char *str = strtok(input, ","); str != nullptr; str = strtok(nullptr, ",")) {
			strs.emplace_back(str);
		}
		auto l       = strs[0].find(strs[1]);
		const auto r = strs[0].rfind(strs[2]);
		if(l == string::npos || r == string::npos) {
			cout << -1;
			return 0;
		}
		l += strs[1].length();
		cout << (static_cast<int>(r) < static_cast<int>(l) ? -1 : static_cast<int>(r) - static_cast<int>(l));
		return 0;
	}

	int acwing779::main(istream &cin, ostream &cout) {
		while(true) {
			int n;
			cin >> n;
			if(n == 0) {
				break;
			}
			string suffix;
			cin >> suffix;
			for(int i = 1; i < n; i++) {
				string str;
				cin >> str;
				if(!suffix.empty()) {
					auto ss = stringstream();
					for(int j = 0; j < min(str.length(), suffix.length()) && suffix[suffix.length() - 1 - j] == str[str.length() - 1 - j]; j++) {
						ss << suffix[suffix.length() - 1 - j];
					}
					string s = ss.str();
					suffix   = string(s.rbegin(), s.rend());
				}
			}
			cout << suffix << endl;
		}
		return 0;
	}

	int acwing804::fact(int n) {
		if(n == 1) {
			return 1;
		}
		return n * fact(n - 1);
	}

	int acwing804::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		cout << fact(n);
		return 0;
	}

	int acwing810::abs(int n) { return n > 0 ? n : -n; }

	int acwing810::main(istream &cin, ostream &cout) {
		int x;
		cin >> x;
		cout << abs(x);
		return 0;
	}

	int acwing805::main(istream &cin, ostream &cout) {
		int x;
		int y;
		cin >> x >> y;
		cout << max(x, y);
		return 0;
	}

	int acwing805::max(int x, int y) { return x > y ? x : y; }

	int acwing806::main(istream &cin, ostream &cout) {
		double x;
		double y;
		cin >> x >> y;
		cout << fixed << setprecision(2) << add(x, y);
		return 0;
	}

	double acwing806::add(double x, double y) { return x + y; }

	int acwing808::main(istream &cin, ostream &cout) {
		int a;
		int b;
		cin >> a >> b;
		cout << gcd(a, b);
		return 0;
	}

	int acwing808::gcd(int a, int b) {
		while(b != 0) {
			const int t = a % b;
			a           = b;
			b           = t;
		}
		return a;
	}

	int acwing807::main(istream &cin, ostream &cout) {
		int l;
		int r;
		cin >> l >> r;
		cout << sum(l, r);
		return 0;
	}

	int acwing807::sum(int l, int r) {
		int sum = (l + r) * ((r - l + 1) / 2);
		if((r - l + 1) % 2 == 1) {
			sum += (r + l) / 2;
		}
		return sum;
	}

	int acwing811::main(istream &cin, ostream &cout) {
		int x;
		int y;
		cin >> x >> y;
		swap(x, y);
		cout << x << " " << y;
		return 0;
	}

	void acwing811::swap(int &x, int &y) {
		const int temp = x;
		x              = y;
		y              = temp;
	}

	int acwing809::main(istream &cin, ostream &cout) {
		int a;
		int b;
		cin >> a >> b;
		cout << lcm(a, b);
		return 0;
	}

	int acwing809::lcm(int a, int b) {
		const int f = acwing808::gcd(a, b);
		return a * b / f;
	}

	int acwing812::main(istream &cin, ostream &cout) {
		int n;
		int size;
		cin >> n >> size;
		auto *a = new int[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		print(a, size, cout);
		delete[] a;
		return 0;
	}

	void acwing812::print(int *a, int size, ostream &cout) {
		for(int i = 0; i < size; i++) {
			cout << a[i] << " ";
		}
	}

	int acwing814::main(istream &cin, ostream &cout) {
		int n;
		int m;
		int size;
		cin >> n >> m >> size;
		auto *a = new int[n];
		auto *b = new int[m];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for(int i = 0; i < m; i++) {
			cin >> b[i];
		}
		copy(a, b, size);
		for(int i = 0; i < m; i++) {
			cout << b[i] << " ";
		}
		return 0;
	}

	void acwing814::copy(const int *a, int *b, int size) {
		for(int i = 0; i < size; i++) {
			b[i] = a[i];
		}
	}

	void acwing813::print2D(int a[][100], int row, int col, ostream &cout) {
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}

	int acwing813::main(istream &cin, ostream &cout) {
		int row;
		int col;
		cin >> row >> col;
		int arr[100][100];
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				cin >> arr[i][j];
			}
		}
		print2D(arr, row, col, cout);
		return 0;
	}

	int acwing815::main(istream &cin, ostream &cout) {
		auto *str = new char[101];
		cin.getline(str, 101);
		print(str, cout);
		return 0;
	}

	void acwing815::print(char *str, ostream &cout) {
		for(int i = 0; str[i] != '\0'; i++) {
			cout << str[i];
		}
	}

	int acwing4305::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		char fibb[1001] = {};
		memset(fibb, 'o', sizeof fibb);
		fibb[1]           = 'O';
		unsigned int a    = 1;
		unsigned int b    = 1;
		unsigned int next = a + b;
		while(next <= n) {
			fibb[next] = 'O';
			a          = b;
			b          = next;
			next       = a + b;
		}
		for(int i = 1; i <= n; i++) {
			cout << fibb[i];
		}
		return 0;
	}

	int acwing4306::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int sum      = 0;
		int addition = 0;
		for(int i = 1; i <= n; i++) {
			if(i + addition < a[i - 1]) {
				addition = a[i - 1] - i;
			}
			sum += i + addition - a[i - 1];
		}
		cout << sum;
		return 0;
	}

	int acwing4307::main(istream &cin, ostream &cout) {
		string a;
		string b;
		cin >> a >> b;
		auto a_count = unordered_map<int, int>();
		for(const char ch: a) {
			a_count[ch - '0']++;
		}
		if(a.length() == b.length()) {
			cout << dfs(0, false, a_count, b);
		} else {
			for(int i = 9; i >= 0; i--) {
				while(a_count[i] > 0) {
					cout << i;
					a_count[i]--;
				}
			}
		}
		return 0;
	}

	string acwing4307::dfs(int i, bool free, unordered_map<int, int> um, string &b) {
		auto oss = ostringstream();
		int j    = b[i] - '0';
		if(free) {
			goto B;
		}
		if(um[j] > 0) {
			auto um_cpy = unordered_map(um);
			um_cpy[j]--;
			if(i == b.length() - 1) {
				oss << j;
				return oss.str();
			}
			string ans = dfs(i + 1, false, um_cpy, b);
			if(!ans.empty()) {
				oss << j << ans;
			} else {
				//不可行
				goto B;
			}
		} else {
		B:;
			int k = b[i] - '0' - 1;
			if(free) {
				k = 9;
			}
			for(; k >= 0; k--) {
				if(um[k] > 0) {
					auto um_cpy = unordered_map(um);
					um_cpy[k]--;
					if(i == b.length() - 1) {
						oss << k;
						break;
					}
					string ans = dfs(i + 1, true, um_cpy, b);
					if(!ans.empty()) {
						oss << k << ans;
						break;
					}
				}
			}
		}

		return oss.str();
	}

	int acwing819::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		cout << factorial(n);
		return 0;
	}

	int acwing819::factorial(int n) {
		if(n == 1) {
			return 1;
		}
		return n * factorial(n - 1);
	}

	int acwing816::main(istream &cin, ostream &cout) {
		int n;
		int size;
		cin >> n >> size;
		auto *a = new int[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		reverse(a, size);
		for(int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		delete[] a;
		return 0;
	}

	void acwing816::reverse(int a[], int size) {
		for(int i = 0; i < size - 1 - i; i++) {
			const int tmp   = a[i];
			a[i]            = a[size - 1 - i];
			a[size - 1 - i] = tmp;
		}
	}

	int acwing820::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		cout << fibb(n);
		return 0;
	}

	int acwing820::fibb(int n) {
		if(n <= 2) {
			return 1;
		}
		return fibb(n - 1) + fibb(n - 2);
	}

	int acwing817::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto *a = new int[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << get_unique_count(a, n);
		delete[] a;
		return 0;
	}

	int acwing817::get_unique_count(int *a, int n) {
		unordered_set<int> um;
		for(int i = 0; i < n; i++) {
			um.insert(a[i]);
		}
		return um.size();
	}

	int acwing818::main(istream &cin, ostream &cout) {
		int n;
		int l;
		int r;
		cin >> n >> l >> r;
		auto *a = new int[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, l, r);
		for(int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		delete[] a;
		return 0;
	}

	void acwing818::sort(int *a, int l, int r) {
		if(l == r) {
			return;
		}
		if(l + 1 == r) {
			if(a[l] < a[r]) {
				return;
			}
			const int tmp = a[l];
			a[l]          = a[r];
			a[r]          = tmp;
		}
		const int m = a[(l + r) / 2];
		deque<int> dq;
		int cursor = l;
		dq.push_back(m);
		for(int i = l; i <= r; i++) {
			if(i != (l + r) / 2) {
				if(a[i] <= m) {
					dq.push_front(a[i]);
					cursor++;
				} else {
					dq.push_back(a[i]);
				}
			}
		}
		for(int i = l; i <= r; i++) {
			a[i] = dq[i - l];
		}
		if(l <= cursor - 1) {
			sort(a, l, cursor - 1);
		}
		if(r >= cursor + 1) {
			sort(a, cursor + 1, r);
		}
	}

	int acwing821::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto *dp = new int[n + 1];
		memset(dp, 0, (n + 1) * sizeof(int));
		dp[1] = 1;
		dp[2] = 1;
		for(int i = 1; i <= n; i++) {
			if(i + 1 <= n) {
				dp[i + 1] += dp[i];
			}
			if(i + 2 <= n) {
				dp[i + 2] += dp[i];
			}
		}
		cout << dp[n];
		delete[] dp;
		return 0;
	}

	int acwing822::main(istream &cin, ostream &cout) {
		int n;
		int m;
		cin >> n >> m;
		const int sum   = n + m;
		auto *factorial = new unsigned long long[sum + 1];
		factorial[1]    = 1;
		for(int i = 2; i <= sum; i++) {
			factorial[i] = i * factorial[i - 1];
		}
		cout << factorial[sum] / (factorial[n] * factorial[m]);
		delete[] factorial;
		return 0;
	}

	int acwing823::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		set<int> s;
		for(int i = 1; i <= n; i++) {
			s.insert(i);
		}
		vector<int> vec;
		dfs(vec, s, cout);
		return 0;
	}

	void acwing823::dfs(vector<int> &vec, set<int> &s, ostream &cout) {
		if(s.empty()) {
			for(const int i: vec) {
				cout << i << " ";
			}
			cout << endl;
		} else {
			for(auto i: s) {
				vector vec_cpy = vec;
				set<int> s_cpy = s;
				vec_cpy.push_back(i);
				s_cpy.erase(i);
				dfs(vec_cpy, s_cpy, cout);
			}
		}
	}

	int acwing21::Solution::Fibonacci(int n) {
		auto *fibb = new int[n];
		fibb[0]    = 1;
		fibb[1]    = 1;
		for(int i = 2; i < n; i++) {
			fibb[i] = fibb[i - 1] + fibb[i - 2];
		}
		const int ans = fibb[n - 1];
		delete[] fibb;
		return ans;
	}

	namespace acwing78 {
		string Solution::leftRotateString(string str, int n) {
			ostringstream oss;
			for(int i = 0; i < str.length(); i++) {
				oss << str[(n + i) % str.length()];
			}
			return oss.str();
		}
	}// namespace acwing78

	namespace acwing16 {
		string Solution::replaceSpaces(string &str) {
			ostringstream oss;
			for(const char ch: str) {
				if(ch != ' ') {
					oss << ch;
				} else {
					oss << "%20";
				}
			}
			return oss.str();
		}
	}// namespace acwing16

	namespace acwing87 {
		int Solution::strToInt(string str) {
			for(int i = 0; i < str.length(); i++) {
				if(str[i] != ' ') {
					str = str.substr(i);
					break;
				}
			}
			bool pos = true;
			if(str[0] == '+' || str[0] == '-') {
				pos = str[0] == '+';
				str = str.substr(1);
			}
			unsigned long long ans = 0;
			for(const char ch: str) {
				if(isdigit(ch) != 0) {
					ans *= 10;
					ans += ch - '0';
				} else {
					break;
				}
			}
			return ans > INT_MAX
			               ? (pos ? INT_MAX : INT_MIN)
			       : pos
			               ? ans
			               : -ans;
		}
	}// namespace acwing87

	int acwing4308::main(istream &cin, ostream &cout) {
		string s1;
		string s2;
		cin >> s1 >> s2;
		bool flag = true;
		cout << s1[0];
		for(int i = 1; i < s1.length(); i++) {
			const char ch = s1[i];
			if(ch < s2[0]) {
				cout << ch;
			} else {
				break;
			}
		}
		cout << s2[0];
		return 0;
	}

	int acwing4309::main(istream &cin, ostream &cout) {
		int n;
		int x0;
		int y0;
		cin >> n >> x0 >> y0;
		bool flag = false;
		unordered_set<double> slopes;
		for(int i = 0; i < n; i++) {
			int xi;
			int yi;
			cin >> xi >> yi;
			if(xi != x0) {
				double slope = static_cast<double>(y0 - yi) / (x0 - xi);
				slopes.insert(slope);
			} else {
				flag = true;
			}
		}
		cout << slopes.size() + (flag ? 1 : 0);
		return 0;
	}

	namespace acwing4310 {
		int acwing4310::main(istream &cin, ostream &cout) {
			int n;
			int q;
			cin >> n >> q;
			vector<int> vec;
			for(int i = 1; i <= n; i++) {
				um[i] = new TreeNode(i);
			}
			for(int i = 2; i <= n; i++) {
				int parent;
				cin >> parent;
				um[parent]->nexts[i] = um[i];
			}
			dfs(&vec, um[1]);
			for(int i = 0; i < vec.size(); i++) {
				position[vec[i]] = i;
			}
			for(int i = 0; i < q; i++) {
				int u;
				int k;
				cin >> u >> k;
				if(k > size_tree[u]) {
					cout << -1;
				} else {
					cout << vec[position[u] + k - 1];
				}
				cout << endl;
			}
			for(auto [i, v]: um) {
				delete v;
			}
			return 0;
		}

		int acwing4310::dfs(vector<int> *vec, TreeNode *node) {
			int sum = 1;
			vec->push_back(node->val);
			for(auto [i, next]: node->nexts) {
				if(next != nullptr) {
					sum += dfs(vec, next);
				}
			}
			size_tree[node->val] = sum;
			return sum;
		}
	}// namespace acwing4310

	namespace acwing84 {
		int Solution::getSum(int n) {
			int ans = (1 + n) * (n / 2);
			if(n % 2 != 0) {
				ans += n / 2;
			}
			return ans;
		}
	}// namespace acwing84

	namespace acwing35 {
		ListNode *Solution::reverseList(ListNode *head) {
			if(head == nullptr) {
				return head;
			}
			auto *prev    = head;
			auto *current = head->next;
			while(current != nullptr) {
				auto *next    = current->next;
				current->next = prev;
				prev          = current;
				current       = next;
			}
			head->next = nullptr;
			return prev;
		}
	}// namespace acwing35

	namespace acwing28 {
		void Solution::deleteNode(ListNode *node) {
			node->val        = node->next->val;
			const auto *next = node->next;
			delete next;
			node->next = node->next->next;
		}
	}// namespace acwing28

	namespace acwing66 {
		ListNode *Solution::findFirstCommonNode(ListNode *headA, ListNode *headB) {
			unordered_set<ListNode *> nodes;
			for(auto *current = headA; current != nullptr; current = current->next) {
				nodes.insert(current);
			}
			for(auto *current = headB; current != nullptr; current = current->next) {
				if(nodes.contains(current)) {
					return current;
				}
			}
			return nullptr;
		}
	}// namespace acwing66

	namespace acwing36 {
		ListNode *Solution::merge(ListNode *l1, ListNode *l2) {
			auto *current        = new ListNode(0);
			const ListNode *head = current;
			while(l1 != nullptr && l2 != nullptr) {
				if(l1->val < l2->val) {
					current->next = l1;
					l1            = l1->next;
				} else {
					current->next = l2;
					l2            = l2->next;
				}
				current = current->next;
			}
			if(l1 == nullptr) {
				current->next = l2;
			} else {
				current->next = l1;
			}
			return head->next;
		}
	}// namespace acwing36

	namespace acwing29 {
		ListNode *Solution::deleteDuplication(ListNode *head) {
			if(head == nullptr) {
				return head;
			}
			while(head != nullptr && head->next != nullptr && head->val == head->next->val) {
				const int val = head->val;
				while(head != nullptr && head->val == val) {
					head = head->next;
				}
			}
			ListNode *ans = head;
			while(head != nullptr) {
				while(head->next != nullptr && head->next->next != nullptr && head->next->val == head->next->next->val) {
					const int val    = head->next->val;
					ListNode *cursor = head->next;
					while(cursor != nullptr && cursor->val == val) {
						cursor = cursor->next;
					}
					head->next = cursor;
				}
				head = head->next;
			}
			return ans;
		}
	}// namespace acwing29

	namespace acwing67 {
		int Solution::getNumberOfK(vector<int> &nums, int k) {
			int ans   = 0;
			bool flag = false;
			for(const auto num: nums) {
				if(num == k) {
					ans++;
					flag = true;
				} else if(flag) {
					break;
				}
			}
			return ans;
		}
	}// namespace acwing67

	namespace acwing53 {
		vector<int> Solution::getLeastNumbers_Solution(vector<int> input, int k) {
			sort(input.begin(), input.end());
			return vector(input.begin(), input.begin() + k);
		}
	}// namespace acwing53

	/// \brief AcWing 68. 0到n-1中缺失的数字
	namespace acwing68 {
		int Solution::getMissingNumber(vector<int> &nums) {
			if(nums.empty()) {
				return 0;
			}
			int i = 0;
			while(nums[i] == i) {
				i++;
			}
			return i;
		}
	}// namespace acwing68

	namespace acwing75 {
		vector<int> Solution::findNumbersWithSum(vector<int> &nums, int target) {
			vector<int> ans(2);
			set nms(nums.begin(), nums.end());
			for(auto num = nms.begin(); *num <= target / 2 && num != nms.end(); ++num) {
				if(nms.contains(target - *num)) {
					ans[0] = *num;
					ans[1] = target - *num;
					return ans;
				}
			}
			return ans;
		}
	}// namespace acwing75

	namespace acwing32 {
		void Solution::reOrderArray(vector<int> &array) {
			int l = 0;
			int r = array.size() - 1;
			while(l < r) {
				while(l < r && array[l] % 2 == 1) {
					l++;
				}
				while(l < r && array[r] % 2 == 0) {
					r--;
				}
				if(l < r) {
					swap(array[l], array[r]);
				}
			}
		}
	}// namespace acwing32

	namespace acwing51 {
		vector<vector<int>> Solution::permutation(vector<int> &nums) {
			auto ans = vector<vector<int>>();
			set<vector<int>> s;
			dfs(vector<int>(), nums, s);
			for(const auto &vec: s) {
				ans.push_back(vec);
			}
			return ans;
		}

		void Solution::dfs(const vector<int> &vec, vector<int> nums, set<vector<int>> &s) {
			if(nums.empty()) {
				s.insert(vec);
			}
			for(int i = 0; i < nums.size(); i++) {
				auto nums_cpy = vector(nums);
				auto vec_cpy  = vector(vec);
				nums_cpy.erase(nums_cpy.begin() + i);
				vec_cpy.push_back(nums[i]);
				dfs(vec_cpy, nums_cpy, s);
			}
		}
	}// namespace acwing51

	namespace acwing17 {
		vector<int> Solution::printListReversingly(ListNode *head) {
			deque<int> deq;
			for(const auto *current = head; current != nullptr; current = current->next) {
				deq.push_front(current->val);
			}
			return vector(deq.begin(), deq.end());
		}
	}// namespace acwing17

	namespace acwing26 {
		int Solution::NumberOf1(int n) {
			int ans         = 0;
			unsigned int un = n;
			while(un != 0U) {
				ans += un & 1;
				un >>= 1;
			}
			return ans;
		}
	}// namespace acwing26

	namespace acwing20 {
		MyQueue::MyQueue() {
			main = vector<int>();
			tmp  = vector<int>();
		}

		void MyQueue::push(int x) { main.push_back(x); }

		int MyQueue::pop() {
			while(main.size() != 1) {
				tmp.push_back(main.back());
				main.pop_back();
			}
			const auto ret = main.back();
			main.pop_back();
			while(!tmp.empty()) {
				main.push_back(tmp.back());
				tmp.pop_back();
			}
			return ret;
		}

		int MyQueue::peek() {
			while(main.size() != 1) {
				tmp.push_back(main.back());
				main.pop_back();
			}
			const auto ret = main.back();
			while(!tmp.empty()) {
				main.push_back(tmp.back());
				tmp.pop_back();
			}
			return ret;
		}

		bool MyQueue::empty() const { return main.empty(); }
	}// namespace acwing20

	int acwing862::main(istream &cin, ostream &cout) {
		int n;
		cin >> n;
		auto comp = [](tuple<int, float, string> a, tuple<int, float, string> b) {
			auto [ax, ay, az] = std::move(a);
			auto [bx, by, bz] = std::move(b);
			return ax < bx;
		};
		set<tuple<int, float, string>, decltype(comp)> s(comp);
		for(int i = 0; i < n; i++) {
			int x;
			float y;
			string z;
			cin >> x >> y >> z;
			s.insert(make_tuple(x, y, z));
		}
		for(const auto &t: s) {
			auto [x, y, z] = t;
			cout << x << ' ' << fixed << setprecision(2) << y << ' ' << z << endl;
		}
		return 0;
	}

	int acwing4311::main(istream &cin, ostream &cout) {
		int n;
		int m;
		cin >> n >> m;
		double maximum = 0;
		for(int i = 0; i < n; i++) {
			int a;
			int b;
			cin >> a >> b;
			maximum = max(maximum, m * a / static_cast<double>(b));
		}
		cout << fixed << setprecision(6) << maximum;
		return 0;
	}

	int acwing3412::main(istream &cin, ostream &cout) {
		int n;
		int m;
		int q;
		cin >> n >> m >> q;
		if(m > n) {
			for(int i = 0; i < q; i++) {
				cout << 0 << endl;
			}
			return 0;
		}
		string s;
		string t;
		cin >> s >> t;
		set<int> sub_end;
		set<int> sub_start;
		int sub_count = 0;
		for(int i = 0; i + m <= n; i++) {
			string str = s.substr(i, m);
			if(str == t) {
				sub_count++;
				sub_start.insert(i);
				sub_end.insert(i + m - 1);
			}
		}
		vector sub_end_count(n + 1, 0);
		vector sub_start_count(n + 1, 0);
		int current = 0;
		for(int i = 0; i < n + 1; i++) {
			if(sub_end.contains(i)) {
				current++;
			}
			sub_end_count[i] = current;
		}
		current = 0;
		for(int i = n; i >= 0; i--) {
			if(sub_start.contains(i)) {
				current++;
			}
			sub_start_count[i] = current;
		}
		for(int i = 0; i < q; i++) {
			int l;
			int r;
			cin >> l >> r;
			int ans = sub_end_count[r - 1] - (sub_count - sub_start_count[l - 1]);
			cout << max(ans, 0) << endl;
		}
		return 0;
	}

	int acwing3346::main(istream &cin, ostream &cout) {
		vector<int> nums(7);
		vector<int> abc(3);
		for(int i = 0; i < 7; i++) {
			cin >> nums[i];
		}
		sort(nums.begin(), nums.end());
		abc[0] = nums[0];
		abc[1] = nums[1];
		abc[2] = nums[6] - abc[0] - abc[1];
		sort(abc.begin(), abc.end());
		cout << abc[0] << ' ' << abc[1] << ' ' << abc[2];
		return 0;
	}

	namespace acwing3358 {
		int main(istream &cin, ostream &cout) {
			int char_pos[26] = {};
			char ch;
			for(int i = 0; i < 26; i++) {
				cin >> ch;
				char_pos[ch - 'a'] = i;
			}
			int ans     = 1;
			int current = -1;
			while(cin >> ch) {
				if(char_pos[ch - 'a'] <= current) {
					ans++;
				}
				current = char_pos[ch - 'a'];
			}
			cout << ans;
			return 0;
		}
	};// namespace acwing3358

	namespace acwing3370 {
		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			unordered_map<string, int> zodiacs;
			unordered_map<string, cow *> cows;
			zodiacs["Ox"]      = 0;
			zodiacs["Tiger"]   = 1;
			zodiacs["Rabbit"]  = 2;
			zodiacs["Dragon"]  = 3;
			zodiacs["Snake"]   = 4;
			zodiacs["Horse"]   = 5;
			zodiacs["Goat"]    = 6;
			zodiacs["Monkey"]  = 7;
			zodiacs["Rooster"] = 8;
			zodiacs["Dog"]     = 9;
			zodiacs["Pig"]     = 10;
			zodiacs["Rat"]     = 11;
			cows["Bessie"]     = new cow("Bessie", 0, zodiacs["Ox"]);
			for(int i = 0; i < n; i++) {
				string str;
				string name1;
				string name2;
				cin >> name1 >> str >> str >> str;
				const bool previous = str == "previous";
				cin >> str;
				const int zodiac = zodiacs[str];
				cin >> str >> str >> name2;
				cow *cow1;
				cow *cow2;
				if(!cows.contains(name1)) {
					cow1        = new cow(name1, -1, zodiac);
					cows[name1] = cow1;
				} else {
					cow1         = cows[name1];
					cow1->zodiac = zodiac;
				}
				if(!cows.contains(name2)) {
					cow2        = new cow(name2, -1, -1);
					cows[name2] = cow2;
				} else {
					cow2 = cows[name2];
				}
				if(previous) {
					cow2->previous.push_back(cow1);
					cow1->next.push_back(cow2);
				} else {
					cow2->next.push_back(cow1);
					cow1->previous.push_back(cow2);
				}
			}
			cout << abs(dfs(cows["Bessie"]));
			return 0;
		}

		int dfs(cow *c) {
			if(c->name == "Elsie") {
				return c->val;
			}
			for(auto *prev: c->previous) {
				if(prev->val == -1) {
					if(c->zodiac == prev->zodiac) {
						prev->val = c->val - 12;
					} else {
						prev->val = c->val - (c->zodiac + 12 - prev->zodiac) % 12;
					}
					const int ret = dfs(prev);
					if(ret != -1) {
						return ret;
					}
				}
			}
			for(auto *nxt: c->next) {
				if(nxt->val == -1) {
					if(c->zodiac == nxt->zodiac) {
						nxt->val = c->val + 12;
					} else {
						nxt->val = c->val + (nxt->zodiac + 12 - c->zodiac) % 12;
					}
					const int ret = dfs(nxt);
					if(ret != -1) {
						return ret;
					}
				}
			}
			return -1;
		}

		cow::cow(string name, int val, int zodiac) {
			this->name     = std::move(name);
			this->val      = val;
			this->zodiac   = zodiac;
			this->previous = vector<cow *>();
			this->next     = vector<cow *>();
		}
	}// namespace acwing3370

	namespace acwing3745 {
		int main(istream &cin, ostream &cout) {
			int n;
			int l;
			cin >> n >> l;
			vector<int> c(n);
			unordered_map<int, int> count;
			for(int i = 0; i < n; i++) {
				cin >> c[i];
				count[c[i]]++;
			}
			sort(c.rbegin(), c.rend());
			if(*c.begin() == 0) {
				if(l != 0) {
					*c.begin() = 1;
					l--;
				} else {
					cout << 0;
					return 0;
				}
			}
			int h = 0;
			while(h < n && c[h] >= h + 1) {
				h++;
			}
			if(l == 0) {
				cout << h;
				return 0;
			}
			int k = 0;
			for(int i = h - 1; i >= 0 && c[i] == h; i--) {
				k++;
			}
			if(l >= k + 1 && c[h] == h) {
				cout << h + 1;
			} else {
				cout << h;
			}
			return 0;
		}
	}// namespace acwing3745

	namespace acwing1459 {
		int main(istream &cin, ostream &cout) {
			int k;
			int n;
			cin >> k >> n;
			auto hash = [](const pair<int, int> p) -> int { return p.first * 20 + p.second; };
			unordered_set<pair<int, int>, decltype(hash)> pairs;
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					if(i != j) {
						pairs.insert(make_pair(i, j));
					}
				}
			}
			for(int i = 0; i < k; i++) {
				vector<int> vec(n);
				for(int j = 0; j < n; j++) {
					cin >> vec[j];
				}
				for(int j = 0; j + 1 < n; j++) {
					for(int l = j + 1; l < n; l++) {
						pairs.erase(make_pair(vec[j], vec[l]));
					}
				}
			}
			cout << pairs.size();
			return 0;
		}
	}// namespace acwing1459

	namespace acwing1442 {
		int main(istream &cin, ostream &cout) {
			int n;
			int k;
			cin >> n >> k;
			vector<string> vec(n);
			for(int i = 0; i < n; i++) {
				cin >> vec[i];
			}
			ostringstream oss;
			oss << vec[0];
			int current = vec[0].length();
			for(int i = 1; i < n; i++) {
				if(current + vec[i].length() > k) {
					cout << oss.str() << endl;
					oss = ostringstream();
					oss << vec[i];
					current = vec[i].length();
				} else {
					oss << ' ';
					oss << vec[i];
					current += vec[i].length();
				}
			}
			cout << oss.str();
			return 0;
		}
	}// namespace acwing1442

	namespace acwing4314 {
		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			int ans = 0;
			for(int a = 1; a <= n; a++) {
				for(int b = a; b <= n; b++) {
					const int c = a ^ b ^ 0;
					if(n >= c && c >= b && c < a + b) {
						ans++;
					}
				}
			}
			cout << ans;
			return 0;
		}
	}// namespace acwing4314

	namespace acwing4315 {
		int main(istream &cin, ostream &cout) {
			long long n;
			long long s;
			cin >> n >> s;
			vector<long long> a(n);
			long long a_sum = 0;
			for(int i = 0; i < n; i++) {
				cin >> a[i];
				a_sum += a[i];
			}
			for(int i = 0; i < n; i++) {
				const long long low  = max(static_cast<long long>(1), s - (a_sum - a[i]));
				const long long high = min(a[i], s - (n - 1));
				if(low <= high) {
					cout << a[i] - (high - low + 1) << ' ';
				}
			}
			return 0;
		}
	}// namespace acwing4315

	namespace acwing1671 {
		int main(istream &cin, ostream &cout) {
			int ans = 0;
			unordered_map<int, set<int>> col;
			unordered_map<int, set<int>> row;
			set<pair<int, int>> us;
			int n;
			cin >> n;
			for(int i = 0; i < n; i++) {
				int x;
				int y;
				cin >> x >> y;
				us.insert(make_pair(x, y));
				row[x].insert(y);
				col[y].insert(x);
			}
			for(auto [x, y]: us) {
				const int max_width  = max(abs(*row[x].begin() - y), abs(*row[x].rbegin() - y));
				const int max_height = max(abs(*col[y].begin() - x), abs(*col[y].rbegin() - x));
				ans                  = max(ans, max_width * max_height);
			}
			cout << ans;
			return 0;
		}
	}// namespace acwing1671

	namespace acwing1659 {
		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			vector<bool> pen(n);
			string str;
			cin >> str;
			bool has1 = false;
			for(int i = 0; i < n; i++) {
				pen[i] = str[i] == '1';
				if(pen[i]) {
					has1 = true;
				}
			}
			if(!has1) {
				cout << n - 1;
				return 0;
			}
			vector<int> spaces2;
			vector<int> spaces1;
			int current = 0;
			int left    = 0;
			int right   = n - 1;
			while(!pen[left]) {
				left++;
			}
			if(left > 0) {
				spaces1.push_back(left);
			}
			left++;
			while(!pen[right]) {
				right--;
			}
			if(right < n - 1) {
				spaces1.push_back(n - 1 - right);
			}
			for(; left <= right; left++) {
				if(!pen[left]) {
					current++;
				} else {
					spaces2.push_back(current);
					current = 0;
				}
			}
			int minimum = 0;
			int limit   = n;
			sort(spaces2.begin(), spaces2.end());
			sort(spaces1.begin(), spaces1.end());
			if(!spaces2.empty()) {
				limit = *spaces2.begin();
				//两个都在2
				//两个都在2的最大
				const int a = (*spaces2.rbegin() - 2) / 3;
				minimum     = max(minimum, a);
				//两个分别在2的最大和第二大
				if(spaces2.size() > 1) {
					const int b = (spaces2[spaces2.size() - 2] - 1) / 2;
					minimum     = max(minimum, b);
				}
				//两个分别在2的最大和1的最大
				if(!spaces1.empty()) {
					const int a = (*spaces2.rbegin() - 1) / 2;
					int b       = *spaces1.rbegin() - 1;
					minimum     = max(minimum, min(a, b));
					//两个都在1的最大
					b       = (*spaces1.rbegin() - 2) / 2;
					minimum = max(minimum, b);
					//两个分别在1的最大和第二大
					if(spaces1.size() > 1) {
						const int a = *spaces1.begin() - 1;
						minimum     = max(minimum, a);
					}
				}
			} else {
				//两个分别在1的最大和第二大
				if(spaces1.size() > 1) {
					const int a = *spaces1.begin() - 1;
					minimum     = max(minimum, a);
				}
				//两个都在1的最大
				const int b = (*spaces1.rbegin() - 2) / 2;
				minimum     = max(minimum, b);
			}
			minimum = min(limit, minimum);
			cout << minimum + 1;
			return 0;
		}
	}// namespace acwing1659

	namespace acwing1714 {
		int main(istream &cin, ostream &cout) {
			unsigned int c[3];
			unsigned int m[3];
			for(int i = 0; i < 3; i++) {
				cin >> c[i] >> m[i];
			}
			for(int i = 0; i < 100; i++) {
				const int a = i % 3;
				const int b = (i + 1) % 3;
				if(m[a] + m[b] <= c[b]) {
					m[b] += m[a];
					m[a] = 0;
				} else {
					m[a] -= c[b] - m[b];
					m[b] = c[b];
				}
			}
			for(int i = 0; i < 3; i++) {
				cout << m[i] << endl;
			}
			return 0;
		}
	}// namespace acwing1714

	namespace acwing1695 {
		int main(istream &cin, ostream &cout) {
			bool nuts[3][3]         = {{true, false, false},
                               {false, true, false},
                               {false, false, true}};
			unsigned short score[3] = {0, 0, 0};
			unsigned short ans      = 0;
			unsigned short n;
			cin >> n;
			unsigned short a;
			unsigned short b;
			unsigned short g;
			for(unsigned short i = 0; i < n; i++) {
				cin >> a >> b >> g;
				a--;
				b--;
				g--;
				for(unsigned short j = 0; j < 3; j++) {
					swap(nuts[j][a], nuts[j][b]);
					if(nuts[j][g]) {
						score[j]++;
					}
				}
			}
			for(unsigned short i = 0; i < 3; i++) {
				ans = max(ans, score[i]);
			}
			cout << ans;
			return 0;
		}
	}// namespace acwing1695

	namespace acwing1683 {
		int main(istream &cin, ostream &cout) {
			int pos[3];
			int ans1;
			cin >> pos[0] >> pos[1] >> pos[2];
			sort(pos, pos + 3);
			const int g1 = pos[1] - pos[0];
			const int g2 = pos[2] - pos[1];
			if(g1 == 2 || g2 == 2) {
				ans1 = 1;
			} else {
				ans1 = 2;
			}
			int ans2 = max(g1, g2);
			ans2--;
			cout << ans1 << endl
			     << ans2;
			return 0;
		}
	}// namespace acwing1683

	namespace acwing4318 {
		int main(istream &cin, ostream &cout) {
			int x = 0;
			int y = 0;
			char op;
			int step = 0;
			set<pair<int, int>> s;
			s.insert(make_pair(0, 0));
			while(cin >> op) {
				step++;
				switch(op) {
					case 'U':
						x--;
						if(s.contains(make_pair(x, y)) ||
						   s.contains(make_pair(x - 1, y)) ||
						   s.contains(make_pair(x, y + 1)) ||
						   s.contains(make_pair(x, y - 1))) {
							cout << "NO";
							return 0;
						}
						break;
					case 'D':
						x++;
						if(s.contains(make_pair(x, y)) ||
						   s.contains(make_pair(x + 1, y)) ||
						   s.contains(make_pair(x, y + 1)) ||
						   s.contains(make_pair(x, y - 1))) {
							cout << "NO";
							return 0;
						}
						break;
					case 'L':
						y--;
						if(s.contains(make_pair(x, y)) ||
						   s.contains(make_pair(x, y - 1)) ||
						   s.contains(make_pair(x + 1, y)) ||
						   s.contains(make_pair(x - 1, y))) {
							cout << "NO";
							return 0;
						}
						break;
					case 'R':
						y++;
						if(s.contains(make_pair(x, y)) ||
						   s.contains(make_pair(x, y + 1)) ||
						   s.contains(make_pair(x + 1, y)) ||
						   s.contains(make_pair(x - 1, y))) {
							cout << "NO";
							return 0;
						}
						break;
					default:
						step--;
						break;
				}
				s.insert(make_pair(x, y));
			}
			if(step == 1) {
				cout << "YES";
				return 0;
			}
			if(abs(x) <= 1 && y == 0 || x == 0 && abs(y) <= 1) {
				cout << "NO";
			} else {
				cout << "YES";
			}
			return 0;
		}
	}// namespace acwing4318

	namespace acwing4319 {
		int main(istream &cin, ostream &cout) {
			unsigned int n;
			unsigned int k;
			cin >> n >> k;
			vector<unsigned int> a(n);
			vector<vector<pair<unsigned int, unsigned int>>> factors(n);
			map<vector<pair<unsigned int, unsigned int>>, unsigned int> factor_status_count;
			for(int i = 0; i < n; i++) {
				cin >> a[i];
				for(unsigned int factor = 2; factor * factor <= a[i]; factor++) {
					if(a[i] % factor != 0U) {
						continue;
					}
					unsigned int count = 0;
					while(a[i] % factor == 0) {
						a[i] /= factor;
						++count;
					}
					count %= k;
					if(count != 0) {
						factors[i].emplace_back(factor, count);
					}
				}
				if(a[i] != 1) {
					factors[i].emplace_back(a[i], 1);
				}
			}
			unsigned long long ans = 0;
			for(unsigned int i = 0; i < n; i++) {
				vector<pair<unsigned int, unsigned int>> factor_status;
				for(auto [factor, count]: factors[i]) {
					factor_status.emplace_back(factor, k - count);
				}
				ans += factor_status_count[factor_status];
				++factor_status_count[factors[i]];
			}
			cout << ans;
			return 0;
		}
	}// namespace acwing4319

	namespace acwing1470 {
		int main(istream &cin, ostream &cout) {
			char farm[10][10] = {};
			pair<int, int> b;
			pair<int, int> l;
			for(int i = 0; i < 10; i++) {
				for(int j = 0; j < 10; j++) {
					cin >> farm[i][j];
					if(farm[i][j] == 'B') {
						b = make_pair(i, j);
					} else if(farm[i][j] == 'L') {
						l = make_pair(i, j);
					}
				}
			}
			priority_queue<status> pq;
			pq.push(status(0, l, b));
			while(!pq.empty()) {
				status s = pq.top();
				pq.pop();
				if(s.current == b) {
					cout << s.len - 1;
					return 0;
				}
				pair<int, int> nexts[4] = {make_pair(s.current.first + 1, s.current.second),
				                           make_pair(s.current.first - 1, s.current.second),
				                           make_pair(s.current.first, s.current.second + 1),
				                           make_pair(s.current.first, s.current.second - 1)};
				for(const auto next: nexts) {
					if(0 <= next.first && next.first < 10 && 0 <= next.second && next.second < 10 && farm[next.first][next.second] != 'R') {
						pq.push(status(s.len + 1, next, b));
					}
				}
			}
			return 0;
		}

		bool status::operator<(const status &s) const { return this->get_weight() > s.get_weight(); }

		int status::get_weight() const { return len + abs(current.first - target.first) + abs(current.second - target.second); }
	}// namespace acwing1470

	namespace acwing1761 {
		int main(istream &cin, ostream &cout) {
			int x1[3];
			int y1[3];
			int x2[3];
			int y2[3];
			for(int i = 0; i < 3; i++) {
				cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
			}
			unsigned int area = 0;
			for(int i = 0; i < 2; i++) {
				area += abs(x2[i] - x1[i]) * abs(y2[i] - y1[i]);
				int x_1 = x1[2];
				int x_2 = x2[2];
				int y_1 = y1[2];
				int y_2 = y2[2];
				x_1     = max(x_1, x1[i]);
				x_2     = max(x_2, x1[i]);
				x_1     = min(x_1, x2[i]);
				x_2     = min(x_2, x2[i]);
				y_1     = max(y_1, y1[i]);
				y_2     = max(y_2, y1[i]);
				y_1     = min(y_1, y2[i]);
				y_2     = min(y_2, y2[i]);
				area -= abs(x_2 - x_1) * abs(y_2 - y_1);
			}
			cout << area;
			return 0;
		}
	}// namespace acwing1761

	namespace acwing1749 {
		int main(istream &cin, ostream &cout) {
			int x1[2];
			int x2[2];
			int y1[2];
			int y2[2];
			for(int i = 0; i < 2; i++) {
				cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
			}
			const unsigned int area = abs(x2[0] - x1[0]) * abs(y2[0] - y1[0]);
			int x_1                 = x1[1];
			int x_2                 = x2[1];
			int y_1                 = y1[1];
			int y_2                 = y2[1];
			x_1                     = max(x_1, x1[0]);
			x_2                     = max(x_2, x1[0]);
			x_1                     = min(x_1, x2[0]);
			x_2                     = min(x_2, x2[0]);
			y_1                     = max(y_1, y1[0]);
			y_2                     = max(y_2, y1[0]);
			y_1                     = min(y_1, y2[0]);
			y_2                     = min(y_2, y2[0]);
			if(x_2 == x_1 || y_2 == y_1) {
				//没有遮盖
				cout << area;
				return 0;
			}
			if(y_2 == y2[0] && y_1 == y1[0]) {
				//纵向填满
				cout << abs(abs(x2[0] - x1[0]) - abs(x_2 - x_1)) * abs(y_2 - y_1);
				return 0;
			}
			if(x_1 == x1[0] && x_2 == x2[0] && (y_1 == y1[0] || y_2 == y2[0])) {
				//横向填满
				cout << (x_2 - x_1) * max(y2[0] - y_2, y_1 - y1[0]);
				return 0;
			}
			cout << area;
			return 0;
		}
	}// namespace acwing1749

	namespace acwing1737 {
		int main(istream &cin, ostream &cout) {
			int a;
			int b;
			int x;
			int y;
			cin >> a >> b >> x >> y;
			const int d1 = abs(b - a);
			const int d2 = abs(a - x) + abs(b - y);
			const int d3 = abs(a - y) + abs(b - x);
			cout << min(d1, min(d2, d3));
			return 0;
		}
	}// namespace acwing1737

	namespace acwing1725 {
		int main(istream &cin, ostream &cout) {
			unordered_set<char> row[3];
			unordered_set<char> col[3];
			unordered_set<char> main_diagonal;
			unordered_set<char> leading_diagonal;
			unordered_set<char> win_1;
			auto hash = [](const pair<char, char> &p) {
				vector vec = {p.first, p.second};
				sort(vec.begin(), vec.end());
				unsigned int val = 0;
				for(auto &ch: vec) {
					ch -= 'A';
					val *= 26;
					val += ch;
				}
				return val;
			};
			unordered_set<pair<char, char>, decltype(hash)> win_2;
			char board[3][3];
			for(int i = 0; i < 3; i++) {
				for(int j = 0; j < 3; j++) {
					cin >> board[i][j];
					row[i].insert(board[i][j]);
					col[j].insert(board[i][j]);
				}
			}
			main_diagonal.insert(board[0][0]);
			main_diagonal.insert(board[1][1]);
			main_diagonal.insert(board[2][2]);
			leading_diagonal.insert(board[0][2]);
			leading_diagonal.insert(board[1][1]);
			leading_diagonal.insert(board[2][0]);
			for(int i = 0; i < 3; i++) {
				if(row[i].size() == 1) {
					win_1.insert(board[i][0]);
				} else if(row[i].size() == 2) {
					win_2.insert(make_pair(*row[i].begin(), *++row[i].begin()));
				}
				if(col[i].size() == 1) {
					win_1.insert(board[0][i]);
				} else if(col[i].size() == 2) {
					win_2.insert(make_pair(*col[i].begin(), *++col[i].begin()));
				}
			}
			if(main_diagonal.size() == 1) {
				win_1.insert(board[1][1]);
			} else if(main_diagonal.size() == 2) {
				win_2.insert(make_pair(*main_diagonal.begin(), *++main_diagonal.begin()));
			}
			if(leading_diagonal.size() == 1) {
				win_1.insert(board[1][1]);
			} else if(leading_diagonal.size() == 2) {
				win_2.insert(make_pair(*leading_diagonal.begin(), *++leading_diagonal.begin()));
			}
			cout << win_1.size() << endl
			     << win_2.size();
			return 0;
		}
	}// namespace acwing1725

	namespace acwing4394 {
		int main(istream &cin, ostream &cout) {
			unsigned n;
			unsigned k;
			cin >> n >> k;
			vector<unsigned> vec(n);
			for(unsigned i = 0; i < n; i++) {
				cin >> vec[i];
			}
			unsigned l     = 0;
			unsigned r     = 0;
			unsigned max_l = l;
			unsigned max_r = r;
			vector<unsigned> um(1000001, 0);
			unsigned size = 1;
			um[vec[0]]++;
			while(r < n) {
				while(size <= k) {
					r++;
					if(r < n) {
						if(um[vec[r]] == 0) {
							size++;
						}
						if(size > k) {
							r--;
							size--;
							break;
						}
						um[vec[r]]++;
					} else {
						cout << max_l + 1 << ' ' << max_r + 1;
						return 0;
					}
					max_r = r;
				}

				um[vec[l]]--;
				if(um[vec[l]] == 0) {
					size--;
				}
				l++;
				r++;
				if(r < n) {
					if(um[vec[r]] == 0) {
						size++;
					}
					um[vec[r]]++;
					if(size <= k) {
						max_l = l;
						max_r = r;
					}
				} else {
					cout << max_l + 1 << ' ' << max_r + 1;
					return 0;
				}
			}
			cout << max_l + 1 << ' ' << max_r + 1;
			return 0;
		}
	}// namespace acwing4394

	namespace acwing1812 {
		int main(istream &cin, ostream &cout) {
			int x[2][2];
			int y[2][2];
			for(int i = 0; i < 2; i++) {
				cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
			}
			const int x1   = min(x[0][0], x[1][0]);
			const int x2   = max(x[0][1], x[1][1]);
			const int y1   = min(y[0][0], y[1][0]);
			const int y2   = max(y[0][1], y[1][1]);
			const int edge = max(y2 - y1, x2 - x1);
			cout << edge * edge;
			return 0;
		}
	}// namespace acwing1812

	namespace acwing1800 {
		int main(istream &cin, ostream &cout) {
			unordered_map<string, unsigned> um;
			um["Bessie"]    = 0;
			um["Elsie"]     = 0;
			um["Daisy"]     = 0;
			um["Gertie"]    = 0;
			um["Annabelle"] = 0;
			um["Maggie"]    = 0;
			um["Henrietta"] = 0;
			unsigned short n;
			cin >> n;
			string name;
			unsigned amount;
			unsigned minimum = 0;
			while(n-- != 0U) {
				cin >> name >> amount;
				um[name] += amount;
				minimum = max(minimum, um[name]);
			}
			unsigned second_minimum = minimum;
			for(auto &[name, amount]: um) {
				minimum = min(minimum, amount);
			}
			for(auto &[name, amount]: um) {
				if(amount != minimum && amount < second_minimum) {
					second_minimum = amount;
				}
			}
			string ans;
			for(auto &[name, amount]: um) {
				if(second_minimum == amount) {
					if(ans.empty()) {
						ans = name;
					} else {
						cout << "Tie";
						return 0;
					}
				}
			}
			cout << ans;
			return 0;
		}
	}// namespace acwing1800

	namespace acwing1788 {
		int main(istream &cin, ostream &cout) {
			int n;
			unordered_map<int, int> um;
			cin >> n;
			int ans = 0;
			while(n-- != 0) {
				int id;
				int side;
				cin >> id >> side;
				if(!um.contains(id)) {
					um[id] = side;
				} else if(um[id] != side) {
					ans++;
					um[id] = side;
				}
			}
			cout << ans;
			return 0;
		}
	}// namespace acwing1788

	namespace acwing1775 {
		int main(istream &cin, ostream &cout) {
			int x;
			int y;
			cin >> x >> y;
			int step     = 1;
			unsigned ans = 0;
			int current  = x;
			while(current != y) {
				if((y - current) * (y - (x + step)) < 0) {
					ans += abs(y - current);
					cout << ans;
					return 0;
				}
				ans += abs(x + step - current);
				current = x + step;
				step *= -2;
			}
			cout << ans;
			return 0;
		}
	}// namespace acwing1775

	namespace acwing785 {
		void qs(vector<int> &vec, int l, int r) {
			if(l >= r) {
				return;
			}
			const int x = vec[l + r >> 1];
			int lp      = l - 1;
			int rp      = r + 1;
			while(lp < rp) {
				while(vec[++lp] < x) {}
				while(vec[--rp] > x) {}
				if(lp < rp) {
					swap(vec[lp], vec[rp]);
				}
			}
			qs(vec, l, rp);
			qs(vec, rp + 1, r);
		}

		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			vector<int> vec(n);
			for(int i = 0; i < n; i++) {
				cin >> vec[i];
			}
			qs(vec, 0, n - 1);
			for(int i = 0; i < n; i++) {
				cout << vec[i] << ' ';
			}
			return 0;
		}
	}// namespace acwing785

	/// \brief 788. 逆序对的数量
	namespace acwing788 {
		void ms(vector<int> &arr, int l, int r, int *ans) {
			if(l >= r) {
				return;
			}
			const int m = l + r >> 1;
			ms(arr, l, m, ans);
			ms(arr, m + 1, r, ans);
			int i = l;
			int j = m + 1;
			int p = 0;
			vector<int> tmp(r - l + 1);
			while(i <= m && j <= r) {
				if(arr[i] <= arr[j]) {
					tmp[p++] = arr[i++];
				} else {
					tmp[p++] = arr[j++];
					*ans += m - i + 1;
				}
			}
			while(i <= m) {
				tmp[p++] = arr[i++];
			}
			while(j <= r) {
				tmp[p++] = arr[j++];
			}
			for(int i = 0; i < p; i++) {
				arr[l + i] = tmp[i];
			}
		}

		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			vector<int> vec(n);
			for(int i = 0; i < n; i++) {
				cin >> vec[i];
			}
			int ans = 0;
			ms(vec, 0, n - 1, &ans);
			cout << ans;
			return 0;
		}
	}// namespace acwing788

	namespace acwing789 {

		long bfl(const vector<long> &vec, long target) {
			int l = 0;
			int r = vec.size() - 1;
			while(l < r) {
				const int m = (l + r + 1) / 2;
				if(vec[m] <= target) {
					l = m;
				} else {
					r = m - 1;
				}
			}
			if(vec[l] != target) {
				return -1;
			}
			return l;
		}

		long bfr(const vector<long> &vec, long target) {
			int l = 0;
			int r = vec.size() - 1;
			while(l < r) {
				const int m = (l + r) / 2;
				if(vec[m] < target) {
					l = m + 1;
				} else {
					r = m;
				}
			}
			if(vec[l] != target) {
				return -1;
			}
			return l;
		}

		int main(istream &cin, ostream &cout) {
			long n;
			long q;
			cin >> n >> q;
			vector<long> vec(n);
			for(long i = 0; i < n; i++) {
				cin >> vec[i];
			}
			for(long i = 0; i < q; i++) {
				long k;
				cin >> k;
				cout << bfr(vec, k) << ' ' << bfl(vec, k) << endl;
			}
			return 0;
		}
	}// namespace acwing789

	namespace acwing1866 {
		int main(istream &cin, ostream &cout) {
			int a;
			int b;
			int c;
			int d;
			cin >> a >> b >> c >> d;
			const int ab    = b - a;
			const int cd    = d - c;
			const int dup_d = min(b, max(a, d));
			const int dup_c = min(b, max(a, c));
			const int sum   = ab + cd - (dup_d - dup_c);
			cout << sum;
			return 0;
		}
	}// namespace acwing1866

	namespace acwing1854 {
		int main(istream &cin, ostream &cout) {
			int b[4][2];
			for(int i = 0; i < 4; i++) {
				for(int j = 0; j < 2; j++) {
					cin >> b[i][j];
				}
			}
			int ans[3];
			ans[2] = b[3][1] - b[3][0];
			b[2][0] -= ans[2];
			ans[1] = b[2][1] - b[2][0];
			b[1][0] -= ans[1];
			ans[0] = b[1][1] - b[1][0];
			for(int i = 0; i < 3; i++) {
				cout << ans[i] << endl;
			}
			return 0;
		}
	}// namespace acwing1854

	namespace acwing4397 {
		bool cmp(const pair<int, int> &a, const pair<int, int> &b) { return a.first > b.first; }

		int main(istream &cin, ostream &cout) {
			int n;
			int k;
			cin >> n >> k;
			vector<int> a(n);
			vector<int> b(n);
			vector<pair<int, int>> a_b(n);
			for(int i = 0; i < n; i++) {
				cin >> a[i];
			}
			for(int i = 0; i < n; i++) {
				cin >> b[i];
				a_b[i] = make_pair(a[i] - b[i], i);
			}
			sort(a_b.begin(), a_b.end(), cmp);
			for(int i = 0; i < k; i++) {
				if(a_b[i].first > 0) {
					a[a_b[i].second] = b[a_b[i].second];
				} else {
					break;
				}
			}
			long long ans = 0;
			for(int i = 0; i < n; i++) {
				ans += a[i];
			}
			cout << ans;
			return 0;
		}
	}// namespace acwing4397

	namespace acwing4398 {
		void TrieNode::insert(const string &str, int start, string *origin) {
			if(!this->nexts.contains(str[start])) {
				this->nexts[str[start]] = new TrieNode(str[start]);
			}
			if(origin != nullptr) {
				this->nexts[str[start]]->origin.insert(origin);
			}
			if(str.length() - start != 1) {
				this->nexts[str[start]]->insert(str, start + 1, origin);
			}
		}

		TrieNode *TrieNode::search(const string &str, int start) {
			this->ch = this->ch;
			if(this->nexts.contains(str[start])) {
				if(start + 1 == str.length()) {
					return this->nexts[str[start]];
				}
				return this->nexts[str[start]]->search(str, start + 1);
			}
			return nullptr;
		}

		TrieNode::~TrieNode() {
			for(const auto [k, v]: this->nexts) {
				delete v;
			}
		}

		int main(istream &cin, ostream &cout) {
			int n;
			int q;
			cin >> n;
			TrieNode tn(0);
			vector<string> f(n);
			for(int i = 0; i < n; i++) {
				cin >> f[i];
				for(int j = 0; j < f[i].length(); ++j) {
					tn.insert(f[i], j, &f[i]);
				}
			}
			cin >> q;
			for(int i = 0; i < q; i++) {
				string s;
				cin >> s;
				const TrieNode *node = tn.search(s, 0);
				if(node == nullptr) {
					cout << "0 -" << endl;
				} else {
					cout << node->origin.size() << ' ' << **node->origin.begin() << endl;
				}
			}
			return 0;
		}
	}// namespace acwing4398

	namespace acwing1842 {
		int main(istream &cin, ostream &cout) {
			int x;
			int y;
			int m;
			cin >> x >> y >> m;
			int ans = 0;
			for(int i = 0; y * i <= m; ++i) {
				int amount = y * i;
				amount += (m - amount) / x * x;
				ans = max(ans, amount);
			}
			cout << ans;
			return 0;
		}
	}// namespace acwing1842

	namespace acwing1824 {
		int main(istream &cin, ostream &cout) {
			int n;
			int k;
			cin >> n >> k;
			vector vec(10010, 0);
			unsigned int size;
			for(int i = 0; i < n; i++) {
				cin >> size;
				vec[size]++;
			}
			vector sum(10010, 0);
			for(int i = 1; i < 10010; i++) {
				sum[i] = sum[i - 1] + vec[i];
			}
			int ans = 0;
			for(int i = 1; i + k < 10010; i++) {
				ans = max(ans, sum[i + k] - sum[i - 1]);
			}
			cout << ans;
			return 0;
		}
	}// namespace acwing1824

	namespace acwing800 {
		int main(istream &cin, ostream &cout) {
			int n;
			int m;
			int x;
			cin >> n >> m >> x;
			vector<int> a(n);
			vector<int> b(m);
			for(int i = 0; i < n; i++) {
				cin >> a[i];
			}
			for(int i = 0; i < m; i++) {
				cin >> b[i];
			}
			int pa = 0;
			int pb = m - 1;
			while(a[pa] + b[pb] < x) {
				++pa;
			}
			for(; pa < n; pa++) {
				if(a[pa] + b[pb] == x) {
					cout << pa << ' ' << pb;
					return 0;
				}
				while(a[pa] + b[pb] > x) {
					--pb;
					if(a[pa] + b[pb] == x) {
						cout << pa << ' ' << pb;
						return 0;
					}
				}
			}
			return 0;
		}
	}// namespace acwing800

	namespace acwing2816 {
		int main(istream &cin, ostream &cout) {
			int n;
			int m;
			cin >> n >> m;
			vector<int> a(n);
			vector<int> b(m);
			for(int i = 0; i < n; i++) {
				cin >> a[i];
			}
			for(int i = 0; i < m; i++) {
				cin >> b[i];
			}
			int pa = 0;
			int pb = 0;
			for(; pa < n; ++pa) {
				while(pb < m && b[pb] != a[pa]) {
					++pb;
				}
				if(pb == m) {
					cout << "No";
					return 0;
				}
				++pb;
			}
			cout << "Yes";
			return 0;
		}
	}// namespace acwing2816

	namespace acwing1902 {
		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			vector<pair<int, int>> checkpoints(n);
			vector<int> d(n - 1);
			for(int i = 0; i < n; i++) {
				int x;
				int y;
				cin >> x >> y;
				checkpoints[i] = make_pair(x, y);
			}
			int sum = 0;
			for(int i = 0; i < n - 1; i++) {
				const auto &[x1, y1] = checkpoints[i];
				const auto &[x2, y2] = checkpoints[i + 1];
				d[i]                 = abs(x2 - x1) + abs(y2 - y1);
				sum += d[i];
			}
			int max_diff = 0;
			for(int i = 1; i < n - 1; i++) {
				const auto &[x1, y1] = checkpoints[i - 1];
				const auto &[x2, y2] = checkpoints[i + 1];
				const int dist       = abs(x2 - x1) + abs(y2 - y1);
				int diff             = d[i - 1] + d[i] - dist;
				max_diff             = max(max_diff, diff);
			}
			cout << sum - max_diff;
			return 0;
		}
	}// namespace acwing1902

	namespace acwing3302 {
		int main(istream &cin, ostream &cout) {
			stack<int> nums;
			stack<char> ops;
			char ch;
			int num;
			while((ch = cin.peek()) > 0) {
				if(isdigit(ch) != 0) {
					cin >> num;
					if(!ops.empty() && ops.top() == '*') {
						num = nums.top() * num;
						nums.pop();
						nums.push(num);
						ops.pop();
					} else if(!ops.empty() && ops.top() == '/') {
						num = nums.top() / num;
						nums.pop();
						nums.push(num);
						ops.pop();
					} else {
						nums.push(num);
					}
				} else {
					cin >> ch;
					if(ch == ')') {
						vector<char> vec_op;
						vector<int> vec_num;
						vec_num.push_back(nums.top());
						nums.pop();
						while(ops.top() != '(') {
							vec_op.push_back(ops.top());
							vec_num.push_back(nums.top());
							ops.pop();
							nums.pop();
						}
						ops.pop();
						for(int i = vec_op.size() - 1; i >= 0; --i) {
							if(vec_op[i] == '+') {
								vec_num.back() += vec_num[i];
							} else if(vec_op[i] == '-') {
								vec_num.back() -= vec_num[i];
							} else {
								return 1;
							}
						}
						num = vec_num.back();
						if(!ops.empty() && ops.top() == '*') {
							num = nums.top() * num;
							nums.pop();
							nums.push(num);
							ops.pop();
						} else if(!ops.empty() && ops.top() == '/') {
							num = nums.top() / num;
							nums.pop();
							nums.push(num);
							ops.pop();
						} else {
							nums.push(num);
						}
					} else {
						ops.push(ch);
					}
				}
			}
			vector<char> vec_op;
			vector<int> vec_num;
			vec_num.push_back(nums.top());
			nums.pop();
			while(!ops.empty()) {
				vec_op.push_back(ops.top());
				vec_num.push_back(nums.top());
				ops.pop();
				nums.pop();
			}
			for(int i = vec_op.size() - 1; i >= 0; --i) {
				if(vec_op[i] == '+') {
					vec_num.back() += vec_num[i];
				} else if(vec_op[i] == '-') {
					vec_num.back() -= vec_num[i];
				} else {
					return 1;
				}
			}
			cout << vec_num.back();
			return 0;
		}
	}// namespace acwing3302

	namespace acwing831 {
		int main(istream &cin, ostream &cout) {
			int n;
			int m;
			string p;
			string s;
			cin >> n >> p >> m >> s;
			const vector<int> next = get_next(p);
			int ip                 = 0;
			int is                 = 0;
			while(ip < n && is < m) {
				if(p[ip] == s[is]) {
					if(ip == n - 1) {
						//整串匹配成功
						cout << is - n + 1 << ' ';
						ip = next[ip - 1];
					} else {
						//当前匹配成功
						ip++;
						is++;
					}
				} else {
					if(ip == 0) {
						//开头就匹配失败
						is++;
					} else {
						//匹配失败，但不在开头
						ip = next[ip - 1];
					}
				}
			}
			return 0;
		}

		vector<int> get_next(const string &str) {
			const int n = str.length();
			vector next(n, 0);
			int i = 1;
			int j = 0;
			while(i < n && j < n) {
				if(str[i] == str[j]) {
					//匹配成功
					next[i] = j + 1;
					j++;
					i++;
				} else {
					if(j == 0) {
						//开头就匹配失败
						i++;
					} else {
						//匹配失败，但不在开头
						j = next[j - 1];
					}
				}
			}
			return next;
		}
	}// namespace acwing831

	namespace acwing1892 {
		int main(istream &cin, ostream &cout) {
			int a;
			int b;
			int n;
			cin >> a >> b >> n;
			int ans = 1001;
			for(int i = 0; i < n; i++) {
				int price;
				int num;
				bool flag = false;
				cin >> price >> num;
				int city;
				for(int j = 0; j < num; j++) {
					cin >> city;
					if(city == a) {
						flag = true;
					} else if(flag && city == b) {
						ans = min(ans, price);
					}
				}
			}
			if(ans == 1001) {
				cout << -1;
			} else {
				cout << ans;
			}
			return 0;
		}
	}// namespace acwing1892

	namespace acwing1883 {
		int main(istream &cin, ostream &cout) {
			string s;
			string t;
			string res;
			cin >> s >> t;
			const int slen = s.length();
			const int tlen = t.length();
			//一边添加一边判断
			for(int i = 0; i < slen; i++) {
				res += s[i];
				//当添加到长度大于等于t字符串时，开始比较
				//每次从末尾向前匹配
				while(res.length() >= tlen && res.substr(res.length() - tlen, tlen) == t) {
					//存在t字符串，则删除
					res.erase(res.begin() + res.length() - tlen, res.end());
				}
			}
			cout << res;
			return 0;
		}
	}// namespace acwing1883

	namespace acwing1995 {
		int main(istream &cin, ostream &cout) {
			int b;
			int e;
			cin >> b >> e;
			vector<int> pos_b;
			vector<int> pos_e;
			pos_b.push_back(0);
			pos_e.push_back(0);
			while(b-- != 0) {
				char dir;
				int dist;
				cin >> dist >> dir;
				if(dir == 'L') {
					for(int i = 0; i < dist; i++) {
						pos_b.push_back(pos_b.back() - 1);
					}
				} else {
					for(int i = 0; i < dist; i++) {
						pos_b.push_back(pos_b.back() + 1);
					}
				}
			}
			while(e-- != 0) {
				char dir;
				int dist;
				cin >> dist >> dir;
				if(dir == 'L') {
					for(int i = 0; i < dist; i++) {
						pos_e.push_back(pos_e.back() - 1);
					}
				} else {
					for(int i = 0; i < dist; i++) {
						pos_e.push_back(pos_e.back() + 1);
					}
				}
			}
			const int t = max(pos_e.size(), pos_b.size());
			int ans     = 0;
			bool flag   = true;
			for(int i = 0; i < t; i++) {
				const int pe = i < pos_e.size() ? pos_e[i] : pos_e.back();
				const int pb = i < pos_b.size() ? pos_b[i] : pos_b.back();
				if(pe == pb) {
					if(!flag) {
						ans++;
					}
					flag = true;
				} else {
					flag = false;
				}
			}
			cout << ans;
			return 0;
		}
	}// namespace acwing1995

	namespace acwing143 {
		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			vector<string> vec(n);
			TrieNode tn;
			for(int j = 0; j < n; j++) {
				unsigned a;
				cin >> a;
				ostringstream oss;
				for(int i = 30; i >= 0; i--) {
					oss << ((a & 1 << i) != 0u ? '1' : '0');
				}
				string str = oss.str();
				vec[j]     = str;
				tn.insert(str, 0);
			}
			unsigned maximum = 0;
			for(const auto &str: vec) {
				const TrieNode *current = &tn;
				unsigned ans            = 0;
				for(int i = 0; i <= 30; i++) {
					ans <<= 1;
					if(current->next[(str[i] - '0') == 0] != nullptr) {
						current = current->next[(str[i] - '0') == 0];
						ans += 1;
					} else {
						current = current->next[str[i] - '0'];
					}
				}
				maximum = max(maximum, ans);
			}
			cout << maximum;
			return 0;
		}

		void TrieNode::insert(const string &str, int i) {
			if(this->next[str[i] - '0'] == nullptr) {
				this->next[str[i] - '0']      = new TrieNode();
				this->next[str[i] - '0']->val = str[i] - '0';
			}
			if(i + 1 < str.length()) {
				this->next[str[i] - '0']->insert(str, i + 1);
			}
		}
	}// namespace acwing143

	namespace acwing837 {
		int main(istream &cin, ostream &cout) {
			int n;
			int m;
			cin >> n >> m;
			UnionFind uf(n);
			while((m--) != 0) {
				string op;
				int a;
				int b;
				cin >> op;
				if(op == "C") {
					cin >> a >> b;
					uf.unite(a - 1, b - 1);
				} else if(op == "Q1") {
					cin >> a >> b;
					cout << (uf.same(a - 1, b - 1) ? "Yes" : "No") << endl;
				} else {
					cin >> a;
					cout << uf.get_size(a - 1) << endl;
				}
			}
			return 0;
		}
	}// namespace acwing837

	namespace acwing240 {
		int main(istream &cin, ostream &cout) {
			int n;
			int k;
			cin >> n >> k;
			UnionFind uf(n);
			int ans = 0;
			while((k--) != 0) {
				char d;
				int x;
				int y;
				cin >> d >> x >> y;
				if(x > n || y > n) {
					ans++;
					continue;
				}
				x--;
				y--;
				const int px = uf.find(x);
				const int py = uf.find(y);
				if(d == '1') {
					if(px == py) {
						if((uf.dist[x] - uf.dist[y]) % 3 != 0) {
							ans++;
						}
					} else {
						uf.parent[px] = py;
						uf.dist[px]   = uf.dist[y] - uf.dist[x];
					}
				} else {
					if(x == y) {
						ans++;
						continue;
					}
					if(px == py) {
						if((uf.dist[x] - uf.dist[y] - 1) % 3 != 0) {
							ans++;
						}
					} else {
						uf.parent[px] = py;
						uf.dist[px]   = uf.dist[y] - uf.dist[x] + 1;
					}
				}
			}
			cout << ans;
			return 0;
		}

		UnionFind::UnionFind(int n) {
			parent = vector<int>(n);
			dist   = vector(n, 0);
			for(int i = 0; i < n; i++) {
				parent[i] = i;
			}
		}

		int UnionFind::find(int x) {
			if(parent[x] != x) {
				const int tmp = find(parent[x]);
				dist[x] += dist[parent[x]];
				parent[x] = tmp;
			}
			return parent[x];
		}
	}// namespace acwing240
}// namespace acwing
