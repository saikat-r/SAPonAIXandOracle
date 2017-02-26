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
echo                        ********Generate DCP VLAN Sheet**********************
echo                        ********Auto Collect Data****************************
echo                        ********Manual Create Excel Data*********************
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
wscript "Physical.IP.vbs"
echo.
echo.
echo         Making All DCP Physical Host Files List
echo.
echo.
REM call "makeDCP.PHY.HOST.file.AUTO.cmd"
echo.
echo.
echo         Completed All DCP Physical Host Files List
echo.
echo         Reading All Hosts to collect Service Data
echo.
echo.
wscript "ServiceData.vbs"
REM call "readHOSTdata.plink.AUTO.cmd"
echo.
echo.
echo         Completed Reading Service Data
REM cscript "Dummy.vbs" 
echo.
echo.
wscript "xlsMACRO.vbs"
echo         Now go and Make the VLAN Sheet from MACRO
echo         Open GSPO_Basis_Make_VLAN_Sheet_V3.xlsm
echo         Remove Macro from DCP_VLAN_Sheet.xls
echo         Don't return here until your VLAN Sheet is macro free !!
echo.
echo.
set "dummy="
set /p DUMMY=Hit ENTER to Start FTP of VLAN Sheet...
if defined dummy (echo Hit ENTER to Continue FTP of VLAN Sheet !!) else (echo ENTER was pressed)
REM call "DCP_VLAN_Sheet_V4.xlsm"
wscript "FTPprompt.vbs"
REM perl "csv_2_excel.pl" "VLANsheetLIVE.CSV" "VLANsheetPERL.xls"
echo.
echo.
ftp -n -s:VLANftpcmd.dat wlggceod000e0.linde.lds.grp
call "Get.Send.VLANmap.link.cmd"
REM timeout /t 180 >null
REM goto loop
echo .
echo.
echo         Nothing Else to Do !
echo.
set "dummy="
set /p DUMMY=Hit ENTER to EXIT...
if defined dummy (echo Hit ENTER to EXIT !!!) else (echo ENTER was pressed)

