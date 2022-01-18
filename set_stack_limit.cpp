//
// Created by tategotoazarasi on 2022/1/18.
//
#if defined(linux)
#include <iostream>
#include <sys/resource.h>

int set_stack_limit() {
	const rlim_t kStackSize = 64 * 1024 * 1024;// min stack size = 16 MB
	struct rlimit rl {};
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if(result == 0) {
		if(rl.rlim_cur < kStackSize) {
			rl.rlim_cur = kStackSize;
			result      = setrlimit(RLIMIT_STACK, &rl);
			if(result != 0) {
				std::cerr << "setrlimit returned result = " << result << std::endl;
			}
		}
	}
	return result;
}
#elif
int set_stack_limit() {
	return 0;
}
#endif