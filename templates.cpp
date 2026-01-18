#include "templates.h"

#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <sstream>
#include <unordered_set>

using namespace std;

void TrieNode::insert(const string &str) {
	if(this->nexts[str[0] - 'a'] == nullptr) {
		this->nexts[str[0] - 'a'] = new TrieNode(str[0]);
	}
	if(str.length() == 1) {
		this->nexts[str[0] - 'a']->end_of_word = true;
		this->nexts[str[0] - 'a']->count++;
	} else {
		this->nexts[str[0] - 'a']->insert(str.substr(1));
	}
}

TrieNode::~TrieNode() {
	for(const auto *next: this->nexts) {
		delete next;
	}
}

unsigned long BigInt::get_size() const { return vec.size(); }

unsigned short BigInt::operator[](unsigned long i) const { return vec[i]; }

BigInt::BigInt(const vector<unsigned short> &vec, bool positive)
    : positive(positive) {
	int end_i = vec.size() - 1;
	while(end_i >= 0 && vec[end_i] == 0) {
		end_i--;
	}
	this->vec = vector<unsigned short>();
	for(int i = 0; i <= end_i; i++) {
		this->vec.push_back(vec[i]);
	}
	if(this->vec.empty()) {
		this->vec.push_back(0);
	}
}

BigInt::BigInt(short n) {
	if(n < 0) {
		positive = false;
		n        = -n;
	}
	vec = vector<unsigned short>();
	stringstream ss;
	ss << n;
	char ch;
	while(ss >> ch) {
		vec.push_back(ch - '0');
	}
}

BigInt::BigInt(int n) {
	if(n < 0) {
		positive = false;
		n        = -n;
	}
	vec = vector<unsigned short>();
	stringstream ss;
	ss << n;
	char ch;
	while(ss >> ch) {
		vec.push_back(ch - '0');
	}
}

BigInt::BigInt(long n) {
	if(n < 0) {
		positive = false;
		n        = -n;
	}
	vec = vector<unsigned short>();
	stringstream ss;
	ss << n;
	char ch;
	while(ss >> ch) {
		vec.push_back(ch - '0');
	}
}

BigInt::BigInt(long long int n) {
	if(n < 0) {
		positive = false;
		n        = -n;
	}
	vec = vector<unsigned short>();
	do {
		vec.push_back(n % 10);
		n /= 10;
	} while(n != 0);
}

BigInt::BigInt(unsigned short n) {
	vec = vector<unsigned short>();
	do {
		vec.push_back(n % 10);
		n /= 10;
	} while(n != 0);
}

BigInt::BigInt(unsigned int n) {
	vec = vector<unsigned short>();
	do {
		vec.push_back(n % 10);
		n /= 10;
	} while(n != 0);
}

BigInt::BigInt(unsigned long n) {
	vec = vector<unsigned short>();
	do {
		vec.push_back(n % 10);
		n /= 10;
	} while(n != 0);
}

BigInt::BigInt(unsigned long long int n) {
	vec = vector<unsigned short>();
	do {
		vec.push_back(n % 10);
		n /= 10;
	} while(n != 0);
}

BigInt::BigInt(const string &str) {
	int start_i = str.length() - 1;
	while(start_i >= 0 && isdigit(str[start_i]) != 0) {
		vec.push_back(str[start_i] - '0');
		start_i--;
	}
	if(str[0] == '-') {
		positive = false;
	}
}

BigInt::BigInt(const char *str) {
	int start_i = strlen(str) - 1;
	while(start_i >= 0 && isdigit(str[start_i]) != 0) {
		vec.push_back(str[start_i] - '0');
		start_i--;
	}
	if(str[0] == '-') {
		positive = false;
	}
}

BigInt::BigInt(const BigInt &bi) {
	int end_i = bi.vec.size() - 1;
	while(end_i >= 0 && bi.vec[end_i] == 0) {
		end_i--;
	}
	this->vec = vector<unsigned short>();
	for(int i = 0; i <= end_i; i++) {
		this->vec.push_back(bi.vec[i]);
	}
	if(this->vec.empty()) {
		this->vec.push_back(0);
	}
	this->positive = bi.positive;
}

BigInt BigInt::operator+(const BigInt &bi) const {
	if(this->positive && !bi.positive) {
		return *this - -bi;
	}
	if(!this->positive && bi.positive) {
		return bi - -*this;
	}
	vector<unsigned short> v;
	unsigned short carry = 0;
	for(long long i = 0; i < max(this->get_size(), bi.get_size()) || carry != 0; i++) {
		const unsigned short this_num = i < this->get_size() ? (*this)[i] : 0;
		const unsigned short bi_num   = i < bi.get_size() ? bi[i] : 0;
		unsigned short sum            = this_num + bi_num;
		sum += carry;
		carry = sum / 10;
		sum %= 10;
		v.push_back(sum);
	}
	auto ret = BigInt(v, this->positive);
	return ret;
}

BigInt BigInt::operator-(const BigInt &bi) const {
	if(this->positive != bi.positive) {
		return *this + -bi;
	}
	if(!this->positive) {
		return -bi - -*this;
	}
	if(*this < bi) {
		return -(bi - *this);
	}
	vector<unsigned short> v;
	unsigned short borrow = 0;
	for(long long i = 0; i < max(this->get_size(), bi.get_size()); i++) {
		short this_num     = i < this->get_size() ? (*this)[i] : 0;
		const short bi_num = i < bi.get_size() ? bi[i] : 0;
		this_num -= borrow;
		short diff = this_num - bi_num;
		borrow     = 0;
		while(diff < 0) {
			borrow++;
			diff += 10;
		}
		v.push_back(diff);
	}
	auto ret = BigInt(v, true);
	return ret;
}

vector<unsigned short> BigInt::operator*(const unsigned short n) const {
	vector<unsigned short> res;
	unsigned short c = 0;
	for(const auto v: this->vec) {
		unsigned short num = n * v + c;
		c                  = num / 10;
		num %= 10;
		res.emplace_back(num);
	}
	while(c > 0) {
		res.emplace_back(c % 10);
		c /= 10;
	}
	return res;
}

BigInt BigInt::operator*(const BigInt &bi) const {
	unsigned max_len = 0;
	vector<vector<unsigned short>> vecs(bi.vec.size());
	for(int i = 0; i < bi.vec.size(); i++) {
		vector<unsigned short> vi(i, 0);
		vector<unsigned short> ai = *this * bi.vec[i];
		vi.insert(vi.end(), ai.begin(), ai.end());
		vecs[i] = vi;
		max_len = max(max_len, static_cast<unsigned>(vi.size()));
	}
	vector<unsigned short> ans;
	unsigned short c = 0;
	for(int i = 0; i < max_len; i++) {
		unsigned int v = 0;
		for(int j = 0; j < vecs.size(); j++) {
			v += i < vecs[j].size() ? vecs[j][i] : 0;
		}
		v += c;
		c = v / 10;
		v %= 10;
		ans.emplace_back(v);
	}
	while(c > 0) {
		ans.emplace_back(c % 10);
		c /= 10;
	}
	return BigInt(ans, (*this).positive == bi.positive);
}

BigInt BigInt::operator/(const BigInt & /*bi*/) const { return *this; }

BigInt BigInt::operator%(const BigInt & /*bi*/) const { return *this; }

bool BigInt::operator>(const BigInt &bi) const {
	if(this->positive != bi.positive) {
		return this->positive;
	}
	if(!this->positive && !bi.positive) {
		return -*this < -bi;
	}
	if(this->get_size() != bi.get_size()) {
		return this->get_size() > bi.get_size();
	}

	for(int i = get_size() - 1; i >= 0; --i) {
		if((*this)[i] > bi[i]) {
			return true;
		}
		if((*this)[i] < bi[i]) {
			return false;
		}
		if((*this)[i] < bi[i]) {
			return false;
		}
	}
	return false;
}

bool BigInt::operator<(const BigInt &bi) const {
	if(this->positive != bi.positive) {
		return !this->positive;
	}
	if(!this->positive && !bi.positive) {
		return -*this > -bi;
	}
	if(this->get_size() != bi.get_size()) {
		return this->get_size() < bi.get_size();
	}
	return !(*this >= bi);
}

bool BigInt::operator==(const BigInt &bi) const {
	if(this->positive == bi.positive) {
		return this->vec == bi.vec;
	}
	return false;
}

bool BigInt::operator!=(const BigInt &bi) const {
	if(this->positive == bi.positive) {
		return this->vec != bi.vec;
	}
	return true;
}

bool BigInt::operator>=(const BigInt &bi) const { return *this == bi || *this > bi; }

bool BigInt::operator<=(const BigInt &bi) const { return *this == bi || *this < bi; }

BigInt &BigInt::operator+=(const BigInt &bi) {
	*this = *this + bi;
	return *this;
}

BigInt &BigInt::operator-=(const BigInt &bi) {
	*this = *this - bi;
	return *this;
}

BigInt &BigInt::operator*=(const BigInt &bi) {
	*this = *this * bi;
	return *this;
}

BigInt &BigInt::operator/=(const BigInt &bi) {
	*this = *this / bi;
	return *this;
}

BigInt &BigInt::operator%=(const BigInt &bi) {
	*this = *this % bi;
	return *this;
}

ostream &operator<<(ostream &os, const BigInt &bi) {
	if(!bi.positive) {
		os << '-';
	}
	for(auto it = bi.vec.rbegin(); it != bi.vec.rend(); ++it) {
		os << *it;
	}
	return os;
}

istream &operator>>(istream &is, const BigInt & /*bi*/) { return is; }

BigInt BigInt::operator-() const { return BigInt(this->vec, !this->positive); }

BigInt &BigInt::operator++() {
	*this += 1;
	return *this;
}

BigInt &BigInt::operator--() {
	*this -= 1;
	return *this;
}

BigInt BigInt::operator++(int) {
	auto ret = BigInt(*this);
	*this += 1;
	return ret;
}

BigInt BigInt::operator--(int) {
	auto ret = BigInt(*this);
	*this -= 1;
	return ret;
}
BigInt::BigInt() {
	vec      = vector<unsigned short>();
	positive = true;
}

bool Fraction::is_positive() const { return positive; }

unsigned long long Fraction::get_numerator() const { return numerator; }

unsigned long long Fraction::get_denominator() const { return denominator; }

void Fraction::simplify() {
	const unsigned long long factor = gcd(numerator, denominator);
	numerator /= factor;
	denominator /= factor;
}

Fraction::Fraction(bool positive, long long numerator, long long denominator) {
	if(numerator < 0) {
		positive = !positive;
	}
	if(denominator < 0) {
		positive = !positive;
	}
	this->positive    = positive;
	this->numerator   = abs(numerator);
	this->denominator = abs(denominator);
	this->simplify();
}

Fraction Fraction::operator+(const Fraction &f) const {
	long long numerator1 = this->numerator * f.denominator;
	long long numerator2 = this->denominator * f.numerator;
	if(!this->positive) {
		numerator1 = -numerator1;
	}
	if(!f.positive) {
		numerator2 = -numerator2;
	}
	return {true, numerator1 + numerator2, static_cast<long long>(this->denominator * f.denominator)};
}

Fraction Fraction::operator-(const Fraction &f) const {
	long long numerator1 = this->numerator * f.denominator;
	long long numerator2 = this->denominator * f.numerator;
	if(!this->positive) {
		numerator1 = -numerator1;
	}
	if(!f.positive) {
		numerator2 = -numerator2;
	}
	return {true, numerator1 - numerator2, static_cast<long long>(this->denominator * f.denominator)};
}

Fraction Fraction::operator*(const Fraction &f) const {
	long long numerator1 = this->numerator;
	long long numerator2 = f.numerator;
	if(!this->positive) {
		numerator1 = -numerator1;
	}
	if(!f.positive) {
		numerator2 = -numerator2;
	}
	return {true, numerator1 * numerator2, static_cast<long long>(this->denominator * f.denominator)};
}

Fraction Fraction::operator/(const Fraction &f) const { return *this * Fraction(f.positive, f.denominator, f.numerator); }

ostream &operator<<(ostream &os, const Fraction &frac) {
	if(frac.denominator == 0) {
		os << "Inf";
		return os;
	}
	if(frac.numerator == 0) {
		os << 0;
		return os;
	}
	if(!frac.positive) {
		os << "(-";
	}
	if(frac.numerator % frac.denominator == 0) {
		os << frac.numerator / frac.denominator;
	} else {
		if(frac.numerator / frac.denominator != 0) {
			os << frac.numerator / frac.denominator << ' ';
		}
		os << frac.numerator % frac.denominator << '/' << frac.denominator;
	}
	if(!frac.positive) {
		os << ")";
	}
	return os;
}

UnionFind::UnionFind(int n) {
	this->parent = vector<int>(n);
	this->rank   = vector<int>(n);
	this->size   = vector<int>(n);
	for(int i = 0; i < n; i++) {
		this->parent[i] = i;
		this->rank[i]   = 0;
		size[i]         = 1;
	}
}

int UnionFind::find(int x) {
	if(parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void UnionFind::unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) {
		return;
	}
	if(rank[x] < rank[y]) {
		parent[x] = y;
		size[y] += size[x];
	} else {
		parent[y] = x;
		size[x] += size[y];
		if(rank[x] == rank[y]) {
			rank[x]++;
		}
	}
}

bool UnionFind::same(int x, int y) { return find(x) == find(y); }

int UnionFind::get_size(int x) { return size[find(x)]; }

unsigned UnionFind::count() {
	unordered_set<int> us;
	for(int i = 0; i < size.size(); i++) {
		us.insert(find(i));
	}
	return us.size();
}

Matrix::Matrix(int n) { mat = vector<vector<int>>(n, vector<int>(n, 0)); }

Matrix::Matrix(const Matrix &m) {
	mat = vector<vector<int>>(m.mat.size(), vector<int>(m.mat.size(), 0));
	for(int i = 0; i < m.mat.size(); i++) {
		for(int j = 0; j < m.mat.size(); j++) {
			mat[i][j] = m.mat[i][j];
		}
	}
}

Matrix Matrix::operator*(const Matrix &m) const {
	Matrix ret(mat.size());
	for(int i = 0; i < mat.size(); i++) {
		for(int j = 0; j < mat.size(); j++) {
			for(int k = 0; k < mat.size(); k++) {
				ret.mat[i][j] += mat[i][k] * m.mat[k][j];
			}
		}
	}
	return ret;
}

vector<int> &Matrix::operator[](int i) {
	return mat[i];
}

const vector<int> &Matrix::operator[](int i) const {
	return mat[i];
}

Matrix Matrix::identity(int n) {
	Matrix ret(n);
	for(int i = 0; i < n; i++) {
		ret.mat[i][i] = 1;
	}
	return ret;
}

char huffman::get_c() const { return c; }

huffman *huffman::get_left() const { return left; }

huffman *huffman::get_right() const { return right; }

int huffman::get_weight() const { return weight; }

bool operator<(const huffman &h1, const huffman &h2) {
	return h1.get_weight() > h2.get_weight();
}

pair<string, huffman *> huffman::compress(string input) {
	int counter[26] = {};
	memset(counter, 0, sizeof(counter));
	for(char c: input) {
		counter[c - 'a']++;
	}
	priority_queue<huffman *, vector<huffman *>, huffman_ptr_comp> pq = {};
	for(int i = 0; i < 26; i++) {
		pq.push(new huffman(i + 'a', nullptr, nullptr, counter[i]));
	}
	while(pq.size() >= 2) {
		huffman *h1 = pq.top();
		pq.pop();
		huffman *h2 = pq.top();
		pq.pop();
		auto *n = new huffman('\0', h1, h2, h1->get_weight() + h2->get_weight());
		pq.push(n);
	}
	huffman *top = pq.top();
	pq.pop();
	huffman::gen_table("", top, top);
	ostringstream ans = {};
	for(char c: input) {
		ans << top->table[c];
	}
	return make_pair(ans.str(), top);
}

void huffman::gen_table(string str, huffman *current, huffman *top) {
	if(current->left == nullptr && current->right == nullptr) {
		top->table[current->get_c()] = str;
	}
	if(current->left != nullptr) {
		gen_table(str + '0', current->left, top);
	}
	if(current->right != nullptr) {
		gen_table(str + '1', current->right, top);
	}
}

string huffman::decompress(string input) {
	vector<char> ans = {};
	huffman *current = this;
	for(char ch: input) {
		if(ch == '0') {
			current = current->left;
		} else {
			current = current->right;
		}
		if(current->get_left() == nullptr && current->get_right() == nullptr) {
			ans.push_back(current->get_c());
			current = this;
		}
	}
	ostringstream oss = {};
	for(char ch: ans) {
		oss << ch;
	}
	return oss.str();
}

bool huffman_ptr_comp::operator()(const huffman *a, const huffman *b) const {
	return a->get_weight() < b->get_weight();
}

namespace elias_gamma {
	vector<bool> encode(vector<bool> input) {
		vector<int> len_list = {};
		vector<bool> ans     = {};
		ans.push_back(static_cast<unsigned short>(input[0] ? 1 : 0));
		//len_list.push_back(input[0]);
		bool current    = input[0];
		int current_len = 0;
		for(bool c: input) {
			if(c == current) {
				current_len++;
			} else {
				len_list.push_back(current_len);
				current_len = 1;
				current     = c;
			}
		}
		len_list.push_back(current_len);

		for(auto len: len_list) {
			ostringstream oss = {};
			vector<bool> seg  = {};
			int bits          = std::bit_width(static_cast<unsigned int>(len));
			for(int i = 0; i < bits - 1; i++) {
				seg.push_back(false);
			}
			for(int i = bits - 1; i >= 0; i--) {
				seg.push_back((len >> i) & 1);
			}
			ans.insert(ans.end(), seg.begin(), seg.end());
		}
		return ans;
	}
	vector<bool> decode(vector<bool> input) {
		if(input.empty())
			return {};
		bool flag = input[0];
		vector<bool> ans;
		int i = 1;
		while(i < input.size()) {
			int zero_cnt = 0;
			while(i < input.size() && !input[i]) {
				zero_cnt++;
				i++;
			}
			if(i >= input.size())
				break;
			int len          = 0;
			int bits_to_read = zero_cnt + 1;
			for(int j = 0; j < bits_to_read; j++) {
				len = (len << 1) | (input[i] ? 1 : 0);
				i++;
			}
			for(int k = 0; k < len; k++)
				ans.push_back(flag);
			flag = !flag;
		}
		return ans;
	}
}// namespace elias_gamma

namespace lzw {
	pair<vector<int>, unordered_map<int, string>> encode(string input) {
		unordered_set<string> table = {};
		vector<string> wordlist     = {};
		for(char c: input) {
			string s;
			s.push_back(c);
			table.insert(s);
		}
		int i = 0;
		string word;
		for(int j = 0; j < input.size(); j++) {
			auto substr = input.substr(i, j - i + 1);
			if(!table.contains(substr)) {
				wordlist.push_back(word);
				table.insert(substr);
				i    = j;
				word = input.substr(j, 1);
			} else {
				word = substr;
			}
		}
		wordlist.push_back(word);
		vector<string> vec(table.begin(), table.end());
		unordered_map<string, int> um = {};
		for(int i = 0; i < vec.size(); i++) {
			um[vec[i]] = i;
		}
		vector<int> ans(wordlist.size());
		for(int i = 0; i < wordlist.size(); i++) {
			ans[i] = um[wordlist[i]];
		}
		unordered_map<int, string> um2 = {};
		for(auto &[k, v]: um) {
			um2[v] = k;
		}
		return make_pair(ans, um2);
	}

	string decode(vector<int> input, unordered_map<int, string> dict) {
		ostringstream oss = {};
		for(int i: input) {
			oss << dict[i];
		}
		return oss.str();
	}
}// namespace lzw

namespace mtf {
	vector<int> encode(string input) {
		list<char> dict = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
		int i           = 0;
		vector<int> ans(input.size());
		for(char c: input) {
			int index = -1;
			for(auto it = dict.begin(); it != dict.end(); ++it) {
				if(*it == c) {
					index    = std::distance(dict.begin(), it);
					ans[i++] = index;
					dict.erase(it);
					break;
				}
			}
			dict.push_front(c);
		}
		return ans;
	}
	string decode(vector<int> input) {
		list<char> dict   = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
		ostringstream ans = {};
		for(int i: input) {
			auto it = dict.begin();
			char c;
			for(int j = 0; j < i; j++) {
				++it;
			}
			c = *it;
			dict.erase(it);
			ans << c;
			dict.push_front(c);
		}
		return ans.str();
	}
}// namespace mtf

namespace bwt {
	string encode(string input) {
		deque<char> deq(input.begin(), input.end());
		deq.push_back('$');
		ostringstream oss = {};
		vector<string> vec(deq.size());

		for(int i = 0; i < deq.size(); i++) {
			for(auto c: deq) {
				oss << c;
			}
			deq.push_back(deq.front());
			deq.pop_front();
			vec[i] = oss.str();
			oss    = ostringstream();
		}
		ranges::sort(vec.begin(), vec.end());
		for(string str: vec) {
			oss << str.back();
		}
		return oss.str();
	}
	struct node {
		char c;
		int order                                                 = 0;
		bool operator==(vector<node>::const_reference node) const = default;
	};
	string decode(string input) {
		vector<node> l               = {};
		unordered_map<char, int> cnt = {};
		for(char c: input) {
			l.push_back(node{c, cnt[c]});
			cnt[c]++;
		}
		vector<node> f = l;
		sort(f.begin(), f.end(), [](const node &a, const node &b) {
			if(a.c != b.c) {
				return a.c < b.c;
			} else {
				return a.order < b.order;
			}
		});
		deque<char> deq;
		int cur = 0;
		for(int j = 0; j < f.size() - 1; j++) {
			deq.push_front(l[cur].c);
			for(int i = 0; i < f.size(); i++) {
				if(f[i] == l[cur]) {
					cur = i;
					break;
				}
			}
		}
		ostringstream oss = {};
		for(char c: deq) {
			oss << c;
		}
		return oss.str();
	}
}// namespace bwt

namespace hamming {
	vector<bool> encode(vector<bool> input) {
		vector<bool> ans = {};
		for(int i = 0; i < input.size();) {
			unsigned int index = ans.size() + 1;
			if(std::popcount(index) == 1) {
				ans.push_back(false);
			} else {
				ans.push_back(input[i]);
				i++;
			}
		}
		for(int i = 0; i < ans.size(); i++) {
			unsigned int j = i + 1;
			if(std::popcount(j) != 1) {
				for(int k = 0; (1 << k) - 1 < ans.size(); k++) {
					if((i + 1) & (1 << k)) {
						ans[(1 << k) - 1] = ans[(1 << k) - 1] ^ ans[i];
					}
				}
			}
		}
		return ans;
	}
	vector<bool> correct(vector<bool> input) {
		unsigned int error_i = 0;
		for(unsigned int i = 0; i < input.size(); i++) {
			unsigned int real_i = i + 1;
			if(input[i] == 1) {
				error_i ^= real_i;
			}
		}
		input[error_i - 1] = !input[error_i - 1];
		return input;
	}
}// namespace hamming