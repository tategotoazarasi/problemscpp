#ifndef PROBLEMSCPP_PAT_H
#define PROBLEMSCPP_PAT_H

#include <iostream>
#include <unordered_set>

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

		/// \brief 1024 科学计数法
		namespace b1024 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1025 反转链表
		namespace b1025 {
			struct Node {
				string address;
				int data;
				Node *prev = nullptr;
				Node *next = nullptr;
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1025

		/// \brief 1026 程序运行时间
		namespace b1026 {
			int main(istream &cin, ostream &cout);
		}

		/**
		 * \brief 1027 打印沙漏
		 */
		namespace b1027 {
			int main(istream &cin, ostream &cout);
		}

		/**
		 * \brief 1028 人口普查 
		 */
		namespace b1028 {
			struct Person {
				string name;
				int year{};
				int month{};
				int day{};
				Person() = default;

				Person(int year, int month, int day)
				    : year(year), month(month), day(day) {}

				bool operator<(const Person &p) const;
			};

			bool is_valid(int year, int month, int day);
			int main(istream &cin, ostream &cout);
		}// namespace b1028

		/// \brief 1029 旧键盘
		namespace b1029 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1030 完美数列
		namespace b1030 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1031 查验身份证
		namespace b1031 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1032 挖掘机技术哪家强
		namespace b1032 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1033 旧键盘打字
		namespace b1033 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1034 有理数四则运算
		namespace b1034 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1035 插入与归并
		namespace b1035 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1036 跟奥巴马一起编程
		namespace b1036 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1037 在霍格沃茨找零钱
		namespace b1037 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1038 统计同成绩学生
		namespace b1038 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1039 到底买不买
		namespace b1039 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1040 有几个PAT
		namespace b1040 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1041 考试座位号
		namespace b1041 {
			struct student {
				string id;
				int seat1{};
				int seat2{};
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1041

		/// \brief 1042 字符统计
		namespace b1042 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1043 输出PATest
		namespace b1043 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1044 火星数字
		namespace b1044 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1045 快速排序
		namespace b1045 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1046 划拳
		namespace b1046 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1047 编程团体赛
		namespace b1047 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1048 数字加密
		namespace b1048 {
			int main(istream &cin, ostream &cout);
		}

		/**
		 * \brief 1049 数列的片段和
		 */
		namespace b1049 {
			int main(istream &cin, ostream &cout);
		}

		/**
		 * \brief 1050 螺旋矩阵
		 */
		namespace b1050 {
			int main(istream &cin, ostream &cout);
		}

		/**
		 * \brief 1051 复数乘法
		 */
		namespace b1051 {
			int main(istream &cin, ostream &cout);
		}

		/**
		 * \brief 1052 卖个萌
		 */
		namespace b1052 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1053 住房空置率
		namespace b1053 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1054 求平均值
		namespace b1054 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1055 集体照
		namespace b1055 {
			struct Person {
				string name;
				int height{};

				bool operator<(const Person &p) const;
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1055

		/// \brief 1056 组合数的和
		namespace b1056 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1057 数零壹
		namespace b1057 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1058 选择题
		namespace b1058 {
			struct Problem {
				int score{};
				int num{};
				int correct_num{};
				unordered_set<char> correct_choices;
				int error_count{};
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1058

		/// \brief 1059 C语言竞赛
		namespace b1059 {
			bool is_prime(int n);
			int main(istream &cin, ostream &cout);
		}// namespace b1059

		/// \brief 1060 爱丁顿数
		namespace b1060 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1061 判断题
		namespace b1061 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1062 最简分数
		namespace b1062 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1063 计算谱半径
		namespace b1063 {
			int main(istream &cin, ostream &cout);
		}
	}// namespace b

	/// \brief 甲级
	namespace a {}

	/// \brief 顶级
	namespace top {}
}// namespace pat

#endif//PROBLEMSCPP_PAT_H
