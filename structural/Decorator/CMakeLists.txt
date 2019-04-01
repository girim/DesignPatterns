cmake_minimum_required(VERSION 3.5.1)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-I /usr/local/lib/boost_1_61_0 -std=c++1z -pthread")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Structural)
add_executable(StaticDecoratorUsingMixin StaticDecoratorUsingMixin.cpp)
