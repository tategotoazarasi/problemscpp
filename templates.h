#pragma once
#include <array>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/// \brief 字典树节点
struct TrieNode {
	char ch;
	array<TrieNode *, 26> nexts = {};
	bool end_of_word            = false;
	unsigned count              = 0;

	explicit TrieNode(char ch)
	    : ch(ch) {}

	void insert(const string &str);
	~TrieNode();
};

/// \brief 高精度整数
class BigInt {
private:
	bool positive              = true;
	vector<unsigned short> vec = {};
	[[nodiscard]] unsigned long get_size() const;
	unsigned short operator[](unsigned long /*i*/) const;
	BigInt(const vector<unsigned short> &vec, bool positive);
	vector<unsigned short> operator*(unsigned short n) const;

public:
	BigInt(short n);
	BigInt(int n);
	BigInt(long n);
	BigInt(long long n);
	BigInt(unsigned short n);
	BigInt(unsigned int n);
	BigInt(unsigned long n);
	BigInt(unsigned long long n);
	BigInt(const string &str);
	BigInt(const char *str);
	BigInt(const BigInt &bi);
	BigInt operator+(const BigInt &bi) const;
	BigInt operator-(const BigInt &bi) const;
	BigInt operator*(const BigInt &bi) const;
	BigInt operator/(const BigInt &bi) const;
	BigInt operator%(const BigInt &bi) const;
	BigInt operator-() const;
	BigInt &operator+=(const BigInt &bi);
	BigInt &operator-=(const BigInt &bi);
	BigInt &operator*=(const BigInt &bi);
	BigInt &operator/=(const BigInt &bi);
	BigInt &operator%=(const BigInt &bi);
	BigInt &operator++();
	BigInt &operator--();
	BigInt operator++(int);
	BigInt operator--(int);
	bool operator>(const BigInt &bi) const;
	bool operator<(const BigInt &bi) const;
	bool operator==(const BigInt &bi) const;
	bool operator!=(const BigInt &bi) const;
	bool operator>=(const BigInt &bi) const;
	bool operator<=(const BigInt &bi) const;
	friend ostream &operator<<(ostream &os, const BigInt & /*bi*/);
	friend istream &operator>>(istream &is, const BigInt & /*bi*/);
	BigInt();
};

/// \brief 分数
class Fraction {
private:
	bool positive;                 ///< 正负
	unsigned long long numerator;  ///< 分子
	unsigned long long denominator;///< 分母
	void simplify();

public:
	Fraction(bool positive, long long numerator, long long denominator);
	Fraction operator+(const Fraction &f) const;
	Fraction operator-(const Fraction &f) const;
	Fraction operator*(const Fraction &f) const;
	Fraction operator/(const Fraction &f) const;
	[[nodiscard]] bool is_positive() const;
	[[nodiscard]] unsigned long long get_numerator() const;
	[[nodiscard]] unsigned long long get_denominator() const;
	friend ostream &operator<<(ostream &os, const Fraction &frac);
};

/// \brief 并查集
class UnionFind {
private:
	vector<int> parent;
	vector<int> rank;
	vector<int> size;

public:
	explicit UnionFind(int n);
	int find(int x);
	void unite(int x, int y);
	bool same(int x, int y);
	int get_size(int x);
	unsigned count();
};

/// \brief 矩阵
class Matrix {
private:
	vector<vector<int>> mat;

public:
	Matrix(int n);
	Matrix(const Matrix &m);
	Matrix operator*(const Matrix &m) const;
	vector<int> &operator[](int i);
	const vector<int> &operator[](int i) const;
	static Matrix identity(int n);
};

/// \brief 平衡二叉树节点
template<typename T>
class AVLNode {
private:
	T value;
	int height         = 1;
	AVLNode<T> *left   = nullptr;
	AVLNode<T> *right  = nullptr;
	AVLNode<T> *parent = nullptr;

	AVLNode *find_next() {
		AVLNode *ans = this->right;
		if(ans == nullptr) {
			return nullptr;
		}
		while(ans->left != nullptr) {
			ans = ans->left;
		}
		return ans;
	}

public:
	AVLNode(T value)
	    : value(value) {}
	T get_value() const { return value; }
	void set_value(const T &value) { this->value = value; }
	int get_height() const { return height; }
	void set_height(int height) { this->height = height; }
	AVLNode<T> *get_left() const { return left; }
	void set_left(AVLNode<T> *left) { this->left = left; }
	AVLNode<T> *get_right() const { return right; }
	void set_right(AVLNode<T> *right) { this->right = right; }
	AVLNode<T> *get_parent() const { return parent; }
	void set_parent(AVLNode<T> *parent) { this->parent = parent; }

	void insert(AVLNode *node) {
		AVLNode *current = this;
		AVLNode *prior   = nullptr;
		while(current != nullptr) {
			prior = current;
			if(node->value >= current->value) {
				current = current->right;
			} else {
				current = current->left;
			}
		}
		if(node->value >= prior->value) {
			prior->right = node;
		} else {
			prior->left = node;
		}
		node->parent = prior;
		current      = prior;
		while(current != nullptr) {
			int height_left  = current->left ? current->left->height : 0;
			int height_right = current->right ? current->right->height : 0;
			if(abs(height_left - height_right) > 1) {
				current->balance();
			}
			current->height = max(height_left, height_right) + 1;
			current         = current->parent;
		}
	}

	AVLNode *find(T v) {
		AVLNode *current = this;
		while(current->value != v) {
			if(v < current->value) {
				current = current->left;
			} else {
				current = current->right;
			}
		}
		return current;
	}

	void remove(T v) {
		AVLNode *to_remove = this->find(v);
		if(to_remove == nullptr) {
			return;
		}
		AVLNode *next = to_remove->find_next();
		if(next == nullptr) {
			//TODO
		}
		//TODO
	}

	void balance() {
		//TODO
	}
};

class huffman {
private:
	char c;
	huffman *left;
	huffman *right;
	int weight;
	unordered_map<char, string> table = {};
	static void gen_table(string str, huffman *current, huffman *top);

public:
	huffman(char c, huffman *left, huffman *right, int weight): c(c), left(left), right(right), weight(weight) {}
	char get_c() const;
	huffman *get_left() const;
	huffman *get_right() const;
	int get_weight() const;
	bool operator<(const huffman &h) const;
	static std::vector<int> generate_bounded_normal_ints(int n);
	static pair<string, huffman *> compress(string input);
	string decompress(string input);
};

struct huffman_ptr_comp {
	bool operator()(const huffman *a, const huffman *b) const;
};

namespace elias_gamma {
	vector<bool> encode(vector<bool> input);
	vector<bool> decode(vector<bool> input);
}// namespace elias_gamma

namespace lzw {
	pair<vector<int>, unordered_map<int, string>> encode(string input);
	string decode(vector<int> input, unordered_map<int, string> dict);
}// namespace lzw

namespace mtf {
	vector<int> encode(string input);
	string decode(vector<int> input);
}// namespace mtf

namespace bwt {
	string encode(string input);
	string decode(string input);
}// namespace bwt