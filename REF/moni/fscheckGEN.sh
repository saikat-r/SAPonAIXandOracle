#!/bin/sh
# Sumit Das 2016 12 11 Original
# Monitor DB FS

SID=$1
LOGS=/usr/sap/scratch/DAILYMONI/work
HOST=`uname -n`
echo "Started fscheckGEN script on host ..." $HOST
df -gt | grep -i $SID
df -gt | grep -i $SID | grep -vE 'Filesystem|archivpool2' | while read output
do
  echo $output > $LOGS/$HOST.$SID.`date "+%Y.%m.%d_%H.%M.%S"`.FSchk.LOG

  STORAGE=$(echo $output | awk '{ print $1 }')
  TOTALSPACE=$(echo $output | awk '{ print $2 }')
  USEDSPACE=$(echo $output | awk '{ print $3 }')
  FREESPACE=$(echo $output | awk '{ print $4 }')
  USEDPCT=$(echo $output | awk '{ print $5 }' | cut -d % -f 1)
  MOUNTFS=$(echo $output | awk '{ print $6 }')

  if [ $USEDPCT = "-" ] ; then 
    echo "FS $MOUNTFS is actually unmonted or in NFS error state on $STORAGE" ;
    echo "FS $MOUNTFS is actually unmonted or in NFS error state on $STORAGE" |
    mail -s "Alert: $SID - NFS mount error" sam8boc@gmail.com
  fi

  if [ $USEDPCT -ge 90 ] && [ $FREESPACE -le 10 ]; then
     echo "Running out of space \"$STORAGE \" $FREESPACE GB free on $HOST as on $(date) " ;
     echo "Running out of space \"$STORAGE \" $FREESPACE GB free on $HOST as on $(date) " |
     mail -s "Alert: $SID - Disk space on $MOUNTFS is $USEDPCT% used" sam8boc@gmail.com
  fi
done

echo "Finished fscheckGEN script on host ..." $HOST
#chmod 777 $LOGS/$HOST.$SID.*FSchk.LOG
#find $LOGS/$HOST.$SID.*FSchk.LOG -mtime -7  -ok  rm -f {} \;

#Adapted from:
#http://www.cyberciti.biz/tips/shell-script-to-watch-the-disk-space.html