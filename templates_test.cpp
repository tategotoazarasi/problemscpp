#include "templates.h"
#include "gtest/gtest.h"
#include <sstream>

using namespace std;

TEST(BigInt, plus1) {
	BigInt bi1 = "112233445566778899";
	BigInt bi2 = "9988776655443322";
	BigInt bi  = bi1 + bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("122222222222222221", ans);
}

TEST(BigInt, plus2) {
	BigInt bi1 = "-57483928028032689427590";
	BigInt bi2 = "-1093857940790276890525749302";
	BigInt bi  = bi1 + bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("-1093915424718304923215176892", ans);
}

TEST(BigInt, comp1) {
	BigInt bi1 = "-57483928028032689427590";
	BigInt bi2 = "-1093857940790276890525749302";
	ASSERT_TRUE(bi1 != bi2);
}

TEST(BigInt, comp2) {
	BigInt bi1 = "-57483928028032689427590";
	BigInt bi2 = "-57483928028032689427590";
	ASSERT_TRUE(bi1 == bi2);
}

TEST(BigInt, comp3) {
	BigInt bi1 = "-57483928028032689427590";
	BigInt bi2 = "-1093857940790276890525749302";
	ASSERT_TRUE(bi1 > bi2);
}

TEST(BigInt, comp4) {
	BigInt bi1 = "-57483928028032689427590";
	BigInt bi2 = "-57483928028032689427591";
	ASSERT_TRUE(bi1 >= bi2);
}

TEST(BigInt, comp5) {
	BigInt bi1 = "-57483928028032689427590";
	BigInt bi2 = "57483928028032689427590";
	ASSERT_TRUE(bi1 <= bi2);
}

TEST(BigInt, comp6) {
	BigInt bi1 = "57483928028032689427590";
	BigInt bi2 = "-57483928028032689427590";
	ASSERT_TRUE(bi1 > bi2);
}

TEST(BigInt, comp7) {
	BigInt bi1 = "44324324";
	ASSERT_TRUE(bi1 > 456);
}

TEST(BigInt, minus1) {
	BigInt bi1 = "-57483928028032689427590";
	BigInt bi2 = "-1093857940790276890525749302";
	BigInt bi  = bi1 - bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("1093800456862248857836321712", ans);
}

TEST(BigInt, minus2) {
	BigInt bi1 = "52785940326406280942375";
	BigInt bi2 = "432463829";
	BigInt bi  = bi1 - bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("52785940326405848478546", ans);
}

TEST(BigInt, minus3) {
	BigInt bi1 = "9421965382";
	BigInt bi2 = "7589436289289054";
	BigInt bi  = bi1 - bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("-7589426867323672", ans);
}

TEST(BigInt, minus4) {
	BigInt bi1 = "-4214325";
	BigInt bi2 = "-4781955555";
	BigInt bi  = bi1 - bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("4777741230", ans);
}