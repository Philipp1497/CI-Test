cd %~dp0
echo %PATH%
cd bin
make.exe
copy *.o ..\results 2>&1
del *.o 2>&1
pause
