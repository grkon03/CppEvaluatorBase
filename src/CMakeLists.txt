# minimum version
cmake_minimum_required(VERSION 3.16)

# subdirectories
add_subdirectory(basic)

# library
add_library(
    CppEvaluatorBaseSrc
)

# dependencies
add_dependencies(CppEvaluatorBaseSrc CppEvaluatorBaseBasic)