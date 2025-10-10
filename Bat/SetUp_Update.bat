@echo off
setlocal

echo Run Start
cd /d %~dp0
set "CURDIR=%cd%"

call "%ProgramFiles%\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

cd ../Engine
echo %cd%

echo git pull origin master start

git reset --hard
git pull origin master

echo git pull origin master completed

rem 削除したいフォルダのパスを指定
set "TARGET=%cd%/Generated"
set "TARGETENGINE=%cd%/Externals/Engine"

echo Deleting Target folders:
echo %TARGET%
echo %TARGETENGINE%

rem Generated削除
if exist "%TARGET%" (
    echo.
    echo ==== Deleting contents of %TARGET% ====
    for /r "%TARGET%" %%f in (*) do (
        echo Deleting: %%f
        del /f /q "%%f"
    )
    for /d %%d in ("%TARGET%\*") do rd /s /q "%%d"
)

rem ExternalsのEngine削除
if exist "%TARGETENGINE%" (
    echo.
    echo ==== Deleting contents of %TARGETENGINE% ====
    for /r "%TARGETENGINE%" %%f in (*) do (
        echo Deleting: %%f
        del /f /q "%%f"
    )
    for /d %%d in ("%TARGETENGINE%\*") do rd /s /q "%%d"
)

echo.
echo All deletions completed!
cd ..
pause

:: Run_ALL.bat を実行
call "Engine\Bat\Run_ALL.bat"

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