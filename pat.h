#ifndef PROBLEMSCPP_PAT_H
#define PROBLEMSCPP_PAT_H

#include <iostream>

using namespace std;

/// \brief 计算机程序设计能力考试
namespace pat {
	/// \brief 乙级
	namespace b {
		/// \brief 1001 害死人不偿命的(3n+1)猜想
		namespace b1001 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1002 写出这个数
		namespace b1002 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1003 我要通过！
		namespace b1003 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1004 成绩排名
		namespace b1004 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1005 继续(3n+1)猜想
		namespace b1005 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1006 换个格式输出整数
		namespace b1006 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1007 素数对猜想
		namespace b1007 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1008 数组元素循环右移问题
		namespace b1008 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1009 说反话
		namespace b1009 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1010 一元多项式求导
		namespace b1010 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1011 A+B 和 C
		namespace b1011 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1012 数字分类
		namespace b1012 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1013 数素数
		namespace b1013 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1014 福尔摩斯的约会
		namespace b1014 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1015 德才论
		namespace b1015 {
			struct student {
				string id;
				int morality{};
				int ability{};
				bool operator<(const student &stu) const;
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1015

		/// \brief 1016 部分A+B
		namespace b1016 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1018 锤子剪刀布
		namespace b1018 {
			int main(istream &cin, ostream &cout);
		}

		/**
		 * \brief 1019 数字黑洞 
		 */
		namespace b1019 {
			int main(istream &cin, ostream &cout);
		}

		/**
		 * \brief 1020 月饼 
		 */
		namespace b1020 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1021 个位数统计
		namespace b1021 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1022 D进制的A+B
		namespace b1022 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1023 组个最小数
		namespace b1023 {
			int main(istream &cin, ostream &cout);
		}
	}// namespace b

	/// \brief 甲级
	namespace a {}

	/// \brief 顶级
	namespace top {}
}// namespace pat

#endif//PROBLEMSCPP_PAT_H
