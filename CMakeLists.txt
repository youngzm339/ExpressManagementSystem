cmake_minimum_required(VERSION 3.24)
project(ExpressManagementSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(ExpressManagementSystem main.cpp User.cpp User.h Item.cpp Item.h Method.cpp Method.h)
