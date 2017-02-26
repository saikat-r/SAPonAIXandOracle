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


REM     START Syncronnization

echo. >> C:\Users\in10c2\OneDrive\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo    ********************Start Copy of Shell scripts from FTP Server to Local ****************** >> C:\Users\in10c2\OneDrive\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log
echo.
echo    Start Copy of Shell scripts from FTP Server to Local...
echo.
echo. >> C:\Users\in10c2\OneDrive\StartupSYNC\LOGs\SYNC.%computername%.%username%.%mydate%_%mytime%.log

REM -- Define File Filter, i.e. files with extension .txt
Set FindStrArgs=/E /C:".sh"

REM -- Extract Ftp Script to create List of Files
Set "FtpCommand=ls"
Call:extractFileSection "[Ftp Script 1]" "-">"%temp%\%~n0.ftp"
Rem Notepad "%temp%\%~n0.ftp"

REM -- Execute Ftp Script, collect File Names
Set "FileList="
For /F "Delims=" %%A In ('"Ftp -v -i -s:"%temp%\%~n0.ftp"|Findstr %FindStrArgs%"') Do (
    Call Set "FileList=%%FileList%% "%%A""
)

REM -- Extract Ftp Script to Upload files that don't exist in local folder
Set "FtpCommand=mget"
For %%A In (%FileList%) Do If Not Exist "%%~A" Call Set "FtpCommand=%%FtpCommand%% "%%~A""
Call:extractFileSection "[Ftp Script 1]" "-">"%temp%\%~n0.ftp"
Rem Notepad "%temp%\%~n0.ftp"

For %%A In (%FtpCommand%) Do Echo.%%A

REM -- Execute Ftp Script, Upload files
ftp -i -s:"%temp%\%~n0.ftp"
Del "%temp%\%~n0.ftp"
GOTO:EOF


:extractFileSection StartMark EndMark FileName -- extract a section of file that is defined by a start and end mark
::                  -- [IN]     StartMark - start mark, use '...:S' mark to allow variable substitution
::                  -- [IN,OPT] EndMark   - optional end mark, default is first empty line
::                  -- [IN,OPT] FileName  - optional source file, default is THIS file
:$created 20080219 :$changed 20100205 :$categories ReadFile
:$source http://www.dostips.com
SETLOCAL Disabledelayedexpansion
set "bmk=%~1"
set "emk=%~2"
set "src=%~3"
set "bExtr="
set "bSubs="
if "%src%"=="" set src=%~f0&        rem if no source file then assume THIS file
for /f "tokens=1,* delims=]" %%A in ('find /n /v "" "%src%"') do (
    if /i "%%B"=="%emk%" set "bExtr="&set "bSubs="
    if defined bExtr if defined bSubs (call echo.%%B) ELSE (echo.%%B)
    if /i "%%B"=="%bmk%"   set "bExtr=Y"
    if /i "%%B"=="%bmk%:S" set "bExtr=Y"&set "bSubs=Y"
)
EXIT /b


[Ftp Script 1]:S
!Title Connecting...
open ftpq.edc.linde.grp
SImoni
Iamroot0

!Title Preparing...
cd moniscripts
lcd C:\Users\in10c2\Desktop\moniscripts
ascii

!Title Processing... %FtpCommand%
%FtpCommand%

!Title Disconnecting...
disconnect
bye

echo.
echo    ALL Shlell Scripts Download Completed !
echo.
echo    Logs files generated in C:\Users\in10c2\OneDrive\StartupSYNC\LOGs folder !
echo.

set "dummy="
set /p DUMMY=Hit ENTER to EXIT...
if defined dummy (echo To Exit only Hit Enter Key !) else (echo ENTER was pressed)
