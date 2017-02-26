#!/usr/bin/bash
# Sumit Das 2016 09 15
# Read DCPAIX list

#set -x

SERVTYPE=`more /etc/motd | grep Welcome | awk '{print $3}' | cut -c 1-3`
if [ $SERVTYPE = "dcp" ] ; then CLUSTER=`df -gt / | tail -n 1 | cut -c 48-55` ; 
else CLUSTER="APPCOM" ; fi
SERVER_NAME=`uname -n` ;
PHY_SERVER_NAME=`more /etc/motd | grep physical | awk '{print $NF}'` ;
ifconfig -a > IFCNF ; PHY_IP=`awk '/en2:/{x=NR+1;next}(NR<=x){print}' IFCNF | awk '{print $2}'` ; rm IFCNF
SERVER_SLICE=`more /etc/motd | grep slice | awk '{print $NF}'` ;
VLAN_ID=`more /etc/motd | grep VLAN | awk '{print $NF}'` ;
SAP_SYSTEMS=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9` `ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9` ;
ABAP_SYSTEMS=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2` ;
JAVA_SYSTEMS=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2` ;
ABAP_HOSTNAMES=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _` ;
JAVA_HOSTNAMES=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _` ;
DB_SYSTEMS=`ps -ef | grep tns | awk '{print $10}' | cut -f 2 -d _`

echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID >> /home/users/in10c2/sumit/VLANmap/DCPAIX.`uname -n`.VLANsheet.CSV



