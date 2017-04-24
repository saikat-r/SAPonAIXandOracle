@echo off
::: -- Set the window title --
SET "title=%~nx0 - version %version%"
REM TITLE %title%
TITLE LCM Info for SAP

::: -- Set the window color --
COLOR 1A

::: -- Set the window size --
MODE CON: COLS=120 LINES=40


echo.
echo.
echo.
echo             ********SAP System Info for LCM************************
echo             ********Created by: Sumit Das, Linde GSPO BASIS********
echo             ********Created On: 2017.04.23*************************
echo             ********Last Modified by: Sumit Das, Linde GSPO BASIS**
echo             ********Last Modified On: 2017.04.24*******************
echo.
echo.
echo.
echo.

REM Create the date and time elements.
for /f "tokens=1-7 delims=:/-, " %%i in ('echo exit^|cmd /q /k"prompt $d $t"') do (
   for /f "tokens=2-4 delims=/-,() skip=1" %%a in ('echo.^|date') do (
      set dow=%%i
      set %%a=%%j
      set %%b=%%k
      set %%c=%%l
      set hh=%%m
      set min=%%n
      set ss=%%o
   )
)

REM Lets see the result.
echo %dow% %yy%-%mm%-%dd% @ %hh%:%min%:%ss%
set DATESTAMP=%yy%-%mm%-%dd%.%hh%-%min%-%ss%

setlocal enabledelayedexpansion

set BASEDIR=%USERPROFILE%\Documents\GitHub\SAPonAIXandOracle\LCM
FOR %%i IN (%BASEDIR%) DO IF NOT EXIST %%~si\NUL mkdir %BASEDIR%
cd %BASEDIR%
REM echo %BASEDIR%
REM cd
echo.

:STARToff
echo.
echo.
echo --- START with whatever Information you have ---
echo --- Choose one of the options                ---
echo.
echo 1]. If you have SAP SID,   ENTER : 1
echo 2]. If you have Server IP, ENTER : 2
echo X]. To EXIT, HIT any key         : X
echo.
set myCHOICE_1=
set /p myCHOICE_1=  Enter one of the above options ... =   %=%
echo.
if %myCHOICE_1% EQU 1 goto:SAPsysINFO
if %myCHOICE_1% EQU 2 goto:ServerINFO
if NOT %myCHOICE_1% == 1 OR if NOT %myCHOICE_1% == 2 goto:ENDOFCODE

:SAPsysINFO
set SAPSID=
set /p SAPSID=	Provide SID of the SAP system for which Info needs to be collected... =	%=%
echo.

REM echo    Your SAP SID has following Server IPs ...
REM echo.
REM using SQLITE3
REM cd data
REM ..\bin\sqlite3 SAPSIDS.db "select * from VLANdata where SERVICE like '%%%SAPSID%%%'" ;

REM echo select * from VLANdata where SERVICE like '%%%SAPSID%%%'; > ..\temp\temp_select_SAPSID.sql
REM using SQLITE3 SQLITE
REM cd ..\temp
REM ..\bin\sqlite3 ..\data\SAPSIDS.db ".read temp_select_SAPSID.sql"
REM echo.
REM exit SQLITE3
REM cd %BASEDIR%

echo.
set myCHOICE_4=
set /p myCHOICE_4=    Do you want to save your data (y/n) :  %=%
if %myCHOICE_4% == y (
	cd %BASEDIR%
	set SIDINFOfile=%SAPSID%_INFO_%DATESTAMP%.TXT
	echo .headers on > temp\temp_select_SAPSID.sql
	echo .output !SIDINFOfile! >> temp\temp_select_SAPSID.sql
 	echo select * from VLANdata where SERVICE like '%%%SAPSID%%%'; >> temp\temp_select_SAPSID.sql
 	cd temp
 	echo.
 	echo    Your SAP SID has following Server IPs ...
 	echo.
 	..\bin\sqlite3 ..\data\SAPSIDS.db ".read temp_select_SAPSID.sql"
 	type !SIDINFOfile!
 	echo.
	cd %BASEDIR%
	copy temp\!SIDINFOfile! LOGs\!SIDINFOfile!
	del temp\!SIDINFOfile!
	echo    Your SID Info was saved to !SIDINFOfile! in LOGs
	echo.
	echo    Your SID Info file will be displayed now...
	echo    Please close the notepad to continue...
	@pause
	bin\n2.exe LOGs\!SIDINFOfile!
	goto postSID
) 
if NOT %myCHOICE_4% == y (
	echo    Your SAP SID has following Server IPs ...
	echo.
	REM using SQLITE3
	cd %BASEDIR%\data
	..\bin\sqlite3 SAPSIDS.db "select * from VLANdata where SERVICE like '%%%SAPSID%%%'" ;
	goto postSID
)

:postSID
echo.
set myCHOICE_3=
set /p myCHOICE_3=  Do you want to repeat (y/n) :  %=%
if %myCHOICE_3% == y goto:STARToff
if NOT %myCHOICE_3% == y goto:ENDOFCODE
goto ENDOFCODE

:ServerINFO
echo.
set SERVERIP=
set /p SERVERIP=   Enter the Server IP or Hostname you have ... =  %=%
echo.
echo Base Directrory is ... %BASEDIR%
echo Server IP is       ... %SERVERIP%
echo DATESTAMP is       ... %DATESTAMP%
set ServerINFOfile=LOGs\%SERVERIP%_INFO_%DATESTAMP%.TXT
echo Server Info file is... %ServerINFOfile% inside LOGs folder of your Base Directory
REM cd
echo.
echo    Please wait ... Your data is being collected...
echo.
plink -ssh %SERVERIP% -l in10c2 -pw Start1234 sh /home/users/in10c2/moni/moni-server-v.10.sh > %ServerINFOfile%
echo.
echo.
echo    Server Info is stored in file ... %SERVERIP%_INFO_%DATESTAMP%.TXT in LOGs of Base Directory
echo    Your Server Info will be displayed on Screen now...
echo.
@pause
cls
type LOGs\%ServerINFOfile%
echo.
echo    Your file will be opened now...
bin\n2.exe LOGs\%ServerINFOfile%

echo.
set myCHOICE_2=
set /p myCHOICE_2=  Do you want to repeat (y/n) :  %=%
if %myCHOICE_2% == y goto:STARToff
if NOT %myCHOICE_2% == y goto:ENDOFCODE
goto ENDOFCODE

:ENDOFCODE
echo.
echo    ALL Info Collected !
echo.

set "dummy="
set /p DUMMY=Hit ENTER to EXIT...
if defined dummy (echo To Exit only Hit Enter Key !) else (echo ENTER was pressed)

