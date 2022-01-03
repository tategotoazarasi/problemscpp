//
// Created by tategotoazarasi on 2021/12/29.
//

#ifndef PROBLEMSCPP_LINTCODE_H
#define PROBLEMSCPP_LINTCODE_H

#include<string>
#include<vector>

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
			static string licenseKeyFormatting(string&, int);
		};
	}

	namespace distribute_candies {
		class Solution {
		public:
			/**
			 * @param candies: a list of integers
			 * @return: return a integer
			 */
			static int distributeCandies(vector<int>& candies);
		};
	}

	namespace remove_extra {
		class Solution {
		public:
			/**
			 * @param s: the original string
			 * @return: the string without arbitrary spaces
			 */
			static string removeExtra(string& s);
		};
	}
}


#endif //PROBLEMSCPP_LINTCODE_H
