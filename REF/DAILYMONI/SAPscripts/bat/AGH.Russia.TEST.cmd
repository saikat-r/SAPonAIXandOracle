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
echo             ********Test for AGH Connectivity**********************
echo             ********Originally Created for Linde Fardidabad Site***
echo             ********Created by: Sumit Das, Linde SI BASIS**********
echo             ********Created On: 2015.03.15*************************
echo             ********Last Modified by: Sumit Das, Linde SI BASIS****
echo             ********Last Modified On: 2015.11.20*******************
echo             ********For Russia Users AGH Conneciton Test***********	
echo.
echo.
echo.
echo.
For /f "tokens=2-4 delims=/ " %%a in ('date /t') do (set mydate=%%c-%%a-%%b)
For /f "tokens=1-2 delims=/:" %%a in ("%TIME%") do (set mytime=%%a%%b)
echo     TIME: %mydate%_%mytime%


REM      Collect System Details
echo     Collecting your PC details...
echo     Test for AGH Connectivity > LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo     by Linde SI Basis >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo     TIME: %mydate%_%mytime% >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo     Your PC name is:   %computername%
echo     Your PC name is:   %computername% >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
hostname >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo     And you are:       %username%
echo     And you are:       %username% >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
whoami >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Your PC ipconfig - ALL************************************ >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt 
ipconfig /all >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Your PC Routing Table************************************** >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt 
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
netstat -r >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Your PC Netstat******************************************* >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt 
netstat -n >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt


REM     START Netwrok Tests

echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Testing connection to internet...************************* >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo    Testing connection to internet...
echo.
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt

ping google.com >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
REM pause

echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Testing connection to SAP P8E Servers...****************** >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo    Testing connection to SAP Servers...
echo.
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt

ping ciagh58.edc.linde.grp >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
ping cidgh12.edc.linde.grp >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
ping cipgh59.edc.linde.grp >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
ping linciagh5800.edc.linde.grp >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt

REM pause

echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Testing niping to SAP Servers...********************** >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo    Testing niping to SAP Servers...
echo.
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt

echo    ******NIPING Connection to ciagh58.edc.linde.grp******* >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H ciagh58.edc.linde.grp >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cidgh12.edc.linde.grp******* >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cidgh12.edc.linde.grp >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cipgh59.edc.linde.grp******* >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cipgh59.edc.linde.grp >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to linciagh5800.edc.linde.grp******* >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H linciagh5800.edc.linde.grp >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt

REM pause
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Testing connection to SAP Disatcher Ports...********** >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo    Testing niping to SAP Disatcher/Message Server/Gateway Ports...
echo.
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to ciagh58.edc.linde.grp MESSAGE SERVER PORT 3658 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H ciagh58.edc.linde.grp -S 3658 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to ciagh58.edc.linde.grp GATEWAY PORT 3358 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H ciagh58.edc.linde.grp -S 3358 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt

REM pause
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cipgh59.edc.linde.grp MESSAGE SERVER PORT 3659 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cipgh59.edc.linde.grp -S 3659 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cipgh59.edc.linde.grp GATEWAY PORT 3359 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cipgh59.edc.linde.grp -S 3359 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to ciagh58.edc.linde.grp DISPATCHER PORT 3258 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H ciagh58.edc.linde.grp -S 3258 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cipgh59.edc.linde.grp DISPATCHER PORT 3259 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cipgh59.edc.linde.grp -S 3259 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Testing connection to Oracle DB Ports...********** >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo    Testing niping to Oracle DB Ports...
echo.
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to dbagh58c.edc.linde.grp ORACLE TNS PORT 1558 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H dbagh58c.edc.linde.grp -S 1558 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to linciagh5800.edc.linde.grp ORACLE TNS PORT 1558 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H lindbagh5800c4.edc.linde.grp -S 1558 >> LOGs\AGH.test.%computername%.%username%.%mydate%_%mytime%.log.txt


echo.
echo    ALL Tests Completed !
echo.
echo    Please submit files generated in LOGs folder to your System Administrators !
echo.

set "dummy="
set /p DUMMY=Hit ENTER to EXIT...
if defined dummy (echo To Exit only Hit Enter Key !) else (echo ENTER was pressed)
