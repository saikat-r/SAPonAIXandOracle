#!/usr/bin/bash
# Sumit Das 2017 02 17 Original
# System Info Script from DB

SID=$1
SCHEMA=$2
cd /home/users/in10c2/sumit/ADHOCDBINFO

HOST=`uname -n`
echo "Started System Info from DB script on Host ..." $HOST
sqlplus -s "/ as sysdba" << SYSINFO
    SET FEEDBACK OFF
    SET TRIMSPOOL ON
    SET TERMOUT OFF
    SET LINESIZE 1000
    SET PAGESIZE 400
    

spool DBAUSERS$SID.txt
select username from dba_users;
spool OFF;
SYSINFO

cat DBAUSERS$SID.txt






