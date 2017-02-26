@echo off
REM Start Syncronization

echo user SImoni> ftpcmd.dat
echo Iamroot0>> ftpcmd.dat
echo ascii>> ftpcmd.dat
echo prompt>> ftpcmd.dat
echo lcd %2>> ftpcmd.dat
echo cd %3>> ftpcmd.dat
echo %1 %4 >> ftpcmd.dat
echo bye>> ftpcmd.dat
ftp -n -s:ftpcmd.dat ftpq.edc.linde.grp

