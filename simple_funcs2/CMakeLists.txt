cmake_minimum_required(VERSION 3.14) # version can be different
project(my_cpp_project) #name of your project
set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest) # add googletest subdirectory
include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>
# target_link_libraries(tests PRIVATE gtest) # link google test to this executable
enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
add_executable(
  tests.cpp
  tests
)
target_link_libraries(
  tests
  GTest::gtest_main
  gtest/gtest.h
)
gtest_discover_tests(tests)
