/*#include "gtest/gtest.h"
#include"templates.h"

TEST(UnionFind,case1) {
	auto hash = [](const int &val) {
		return size_t(val);
	};
	auto equal = [](const int&a,const int&b) {
		return a == b;
	};
	function<size_t(const int &val)> h = hash;
	UnionFind<int,h,equal> uf;
}*/
