title Neon Learn Note
adb remount || goto failed

@REM remove old files
adb shell "rm -rf /sdcard/blackbox/testdata"

adb push ./Bin /system/bin || goto failed
adb push ./testdata /sdcard/blackbox/testdata || goto failed
adb shell "image_rgb2gray"

echo "Successfully"
pause
exit 0

failed:
echo "Failed"
pause