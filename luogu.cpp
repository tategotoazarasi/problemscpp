//
// Created by tategotoazarasi on 2022/1/2.
//

#include "luogu.h"
#include<iostream>
#include<cmath>

using namespace std;

namespace luogu {
	int T210229::main(istream& cin, ostream& cout) {
		int n;
		int counta = 0;
		cin >> n;
		auto strs = new string[n];
		auto indexes = new int[n];

		for (int i = 0; i < n; i++) {
			cin >> strs[i];
			indexes[i] = 0;
		}
		char current = strs[0][0];
		indexes[0] = 1;
		bool end = false;
		while (!end) {
			end = true;
			bool change = true;
			for (int i = 0; i < n; i++) {
				if (indexes[i] < strs[i].size()) {
					if (strs[i][indexes[i]] == current) {
						counta++;
						indexes[i]++;
						change = false;
					}
					end = false;
				}
			}
			if (change && !end) {
				counta--;
				current = (current == '0') ? '1' : '0';
			}
		}

		int countb = 0;
		for (int i = 0; i < n; i++) {
			indexes[i] = 0;
		}
		current = '0';
		if (strs[0][0] == '0') {
			current = '1';
		}
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (strs[i][0] == current) {
				indexes[i] = 1;
				flag = true;
				break;
			}
		}
		if (flag) {
			end = false;
			while (!end) {
				end = true;
				bool change = true;
				for (int i = 0; i < n; i++) {
					if (indexes[i] < strs[i].size()) {
						if (strs[i][indexes[i]] == current) {
							countb++;
							indexes[i]++;
							change = false;
						}
						end = false;
					}
				}
				if (change && !end) {
					countb--;
					current = (current == '0') ? '1' : '0';
				}
			}
		}

		cout << max(counta, countb);

		return 0;
	}
}