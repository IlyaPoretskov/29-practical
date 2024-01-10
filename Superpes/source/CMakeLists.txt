cmake_minimum_required(VERSION 3.26)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(Superpes main.cpp
        ${MY_INCLUDE_DIR}/superpes.h
        superpes.cpp)

target_include_directories(Superpes PUBLIC ${MY_INCLUDE_DIR})