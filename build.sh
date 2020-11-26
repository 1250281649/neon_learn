#!/bin/bash
CUR_DIR=$(dirname $0)
cd ${CUR_DIR}

. tools/scripts/package.sh

BUILD_DIR=build
ndk_dir=/opt/android/android-ndk-r20b

if [ ! -d ${BUILD_DIR} ]; then
    mkdir ${BUILD_DIR}
fi

cd ${BUILD_DIR}
cmake ../ \
    -DCMAKE_ANDROID_NDK=${ndk_dir} \
    -DCMAKE_TOOLCHAIN_FILE=${ndk_dir}/build/cmake/android.toolchain.cmake \
    -DANDROID_TOOLCHAIN=clang \
    -DCMAKE_BUILD_TYPE=Release \
    -DANDROID_ABI=armeabi-v7a \
    -DANDROID_PLATFORM=18 \
    -DCMAKE_CXX_STANDARD=11

make -j3
if [ ! $? ]; then
    exit 0
fi

package_neon_bin ${CUR_DIR}
copy_to_share ${CUR_DIR}