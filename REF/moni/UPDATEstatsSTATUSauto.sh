#!/usr/bin/bash
# Sumit Das 2017 02 03
# Last Modified 2017 02 03
# Check Update STATs Status

#echo "Number of Arguments is " $#
#if [ $# -eq 2 ] ; then datestamp=$1 ; debugmode=$2 ; echo "$debugmode mode ON" ; fi
#if [ $# -eq 1 ] ; then datestamp=$1 ; debugmode="nodebug" ; fi
#if [ $# -eq 0 ] ; then datestamp=$(date "+%Y.%m.%d-%H.%M.%S") ; debugmode="nodebug" ; fi

#datestamp=$(date "+%Y.%m.%d-%H.%M.%S")
datestamp=$2
debugmode="nodebug"
LOGfile="DCPAIX.`uname -n`.$datestamp.UPDATEstats.STATUS.CSV"
DBSID=$1

SERVTYPE=`more /etc/motd | grep Welcome | awk '{print $3}' | cut -c 1-3`
if [ $SERVTYPE = "dcp" ] ; then CLUSTER=`df -gt / | tail -n 1 | cut -c 48-55` ;
else CLUSTER="APPCOM" ; fi
SERVER_NAME=`uname -n` ;

rm -f tmp_UpdateStats
ls -r /oracle/$DBSID/sapcheck/*.sta > tmp_UpdateStats
if [ -f tmp_UpdateStats ] ; then
i=0
while IFS= read -r line; do
    #echo $line
    STATUS=`tail $line | egrep "BR0802I BRCONNECT completed successfully" | awk '{print $4}'`
    STATE=`tail $line | egrep "BR0802I BRCONNECT completed successfully" | awk '{print $3}'`
    DATEofBKP=`tail -n 2 $line | head -n 1 | awk '{print $5}'`
    TIMEofBKP=`tail -n 2 $line | head -n 1 | awk '{print $6}'`
    DBversion=`head -n 50 $line | grep oracle_info | awk '{print $3}'`
    CMDLINE=`head -n 50 $line | grep command_line`

    if [ "$STATUS" = "successfully" ] && [ "$STATE" = "completed" ] ; then
        STATUS_REP="COMPLETED"
        #echo "$DBSID | on DB version | $DBversion | cluster $CLUSTER | LPAR $SERVER_NAME | $STATUS_REP | Update STATs  | on | $DATEofBKP | at | $TIMEofBKP | with $CMDLINE \n'
        echo "$DBSID,on DB version,$DBversion,$CLUSTER,$SERVER_NAME,$STATUS_REP,Update STATs,on,$DATEofBKP,at,$TIMEofBKP,with $CMDLINE"
        echo ""
        echo $DBSID,$STATUS_REP,$DATEofBKP,$TIMEofBKP >> $LOGfile
        break
    else
        STATUS_REP="FAILED"
        #echo $DBSID,$STATUS_REP,$DATEofBKP,$TIMEofBKP
        echo $DBSID,$STATUS_REP,$DATEofBKP,$TIMEofBKP >> $LOGfile
    fi
done < tmp_UpdateStats
fi
rm -f tmp_UpdateStats
