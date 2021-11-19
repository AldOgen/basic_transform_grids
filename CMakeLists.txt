cmake_minimum_required(VERSION 3.10)
project(coursework)

set(CMAKE_CXX_STANDARD 17)

find_library(LIBAIW libaiw.a)

#target_include_directories(SOURCE PRIVATE ${PROJECT_SOURCE_DIR}/scr/include)
#include_directories("${PROJECT_SOURCE_DIR}/scr/")

add_executable(coursework
        main.cpp
        ${PROJECT_SOURCE_DIR}/scr/include/data_structures
        ${PROJECT_SOURCE_DIR}/scr/include/direct_problem
        ${PROJECT_SOURCE_DIR}/scr/include/inverse_problem
        ${PROJECT_SOURCE_DIR}/scr/include/logger
        ${PROJECT_SOURCE_DIR}/scr/include/testing
        ${PROJECT_SOURCE_DIR}/scr/unit_tests/grad_test
)
target_link_libraries(coursework ${CMAKE_DL_LIBS} ${LIBAIW})