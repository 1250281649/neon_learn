#!/bin/bash

package_neon_bin()
{
    BUILD_DIR=$1
    cd ${BUILD_DIR}

    if [ ! -d ${BUILD_DIR}/output ]; then
        mkdir ${BUILD_DIR}/output
    fi

    cp -rf Bin/ output/
    cp ../tools/scripts/adb_push_all.bat output/
    cp ../tools/scripts/adb_push_bin.bat output/
}

copy_to_share()
{
    BUILD_DIR=$1
    if [ ! -d ${BUILD_DIR}/output ]; then
        echo "output folder not exits, check compile status"
        exit 1
    fi

    # copy test data
    cp -rf ${BUILD_DIR}/../testdata/ ${BUILD_DIR}/output/

    cp -rf ${BUILD_DIR}/output/* /mnt/hgfs/VM_Share/neon_out
}