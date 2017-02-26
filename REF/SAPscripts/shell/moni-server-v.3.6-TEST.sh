#!/usr/bin/bash
# Sumit Das 2015 06 27

#Define Variables
SID=$1
mailsend=$2
debugmode=$3
if [[ -z $debugmode ]]; then debugmode="nodebug" ; echo $debugmode ; fi
if [ $debugmode = "debug" ]; then echo "$( basename $0 )" ; fi

datestamp=$(date "+%Y.%m.%d-%H.%M.%S")
LOGFILE=/home/users/in10c2/sumit/moniscripts/monitoringLOGS/$1.AIXmonitor.$datestamp.log
SUBJECT=$1.AIXmonitor.$datestamp.log
RECIPIENT=si_basis@linde.com
if [ $debugmode = "debug" ]; then echo $RECIPIENT ; fi 

sh /home/users/in10c2/sumit/moniscripts/moni-server-v.5.1.sh $SID $debugmode > $LOGFILE

if [ mailsend = 'yes']
	cat "$LOGFILE" | mailx -r "AIXmonitoring" -s "$SUBJECT" "$RECIPIENT"
	echo "$SID Monitoring Log E-mail sent to $RECIPIENT"
else
	echo "Sending mail not requested !"
fi



