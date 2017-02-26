@echo off
cls
echo     Batch File for USB HARD Drive and 
echo  wlggceol000e9.linde.lds.grp Syncronization.
echo.
echo.
echo.

echo.
echo.
if NOT exist "D:\WLGGCEOL000E9\VeryImportantFile-DONOTREMOVE.exe" echo     USB HARD Drive not detected.
if NOT exist "D:\WLGGCEOL000E9\VeryImportantFile-DONOTREMOVE.exe" echo     Program will now EXIT.
echo.
echo.
if NOT exist "D:\WLGGCEOL000E9\VeryImportantFile-DONOTREMOVE.exe" pause
if NOT exist "D:\WLGGCEOL000E9\VeryImportantFile-DONOTREMOVE.exe" exit
echo.
echo     Synchronization in Progress.......
echo.
echo.

echo. >> "D:\WLGGCEOL000E9\BOCreport.txt"
echo. >> "D:\WLGGCEOL000E9\BOCreport.txt"
echo ************************************************************************** >> "D:\WLGGCEOL000E9\BOCreport.txt"
echo. >> "D:\WLGGCEOL000E9\BOCreport.txt"
echo. >> "D:\WLGGCEOL000E9\BOCreport.txt"

DATE /T >> "D:\WLGGCEOL000E9\BOCreport.txt"
TIME /T >> "D:\WLGGCEOL000E9\BOCreport.txt"

echo Now copying folder MyDocs for IN10C2
REM xcopy "C:\Users\in10c2\BIN\*.*" D:\WLGGCEOL000E9\Users\in10c2\BIN\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST1.txt /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Users\in10c2\BIN\*.*" D:\WLGGCEOL000E9\Users\in10c2\BIN\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Users\in10c2\Documents\*.*" D:\WLGGCEOL000E9\Users\in10c2\Documents\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Users\in10c2\Downloads\*.*" D:\WLGGCEOL000E9\Users\in10c2\Downloads\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Users\in10c2\dwhelper\*.*" D:\WLGGCEOL000E9\Users\in10c2\dwhelper\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Users\in10c2\Favorites\*.*" D:\WLGGCEOL000E9\Users\in10c2\Favorites\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Users\in10c2\LotusArchive\*.*" D:\WLGGCEOL000E9\Users\in10c2\LotusArchive\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Users\in10c2\Pictures\*.*" D:\WLGGCEOL000E9\Users\in10c2\Pictures\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"

echo Now copying folder MyDocs for SDAS9
xcopy "C:\Users\sdas9\Documents\*.*" D:\WLGGCEOL000E9\Users\sdas9\Documents\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Users\sdas9\Downloads\*.*" D:\WLGGCEOL000E9\Users\sdas9\Downloads\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Users\sdas9\dwhelper\*.*" D:\WLGGCEOL000E9\Users\sdas9\dwhelper\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Users\sdas9\Favorites\*.*" D:\WLGGCEOL000E9\Users\sdas9\Favorites\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Users\sdas9\Pictures\*.*" D:\WLGGCEOL000E9\Users\sdas9\Pictures\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Users\sdas9\Tor Browser\*.*" "D:\WLGGCEOL000E9\Users\sdas9\Tor Browser\*.*" /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Users\sdas9\VirtualBox VMs\*.*" "D:\WLGGCEOL000E9\Users\sdas9\VirtualBox VMs\*.*" /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"

echo Now copying folder Perl MinGW Python27 Ruby TURBOC3 
xcopy "C:\Dwimperl\*.*" D:\WLGGCEOL000E9\Dwimperl\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\MinGW\*.*" D:\WLGGCEOL000E9\MinGW\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Python27\*.*" D:\WLGGCEOL000E9\Python27\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\Ruby22-x64\*.*" D:\WLGGCEOL000E9\Ruby22-x64\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"
xcopy "C:\TURBOC3\*.*" D:\WLGGCEOL000E9\TURBOC3\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"

echo Now copying folder WAMP 
xcopy "C:\wamp\*.*" D:\WLGGCEOL000E9\wamp\*.* /EXCLUDE:D:\WLGGCEOL000E9\ExcludeLIST2.txt /D /S /H /K /Y >> "D:\WLGGCEOL000E9\BOCreport.txt"

echo     Synchronization Complete.
echo     Check BOCreport.txt on WLGGCEOL000E9 folder !
echo.
echo.
pause
exit