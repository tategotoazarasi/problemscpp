#include "luogu.h"
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

namespace luogu {
	int P1001::main(istream &cin, ostream &cout) {
		unsigned int a;
		unsigned int b;
		cin >> a >> b;
		cout << a + b;
		return 0;
	}

	int P1000::main(istream & /*cin*/, ostream &cout) {
		cout << "                ********\n"
		        "               ************\n"
		        "               ####....#.\n"
		        "             #..###.....##....\n"
		        "             ###.......######              ###            ###\n"
		        "                ...........               #...#          #...#\n"
		        "               ##*#######                 #.#.#          #.#.#\n"
		        "            ####*******######             #.#.#          #.#.#\n"
		        "           ...#***.****.*###....          #...#          #...#\n"
		        "           ....**********##.....           ###            ###\n"
		        "           ....****    *****....\n"
		        "             ####        ####\n"
		        "           ######        ######\n"
		        "##############################################################\n"
		        "#...#......#.##...#......#.##...#......#.##------------------#\n"
		        "###########################################------------------#\n"
		        "#..#....#....##..#....#....##..#....#....#####################\n"
		        "##########################################    #----------#\n"
		        "#.....#......##.....#......##.....#......#    #----------#\n"
		        "##########################################    #----------#\n"
		        "#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#\n"
		        "##########################################    ############";
		return 0;
	}

	int P1008::main(istream & /*cin*/, ostream &cout) {
		for(unsigned short i = 1; i <= 3; i++) {
			for(unsigned short j = 1; j <= 9; j++) {
				if(j == i) {
					continue;
				}
				for(unsigned short k = 1; k <= 9; k++) {
					if(k == i || k == j || k * 2 % 10 == j || k * 2 % 10 == i || k * 3 % 10 == j || k * 3 % 10 == i || k == 5) {
						continue;
					}
					const unsigned short num = 100 * i + 10 * j + k;
					if(num > 333) {
						continue;
					}
					unsigned short num2 = 2 * num;
					unsigned short num3 = 3 * num;
					auto um             = unordered_set<unsigned short>();
					um.insert(i);
					um.insert(j);
					um.insert(k);
					unsigned short n = num2 % 10;

					if(um.contains(n) || n == 0) {
						continue;
					}
					um.insert(n);
					num2 /= 10;
					n = num2 % 10;
					if(um.contains(n) || n == 0) {
						continue;
					}
					um.insert(n);
					num2 /= 10;
					n = num2 % 10;
					if(um.contains(n) || n == 0) {
						continue;
					}
					um.insert(n);

					n = num3 % 10;
					if(um.contains(n) || n == 0) {
						continue;
					}
					um.insert(n);
					num3 /= 10;
					n = num3 % 10;
					if(um.contains(n) || n == 0) {
						continue;
					}
					um.insert(n);
					num3 /= 10;
					n = num3 % 10;
					if(um.contains(n) || n == 0) {
						continue;
					}
					um.insert(n);
					cout << num << " " << num * 2 << " " << num * 3 << endl;
				}
			}
		}
		return 0;
	}

	int P1002::main(istream &cin, ostream &cout) {
		int n;
		int m;
		int cx;
		int cy;
		cin >> n >> m >> cx >> cy;
		unsigned long long board[21][21] = {};
		board[0][0]                      = 1;
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= m; j++) {
				if(abs(cx - i) * abs(cy - j) == 2 || i == cx && j == cy) {
					board[i][j] = 0;
					continue;
				}
				if(i - 1 >= 0) {
					board[i][j] += board[i - 1][j];
				}
				if(j - 1 >= 0) {
					board[i][j] += board[i][j - 1];
				}
			}
		}
		cout << board[n][m];
		return 0;
	}

	int P1003::main(istream &cin, ostream &cout) {
		auto as = vector<unsigned int>();
		auto bs = vector<unsigned int>();
		auto gs = vector<unsigned int>();
		auto ks = vector<unsigned int>();
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			unsigned int a;
			unsigned int b;
			unsigned int g;
			unsigned int k;
			cin >> a >> b >> g >> k;
			as.push_back(a);
			bs.push_back(b);
			gs.push_back(g);
			ks.push_back(k);
		}
		unsigned int x;
		unsigned int y;
		cin >> x >> y;
		for(int i = n - 1; i >= 0; i--) {
			if(as[i] <= x && x <= as[i] + gs[i] && bs[i] <= y && y <= bs[i] + ks[i]) {
				cout << i + 1;
				return 0;
			}
		}
		cout << -1;
		return 0;
	}

	int P5703::main(istream &cin, ostream &cout) {
		unsigned long a, b;
		cin >> a >> b;
		cout << a * b;
		return 0;
	}

	int P5704::main(istream &cin, ostream &cout) {
		char ch;
		cin >> ch;
		cout << char(toupper(ch));
		return 0;
	}
}// namespace luogu
