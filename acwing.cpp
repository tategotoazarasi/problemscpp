#include "acwing.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
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
		string str1, str2, str3;
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
		vector<short> vec = vector<short>();
		vec.resize(3);
		cin >> vec[0];
		cin >> vec[1];
		cin >> vec[2];
		vector<short> sorted = vector<short>(vec);
		sort(sorted.begin(), sorted.end());
		for(auto num: sorted) {
			cout << num << endl;
		}
		cout << endl;
		for(auto num: vec) {
			cout << num << endl;
		}
		return 0;
	}
}// namespace acwing
