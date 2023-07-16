cmake_minimum_required(VERSION 3.5)
project(IC_SIM_DYNAMIC_SIMULATION VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

add_library(ic_dynamic_model_simulator src/FlightSimulatorBase.cpp src/SimulationRates.cpp src/engine/SimulationEngine.cpp src/model/DynamicModelBase.cpp src/model/DroneDynamicModel.cpp src/model/HopperDynamicModel.cpp)
target_include_directories(ic_dynamic_model_simulator PUBLIC include/)
target_link_libraries(ic_dynamic_model_simulator INTERFACE Eigen3::Eigen)
target_link_libraries(ic_dynamic_model_simulator PRIVATE ic_common)