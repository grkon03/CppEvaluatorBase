# minimum version
cmake_minimum_required(VERSION 3.16)

# subdirectories
add_subdirectory(basic)

# link libraries
target_link_libraries(
    ${PROJECT_NAME}
    CppEvaluatorBaseBasic
)