#include "templates.h"
#include "gtest/gtest.h"
#include <sstream>

using namespace std;

TEST(BigInt, plus1) {
	const BigInt bi1 = "112233445566778899";
	const BigInt bi2 = "9988776655443322";
	const BigInt bi  = bi1 + bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("122222222222222221", ans);
}

TEST(BigInt, plus2) {
	const BigInt bi1 = "1";
	const BigInt bi2 = "999999999";
	const BigInt bi  = bi1 + bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("1000000000", ans);
}

TEST(BigInt, plus3) {
	const BigInt bi1 = "-57483928028032689427590";
	const BigInt bi2 = "-1093857940790276890525749302";
	const BigInt bi  = bi1 + bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("-1093915424718304923215176892", ans);
}

TEST(BigInt, comp1) {
	const BigInt bi1 = "-57483928028032689427590";
	const BigInt bi2 = "-1093857940790276890525749302";
	ASSERT_TRUE(bi1 != bi2);
}

TEST(BigInt, comp2) {
	const BigInt bi1 = "-57483928028032689427590";
	const BigInt bi2 = "-57483928028032689427590";
	ASSERT_TRUE(bi1 == bi2);
}

TEST(BigInt, comp3) {
	const BigInt bi1 = "-57483928028032689427590";
	const BigInt bi2 = "-1093857940790276890525749302";
	ASSERT_TRUE(bi1 > bi2);
}

TEST(BigInt, comp4) {
	const BigInt bi1 = "-57483928028032689427590";
	const BigInt bi2 = "-57483928028032689427591";
	ASSERT_TRUE(bi1 >= bi2);
}

TEST(BigInt, comp5) {
	const BigInt bi1 = "-57483928028032689427590";
	const BigInt bi2 = "57483928028032689427590";
	ASSERT_TRUE(bi1 <= bi2);
}

TEST(BigInt, comp6) {
	const BigInt bi1 = "57483928028032689427590";
	const BigInt bi2 = "-57483928028032689427590";
	ASSERT_TRUE(bi1 > bi2);
}

TEST(BigInt, comp7) {
	const BigInt bi1 = "44324324";
	ASSERT_TRUE(bi1 > 456);
}

TEST(BigInt, minus1) {
	const BigInt bi1 = "-57483928028032689427590";
	const BigInt bi2 = "-1093857940790276890525749302";
	const BigInt bi  = bi1 - bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("1093800456862248857836321712", ans);
}

TEST(BigInt, minus2) {
	const BigInt bi1 = "52785940326406280942375";
	const BigInt bi2 = "432463829";
	const BigInt bi  = bi1 - bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("52785940326405848478546", ans);
}

TEST(BigInt, minus3) {
	const BigInt bi1 = "9421965382";
	const BigInt bi2 = "7589436289289054";
	const BigInt bi  = bi1 - bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("-7589426867323672", ans);
}

TEST(BigInt, minus4) {
	const BigInt bi1 = "-4214325";
	const BigInt bi2 = "-4781955555";
	const BigInt bi  = bi1 - bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("4777741230", ans);
}

TEST(BigInt, minus5) {
	const BigInt bi1 = "123456789";
	const BigInt bi2 = "987654321";
	const BigInt bi  = bi1 - bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("-864197532", ans);
}

TEST(BigInt, multiply1) {
	const BigInt bi1 = "123456789";
	const BigInt bi2 = "987654321";
	const BigInt bi  = bi1 * bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("121932631112635269", ans);
}

TEST(BigInt, multiply2) {
	const BigInt bi1 = "73892532615";
	const BigInt bi2 = "-544835983274";
	const BigInt bi  = bi1 * bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("-40259310663899639481510", ans);
}

TEST(BigInt, multiply3) {
	const BigInt bi1 = "-57843957920564789329632578432578924635789325423789";
	const BigInt bi2 = "-5746578193211561278947328194319125";
	const BigInt bi  = bi1 * bi2;
	stringstream ss;
	ss << bi;
	string ans;
	ss >> ans;
	ASSERT_EQ("332404827195364786322355785444558091034080578559256965088672851184934586482932664625", ans);
}

TEST(AVLNodeTest, ConstructionAndGetters) {
	AVLNode<int> node(10);
	ASSERT_EQ(node.get_value(), 10);
	ASSERT_EQ(node.get_height(), 1);
	ASSERT_EQ(node.get_left(), nullptr);
	ASSERT_EQ(node.get_right(), nullptr);
	ASSERT_EQ(node.get_parent(), nullptr);
}

TEST(AVLNodeTest, Setters) {
	AVLNode<int> node(10);
	AVLNode<int> left_child(5);
	AVLNode<int> right_child(15);
	AVLNode<int> parent(20);

	node.set_value(99);
	ASSERT_EQ(node.get_value(), 99);

	node.set_height(5);
	ASSERT_EQ(node.get_height(), 5);

	node.set_left(&left_child);
	ASSERT_EQ(node.get_left(), &left_child);
	ASSERT_EQ(node.get_left()->get_value(), 5);

	node.set_right(&right_child);
	ASSERT_EQ(node.get_right(), &right_child);
	ASSERT_EQ(node.get_right()->get_value(), 15);

	node.set_parent(&parent);
	ASSERT_EQ(node.get_parent(), &parent);
	ASSERT_EQ(node.get_parent()->get_value(), 20);
}


TEST(AVLNodeTest, SimpleInsertion) {
	AVLNode<int> root(10);
	AVLNode<int> node5(5);
	AVLNode<int> node15(15);

	// Insert a smaller value
	root.insert(&node5);
	ASSERT_EQ(root.get_left(), &node5);
	ASSERT_EQ(root.get_right(), nullptr);
	ASSERT_EQ(node5.get_parent(), &root);
	// Check height updates
	ASSERT_EQ(node5.get_height(), 1);
	ASSERT_EQ(root.get_height(), 2);

	// Insert a larger value
	root.insert(&node15);
	ASSERT_EQ(root.get_left(), &node5);
	ASSERT_EQ(root.get_right(), &node15);
	ASSERT_EQ(node15.get_parent(), &root);
	// Check height updates
	ASSERT_EQ(node15.get_height(), 1);
	ASSERT_EQ(root.get_height(), 2);// max(left_height, right_height) + 1 -> max(1, 1) + 1 = 2
}

TEST(AVLNodeTest, DeeperInsertionAndFind) {
	// Create nodes
	AVLNode<int> root(20);
	AVLNode<int> node10(10);
	AVLNode<int> node30(30);
	AVLNode<int> node5(5);
	AVLNode<int> node15(15);
	AVLNode<int> node25(25);
	AVLNode<int> node35(35);

	// Insert them
	root.insert(&node10);
	root.insert(&node30);
	root.insert(&node5);
	root.insert(&node15);
	root.insert(&node25);
	root.insert(&node35);

	/*
     * The resulting tree structure should be:
     * 20 (h=3)
     * /  \
     * 10(h=2) 30(h=2)
     * / \     / \
     * 5 15   25  35  (all h=1)
    */

	// Verify structure
	ASSERT_EQ(root.get_left(), &node10);
	ASSERT_EQ(root.get_right(), &node30);
	ASSERT_EQ(node10.get_parent(), &root);
	ASSERT_EQ(node30.get_parent(), &root);

	ASSERT_EQ(node10.get_left(), &node5);
	ASSERT_EQ(node10.get_right(), &node15);
	ASSERT_EQ(node5.get_parent(), &node10);
	ASSERT_EQ(node15.get_parent(), &node10);

	ASSERT_EQ(node30.get_left(), &node25);
	ASSERT_EQ(node30.get_right(), &node35);
	ASSERT_EQ(node25.get_parent(), &node30);
	ASSERT_EQ(node35.get_parent(), &node30);

	// Verify heights
	ASSERT_EQ(root.get_height(), 3);
	ASSERT_EQ(node10.get_height(), 2);
	ASSERT_EQ(node30.get_height(), 2);
	ASSERT_EQ(node5.get_height(), 1);
	ASSERT_EQ(node15.get_height(), 1);
	ASSERT_EQ(node25.get_height(), 1);
	ASSERT_EQ(node35.get_height(), 1);

	// Verify find method (for existing values)
	ASSERT_EQ(root.find(20), &root);
	ASSERT_EQ(root.find(10), &node10);
	ASSERT_EQ(root.find(35), &node35);
	ASSERT_EQ(root.find(15), &node15);
}