//
// Created by tategotoazarasi on 2021/12/29.
//

#ifndef PROBLEMSCPP_LINTCODE_H
#define PROBLEMSCPP_LINTCODE_H

#include <string>
#include <vector>

using namespace std;

namespace lintcode {
	namespace license_key_formatting {
		class Solution {
		public:
			/**
			* @param S: a string
			* @param K: a integer
			* @return: return a string
			*/
			static string licenseKeyFormatting(string &, int);
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
			static int fibonacci(int);
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
}    // namespace lintcode

#endif//PROBLEMSCPP_LINTCODE_H
