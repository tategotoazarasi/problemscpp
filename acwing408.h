//
// Created by tategotoazarasi on 24-5-7.
//

#ifndef PROBLEMSCPP_ACWING408_H
#define PROBLEMSCPP_ACWING408_H

#include "templates.h"
#include <iostream>
#include <map>
#include <set>
#include <stack>
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
			huff_tree(u_int64_t val, u_int64_t height, u_int64_t k): val(val), height(height), children(k, nullptr) {};
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

	/**
	 * @brief 858. Prim算法求最小生成树
	 */
	namespace acwing858_408 {
		// Custom hash function for pair<int, int>
		struct pair_hash {
			template<class T1, class T2>
			size_t operator()(const pair<T1, T2> &p) const;
		};

		// Custom equal function for pair<int, int>
		struct pair_equal {
			template<class T1, class T2>
			bool operator()(const pair<T1, T2> &p1, const pair<T1, T2> &p2) const;
		};

		// Custom comparator for tuple<int, int, int>
		struct tuple_compare {
			bool operator()(const tuple<int, int, int> &t1, const tuple<int, int, int> &t2);
		};
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing858_408

	/**
	 * @brief 849. Dijkstra求最短路 I
	 */
	namespace acwing849_408 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 854. Floyd求最短路
	 */
	namespace acwing854_408 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 848. 有向图的拓扑序列
	 */
	namespace acwing848_408 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3402. 等差数列
	 */
	namespace acwing3402 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3472. 八皇后
	 */
	namespace acwing3472 {
		void dfs(vector<vector<bool>> board, int current_row, vector<string> &ans, vector<int> &ans_stk);
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing3472

	/**
	 * @brief 3439. 首字母大写
	 */
	namespace acwing3439 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3379. 反序输出
	 */
	namespace acwing3379 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3390. 特殊乘法
	 */
	namespace acwing3390 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3397. 众数
	 */
	namespace acwing3397 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3426. 糖果分享游戏
	 */
	namespace acwing3426 {
		bool ended(vector<int> &candy);
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing3426

	/**
	 * @brief 3406. 日志排序
	 */
	namespace acwing3406 {
		struct task {
			string name;
			string date_time;
			double duration;
			string raw_line;
		};
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing3406

	/**
	 * @brief 3447. 子串计算
	 */
	namespace acwing3447 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3820. 未出现过的最小正整数
	 */
	namespace acwing3820 {
		int findMissMin(vector<int> &nums);
	}

	/**
	 * @brief 840. 模拟散列表
	 */
	namespace acwing840_408 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3542. 查找
	 */
	namespace acwing3542 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3581. 单词识别
	 */
	namespace acwing3581 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 785. 快速排序
	 */
	namespace acwing785_408 {
		void qs(vector<int> &vec, int l, int r);
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing785_408

	/**
	 * @brief 3504. 字符串转换整数
	 */
	namespace acwing3504 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 1603. 整数集合划分
	 */
	namespace acwing1603 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3527. 旋转矩阵
	 */
	namespace acwing3527 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3534. 矩阵幂
	 */
	namespace acwing3534 {
		Matrix getMat(vector<Matrix *> &mat, int p);
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing3534

	/**
	 * @brief 3535. C翻转
	 */
	namespace acwing3535 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3874. 三元组的最小距离
	 */
	namespace acwing3874 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 52. 数组中出现次数超过一半的数字
	 */
	namespace acwing52 {
		int moreThanHalfNum_Solution(vector<int> &nums);
	}

	/**
	 * @brief 3392. 递推数列
	 */
	namespace acwing3392 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3433. 吃糖果
	 */
	namespace acwing3433 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3441. 重复者
	 */
	namespace acwing3441 {
		int main(istream & /*cin*/, ostream & /*cout*/);
		void draw(const vector<vector<char>> &g, int n, int level, vector<vector<char>> &canvas, int x, int y, int space);
	}// namespace acwing3441

	/**
	 * @brief 2. 01背包问题
	 */
	namespace acwing2 {
		struct status {
			int w;
			vector<bool> free;
		};
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing2

	/**
	 * @brief 3445. 点菜问题
	 */
	namespace acwing3445 {
		struct status {
			int v;
			vector<bool> free;
		};
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing3445

	/**
	 * @brief 3442. 神奇的口袋
	 */
	namespace acwing3442 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing3442

	/**
	 * @brief 3382. 整数拆分
	 */
	namespace acwing3382 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3389. N 的阶乘
	 */
	namespace acwing3389 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3448. 基本算术
	 */
	namespace acwing3448 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3453. 整数查询
	 */
	namespace acwing3453 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3380. 质因数的个数
	 */
	namespace acwing3380 {
		bool add(long long n);
		int main(istream & /*cin*/, ostream & /*cout*/);
	}// namespace acwing3380

	/**
	 * @brief 3377. 约数的个数
	 */
	namespace acwing3377 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3507. 阶乘的末尾0
	 */
	namespace acwing3507 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}

	/**
	 * @brief 3484. 整除问题
	 */
	namespace acwing3484 {
		int main(istream & /*cin*/, ostream & /*cout*/);
	}
}// namespace acwing

#endif//PROBLEMSCPP_ACWING408_H
