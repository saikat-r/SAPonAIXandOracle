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
echo             ********Batch File to copy from FTP to Local***********
echo             ********Originally Created for Linde Fardidabad Site***
echo             ********Created by: Sumit Das, Linde SI BASIS**********
echo             ********Created On: 2015.06.27*************************
echo             ********Last Modified by: Sumit Das, Linde SI BASIS****
echo             ********Last Modified On: 2015.06.27*******************
echo.
echo.
echo.
echo.
For /f "tokens=2-4 delims=/ " %%a in ('date /t') do (set mydate=%%c-%%a-%%b)
For /f "tokens=1-2 delims=/:" %%a in ("%TIME%") do (set mytime=%%a%%b)
echo     TIME: %mydate%_%mytime%


REM      Collect System Details
echo     Collecting your PC details...
echo     Sync shell scripts from FTP to Local > C:\Users\in10c2\OneDrive\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo     by Linde SI Basis >> C:\Users\in10c2\OneDrive\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo     TIME: %mydate%_%mytime% >> C:\Users\in10c2\OneDrive\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo. >> C:\Users\in10c2\OneDrive\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo     Your PC name is:   %computername%
echo     Your PC name is:   %computername% >> C:\Users\in10c2\OneDrive\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
hostname >> C:\Users\in10c2\OneDrive\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo     And you are:       %username%
echo     And you are:       %username% >> C:\Users\in10c2\OneDrive\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
whoami >> C:\Users\in10c2\OneDrive\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo.

REM Start Syncronization

echo user SImoni> ftpcmd.dat
echo Iamroot0>> ftpcmd.dat
echo ascii>> ftpcmd.dat
echo prompt>> ftpcmd.dat
echo cd moniscripts>> ftpcmd.dat
echo lcd C:\Users\in10c2\Desktop\moniscripts2>> ftpcmd.dat
echo mget * >> ftpcmd.dat
echo bye>> ftpcmd.dat
ftp -n -s:ftpcmd.dat ftpq.edc.linde.grp
REM del ftpcmd.dat


echo.
echo    ALL Shell Scripts Download Completed !
echo.
echo    Logs files generated in C:\Users\in10c2\OneDrive\StartupSYNC\LOGs folder !
echo.

set "dummy="
set /p DUMMY=Hit ENTER to EXIT...
if defined dummy (echo To Exit only Hit Enter Key !) else (echo ENTER was pressed)
