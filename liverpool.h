//
// Created by wangzhiheng on 26/09/2025.
//

#ifndef PROBLEMSCPP_COMO526_H
#define PROBLEMSCPP_COMO526_H

#include <iosfwd>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

namespace liverpool {
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

	namespace allpairspath {
		struct edge {
			int u, v, w;
		};
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace allpairspath

	namespace weakvertices {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	namespace clockpictures {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	namespace ceremony {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	namespace doctorkattis {
		struct cat {
			string name;
			int order;
			int infection_level;

			bool operator<(const cat &c2) const;
		};
		void arrive_at_clinic(string cat_name, int infection_level);
		void update_infection_level(string cat_name, int increase_infection);
		void treat(string cat_name);
		string query();
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace doctorkattis

	namespace lobby {
		int main_1(istream &cin, ostream &cout);
		int main_2(istream &cin, ostream &cout);
	}// namespace lobby

	namespace printing_department {
		void remove(vector<vector<int>> &cnt, const vector<string> &input, int x, int y, int w, int h, int &ans);
		int main_1(istream &cin, ostream &cout);
		int main_2(istream &cin, ostream &cout);
	}// namespace printing_department

	namespace secret_entrance {
		int main_1(istream &cin, ostream &cout);
		int main_2(istream &cin, ostream &cout);
	}// namespace secret_entrance

	namespace cafeteria {
		int main_1(istream &cin, ostream &cout);
		int main_2(istream &cin, ostream &cout);
	}// namespace cafeteria

	namespace gift_shop {
		int main_1(istream &cin, ostream &cout);
		int main_2(istream &cin, ostream &cout);
	}// namespace gift_shop

	namespace trash_compactor {
		int main_1(istream &cin, ostream &cout, int n, int nl);
		int main_2(istream &cin, ostream &cout);
	}// namespace trash_compactor

	namespace movie_theater {
		int main_1(istream &cin, ostream &cout);
		int main_2(istream &cin, ostream &cout);
	}// namespace movie_theater

	namespace factory {
		int main_1(istream &cin, ostream &cout);
	}// namespace factory

	namespace reactor {
		int main_1(istream &cin, ostream &cout);
		int main_2(istream &cin, ostream &cout);
	}// namespace reactor
}// namespace liverpool

#endif//PROBLEMSCPP_COMO526_H
