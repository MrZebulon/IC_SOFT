cmake_minimum_required(VERSION 3.5)
project(IC_SOFT VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3 REQUIRED NO_MODULE)
include_directories("${EIGEN3_INCLUDE_DIR}")

add_subdirectory("${PROJECT_SOURCE_DIR}/common" "${PROJECT_SOURCE_DIR}/common/output")

add_subdirectory("${PROJECT_SOURCE_DIR}/Orchestrator" "${PROJECT_SOURCE_DIR}/Orchestrator/output")
add_subdirectory("${PROJECT_SOURCE_DIR}/Simulator/DynamicModel" "${PROJECT_SOURCE_DIR}/Simulator/DynamicModel/output")
add_subdirectory("${PROJECT_SOURCE_DIR}/Simulator/Sensor" "${PROJECT_SOURCE_DIR}/Simulator/Sensor/output")