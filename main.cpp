#include "gtest/gtest.h"

int set_stack_limit();

int main(int argc, char **argv) {
	set_stack_limit();
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
