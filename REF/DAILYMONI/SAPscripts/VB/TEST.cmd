@echo off
color F0
mode con lines=25 cols=60
cls
title "Notepad - MyProgram.bat"

set /P "name=What is your name? "
echo Hello %name%, glad to see you...
pause