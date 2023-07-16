cmake_minimum_required(VERSION 3.5)
project(IC_SIM_SENSORS VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

add_library(ic_sensor_simulator src/FakeSensor.cpp)
target_include_directories(ic_sensor_simulator PUBLIC include/)
target_link_libraries(ic_sensor_simulator PRIVATE ic_common)
target_link_libraries(ic_sensor_simulator INTERFACE Eigen3::Eigen)







