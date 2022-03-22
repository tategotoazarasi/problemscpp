#include "templates.h"
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

unsigned long BigInt::get_size() const {
	return vec.size();
}

unsigned short BigInt::operator[](unsigned long i) const {
	return vec[i];
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
	if(str[0] == '-') {
		positive = false;
		vec      = vector<unsigned short>(str.length() - 1);
		for(int i = 1; i < str.length(); i++) {
			vec[i - 1] = str[i] - '0';
		}
	} else {
		vec = vector<unsigned short>(str.length());
		for(int i = 0; i < str.length(); i++) {
			vec[i] = str[i] - '0';
		}
	}
}

BigInt::BigInt(const BigInt &bi) {
	this->vec      = vector(bi.vec);
	this->positive = bi.positive;
}

BigInt &BigInt::operator=(const BigInt &bi) {
	this->vec      = vector(bi.vec);
	this->positive = bi.positive;
	return *this;
}

BigInt &BigInt::operator=(const string &str) {
	if(str[0] == '-') {
		positive = false;
		vec      = vector<unsigned short>(str.length() - 1);
		for(int i = 1; i < str.length(); i++) {
			vec[i - 1] = str[i] - '0';
		}
	} else {
		vec = vector<unsigned short>(str.length());
		for(int i = 0; i < str.length(); i++) {
			vec[i] = str[i] - '0';
		}
	}
	return *this;
}

BigInt &BigInt::operator=(int n) {
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
	return *this;
}

BigInt &BigInt::operator=(short n) {
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
	return *this;
}

BigInt &BigInt::operator=(long n) {
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
	return *this;
}

BigInt &BigInt::operator=(long long int n) {
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
	return *this;
}

BigInt &BigInt::operator=(const unsigned short &n) {
	vec = vector<unsigned short>();
	stringstream ss;
	ss << n;
	char ch;
	while(ss >> ch) {
		vec.push_back(ch - '0');
	}
	return *this;
}

BigInt &BigInt::operator=(const unsigned int &n) {
	vec = vector<unsigned short>();
	stringstream ss;
	ss << n;
	char ch;
	while(ss >> ch) {
		vec.push_back(ch - '0');
	}
	return *this;
}

BigInt &BigInt::operator=(const unsigned long &n) {
	vec = vector<unsigned short>();
	stringstream ss;
	ss << n;
	char ch;
	while(ss >> ch) {
		vec.push_back(ch - '0');
	}
	return *this;
}

BigInt &BigInt::operator=(const unsigned long long int &n) {
	vec = vector<unsigned short>();
	stringstream ss;
	ss << n;
	char ch;
	while(ss >> ch) {
		vec.push_back(ch - '0');
	}
	return *this;
}

BigInt BigInt::operator+(const BigInt &bi) const {
	return *this;
}

BigInt BigInt::operator-(const BigInt &bi) const {
	return *this;
}

BigInt BigInt::operator*(const BigInt &bi) const {
	return *this;
}

BigInt BigInt::operator/(const BigInt &bi) const {
	return *this;
}

BigInt BigInt::operator%(const BigInt &bi) const {
	return *this;
}

bool BigInt::operator>(const BigInt &bi) const {
	return true;
}

bool BigInt::operator<(const BigInt &bi) const {
	return true;
}

bool BigInt::operator==(const BigInt &bi) const {
	return true;
}

bool BigInt::operator!=(const BigInt &bi) const {
	return true;
}

bool BigInt::operator>=(const BigInt &bi) const {
	return true;
}

bool BigInt::operator<=(const BigInt &bi) const {
	return true;
}

BigInt &BigInt::operator+=(const BigInt &bi) {
	return *this;
}

BigInt &BigInt::operator-=(const BigInt &bi) {
	return *this;
}

BigInt &BigInt::operator*=(const BigInt &bi) {
	return *this;
}

BigInt &BigInt::operator/=(const BigInt &bi) {
	return *this;
}

BigInt &BigInt::operator%=(const BigInt &bi) {
	return *this;
}

ostream &operator<<(ostream &os, const BigInt &) {
}

istream &operator>>(istream &is, const BigInt &) {
}