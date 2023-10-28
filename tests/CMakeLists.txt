add_executable(parseTest parseTest.cpp)

target_link_libraries(parseTest PRIVATE sourceLibrary)

include(CTest)

add_test(NAME parseTest COMMAND parseTest)