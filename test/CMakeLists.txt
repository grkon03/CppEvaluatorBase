cmake_minimum_required(VERSION 3.16)

project(CEBtest CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# avoid warning
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(
  basic_test
  ./basic/error_test.cpp
)

add_executable(
  CEBtest
  ${basic_test}
)
target_link_libraries(
  CEBtest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(CEBtest)