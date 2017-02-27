REM @echo off
REM :loop

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
echo                        ********Auto Send VLAN Sheet*************************
echo                        ********Created by: Sumit Das, Linde GSPO BASIS******
echo                        ********Created On: 2017.02.26***********************
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


cd "C:\Users\in10c2\Box Sync\BOC\SIsupport\UNIXscripts\moniscripts"
wscript "LindeNetwork.vbs"
echo.
echo        Make sure you are connected to Linde Network !!!
echo.
set "dummy="
set /p DUMMY=Hit ENTER to START...
if defined dummy (echo Hit ENTER to Start !) else (echo ENTER was pressed)
ftp -n -s:VLANftpcmd.dat wlggceod000e0.linde.lds.grp
echo .
echo.
echo         Nothing Else to Do !
echo.
set "dummy="
set /p DUMMY=Hit ENTER to EXIT...
if defined dummy (echo Hit ENTER to EXIT !!!) else (echo ENTER was pressed)

