title Neon Learn Note
adb remount || goto failed

adb push ./Bin /system/bin || goto failed
adb shell "lesson_06_reorder_data"

echo "Successfully"
pause
exit 0

failed:
echo "Failed"
pause