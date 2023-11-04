cmake_minimum_required(VERSION 3.11)

project(3A-SEI-SoC-POO-PROJECT)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wconversion -std=gnu99")

# Enabling unit testing
enable_testing()

# Adding directories
add_subdirectory(source)
add_subdirectory(include)
add_subdirectory(tests)

# Building main executable
add_executable(project source/main)
target_link_libraries(project PRIVATE sourceLibrary)
