# Sets CMAKE version
cmake_minimum_required(VERSION 3.11)
project(main CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GTest CONFIG REQUIRED)
enable_testing()

add_executable(test_main
    DecoratorSample.cpp
)

target_compile_options(test_main
    PUBLIC -g3 -O0 -std=c++17 -Wall # --coverage
)

target_link_options(test_main
    PUBLIC ${CMAKE_EXE_LINKER_FLAGS}

    # PUBLIC --coverage
)

# target_link_libraries(test_main)
target_link_libraries(test_main GTest::gtest GTest::gtest_main GTest::gmock)
include(GoogleTest)
gtest_discover_tests(test_main)
