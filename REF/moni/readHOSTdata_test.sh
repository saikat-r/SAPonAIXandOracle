#!/usr/bin/bash
# Sumit Das 2016 10 09
# Last Modified 2017 01 22
# Read DCPAIX list

#echo "Number of Arguments is " $#
#if [ $# -eq 2 ] ; then datestamp=$1 ; debugmode=$2 ; echo "$debugmode mode ON" ; fi
#if [ $# -eq 1 ] ; then datestamp=$1 ; debugmode="nodebug" ; fi
#if [ $# -eq 0 ] ; then datestamp=$(date "+%Y.%m.%d-%H.%M.%S") ; debugmode="nodebug" ; fi

datestamp=$(date "+%Y.%m.%d-%H.%M.%S")
debugmode="nodebug"
SHEETname="DCPAIX.`uname -n`.$datestamp.VLANsheet"

SERVTYPE=`more /etc/motd | grep Welcome | awk '{print $3}' | cut -c 1-3`
if [ $SERVTYPE = "dcp" ] ; then CLUSTER=`df -gt / | tail -n 1 | cut -c 48-55` ;
else CLUSTER="APPCOM" ; fi
SERVER_NAME=`uname -n` ;

PHY_SERVER_NAME=`more /etc/motd | grep physical | awk '{print $NF}'` ;
ifconfig -a > IFCNF ; PHY_IP=`awk '/en2:/{x=NR+1;next}(NR<=x){print}' IFCNF | awk '{print $2}'` ; rm IFCNF

SERVER_SLICE=`more /etc/motd | grep slice | awk '{print $NF}'` ;
VLAN_ID=`more /etc/motd | grep VLAN | awk '{print $NF}'` ;

#set -x
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9 > tmp_ABAP_SID
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2 > tmp_ABAP_INSTANCE
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ > tmp_ABAP_HOSTNAMES
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | rev | cut -c 1-2 | rev > tmp_ABAP_SYS_NR
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 4-5 | awk '{print toupper($0)}' > tmp_ABAP_TYPE

SID=( `cat "tmp_ABAP_SID" `) ; #echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
ABAP_HOSTNAMES=( `cat "tmp_ABAP_HOSTNAMES" `) ; #echo ${ABAP_HOSTNAMES[@]} ; echo ${#ABAP_HOSTNAMES[@]}
ABAP_SYS_NR=( `cat "tmp_ABAP_SYS_NR" `) ; #echo ${ABAP_SYS_NR[@]} ; echo ${#ABAP_SYS_NR[@]}
ABAP_INSTANCE=( `cat "tmp_ABAP_INSTANCE" `) ; #echo ${ABAP_INSTANCE[@]} ; echo ${#ABAP_INSTANCE[@]}
ABAP_TYPE=( `cat "tmp_ABAP_TYPE" `) ; #echo ${ABAP_TYPE[@]} ; echo ${#ABAP_TYPE[@]}

rm -f tmp_CUST_IP
for LINE in "${ABAP_HOSTNAMES[@]}"
do
	ping -c 1 $LINE | grep PING | awk '{print $3}' | rev | cut -c3- | rev | cut -c2- >> tmp_CUST_IP
done
CUST_IP=( `cat "tmp_CUST_IP" `) ; #echo ${CUST_IP[@]} ; echo ${#CUST_IP[@]}

i=o
while [ $i -lt "${#SID[@]}" ]
do
	TYPE=`echo "${ABAP_TYPE[$i]}"` ; SYSSID=`echo "${SID[$i]}"` ; NR=`echo "${ABAP_SYS_NR[$i]}"` ;
	SERVICE_NAME=$TYPE"_"$SYSSID"_"$NR
	IP=`echo "${CUST_IP[$i]}"` ; INST=`echo "${ABAP_INSTANCE[$i]}"` ;
	echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST
	echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST >> /home/users/in10c2/sumit/VLANmap/$SHEETname.CSV
	((i++))
done

