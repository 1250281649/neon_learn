cmake_minimum_required(VERSION 3.6)
project(neon_learn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fPIC -pthread -std=c++11 -mfpu=neon -mfloat-abi=softfp")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fPIC")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -ldl")

#include files
include_directories(
	../
)

#================== tutorial examples example ==================
add_executable(${PROJECT_NAME} src/tutorial_01.cpp)