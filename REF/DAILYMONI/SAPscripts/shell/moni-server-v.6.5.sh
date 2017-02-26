#!/usr/bin/bash
# Sumit Das 2015 01 11
# Check a system's details

#set -x
msHOST=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -c 43-`
jcHOST=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -c 43-`
NUMmsHOST=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -c 43- | wc -l`
NUMjcHOST=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -c 43- | wc -l`

echo ""
SERVTYPE=`more /etc/motd | grep Welcome | awk '{print $3}' | cut -c 1-3`
if [ $SERVTYPE = "dcp" ] ; then echo "This server is on DCP cluster..." `df -gt / | tail -n 1 | cut -c 48-55` ; 
else echo "This server is on APPCom........" ; fi
echo "This server hostname is........."  `hostname` ;
echo "Physical Hardware is............" `more /etc/motd | grep physical | awk '{print $NF}'` ;
ifconfig -a > IFCNF ; echo "Physical IP of this server......" `awk '/en2:/{x=NR+1;next}(NR<=x){print}' IFCNF | awk '{print $2}'` ; rm IFCNF
echo "Slice-Size of this server......." `more /etc/motd | grep slice | awk '{print $NF}'` ;
echo "VLAN-ID of this server.........." `more /etc/motd | grep VLAN | awk '{print $NF}'` ;
echo "SAP systems running here........" `ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9` `ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9` ;
echo "ABAP Instance Running here......" `ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2` ;
echo "Java Instance Running here......" `ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2` ;
echo "ABAP Hostnames available here..." `ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _` ;
echo "JAVA Hostnames available here..." `ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _` ;
echo "DB running on this server......." `ps -ef | grep tns | awk '{print $10}' | cut -f 2 -d _`
echo ""

if [ $NUMmsHOST -eq 1 ]
then
        echo "Host file entries..............."
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

