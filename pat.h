#ifndef PROBLEMSCPP_PAT_H
#define PROBLEMSCPP_PAT_H

#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>

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

		/// \brief 1064 朋友数
		namespace b1064 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1066 图像过滤
		namespace b1066 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1065 单身狗
		namespace b1065 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1067 试密码
		namespace b1067 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1068 万绿丛中一点红
		namespace b1068 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1069 微博转发抽奖
		namespace b1069 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1070 结绳
		namespace b1070 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1071 小赌怡情
		namespace b1071 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1072 开学寄语
		namespace b1072 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1073 多选题常见计分法
		namespace b1073 {
			/// \brief 多选题
			struct problem {
				int id{};              ///< 编号
				int score{};           ///< 满分值
				int noa{};             ///< 选项个数
				int noca{};            ///< 正确选项个数
				unordered_set<char> ca;///< 正确选项
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1073

		/// \brief 1074 宇宙无敌加法器
		namespace b1074 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1075 链表元素分类
		namespace b1075 {
			struct Node {
				string addr;
				int data{};
				string next;
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1075

		/// \brief 1076 Wifi密码
		namespace b1076 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1078 字符串压缩与解压
		namespace b1078 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1077 互评成绩计算
		namespace b1077 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1079 延迟的回文数
		namespace b1079 {
			bool is_palindromic(string str);
			int main(istream &cin, ostream &cout);
		}// namespace b1079

		/// \brief 1080 MOOC期终成绩
		namespace b1080 {
			struct student {
				string id;
				int p        = -1;
				int mid_term = -1;
				int final    = -1;
				int score{};
				[[nodiscard]] int get_score() const;
				bool operator<(const student & /*stu*/) const;
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1080

		/// \brief 1081 检查密码
		namespace b1081 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1082 射击比赛
		namespace b1082 {
			struct player {
				string id;
				int x{};
				int y{};
				[[nodiscard]] int get_dist() const;
				bool operator<(const player & /*p*/) const;
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1082

		/// \brief 1083 是否存在相等的差
		namespace b1083 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1084 外观数列
		namespace b1084 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1085 PAT单位排行
		namespace b1085 {
			struct school {
				string id;
				int a_sum = 0;
				int b_sum = 0;
				int t_sum = 0;
				int count = 0;
				school()  = default;

				explicit school(string id)
				    : id(std::move(std::move(id))){};
				[[nodiscard]] int get_score() const;
				bool operator<(const school & /*sc*/) const;
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1085

		/// \brief 1086 就不告诉你
		namespace b1086 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1087 有多少不同的值
		namespace b1087 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1088 三人行
		namespace b1088 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1089 狼人杀-简单版
		namespace b1089 {
			bool is_true(const vector<int> &vec, int wolf1, int wolf2);
			int main(istream &cin, ostream &cout);
		}// namespace b1089

		/// \brief 1090 危险品装箱
		namespace b1090 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1091 N-自守数
		namespace b1091 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1092 最好吃的月饼
		namespace b1092 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1093 字符串A+B
		namespace b1093 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1094 谷歌的招聘
		namespace b1094 {
			bool is_prime(unsigned int n);
			int main(istream &cin, ostream &cout);
		}// namespace b1094

		/// \brief 1095 解码PAT准考证
		namespace b1095 {
			struct student {
				string id;
				string date;
				string room;
				char level{};
				int grade{};
			};

			struct room {
				string id;
				unordered_set<student *> students;
				int count = 0;
				int sum   = 0;
			};

			struct p_stu_comp {
				bool operator()(const student *stu1, const student *stu2) const;
			};

			struct room_cnt_comp {
				bool operator()(const pair<string, int> &p1, const pair<string, int> &p2) const;
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1095

		/// \brief 1096 大美数
		namespace b1096 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1097 矩阵行平移
		namespace b1097 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1098 岩洞施工
		namespace b1098 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1099 性感素数
		namespace b1099 {
			bool is_prime(unsigned int n);
			int main(istream &cin, ostream &cout);
		}// namespace b1099

		/// \brief 1100 校庆
		namespace b1100 {
			struct comp {
				bool operator()(const string &s1, const string &s2) const;
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1100

		/// \brief 1101 B是A的多少倍
		namespace b1101 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1102 教超冠军卷
		namespace b1102 {
			struct paper {
				string id;
				int sale{};
				int price{};
			};

			struct comp_sale {
				bool operator()(const paper &p1, const paper &p2) const;
			};

			struct comp_total {
				bool operator()(const paper &p1, const paper &p2) const;
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1102

		/// \brief 1103 缘分数
		namespace b1103 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1104 天长地久
		namespace b1104 {
			bool is_prime(int n);
			void dfs(string str, int current_i, int m, int k, int current_sum, int cnt9, vector<string> &ans);
			int main(istream &cin, ostream &cout);
		}// namespace b1104

		/// \brief 1105 链表合并
		namespace b1105 {
			struct node {
				string address;
				unsigned data{};
				string next;
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1105

		/// \brief 1106 2019数列
		namespace b1106 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1107 老鼠爱大米
		namespace b1107 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1108 String复读机
		namespace b1108 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1109 擅长C
		namespace b1109 {
			int main(istream &cin, ostream &cout);
		}

		/// \brief 1110 区块反转
		namespace b1110 {
			struct node {
				string address;
				int data{};
				string next;
			};

			int main(istream &cin, ostream &cout);
		}// namespace b1110
	}    // namespace b

	/// \brief 甲级
	namespace a {
		/// \brief 1003 Emergency
		namespace a1003 {
			struct comp {
				bool operator()(const tuple<int, int, int> &a, const tuple<int, int, int> &b) const;
			};
			int main(istream &cin, ostream &cout);
		}// namespace a1003

		/// \brief 1004 Counting Leaves
		namespace a1004 {
			struct node {
				string id;
				unordered_set<node *> children;

				explicit node(string id): id(std::move(id)) {}
			};
			int main(istream &cin, ostream &cout);
		}// namespace a1004
	}    // namespace a

	/// \brief 顶级
	namespace top {}
}// namespace pat

#endif//PROBLEMSCPP_PAT_H
