#!/usr/bin/bash
# Sumit Das 2017 01 31
# Last Modified 2017 01 31
# Check DB Backup Status

#echo "Number of Arguments is " $#
#if [ $# -eq 2 ] ; then datestamp=$1 ; debugmode=$2 ; echo "$debugmode mode ON" ; fi
#if [ $# -eq 1 ] ; then datestamp=$1 ; debugmode="nodebug" ; fi
#if [ $# -eq 0 ] ; then datestamp=$(date "+%Y.%m.%d-%H.%M.%S") ; debugmode="nodebug" ; fi

#datestamp=$(date "+%Y.%m.%d-%H.%M.%S")
datestamp=$2
debugmode="nodebug"
LOGfile="DCPAIX.`uname -n`.$datestamp.backup.STATUS.CSV"
DBSID=$1

SERVTYPE=`more /etc/motd | grep Welcome | awk '{print $3}' | cut -c 1-3`
if [ $SERVTYPE = "dcp" ] ; then CLUSTER=`df -gt / | tail -n 1 | cut -c 48-55` ;
else CLUSTER="APPCOM" ; fi
SERVER_NAME=`uname -n` ;

rm -f tmp_DBbackupFiles
ls -r /oracle/$DBSID/sapbackup/*.anf > tmp_DBbackupFiles

if [ -f tmp_DBbackupFiles ] ; then
i=0
while IFS= read -r line; do
    #echo $line
    STATUS=`tail $line | egrep "Backup completed successfully" | awk '{print $4}'`
    STATE=`tail $line | egrep "Backup completed successfully" | awk '{print $3}'`
    DATEofBKP=`tail $line | egrep "Backup completed successfully" | awk '{print $6}'`
    TIMEofBKP=`tail $line | egrep "Backup completed successfully" | awk '{print $7}'`
    DBversion=`cat $line | grep dbversion | awk '{print $2}'`
    xbrversion=`cat $line | grep init_files | awk '{print $2}'`
    if [ "$STATUS" = "successfully" ] && [ "$STATE" = "completed" ] ; then
        STATUS_REP="COMPLETED"
        #echo "| $DBSID | last backup was | $STATUS_REP | on | $DATEofBKP | at | $TIMEofBKP |"
        echo "$DBSID,$DBVERSION,last backup was,$STATUS_REP,on,$DATEofBKP,at,$TIMEofBKP,$xbrversion"
        echo $DBSID,$STATUS_REP,$DATEofBKP,$TIMEofBKP >> $LOGfile
        break
    else
        STATUS_REP="FAILED"
        #echo $DBSID,$STATUS_REP,$DATEofBKP,$TIMEofBKP
        echo $DBSID,$STATUS_REP,$DATEofBKP,$TIMEofBKP >> $LOGfile
    fi
done < tmp_DBbackupFiles
fi
rm -f tmp_DBbackupFiles

