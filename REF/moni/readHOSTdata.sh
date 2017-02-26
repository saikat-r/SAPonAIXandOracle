#!/usr/bin/bash
# Sumit Das 2016 10 09
# Last Modified 2017 01 22
# Read DCPAIX list

#set -x
#echo "Number of Arguments is " $#
#if [ $# -eq 2 ] ; then datestamp=$1 ; debugmode=$2 ; echo "$debugmode mode ON" ; fi
#if [ $# -eq 1 ] ; then datestamp=$1 ; debugmode="nodebug" ; fi
#if [ $# -eq 0 ] ; then datestamp=$(date "+%Y.%m.%d-%H.%M.%S") ; debugmode="nodebug" ; fi
#set +x
datestamp=$(date "+%Y.%m.%d-%H.%M.%S")
debugmode="nodebug"

SERVTYPE=`more /etc/motd | grep Welcome | awk '{print $3}' | cut -c 1-3`
if [ $SERVTYPE = "dcp" ] ; then CLUSTER=`df -gt / | tail -n 1 | cut -c 48-55` ;
else CLUSTER="APPCOM" ; fi
SERVER_NAME=`uname -n` ;

PHY_SERVER_NAME=`more /etc/motd | grep physical | awk '{print $NF}'` ;
ifconfig -a > IFCNF ; PHY_IP=`awk '/en2:/{x=NR+1;next}(NR<=x){print}' IFCNF | awk '{print $2}'` ; rm IFCNF

SERVER_SLICE=`more /etc/motd | grep slice | awk '{print $NF}'` ;
VLAN_ID=`more /etc/motd | grep VLAN | awk '{print $NF}'` ;

#set -x
ABAP_SID=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9` ;
if [ ! -z "$ABAP_SID" ]
then
        if [ $debugmode = "debug" ]; then echo "Found ms.sap in SID" ; fi
        ABAP_SID_SE=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF-2) }' | cut -c 7-9` ;
        ABAP_SID_IG=`ps -ef | grep ig.sap | grep pf | awk '{ print $(NF-2) }' | cut -c 7-9` ;
else
        ABAP_SID=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF-2) }' | cut -c 7-9` ;
        if [ $debugmode = "debug" ]; then echo "Not Found ms.sap in SID" ; fi
        if [ ! -z "$ABAP_SID" ]
        then
                if [ $debugmode = "debug" ]; then echo "Found se.sap in SID" ; fi
        else
                if [ $debugmode = "debug" ]; then echo "Not Found se.sap in SID" ; fi
                ABAP_SID=`ps -ef | grep ig.sap | grep pf | awk '{ print $(NF-2) }' | cut -c 7-9` ;
                if [ ! -z "$ABAP_SID" ]
                then
                        if [ $debugmode = "debug" ]; then echo "Found ig.sap in SID" ; fi
                else
                        if [ $debugmode = "debug" ]; then echo "Not Found ms.sap and se.sap or ig.sap in SID" ; fi
                fi
        fi
fi
echo $ABAP_SID > tmp_ABAP_SID
echo $ABAP_SID_SE > tmp_ABAP_SID_SE
echo $ABAP_SID_IG > tmp_ABAP_SID_IG

ABAP_INSTANCE=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2` ;
if [ ! -z "$ABAP_INSTANCE" ]
then
        if [ $debugmode = "debug" ]; then echo "Found ms.sap in INST" ; fi
else
        ABAP_INSTANCE=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF-2) }' | cut -d _ -f 2` ;
        if [ $debugmode = "debug" ]; then echo "Not Found ms.sap in INST" ; fi
        if [ ! -z "$ABAP_INSTANCE" ]
        then
                if [ $debugmode = "debug" ]; then echo "Found se.sap in INST" ; fi
        else
                if [ $debugmode = "debug" ]; then echo "Not Found se.sap in INST" ; fi
                ABAP_INSTANCE=`ps -ef | grep ig.sap | grep pf | awk '{ print $(NF-2) }' | cut -d _ -f 2` ;
                if [ ! -z "$ABAP_INSTANCE" ]
                then
                        if [ $debugmode = "debug" ]; then echo "Found ig.sap in INST"  ; fi
                else
                        if [ $debugmode = "debug" ]; then echo "Not Found ms.sap and se.sap or ig.sap in INST" ; fi
                fi
        fi
fi
echo $ABAP_INSTANCE > tmp_ABAP_INSTANCE

ABAP_HOSTNAMES=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _` ;
if [ ! -z "$ABAP_HOSTNAMES" ]
then
        if [ $debugmode = "debug" ]; then echo "Found ms.sap in HOST" ; fi
else
        ABAP_HOSTNAMES=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _` ;
        if [ $debugmode = "debug" ]; then echo "Not Found ms.sap in HOST" ; fi
        if [ ! -z "$ABAP_HOSTNAMES" ]
        then
                if [ $debugmode = "debug" ]; then echo "Found se.sap in HOST" ; fi
        else
                if [ $debugmode = "debug" ]; then echo "Not Found se.sap in HOST" ; fi
                ABAP_HOSTNAMES=`ps -ef | grep ig.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _` ;
                if [ ! -z "$ABAP_HOSTNAMES" ]
                then
                        if [ $debugmode = "debug" ]; then echo "Found ig.sap in HOST" ; fi
                else
                        if [ $debugmode = "debug" ]; then echo "Not Found ms.sap and se.sap or ig.sap in HOST" ; fi
                fi
        fi
fi
echo $ABAP_HOSTNAMES > tmp_ABAP_HOSTNAMES

ABAP_SYS_NR=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | rev | cut -c 1-2 | rev` ;
if [ ! -z "$ABAP_SYS_NR" ]
then
        if [ $debugmode = "debug" ]; then echo "Found ms.sap in SYS_NR" ; fi
else
        ABAP_SYS_NR=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF-2) }' | rev | cut -c 1-2 | rev` ;
        if [ $debugmode = "debug" ]; then echo "Not Found ms.sap in SYS_NR" ; fi
        if [ ! -z "$ABAP_SYS_NR" ]
        then
                if [ $debugmode = "debug" ]; then echo "Found se.sap in SYS_NR" ; fi
        else
                if [ $debugmode = "debug" ]; then echo "Not Found se.sap in SYS_NR" ; fi
                ABAP_SYS_NR=`ps -ef | grep ig.sap | grep pf | awk '{ print $(NF-2) }' | rev | cut -c 1-2 | rev` ;
                if [ ! -z "$ABAP_SYS_NR" ]
                then
                        if [ $debugmode = "debug" ]; then echo "Found ig.sap in SYS_NR" ; fi
                else
                        if [ $debugmode = "debug" ]; then echo "Not Found ms.sap and se.sap or ig.sap in SYS_NR" ; fi
                fi
        fi
fi
echo $ABAP_SYS_NR > tmp_ABAP_SYS_NR

if [ $SERVTYPE = "dcp" ]
# SET ABAP SYSTEM TYPE CI AP for DCP
then
ABAP_TYPE=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 4-5` ;
if [ ! -z "$ABAP_TYPE" ]
then
        if [ $debugmode = "debug" ]; then echo "Found ms.sap in SYS_NR" ; fi
        ABAP_TYPE=`echo "$ABAP_TYPE" | awk '{print toupper($0)}'` ;
else
        ABAP_TYPE=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 4-5` ;
        if [ $debugmode = "debug" ]; then echo "Not Found ms.sap in SYS_NR" ; fi
        if [ ! -z "$ABAP_TYPE" ]
        then
                if [ $debugmode = "debug" ]; then echo "Found se.sap in SYS_NR" ; fi
                ABAP_TYPE=`echo "$ABAP_TYPE" | awk '{print toupper($0)}'` ;
        else
                if [ $debugmode = "debug" ]; then echo "Not Found se.sap in SYS_NR" ; fi
                ABAP_TYPE=`ps -ef | grep ig.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 4-5` ;
                if [ ! -z "$ABAP_TYPE" ]
                then
                        if [ $debugmode = "debug" ]; then echo "Found ig.sap in SYS_NR" ; fi
                        ABAP_TYPE=`echo "$ABAP_TYPE" | awk '{print toupper($0)}'` ;
                else
                        if [ $debugmode = "debug" ]; then echo "Not Found ms.sap and se.sap or ig.sap in SYS_NR" ; fi
                fi
        fi
fi
else
# SET ABAP SYSTEM TYPE CI AP for AppCom
ABAP_TYPE=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 1-2` ;
if [ ! -z "$ABAP_TYPE" ]
then
        if [ $debugmode = "debug" ]; then echo "Found ms.sap in SYS_NR" ; fi
        ABAP_TYPE=`echo "$ABAP_TYPE" | awk '{print toupper($0)}'` ;
else
        ABAP_TYPE=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 1-2` ;
        if [ $debugmode = "debug" ]; then echo "Not Found ms.sap in SYS_NR" ; fi
        if [ ! -z "$ABAP_TYPE" ]
        then
                if [ $debugmode = "debug" ]; then echo "Found se.sap in SYS_NR" ; fi
                ABAP_TYPE=`echo "$ABAP_TYPE" | awk '{print toupper($0)}'` ;
        else
                if [ $debugmode = "debug" ]; then echo "Not Found se.sap in SYS_NR" ; fi
                ABAP_TYPE=`ps -ef | grep ig.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 1-2` ;
                if [ ! -z "$ABAP_TYPE" ]
                then
                        if [ $debugmode = "debug" ]; then echo "Found ig.sap in SYS_NR" ; fi
                        ABAP_TYPE=`echo "$ABAP_TYPE" | awk '{print toupper($0)}'` ;
                else
                        if [ $debugmode = "debug" ]; then echo "Not Found ms.sap and se.sap or ig.sap in SYS_NR" ; fi
                fi
        fi
fi
fi
echo $ABAP_TYPE > tmp_ABAP_TYPE

#set +x
JAVA_SID=`ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF-1) }' | cut -c 7-9` ;
echo $JAVA_SID > tmp_JAVA_SID
JAVA_INSTANCE=`ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF-1) }' | cut -d _ -f 2` ;
echo $JAVA_INSTANCE > tmp_JAVA_INSTANCE
JAVA_HOSTNAMES=`ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF) }' | cut -f 3 -d _` ;
echo $JAVA_HOSTNAMES > tmp_JAVA_HOSTNAMES
JAVA_SYS_NR=`ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF-1) }' | rev | cut -c 1-2 | rev` ;
echo $JAVA_SYS_NR > tmp_JAVA_SYS_NR
if [ $SERVTYPE = "dcp" ]
        then
        if [ $debugmode = "debug" ] ; then set -x ; fi
        JAVA_TYPE=`ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 4-5` ;
        JAVA_TYPE=`echo "$JAVA_TYPE" | awk '{print toupper($0)}'` ;
        if [ $debugmode = "debug" ] ; then set +x ; fi
else
        if [ $debugmode = "debug" ] ; then set -x ; fi
        JAVA_TYPE=`ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 1-2` ;
        JAVA_TYPE=`echo "$JAVA_TYPE" | awk '{print toupper($0)}'` ;
        if [ $debugmode = "debug" ] ; then set +x ; fi
fi
echo $JAVA_TYPE > tmp_JAVA_TYPE

SMD_SID=`ps -ef | grep jc.sap | grep SMD | awk '{ print $(NF-1) }' | cut -c 7-9` ;
SMD_INSTANCE=`ps -ef | grep jc.sap | grep SMD | awk '{ print $(NF-1) }' | cut -d _ -f 2` ;
SMD_HOSTNAMES=`ps -ef | grep jc.sap | grep SMD | awk '{ print $(NF) }' | cut -f 3 -d _` ;
echo $JAVA_SYS_NR > tmp_JAVA_SYS_NR
if [ $SERVTYPE = "dcp" ]
        then
        if [ $debugmode = "debug" ] ; then set -x ; fi
        SMD_TYPE=`ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 4-5` ;
        SMD_TYPE=`echo "$SMD_TYPE" | awk '{print toupper($0)}'` ;
        if [ $debugmode = "debug" ] ; then set +x ; fi
else
        if [ $debugmode = "debug" ] ; then set -x ; fi
        SMD_TYPE=`ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 1-2` ;
        SMD_TYPE=`echo "$SMD_TYPE" | awk '{print toupper($0)}'` ;
        if [ $debugmode = "debug" ] ; then set +x ; fi
fi
echo $SMD_TYPE > tmp_SMD_TYPE


while read LINE
do
        if [ -f tmp_ABAP_SID ] ; then
                read SID[$i]   $LINE ; #echo $LINE ;
                ((i++)) ;
        fi
done < tmp_ABAP_SID

while read LINE
do
        if [ -f tmp_ABAP_SID_SE ] ; then
                read SID[$i]   $LINE ; #echo $LINE ;
                ((i++)) ;
        fi
done < tmp_ABAP_SID_SE

while read LINE
do
        if [ -f tmp_ABAP_SID_IG ] ; then
                read SID[$i]   $LINE ; #echo $LINE ;
                ((i++)) ;
        fi
done < tmp_ABAP_SID_IG

while read LINE
do
        if [ -f tmp_JAVA_SID ] ; then
                read SID[$i]   $LINE ; #echo $LINE ;
                ((i++)) ;
        fi
done < tmp_JAVA_SID
SID_NUM=$i
echo ${SID[*]}

i=1
while read LINE
do
        if [ -f tmp_ABAP_INSTANCE ] ; then
                read INSTANCE[$i]   $LINE ; #echo $LINE ;
                ((i++)) ;
        fi
done < tmp_ABAP_INSTANCE

while read LINE
do
        if [ -f tmp_JAVA_INSTANCE ] ; then
                read INSTANCE[$i]   $LINE ; #echo $LINE ;
                ((i++)) ;
        fi
done < tmp_JAVA_INSTANCE
INSTANCE_NUM=$i
echo ${INSTANCE[*]}

i=1
while read LINE
do
        if [ -f tmp_ABAP_HOSTNAMES ] ; then
                read HOSTNAMES[$i]   $LINE ; #echo $LINE ;
                ((i++)) ;
        fi
done < tmp_ABAP_HOSTNAMES

while read LINE
do
        if [ -f tmp_JAVA_HOSTNAMES ] ; then
                read HOSTNAMES[$i]   $LINE ; #echo $LINE ;
                ((i++)) ;
        fi
done < tmp_JAVA_HOSTNAMES
HOSTNAMES_NUM=$i
echo ${HOSTNAMES[*]}

i=1
while read LINE
do
        if [ -f tmp_ABAP_TYPE ] ; then
                read TYPE[$i]   $LINE ; #echo $LINE ;
                ((i++)) ;
        fi
done < tmp_ABAP_TYPE

while read LINE
do
        if [ -f tmp_JAVA_TYPE ] ; then
                read TYPE[$i]   $LINE ; #echo $LINE ;
                ((i++)) ;
        fi
done < tmp_JAVA_TYPE
TYPE_NUM=$i
echo ${TYPE[*]}

i=1
while read LINE
do
        if [ -f tmp_ABAP_SYS_NR ] ; then
                #read SYS_NR[$i]   $LINE ; #echo $LINE ;
                typeset -i SYS_NR[$i]=$LINE ; #echo $LINE
                ((i++)) ;
        fi
done < tmp_ABAP_SYS_NR

while read LINE
do
        if [ -f tmp_JAVA_SYS_NR ] ; then
                #read SYS_NR[$i]   $LINE ; #echo $LINE ;
                typeset -i SYS_NR[$i]=$LINE ; #echo $LINE
                ((i++)) ;
        fi
done < tmp_JAVA_SYS_NR
SYS_NR_NUM=$i
echo ${SYS_NR[*]}


PROFILE_FILE_MS=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -d = -f 2` ;
PROFILE_PATH_MS=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }'  | cut -c 4-28` ;

PROFILE_FILE_SE=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF) }' | cut -d = -f 2` ;
PROFILE_PATH_SE=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF) }'  | cut -c 4-28` ;

PROFILE_FILE_IG=`ps -ef | grep ig.sap | grep pf | awk '{ print $(NF) }' | cut -d = -f 2` ;
PROFILE_PATH_IG=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }'  | cut -c 4-28` ;

PROFILE_FILE_JC=`ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF) }' | cut -d = -f 2` ;
PROFILE_PATH_JC=`ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF) }'  | cut -c 4-28` ;

DB_SYSTEMS=`ps -ef | grep tns  | grep -v grep | awk '{print $(NF-1)}' | cut -f 2 -d _` ;
if [ ! -z $DB_SYSTEMS ]
        then
        DEFAULT_PFL_NAME="DEFAULT.PFL"
        DEFAULT_PFL="$PROFILE_PATH_MS$DEFAULT_PFL_NAME"
        DB_HOSTNAME=`grep SAPDBHOST $DEFAULT_PFL | cut -d = -f 2`
fi



echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$ABAP_SID,$ABAP_SID_SE,$JAVA_SID,$ABAP_INSTANCE,$JAVA_INSTANCE,$ABAP_HOSTNAMES,$JAVA_HOSTNAMES,$ABAP_TYPE,$JAVA_TYPE,$SMD_SID,$SMD_INSTANCE,$DB_SYSTEMS

echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$ABAP_SID,$ABAP_SID_SE,$JAVA_SID,$ABAP_INSTANCE,$JAVA_INSTANCE,$ABAP_HOSTNAMES,$JAVA_HOSTNAMES,$ABAP_TYPE,$JAVA_TYPE,$SMD_SID,$SMD_INSTANCE,$DB_SYSTEMS >> /home/users/in10c2/sumit/VLANmap/DCPAIX.`uname -n`.$datestamp.VLANsheet.CSV

