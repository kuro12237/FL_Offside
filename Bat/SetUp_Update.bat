@echo off
setlocal

echo Run Start
cd /d %~dp0
set "CURDIR=%cd%"

call "%ProgramFiles%\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"



:: Run_ALL.bat を実行
call "../Engine\Bat\Run_ALL.bat"

pause

:: Run_ALL が終わったら Externals 内のすべてをコピー
echo.
echo Copy Externals...
echo %CURDIR%
echo コピー元: %CURDIR%\..\Engine\Externals\*
echo コピー先: %CURDIR%\..\Externals\
pause

if not exist "%CURDIR%\..\Externals" mkdir "%CURDIR%\..\Externals"
xcopy "%CURDIR%\..\Engine\Externals\*" "%CURDIR%\..\Externals\" /E /I /Y
pause