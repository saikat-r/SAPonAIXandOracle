#!/usr/bin/bash
# Sumit Das 2015 01 11
# Check a system's details

#set -x
msHOST=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -c 43-`
jcHOST=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -c 43-`
NUMmsHOST=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -c 43- | wc -l`
NUMjcHOST=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -c 43- | wc -l`

echo ""
echo "This server is on DCP cluster..." `df -gt / | tail -n 1 | cut -c 48-55` ;
echo ""
echo "This server hostanme is........."  `hostname` ;
echo ""
echo "SAP systems running here........" `ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9` `ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9` ;
echo ""
echo "ABAP Instance Running here......" `ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2` ;
echo ""
echo "Java Instance Running here......" `ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2` ;
echo ""
echo "ABAP Hostanmes available here..." `ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -c 43-` ;
echo ""
echo "JAVA Hostanmes available here..." `ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -c 43-` ;
echo ""
echo "DB running on this server......." `ps -ef | grep tns | awk '{print $10}'`
echo ""

if [ $NUMmsHOST -eq 1 ]
then
        echo "Host file entries.............."
        more /etc/hosts | grep $msHOST
        if [ $NUMjcHOST -eq 1 ] ; then more /etc/hosts | grep $jcHOST ; fi
else

echo ""
echo "Host file entries recursive...."
i=0
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9 > listSYS
FN='listSYS'
while read LINE
do
more /etc/hosts | grep -i $LINE
((i++))
done < $FN

i=0
ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9 > listSYS
FN='listSYS'
while read LINE
do
more /etc/hosts | grep -i $LINE
((i++))
done < $FN

rm listSYS
fi

