#include "lintcode.h"

#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

namespace lintcode {
	namespace license_key_formatting {
		string Solution::licenseKeyFormatting(string &S, int K) {
			auto S2     = ostringstream();
			auto output = ostringstream();
			int len     = 0;
			for(char c: S) {
				if(isalnum(c) != 0) {
					len++;
					if(isdigit(c) != 0 || isupper(c) != 0) {
						S2 << c;
					} else if(islower(c) != 0) {
						S2 << static_cast<char>(toupper(c));
					}
				}
			}
			string str  = S2.str();
			int first   = len % K;
			int average = len / K;
			if(first == 0) {
				first = K;
			}
			string str1 = str.substr(0, first);
			string str2 = str.substr(first);
			for(char c: str1) {
				output << c;
			}
			int count = 0;
			for(char c: str2) {
				if(count == 0) {
					output << '-';
				}
				output << c;
				count++;
				count %= K;
			}
			return output.str();
		}
	}// namespace license_key_formatting

	namespace distribute_candies {
		int Solution::distributeCandies(vector<int> &candies) {
			auto m      = map<long, int>();
			auto ans    = set<int>();
			const int n = static_cast<int>(candies.size()) / 2;
			int sum     = 0;
			for(const auto candy: candies) {
				m[candy]++;
			}
			while(sum < n) {
				for(auto candy: m) {
					if(candy.second != 0) {
						if(!ans.contains(static_cast<int>(candy.first))) {
							ans.insert(static_cast<int>(candy.first));
							if(ans.size() == m.size()) {
								return static_cast<int>(ans.size());
							}
						}
						candy.second--;
						sum++;
					}
					if(sum >= n) {
						break;
					}
				}
			}
			return static_cast<int>(ans.size());
		}
	}// namespace distribute_candies

	namespace remove_extra {
		string Solution::removeExtra(string &s) {
			auto output = ostringstream();
			bool start  = true;
			bool flag   = false;
			for(const char c: s) {
				if(c != ' ') {
					if(flag && !start) {
						output << ' ';
					}
					output << c;
					start = false;
					flag  = false;
				} else {
					flag = true;
				}
			}
			return output.str();
		}
	}// namespace remove_extra

	namespace fibonacci {
		int Solution::fibonacci(int n) {
			auto *arr = new int[n];
			arr[0]    = 0;
			arr[1]    = 1;
			for(int i = 2; i < n; i++) {
				arr[i] = arr[i - 1] + arr[i - 2];
			}
			return arr[n - 1];
		}
	}// namespace fibonacci

	namespace character_deletion {
		string Solution::CharacterDeletion(string &str, string &sub) {
			auto oss = ostringstream();
			auto us  = unordered_set<char>();
			for(auto ch: sub) {
				us.insert(ch);
			}
			for(auto ch: str) {
				if(!us.contains(ch)) {
					oss << ch;
				}
			}
			return oss.str();
		}
	}// namespace character_deletion

	namespace judge_circle {
		bool Solution::judgeCircle(string &moves) {
			int x = 0;
			int y = 0;
			for(const char ch: moves) {
				switch(ch) {
					case 'R':
						x--;
						break;
					case 'L':
						x++;
						break;
					case 'U':
						y--;
						break;
					case 'D':
						y++;
						break;
					default: break;
				}
			}
			return x == 0 && y == 0;
		}
	}// namespace judge_circle

	namespace intersection {
		vector<vector<int>> Solution::Intersection(vector<vector<int>> &a, vector<vector<int>> &b) {
			vector<vector<int>> res;
			if(a.empty() || b.empty()) {
				return res;
			}
			for(int i = 0, j = 0; i < a.size() && j < b.size();) {
				if(is_intersected(a[i], b[j])) {
					res.emplace_back(vector({i, j}));
				}
				if(a[i][1] == b[j][1]) {
					++i;
					++j;
				} else if(a[i][1] > b[j][1]) {
					++j;
				} else {
					++i;
				}
			}
			return res;
		}

		bool Solution::is_intersected(const vector<int> &l, const vector<int> &r) {
			if(l[0] == r[0]) {
				return true;
			}
			if(l[0] < r[0]) {
				return r[0] <= l[1];
			}
			return l[0] <= r[1];
		}
	}// namespace intersection

	namespace flatten {
		void Solution::flatten(TreeNode *root) {
			if(root == nullptr) {
				return;
			}
			root = vlr(root);
		}

		TreeNode *Solution::vlr(TreeNode *node) {
			if(node->left != nullptr) {
				if(node->right != nullptr) {
					auto *tmp     = node->right;
					node->right   = vlr(node->left);
					auto *current = node->right;
					while(current->right != nullptr) {
						current = current->right;
					}
					current->right = vlr(tmp);
					node->left     = nullptr;
				} else {
					node->right = vlr(node->left);
					node->left  = nullptr;
				}
			} else {
				if(node->right != nullptr) {
					node->right = vlr(node->right);
				}
			}
			return node;
		}
	}// namespace flatten

	namespace convert {
		string Solution::convert(long long index) {
			unsigned long long prefix = index / 702 + 1;
			if(index % 702 == 0) {
				prefix--;
				index = 702;
			} else {
				index %= 702;
			}
			auto ans   = string();
			bool round = false;
			while(index != 0) {
				char ch = 0;
				if(round) {
					ch    = static_cast<char>(index % 26 + 63);
					round = false;
				} else {
					ch = static_cast<char>(index % 26 + 64);
				}
				if(ch == '@' && index >= 26) {
					ch    = 'Z';
					round = true;
				} else if(ch == '?' && index >= 26) {
					ch    = 'Y';
					round = true;
				}
				if('A' <= ch && ch <= 'Z') {
					ans.insert(0, 1, ch);
				}
				index /= 26;
			}
			return to_string(prefix) + ans;
		}
	}// namespace convert

	namespace min_path_sum {
		int Solution::minPathSum(vector<vector<int>> &grid) {
			const unsigned int m = grid.size();
			const unsigned int n = grid[0].size();
			auto dp              = new int *[m + 1];
			for(int i = 0; i <= m; i++) {
				dp[i] = new int[n + 1];
				memset(dp[i], INT_MAX, (n + 1) * sizeof(int));
			}
			dp[1][1] = grid[0][0];
			for(int i = 1; i <= m; i++) {
				for(int j = 1; j <= n; j++) {
					if(i == 1 && j == 1) {
						continue;
					}
					unsigned int min = dp[i - 1][j];
					if(dp[i][j - 1] < min) {
						min = dp[i][j - 1];
					}
					dp[i][j] = grid[i - 1][j - 1] + min;
				}
			}
			return dp[m][n];
		}
	}// namespace min_path_sum
}// namespace lintcode
