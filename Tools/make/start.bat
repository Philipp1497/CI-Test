cd make
set "dir=%cd%"
rem for /f %%a in ('C:\msys64\usr\bin\cygpath.exe %dir%') do set SOURCEPATH=%%a
set "SOURCEPATH=../../Source"
echo %PATH%
%MAKE_PATH%
pause