cmake_minimum_required(VERSION 3.21)
project(problemscpp)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:67108864")
endif ()

find_package(GTest)

if (NOT ${GTest_FOUND})
    message("GTest NOT FOUND")
    include(FetchContent)
    FetchContent_Declare(
            googletest
            # Specify the commit you depend on and update it regularly.
            URL https://codeload.github.com/google/googletest/zip/release-1.11.0
            )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif ()

# Now simply link against gtest or gtest_main as needed. Eg
include(GoogleTest)
enable_testing()
add_executable(problemscpp main.cpp acwing.cpp acwing.h lintcode.cpp lintcode.h leetcode.cpp leetcode.h luogu.cpp luogu.h leetcode_test.cpp lintcode_test.cpp acwing_test.cpp luogu_test.cpp set_stack_limit.cpp templates.h templates_test.cpp pat.cpp pat.h pat_test.cpp templates.cpp
               acwing408.cpp
               acwing408.h
               acwing408_test.cpp
               comp526.h
               comp526.cpp
               comp526_test.cpp
               codeforces.h
               codeforces.cpp
               codeforces_test.cpp
               )
target_link_libraries(problemscpp PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
gtest_discover_tests(problemscpp)
add_test(NAME problemscpp COMMAND problemscpp)