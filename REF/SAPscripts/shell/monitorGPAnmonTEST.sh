#!/usr/bin/bash
#Sumit Das 2015 10 02
set -x
#RECIPIENT=`cat /home/users/in10c2/sumit/moniscripts/GPAmailLIST`
RECIPIENT=sam8boc@gmail.com
datestamp=$(date "+%Y.%m.%d-%H.%M.%S")
/usr/bin/nmon -F /usr/sap/scratch/GPA_mon/`hostname`_$datestamp.nmon -t  -s 6  -c 5
sleep 35

uuencode /usr/sap/scratch/GPA_mon/`hostname`_$datestamp.nmon /usr/sap/scratch/GPA_mon/`hostname`_$datestamp.nmon | mailx -r "SLEEP GPA-nmon-logs" -s "GPA-nmon-logs" "$RECIPIENT"

exit
