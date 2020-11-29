title Neon Learn Note
adb remount || goto failed

adb push ./Bin /system/bin || goto failed
adb shell "lesson_10_compare"

echo "Successfully"
pause
exit 0

failed:
echo "Failed"
pause