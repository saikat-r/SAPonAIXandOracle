#!/usr/bin/bash
# Sumit Das 2016 12 11 Original
# Tablespace Script

SID=$1
LOGS=/usr/sap/scratch/DAILYMONI/work
SCRIPTS_DIR=/usr/sap/scratch/DAILYMONI/scripts/standalone
HOST=`uname -n`
echo "Started tscheckGEn script on Host ..." $HOST
sqlplus -s "/ as sysdba" << $LOGS/TABLESPACE.$SID.$HOST
    SET FEEDBACK OFF
    SET TRIMSPOOL ON
    SET TERMOUT OFF
    SET PAGESIZE 200

spool $LOGS/$SID.$HOST.TS.txt
@$SCRIPTS_DIR/tablespace.sql
spool off;
$LOGS/TABLESPACE.$SID.$HOST

tail -n +4 $LOGS/$SID.$HOST.TS.txt > $LOGS/$SID.$HOST.TS.txt.tmp
mv $LOGS/$SID.$HOST.TS.txt.tmp $LOGS/$SID.$HOST.TS.txt


while IFS='' read -r line || [[ -n "$line" ]]; do
        TABLESPACE_NAME=`echo "$line" | awk '{print $1}'`
        #echo $TABLESPACE_NAME
        USED_PCT=`echo "$line" | awk '{print $(NF-1)}'`
        #echo $USED_PCT
        FREE_SPACE=`echo "$line" | awk '{print $4}'`
        FREE_SPACE_GB=`expr $FREE_SPACE / 1024`
        #echo $FREE_SPACE_GB
        #echo "$TABLESPACE_NAME has only $FREE_SPACE MB freespace and it is $USED_PCT % utilized"
        MAIL_BODY=`echo "$TABLESPACE_NAME has only $FREE_SPACE_GB GB freespace and it is $USED_PCT % utilized"`
        echo $MAIL_BODY

  if [ $USED_PCT -ge 90 ] && [ $FREE_SPACE_GB -le 10 ]; then
     echo $MAIL_BODY | mail -r `whoami` -s "Alert: $SID - TableSpace $TABLESPACE_NAME is $USED_PCT % used" sam8boc@gmail.com
  fi


done < "$LOGS/$SID.$HOST.TS.txt"
echo "Finished tscheckGEn script on Host ... " $HOST
