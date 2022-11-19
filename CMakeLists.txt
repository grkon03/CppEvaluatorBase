# minimum version
cmake_minimum_required(VERSION 3.16)

# subdirectories
add_subdirectory(src)

# library
add_library(
    CppEvaluatorBase
)

# dependencies
add_dependencies(CppEvaluatorBase CppEvaluatorBaseSrc)