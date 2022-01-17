#include "luogu.h"
#include <iostream>
#include <unordered_set>

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
}// namespace luogu
