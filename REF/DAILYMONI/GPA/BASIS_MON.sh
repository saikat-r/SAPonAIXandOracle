#!/bin/bash

set -x


typeset CALLER="$(id | sed 's/[^(]*(//;s/).*//')"
SCNAME=$0
SVNAME=${SCNAME%.*}
DIRNAME=`dirname $0`
#DIRNAME=`pwd`
CFGFILE=${SVNAME}.config
CFGTEMP="/tmp/"`basename ${CFGFILE}`".temp"
egrep -v '^[ ]*#|^$' $CFGFILE | awk '{ print $1 " " $2 }' | sed -e 's/ $//' > $CFGTEMP
source $CFGTEMP


#source "/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING/variable.cfg"

#SID=AGU

MOUNT_GRN_THRES=60
MOUNT_RED_THRES=90
ERROR_COUNT=100
MAIL_DIST_LIST=nayan.karmakar@linde.com
#WORK_LOG=/usr/sap/AGU/DVEBMGS20/work
#ORA_LOG=/oracle/AGU/saptrace/diag/rdbms/agu/AGU/trace
#WORK_DIRECTORY=/usr/sap/scratch/NAYAN_TEST_DIR/DAILYMONITORING
REPORT_DIR=/usr/sap/scratch/DAILYMONI/reports

#SCRIPT_DIRECTORY=/usr/sap/scratch/MONITORING_SCRIPT/
echo > /usr/sap/scratch/DAILYMONI/SQL_SCRPT/""$SID"_DB_STAT.tmp"

SID_DB_STAT=/usr/sap/scratch/DAILYMONI/SQL_SCRPT/""$SID"_DB_STAT.tmp"
#REPORT_NAME=/usr/sap/scratch/NAYAN_TEST_DIR/SQL_SCRPT/MON_REP.html

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



###########################################################################################################################

#SQL PART

###########################################################################################################################



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



if [ $SERVICE_NAME == ""$SID"_"$SAP_SYSTEM_NO"_DB" ]

then
echo $SERVICE_NAME
echo ""$SID"_"$SAP_SYSTEM_NO"_DB"


/oracle/$SID/11204/bin/sqlplus -s "/ as sysdba" << DBSTAT
    SET HEADING OFF
    SET FEEDBACK OFF
    SET LINESIZE 3800
    SET TRIMSPOOL ON
    SET TERMOUT OFF
    SET SPACE 0
    SET PAGESIZE 0
spool $SID_DB_STAT
select status from v\$instance;
spool off;
DBSTAT

fi


###########################################################################################################################

#RAM CPU DETAIL

###########################################################################################################################

nohup $SCRIPT_DIRECTORY/""$SERVICE_NAME".RAM" > $WORK_DIRECTORY/ram.log 2>&1 & 
nohup $SCRIPT_DIRECTORY/""$SERVICE_NAME".SWAP" > $WORK_DIRECTORY/swap.log 2>&1 &
nohup $SCRIPT_DIRECTORY/""$SERVICE_NAME".CPU" > $WORK_DIRECTORY/cpu.log 2>&1 &





###########################################################################################################################

#REPORT GENERATION START

###########################################################################################################################

echo "<html>" > $REPORT_NAME
echo "<body bgcolor="#ceebfd">" >> $REPORT_NAME

#-------------------------------------------------
#Style declaration
#-------------------------------------------------

echo "<style>" >> $REPORT_NAME
echo "h2 {background-color: #2c3e50; color: #ffff00; text-align: center;}" >> $REPORT_NAME

echo ".button {" >> $REPORT_NAME
echo "  display: inline-block;" >> $REPORT_NAME
echo "  width: 12em;  height: 1.5em;" >> $REPORT_NAME
echo "  font-size: 10px;" >> $REPORT_NAME
echo "  cursor: pointer;" >> $REPORT_NAME
echo "  text-align: center;" >> $REPORT_NAME
echo "  text-decoration: none;" >> $REPORT_NAME
echo "  outline: none;" >> $REPORT_NAME
echo "  color: #fff;" >> $REPORT_NAME
echo "  background-color:  #2980b9;" >> $REPORT_NAME
echo "  border: none;" >> $REPORT_NAME
echo "  border-radius: 50px;" >> $REPORT_NAME
echo " box-shadow: 0 5px #666;" >> $REPORT_NAME
echo "}" >> $REPORT_NAME

echo ".button:hover {background-color:   #1a5276}" >> $REPORT_NAME

echo ".button:active {" >> $REPORT_NAME
echo "  background-color:  #d35400;" >> $REPORT_NAME
echo "  box-shadow: 0 0px #666;" >> $REPORT_NAME
echo "  transform: translateY(4px);" >> $REPORT_NAME
echo "}" >> $REPORT_NAME


echo "</style>" >> $REPORT_NAME
#-------------------------------------------------

echo "<p>" >> $REPORT_NAME
echo "<h2>Report Generation Date: "$(date)"</h2>" >> $REPORT_NAME
echo "<h2>Report Generated for Host: "$SAP_LOCALHOST" SID: "$SID" Application Type: "$SERVICE_NAME"</h2>" >> $REPORT_NAME

#=================
#Table for Buttons
#=================

#=================
#Table for Buttons
#=================

#echo "&nbsp;" >> $REPORT_NAME

echo "<table align="center" bgcolor="#ceebfd">" >> $REPORT_NAME


echo "<tr>" >> $REPORT_NAME

echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_WORKPROCESS_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>WP-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_RFC_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>RFC-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_GATEWAY_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>GATEWAY-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_DISPATCHER_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>DISPATCHER_LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_ENQUE_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>ENQUE_LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME

#echo "</tr>" >> $REPORT_NAME

#echo "<tr>" >> $REPORT_NAME

echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_STDERROR_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>STDERROR_LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_STDOUT_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>STDOUT-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_ICM_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>ICM-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_MSGSRVR_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>MSGSRVR-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME

#echo "&nbsp;" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_DEVTP_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>DEVTP-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME

echo "</tr>" >> $REPORT_NAME

echo "</table>" >> $REPORT_NAME
#echo "&nbsp;" >> $REPORT_NAME






#echo "&nbsp;" >> $REPORT_NAME
echo "<table align="center" bgcolor="#ceebfd">" >> $REPORT_NAME
echo "<tr>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_ORA_ALERT_SID_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>ORA_ALERT_SID-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_REDOLOG_SWTCH_DAY_"$SID".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>REDO LOG WEEKLY</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME

echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_LARGEST_TABLE_"$SID".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>LARGEST TABLE</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME

echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_ABBORTED_JOBS_"$SID".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>ABBORTED JOBS</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME

echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_TABLE_SPACE_"$SID".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>TABLE SPACE</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "</tr>" >> $REPORT_NAME
echo "</table>" >> $REPORT_NAME
echo "&nbsp;" >> $REPORT_NAME

#=================
#Table for MAIN REPORTS
#=================




echo "<table style="width:100%">" >> $REPORT_NAME





###########################################################################################################################

#Collect Variables

###########################################################################################################################

#==========================================================================================================================
#DB RELATED
#==========================================================================================================================

DB_STAT=$(cat $SID_DB_STAT | grep OPEN | wc -l)

echo $DB_STAT


#==========================================================================================================================
#DB Process
#==========================================================================================================================

LSNRCTL_STAT=$(ps -ef | grep tnslsnr | grep -v grep | wc -l)
ORA_PROS_COUNT=$(ps -ef | grep "oracle"$SID"" | grep -v grep | grep -v tnslsnr | wc -l)
ORA_LOG_WRTR_STAT=$(ps -ef | grep "ora_lgwr_"$SID"" | grep -v grep | wc -l)
ORA_DATB_WRTR_STAT=$(ps -ef | grep "ora_dbw0_"$SID"" | grep -v grep | wc -l)
ORA_RCVR_PROS_STAT=$(ps -ef | grep ora_reco_ | grep -v grep | wc -l)
ORA_PROS_MON_STAT=$(ps -ef | grep "ora_pmon_"$SID"" | grep -v grep | wc -l) 
ORA_SYS_MON_STAT=$(ps -ef | grep "ora_smon_"$SID"" | grep -v grep | wc -l)
ORA_CHKPNT_STAT=$(ps -ef | grep "ora_ckpt_"$SID"" | grep -v grep | wc -l)
ORA_ARCHVR_STAT=$(ps -ef | grep ora_arc | grep -v grep | wc -l)
ORA_DBRM_PROS_STAT=$(ps -ef | grep "ora_dbrm_"$SID"" | grep -v grep | wc -l)
ORA_AQ_SRVR_PROS_STAT=$(ps -ef | grep ora_q00 | grep -v grep | wc -l)
ORA_SPC_MNG_SLV_PROS_STAT=$(ps -ef | grep ora_w00 | grep -v grep | wc -l)
ORA_DIAG_CPTR_PROS_STAT=$(ps -ef | grep "ora_diag_"$SID"" | grep -v grep | wc -l)
ORA_GEN_TASK_EXEC_PROS_STAT=$(ps -ef | grep ora_gen | grep -v grep | wc -l)

ORA_LAST_BACKUP_FILE=$(ls -lrt /oracle/$SID/sapbackup | grep .anf | tail -1 | awk '{print $9}')
ORA_LAST_BACKUP_FILE_TIME=$(ls -lrt /oracle/$SID/sapbackup | grep .anf | tail -1 | awk '{print $6, $7, $8}')
ORA_BACKUP_STATUS_COM_SUCC=$(grep -i completed.successfully /oracle/$SID/sapbackup/$ORA_LAST_BACKUP_FILE | wc -l)
ORA_BACKUP_STATUS_STAT_FILE=$WORK_DIRECTORY/BACKUP_STAT_FILE.txt
ORA_BACKUP_STATUS_STAT=$(grep -i error /oracle/$SID/sapbackup/$ORA_LAST_BACKUP_FILE > $ORA_BACKUP_STATUS_STAT_FILE)




#==========================================================================================================================
#SAP Processes ABAP SINGLE NODE
#==========================================================================================================================

MESSAGE_SERVER_STAT=$(ps -ef | grep -e "ms.sap"$SID"" | grep -v grep | wc -l)
GATEWAY_STAT=$(ps -ef | grep gwrd | grep $SAP_LOCALHOST | grep $SID | grep -v grep | wc -l)
WORKPROCESS_STAT=$(ps -ef | grep "dw.sap"$SID"" | grep $SAP_LOCALHOST | grep $SID | grep -v grep | wc -l)
SAPSTART_SERV_STAT=$(ps -ef | grep -w sapstart | grep $SAP_LOCALHOST | grep $SID | grep -v grep | wc -l)
STARTSRV_STAT=$(ps -ef | grep sapstartsrv | grep $SAP_LOCALHOST | grep $SID | grep -v grep | wc -l)
INTRNT_COM_MNGR_STAT=$(ps -ef | grep icman | grep $SAP_LOCALHOST | grep $SID | grep -v grep | wc -l)
COLLECTOR_PROC_STAT=$(ps -ef | grep "co.sap"$SID"" | grep $SAP_LOCALHOST | grep -v grep | wc -l)
SEND_PROC_STAT=$(ps -ef | grep "se.sap"$SID"" | grep $SAP_LOCALHOST | grep -v grep | wc -l)
INTRNT_GRPH_SRV_STAT=$(ps -ef | grep "ig.sap"$SID"" | grep $SAP_LOCALHOST | grep -v grep | wc -l)




echo q | /sapmnt/$SID/exe/dpmon pf=/sapmnt/$SID/profile/$INSTANCE_PROFILE l > $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE_$INSTANCE_PROFILE

DPMON_WORKPROCESS_STOP_STAT=$(grep -i DpMonInit.failed $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | wc -l)

DPMON_WORKPROCESS_DIA_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep DIA | grep -v grep | wc -l)
DPMON_WORKPROCESS_DIA_RUN_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep DIA | grep -i RUN | grep -v grep | wc -l)
DPMON_WORKPROCESS_DIA_STOP_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep DIA | grep -i STOP | grep -v grep | wc -l)
DPMON_WORKPROCESS_DIA_WAIT_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep DIA | grep -i WAIT | grep -i RUN | grep -v grep | wc -l)
DPMON_WORKPROCESS_DIA_HOLD_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep DIA | grep -i HOLD | grep -v grep | wc -l)
DPMON_WORKPROCESS_DIA_PRIV_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep DIA | grep -i PRIV | grep -v grep | wc -l)

DPMON_WORKPROCESS_UPD_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep UPD | grep -v grep | wc -l)
DPMON_WORKPROCESS_UPD_RUN_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep UPD | grep -i RUN | grep -v grep | wc -l)
DPMON_WORKPROCESS_UPD_STOP_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep UPD | grep -i STOP | grep -v grep | wc -l)
DPMON_WORKPROCESS_UPD_WAIT_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep UPD | grep -i WAIT | grep -i RUN | grep -v grep | wc -l)
DPMON_WORKPROCESS_UPD_HOLD_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep UPD | grep -i HOLD | grep -v grep | wc -l)
DPMON_WORKPROCESS_UPD_PRIV_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep UPD | grep -i PRIV | grep -v grep | wc -l)


DPMON_WORKPROCESS_UP2_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep UP2 | grep -v grep | wc -l)
DPMON_WORKPROCESS_UP2_RUN_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep UP2 | grep -i RUN | grep -v grep | wc -l)
DPMON_WORKPROCESS_UP2_STOP_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep UP2 | grep -i STOP | grep -v grep | wc -l)
DPMON_WORKPROCESS_UP2_WAIT_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep UP2 | grep -i WAIT | grep -i RUN | grep -v grep | wc -l)
DPMON_WORKPROCESS_UP2_HOLD_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep UP2 | grep -i HOLD | grep -v grep | wc -l)
DPMON_WORKPROCESS_UP2_PRIV_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep UP2 | grep -i PRIV | grep -v grep | wc -l)

DPMON_WORKPROCESS_ENQ_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep ENQ | grep -v grep | wc -l)
DPMON_WORKPROCESS_ENQ_RUN_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep ENQ | grep -i RUN | grep -v grep | wc -l)
DPMON_WORKPROCESS_ENQ_STOP_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep ENQ | grep -i STOP | grep -v grep | wc -l)
DPMON_WORKPROCESS_ENQ_WAIT_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep ENQ | grep -i WAIT | grep -i RUN | grep -v grep | wc -l)
DPMON_WORKPROCESS_ENQ_HOLD_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep ENQ | grep -i HOLD | grep -v grep | wc -l)
DPMON_WORKPROCESS_ENQ_PRIV_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep ENQ | grep -i PRIV | grep -v grep | wc -l)

DPMON_WORKPROCESS_BTC_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep BTC | grep -v grep | wc -l)
DPMON_WORKPROCESS_BTC_RUN_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep BTC | grep -i RUN | grep -v grep | wc -l)
DPMON_WORKPROCESS_BTC_STOP_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep BTC | grep -i STOP | grep -v grep | wc -l)
DPMON_WORKPROCESS_BTC_WAIT_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep BTC | grep -i WAIT | grep -i RUN | grep -v grep | wc -l)
DPMON_WORKPROCESS_BTC_HOLD_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep BTC | grep -i HOLD | grep -v grep | wc -l)
DPMON_WORKPROCESS_BTC_PRIV_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep BTC | grep -i PRIV | grep -v grep | wc -l)

DPMON_WORKPROCESS_SPO_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep SPO | grep -v grep | wc -l)
DPMON_WORKPROCESS_SPO_RUN_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep SPO | grep -i RUN | grep -v grep | wc -l)
DPMON_WORKPROCESS_SPO_STOP_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep SPO | grep -i STOP | grep -v grep | wc -l)
DPMON_WORKPROCESS_SPO_WAIT_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep SPO | grep -i WAIT | grep -i RUN | grep -v grep | wc -l)
DPMON_WORKPROCESS_SPO_HOLD_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep SPO | grep -i HOLD | grep -v grep | wc -l)
DPMON_WORKPROCESS_SPO_HOLD_COUNT=$(cat $WORK_DIRECTORY/TOTAL_DPMON_WORKPROCESS.txt_$INSTANCE_PROFILE | grep SPO | grep -i HOLD | grep -v grep | wc -l)
#==========================================================================================================================
#LOG FILES
#==========================================================================================================================
AVAILABLE_LOG_STAT=$(tail -1 $WORK_LOG/available.log | awk '{print $1}' | grep -w Unavailable | wc -l)
AVAILABLE_LOG_PERIOD=$(tail -1 $WORK_LOG/available.log | awk '{print $2, $3, $4, $5, $6}')

VMCAVAILABLE_LOG_STAT=$(tail -1 $WORK_LOG/VMCavailable.log | awk '{print $3}'  | cut -f 1,20 -d :)
VMCAVAILABLE_LOG_PERIOD=$(tail -1 $WORK_LOG/VMCavailable.log | awk '{print $1, $2}')


nohup $SCRIPT_DIRECTORY/$SERVICE_NAME.LOG > $WORK_DIRECTORY/test.log 2>&1 &


#==========================================================================================================================
#Mount POints
#==========================================================================================================================


DF_USR_SAP_MNTPNT=$(df -gt /usr/sap | grep /usr/sap | awk '{print $6}' | head -1)
DF_USR_SAP_ALCTN=$(df -gt /usr/sap | grep /usr/sap | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_USR_SAP_COUNT=$(df -gt /usr/sap | grep /usr/sap | wc -l)

DF_USR_SAP_SID_MNTPNT=$(df -gt /usr/sap/$SID | grep /usr/sap/$SID | awk '{print $6}' | head -1)
DF_USR_SAP_SID_ALCTN=$(df -gt /usr/sap/$SID | grep /usr/sap/$SID | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_USR_SAP_SID_COUNT=$(df -gt /usr/sap/$SID | grep /usr/sap/$SID | wc -l)

DF_SAPMNT_MNTPNT=$(df -gt /sapmnt | grep /sapmnt | awk '{print $6}' | head -1)
DF_SAPMNT_ALCTN=$(df -gt /sapmnt | grep /sapmnt | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_SAPMNT_COUNT=$(df -gt /sapmnt | grep /sapmnt | wc -l)

DF_SAPMNT_SID_MNTPNT=$(df -gt /sapmnt/$SID | grep /sapmnt/$SID | awk '{print $6}' | head -1)
DF_SAPMNT_SID_ALCTN=$(df -gt /sapmnt/$SID | grep /sapmnt/$SID | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_SAPMNT_SID_COUNT=$(df -gt /sapmnt/$SID | grep /sapmnt/$SID | wc -l)

DF_ORACL_MNTPNT=$(df -gt /oracle | grep /oracle | awk '{print $6}' | head -1)
DF_ORACL_ALCTN=$(df -gt /oracle | grep /oracle | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_ORACL_COUNT=$(df -gt /oracle | grep /oracle | wc -l)

DF_ORACL_SID_MNTPNT=$(df -gt /oracle/$SID | grep /oracle/$SID | awk '{print $6}' | head -1)
DF_ORACL_SID_ALCTN=$(df -gt /oracle/$SID | grep /oracle/$SID | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_ORACL_SID_COUNT=$(df -gt /oracle/$SID | grep /oracle/$SID | wc -l)

DF_SAPREORG_MNTPNT=$(df -gt /oracle/$SID/sapreorg | grep /oracle/$SID/sapreorg | awk '{print $6}' | head -1)
DF_SAPREORG_ALCTN=$(df -gt /oracle/$SID/sapreorg | grep /oracle/$SID/sapreorg | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_SAPREORG_COUNT=$(df -gt /oracle/$SID/sapreorg | grep /oracle/$SID/sapreorg | wc -l)

DF_SAPTRCE_MNTPNT=$(df -gt /oracle/$SID/saptrace | grep /oracle/$SID/saptrace | awk '{print $6}' | head -1)
DF_SAPTRCE_ALCTN=$(df -gt /oracle/$SID/saptrace | grep /oracle/$SID/saptrace | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_SAPTRCE_COUNT=$(df -gt /oracle/$SID/saptrace | grep /oracle/$SID/saptrace | wc -l)

DF_SAPARCH_MNTPNT=$(df -gt /oracle/$SID/saparch | grep /oracle/$SID/saparch | awk '{print $6}' | head -1)
DF_SAPARCH_ALCTN=$(df -gt /oracle/$SID/saparch | grep /oracle/$SID/saparch | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_SAPARCH_COUNT=$(df -gt /oracle/$SID/saparch | grep /oracle/$SID/saparch | wc -l)

DF_SAPBKP_MNTPNT=$(df -gt /oracle/$SID/sapbackup | grep /oracle/$SID/sapbackup | awk '{print $6}' | head -1)
DF_SAPBKP_ALCTN=$(df -gt /oracle/$SID/sapbackup | grep /oracle/$SID/sapbackup | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_SAPBKP_COUNT=$(df -gt /oracle/$SID/sapbackup | grep /oracle/$SID/sapbackup | wc -l)

DF_ORAARCH_MNTPNT=$(df -gt /oracle/$SID/oraarch | grep /oracle/$SID/oraarch | awk '{print $6}' | head -1)
DF_ORAARCH_ALCTN=$(df -gt /oracle/$SID/oraarch | grep /oracle/$SID/oraarch | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_ORAARCH_COUNT=$(df -gt /oracle/$SID/oraarch | grep /oracle/$SID/oraarch | wc -l)

DF_OLOGA_MNTPNT=$(df -gt /oracle/$SID/origlogA | grep /oracle/$SID/origlogA | awk '{print $6}' | head -1)
DF_OLOGA_ALCTN=$(df -gt /oracle/$SID/origlogA | grep /oracle/$SID/origlogA | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_OLOGA_COUNT=$(df -gt /oracle/$SID/origlogA | grep /oracle/$SID/origlogA | wc -l)

DF_OLOGB_MNTPNT=$(df -gt /oracle/$SID/origlogB | grep /oracle/$SID/origlogB | awk '{print $6}' | head -1)
DF_OLOGB_ALCTN=$(df -gt /oracle/$SID/origlogB | grep /oracle/$SID/origlogB | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_OLOGB_COUNT=$(df -gt /oracle/$SID/origlogB | grep /oracle/$SID/origlogB | wc -l)

DF_MLOGA_MNTPNT=$(df -gt /oracle/$SID/mirrlogA | grep /oracle/$SID/mirrlogA | awk '{print $6}' | head -1)
DF_MLOGA_ALCTN=$(df -gt /oracle/$SID/mirrlogA | grep /oracle/$SID/mirrlogA | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_MLOGA_COUNT=$(df -gt /oracle/$SID/mirrlogA | grep /oracle/$SID/mirrlogA | wc -l)

DF_MLOGB_MNTPNT=$(df -gt /oracle/$SID/mirrlogB | grep /oracle/$SID/mirrlogB | awk '{print $6}' | head -1)
DF_MLOGB_ALCTN=$(df -gt /oracle/$SID/mirrlogB | grep /oracle/$SID/mirrlogB | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_MLOGB_COUNT=$(df -gt /oracle/$SID/mirrlogB | grep /oracle/$SID/mirrlogB | wc -l)

DF_ARCHVPL_MNTPNT=$(df -gt /oracle/$SID/archivepool | grep /oracle/$SID/archivepool | awk '{print $6}' | head -1)
DF_ARCHVPL_ALCTN=$(df -gt /oracle/$SID/archivepool | grep /oracle/$SID/archivepool | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_ARCHVPL_COUNT=$(df -gt /oracle/$SID/archivepool | grep /oracle/$SID/archivepool | wc -l)

DF_ARCHVPL_MNTPNT=$(df -gt /oracle/$SID/archivpool | grep /oracle/$SID/archivpool | awk '{print $6}' | head -1)
DF_ARCHVPL_ALCTN=$(df -gt /oracle/$SID/archivpool | grep /oracle/$SID/archivpool | awk '{print $5}' | cut -f 1,3 -d % | head -1)
DF_ARCHVPL_COUNT=$(df -gt /oracle/$SID/archivpool | grep /oracle/$SID/archivpool | wc -l)


#DF_SAPDATA1_MNTPNT=$(df -gt /oracle/$SID/sapdata1 | grep /oracle/$SID/sapdata1 | awk '{print $6}' | head -1)
#DF_SAPDATA1_ALCTN=$(df -gt /oracle/$SID/sapdata1 | grep /oracle/$SID/sapdata1 | awk '{print $5}' | cut -f 1,3 -d % | head -1)
#DF_SAPDATA1_COUNT=$(df -gt /oracle/$SID/sapdata1 | grep /oracle/$SID/sapdata1 | wc -l)

#echo $DB_STAT


#if [ "cat /usr/sap/scratch/NAYAN_TEST_DIR/SQL_SCRPT/DB_STAT.txt" -eq "OPEN" ]


###########################################################################################################################

#Define Monitored Area --> DATABASE

###########################################################################################################################

if [ $SERVICE_NAME == ""$SID"_"$SAP_SYSTEM_NO"_DB" ]

then

echo "<tr>" >> $REPORT_NAME
echo "<th width="25%" bgcolor="#2c3e50" colspan="2"><font color="#d0d3d4">MONITORED AREA -- DATABASE</font></th>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME


###########################################################################################################################

#Define Table Heading

###########################################################################################################################

echo "<tr>" >> $REPORT_NAME
echo "<th width="25%" bgcolor="#2c3e50"><font color="#d0d3d4">MONITORED COMPONENT</font></th>" >> $REPORT_NAME
echo "<th width="25%" bgcolor="#2c3e50"><font color="#d0d3d4">STATUS</font></th>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME



###########################################################################################################################

#Report Generation LOGIC

###########################################################################################################################


if [ "$DB_STAT" -eq 1 ]

echo DBSTAT="$DB_STAT"

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">DATABASE STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">OPEN</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

#echo "DB UP" >> $REPORT_NAME



elif [ "$DB_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">DATABASE STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">DOWN</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

#echo "DB UP" >> $REPORT_NAME

fi

fi


###########################################################################################################################

#Define Monitored Area --> Proceses

###########################################################################################################################

echo "<tr>" >> $REPORT_NAME
echo "<th width="25%" bgcolor="#2c3e50" colspan="2"><font color="#d0d3d4">MONITORED AREA -- PROCESS</font></th>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

echo "<tr>" >> $REPORT_NAME
echo "<th width="25%" bgcolor="#2c3e50"><font color="#d0d3d4">MONITORED COMPONENT</font></th>" >> $REPORT_NAME
echo "<th width="25%" bgcolor="#2c3e50"><font color="#d0d3d4">STATUS</font></th>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME




###########################################################################################################################

#Report Generation LOGIC

###########################################################################################################################
#=========================
#==================================================
#Process Collector for DB Specific
#==================================================
if [ $SERVICE_NAME == ""$SID"_"$SAP_SYSTEM_NO"_DB" ]

then

if [ "$ORA_BACKUP_STATUS_COM_SUCC" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">BACKUP STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">COMPLETED SUCCESFULLY at $ORA_LAST_BACKUP_FILE_TIME</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$ORA_BACKUP_STATUS_COM_SUCC" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">BACKUP STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT COMPLETED/ WARNING at $ORA_LAST_BACKUP_FILE_TIME</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi



if [ "$LSNRCTL_STAT" -ge 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">LISTENER STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$LSNRCTL_STAT" -eq 0 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">LISTENER STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#-------------------
#ORACLE PROCESS COUNT
#-------------------

if [ "$ORA_PROS_COUNT" -gt 0 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">ORACLE PROCESS COUNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING (COUNT: "$ORA_PROS_COUNT")</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$ORA_PROS_COUNT" -eq 0 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">ORACLE PROCESS COUNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED (COUNT: "$ORA_PROS_COUNT")</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#-------------------
#LOG WRITER
#-------------------

if [ "$ORA_LOG_WRTR_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">LOG WRITER STATUS (LGWR)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$ORA_LOG_WRTR_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">LOG WRITER STATUS (LGWR)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#-------------------
#DATABASE WRITER
#-------------------

if [ "$ORA_DATB_WRTR_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">DATABASE WRITER STATUS (DBW0)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$ORA_DATB_WRTR_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">DATABASE WRITER STATUS (DBW0)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi



#-------------------
#PROCESS MONITOR
#-------------------

if [ "$ORA_PROS_MON_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">PROCESS MONITOR STATUS (PMON)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$ORA_PROS_MON_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">PROCESS MONITOR STATUS (PMON)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#-------------------
#SYSTEM MONITOR
#-------------------

if [ "$ORA_SYS_MON_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">SYSTEM MONITOR STATUS (SMON)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$ORA_SYS_MON_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">SYSTEM MONITOR STATUS (SMON)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#-------------------
#CHECKPOINT PROCESS
#-------------------

if [ "$ORA_CHKPNT_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">CHECKPOINT PROCESS STATUS (CKPT)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$ORA_CHKPNT_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">CHECKPOINT PROCESS STATUS (CKPT)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#-------------------
#DATABASE RESOURCE MANAGER PROCESS
#-------------------

if [ "$ORA_DBRM_PROS_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">DATABASE RESOURCE MANAGER PROCESS STATUS (DBRM)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$ORA_DBRM_PROS_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">DATABASE RESOURCE MANAGER PROCESS STATUS (DBRM)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#-------------------
#DIAGNOSTIC CAPTURE PROCESS
#-------------------

if [ "$ORA_DIAG_CPTR_PROS_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">DIAGNOSTIC CAPTURE PROCESS (DIAG)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$ORA_DIAG_CPTR_PROS_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">DIAGNOSTIC CAPTURE PROCESS (DIAG)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#-------------------
#ARCHIVER PROCESS
#-------------------

if [ "$ORA_ARCHVR_STAT" -gt 0 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">ARCHIVER PROCESS STATUS (ARCn)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING (COUNT:"$ORA_ARCHVR_STAT")</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$ORA_ARCHVR_STAT" -eq 0 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">ARCHIVER PROCESS STATUS (ARCn)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED (COUNT:"$ORA_ARCHVR_STAT")</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#-------------------
#AQ SERVER PROCESS
#-------------------

if [ "$ORA_AQ_SRVR_PROS_STAT" -gt 0 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">AQ SERVER PROCESS (Q00n)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING (COUNT:"$ORA_AQ_SRVR_PROS_STAT")</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$ORA_AQ_SRVR_PROS_STAT" -eq 0 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">AQ SERVER PROCESS (Q00n)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED (COUNT:"$ORA_AQ_SRVR_PROS_STAT")</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#-------------------
#SPACE MANAGEMENT SLAVE PROCESS
#-------------------

if [ "$ORA_SPC_MNG_SLV_PROS_STAT" -gt 0 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">SPACE MANAGEMENT SLAVE PROCESS (Wnnn)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING (COUNT:"$ORA_SPC_MNG_SLV_PROS_STAT")</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$ORA_SPC_MNG_SLV_PROS_STAT" -eq 0 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">SPACE MANAGEMENT SLAVE PROCESS (Wnnn)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED (COUNT:"$ORA_SPC_MNG_SLV_PROS_STAT")</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#-------------------
#GENERAL TASK EXECUTION PROCESS
#-------------------

if [ "$ORA_GEN_TASK_EXEC_PROS_STAT" -gt 0 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">GENERAL TASK EXECUTION PROCESS (GENn)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING (COUNT:"$ORA_GEN_TASK_EXEC_PROS_STAT")</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$ORA_GEN_TASK_EXEC_PROS_STAT" -eq 0 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">GENERAL TASK EXECUTION PROCESS (GENn)</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED (COUNT:"$ORA_GEN_TASK_EXEC_PROS_STAT")</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi



fi

#=========================

#=========================
#==================================================
#Process Collector for CI/ APPLICATIONSERVER Specific
#==================================================

if [ $SERVICE_NAME == ""$SID"_"$SAP_SYSTEM_NO"_CI" ]

then

if [ "$MESSAGE_SERVER_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">MESSAGE SERVER STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$MESSAGE_SERVER_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">MESSAGE SERVER STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

fi
#=========================

#=========================

if [ $SERVICE_NAME == ""$SID"_"$SAP_SYSTEM_NO"_CI" -o $SERVICE_NAME == ""$SID"_"$SAP_SYSTEM_NO"_AP" ]

then

if [ "$GATEWAY_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">GATEWAY STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$GATEWAY_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">GATEWAY STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#=========================

#=========================
if [ "$WORKPROCESS_STAT" -ge 1 -a "$DPMON_WORKPROCESS_STOP_STAT" -eq "0" ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">WORK PROCESS COUNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">"$WORKPROCESS_STAT"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME


#1-------------

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">DIALOG WORK PROCESS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">TOTAL:"$DPMON_WORKPROCESS_DIA_COUNT" RUNNING:"$DPMON_WORKPROCESS_DIA_RUN_COUNT" STOPPED:"$DPMON_WORKPROCESS_DIA_STOP_COUNT" WAIT:"$DPMON_WORKPROCESS_DIA_WAIT_COUNT" HOLD:"$DPMON_WORKPROCESS_DIA_HOLD_COUNT" PRIVATE: "$DPMON_WORKPROCESS_DIA_PRIV_COUNT"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME


#2-------------

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">UPDATE WORK PROCESS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">TOTAL:"$DPMON_WORKPROCESS_UPD_COUNT" RUNNING:"$DPMON_WORKPROCESS_UPD_RUN_COUNT" STOPPED"$DPMON_WORKPROCESS_UPD_STOP_COUNT" WAIT:"$DPMON_WORKPROCESS_UPD_WAIT_COUNT" HOLD:"$DPMON_WORKPROCESS_UPD_HOLD_COUNT" PRIVATE: "$DPMON_WORKPROCESS_UPD_PRIV_COUNT"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME



#3-------------

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">UPDATE2 WORK PROCESS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">TOTAL:"$DPMON_WORKPROCESS_UP2_COUNT" RUNNING:"$DPMON_WORKPROCESS_UP2_RUN_COUNT" STOPPED:"$DPMON_WORKPROCESS_UP2_STOP_COUNT" WAIT:"$DPMON_WORKPROCESS_UP2_WAIT_COUNT" HOLD:"$DPMON_WORKPROCESS_UP2_HOLD_COUNT" PRIVATE: "$DPMON_WORKPROCESS_UP2_PRIV_COUNT"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME



#4-------------

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">ENQUE WORK PROCESS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">TOTAL:"$DPMON_WORKPROCESS_ENQ_COUNT" RUNNING:"$DPMON_WORKPROCESS_ENQ_RUN_COUNT" STOPPED"$DPMON_WORKPROCESS_ENQ_STOP_COUNT" WAIT:"$DPMON_WORKPROCESS_ENQ_WAIT_COUNT" HOLD:"$DPMON_WORKPROCESS_ENQ_HOLD_COUNT" PRIVATE: "$DPMON_WORKPROCESS_ENQ_PRIV_COUNT"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME



#5--------------------------

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">BATCH WORK PROCESS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">TOTAL:"$DPMON_WORKPROCESS_BTC_COUNT" RUNNING:"$DPMON_WORKPROCESS_BTC_RUN_COUNT" STOPPED:"$DPMON_WORKPROCESS_BTC_STOP_COUNT" WAIT:"$DPMON_WORKPROCESS_BTC_WAIT_COUNT" HOLD:"$DPMON_WORKPROCESS_BTC_HOLD_COUNT" PRIVATE: "$DPMON_WORKPROCESS_BTC_PRIV_COUNT"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME



#6-------------

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">SPOOL WORK PROCESS COUNT TOTAL</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">TOTAL:"$DPMON_WORKPROCESS_SPO_COUNT" RUNNING:"$DPMON_WORKPROCESS_SPO_RUN_COUNT" STOPPED:"$DPMON_WORKPROCESS_SPO_STOP_COUNT" WAIT:"$DPMON_WORKPROCESS_SPO_WAIT_COUNT" HOLD:"$DPMON_WORKPROCESS_SPO_HOLD_COUNT" PRIVATE: "$DPMON_WORKPROCESS_SPO_HOLD_COUNT"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME



#-------------


fi



#-------------

if [ "$WORKPROCESS_STAT" -eq 0 -o "$DPMON_WORKPROCESS_STOP_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">WORK PROCESS COUNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">"$WORKPROCESS_STAT"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

#1-------------

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">DIALOG WORK PROCESS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">TOTAL:"$DPMON_WORKPROCESS_DIA_COUNT" RUNNING:"$DPMON_WORKPROCESS_DIA_RUN_COUNT" STOPPED:"$DPMON_WORKPROCESS_DIA_STOP_COUNT" WAIT:"$DPMON_WORKPROCESS_DIA_WAIT_COUNT" HOLD:"$DPMON_WORKPROCESS_DIA_HOLD_COUNT" PRIVATE: "$DPMON_WORKPROCESS_DIA_PRIV_COUNT"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME


#2-------------

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">UPDATE WORK PROCESS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">TOTAL:"$DPMON_WORKPROCESS_UPD_COUNT" RUNNING:"$DPMON_WORKPROCESS_UPD_RUN_COUNT" STOPPED"$DPMON_WORKPROCESS_UPD_STOP_COUNT" WAIT:"$DPMON_WORKPROCESS_UPD_WAIT_COUNT" HOLD:"$DPMON_WORKPROCESS_UPD_HOLD_COUNT" PRIVATE: "$DPMON_WORKPROCESS_UPD_PRIV_COUNT"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME



#3-------------

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">UPDATE2 WORK PROCESS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">TOTAL:"$DPMON_WORKPROCESS_UP2_COUNT" RUNNING:"$DPMON_WORKPROCESS_UP2_RUN_COUNT" STOPPED:"$DPMON_WORKPROCESS_UP2_STOP_COUNT" WAIT:"$DPMON_WORKPROCESS_UP2_WAIT_COUNT" HOLD:"$DPMON_WORKPROCESS_UP2_HOLD_COUNT" PRIVATE: "$DPMON_WORKPROCESS_UP2_PRIV_COUNT"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME



#4-------------

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">ENQUE WORK PROCESS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">TOTAL:"$DPMON_WORKPROCESS_ENQ_COUNT" RUNNING:"$DPMON_WORKPROCESS_ENQ_RUN_COUNT" STOPPED"$DPMON_WORKPROCESS_ENQ_STOP_COUNT" WAIT:"$DPMON_WORKPROCESS_ENQ_WAIT_COUNT" HOLD:"$DPMON_WORKPROCESS_ENQ_HOLD_COUNT" PRIVATE: "$DPMON_WORKPROCESS_ENQ_PRIV_COUNT"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME



#5--------------------------

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">BATCH WORK PROCESS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">TOTAL:"$DPMON_WORKPROCESS_BTC_COUNT" RUNNING:"$DPMON_WORKPROCESS_BTC_RUN_COUNT" STOPPED:"$DPMON_WORKPROCESS_BTC_STOP_COUNT" WAIT:"$DPMON_WORKPROCESS_BTC_WAIT_COUNT" HOLD:"$DPMON_WORKPROCESS_BTC_HOLD_COUNT" PRIVATE: "$DPMON_WORKPROCESS_BTC_PRIV_COUNT"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME



#6-------------

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">SPOOL WORK PROCESS COUNT TOTAL</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">TOTAL:"$DPMON_WORKPROCESS_SPO_COUNT" RUNNING:"$DPMON_WORKPROCESS_SPO_RUN_COUNT" STOPPED:"$DPMON_WORKPROCESS_SPO_STOP_COUNT" WAIT:"$DPMON_WORKPROCESS_SPO_WAIT_COUNT" HOLD:"$DPMON_WORKPROCESS_SPO_HOLD_COUNT" PRIVATE: "$DPMON_WORKPROCESS_SPO_HOLD_COUNT"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME



#-------------




fi

#=========================

#=========================

if [ "$SAPSTART_SERV_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">SAPSTART SERVICE STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$SAPSTART_SERV_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">SAPSTART SERVICE STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#=========================

#=========================

if [ "$STARTSRV_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">SAPSTARTSRV SERVICE STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$STARTSRV_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">SAPSTARTSRV SERVICE STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#=========================

#=========================

if [ "$INTRNT_COM_MNGR_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">INTERNET COMMUNICATION MANAGER STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$INTRNT_COM_MNGR_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">INTERNET COMMUNICATION MANAGER STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#=========================

#=========================

if [ "$COLLECTOR_PROC_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">COLLECTOR PROCESS STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$COLLECTOR_PROC_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">COLLECTOR PROCESS STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#=========================

#=========================

if [ "$SEND_PROC_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">SEND PROCESS STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$SEND_PROC_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">SEND PROCESS STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#=========================

#=========================

if [ "$INTRNT_GRPH_SRV_STAT" -eq 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">INTERNET GRAPHICS PROCESS STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">RUNNING</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ "$INTRNT_GRPH_SRV_STAT" -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">INTERNET GRAPHICS PROCESS STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT RUNNING/ STOPPED</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi
#=========================

###########################################################################################################################

#Define Monitored Area --> Mount POint

###########################################################################################################################

echo "<tr>" >> $REPORT_NAME
echo "<th width="25%" bgcolor="#2c3e50" colspan="2"><font color="#d0d3d4">MONITORED AREA -- MOUNTPOINT</font></th>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

echo "<tr>" >> $REPORT_NAME
echo "<th width="25%" bgcolor="#2c3e50"><font color="#d0d3d4">MOUNTPOINT</font></th>" >> $REPORT_NAME
echo "<th width="25%" bgcolor="#2c3e50"><font color="#d0d3d4">ALLOCATION</font></th>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME




###########################################################################################################################

#Report Generation LOGIC

###########################################################################################################################



#USR_SAP

if [ $DF_USR_SAP_COUNT -eq 1 ]
then
if [ $DF_USR_SAP_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_USR_SAP_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_USR_SAP_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi



if [ $DF_USR_SAP_ALCTN -gt $MOUNT_GRN_THRES -a $DF_USR_SAP_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_USR_SAP_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_USR_SAP_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_USR_SAP_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_USR_SAP_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_USR_SAP_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi

#=================

#USR_SAP_SID

if [ $DF_USR_SAP_SID_COUNT -eq 1 ]
then

if [ $DF_USR_SAP_SID_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_USR_SAP_SID_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_USR_SAP_SID_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_USR_SAP_SID_ALCTN -gt $MOUNT_GRN_THRES -a $DF_USR_SAP_SID_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_USR_SAP_SID_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_USR_SAP_SID_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_USR_SAP_SID_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_USR_SAP_SID_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_USR_SAP_SID_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi

#=================

#SAPMNT

if [ $DF_SAPMNT_COUNT -eq 1 ]
then

if [ $DF_SAPMNT_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_SAPMNT_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_SAPMNT_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_SAPMNT_ALCTN -gt $MOUNT_GRN_THRES -a $DF_SAPMNT_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_SAPMNT_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_SAPMNT_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_SAPMNT_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_SAPMNT_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_SAPMNT_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi

#=================

#SAPMNT_SID

if [ $DF_SAPMNT_SID_COUNT -eq 1 ]
then

if [ $DF_SAPMNT_SID_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_SAPMNT_SID_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_SAPMNT_SID_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_SAPMNT_SID_ALCTN -gt $MOUNT_GRN_THRES -a $DF_SAPMNT_SID_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_SAPMNT_SID_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_SAPMNT_SID_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_SAPMNT_SID_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_SAPMNT_SID_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_SAPMNT_SID_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi

#=================

#ORACL

if [ $DF_ORACL_COUNT -eq 1 ]
then

if [ $DF_ORACL_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_ORACL_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_ORACL_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_ORACL_ALCTN -gt $MOUNT_GRN_THRES -a $DF_ORACL_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_ORACL_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_ORACL_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_ORACL_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_ORACL_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_ORACL_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi

#=================

#ORACL_SID

if [ $DF_ORACL_SID_COUNT -eq 1 ]
then

if [ $DF_ORACL_SID_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_ORACL_SID_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_ORACL_SID_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_ORACL_SID_ALCTN -gt $MOUNT_GRN_THRES -a $DF_ORACL_SID_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_ORACL_SID_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_ORACL_SID_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_ORACL_SID_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_ORACL_SID_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_ORACL_SID_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi

#=================

#SAPREORG
if [ $DF_SAPREORG_COUNT -eq 1 ]
then

if [ $DF_SAPREORG_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_SAPREORG_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_SAPREORG_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_SAPREORG_ALCTN -gt $MOUNT_GRN_THRES -a $DF_SAPREORG_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_SAPREORG_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_SAPREORG_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_SAPREORG_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_SAPREORG_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_SAPREORG_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi

#=================

#SAPTRCE

if [ $DF_SAPTRCE_COUNT -eq 1 ]
then

if [ $DF_SAPTRCE_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_SAPTRCE_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_SAPTRCE_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_SAPTRCE_ALCTN -gt $MOUNT_GRN_THRES -a $DF_SAPTRCE_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_SAPTRCE_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_SAPTRCE_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_SAPTRCE_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_SAPTRCE_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_SAPTRCE_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi

#=================

#SAPARCH

if [ $DF_SAPARCH_COUNT -eq 1 ]
then

if [ $DF_SAPARCH_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_SAPARCH_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_SAPARCH_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_SAPARCH_ALCTN -gt $MOUNT_GRN_THRES -a $DF_SAPARCH_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_SAPARCH_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_SAPARCH_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_SAPARCH_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_SAPARCH_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_SAPARCH_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi

#=================

#SAPBKP

if [ $DF_SAPBKP_COUNT -eq 1 ]
font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_ORAARCH_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_ORAARCH_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_ORAARCH_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi

#=================

#OLOGA

if [ $DF_OLOGA_COUNT -eq 1 ]
then

if [ $DF_OLOGA_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_OLOGA_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_OLOGA_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_OLOGA_ALCTN -gt $MOUNT_GRN_THRES -a $DF_OLOGA_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_OLOGA_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_OLOGA_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_OLOGA_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_OLOGA_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_OLOGA_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi

#=================

#OLOGB

if [ $DF_OLOGB_COUNT -eq 1 ]
then


if [ $DF_OLOGB_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_OLOGB_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_OLOGB_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_OLOGB_ALCTN -gt $MOUNT_GRN_THRES -a $DF_OLOGB_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_OLOGB_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_OLOGB_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_OLOGB_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_OLOGB_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_OLOGB_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi

#=================

#MLOGA

if [ $DF_MLOGA_COUNT -eq 1 ]
then

if [ $DF_MLOGA_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_MLOGA_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_MLOGA_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_MLOGA_ALCTN -gt $MOUNT_GRN_THRES -a $DF_MLOGA_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_MLOGA_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_MLOGA_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_MLOGA_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_MLOGA_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_MLOGA_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi

#=================

#MLOGB

if [ $DF_MLOGB_COUNT -eq 1 ]
then

if [ $DF_MLOGB_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_MLOGB_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_MLOGB_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_MLOGB_ALCTN -gt $MOUNT_GRN_THRES -a $DF_MLOGB_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_MLOGB_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_MLOGB_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_MLOGB_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_MLOGB_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_MLOGB_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi

#=================

#ARCHVPL

if [ $DF_ARCHVPL_COUNT -eq 1 ]
then

if [ $DF_ARCHVPL_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_ARCHVPL_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_ARCHVPL_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_ARCHVPL_ALCTN -gt $MOUNT_GRN_THRES -a $DF_ARCHVPL_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_ARCHVPL_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_ARCHVPL_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_ARCHVPL_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_ARCHVPL_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_ARCHVPL_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi
#=================

#SAPDATA

for i in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 
do

DF_SAPDATA_COUNT=$(df -gt | grep /oracle/$SID/sapdata$i | wc -l)

if [ $DF_SAPDATA_COUNT -ge 1 ]
then


DF_SAPDATA_MNTPNT=$(df -gt /oracle/$SID/sapdata$i | grep /oracle/$SID/sapdata$i | awk '{print $6}' | head -1)
DF_SAPDATA_ALCTN=$(df -gt /oracle/$SID/sapdata$i | grep /oracle/$SID/sapdata$i | awk '{print $5}' | cut -f 1,3 -d % | head -1)




if [ $DF_SAPDATA_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_SAPDATA_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">$DF_SAPDATA_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_SAPDATA_ALCTN -gt $MOUNT_GRN_THRES -a $DF_SAPDATA_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_SAPDATA_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f9e79f"><font color="#7d6608">$DF_SAPDATA_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi


if [ $DF_SAPDATA_ALCTN -gt $MOUNT_RED_THRES ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_SAPDATA_MNTPNT</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">$DF_SAPDATA_ALCTN "%"</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi
fi


done
#=================
###########################################################################################################################

#Define Monitored Area --> LOGS

###########################################################################################################################

echo "<tr>" >> $REPORT_NAME
echo "<th width="25%" bgcolor="#2c3e50" colspan="2"><font color="#d0d3d4">MONITORED AREA -- LOGS</font></th>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

echo "<tr>" >> $REPORT_NAME
echo "<th width="25%" bgcolor="#2c3e50"><font color="#d0d3d4">MONITORED COMPONENT</font></th>" >> $REPORT_NAME
echo "<th width="25%" bgcolor="#2c3e50"><font color="#d0d3d4">STATUS</font></th>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME




###########################################################################################################################

#=================

#AVAILABLE LOG


if [ $AVAILABLE_LOG_STAT -ne 1 ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">SAP AVAILABLE LOG STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">AVAILABLE (SINCE: $AVAILABLE_LOG_PERIOD)</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

else

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">SAP AVAILABLE LOG STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT AVAILABLE (SINCE: $AVAILABLE_LOG_PERIOD)</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#=================

#=================

#AVAILABLE LOG


if [ $VMCAVAILABLE_LOG_STAT == "available" ]

then

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">SAP VMC AVAILABLE LOG STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#abebc6"><font color="#145a32">AVAILABLE (TIME: $VMCAVAILABLE_LOG_PERIOD)</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME


else

echo "<tr>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">SAP VMC AVAILABLE LOG STATUS</font></td>" >> $REPORT_NAME
echo "<td width="25%" bgcolor="#f5b7b1"><font color="#641e16">NOT AVAILABLE (TIME: $VMCAVAILABLE_LOG_PERIOD)</font></td>" >> $REPORT_NAME
echo "</tr>" >> $REPORT_NAME

fi

#=================

echo "</table>" >> $REPORT_NAME



#=================







 


#=================
#Table for Buttons
#=================

echo "&nbsp;" >> $REPORT_NAME

echo "<table align="center" bgcolor="#ceebfd">" >> $REPORT_NAME


echo "<tr>" >> $REPORT_NAME

echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_WORKPROCESS_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>WP-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_RFC_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>RFC-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_GATEWAY_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>GATEWAY-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_DISPATCHER_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>DISPATCHER_LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_ENQUE_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>ENQUE_LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME



#echo "</tr>" >> $REPORT_NAME


#echo "<tr>" >> $REPORT_NAME




echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_STDERROR_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>STDERROR_LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_STDOUT_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>STDOUT-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_ICM_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>ICM-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_MSGSRVR_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>MSGSRVR-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_DEVTP_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>DEVTP-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME

echo "</tr>" >> $REPORT_NAME

echo "</table>" >> $REPORT_NAME
#echo "&nbsp;" >> $REPORT_NAME



#echo "&nbsp;" >> $REPORT_NAME
echo "<table align="center" bgcolor="#ceebfd">" >> $REPORT_NAME
echo "<tr>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_ORA_ALERT_SID_"$SERVICE_NAME".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>ORA_ALERT_SID-LOG</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_REDOLOG_SWTCH_DAY_"$SID".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>REDO LOG WEEKLY</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME

echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_LARGEST_TABLE_"$SID".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>LARGEST TABLE</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME

echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_ABBORTED_JOBS_"$SID".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>ABBORTED JOBS</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME

echo "<td>" >> $REPORT_NAME
echo "<form method=get action=http://wlggceod000e0.linde.lds.grp/basis/AIXmoni/tables/"REP_TABLE_SPACE_"$SID".html">" >> $REPORT_NAME
echo "<button type=submit class=button align=center><span>TABLE SPACE</span></button>" >> $REPORT_NAME
echo "</form>" >> $REPORT_NAME
echo "</td>" >> $REPORT_NAME


echo "</tr>" >> $REPORT_NAME
echo "</table>" >> $REPORT_NAME
echo "&nbsp;" >> $REPORT_NAME

#====================================================================================================
#
# CANVAS SECTION
#
#====================================================================================================


echo '<canvas id="myCanvas1" width="300" height="200" style="border:1px solid #34495e; background-color:#34495e">' >> $REPORT_NAME
echo "Your browser does not support the canvas element." >> $REPORT_NAME
echo "</canvas>" >> $REPORT_NAME



#USR_SAP
#====================

if [ $DF_USR_SAP_COUNT -ge 1 ]
then
if [ $DF_USR_SAP_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,1,"$DF_USR_SAP_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_USR_SAP_ALCTN""%" "$DF_USR_SAP_MNTPNT"'"'",""$DF_USR_SAP_ALCTN"",8,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_USR_SAP_ALCTN -gt $MOUNT_GRN_THRES -a $DF_USR_SAP_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,1,"$DF_USR_SAP_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_USR_SAP_ALCTN""%" "$DF_USR_SAP_MNTPNT"'"'",""$DF_USR_SAP_ALCTN"",8,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_USR_SAP_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,1,"$DF_USR_SAP_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_USR_SAP_ALCTN""%" "$DF_USR_SAP_MNTPNT"'"'",""$DF_USR_SAP_ALCTN"",8,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#USR_SAP_SID

if [ $DF_USR_SAP_SID_COUNT -ge 1 ]
then

if [ $DF_USR_SAP_SID_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,10,"$DF_USR_SAP_SID_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_USR_SAP_SID_ALCTN""%" "$DF_USR_SAP_SID_MNTPNT"'"'",""$DF_USR_SAP_SID_ALCTN"",17,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_USR_SAP_SID_ALCTN -gt $MOUNT_GRN_THRES -a $DF_USR_SAP_SID_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,10,"$DF_USR_SAP_SID_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_USR_SAP_SID_ALCTN""%" "$DF_USR_SAP_SID_MNTPNT"'"'",""$DF_USR_SAP_SID_ALCTN"",17,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_USR_SAP_SID_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,10,"$DF_USR_SAP_SID_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_USR_SAP_SID_ALCTN""%" "$DF_USR_SAP_SID_MNTPNT"'"'",""$DF_USR_SAP_SID_ALCTN"",17,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#SAPMNT

if [ $DF_SAPMNT_COUNT -ge 1 ]
then

if [ $DF_SAPMNT_ALCTN -le $MOUNT_GRN_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,19,"$DF_SAPMNT_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPMNT_ALCTN""%" "$DF_SAPMNT_MNTPNT"'"'",""$DF_SAPMNT_ALCTN"",26,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_SAPMNT_ALCTN -gt $MOUNT_GRN_THRES -a $DF_SAPMNT_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,19,"$DF_SAPMNT_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPMNT_ALCTN""%" "$DF_SAPMNT_MNTPNT"'"'",""$DF_SAPMNT_ALCTN"",26,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_SAPMNT_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,19,"$DF_SAPMNT_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPMNT_ALCTN""%" "$DF_SAPMNT_MNTPNT"'"'",""$DF_SAPMNT_ALCTN"",26,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#SAPMNT_SID

if [ $DF_SAPMNT_SID_COUNT -ge 1 ]
then

if [ $DF_SAPMNT_SID_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,28,"$DF_SAPMNT_SID_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPMNT_SID_ALCTN""%" "$DF_SAPMNT_SID_MNTPNT"'"'",""$DF_SAPMNT_SID_ALCTN"",35,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_SAPMNT_SID_ALCTN -gt $MOUNT_GRN_THRES -a $DF_SAPMNT_SID_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,28,"$DF_SAPMNT_SID_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPMNT_SID_ALCTN""%" "$DF_SAPMNT_SID_MNTPNT"'"'",""$DF_SAPMNT_SID_ALCTN"",35,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_SAPMNT_SID_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,28,"$DF_SAPMNT_SID_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPMNT_SID_ALCTN""%" "$DF_SAPMNT_SID_MNTPNT"'"'",""$DF_SAPMNT_SID_ALCTN"",35,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#ORACL

if [ $DF_ORACL_COUNT -ge 1 ]
then

if [ $DF_ORACL_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,37,"$DF_ORACL_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_ORACL_ALCTN""%" "$DF_ORACL_MNTPNT"'"'",""$DF_ORACL_ALCTN"",44,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_ORACL_ALCTN -gt $MOUNT_GRN_THRES -a $DF_ORACL_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,37,"$DF_ORACL_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_ORACL_ALCTN""%" "$DF_ORACL_MNTPNT"'"'",""$DF_ORACL_ALCTN"",44,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_ORACL_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,37,"$DF_ORACL_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_ORACL_ALCTN""%" "$DF_ORACL_MNTPNT"'"'",""$DF_ORACL_ALCTN"",44,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi


#=================
#ORACL_SID

if [ $DF_ORACL_SID_COUNT -ge 1 ]
then

if [ $DF_ORACL_SID_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,46,"$DF_ORACL_SID_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_ORACL_SID_ALCTN""%" "$DF_ORACL_SID_MNTPNT"'"'",""$DF_ORACL_SID_ALCTN"",53,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_ORACL_SID_ALCTN -gt $MOUNT_GRN_THRES -a $DF_ORACL_SID_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,46,"$DF_ORACL_SID_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_ORACL_SID_ALCTN""%" "$DF_ORACL_SID_MNTPNT"'"'",""$DF_ORACL_SID_ALCTN"",53,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_ORACL_SID_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,46,"$DF_ORACL_SID_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_ORACL_SID_ALCTN""%" "$DF_ORACL_SID_MNTPNT"'"'",""$DF_ORACL_SID_ALCTN"",53,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#SAPREORG
if [ $DF_SAPREORG_COUNT -ge 1 ]
then

if [ $DF_SAPREORG_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,55,"$DF_SAPREORG_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPREORG_ALCTN""%" "$DF_SAPREORG_MNTPNT"'"'",""$DF_SAPREORG_ALCTN"",62,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_SAPREORG_ALCTN -gt $MOUNT_GRN_THRES -a $DF_SAPREORG_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,55,"$DF_SAPREORG_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPREORG_ALCTN""%" "$DF_SAPREORG_MNTPNT"'"'",""$DF_SAPREORG_ALCTN"",62,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_SAPREORG_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,55,"$DF_SAPREORG_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPREORG_ALCTN""%" "$DF_SAPREORG_MNTPNT"'"'",""$DF_SAPREORG_ALCTN"",62,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#SAPTRCE

if [ $DF_SAPTRCE_COUNT -ge 1 ]
then

if [ $DF_SAPTRCE_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,64,"$DF_SAPTRCE_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPTRCE_ALCTN""%" "$DF_SAPTRCE_MNTPNT"'"'",""$DF_SAPTRCE_ALCTN"",71,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_SAPTRCE_ALCTN -gt $MOUNT_GRN_THRES -a $DF_SAPTRCE_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,64,"$DF_SAPTRCE_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPTRCE_ALCTN""%" "$DF_SAPTRCE_MNTPNT"'"'",""$DF_SAPTRCE_ALCTN"",71,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_SAPTRCE_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,64,"$DF_SAPTRCE_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPTRCE_ALCTN""%" "$DF_SAPTRCE_MNTPNT"'"'",""$DF_SAPTRCE_ALCTN"",71,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#SAPARCH

if [ $DF_SAPARCH_COUNT -ge 1 ]
then

if [ $DF_SAPARCH_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,73,"$DF_SAPARCH_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPARCH_ALCTN""%" "$DF_SAPARCH_MNTPNT"'"'",""$DF_SAPARCH_ALCTN"",80,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_SAPARCH_ALCTN -gt $MOUNT_GRN_THRES -a $DF_SAPARCH_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,73,"$DF_SAPARCH_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPARCH_ALCTN""%" "$DF_SAPARCH_MNTPNT"'"'",""$DF_SAPARCH_ALCTN"",80,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_SAPARCH_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,73,"$DF_SAPARCH_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPARCH_ALCTN""%" "$DF_SAPARCH_MNTPNT"'"'",""$DF_SAPARCH_ALCTN"",80,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#SAPBKP

if [ $DF_SAPBKP_COUNT -ge 1 ]
then

if [ $DF_SAPBKP_ALCTN -le $MOUNT_GRN_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,82,"$DF_SAPBKP_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPBKP_ALCTN""%" "$DF_SAPBKP_MNTPNT"'"'",""$DF_SAPBKP_ALCTN"",89,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_SAPBKP_ALCTN -gt $MOUNT_GRN_THRES -a $DF_SAPBKP_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,82,"$DF_SAPBKP_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPBKP_ALCTN""%" "$DF_SAPBKP_MNTPNT"'"'",""$DF_SAPBKP_ALCTN"",89,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_SAPBKP_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,82,"$DF_SAPBKP_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_SAPBKP_ALCTN""%" "$DF_SAPBKP_MNTPNT"'"'",""$DF_SAPBKP_ALCTN"",89,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#ORAARCH

if [ $DF_ORAARCH_COUNT -ge 1 ]
then

if [ $DF_ORAARCH_ALCTN -le $MOUNT_GRN_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,91,"$DF_ORAARCH_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_ORAARCH_ALCTN""%" "$DF_ORAARCH_MNTPNT"'"'",""$DF_ORAARCH_ALCTN"",98,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_ORAARCH_ALCTN -gt $MOUNT_GRN_THRES -a $DF_ORAARCH_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,91,"$DF_ORAARCH_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_ORAARCH_ALCTN""%" "$DF_ORAARCH_MNTPNT"'"'",""$DF_ORAARCH_ALCTN"",98,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_ORAARCH_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,91,"$DF_ORAARCH_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_ORAARCH_ALCTN""%" "$DF_ORAARCH_MNTPNT"'"'",""$DF_ORAARCH_ALCTN"",98,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#OLOGA

if [ $DF_OLOGA_COUNT -ge 1 ]
then

if [ $DF_OLOGA_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,100,"$DF_OLOGA_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_OLOGA_ALCTN""%" "$DF_OLOGA_MNTPNT"'"'",""$DF_OLOGA_ALCTN"",107,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_OLOGA_ALCTN -gt $MOUNT_GRN_THRES -a $DF_OLOGA_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,100,"$DF_OLOGA_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_OLOGA_ALCTN""%" "$DF_OLOGA_MNTPNT"'"'",""$DF_OLOGA_ALCTN"",107,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_OLOGA_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,100,"$DF_OLOGA_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_OLOGA_ALCTN""%" "$DF_OLOGA_MNTPNT"'"'",""$DF_OLOGA_ALCTN"",107,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#OLOGB

if [ $DF_OLOGB_COUNT -ge 1 ]
then


if [ $DF_OLOGB_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,109,"$DF_OLOGB_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_OLOGB_ALCTN""%" "$DF_OLOGB_MNTPNT"'"'",""$DF_OLOGB_ALCTN"",116,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_OLOGB_ALCTN -gt $MOUNT_GRN_THRES -a $DF_OLOGB_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,109,"$DF_OLOGB_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_OLOGB_ALCTN""%" "$DF_OLOGB_MNTPNT"'"'",""$DF_OLOGB_ALCTN"",116,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_OLOGB_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,109,"$DF_OLOGB_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_OLOGB_ALCTN""%" "$DF_OLOGB_MNTPNT"'"'",""$DF_OLOGB_ALCTN"",116,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#MLOGA

if [ $DF_MLOGA_COUNT -ge 1 ]
then

if [ $DF_MLOGA_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,118,"$DF_MLOGA_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_MLOGA_ALCTN""%" "$DF_MLOGA_MNTPNT"'"'",""$DF_MLOGA_ALCTN"",125,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_MLOGA_ALCTN -gt $MOUNT_GRN_THRES -a $DF_MLOGA_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,118,"$DF_MLOGA_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_MLOGA_ALCTN""%" "$DF_MLOGA_MNTPNT"'"'",""$DF_MLOGA_ALCTN"",125,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_MLOGA_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,118,"$DF_MLOGA_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_MLOGA_ALCTN""%" "$DF_MLOGA_MNTPNT"'"'",""$DF_MLOGA_ALCTN"",125,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#MLOGB

if [ $DF_MLOGB_COUNT -ge 1 ]
then

if [ $DF_MLOGB_ALCTN -le $MOUNT_GRN_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,127,"$DF_MLOGB_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_MLOGB_ALCTN""%" "$DF_MLOGB_MNTPNT"'"'",""$DF_MLOGB_ALCTN"",134,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_MLOGB_ALCTN -gt $MOUNT_GRN_THRES -a $DF_MLOGB_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,127,"$DF_MLOGB_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_MLOGB_ALCTN""%" "$DF_MLOGB_MNTPNT"'"'",""$DF_MLOGB_ALCTN"",134,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_MLOGB_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,127,"$DF_MLOGB_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_MLOGB_ALCTN""%" "$DF_MLOGB_MNTPNT"'"'",""$DF_MLOGB_ALCTN"",134,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#ARCHVPL

if [ $DF_ARCHVPL_COUNT -ge 1 ]
then

if [ $DF_ARCHVPL_ALCTN -le $MOUNT_GRN_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
echo "ctx.fillRect(1,136,"$DF_ARCHVPL_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_ARCHVPL_ALCTN""%" "$DF_ARCHVPL_MNTPNT"'"'",""$DF_ARCHVPL_ALCTN"",143,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_ARCHVPL_ALCTN -gt $MOUNT_GRN_THRES -a $DF_ARCHVPL_ALCTN -le $MOUNT_RED_THRES ]

then

echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
echo "ctx.fillRect(1,136,"$DF_ARCHVPL_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_ARCHVPL_ALCTN""%" "$DF_ARCHVPL_MNTPNT"'"'",""$DF_ARCHVPL_ALCTN"",143,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME


fi

if [ $DF_ARCHVPL_ALCTN -gt $MOUNT_RED_THRES ]

then


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
echo "ctx.fillRect(1,136,"$DF_ARCHVPL_ALCTN",8);" >> $REPORT_NAME
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
echo "ctx.fillText("'"'"  ""$DF_ARCHVPL_ALCTN""%" "$DF_ARCHVPL_MNTPNT"'"'",""$DF_ARCHVPL_ALCTN"",143,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME

fi

fi

#=================

#SAPDATA1

#if [ $DF_SAPDATA1_COUNT -ge 1 ]
#then
#if [ $DF_SAPDATA1_ALCTN -le $MOUNT_GRN_THRES ]

#then

#echo "<script>" >> $REPORT_NAME
#echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
#echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
#echo 'ctx.fillStyle = "#abebc6";' >> $REPORT_NAME
#echo "ctx.fillRect(1,145,"$DF_SAPDATA1_ALCTN",8);" >> $REPORT_NAME
#echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
#echo "ctx.fillText("'"'"  ""$DF_SAPDATA1_ALCTN""%" "$DF_SAPDATA1_MNTPNT"'"'",""$DF_SAPDATA1_ALCTN"",152,250,8);" >> $REPORT_NAME
#echo "</script>" >> $REPORT_NAME


#fi

#if [ $DF_SAPDATA1_ALCTN -gt $MOUNT_GRN_THRES -a $DF_SAPDATA1_ALCTN -le $MOUNT_RED_THRES ]

#then

#echo "<script>" >> $REPORT_NAME
#echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
#echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
#echo 'ctx.fillStyle = "#f9e79f";' >> $REPORT_NAME
#echo "ctx.fillRect(1,145,"$DF_SAPDATA1_ALCTN",8);" >> $REPORT_NAME
#echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
#echo "ctx.fillText("'"'"  ""$DF_SAPDATA1_ALCTN""%" "$DF_SAPDATA1_MNTPNT"'"'",""$DF_SAPDATA1_ALCTN"",152,250,8);" >> $REPORT_NAME
#echo "</script>" >> $REPORT_NAME


#fi

#if [ $DF_SAPDATA1_ALCTN -gt $MOUNT_RED_THRES ]

#then


#echo "<script>" >> $REPORT_NAME
#echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
#echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
#echo 'ctx.fillStyle = "#f5b7b1";' >> $REPORT_NAME
#echo "ctx.fillRect(1,145,"$DF_SAPDATA1_ALCTN",8);" >> $REPORT_NAME
#echo 'ctx.font = "10px Arial";' >> $REPORT_NAME
#echo "ctx.fillText("'"'"  ""$DF_SAPDATA1_ALCTN""%" "$DF_SAPDATA1_MNTPNT"'"'",""$DF_SAPDATA1_ALCTN"",152,250,8);" >> $REPORT_NAME
#echo "</script>" >> $REPORT_NAME

#fi

#fi


echo "<script>" >> $REPORT_NAME
echo 'var canvas = document.getElementById("myCanvas1");' >> $REPORT_NAME
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME
echo 'ctx.fillStyle = "#85c1e9";' >> $REPORT_NAME
echo 'ctx.font = "20px Arial";' >> $REPORT_NAME

echo "ctx.fillText('"'MOUNTPOINT'"',70,170,250,8);" >> $REPORT_NAME
echo "</script>" >> $REPORT_NAME



#====================================================================================================
#
# CANVAS SECTION FOR MEMORY UTILIZATION
#
#====================================================================================================


cat $REPORT_DIR/"RAM_"$SERVICE_NAME".html" >> $REPORT_NAME
cat $REPORT_DIR/"SWAP_"$SERVICE_NAME".html" >> $REPORT_NAME
cat $REPORT_DIR/"CPU_"$SERVICE_NAME".html" >> $REPORT_NAME






echo "</p>" >> $REPORT_NAME
echo "</body>" >> $REPORT_NAME
echo "</html>" >> $REPORT_NAME


#uuencode $REPORT_NAME $REPORT_NAME | mailx -s "<MONITORING> <"$SID"> <"$SAP_LOCALHOST"> <"$SERVICE_NAME"> <$(date)>" $MAIL_DIST_LIST

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
