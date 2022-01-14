#ifndef PROBLEMSCPP_ACWING_H
#define PROBLEMSCPP_ACWING_H

#include <iostream>
#include <unordered_set>

using namespace std;

namespace acwing {
	class acwing1 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	class acwing4200 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	class acwing4201 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	class acwing608 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	class acwing604 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	class acwing606 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	class acwing609 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	class acwing615 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	class acwing616 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	class acwing653 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	class acwing4203 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	class acwing4204 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	class acwing2058 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief 时间转换
	 */
	class acwing654 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief 简单乘积
	 */
	class acwing605 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 2041. 干草堆
	 */
	class acwing2041 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 2060. 奶牛选美
	 */
	namespace acwing2060 {
		class acwing2060 {
		public:
			static int main(istream & /*cin*/, ostream & /*cout*/);
		};

		struct point {
			int x;
			int y;

			point() = default;

			point(int x, int y)
			    : x(x), y(y){};
		};

		struct pointhash {
			size_t operator()(const point & /*p*/) const;
		};

		struct pointequal {
			bool operator()(const point & /*p1*/, const point & /*p2*/) const;
		};

		void flood(point /*first*/, bool /*occupy*/[55][55], unordered_set<point, pointhash, pointequal> * /*edge*/, char /*cowhide*/[55][55], int /*n*/, int /*m*/);
	}// namespace acwing2060

	/**
	 * \brief AcWing 2019. 拖拉机
	 */
	namespace acwing2019 {
		const int N = 1000;

		struct point {
			int x;
			int y;
			int step;

			point(int x, int y, int step)
			    : x(x), y(y), step(step){};
		};

		int bfs(point /*start*/, int ** /*field*/, int /*max_x*/, int /*max_y*/);

		class acwing2019 {
		public:
			static int main(istream & /*cin*/, ostream & /*cout*/);
		};
	}// namespace acwing2019

	/**
	 * \brief AcWing 611. 简单计算
	 */
	class acwing611 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 612. 球的体积
	 */
	class acwing612 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 2014. 岛
	 */
	class acwing2014 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 607. 平均数2
	 */
	class acwing607 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 613. 面积
	 */
	class acwing613 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 610. 工资和奖金
	 */
	class acwing610 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 614. 最大值
	 */
	class acwing614 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 2005. 马蹄铁
	 */
	class acwing2005 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);

		///
		/// \param stage 当前阶段 ture为寻找左括号 false为寻找右括号
		/// \param horseshoes 马蹄铁方格
		/// \param picked 已经走过的区域
		/// \param count 当前括号字符串长度
		/// \param level 括号平衡情况(当前左括号的数量-右括号的数量)
		/// \param x 当前横座标
		/// \param y 当前纵座标
		/// \param n 座标上限
		/// \return 当前状态下最长完全平衡括号字符串的长度
		static int
		dfs(bool stage, char horseshoes[5][5], const bool picked[5][5], int count, int level, int x, int y, int n);
	};

	/**
	 * \brief AcWing 617. 距离
	 */
	class acwing617 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing  618. 燃料消耗
	 */
	class acwing618 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/// \brief AcWing 4206. 判断数字
	class acwing4206 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/// \brief AcWing 4207. 最长合法括号子序列
	class acwing4207 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/// \brief AcWing 4208. 电话号码
	namespace acwing4208 {
		/**
		 * \brief 字典树
		 */
		struct trie_node {
			/**
			 * \brief 值
			 */
			int val;
			/**
			 * \brief 父节点
			 */
			trie_node *father;
			/**
			 * \brief 子节点
			 */
			trie_node *nexts[10]{};

			trie_node(int val, trie_node *father)
			    : val(val), father(father){};

			/**
			 * \brief 反向插入
			 * \param str 插入的字符串
			 */
			void insert(string str);

			/**
			 * \brief 显示
			 */
			void display();

			/**
			 * \brief 分支计数
			 * \return 分支计数
			 */
			int count();
		};

		class acwing4208 {
		public:
			static int main(istream & /*cin*/, ostream & /*cout*/);
		};
	}// namespace acwing4208

	/// \brief AcWing 1996. 打乱字母
	class acwing1996 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);

		static bool cmp(char x, char y);
	};

	/// \brief AcWing 656. 钞票和硬币
	class acwing656 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/// \brief AcWing 655. 天数转换
	class acwing655 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 665. 倍数
	 */
	class acwing665 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 657. 选择练习1
	 */
	class acwing657 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 1987. 粉刷栅栏
	 */
	class acwing1987 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/// \brief AcWing 660. 零食
	class acwing660 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/// \brief AcWing 671. DDD
	class acwing671 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/// \brief AcWing 1978. 奶牛过马路
	namespace acwing1978 {
		struct path {
			int a;
			int b;

			path()
			    : a(0), b(0){};

			path(int a, int b)
			    : a(a), b(b){};
			bool operator<(const path &p) const;
		};

		class acwing1978 {
		public:
			static int main(istream & /*cin*/, ostream & /*cout*/);
		};
	}// namespace acwing1978

	/**
	 * \brief AcWing 659. 区间
	 */
	class acwing659 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 662. 点的坐标
	 */
	class acwing662 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 1969. 品种邻近
	 */
	class acwing1969 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 664. 三角形
	 */
	class acwing664 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 666. 三角形类型
	 */
	class acwing666 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/**
	 * \brief AcWing 1960. 闪烁
	 */
	class acwing1960 {
	private:
		int fsm[1 << 16] = {};
		unsigned int n{};

	public:
		int main(istream & /*cin*/, ostream & /*cout*/);
		unsigned int get_next(unsigned int status);
		[[nodiscard]] bool *decompress(unsigned int status) const;
		unsigned int compress(const bool * /*bulbs*/) const;
	};

	/// \brief AcWing 667. 游戏时间
	class acwing667 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};
}// namespace acwing
#endif//PROBLEMSCPP_ACWING_H
