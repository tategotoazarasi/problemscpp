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

	namespace acwing148 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	namespace acwing836_408 {
		int find(int x);
		void merge(int x, int y);
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing836_408

	namespace acwing18 {
		TreeNode *rebuild(vector<int> &inorder, int in_begin, int in_end, vector<int> &preorder, int pre_begin, int pre_end);
		TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
	}// namespace acwing18

	/**
	 * @brief 3786. 二叉排序树
	 */
	namespace acwing3786 {
		void insert(TreeNode *&root, int x);
		void remove(TreeNode *&root, int x);
		int get_pre(TreeNode *root, int x);
		int get_suc(TreeNode *root, int x);
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing3786

	/**
	 * @brief 149. 荷马史诗
	 */
	namespace acwing149 {
		class huff_tree {
		public:
			u_int64_t val;
			u_int64_t height;
			vector<huff_tree *> children;
			huff_tree(u_int64_t val, u_int64_t height, u_int64_t k): val(val), height(height), children(k, nullptr){};
		};
		struct Compare {
			bool operator()(huff_tree *const &a, huff_tree *const &b);
		};
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing149

	/**
	 * @brief 831. KMP字符串
	 */
	namespace acwing831_408 {
		vector<int> get_next(string s);
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing831_408

	/**
	 * @brief 3385. 玛雅人的密码
	 */
	namespace acwing3385 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3429. 全排列
	 */
	namespace acwing3429 {
		void dfs(vector<char> &stk, int p, ostream &, string s);
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing3429
}// namespace acwing

#endif//PROBLEMSCPP_ACWING408_H
