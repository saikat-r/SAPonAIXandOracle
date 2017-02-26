#!/usr/bin/bash
# Sumit Das 2016 06 03
# Record SAP status to Dashboard

set -x
#Define Variables
APP=$1
SID=$2
SNO=$3
debugmode=$4
if [[ -z $debugmode ]]; then debugmode="nodebug" ; echo $debugmode ; fi
if [ $debugmode = "debug" ]; then echo "$( basename $0 )" ; fi
if [ $debugmode = "debug" ]; then set -x ; fi

datestamp=$(date "+%Y.%m.%d-%H.%M.%S")
datesh=$(date "+%Y.%m.%d")

WorkDir=/home/users/in10c2/moni
LogDir=/home/users/in10c2/moni/monitoringLOGS
cd $WorkDir
mkdir -p monitoringLOGS/$datesh

DNSHOST=$APP$SID$SNO
DNSHOST=`echo $DNSHOST | awk '{print tolower($0)}'`
DBc=c
if [ $APP = "DB" ] || [ $APP = "JD" ] ; then DNSHOST=$DNSHOST$DBc ; fi

#DATA Collection
SERVER_NAME=`ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $DNSHOST uname -n`
if [ -n "$SERVER_NAME" ] ; then SERVER_STATUS="OK." ; else SERVER_STATUS="NOT OK." ; fi

if [ $APP = "CI" ]
then

SAP_INSTANCE=`ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $DNSHOST ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2`
if [ -n "$SAP_INSTANCE" ] ; then SAP_INSTANCE_STATUS="OK." ; else SAP_INSTANCE_STATUS="NOT OK." ; fi

elif [ $APP = "DB" ] || [ $APP = "JD" ]
then
SAP_INSTANCE=`ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $DNSHOST ps -ef | grep pmon | grep -v grep | cut -d _ -f 3`
if [ -n "$SAP_INSTANCE" ] ; then SAP_INSTANCE_STATUS="DB OK." ; else SAP_INSTANCE_STATUS="DB NOT OK." ; fi

elif [ $APP = "AP" ]
then
SAP_INSTANCE=`ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $DNSHOST ps -ef | grep se.sap | grep pf | awk '{ print $(NF-2) }' | cut -d _ -f 2`
if [ -n "$SAP_INSTANCE" ] ; then SAP_INSTANCE_STATUS="OK." ;
else
SAP_INSTANCE=`ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $DNSHOST ps -ef | grep ig.sap | grep pf | awk '{ print $(NF-2) }' | cut -d _ -f 2`
if [ -n "$SAP_INSTANCE" ] ; then SAP_INSTANCE_STATUS="OK." ; else SAP_INSTANCE_STATUS="NOT OK." ; fi
fi

elif [ $APP = "JI" ]
then
SAP_INSTANCE=`ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $DNSHOST ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | grep -v SMDA | cut -d _ -f 2`
if [ -n "$SAP_INSTANCE" ] ; then SAP_INSTANCE_STATUS="OK." ; else SAP_INSTANCE_STATUS="NOT OK." ; fi

else
echo "Please define a application type "
fi

ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $DNSHOST vmstat -Iwt 1 1 | tail -1 > tempCPU
USER_CPU=`more tempCPU | awk '{print $15}'`
SYSTEM_CPU=`more tempCPU | awk '{print $16}'`
IDEAL_CPU=`more tempCPU | awk '{print $17}'`

#USER_CPU=`ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $DNSHOST vmstat -Iwt 1 1 | tail -1 | awk '{print $15}'`
#SYSTEM_CPU=`ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $DNSHOST vmstat -Iwt 1 1 | tail -1 | awk '{print $16}'`
#IDEAL_CPU=`ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $DNSHOST vmstat -Iwt 1 1 | tail -1 | awk '{print $17}'`

ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $DNSHOST svmon -G | head -2 | tail -1 > tempMEM
TOTAL_MEM=`more tempMEM  | awk '{print $2}'`
USED_MEM=`more tempMEM  | awk '{print $3}'`
FREE_MEM=`more tempMEM  | awk '{print $4}'`

#TOTAL_MEM=`ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $DNSHOST svmon -G | head -2 | tail -1 | awk '{print $2}'`
#USED_MEM=`ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $DNSHOST svmon -G | head -2 | tail -1 | awk '{print $3}'`
#FREE_MEM=`ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $DNSHOST svmon -G | head -2 | tail -1 | awk '{print $4}'`

USED_MEM=`expr $USED_MEM '*' 100 `
FREE_MEM=`expr $FREE_MEM '*' 100 `

USED_MEM_PCT=`expr $USED_MEM / $TOTAL_MEM `
FREE_MEM_PCT=`expr $FREE_MEM / $TOTAL_MEM `

NORM_BG="white"

if [ $SAP_INSTANCE_STATUS = "OK." ] || [ $SAP_INSTANCE_STATUS = "DB OK." ] ; then TEXT_BG="lime" ; else TEXT_BG="red" ; fi
if [ $SERVER_STATUS = "OK." ] ; then TEXT_BG="lime" ; else TEXT_BG="red" ; fi

if [ $USER_CPU -le 60 ] ; then UC_NUM_BG="lime" ; elif [ $USER_CPU -ge 61 ] && [ $USER_CPU -le 75 ] ; then UC_NUM_BG="yellow" ; else UC_NUM_BG="red" ; fi
if [ $SYSTEM_CPU -le 60 ] ; then SC_NUM_BG="lime" ; elif [ $SYSTEM_CPU -ge 60 ] && [ $SYSTEM_CPU -le 75 ] ; then SC_NUM_BG="yellow" ; else SC_NUM_BG="red" ; fi
if [ $IDEAL_CPU -le 25 ]  ; then IC_NUM_BG="red" ; elif [ $IDEAL_CPU -ge 26 ] && $IDEAL_CPU -le 75 ] ; then IC_NUM_BG="yellow" ; else IC_NUM_BG="lime" ; fi
if [ $USED_MEM_PCT -le 60 ] ; then UM_NUM_BG="lime" ; elif [ $USED_MEM_PCT -ge 60 ] && [ $USED_MEM_PCT -le 75 ] ; then UM_NUM_BG="yellow" ; else UM_NUM_BG="red" ; fi
if [ $FREE_MEM_PCT -le 25 ] ; then FM_NUM_BG="red" ; elif [ $FREE_MEM_PCT -ge 26 ] && [ $FREE_MEM_PCT -le 75 ] ; then FM_NUM_BG="yellow" ; else FM_NUM_BG="lime" ; fi

# Write to HTML files
echo "<tr><td bgcolor=$NORM_BG>$SID</td><td bgcolor=$NORM_BG>$SERVER_NAME</td><td bgcolor=$TEXT_BG>$SERVER_STATUS</td><td bgcolor=$NORM_BG>$SAP_INSTANCE</td><td bgcolor=$TEXT_BG>$SAP_INSTANCE_STATUS</td><td bgcolor=$UC_NUM_BG>$USER_CPU</td><td bgcolor=$SC_NUM_BG>$SYSTEM_CPU</td><td bgcolor=$IC_NUM_BG>$IDEAL_CPU</td><td bgcolor=$UM_NUM_BG>$USED_MEM_PCT</td><td bgcolor=$FM_NUM_BG>$FREE_MEM_PCT</td><td>In Development</td></tr>" >> tbl_im_Dashboard_Prod_LIVE.html



