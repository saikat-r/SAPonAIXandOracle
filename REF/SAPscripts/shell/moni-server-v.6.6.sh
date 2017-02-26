#!/usr/bin/bash
# Sumit Das 2015 01 11
# Check a system's details

#set -x
# msHOST=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -c 43-` ; echo $msHOST ;
# jcHOST=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -c 43-` ; echo $jcHOST ;
NUMmsHOST=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -c 43- | wc -l` ; echo $NUMmsHOST ; 
NUMjcHOST=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -c 43- | wc -l` ; echo $NUMjcHOST ;
SERVTYPE=`more /etc/motd | grep Welcome | awk '{print $3}' | cut -c 1-3` ; echo $SERVTYPE ; 
if [ $SERVTYPE = "dcp" ] ; then CLUSTER=`df -gt / | tail -n 1 | cut -c 48-55` ; fi ; echo $CLUSTER ;
LPAR=`hostname` ; echo $LPAR
msSAPSIDs=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9` ;
NUMmsSAPSIDs=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9 | wc -l` ;
jcSAPSIDs=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9` ;
NUMjcSAPSIDs=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9 | wc -l` ;
SAPSIDs="$msSAPSIDs $jcSAPSIDs" ; echo $SAPSIDs ;
NUMSAPSIDs=`expr $NUMmsSAPSIDs + $NUMjcSAPSIDs` ; echo $NUMSAPSIDs ;
PHYLPAR=`more /etc/motd | grep physical | awk '{print $NF}'` ; echo $PHYLPAR ;
ifconfig -a > IFCNF ; PHYIP=`awk '/en2:/{x=NR+1;next}(NR<=x){print}' IFCNF | awk '{print $2}'` ; rm IFCNF ; echo $PHYIP ;
SLICE=`more /etc/motd | grep slice | awk '{print $NF}'` ; echo $SLICE ;
VLAN=`more /etc/motd | grep VLAN | awk '{print $NF}'` ; echo $VLAN ;
ABAPinst=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2` ; echo $ABAPinst;
NUMABAPinst=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2 | wc -l` ; echo $NUMABAPinst ;
JAVAinst=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2` ; echo $JAVAinst ;
NUMJAVAinst=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2 | wc -l` ; echo $NUMJAVAinst ;
ABAPhost=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _` ; echo $ABAPhost ;
NUMABAPhost=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | wc -l` ; echo $NUMABAPhost ;
JAVAhost=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _` ; echo $JAVAhost ;
NUMJAVAhost=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | wc -l` ; echo $NUMJAVAhost ;
DBSIDs=`ps -ef | grep tns | awk '{print $10}' | cut -f 2 -d _` ; echo $DBSIDs ;
NUMDBSIDs=`ps -ef | grep tns | awk '{print $10}' | cut -f 2 -d _ | wc -l` ; echo $NUMDBSIDs ;


if [ $NUMmsHOST -eq 1 ]
then
        echo "Host file entries.............."
        more /etc/hosts | grep $msHOST
        if [ $NUMjcHOST -eq 1 ] ; then more /etc/hosts | grep $jcHOST ; fi
else

echo "Host file entries recursive...."
i=0
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ > listSYS
FN='listSYS'
while read LINE
do
# more /etc/hosts | grep -i $LINE
ping -c 1 $LINE | grep PING | awk '{print $2 "   has IP "   $3}'
((i++))
done < $FN

i=0
ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ > listSYS
FN='listSYS'
while read LINE
do
# more /etc/hosts | grep -i $LINE
ping -c 1 $LINE | grep PING | awk '{print $2 "   has IP "   $3}'
((i++))
done < $FN

rm listSYS
fi

