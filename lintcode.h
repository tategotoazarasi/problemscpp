#ifndef PROBLEMSCPP_LINTCODE_H
#define PROBLEMSCPP_LINTCODE_H

#include <string>
#include <vector>

using namespace std;

namespace lintcode {
	class TreeNode {
	public:
		int val;
		TreeNode *left, *right;

		explicit TreeNode(int val)
		    : val(val), left(nullptr), right(nullptr){};
	};

	namespace license_key_formatting {
		class Solution {
		public:
			/**
			* @param S: a string
			* @param K: a integer
			* @return: return a string
			*/
			static string licenseKeyFormatting(string & /*S*/, int /*K*/);
		};
	}// namespace license_key_formatting

	namespace distribute_candies {
		class Solution {
		public:
			/**
			 * @param candies: a list of integers
			 * @return: return a integer
			 */
			static int distributeCandies(vector<int> &candies);
		};
	}// namespace distribute_candies

	namespace remove_extra {
		class Solution {
		public:
			/**
			 * @param s: the original string
			 * @return: the string without arbitrary spaces
			 */
			static string removeExtra(string &s);
		};
	}// namespace remove_extra

	/**
	 * \brief lintcode 1807. 斐波纳契数列简单
	 */
	namespace fibonacci {
		class Solution {
		public:
			/**
			 * @param n: an integer
			 * @return: an ineger f(n)
			 */
			static int fibonacci(int /*n*/);
		};
	}// namespace fibonacci

	/**
	 * \brief lintcode 1905. 字符删除
	 */
	namespace character_deletion {
		class Solution {
		public:
			/**
			 * @param str: The first string given
			 * @param sub: The given second string
			 * @return: Returns the deleted string
			 */
			static string CharacterDeletion(string &str, string &sub);
		};
	}// namespace character_deletion

	/**
	 * \brief lintcode 1104. 机器人能否返回原点
	 */
	namespace judge_circle {
		class Solution {
		public:
			/**
			 * @param moves: a sequence of its moves
			 * @return: if this robot makes a circle
			 */
			static bool judgeCircle(string &moves);
		};
	}// namespace judge_circle

	/**
	 * \brief lintcode 295. 交集
	 */
	namespace intersection {
		class Solution {
		public:
			/**
			 * @param a: first sequence
			 * @param b: second sequence
			 * @return: return ans
			 */
			static vector<vector<int>> Intersection(vector<vector<int>> &a, vector<vector<int>> &b);

			static bool is_intersected(const vector<int> &l, const vector<int> &r);
		};
	}// namespace intersection

	/// \brief LintCode 453. 将二叉树拆成链表
	namespace flatten {
		class Solution {
		public:
			/**
			 * @param root: a TreeNode, the root of the binary tree
			 * @return: nothing
			 */
			static void flatten(TreeNode *root);

			static TreeNode *vlr(TreeNode * /*node*/);
		};
	}// namespace flatten

	/**
	 * \brief LintCode 1730. 电子表格符号转换
	 */
	namespace convert {
		class Solution {
		public:
			/**
			 * @param index: the index to be converted
			 * @return: return the string after convert.
			 */
			static string convert(long long index);
		};
	}// namespace convert

	/// \brief LintCode 110. 最小路径和
	namespace min_path_sum {
		class Solution {
		public:
			/**
     		 * @param grid: a list of lists of integers
     		 * @return: An integer, minimizes the sum of all numbers along its path
     		 */
			static int minPathSum(vector<vector<int>> &grid);
		};
	}// namespace min_path_sum

	/// \brief LintCode 3. 统计数字
	namespace digit_counts {
		class Solution {
		public:
			/**
     		 * @param k: An integer
     		 * @param n: An integer
     		 * @return: An integer denote the count of digit k in 1..n
     		 */
			static int digitCounts(int k, int n);
		};
	}// namespace digit_counts

	/**
	 * \brief LintCode 1746. 二叉搜索树结点最小距离
	 * \date 2022-1-18
	 * \link https://www.lintcode.com/problem/1746/
	 */
	namespace min_diff_in_BST {
		class Solution {
		public:
			/**
			 * @param root:  a Binary Search Tree (BST) with the root node
			 * @return: the minimum difference
			 */
			static int minDiffInBST(TreeNode *root);
		};
	}// namespace min_diff_in_BST
}// namespace lintcode

#endif//PROBLEMSCPP_LINTCODE_H
