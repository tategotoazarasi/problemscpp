//
// Created by tategotoazarasi on 2021/12/29.
//

#ifndef PROBLEMSCPP_LEETCODE_H
#define PROBLEMSCPP_LEETCODE_H

#include<string>
#include<vector>
#include<map>

using namespace std;

namespace leetcode {
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;

		TreeNode() : val(0), left(nullptr), right(nullptr) {}

		explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

		bool operator==(const TreeNode&) const;

		bool operator!=(const TreeNode&) const;
	};


	namespace concatenated_words {
		class Solution {
		public:
			static vector<string> findAllConcatenatedWordsInADict(vector<string>&);
		};

		class TrieNode {
		public:
			bool is_end;
			char ch;
			TrieNode* nexts[26] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
								   nullptr,
								   nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
								   nullptr,
								   nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };

			explicit TrieNode(char);

			void insert(const string& str);

			bool dfs(TrieNode*, const string&, int, bool);
		};
	}

	namespace excel_sheet_column_number {
		class Solution {
		public:
			static int titleToNumber(const string& columnTitle);
		};
	}

	namespace excel_sheet_column_title {
		class Solution {
		public:
			static string convertToTitle(int columnNumber);
		};
	}

	namespace majority_element {
		class Solution {
		private:
			map<int, int> m;
		public:
			Solution();

			int majorityElement(vector<int>& nums);
		};
	}

	namespace count_special_quadruplets {
		class Solution {
		public:
			static int countQuadruplets(vector<int>&);
		};
	}

	namespace hand_of_straights {
		class Solution {
		public:
			static bool isNStraightHand(vector<int>& hand, int groupSize);
		};
	}

	namespace perfect_number {
		class Solution {
		public:
			static bool checkPerfectNumber(int num);
		};
	}

	namespace convert_bst_to_greater_tree {
		struct FriendTreeNode {
			int sum;
			int val;
			FriendTreeNode* left;
			FriendTreeNode* right;
			TreeNode* friend_node;

			explicit FriendTreeNode(int x, TreeNode* friend_node) : sum(x), val(0), left(nullptr), right(nullptr),
				friend_node(friend_node) {}
		};

		class Solution {
		public:
			static TreeNode* convertBST(TreeNode* root);

			static FriendTreeNode* copy(TreeNode*);

			static void get_sum(FriendTreeNode*);

			static void convert(FriendTreeNode*);
		};
	}

	namespace convert_1d_array_into_2d_array {
		class Solution {
		public:
			static vector<vector<int>> construct2DArray(vector<int>& original, int m, int n);
		};
	}

	namespace elimination_game {
		class Solution {
		public:
			static int lastRemaining(int);
		};
	}

	namespace check_if_all_as_appears_before_all_bs {
		class Solution {
		public:
			static bool checkString(string);
		};
	}

	namespace number_of_laser_beams_in_a_bank {
		class Solution {
		public:
			static int numberOfBeams(vector<string>&);

			static int deviceCount(const string&);
		};
	}

	namespace destroying_asteroids {
		class Solution {
		public:
			static bool asteroidsDestroyed(int mass, vector<int>& asteroids);
		};
	}

	namespace maximum_employees_to_be_invited_to_a_meeting {
		class Solution {
		public:
			static int maximumInvitations(vector<int>&);
		};
	}

	namespace day_of_the_week {
		class Solution {
		public:
			static string dayOfTheWeek(int day, int month, int year);
		};
	}

};


#endif //PROBLEMSCPP_LEETCODE_H
