cmake_minimum_required(VERSION 3.5)
project(IC_SIM_ORCHESTRATOR VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

add_library(ic_orchestrator src/OrchestratorBase.cpp)
target_include_directories(ic_orchestrator PUBLIC include/)
target_link_libraries(ic_orchestrator INTERFACE Eigen3::Eigen)
target_link_libraries(ic_orchestrator PRIVATE ic_common)







