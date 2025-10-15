//
// Created by wangzhiheng on 26/09/2025.
//

#ifndef PROBLEMSCPP_COMO526_H
#define PROBLEMSCPP_COMO526_H

#include <iosfwd>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

namespace comp526 {
	namespace stable_matching {
		class Student;
		class Company;
		class Student {
		public:
			Student(int id): id(id) {};
			int id               = -1;
			int current_priority = 0;
			unordered_map<int, Company *> priority_c;
			unordered_map<Company *, int> c_priority;
			Company *matched_company = nullptr;
		};

		class Company {
		public:
			Company(int id): id(id) {};
			int id = -1;
			unordered_map<Student *, int> priority;
			Student *matched_student = nullptr;
			unordered_set<Student *> proposed_students;
		};

		class Solution {
		private:
			vector<Student *> students;
			vector<Company *> companies;

		public:
			vector<int> match(vector<vector<int>>, vector<vector<int>>);
		};
	}// namespace stable_matching

	namespace oddecho {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	namespace recount {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	namespace set {
		class card {
		public:
			int id;
			char f[4];
			card(int id, string s);
		};
		class cardset {
		public:
			unsigned short mask = -1;
			int cnt             = 0;
			unordered_set<card *> cards{};
			cardset() = default;
			cardset(card *c);
			void insert(card *c);
		};

		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace set

	namespace plantingtrees {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	namespace snowflakes {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	namespace amalgram {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	namespace wheresmyinternet {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	namespace oddities {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	namespace countingchocolate {
		bool solve(const vector<int> &a, int john, int sam, int sp, int target);
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace countingchocolate

	namespace grid {
		struct state {
		public:
			int x;
			int y;
			int step;
		};
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace grid
}// namespace comp526

#endif//PROBLEMSCPP_COMO526_H
