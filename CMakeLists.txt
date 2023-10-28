cmake_minimum_required(VERSION 3.5)

project(3A-SEI-SoC-POO-PROJECT)
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wconversion -std=gnu99")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wconversion -std=gnu++11")

add_executable(main ./source/main.cpp ./source/platform.cpp ./source/parse.cpp ./source/cpu.cpp ./source/component.cpp ./source/memory.cpp ./source/display.cpp ./source/bus.cpp)

# Enabling unit testing
include(GoogleTest)
add_executable(BuildTest ./test/unit/build.cpp)
gtest_add_tests(TARGET      BuildTest
                TEST_SUFFIX .noArgs
                TEST_LIST   noArgsTests
)
set_tests_properties(${noArgsTests}   PROPERTIES TIMEOUT 10)