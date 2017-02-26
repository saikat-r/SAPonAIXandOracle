@echo off
::: -- Set the window title --
SET "title=%~nx0 - version %version%"
TITLE %title%

::: -- Set the window color --
COLOR 1A

::: -- Set the window size --
MODE CON: COLS=120 LINES=40


echo.
echo.
echo.
echo             ********Batch File sync between FTP to Local***********
echo             ********Created by: Sumit Das, Linde SI BASIS**********
echo             ********Created On: 2015.06.27*************************
echo.
echo.
echo.
echo.
For /f "tokens=2-4 delims=/ " %%a in ('date /t') do (set mydate=%%c-%%a-%%b)
For /f "tokens=1-2 delims=/:" %%a in ("%TIME%") do (set mytime=%%a%%b)
echo     TIME: %mydate%_%mytime%


REM      Collect System Details
echo     Collecting your PC details...
echo     Your PC name is:   %computername%
echo     And you are:       %username%
echo.

REM call "C:\Users\in10c2\BIN\FTPanytime.cmd" %1 %2 %3 %4
SET /P mode=Enter mode of transfer - get,put,mget,mput	:  
SET /P LOCALD=Enter full path of local directory 		:  
SET /P REMOTED=Enter relative path of remote directory  :  
SET /P FILEname=Enter one filename to transfer, (*) to tarnsfer all files :  
start cmd /k call "C:\Users\in10c2\BIN\FTPanytime.cmd" %mode% %LOCALD% %REMOTED% %FILEname%

echo.
set "dummy="
set /p DUMMY=Hit ENTER to EXIT...
if defined dummy (echo To Exit only Hit Enter Key !) else (echo ENTER was pressed)
