@echo off
:loop
call "C:\Users\in10c2\BIN\serviceFTPmoni.cmd"
timeout /t 60 >null
goto loop

