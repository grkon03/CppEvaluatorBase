# minimum version
cmake_minimum_required(VERSION 3.16)

file(GLOB BASICS *.cpp)

# library
add_library(
    CppEvaluatorBaseBasic
    ${BASICS}
)