#pragma once
#include <array>
#include <string>
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