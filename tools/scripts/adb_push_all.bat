adb remount || goto failed

adb push ./Bin /system/bin || goto failed
adb shell "sort_with_index"

echo "Successfully"
pause
exit 0

failed:
echo "Failed"
pause