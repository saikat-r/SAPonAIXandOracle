#!/usr/bin/bash
# Test from http://stackoverflow.com/questions/18460186/writing-outputs-to-log-file-and-console

LOG_FILE=~/sumit/moniscripts/TEST.log
exec 3>&1 1>>${LOG_FILE} 2>&1

echo "This is stdout"
echo "This is stderr" 1>&2
echo "This is the console (fd 3)" 1>&3
echo "This is both the log and the console" | tee /dev/fd/3
