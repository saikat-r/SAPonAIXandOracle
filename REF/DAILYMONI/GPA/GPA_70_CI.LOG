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



ERROR_COUNT=100
#WORK_LOG=/usr/sap/AGU/DVEBMGS20/work
#ORA_LOG=/oracle/AGU/saptrace/diag/rdbms/agu/AGU/trace
#WORK_DIRECTORY=/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING
#SCRIPT_DIRECTORY=/usr/sap/scratch/MONITORING_SCRIPT/
REPORT_DIR=/usr/sap/scratch/DAILYMONI/reports




REPORT_NAME=$REPORT_DIR/"MON_"$SERVICE_NAME".html"
REPORT_WORKPROCESS_NAME=$REPORT_DIR/"REP_WORKPROCESS_"$SERVICE_NAME".html"
REPORT_RFC_NAME=$REPORT_DIR/"REP_RFC_"$SERVICE_NAME".html"
REPORT_GATEWAY_NAME=$REPORT_DIR/"REP_GATEWAY_"$SERVICE_NAME".html"
REPORT_DISPATCHER_NAME=$REPORT_DIR/"REP_DISPATCHER_"$SERVICE_NAME".html"
REPORT_ENQUE_NAME=$REPORT_DIR/"REP_ENQUE_"$SERVICE_NAME".html"
REPORT_STDERR_NAME=$REPORT_DIR/"REP_STDERROR_"$SERVICE_NAME".html"
REPORT_STDOUT_NAME=$REPORT_DIR/"REP_STDOUT_"$SERVICE_NAME".html"
REPORT_ICM_NAME=$REPORT_DIR/"REP_ICM_"$SERVICE_NAME".html"
REPORT_MSGSRVR_NAME=$REPORT_DIR/"REP_MSGSRVR_"$SERVICE_NAME".html"
REPORT_DEVTP_NAME=$REPORT_DIR/"REP_DEVTP_"$SERVICE_NAME".html"
REPORT_ORA_ALERT_SID_NAME=$REPORT_DIR/"REP_ORA_ALERT_SID_"$SERVICE_NAME".html"




grep -i error $WORK_LOG/dev_w* | tail -n $ERROR_COUNT | sort | uniq -c > $WORK_DIRECTORY/"REP_WORKPROCESS_"$SERVICE_NAME".txt"
sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_WORKPROCESS_"$SERVICE_NAME".txt" > $WORK_DIRECTORY/"REP_WORKPROCESS_"$SERVICE_NAME"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_WORKPROCESS_"$SERVICE_NAME"_front.txt" > $WORK_DIRECTORY/"REP_WORKPROCESS_"$SERVICE_NAME".txt"

grep -i error $WORK_LOG/dev_rfc* | tail -n $ERROR_COUNT | sort | uniq -c > $WORK_DIRECTORY/"REP_RFC_"$SERVICE_NAME".txt"
sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_RFC_"$SERVICE_NAME".txt" > $WORK_DIRECTORY/"REP_RFC_"$SERVICE_NAME"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_RFC_"$SERVICE_NAME"_front.txt" > $WORK_DIRECTORY/"REP_RFC_"$SERVICE_NAME".txt"

grep -i error $WORK_LOG/dev_rd* | tail -n $ERROR_COUNT | sort | uniq -c > $WORK_DIRECTORY/"REP_GATEWAY_"$SERVICE_NAME".txt"
sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_GATEWAY_"$SERVICE_NAME".txt" > $WORK_DIRECTORY/"REP_GATEWAY_"$SERVICE_NAME"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_GATEWAY_"$SERVICE_NAME"_front.txt" > $WORK_DIRECTORY/"REP_GATEWAY_"$SERVICE_NAME".txt"

grep -i error $WORK_LOG/dev_disp* | tail -n $ERROR_COUNT | sort | uniq -c > $WORK_DIRECTORY/"REP_DISPATCHER_"$SERVICE_NAME".txt"
sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_DISPATCHER_"$SERVICE_NAME".txt" > $WORK_DIRECTORY/"REP_DISPATCHER_"$SERVICE_NAME"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_DISPATCHER_"$SERVICE_NAME"_front.txt" > $WORK_DIRECTORY/"REP_DISPATCHER_"$SERVICE_NAME".txt"


grep -i error $WORK_LOG/ENQLOG* | tail -n $ERROR_COUNT | sort | uniq -c > $WORK_DIRECTORY/"REP_ENQUE_"$SERVICE_NAME".txt"
sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_ENQUE_"$SERVICE_NAME".txt" > $WORK_DIRECTORY/"REP_ENQUE_"$SERVICE_NAME"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_ENQUE_"$SERVICE_NAME"_front.txt" > $WORK_DIRECTORY/"REP_ENQUE_"$SERVICE_NAME".txt"

grep -i error $WORK_LOG/stderr* | tail -n $ERROR_COUNT | sort | uniq -c > $WORK_DIRECTORY/"REP_STDERROR_"$SERVICE_NAME".txt"
sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_STDERROR_"$SERVICE_NAME".txt" > $WORK_DIRECTORY/"REP_STDERROR_"$SERVICE_NAME"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_STDERROR_"$SERVICE_NAME"_front.txt" > $WORK_DIRECTORY/"REP_STDERROR_"$SERVICE_NAME".txt"

grep -i error $WORK_LOG/stdout* | tail -n $ERROR_COUNT | sort | uniq -c > $WORK_DIRECTORY/"REP_STDOUT_"$SERVICE_NAME".txt"
sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_STDOUT_"$SERVICE_NAME".txt" > $WORK_DIRECTORY/"REP_STDOUT_"$SERVICE_NAME"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_STDOUT_"$SERVICE_NAME"_front.txt" > $WORK_DIRECTORY/"REP_STDOUT_"$SERVICE_NAME".txt"

grep -i error $WORK_LOG/dev_icm* | tail -n $ERROR_COUNT | sort | uniq -c > $WORK_DIRECTORY/"REP_ICM_"$SERVICE_NAME".txt"
sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_ICM_"$SERVICE_NAME".txt" > $WORK_DIRECTORY/"REP_ICM_"$SERVICE_NAME"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_ICM_"$SERVICE_NAME"_front.txt" > $WORK_DIRECTORY/"REP_ICM_"$SERVICE_NAME".txt"

grep -i error $WORK_LOG/dev_ms* | tail -n $ERROR_COUNT | sort | uniq -c > $WORK_DIRECTORY/"REP_MS_"$SERVICE_NAME".txt"
sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_MS_"$SERVICE_NAME".txt" > $WORK_DIRECTORY/"REP_MS_"$SERVICE_NAME"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_MS_"$SERVICE_NAME"_front.txt" > $WORK_DIRECTORY/"REP_MS_"$SERVICE_NAME".txt"

grep -i error $WORK_LOG/dev_tp* | tail -n $ERROR_COUNT | sort | uniq -c > $WORK_DIRECTORY/"REP_DEVTP_"$SERVICE_NAME".txt"
sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_DEVTP_"$SERVICE_NAME".txt" > $WORK_DIRECTORY/"REP_DEVTP_"$SERVICE_NAME"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_DEVTP_"$SERVICE_NAME"_front.txt" > $WORK_DIRECTORY/"REP_DEVTP_"$SERVICE_NAME".txt"


grep -i error $ORA_LOG/"alert_"$SID".log" | tail -n $ERROR_COUNT | sort | uniq -c > $WORK_DIRECTORY/"REP_ORA_ALERT_SID_"$SERVICE_NAME".txt"
sed -e 's/^/<p>/' $WORK_DIRECTORY/"REP_ORA_ALERT_SID_"$SERVICE_NAME".txt" > $WORK_DIRECTORY/"REP_ORA_ALERT_SID_"$SERVICE_NAME"_front.txt"
awk '$0=$0" </p>"' $WORK_DIRECTORY/"REP_ORA_ALERT_SID_"$SERVICE_NAME"_front.txt" > $WORK_DIRECTORY/"REP_ORA_ALERT_SID_"$SERVICE_NAME".txt"





#=================
#WORKPROCESS
#=================


echo "<html>" > $REPORT_WORKPROCESS_NAME
echo "<body>" >> $REPORT_WORKPROCESS_NAME
echo "<table>" >> $REPORT_WORKPROCESS_NAME
#echo "<tr>" >> $REPORT_WORKPROCESS_NAME
cat "$WORK_DIRECTORY/"REP_WORKPROCESS_"$SERVICE_NAME".txt"" >> $REPORT_WORKPROCESS_NAME


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_WORKPROCESS_"$SERVICE_NAME".txt"" >> $REPORT_WORKPROCESS_NAME


#echo "</tr>" >> $REPORT_WORKPROCESS_NAME
echo "</table>" >> $REPORT_WORKPROCESS_NAME
echo "</body>" >> $REPORT_WORKPROCESS_NAME
echo "</html>" >> $REPORT_WORKPROCESS_NAME

#=================


#=================
#RFC
#=================

echo "<html>" > $REPORT_RFC_NAME
echo "<body>" >> $REPORT_RFC_NAME
echo "<table>" >> $REPORT_RFC_NAME
#echo "<tr>" >> $REPORT_RFC_NAME
cat "$WORK_DIRECTORY/"REP_RFC_"$SERVICE_NAME".txt"" >> $REPORT_RFC_NAME


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_RFC_"$SERVICE_NAME".txt"" >> $REPORT_RFC_NAME


#echo "</tr>" >> $REPORT_RFC_NAME
echo "</table>" >> $REPORT_RFC_NAME
echo "</body>" >> $REPORT_RFC_NAME
echo "</html>" >> $REPORT_RFC_NAME

#=================


#=================
#GATEWAY
#=================


echo "<html>" > $REPORT_GATEWAY_NAME
echo "<body>" >> $REPORT_GATEWAY_NAME
echo "<table>" >> $REPORT_GATEWAY_NAME
#echo "<tr>" >> $REPORT_GATEWAY_NAME
cat "$WORK_DIRECTORY/"REP_GATEWAY_"$SERVICE_NAME".txt"" >> $REPORT_GATEWAY_NAME


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_GATEWAY_"$SERVICE_NAME".txt"" >> $REPORT_GATEWAY_NAME


#echo "</tr>" >> $REPORT_GATEWAY_NAME
echo "</table>" >> $REPORT_GATEWAY_NAME
echo "</body>" >> $REPORT_GATEWAY_NAME
echo "</html>" >> $REPORT_GATEWAY_NAME

#=================

#=================

#=================
#DISPATCHER
#=================


echo "<html>" > $REPORT_DISPATCHER_NAME
echo "<body>" >> $REPORT_DISPATCHER_NAME
echo "<table>" >> $REPORT_DISPATCHER_NAME
#echo "<tr>" >> $REPORT_DISPATCHER_NAME
cat "$WORK_DIRECTORY/"REP_DISPATCHER_"$SERVICE_NAME".txt"" >> $REPORT_DISPATCHER_NAME


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_DISPATCHER_"$SERVICE_NAME".txt"" >> $REPORT_DISPATCHER_NAME


#echo "</tr>" >> $REPORT_DISPATCHER_NAME
echo "</table>" >> $REPORT_DISPATCHER_NAME
echo "</body>" >> $REPORT_DISPATCHER_NAME
echo "</html>" >> $REPORT_DISPATCHER_NAME

#=================

#=================

#=================
#ENQUEUE
#=================


echo "<html>" > $REPORT_ENQUE_NAME
echo "<body>" >> $REPORT_ENQUE_NAME
echo "<table>" >> $REPORT_ENQUE_NAME
#echo "<tr>" >> $REPORT_ENQUE_NAME
cat "$WORK_DIRECTORY/"REP_ENQUE_"$SERVICE_NAME".txt"" >> $REPORT_ENQUE_NAME


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_ENQUE_"$SERVICE_NAME".txt"" >> $REPORT_ENQUE_NAME


#echo "</tr>" >> $REPORT_ENQUE_NAME
echo "</table>" >> $REPORT_ENQUE_NAME
echo "</body>" >> $REPORT_ENQUE_NAME
echo "</html>" >> $REPORT_ENQUE_NAME

#=================

#=================

#=================
#STDERR
#=================


echo "<html>" > $REPORT_STDERR_NAME
echo "<body>" >> $REPORT_STDERR_NAME
echo "<table>" >> $REPORT_STDERR_NAME
#echo "<tr>" >> $REPORT_STDERR_NAME
cat "$WORK_DIRECTORY/"REP_STDERROR_"$SERVICE_NAME".txt"" >> $REPORT_STDERR_NAME


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_STDERR_"$SERVICE_NAME".txt"" >> $REPORT_STDERR_NAME


#echo "</tr>" >> $REPORT_STDERR_NAME
echo "</table>" >> $REPORT_STDERR_NAME
echo "</body>" >> $REPORT_STDERR_NAME
echo "</html>" >> $REPORT_STDERR_NAME

#=================

#=================

#=================
#STDOUT
#=================


echo "<html>" > $REPORT_STDOUT_NAME
echo "<body>" >> $REPORT_STDOUT_NAME
echo "<table>" >> $REPORT_STDOUT_NAME
#echo "<tr>" >> $REPORT_STDOUT_NAME
cat "$WORK_DIRECTORY/"REP_STDOUT_"$SERVICE_NAME".txt"" >> $REPORT_STDOUT_NAME


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_STDOUT_"$SERVICE_NAME".txt"" >> $REPORT_STDOUT_NAME


#echo "</tr>" >> $REPORT_STDOUT_NAME
echo "</table>" >> $REPORT_STDOUT_NAME
echo "</body>" >> $REPORT_STDOUT_NAME
echo "</html>" >> $REPORT_STDOUT_NAME

#=================

#=================

#=================
#ICM
#=================


echo "<html>" > $REPORT_ICM_NAME
echo "<body>" >> $REPORT_ICM_NAME
echo "<table>" >> $REPORT_ICM_NAME
#echo "<tr>" >> $REPORT_ICM_NAME
cat "$WORK_DIRECTORY/"REP_ICM_"$SERVICE_NAME".txt"" >> $REPORT_ICM_NAME


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_ICM_"$SERVICE_NAME".txt"" >> $REPORT_ICM_NAME


#echo "</tr>" >> $REPORT_ICM_NAME
echo "</table>" >> $REPORT_ICM_NAME
echo "</body>" >> $REPORT_ICM_NAME
echo "</html>" >> $REPORT_ICM_NAME

#=================

#=================

#=================
#MESSAGE SERVER
#=================


echo "<html>" > $REPORT_MSGSRVR_NAME
echo "<body>" >> $REPORT_MSGSRVR_NAME
echo "<table>" >> $REPORT_MSGSRVR_NAME
#echo "<tr>" >> $REPORT_MSGSRVR_NAME
cat "$WORK_DIRECTORY/"REP_MS_"$SERVICE_NAME".txt"" >> $REPORT_MSGSRVR_NAME


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_MSGSRVR_"$SERVICE_NAME".txt"" >> $REPORT_MSGSRVR_NAME


#echo "</tr>" >> $REPORT_MSGSRVR_NAME
echo "</table>" >> $REPORT_MSGSRVR_NAME
echo "</body>" >> $REPORT_MSGSRVR_NAME
echo "</html>" >> $REPORT_MSGSRVR_NAME

#=================

#=================

#=================
#DEV_TP
#=================


echo "<html>" > $REPORT_DEVTP_NAME
echo "<body>" >> $REPORT_DEVTP_NAME
echo "<table>" >> $REPORT_DEVTP_NAME
#echo "<tr>" >> $REPORT_DEVTP_NAME
cat "$WORK_DIRECTORY/"REP_DEVTP_"$SERVICE_NAME".txt"" >> $REPORT_DEVTP_NAME


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_DEVTP_"$SERVICE_NAME".txt"" >> $REPORT_DEVTP_NAME


#echo "</tr>" >> $REPORT_DEVTP_NAME
echo "</table>" >> $REPORT_DEVTP_NAME
echo "</body>" >> $REPORT_DEVTP_NAME
echo "</html>" >> $REPORT_DEVTP_NAME

#=================


#=================
#ORACLE SID LOG
#=================


echo "<html>" > $REPORT_ORA_ALERT_SID_NAME
echo "<body>" >> $REPORT_ORA_ALERT_SID_NAME
echo "<table>" >> $REPORT_ORA_ALERT_SID_NAME
#echo "<tr>" >> $REPORT_ORA_ALERT_SID_NAME
cat "$WORK_DIRECTORY/"REP_ORA_ALERT_SID_"$SERVICE_NAME".txt"" >> $REPORT_ORA_ALERT_SID_NAME


#cat "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/"REP_ORA_ALERT_SID_"$SERVICE_NAME".txt"" >> $REPORT_ORA_ALERT_SID_NAME


#echo "</tr>" >> $REPORT_ORA_ALERT_SID_NAME
echo "</table>" >> $REPORT_ORA_ALERT_SID_NAME
echo "</body>" >> $REPORT_ORA_ALERT_SID_NAME
echo "</html>" >> $REPORT_ORA_ALERT_SID_NAME

#=================





