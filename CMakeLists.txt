cmake_minimum_required(VERSION 3.10)
project(coursework)

set(CMAKE_CXX_STANDARD 17)

find_library(LIBAIW libaiw.a PATHS ./aiwlib-master)
include_directories("${PROJECT_SOURCE_DIR}/include/")

add_executable(coursework main.cpp ${SOURCE})
target_link_libraries(coursework ${LIBAIW})