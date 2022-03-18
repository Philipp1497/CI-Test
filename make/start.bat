cd make
set "dir=%cd%"
rem for /f %%a in ('C:\msys64\usr\bin\cygpath.exe %dir%') do set SOURCEPATH=%%a
set "SOURCEPATH=C:/Users/Philipp/Desktop/CI-Test/make"
echo %PATH%
C:\msys64\usr\bin\make.exe
pause