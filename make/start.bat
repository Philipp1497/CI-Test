cd make
set "dir=%cd%"
for /f %%a in ('C:\msys64\usr\bin\cygpath.exe %dir%') do set SOURCEPATH=%%a
echo %PATH%
C:\msys64\usr\bin\make.exe
pause