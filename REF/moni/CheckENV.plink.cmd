@echo off
REM Sumit Das 2016 12 26
REM TableSpace Checks of DB SID (General)

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

cd "C:\Users\in10c2\Box Sync\BOC\SIsupport\UNIXscripts\moniscripts"
set LOGFILE=ALL_PHY_HOSTIP_%yy%-%mm%-%dd%-%hh%-%min%-%ss%.TXT
echo %LOGFILE%
set DATESTAMP_PARSE=%yy%.%mm%.%dd%-%hh%.%min%.%ss%
echo %DATESTAMP_PARSE%


@echo off
for /f "tokens=1-18* delims=," %%A in (VLANsheetDATAmod.CSV) do (
  IF "%%~N" == "BLANK" (
    echo No DB found on Host %%~C
    ) ELSE (
      echo Collecting data now for SERVER %%~C with IP  %%~E having DBs for %%~N
        for /F "tokens=1-5 delims= " %%S in ("%%~N") do (
        REM echo SID 1 is %%S  
        REM echo SID 2 is %%T
        REM echo SID 3 is %%U
        REM echo SID 4 is %%V
        REM echo SID 5 is %%W
        REM pause
        IF NOT "%%S" == "" echo y | plink -ssh -l in10c2 -pw Start1234 %%~E sh /home/users/in10c2/sumit/exec_remote_ssh_sd %%S %%~E sh /home/users/in10c2/moni/checkENV.sh >> LOGS\ENVcheck_%DATESTAMP_PARSE%.LOG
        IF NOT "%%T" == "" echo y | plink -ssh -l in10c2 -pw Start1234 %%~E sh /home/users/in10c2/sumit/exec_remote_ssh_sd %%T %%~E sh /home/users/in10c2/moni/checkENV.sh >> LOGS\ENVcheck_%DATESTAMP_PARSE%.LOG
        IF NOT "%%U" == "" echo y | plink -ssh -l in10c2 -pw Start1234 %%~E sh /home/users/in10c2/sumit/exec_remote_ssh_sd %%U %%~E sh /home/users/in10c2/moni/checkENV.sh >> LOGS\ENVcheck_%DATESTAMP_PARSE%.LOG
        IF NOT "%%V" == "" echo y | plink -ssh -l in10c2 -pw Start1234 %%~E sh /home/users/in10c2/sumit/exec_remote_ssh_sd %%V %%~E sh /home/users/in10c2/moni/checkENV.sh >> LOGS\ENVcheck_%DATESTAMP_PARSE%.LOG
        IF NOT "%%W" == "" echo y | plink -ssh -l in10c2 -pw Start1234 %%~E sh /home/users/in10c2/sumit/exec_remote_ssh_sd %%W %%~E sh /home/users/in10c2/moni/checkENV.sh >> LOGS\ENVcheck_%DATESTAMP_PARSE%.LOG
        )
    )  
)
echo %dow% %yy%-%mm%-%dd% @ %hh%:%min%:%ss%
pause