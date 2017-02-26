#!/usr/bin/bash
# Sumit Das 2016 12 11 Original
# Sumit Das 2017 01 19 Modified to consider AutoExtend Space
# Tablespace Script

SID=$1
LOGS=/usr/sap/scratch/DAILYMONI/work
SCRIPTS_DIR=/home/users/in10c2/moni
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
#cat $LOGS/$SID.$HOST.TS.txt.tmp
mv $LOGS/$SID.$HOST.TS.txt.tmp $LOGS/$SID.$HOST.TS.txt


while IFS='' read -r line || [[ -n "$line" ]]; do
        TABLESPACE_NAME=`echo "$line" | awk '{print $1}'`
        #echo $TABLESPACE_NAME
        USED_PCT=`echo "$line" | awk '{print $(NF)}'`
        #echo $USED_PCT
        FREE_SPACE=`echo "$line" | awk '{print $(NF-1)}'`
        FREE_SPACE_int=${FREE_SPACE%%.*}
        FREE_SPACE_GB=`expr $FREE_SPACE_int / 1024`
        #echo $FREE_SPACE_GB
        echo "$TABLESPACE_NAME has only $FREE_SPACE MB freespace and it is $USED_PCT % utilized"
        MAIL_BODY=`echo "$TABLESPACE_NAME has only $FREE_SPACE_GB GB freespace and it is $USED_PCT % utilized"`
        echo $MAIL_BODY

  if [ $USED_PCT -ge 98 ] && [ $FREE_SPACE_GB -le 2 ]; then
     #echo "I am $SID "
     echo $MAIL_BODY | mail -r `whoami` -s "Tablespace_ALERT_moni: $SID - TableSpace $TABLESPACE_NAME is $USED_PCT % used" sam8boc+moni@gmail.com

  fi


done < "$LOGS/$SID.$HOST.TS.txt"
#echo "Finished tscheckGEn script on Host ... " $HOST

SID=$1
LOGS=/usr/sap/scratch/DAILYMONI/work
SCRIPTS_DIR=/home/users/in10c2/moni
HOST=`uname -n`
echo "Started tscheckGEn TEMP script on Host ..." $HOST
sqlplus -s "/ as sysdba" << $LOGS/TABLESPACE.TEMP.$SID.$HOST
    SET FEEDBACK OFF
    SET TRIMSPOOL ON
    SET TERMOUT OFF
    SET PAGESIZE 200

spool $LOGS/$SID.$HOST.TS.TEMP.txt
@$SCRIPTS_DIR/tablespace_temp.sql
spool off;
$LOGS/TABLESPACE.TEMP.$SID.$HOST

tail -n +4 $LOGS/$SID.$HOST.TS.TEMP.txt > $LOGS/$SID.$HOST.TS.TEMP.txt.tmp
cat $LOGS/$SID.$HOST.TS.TEMP.txt.tmp
mv $LOGS/$SID.$HOST.TS.TEMP.txt.tmp $LOGS/$SID.$HOST.TS.txt


while IFS='' read -r line || [[ -n "$line" ]]; do
        TABLESPACE_NAME=`echo "$line" | awk '{print $1}'`
        #echo $TABLESPACE_NAME
        USED_SPACE=`echo "$line" | awk '{print $(NF-1)}'`
        #echo $USED_PCT
        FREE_SPACE_TEMP=`echo "$line" | awk '{print $(NF)}'`
        #FREE_SPACE_int=${FREE_SPACE_TEMP%%.*}
        #FREE_SPACE_TEMP_GB=`expr $FREE_SPACE_TEMP_int / 1024`
        #echo $FREE_SPACE_GB
        #echo "$TABLESPACE_NAME has only $FREE_SPACE MB freespace and it is $USED_PCT % utilized"
        MAIL_BODY=`echo "$TABLESPACE_NAME has only $FREE_SPACE_TEMP GB freespace and it is 100 % utilized"`
        echo $MAIL_BODY

  if [ $FREE_SPACE_TEMP -eq 0 ]; then
     #echo "I am $SID "
     echo $MAIL_BODY | mail -r `whoami` -s "Tablespace_ALERT_moni: $SID - TableSpace $TABLESPACE_NAME is 100 % used" sam8boc+moni@gmail.com

  fi


done < "$LOGS/$SID.$HOST.TS.txt"
echo "Finished tscheckGEn script on Host ... " $HOST


