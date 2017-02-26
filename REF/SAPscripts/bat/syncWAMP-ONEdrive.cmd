@echo off
::: -- Set the window title --
SET "title=%~nx0 - version %version%"
TITLE %title%

::: -- Set the window color --
COLOR 1A

::: -- Set the window size --
MODE CON: COLS=100 LINES=40


echo.
echo.
echo.
echo             ********Batch File to copy website design**************
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
echo     Sync WAMP files to OneDrive > C:\Users\in10c2\OneDrive\L3APZ1Z\T440\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo     by Linde SI Basis >> C:\Users\in10c2\OneDrive\L3APZ1Z\T440\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo     TIME: %mydate%_%mytime% >> C:\Users\in10c2\OneDrive\L3APZ1Z\T440\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo. >> C:\Users\in10c2\OneDrive\L3APZ1Z\T440\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo     Your PC name is:   %computername%
echo     Your PC name is:   %computername% >> C:\Users\in10c2\OneDrive\L3APZ1Z\T440\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
hostname >> C:\Users\in10c2\OneDrive\L3APZ1Z\T440\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo     And you are:       %username%
echo     And you are:       %username% >> C:\Users\in10c2\OneDrive\L3APZ1Z\T440\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
whoami >> C:\Users\in10c2\OneDrive\L3APZ1Z\T440\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo.


REM     START Syncronnization

echo. >> C:\Users\in10c2\OneDrive\L3APZ1Z\T440\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo    ********************Start Copy of Website design files****************** >> C:\Users\in10c2\OneDrive\L3APZ1Z\T440\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo.
echo    Start Copy of Website design files...
echo.
echo. >> C:\Users\in10c2\OneDrive\L3APZ1Z\T440\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log

xcopy C:\wamp\www\*.* C:\Users\in10c2\OneDrive\wamp\*.* /H /S /Y /G >> C:\Users\in10c2\OneDrive\L3APZ1Z\T440\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log


echo.
echo    ALL File Copy Completed !
echo.
echo    Logs files generated in LOGs folder !
echo.

set "dummy="
set /p DUMMY=Hit ENTER to EXIT...
if defined dummy (echo To Exit only Hit Enter Key !) else (echo ENTER was pressed)
