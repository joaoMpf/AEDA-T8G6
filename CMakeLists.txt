cmake_minimum_required(VERSION 3.17)
project(AEDA_T8G6)

set(CMAKE_CXX_STANDARD 20)

add_executable(AEDA_T8G6 main.cpp toll.cpp lane.cpp employee.cpp vehicle.cpp systemMonitor.cpp systemMonitor.cpp client.h client.cpp client.h Crossing.cpp Crossing.h crossing.cpp crossing.h time.cpp time.h)