#!/usr/bin/bash
# Sumit Das 2017 02 17 Original
# System Info Script from DB

SID=$1
SCHEMA=$2
cd /home/users/in10c2/sumit/ADHOCDBINFO
HOST=`uname -n`
echo "Started System Info from DB script on Host ..." $HOST

echo "---------------" > SYSINFO$SID.txt
echo "ServerOS" `uname -a` >> SYSINFO$SID.txt
echo "OSPatch" `oslevel -s` >> SYSINFO$SID.txt
echo "SAPKernelVersion" `disp+work | grep make | awk '{print $(NF)}'` >> SYSINFO$SID.txt
echo "SAPKernelPatch" `disp+work | grep patch | awk '{print $(NF)}'` >> SYSINFO$SID.txt

sqlplus -s "/ as sysdba" << SYSINFO
    SET FEEDBACK OFF
    SET TRIMSPOOL ON
    SET TERMOUT OFF
    SET LINESIZE 1000
    SET PAGESIZE 400
    SET COLSEP , 

spool DBINFO$SID.txt
select * from $SCHEMA.SVERS;
select * from $SCHEMA.CVERS;
spool OFF;
SYSINFO

echo "SAP Release" >> SYSINFO$SID.txt
cat DBINFO$SID.txt >> SYSINFO$SID.txt

