#!/usr/bin/bash
# Sumit Das 2015 06 11

#Define Variables
SID=$1
debugmode=$2
if [[ -z $debugmode ]]; then debugmode="nodebug" ; echo $debugmode ; fi
if [[ -n $debugmode ]]; then echo "$( basename $0 )" ; fi
LPARLIST1=/home/users/in10c2/sumit/ALL-LPAR-List
datestamp=$(date "+%Y.%m.%d-%H.%M.%S")
LOGFILE=/home/users/in10c2/sumit/moniscripts/monitoringLOGS/$1.AIXmonitor.$datestamp.log

if [ $1 != "NULL" ]
then

sh /home/users/in10c2/sumit/moniscripts/moni-server-v.5.0.sh $SID $debugmode > $LOGFILE
cat "$LOGFILE" | mailx -r "AIXmonitoring" -s "$LOGFILE" "sam8boc@gmail.com"

fi
