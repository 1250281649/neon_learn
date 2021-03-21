cmake_minimum_required(VERSION 3.6)
project(neon_learn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Os -fPIC -pthread -std=c++11 -mfpu=neon -mfloat-abi=softfp")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -Os -fPIC")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -ldl")
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)

#include files
include_directories(
	include
	src
)

set(TOOLS_SRC src/tools/utils.cpp)

#================== tutorial examples ==================
add_executable(lesson_01_types src/lesson_01_types.cpp)

add_executable(lesson_02_init_reg src/lesson_02_init_reg.cpp)

add_executable(lesson_03_load src/lesson_03_load.cpp)

add_executable(lesson_04_store src/lesson_04_store.cpp)

add_executable(lesson_05_get_set src/lesson_05_get_set.cpp)

add_executable(lesson_06_reorder_data src/lesson_06_reorder_data.cpp)

add_executable(lesson_07_vadd src/lesson_07_vadd.cpp)

add_executable(lesson_08_vmul src/lesson_08_vmul.cpp)

add_executable(lesson_09_math src/lesson_09_math.cpp)

add_executable(lesson_10_compare src/lesson_10_compare.cpp)

add_executable(lesson_11_reduce src/lesson_11_reduce.cpp)

add_executable(lesson_12_logic src/lesson_12_logic.cpp)

#================== Applications examples ==================
add_executable(sort_with_index src/examples/sort_with_index.cpp ${TOOLS_SRC})

add_executable(image_rgb_packed2planar src/examples/image_rgb_packed2planar.cpp ${TOOLS_SRC})

add_executable(image_rgb2gray src/examples/image_rgb2gray.cpp ${TOOLS_SRC})

add_executable(image_rotation src/examples/image_rotation.cpp ${TOOLS_SRC})

add_subdirectory(thirdparty/googletest)
set(TEST_SRC
	src/main.cpp
	src/lesson_13_assember.cpp
)
add_executable(neon_gtest ${TEST_SRC})
target_link_libraries(neon_gtest gtest)
target_include_directories(neon_gtest PUBLIC thirdparty/googletest/googletest/include)