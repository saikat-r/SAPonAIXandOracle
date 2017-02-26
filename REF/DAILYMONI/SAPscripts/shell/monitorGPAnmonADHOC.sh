#!/usr/bin/bash
#Sumit Das 2015 10 02

RECIPIENT=`cat /home/users/in10c2/sumit/moniscripts/GPAmailLIST`
datestamp=$(date "+%Y.%m.%d-%H.%M.%S")
/usr/bin/nmon -F /usr/sap/scratch/GPA_mon/`hostname`_$datestamp.nmon -t  -s 60  -c 5
sleep 330
uuencode /usr/sap/scratch/GPA_mon/`hostname`_$datestamp.nmon /usr/sap/scratch/GPA_mon/`hostname`_$datestamp.nmon | mailx -r "GPA-nmon-logs" -s "GPA-nmon-logs" "$RECIPIENT"

exit
