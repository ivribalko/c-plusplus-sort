cmake_minimum_required(VERSION 3.0.0)
project(c-plusplus-sort VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_executable(c-plusplus-sort main.cpp sort.hpp sort.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
