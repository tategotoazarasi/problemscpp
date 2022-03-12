/* #pragma once

#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<typename T, function<size_t(const T &)> hash, function<bool(const T &, const T &)> equal>
class UnionFind {
private:
	unordered_set<T *> items;
	unordered_map<T, *T, function<size_t(const T &)>, function<bool(const T &, const T &)>> parent;
	unordered_map<T, unsigned int, function<size_t(const T &)>, function<bool(const T &, const T &)>> size;
	unordered_map<T, unsigned int, function<size_t(const T &)>, function<bool(const T &, const T &)>> rank;

	T *find(const T &val) {
		if(!equal(*parent[val], val)) {
			parent[val] = find(parent[val]);
		}
		return parent[val];
	}

public:
	UnionFind(unordered_set<T, function<size_t(const T &)>, function<bool(const T &, const T &)>> s) {
		parent = unordered_map<T, *T, function<size_t(const T &)>, function<bool(const T &, const T &)>>(s.size(), hash, equal);
		size   = unordered_map<T, unsigned int, function<size_t(const T &)>, function<bool(const T &, const T &)>>(s.size(), hash, equal);
		rank   = unordered_map<T, unsigned int, function<size_t(const T &)>, function<bool(const T &, const T &)>>(s.size(), hash, equal);
		for(auto val: s) {
			T *p_val = new T(val);
			items.insert(p_val);
			parent[val] = p_val;
			size[val]   = 1;
			rank[val]   = 0;
		}
	}

	void merge(const T &a, const T &b) {
		const T pa = *find(a);
		const T pb = *find(b);
		if(pa != pb) {
			const unsigned int sum = size[pa] + size[pb];
			if(rank[pa] > rank[pb]) {
				parent[pb] = &pa;
			} else {
				parent[pa] = &pb;
				if(rank[pa] == rank[pb]) {
					++rank[pb];
				}
			}
			size[pa] = sum;
			size[pb] = sum;
		}
	}

	bool same(const T &a, const T &b) {
		return equal(*find(a), *find(b));
	}

	int get_size(const T &val) {
		return size[*find(val)];
	}

	~UnionFind() {
		for(auto item: items) {
			delete item;
		}
	}
};
*/