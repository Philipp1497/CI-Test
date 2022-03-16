cd %~dp0
C:\MinGW\msys\1.0\bin\make.exe main.o
copy *.o ..\results 2>&1
del *.o 2>&1
pause
