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
echo             ********Test for SAP Network Connectivity**************
echo             ********Originally Created for Linde Fardidabad Site***
echo             ********Created by: Sumit Das, Linde SI BASIS**********
echo             ********Created On: 2015.03.15*************************
echo             ********Last Modified by: Sumit Das, Linde SI BASIS****
echo             ********Last Modified On: 2015.03.16*******************
echo.
echo.
echo.
echo.
For /f "tokens=2-4 delims=/ " %%a in ('date /t') do (set mydate=%%c-%%a-%%b)
For /f "tokens=1-2 delims=/:" %%a in ("%TIME%") do (set mytime=%%a%%b)
echo     TIME: %mydate%_%mytime%


REM      Collect System Details
echo     Collecting your PC details...
echo     Test for SAP Network Connectivity > LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo     by Linde SI Basis >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo     TIME: %mydate%_%mytime% >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo     Your PC name is:   %computername%
echo     Your PC name is:   %computername% >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
hostname >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo     And you are:       %username%
echo     And you are:       %username% >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
whoami >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Your PC ipconfig - ALL************************************ >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt 
ipconfig /all >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Your PC Routing Table************************************** >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt 
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
netstat -r >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Your PC Netstat******************************************* >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt 
netstat -n >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt


REM     START Netwrok Tests

echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Testing connection to internet...************************* >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo    Testing connection to internet...
echo.
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt

ping google.com >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Testing connection to SAP P8E Servers...****************** >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo    Testing connection to SAP P8E Servers...
echo.
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt

ping cip8e47.edc.linde.grp >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
ping app8e13.edc.linde.grp >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
ping app8e31.edc.linde.grp >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Testing niping to SAP P8E Servers...********************** >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo    Testing niping to SAP P8E Servers...
echo.
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt

echo    ******NIPING Connection to cip8e47.edc.linde.grp******* >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cip8e47.edc.linde.grp >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to app8e13.edc.linde.grp******* >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H app8e13.edc.linde.grp >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to app8e31.edc.linde.grp******* >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H app8e31.edc.linde.grp >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt


echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Testing connection to SAP P8E Disatcher Ports...********** >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo    Testing niping to SAP P8E Disatcher/Message Server/Gateway Ports...
echo.
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cip8e47.edc.linde.grp MESSAGE SERVER PORT 3647 >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cip8e47.edc.linde.grp -S 3647 -X 1 >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cip8e47.edc.linde.grp GATEWAY PORT 3347 >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cip8e47.edc.linde.grp -S 3347 -X 9 >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cip8e47.edc.linde.grp DISPATCHER PORT 3247 >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cip8e47.edc.linde.grp -S 3247 -X 1 >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to app8e13.edc.linde.grp DISPATCHER PORT 3213 >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H app8e13.edc.linde.grp -S 3213 -X 1 >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to app8e31.edc.linde.grp DISPATCHER PORT 3231 >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H app8e31.edc.linde.grp -S 3231 -X 1 >> LOGs\SAP.P8E.%computername%.%username%.%mydate%_%mytime%.log.txt


echo.
echo    ALL Tests Completed !
echo.
echo    Please submit files generated in LOGs folder to your System Administrators !
echo.

set "dummy="
set /p DUMMY=Hit ENTER to EXIT...
if defined dummy (echo To Exit only Hit Enter Key !) else (echo ENTER was pressed)
