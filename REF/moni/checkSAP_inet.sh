#!/bin/ksh
################################################################################
#
# /usr/bin/checksap.sh
# UNIX Shell Script for Checking
# 1. Whether SAP Has Started or not
# is found by checking whether kill.sap file exists or not
# and if it exists, whether the PID recorded in the file is live or not
# 2. Whether DB has started or notA
# is found using the Command R3trans -d
# 3. Whether SAP is able to detect the Message Server or not
# (important for Applicateion Server Test
# Creation Dated : 23/11/2006
# Authored by : Biju Kumar
#
################################################################################
__time=`date` ;
__date=`echo $__time | awk '{ printf "%s",$3$2$6"/"$4 ; }' ;`;
__variable='';
__variable1='';
SAPSYSTEMNAME=$1 #### 'D20';

LOCAL_FILE_NAME=`echo /usr/sap/${SAPSYSTEMNAME}/D*/work/kill.sap`;
my_SID_USERNAME=`echo ${SAPSYSTEMNAME}adm | tr '[A-Z]' '[a-z]'`
APPLICATION_SERVER="true" # Notes whether the SAP System has Application Servers or not ?

MY_PROC_LIST="";
MY_SAP_RUNNING='';
if [ -f $LOCAL_FILE_NAME ];
then
MY_PROC_LIST=`cat $LOCAL_FILE_NAME | awk '{printf $3}'`;
MY_SAP_RUNNING=`ps -p $MY_PROC_LIST | grep 'sapstart' | awk '{printf $4}'`;
fi;

MY_DBSERVER='true';

MY_DB_STR="";
if [ $MY_DBSERVER == "true" ] ;
then
MY_DB_STR=`su - $my_SID_USERNAME -c "R3trans -d" | grep "R3trans finished"| awk '{printf $3}'`;
fi;

__variable1='';
if [ $MY_DB_STR == "(0000)." ];
then
__variable1="$__time DB Inst Running";
else
__variable1="$__time DB Inst Not Running";
fi;
__variable=$__variable" "$__variable1;


MY_ARGUMENT=`ps -ef | grep dw.sap | awk '{if (NR==1) printf $9}'`

if [ $APPLICATION_SERVER == "true" ];
then

my_var=`su - $my_SID_USERNAME -c "lgtst $MY_ARGUMENT" | grep "list of reachable "`;

if [ -z $my_var ];
then
__variable=$__variable", CI Not Running ";
else
__variable=$__variable", CI is Running ";
fi;
fi;

__variable1="";

if [ -f $LOCAL_FILE_NAME ]; #### -a [ $MY_SAP_RUNNING == "sapstart" ];
then
if [ $MY_SAP_RUNNING == "sapstart" ];
then
my_start_time=`ls -lt $LOCAL_FILE_NAME | awk '{ printf "%s",$7"-"$6"-2006 "$8 ; }' ;`;
__variable1="SAP Inst has started at $my_start_time /$__date";
fi;
else
__variable1="SAP Inst has not started /$__date";
fi;

__variable=$__variable", "$__variable1;
echo $__variable ;
##### It can be added to crontab, and scheduled to run maybe every 5 minutes. #####