cmake_minimum_required(VERSION 3.21)
project(problemscpp)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com.cnpmjs.org/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(problemscpp main.cpp acwing.cpp acwing.h lintcode.cpp lintcode.h leetcode.cpp leetcode.h luogu.cpp luogu.h leetcode_test.cpp lintcode_test.cpp acwing_test.cpp luogu_test.cpp)
target_link_libraries(problemscpp gtest_main)
add_test(NAME problemscpp COMMAND problemscpp)