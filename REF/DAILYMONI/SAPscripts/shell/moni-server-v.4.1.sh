#!/usr/bin/bash
# Sumit Das 2015 06 07
# DB Oracle Scripts

user=$1
passwd=$2
sqlplus -s /nolog << EOF
CONNECT $user/$passwd 
whenever sqlerror exit sql.sqlcode;
set echo off 
set feedback off
--set heading off
set underline off
set lin 10000
set pagesize 50000
--set colsep ,

prompt Calculating TableSpace Usage...
prompt x-----------------------------x
-M "HTML ON TABLE 'BORDER="2"'" @/home/users/in10c2/ORACLEscripts/Tablespace_Usage_Percent_Info.sql > SQLmoni_Tablespace_Usage_Percent_Info.html
prompt
prompt
prompt Calculating Temp TableSpace Usage...
prompt x----------------------------------x
@/home/users/in10c2/ORACLEscripts/Temp_Tablespace_Freespace.sql
prompt
prompt
prompt Calculating Log_Switch_in_A_Day...
prompt x--------------------------------x
@/home/users/in10c2/ORACLEscripts/Finding_Log_Switch_in_A_Day.sql
prompt
prompt


exit;
EOF

cat "~/SQLmoni_Tablespace_Usage_Percent_Info.html" | mailx -r "ORACLE" -s "DB Status" "sam8boc@gmail.com"
exit
