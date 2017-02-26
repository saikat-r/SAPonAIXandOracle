@echo off
REM Sumit Das 2017 02 24
REM Send file to DCP server and send email

cd "C:\Users\in10c2\Box Sync\BOC\SIsupport\UNIXscripts\moniscripts"

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

set LOGFILE=Get_and_Send_%yy%-%mm%-%dd%-%hh%-%min%-%ss%.TXT
echo %LOGFILE%

echo Run script on DCP to get file from E0 to DCP server and send mail
plink -ssh 10.141.64.104 -l in10c2 -pw Start1234  sh /home/users/in10c2/moni/Get_and_Send_VLANmap.sh > LOGS\Get_and_Send_VLANmap_10.141.64.104.TXT


