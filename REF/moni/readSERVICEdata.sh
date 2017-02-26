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
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9 > /home/users/in10c2/moni/tmp_ABAP_SID
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2 > /home/users/in10c2/moni/tmp_ABAP_INSTANCE
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ > /home/users/in10c2/moni/tmp_ABAP_HOSTNAMES
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | rev | cut -c 1-2 | rev > /home/users/in10c2/moni/tmp_ABAP_SYS_NR
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 4-5 | awk '{print toupper($0)}' > /home/users/in10c2/moni/tmp_ABAP_TYPE

SID=( `cat "/home/users/in10c2/moni/tmp_ABAP_SID" ` ) ; #echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
ABAP_INSTANCE=( `cat "/home/users/in10c2/moni/tmp_ABAP_INSTANCE" ` ) ; #echo ${ABAP_INSTANCE[@]} ; echo ${#ABAP_INSTANCE[@]}
ABAP_HOSTNAMES=( `cat "/home/users/in10c2/moni/tmp_ABAP_HOSTNAMES" ` ) ; #echo ${ABAP_HOSTNAMES[@]} ; echo ${#ABAP_HOSTNAMES[@]}
ABAP_SYS_NR=( `cat "/home/users/in10c2/moni/tmp_ABAP_SYS_NR" ` ) ; #echo ${ABAP_SYS_NR[@]} ; echo ${#ABAP_SYS_NR[@]}
ABAP_TYPE=( `cat "/home/users/in10c2/moni/tmp_ABAP_TYPE" ` ) ; #echo ${ABAP_TYPE[@]} ; echo ${#ABAP_TYPE[@]}

rm -f /home/users/in10c2/moni/tmp_CUST_IP
for LINE in "${ABAP_HOSTNAMES[@]}"
do
        ping -c 1 $LINE | grep PING | awk '{print $3}' | rev | cut -c3- | rev | cut -c2- >> /home/users/in10c2/moni/tmp_CUST_IP
done
if [ -f /home/users/in10c2/moni/tmp_CUST_IP ]; then CUST_IP=( `cat "/home/users/in10c2/moni/tmp_CUST_IP" ` ) ; #echo ${CUST_IP[@]} ; echo ${#CUST_IP[@]} ;
#Next instructions to the end of MS Section follow this "then"

i=0
while [ $i -lt "${#SID[@]}" ]
do
        TYPE=`echo "${ABAP_TYPE[$i]}"` ; SYSSID=`echo "${SID[$i]}"` ; NR=`echo "${ABAP_SYS_NR[$i]}"` ;
        SERVICE_NAME=$TYPE"_"$SYSSID"_"$NR
        IP=`echo "${CUST_IP[$i]}"` ; INST=`echo "${ABAP_INSTANCE[$i]}"` ;
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST >> /home/users/in10c2/sumit/VLANmap/$SHEETname.CSV
        ((i++))
done

else #Instructions continued from MS CUST_IP check and ends at EOF
#set -x
ps -ef | grep se.sap | grep pf | awk '{ print $(NF-2) }' | cut -c 7-9 > /home/users/in10c2/moni/tmp_ABAP_SID_SE
ps -ef | grep se.sap | grep pf | awk '{ print $(NF-2) }' | cut -d _ -f 2 > /home/users/in10c2/moni/tmp_ABAP_INSTANCE_SE
ps -ef | grep se.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ > /home/users/in10c2/moni/tmp_ABAP_HOSTNAMES_SE
ps -ef | grep se.sap | grep pf | awk '{ print $(NF-2) }' | rev | cut -c 1-2 | rev > /home/users/in10c2/moni/tmp_ABAP_SYS_NR_SE
ps -ef | grep se.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 4-5 | awk '{print toupper($0)}' > /home/users/in10c2/moni/tmp_ABAP_TYPE_SE

SID_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_SID_SE" ` ) ; #echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
ABAP_INSTANCE_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_INSTANCE_SE" ` ) ; #echo ${ABAP_INSTANCE[@]} ; echo ${#ABAP_INSTANCE[@]}
ABAP_HOSTNAMES_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_HOSTNAMES_SE" ` ) ; #echo ${ABAP_HOSTNAMES[@]} ; echo ${#ABAP_HOSTNAMES[@]}
ABAP_SYS_NR_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_SYS_NR_SE" ` ) ; #echo ${ABAP_SYS_NR[@]} ; echo ${#ABAP_SYS_NR[@]}
ABAP_TYPE_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_TYPE_SE" ` ) ; #echo ${ABAP_TYPE[@]} ; echo ${#ABAP_TYPE[@]}

rm -f /home/users/in10c2/moni/tmp_CUST_IP_SE
for LINE in "${ABAP_HOSTNAMES_SE[@]}"
do
        ping -c 1 $LINE | grep PING | awk '{print $3}' | rev | cut -c3- | rev | cut -c2- >> /home/users/in10c2/moni/tmp_CUST_IP_SE
done
if [ -f /home/users/in10c2/moni/tmp_CUST_IP_SE ]; then CUST_IP_SE=( `cat "/home/users/in10c2/moni/tmp_CUST_IP_SE" ` ) ; #echo ${CUST_IP[@]} ; echo ${#CUST_IP[@]} ;
#Next instructions to the end of SE Section follow this "then"
CUST_IP_SE=( `cat "/home/users/in10c2/moni/tmp_CUST_IP_SE" ` ) ; #echo ${CUST_IP[@]} ; echo ${#CUST_IP[@]}

i=0
while [ $i -lt "${#SID_SE[@]}" ]
do
        if [ "${ABAP_INSTANCE_SE[$i]}" != "${ABAP_INSTANCE[$i]}" ]
        then
        TYPE=`echo "${ABAP_TYPE_SE[$i]}"` ; SYSSID=`echo "${SID_SE[$i]}"` ; NR=`echo "${ABAP_SYS_NR_SE[$i]}"` ;
        SERVICE_NAME=$TYPE"_"$SYSSID"_"$NR
        IP=`echo "${CUST_IP_SE[$i]}"` ; INST=`echo "${ABAP_INSTANCE_SE[$i]}"` ;
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST >> /home/users/in10c2/sumit/VLANmap/$SHEETname.CSV
        ((i++))
        fi
done

else #Instructions continued from SE CUST_IP check and ends at EOF
#set -x
ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF-1) }' | cut -c 7-9 > /home/users/in10c2/moni/tmp_JAVA_SID
ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF-1) }' | cut -d _ -f 2 > /home/users/in10c2/moni/tmp_JAVA_INSTANCE
ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF) }' | cut -f 3 -d _ > /home/users/in10c2/moni/tmp_JAVA_HOSTNAMES
ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF-1) }' | rev | cut -c 1-2 | rev > /home/users/in10c2/moni/tmp_JAVA_SYS_NR
ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 4-5 | awk '{print toupper($0)}' > /home/users/in10c2/moni/tmp_JAVA_TYPE

SID_JC=( `cat "/home/users/in10c2/moni/tmp_JAVA_SID" ` ) ; #echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
JAVA_INSTANCE=( `cat "/home/users/in10c2/moni/tmp_JAVA_INSTANCE" ` ) ; #echo ${ABAP_INSTANCE[@]} ; echo ${#ABAP_INSTANCE[@]}
JAVA_HOSTNAMES=( `cat "/home/users/in10c2/moni/tmp_JAVA_HOSTNAMES" ` ) ; #echo ${ABAP_HOSTNAMES[@]} ; echo ${#ABAP_HOSTNAMES[@]}
JAVA_SYS_NR=( `cat "/home/users/in10c2/moni/tmp_JAVA_SYS_NR" ` ) ; #echo ${ABAP_SYS_NR[@]} ; echo ${#ABAP_SYS_NR[@]}
JAVA_TYPE=( `cat "/home/users/in10c2/moni/tmp_JAVA_TYPE" ` ) ; #echo ${ABAP_TYPE[@]} ; echo ${#ABAP_TYPE[@]}

rm -f /home/users/in10c2/moni/tmp_CUST_IP_JC
for LINE in "${JAVA_HOSTNAMES[@]}"
do
        ping -c 1 $LINE | grep PING | awk '{print $3}' | rev | cut -c3- | rev | cut -c2- >> /home/users/in10c2/moni/tmp_CUST_IP_JC
done
if [ -f /home/users/in10c2/moni/tmp_CUST_IP_JC ]; then CUST_IP_JC=( `cat "/home/users/in10c2/moni/tmp_CUST_IP_JC" ` ) ; #echo ${CUST_IP[@]} ; echo ${#CUST_IP[@]} ;
#Next instructions to the end of JC Section follow this "then"
CUST_IP_JC=( `cat "/home/users/in10c2/moni/tmp_CUST_IP_JC" ` ) ; #echo ${CUST_IP[@]} ; echo ${#CUST_IP[@]}

i=0
while [ $i -lt "${#SID_JC[@]}" ]
do
        TYPE=`echo "${JAVA_TYPE[$i]}"` ; SYSSID=`echo "${SID_JC[$i]}"` ; NR=`echo "${JAVA_SYS_NR[$i]}"` ;
        SERVICE_NAME=$TYPE"_"$SYSSID"_"$NR
        IP=`echo "${/home/users/in10c2/moni/tmp_CUST_IP_JC[$i]}"` ; INST=`echo "${JAVA_INSTANCE[$i]}"` ;
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST >> /home/users/in10c2/sumit/VLANmap/$SHEETname.CSV
        ((i++))
done

fi #From SE JC Cust IP
fi #From SE AP Cust IP 
fi #From MS CI Cust IP


