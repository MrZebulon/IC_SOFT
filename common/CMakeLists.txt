cmake_minimum_required(VERSION 3.5)
project(IC_SOFT_COMMON VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

add_library(ic_common src/Structures.cpp)
target_include_directories(ic_common PUBLIC include/)
target_link_libraries(ic_common INTERFACE Eigen3::Eigen)