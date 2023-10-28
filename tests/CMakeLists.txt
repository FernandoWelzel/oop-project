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