#include "gtest/gtest.h"

int set_stack_limit(int stack_size);

int main(int argc, char **argv) {
	set_stack_limit(64 * 1024 * 1024);// min stack size = 64 MB
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
