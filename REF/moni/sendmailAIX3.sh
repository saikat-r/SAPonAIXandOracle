#!/usr/bin/bash
# Sumit Das 2015 06 08

TO=$1
FILE=$2
SENDER=$3

cat "$FILE" | mailx -r "SENDER" -s "$FILE" "$TO"
RC=$?
if [ $RC -eq 0 ]; then echo "E-mail sent... ALL OK !" ; else echo "Failed tosend mail !" ; fi 
exit

