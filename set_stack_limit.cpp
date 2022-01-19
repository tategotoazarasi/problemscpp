#if defined(linux)
#include <iostream>
#include <sys/resource.h>

int set_stack_limit(int stack_size) {
	rlim_t kStackSize = stack_size;// min stack size = 16 MB
	struct rlimit rl {};

	int result = getrlimit(RLIMIT_STACK, &rl);
	if(result == 0 && rl.rlim_cur < kStackSize) {
		rl.rlim_cur = kStackSize;
		result      = setrlimit(RLIMIT_STACK, &rl);
		if(result != 0) {
			std::cerr << "setrlimit returned result = " << result << std::endl;
		}
	}
	return result;
}
#else
int set_stack_limit(int /*stack_size*/) { return 0; }
#endif
