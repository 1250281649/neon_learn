cmake_minimum_required(VERSION 3.6)
project(neon_learn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fPIC -pthread -std=c++11 -mfpu=neon -mfloat-abi=softfp")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fPIC")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -ldl")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)

#include files
include_directories(
	include
)

#================== tutorial examples ==================
add_executable(lesson_01_types src/lesson_01_types.cpp)

add_executable(lesson_02_init_reg src/lesson_02_init_reg.cpp)

add_executable(lesson_03_load src/lesson_03_load.cpp)

add_executable(lesson_04_store src/lesson_04_store.cpp)


#================== Applications examples ==================
add_executable(sort_with_index src/sort_with_index.cpp)