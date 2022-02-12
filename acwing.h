#ifndef PROBLEMSCPP_ACWING_H
#define PROBLEMSCPP_ACWING_H

#include <iostream>
#include <unordered_set>
#include <vector>

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

	/// \brief AcWing 668. 游戏时间2
	class acwing668 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/// \brief AcWing 1952. 金发姑娘和 N 头牛
	class acwing1952 {
	public:
		static int main(istream & /*cin*/, ostream & /*cout*/);
	};

	/// \brief AcWing 669. 加薪
	class acwing669 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 672. 税
	class acwing672 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1945. 奶牛棒球
	class acwing1945 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 4209. 三元组
	 */
	class acwing4209 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 4210. 数字
	 */
	class acwing4210 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 4211. 序列重排
	 */
	class acwing4211 {
	public:
		static int main(istream &cin, ostream &cout);
		static unsigned int no2(unsigned long long a);
		static unsigned int no3(unsigned long long a);
		static bool cmp(unsigned long long a, unsigned long long b);
	};

	/// \brief AcWing 670. 动物
	class acwing670 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 663. 简单排序
	class acwing633 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1934. 贝茜放慢脚步
	class acwing1934 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 658. 一元二次方程公式
	 */
	class acwing658 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 661. 平均数3
	 */
	class acwing661 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 1929. 镜子田地
	 * \date 2022-01-18
	 */
	namespace acwing1929 {
		/**
		 * \brief 方向
		 */
		enum direction {
			/// @brief 左
			left,
			/// @brief 右
			right,
			/// @brief 上
			up,
			/// @brief 下
			down
		};

		/**
		 * \brief 行动
		 */
		struct step {
			/// @brief 方向
			direction d;
			/// @brief 横坐标
			unsigned int x;
			/// @brief 纵坐标
			unsigned int y;

			step(direction d, unsigned int x, unsigned int y)
			    : d(d), x(x), y(y){};
		};

		struct step_hash {
			unsigned long operator()(const step & /*s*/) const;
		};

		struct step_equal {
			bool operator()(const step & /*s1*/, const step & /*s2*/) const;
		};

		class Solution {
		private:
			/// @brief 镜子
			char mirrors[1000][1000] = {0};
			/// @brief 在每格向左时可以被反射的次数
			unsigned int left_map[1000][1000] = {0};
			/// @brief 在每格向右时可以被反射的次数
			unsigned int right_map[1000][1000] = {0};
			/// @brief 在每格向上时可以被反射的次数
			unsigned int up_map[1000][1000] = {0};
			/// @brief 在每格向下时可以被反射的次数
			unsigned int down_map[1000][1000] = {0};
			/// @brief 行数
			unsigned short n{};
			/// @brief 列数
			unsigned short m{};

		public:
			int main(istream &cin, ostream &cout);
			/**
			 * \brief 获取反射的次数
			 * \param d 方向
			 * \param x 横坐标
			 * \param y 纵坐标
			 * \return 在(x,y)以d方向前进的光距离离开剩下的反射次数
			 */
			unsigned int count_reflect(direction d, unsigned int x, unsigned int y);
			/**
			 * \brief 获取记录类型
			 * \param d 方向
			 * \return 方向对应的记录
			 */
			unsigned (*get_record(direction d))[1000][1000];
		};

		/**
		 * \brief 方向经过镜子反射后的变化
		 * \param d 方向
		 * \param mirror 镜子 
		 * \return 方向经过镜子反射后的变化
		 */
		direction reflect(direction d, char mirror);
		/**
		 * \brief 取反方向
		 * \param d 方向
		 * \return d的反方向
		 */
		direction operator!(const direction &d);
	}// namespace acwing1929

	/// \brief AcWing 708. 偶数
	class acwing708 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 715. 余数
	class acwing715 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1922. 懒惰的牛
	class acwing1922 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 709. 奇数
	class acwing709 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 710. 六个奇数
	class acwing710 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1913. 公平摄影
	class acwing1913 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 712. 正数
	 */
	class acwing712 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 711. 乘法表
	 */
	class acwing711 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 1904. 奶牛慢跑
	 */
	class acwing1904 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 714. 连续奇数的和 1
	class acwing714 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 718. 实验
	class acwing718 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1884. COW
	class acwing1884 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 4212. 字符串比较
	 */
	class acwing4212 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 4213. 最小结果
	 */
	class acwing4213 {
	public:
		static int main(istream &cin, ostream &cout);
		static unsigned long long get_min(vector<char> ops, vector<unsigned long long> vec);
	};

	/**
	 * \brief AcWing 4214. 三元组
	 */
	class acwing4214 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 716. 最大数和它的位置
	 */
	class acwing716 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 713. 区间 2
	 */
	class acwing713 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 721. 递增序列
	 */
	class acwing721 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 719. 连续奇数的和 2
	 */
	class acwing719 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 1875. 贝茜的报复
	 */
	class acwing1875 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 720. 连续整数相加
	class acwing720 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 717. 简单斐波那契
	class acwing717 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1855. 愤怒的奶牛
	class acwing1855 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 724. 约数
	class acwing724 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 722. 数字序列和它的和
	class acwing722 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1843. 圆形牛棚
	class acwing1843 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 723. PUM
	class acwing723 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 725. 完全数
	class acwing725 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1826. 农田缩减
	namespace acwing1826 {
		struct cmprow {
			bool operator()(const pair<unsigned int, unsigned int> &left, const pair<unsigned int, unsigned int> &right) const;
		};

		struct cmpcol {
			bool operator()(const pair<unsigned int, unsigned int> &left, const pair<unsigned int, unsigned int> &right) const;
		};

		class acwing1826 {
		public:
			static int main(istream &cin, ostream &cout);
		};
	}// namespace acwing1826

	/// \brief AcWing 1813. 方块游戏
	class acwing1813 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 726. 质数
	class acwing726 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 727. 菱形
	class acwing727 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 737. 数组替换
	 */
	class acwing737 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 740. 数组变换
	 */
	class acwing740 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 1801. 蹄子剪刀布
	 */
	class acwing1801 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 4215. 处理字符串
	 */
	class acwing4215 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 4216. 图中的环
	 */
	class acwing4216 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 4217. 机器人移动
	 */
	class acwing4217 {
		vector<char> ops;
		vector<pair<int, int>> forth;
		vector<pair<int, int>> back;
		unsigned int n;
		int a;
		int b;

	public:
		int main(istream &cin, ostream &cout);
		[[nodiscard]] bool check(int len) const;
	};

	/**
	 * \brief AcWing 738. 数组填充
	 */
	class acwing738 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 741. 斐波那契数列
	 */
	class acwing741 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1789. 牛为什么过马路 II
	class acwing1789 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 739. 数组选择
	class acwing739 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 742. 最小数和它的位置
	class acwing742 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1776. 牛的基因组学
	class acwing1776 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 743. 数组中的行
	class acwing743 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 744. 数组中的列
	class acwing744 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 1762. 牛的洗牌
	 */
	class acwing1762 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 1750. 救生员
	 */
	class acwing1750 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 745. 数组的右上半部分
	class acwing745 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 748. 数组的右下半部分
	class acwing748 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 747. 数组的左上半部分
	class acwing747 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 746. 数组的左下半部分
	class acwing746 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1738. 蹄球
	class acwing1738 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 4296. 合适数对
	 */
	class acwing4296 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 4297. 截断数组
	 */
	class acwing4297 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 4298. 搭档
	 */
	class acwing4298 {
		int n            = 0;      ///< 男孩数量
		int m            = 0;      ///< 女孩数量
		int *a           = nullptr;///< 男孩魅力值
		int *b           = nullptr;///< 女孩魅力值
		bool *found      = nullptr;///< 记录女孩是否已经被找到
		bool **connected = nullptr;///< 邻接矩阵存图
		int *match       = nullptr;///< 记录当前女孩所对应的男孩

	public:
		int main(istream &cin, ostream &cout);
		bool find(int i);
	};

	/**
	 * \brief AcWing 749. 数组的上方区域
	 */
	class acwing749 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 750. 数组的下方区域
	 */
	class acwing750 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 751. 数组的左方区域
	class acwing751 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 752. 数组的右方区域
	class acwing752 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1726. 挤奶顺序
	class acwing1726 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 753. 平方矩阵 I
	class acwing753 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 754. 平方矩阵 II
	class acwing754 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1715. 桶列表
	class acwing1715 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 755. 平方矩阵 III
	class acwing755 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 756. 蛇形矩阵
	class acwing756 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1696. 困牛排序
	class acwing1696 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 760. 字符串长度
	class acwing760 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 762. 字符串匹配
	class acwing762 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 1684. 大型植被恢复
	class acwing1684 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 761. 字符串中的数字个数
	 */
	class acwing761 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 768. 忽略大小写比较字符串大小
	 */
	class acwing768 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/**
	 * \brief AcWing 1471. 牛奶工厂
	 */
	class acwing1471 {
	public:
		static int main(istream &cin, ostream &cout);
	};

	/// \brief AcWing 763. 循环相克令
	class acwing763 {
	public:
		static int main(istream &cin, ostream &cout);
	};
}// namespace acwing
#endif//PROBLEMSCPP_ACWING_H
