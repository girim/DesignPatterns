cmake_minimum_required(VERSION 3.5.1)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++1z -pthread")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Factory)
add_executable(AbstractFactory AbstractFactory.cpp)
