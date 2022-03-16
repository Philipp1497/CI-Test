cd %~dp0
echo %PATH%
start "C:\MinGW\msys\1.0\bin\make.exe"
copy *.o ..\results 2>&1
del *.o 2>&1
pause
