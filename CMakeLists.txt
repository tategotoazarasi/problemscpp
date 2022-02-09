cmake_minimum_required(VERSION 3.21)
project(problemscpp)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:67108864")
    set(GTEST_URL https://archive.fastgit.org/google/googletest/archive/release-1.11.0.zip)
else ()
    set(GTEST_URL https://codeload.github.com/google/googletest/zip/release-1.11.0)
endif ()

find_package(PkgConfig REQUIRED)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(googletest gtest)
endif ()

if (NOT ${PkgConfig_FOUND} OR (NOT DEFINED ${googletest_FOUND}) OR (NOT ${googletest_FOUND}))
    include(FetchContent)
    FetchContent_Declare(
            googletest
            # Specify the commit you depend on and update it regularly.
            URL ${GTEST_URL}
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif ()

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(problemscpp main.cpp acwing.cpp acwing.h lintcode.cpp lintcode.h leetcode.cpp leetcode.h luogu.cpp luogu.h leetcode_test.cpp lintcode_test.cpp acwing_test.cpp luogu_test.cpp set_stack_limit.cpp)
target_link_libraries(problemscpp gtest_main)
add_test(NAME problemscpp COMMAND problemscpp)