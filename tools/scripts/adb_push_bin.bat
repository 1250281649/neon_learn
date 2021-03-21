title Neon Learn Note
adb remount || goto failed

adb shell "mkdir /sdcard/blackbox/testdata/output"
adb push ./Bin /system/bin || goto failed
adb shell "neon_gtest"

echo "Successfully"
pause
exit 0

failed:
echo "Failed"
pause