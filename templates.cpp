#include "templates.h"
#include <numeric>
#include <sstream>

using namespace std;

void TrieNode::insert(const string &str) {
	if(this->nexts[str[0] - 'a'] == nullptr) {
		this->nexts[str[0] - 'a'] = new TrieNode(str[0]);
	}
	if(str.length() == 1) {
		this->nexts[str[0] - 'a']->end_of_word = true;
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
	int start_i = 0;
	while(vec[start_i] == 0) {
		start_i++;
	}
	this->vec = vector<unsigned short>();
	for(int i = start_i; i < vec.size(); i++) {
		this->vec.push_back(vec[i]);
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
	stringstream ss;
	ss << n;
	char ch;
	while(ss >> ch) {
		vec.push_back(ch - '0');
	}
}

BigInt::BigInt(const unsigned short &n) {
	vec = vector<unsigned short>();
	stringstream ss;
	ss << n;
	char ch;
	while(ss >> ch) {
		vec.push_back(ch - '0');
	}
}

BigInt::BigInt(const unsigned int &n) {
	vec = vector<unsigned short>();
	stringstream ss;
	ss << n;
	char ch;
	while(ss >> ch) {
		vec.push_back(ch - '0');
	}
}

BigInt::BigInt(const unsigned long &n) {
	vec = vector<unsigned short>();
	stringstream ss;
	ss << n;
	char ch;
	while(ss >> ch) {
		vec.push_back(ch - '0');
	}
}

BigInt::BigInt(const unsigned long long int &n) {
	vec = vector<unsigned short>();
	stringstream ss;
	ss << n;
	char ch;
	while(ss >> ch) {
		vec.push_back(ch - '0');
	}
}

BigInt::BigInt(const string &str) {
	int start_i = 0;
	if(str[0] == '-') {
		positive = false;
		start_i  = 1;
	}
	while(str[start_i] == '0') {
		start_i++;
	}
	vec = vector<unsigned short>();
	for(int i = start_i; i < str.length(); i++) {
		vec.push_back(str[i] - '0');
	}
}

BigInt::BigInt(const char *str) {
	int start_i = 0;
	if(str[0] == '-') {
		positive = false;
		start_i  = 1;
	}
	while(str[start_i] == '0') {
		start_i++;
	}
	vec = vector<unsigned short>();
	for(int i = start_i; str[i] != '\0'; i++) {
		vec.push_back(str[i] - '0');
	}
}

BigInt::BigInt(const BigInt &bi) {
	int start_i = 0;
	while(bi[start_i] == 0) {
		start_i++;
	}
	this->vec = vector<unsigned short>();
	for(int i = start_i; i < bi.get_size(); i++) {
		this->vec.push_back(bi[i]);
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
		const unsigned short this_num = static_cast<long long>(this->get_size()) - i - 1 >= 0 ? (*this)[this->get_size() - i - 1] : 0;
		const unsigned short bi_num   = static_cast<long long>(bi.get_size()) - i - 1 >= 0 ? bi[bi.get_size() - i - 1] : 0;
		unsigned short sum            = this_num + bi_num;
		sum += carry;
		carry = sum / 10;
		sum %= 10;
		v.push_back(sum);
	}
	v        = vector(v.rbegin(), v.rend());
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
		short this_num     = static_cast<long long>(this->get_size()) - i - 1 >= 0 ? (*this)[this->get_size() - i - 1] : 0;
		const short bi_num = static_cast<long long>(bi.get_size()) - i - 1 >= 0 ? bi[bi.get_size() - i - 1] : 0;
		this_num -= borrow;
		short diff = this_num - bi_num;
		borrow     = 0;
		while(diff < 0) {
			borrow++;
			diff += 10;
		}
		v.push_back(diff);
	}
	v        = vector(v.rbegin(), v.rend());
	auto ret = BigInt(v, true);
	return ret;
}

vector<unsigned short> BigInt::operator*(const unsigned short /*n*/) const { return {}; }

BigInt BigInt::operator*(const BigInt & /*bi*/) const { return *this; }

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

	for(int i = 0; i < get_size(); i++) {
		if((*this)[i] > bi[i]) {
			return true;
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
	for(const auto num: bi.vec) {
		os << num;
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
