# Fetching Google Test library and making it available
include(FetchContent)

FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Making test data available
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Parsing test
add_executable(parseTest parseTest.cpp)
target_link_libraries(parseTest PRIVATE gtest_main sourceLibrary)
add_test(parseTest parseTest)

# Platform test
add_executable(platformTest platformTest.cpp)
target_link_libraries(platformTest PRIVATE gtest_main sourceLibrary)
add_test(platformTest platformTest)

# CPU test
add_executable(CPUTest CPUTest.cpp)
target_link_libraries(CPUTest PRIVATE gtest_main sourceLibrary)
add_test(CPUTest CPUTest)

# Queue test
add_executable(queueTest queueTest.cpp)
target_link_libraries(queueTest PRIVATE gtest_main sourceLibrary)
add_test(queueTest queueTest)

# Memory test
add_executable(memoryTest memoryTest.cpp)
target_link_libraries(memoryTest PRIVATE gtest_main sourceLibrary)
add_test(memoryTest memoryTest)

# Bus test
add_executable(busTest busTest.cpp)
target_link_libraries(busTest PRIVATE gtest_main sourceLibrary)
add_test(busTest busTest)

# Display test
add_executable(displayTest displayTest.cpp)
target_link_libraries(displayTest PRIVATE gtest_main sourceLibrary)
add_test(displayTest displayTest)