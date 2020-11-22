#!/bin/bash
cd $(dirname $0)

mkdir out
build_dir=out/
ndk_dir=/opt/android/android-ndk-r20b

mkdir -p ${build_dir}
cd ${build_dir}
cmake ../ \
    -DCMAKE_ANDROID_NDK=${ndk_dir} \
    -DCMAKE_TOOLCHAIN_FILE=${ndk_dir}/build/cmake/android.toolchain.cmake \
    -DANDROID_TOOLCHAIN=clang \
    -DCMAKE_BUILD_TYPE=Release \
    -DANDROID_ABI=armeabi-v7a \
    -DANDROID_PLATFORM=18 \
    -DCMAKE_CXX_STANDARD=11 \
    -DBOARD_TARGET=Android 

make -j3