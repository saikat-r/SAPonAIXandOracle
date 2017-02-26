#!/bin/bash


typeset CALLER="$(id | sed 's/[^(]*(//;s/).*//')"
SCNAME=$0
SVNAME=${SCNAME%.*}
DIRNAME=`dirname $0`
#DIRNAME=`pwd`
CFGFILE=${SVNAME}.config
CFGTEMP="/tmp/"`basename ${CFGFILE}`".temp"
egrep -v '^[ ]*#|^$' $CFGFILE | awk '{ print $1 " " $2 }' | sed -e 's/ $//' > $CFGTEMP
source $CFGTEMP


export PATH=/sapdb/programs/bin:/oracle/$SID/121/bin:/usr/java14/jre/bin:.:/home/appusers/$SID_ADM:/usr/sap/$SID/SYS/exe/run:/usr/bin:/etc:/usr/sbin:/usr/ucb:/usr/bin/X11:/sbin:/oracle/client/MAXDB/clients/bin:/oracle/$SID/112_64/bin

export LIBPATH=/usr/lib:/lib:/usr/sap/$SID/SYS/exe/run:/oracle/client/12x/instantclient:/sapdb/programs/lib/lib64:/oracle/client/MAXDB/clients/lib:/oracle/client/MAXDB/clients/lib/lib64:/usr/lib:/lib:/usr/sap/$SID/SYS/exe/run:/oracle/client/11x_64/instantclient:/opt/freeware/lib:/opt/freeware/lib:/oracle/client/10x_64/instantclient:/oracle/$SID/11204/bin/:/oracle/$SID/11204/lib/:/oracle/$SID/112_64/bin/:/oracle/$SID/112_64/lib/:/oracle/$SID/121/bin/:/oracle/$SID/121/lib/:/usr/lib:/lib:/usr/sap/$SID/SYS/exe/run:/oracle/client/11x_64/instantclient:/opt/freeware/lib:/opt/freeware/lib

export ORACLE_HOME=$ORACLE_HOME



export dbms_type=ORA
export dbs_ora_tnsname=$SID
export dbs_ora_schema=$DBOWNER
export ORACLE_SID=$SID
export DB_SID=$SID
export ORACLE_BASE=/oracle
export TNS_ADMIN=/usr/sap/$SID/SYS/profile/oracle

export NLS_LANG=AMERICAN_AMERICA.UTF8



ERROR_COUNT=100
#WORK_LOG=/usr/sap/AGU/DVEBMGS20/work
#ORA_LOG=/oracle/AGU/saptrace/diag/rdbms/agu/AGU/trace
#WORK_DIRECTORY=/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING
#SCRIPT_DIRECTORY=/usr/sap/scratch/MONITORING_SCRIPT/
REPORT_DIR=/usr/sap/scratch/DAILYMONI/reports
#SQL_SCRIPT_DIR=/usr/sap/scratch/DAILYMONI/scripts/SQL_SCRPT/

TODAY=`date +%y%m%d`
YSDAY=$((TODAY-1))


REPORT_NAME=$REPORT_DIR/"MON_"$SERVICE_NAME".html"
REPORT_SQL_REDOLOG_SWTCH_DAY=$REPORT_DIR/"REP_REDOLOG_SWTCH_DAY_"$SID".html"
REPORT_SQL_LARGEST_TABLE=$REPORT_DIR/"REP_LARGEST_TABLE_"$SID".html"
REPORT_SQL_ABBORTED_JOBS=$REPORT_DIR/"REP_ABBORTED_JOBS_"$SID".html"
REPORT_SQL_TABLE_SPACE=$REPORT_DIR/"REP_TABLE_SPACE_"$SID".html"


sqlplus -s "/ as sysdba" << DBSTAT
    SET FEEDBACK OFF
    SET LINESIZE 5000
    SET TRIMSPOOL ON
    SET TERMOUT OFF
    SET SPACE 100
    SET PAGESIZE 200

spool $WORK_DIRECTORY/REP_SQL_REDOLOG_SWTCH_DAY_$SID.txt
@$SQL_SCRIPT_DIR/redo_log_switch_day.sql
spool off;

spool $WORK_DIRECTORY/REP_SQL_LARGEST_TABLE_$SID.txt
@$SQL_SCRIPT_DIR/largest_table_in_db.sql
spool off;

spool $WORK_DIRECTORY/REP_SQL_ABBORTED_JOBS_$SID.txt
select count(STATUS) from $DBOWNER.tbtco where ENDDATE='$YSDAY' and STATUS='A';
spool off;

spool $WORK_DIRECTORY/REP_SQL_TABLE_SPACE_$SID.txt
@$SQL_SCRIPT_DIR/tablespace.sql
spool off;

DBSTAT



sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_SQL_REDOLOG_SWTCH_DAY_"$SID".txt" > $WORK_DIRECTORY/"REP_SQL_REDOLOG_SWTCH_DAY_"$SID"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_SQL_REDOLOG_SWTCH_DAY_"$SID"_front.txt" > $WORK_DIRECTORY/"REP_SQL_REDOLOG_SWTCH_DAY_"$SID".txt"


sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_SQL_LARGEST_TABLE_"$SID".txt" > $WORK_DIRECTORY/"REP_SQL_LARGEST_TABLE_"$SID"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_SQL_LARGEST_TABLE_"$SID"_front.txt" > $WORK_DIRECTORY/"REP_SQL_LARGEST_TABLE_"$SID".txt"


sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_SQL_ABBORTED_JOBS_"$SID".txt" > $WORK_DIRECTORY/"REP_SQL_ABBORTED_JOBS_"$SID"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_SQL_ABBORTED_JOBS_"$SID"_front.txt" > $WORK_DIRECTORY/"REP_SQL_ABBORTED_JOBS_"$SID".txt"


sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_SQL_TABLE_SPACE_"$SID".txt" > $WORK_DIRECTORY/"REP_SQL_TABLE_SPACE_"$SID"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_SQL_TABLE_SPACE_"$SID"_front.txt" > $WORK_DIRECTORY/"REP_SQL_TABLE_SPACE_"$SID".txt"




#=================
#REDOLOG_SWTCH_DAY
#=================


echo "<html>" > $REPORT_SQL_REDOLOG_SWTCH_DAY
echo "<body>" >> $REPORT_SQL_REDOLOG_SWTCH_DAY
echo "<table>" >> $REPORT_SQL_REDOLOG_SWTCH_DAY
#echo "<tr>" >> $REPORT_SQL_REDOLOG_SWTCH_DAY
cat "$WORK_DIRECTORY/"REP_SQL_REDOLOG_SWTCH_DAY_"$SID".txt"" >> $REPORT_SQL_REDOLOG_SWTCH_DAY


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_WORKPROCESS_"$SERVICE_NAME".txt"" >> $REPORT_SQL_REDOLOG_SWTCH_DAY


#echo "</tr>" >> $REPORT_SQL_REDOLOG_SWTCH_DAY
echo "</table>" >> $REPORT_SQL_REDOLOG_SWTCH_DAY
echo "</body>" >> $REPORT_SQL_REDOLOG_SWTCH_DAY
echo "</html>" >> $REPORT_SQL_REDOLOG_SWTCH_DAY


#=================
#LARGEST_TABLE
#=================


echo "<html>" > $REPORT_SQL_LARGEST_TABLE
echo "<body>" >> $REPORT_SQL_LARGEST_TABLE
echo "<table>" >> $REPORT_SQL_LARGEST_TABLE
#echo "<tr>" >> $REPORT_SQL_LARGEST_TABLE
cat "$WORK_DIRECTORY/"REP_SQL_LARGEST_TABLE_"$SID".txt"" >> $REPORT_SQL_LARGEST_TABLE


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_WORKPROCESS_"$SERVICE_NAME".txt"" >> $REPORT_SQL_LARGEST_TABLE


#echo "</tr>" >> $REPORT_SQL_LARGEST_TABLE
echo "</table>" >> $REPORT_SQL_LARGEST_TABLE
echo "</body>" >> $REPORT_SQL_LARGEST_TABLE
echo "</html>" >> $REPORT_SQL_LARGEST_TABLE


#=================
#ABBORTED_JOBS
#=================



echo "<html>" > $REPORT_SQL_ABBORTED_JOBS
echo "<body>" >> $REPORT_SQL_ABBORTED_JOBS
echo "<table>" >> $REPORT_SQL_ABBORTED_JOBS
#echo "<tr>" >> $REPORT_SQL_ABBORTED_JOBS
cat "$WORK_DIRECTORY/"REP_SQL_ABBORTED_JOBS_"$SID".txt"" >> $REPORT_SQL_ABBORTED_JOBS


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_WORKPROCESS_"$SERVICE_NAME".txt"" >> $REPORT_SQL_ABBORTED_JOBS


#echo "</tr>" >> $REPORT_SQL_ABBORTED_JOBS
echo "</table>" >> $REPORT_SQL_ABBORTED_JOBS
echo "</body>" >> $REPORT_SQL_ABBORTED_JOBS
echo "</html>" >> $REPORT_SQL_ABBORTED_JOBS


#=================
#TABLE SPACE
#=================



echo "<html>" > $REPORT_SQL_TABLE_SPACE
echo "<body>" >> $REPORT_SQL_TABLE_SPACE
echo "<table>" >> $REPORT_SQL_TABLE_SPACE
#echo "<tr>" >> $REPORT_SQL_TABLE_SPACE
cat "$WORK_DIRECTORY/"REP_SQL_TABLE_SPACE_"$SID".txt"" >> $REPORT_SQL_TABLE_SPACE


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_WORKPROCESS_"$SERVICE_NAME".txt"" >> $REPORT_SQL_ABBORTED_JOBS


#echo "</tr>" >> $REPORT_SQL_TABLE_SPACE
echo "</table>" >> $REPORT_SQL_TABLE_SPACE
echo "</body>" >> $REPORT_SQL_TABLE_SPACE
echo "</html>" >> $REPORT_SQL_TABLE_SPACE




cd /usr/sap/scratch/DAILYMONI/reports/
ftp -vn ftpq.edc.linde.grp <<FTP_REP > ftp.log
user SImoni Iamroot0
cd moniscripts/monitoringLOGS/
prompt
ascii
mput MON_${SID}*
mput REP_*_${SID}*
quit
FTP_REP
