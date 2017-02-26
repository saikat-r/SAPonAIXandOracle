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
echo             ********Test for VERTEX Connectivity*******************
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
echo     Test for VERTEX Connectivity > LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo     by Linde SI Basis >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo     TIME: %mydate%_%mytime% >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo     Your PC name is:   %computername%
echo     Your PC name is:   %computername% >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
hostname >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo     And you are:       %username%
echo     And you are:       %username% >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
whoami >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Your PC ipconfig - ALL************************************ >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt 
ipconfig /all >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Your PC Routing Table************************************** >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt 
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
netstat -r >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Your PC Netstat******************************************* >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt 
netstat -n >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt


REM     START Netwrok Tests

echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Testing connection to internet...************************* >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo    Testing connection to internet...
echo.
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt

ping google.com >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Testing connection to SAP P8E Servers...****************** >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo    Testing connection to SAP Servers...
echo.
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt

ping cis2e63.edc.linde.grp >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
ping dbs2e63c.edc.linde.grp >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
ping cip2e69.edc.linde.grp >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
ping dbp2e69c.edc.linde.grp >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Testing niping to SAP Servers...********************** >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo    Testing niping to SAP Servers...
echo.
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt

echo    ******NIPING Connection to cis2e63.edc.linde.grp******* >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cis2e63.edc.linde.grp >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to dbs2e63c.edc.linde.grp******* >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H dbs2e63c.edc.linde.grp >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cip2e69.edc.linde.grp******* >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cip2e69.edc.linde.grp >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to dbp2e69c.edc.linde.grp******* >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H dbp2e69c.edc.linde.grp >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt


echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Testing connection to SAP Disatcher Ports...********** >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo    Testing niping to SAP Disatcher/Message Server/Gateway Ports...
echo.
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cis2e63.edc.linde.grp MESSAGE SERVER PORT 3663 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cis2e63.edc.linde.grp -S 3663 -X 1 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cis2e63.edc.linde.grp GATEWAY PORT 3363 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cis2e63.edc.linde.grp -S 3363 -X 9 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cip2e69.edc.linde.grp MESSAGE SERVER PORT 3669 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cip2e69.edc.linde.grp -S 3669 -X 1 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cip2e69.edc.linde.grp GATEWAY PORT 3369 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cip2e69.edc.linde.grp -S 3369 -X 9 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cis2e63.edc.linde.grp DISPATCHER PORT 3263 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cis2e63.edc.linde.grp -S 3263 -X 1 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to cip2e69.edc.linde.grp DISPATCHER PORT 3269 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H cip2e69.edc.linde.grp -S 3269 -X 1 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ********************Testing connection to Oracle DB Ports...********** >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo.
echo    Testing niping to Oracle DB Ports...
echo.
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt

echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to dbs2e63c.edc.linde.grp ORACLE TNS PORT 1563 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H dbs2e63c.edc.linde.grp -S 1563 -X9 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo. >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
echo    ******NIPING Connection to dbp2e69c.edc.linde.grp ORACLE TNS PORT 1569 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt
niping -c -H dbp2e69c.edc.linde.grp -S 1569 -X9 >> LOGs\VERTEX.test.%computername%.%username%.%mydate%_%mytime%.log.txt


echo.
echo    ALL Tests Completed !
echo.
echo    Please submit files generated in LOGs folder to your System Administrators !
echo.

set "dummy="
set /p DUMMY=Hit ENTER to EXIT...
if defined dummy (echo To Exit only Hit Enter Key !) else (echo ENTER was pressed)
