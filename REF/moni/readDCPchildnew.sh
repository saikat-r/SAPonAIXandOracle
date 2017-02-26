#!/usr/bin/bash
# Sumit Das 2016 10 09
# Read DCPAIX list

#set -x


datestamp=$(date "+%Y.%m.%d-%H.%M.%S")

SERVTYPE=`more /etc/motd | grep Welcome | awk '{print $3}' | cut -c 1-3`
if [ $SERVTYPE = "dcp" ] ; then CLUSTER=`df -gt / | tail -n 1 | cut -c 48-55` ;
else CLUSTER="APPCOM" ; fi
SERVER_NAME=`uname -n` ;
PHY_SERVER_NAME=`more /etc/motd | grep physical | awk '{print $NF}'` ;
ifconfig -a > IFCNF ; PHY_IP=`awk '/en2:/{x=NR+1;next}(NR<=x){print}' IFCNF | awk '{print $2}'` ; rm IFCNF
SERVER_SLICE=`more /etc/motd | grep slice | awk '{print $NF}'` ;
VLAN_ID=`more /etc/motd | grep VLAN | awk '{print $NF}'` ;
ABAP_SID=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9` ;
JAVA_SID=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9` ;
ABAP_INSTANCE=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2` ;
JAVA_INSTANCE=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2` ;
ABAP_HOSTNAMES=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _` ;
JAVA_HOSTNAMES=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _` ;
DB_SYSTEMS=`ps -ef | grep tns | awk '{print $(NF-1)}' | cut -f 2 -d _`

echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$ABAP_SID,$JAVA_SID,$ABAP_INSTANCE,$JAVA_INSTANCE,$ABAP_HOSTNAMES,$JAVA_HOSTNAMES,$DB_SYSTEMS

echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SAP_SYSTEMS,$ABAP_SYSTEMS,$JAVA_SYSTEMS,$ABAP_HOSTNAMES,$JAVA_HOSTNAMES,$DB_SYSTEMS >> /home/users/in10c2/sumit/VLANmap/DCPAIX.`uname -n`.$datestamp.VLANsheet.CSV

