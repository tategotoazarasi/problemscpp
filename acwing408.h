//
// Created by tategotoazarasi on 24-5-7.
//

#ifndef PROBLEMSCPP_ACWING408_H
#define PROBLEMSCPP_ACWING408_H

#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

namespace acwing {
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x): val(x), left(NULL), right(NULL) {}
	};

	namespace acwing3378 {
		typedef struct student {
			string name;
			int score;
		} student;
		int main(istream & /*cin*/, ostream & /*cout*/);
	};// namespace acwing3378

	namespace acwing3376 {
		typedef struct student {
			string id;
			int id_numeric;
			int score;
		} student;
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing3376

	namespace acwing3374 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing3374

	namespace acwing3757 {
		struct ListNode {
			int val;
			struct ListNode *next;
		};
		void rearrangedList(struct ListNode *head);
		void reverse(struct ListNode *head);
	}// namespace acwing3757

	namespace acwing3607 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	namespace acwing3573 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	namespace acwing3302_408 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	namespace acwing3766 {
		int pathSum(TreeNode *root, int level);
		int pathSum(TreeNode *root);
	}// namespace acwing3766
}// namespace acwing

#endif//PROBLEMSCPP_ACWING408_H
