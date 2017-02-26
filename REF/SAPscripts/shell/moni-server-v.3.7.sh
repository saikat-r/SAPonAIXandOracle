#!/usr/bin/bash
# Sumit Das 2015 06 27

#Define Variables
SID=$1
mailsend=$2
debugmode=$3
if [[ -z $debugmode ]]; then debugmode="nodebug" ; echo $debugmode ; fi
if [ $debugmode = "debug" ]; then echo "$( basename $0 )" ; fi

datestamp=$(date "+%Y.%m.%d-%H.%M.%S")
datesh=$(date "+%Y.%m.%d")
mkdir monitoringLOGS/$datesh
LOGFILE=/home/users/in10c2/sumit/moniscripts/monitoringLOGS/$1.AIXmonitor.$datestamp.log
SUBJECT=$1.AIXmonitor.$datestamp.log
#RECIPIENT=si_basis@linde.com
RECIPIENT=`cat /home/users/in10c2/sumit/moniscripts/GPAmailLIST`
if [ $debugmode = "debug" ]; then echo $RECIPIENT ; fi 

sh /home/users/in10c2/sumit/moniscripts/moni-server-v.5.2.sh $SID $debugmode > $LOGFILE

#mv /home/users/in10c2/*.nmon /home/users/in10c2/sumit/moniscripts/monitoringLOGS/GPAnmon/.
#tar -cvf /home/users/in10c2/sumit/moniscripts/monitoringLOGS/GPAnmon/GPA-NMON.$datestamp.tar /home/users/in10c2/sumit/moniscripts/monitoringLOGS/GPAnmon/*.nmon
#rm /home/users/in10c2/sumit/moniscripts/monitoringLOGS/GPAnmon/*.nmon

if [ $mailsend = "yes" ]; then
	cat "$LOGFILE" | mailx -s "$SUBJECT" -r "GPA-AIX-monitoring" "$RECIPIENT"
	echo "$SID Monitoring Log E-mail sent to $RECIPIENT"
#        cd /home/users/in10c2/sumit/moniscripts/monitoringLOGS/GPAnmon
#        uuencode GPA-NMON.$datestamp.tar GPA-NMON.$datestamp.tar | mailx -r "GPA-nmon-logs" -s "GPA-nmon-logs" "$RECIPIENT" 
else
	echo "Sending mail not requested !"
fi



