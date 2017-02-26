@echo off
REM Sumit Das 2016 12 26
REM Read all PHYsical Hosts of each DCP cluster
REM Collate the PHY HOSTS from each DCP cluster into single file
REM Use this file to trigger other scritps

cd "C:\Users\in10c2\Box Sync\BOC\SIsupport\UNIXscripts\moniscripts"
@echo off
REM This script taken from the following URL:
REM http://www.winnetmag.com/windowsscripting/article/articleid/9177/windowsscripting_9177.html

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

set LOGFILE=ALL_PROD_PHY_HOSTIP_%yy%-%mm%-%dd%-%hh%-%min%-%ss%.TXT
echo %LOGFILE%

echo Reading Data from Legpgi01
plink -ssh 10.141.112.62 -l in10c2 -pw Start1234  sh /home/users/in10c2/moni/readALLphyIP.sh > ALL_PROD_PHY_HOSTIP_10.141.112.62.TXT
echo Reading Data from Legpgn01
plink -ssh 10.141.64.104 -l in10c2 -pw Start1234  sh /home/users/in10c2/moni/readALLphyIP.sh > ALL_PROD_PHY_HOSTIP_10.141.64.104.TXT

type ALL_PROD_PHY_HOSTIP_10.141.112.62.TXT >> LOGS\%LOGFILE%
type ALL_PROD_PHY_HOSTIP_10.141.64.104.TXT >> LOGS\%LOGFILE%

echo %dow% %yy%-%mm%-%dd% @ %hh%:%min%:%ss% >> LOGS\%LOGFILE%
copy LOGS\%LOGFILE% ALL_PROD_PHY_HOSTIP.TXT

pause
