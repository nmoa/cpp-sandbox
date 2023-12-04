# Sets CMAKE version
cmake_minimum_required(VERSION 3.27)
project(main CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES OFF)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
FetchContent_GetProperties(googletest)

include(GoogleTest)

# find_package(Threads REQUIRED)
# find_package(GTest REQUIRED)
enable_testing()

message(STATUS "gtest_SOURCE_DIR = ${gtest_SOURCE_DIR}")
message(STATUS "gmock_SOURCE_DIR = ${gmock_SOURCE_DIR}")

# C++ソースから `#include <gmock/gmock.h>` の形でincludeするために cmakeのinclude_directoriesを指定
set(GTEST_INCLUDE_DIR ${gtest_SOURCE_DIR}/include)
set(GMOCK_INCLUDE_DIR ${gmock_SOURCE_DIR}/include)
include_directories(${GTEST_INCLUDE_DIR} ${GMOCK_INCLUDE_DIR})

add_executable(test_main

    default-constructor.cpp
)

target_compile_options(test_main
    PUBLIC -g3 -O0 -std=c++03 -Wall
)

target_link_options(test_main
    PUBLIC ${CMAKE_EXE_LINKER_FLAGS}
)

# target_link_libraries(test_main)
target_link_libraries(test_main gtest_main)
gtest_discover_tests(test_main)
