#!/usr/bin/bash
# Sumit Das 2015 06 08

recipent=$1
file=$2

cat "$2" | mailx -r "monitoring 2" -s "$2" "$1"
RC=$?
if [ $RC -eq 0 ]; then echo "E-mail sent... ALLOK !" ; else echo "Failed tosend mail !" ; fi 
exit

