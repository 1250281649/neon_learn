title Neon Learn Note
adb remount || goto failed

@REM remove old files
adb shell "rm -rf /sdcard/blackbox/testdata"

adb shell "mkdir /sdcard/blackbox/testdata/output"
adb push ./Bin /system/bin || goto failed
adb push ./testdata /sdcard/blackbox/testdata || goto failed
adb shell "image_rotation"

echo "Successfully"
pause
exit 0

failed:
echo "Failed"
pause