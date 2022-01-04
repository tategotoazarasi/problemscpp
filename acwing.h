//
// Created by tategotoazarasi on 2021/12/28.
//

#ifndef PROBLEMSCPP_ACWING_H
#define PROBLEMSCPP_ACWING_H

#include<iostream>
#include <set>
#include <unordered_set>
#include<vector>

using namespace std;

namespace acwing {
	class acwing1 {
	public:
		static int main(istream&, ostream&);
	};

	class acwing4200 {
	public:
		static int main(istream&, ostream&);
	};

	class acwing4201 {
	public:
		static int main(istream&, ostream&);
	};

	class acwing610 {
	public:
		static int main(istream&, ostream&);
	};

	class acwing604 {
	public:
		static int main(istream&, ostream&);
	};

	class acwing606 {
	public:
		static int main(istream&, ostream&);
	};

	class acwing609 {
	public:
		static int main(istream&, ostream&);
	};

	class acwing615 {
	public:
		static int main(istream&, ostream&);
	};

	class acwing616 {
	public:
		static int main(istream&, ostream&);
	};

	class acwing653 {
	public:
		static int main(istream&, ostream&);
	};

	class acwing4203 {
	public:
		static int main(istream&, ostream&);
	};

	class acwing4204 {
	public:
		static int main(istream&, ostream&);
	};

	class acwing2058 {
	public:
		static int main(istream&, ostream&);
	};

	/**
	 * \brief 时间转换
	 */
	class acwing654 {
	public:
		static int main(istream&, ostream&);
	};

	/**
	 * \brief 简单乘积
	 */
	class acwing605 {
	public:
		static int main(istream&, ostream&);
	};

	/**
	 * \brief AcWing 2041. 干草堆
	 */
	class acwing2041
	{
	public:
		static int main(istream&, ostream&);
	};

	namespace acwing2060 {
		class acwing2060
		{
		public:
			static int main(istream&, ostream&);
		};

		
		struct point
		{
			int x;
			int y;
			point(int x, int y) :x(x), y(y) {};
		};

		struct pointhash
		{
			size_t operator()(const point&)const;
		};

		struct pointequal
		{
			bool operator()(const point&, const point&)const;
		};

		void flood(point, unordered_set<point, pointhash, pointequal>*, unordered_set<point, pointhash, pointequal>*, char[50][50],int,int);
	}
}
#endif //PROBLEMSCPP_ACWING_H
