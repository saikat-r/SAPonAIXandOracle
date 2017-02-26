#!/usr/bin/bash
# Sumit Das 2015 01 11
# Check a system's details

#set -x
apHOST=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF) }' | cut -c 43-` ; #echo $apHOST ;
jcHOST=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -c 43-` ; #echo $jcHOST ;
NUMapHOST=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF) }' | cut -c 43- | wc -l` ; #echo $NUMapHOST ;
NUMjcHOST=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -c 43- | wc -l` ; #echo $NUMjcHOST ;
SERVTYPE=`more /etc/motd | grep Welcome | awk '{print $3}' | cut -c 1-3` ; #echo $SERVTYPE ;
if [ $SERVTYPE = "dcp" ] ; then CLUSTER=`df -gt / | tail -n 1 | cut -c 48-55` ; fi ; #echo $CLUSTER ;
LPAR=`hostname` ; #echo $LPAR
apSAPSIDs=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9` ;
NUMapSAPSIDs=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9 | wc -l` ;
jcSAPSIDs=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9` ;
NUMjcSAPSIDs=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9 | wc -l` ;
SAPSIDs="$apSAPSIDs $jcSAPSIDs" ; #echo $SAPSIDs ;
NUapAPSIDs=`expr $NUMapSAPSIDs + $NUMjcSAPSIDs` ; #echo $NUapAPSIDs ;
PHYLPAR=`more /etc/motd | grep physical | awk '{print $NF}'` ; #echo $PHYLPAR ;
ifconfig -a > IFCNF ; PHYIP=`awk '/en2:/{x=NR+1;next}(NR<=x){print}' IFCNF | awk '{print $2}'` ; rm IFCNF ; #echo $PHYIP ;
SLICE=`more /etc/motd | grep slice | awk '{print $NF}'` ; #echo $SLICE ;
VLAN=`more /etc/motd | grep VLAN | awk '{print $NF}'` ; #echo $VLAN ;
ABAPinst=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF-2) }' | cut -d _ -f 2` ; #echo $ABAPinst;
NUMABAPinst=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF-2) }' | cut -d _ -f 2 | wc -l` ; #echo $NUMABAPinst ;
JAVAinst=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2` ; #echo $JAVAinst ;
NUMJAVAinst=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2 | wc -l` ; #echo $NUMJAVAinst ;
ABAPhost=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _` ; #echo $ABAPhost ;
NUMABAPhost=`ps -ef | grep se.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | wc -l` ; #echo $NUMABAPhost ;
JAVAhost=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _` ; #echo $JAVAhost ;
NUMJAVAhost=`ps -ef | grep jc.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | wc -l` ; #echo $NUMJAVAhost ;
DBSIDs=`ps -ef | grep tns | awk '{print $10}' | cut -f 2 -d _` ; #echo $DBSIDs ;
NUMDBSIDs=`ps -ef | grep tns | awk '{print $10}' | cut -f 2 -d _ | wc -l` ; #echo $NUMDBSIDs ;
NUMsmda=`ps -ef | grep jc.sap | grep SMDA | wc -l` ; #echo $NUMsmda ;
SMDAinst=`ps -ef | grep jc.sap | grep SMDA | awk '{ print $(NF-1) }' | cut -d _ -f 2` ; #echo $SMDAinst ;
msHOST=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -c 43-` ; #echo $msHOST ;
NUMmsHOST=`ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -c 43- | wc -l` ; #echo $NUMmsHOST ;

#TOTinst=expr( $NUMABAPinst + $NUMJAVAinst ) ; #echo $TOTinst ;

echo "Host file entries ............."
i=0
ps -ef | grep se.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ > listSYS
FN='listSYS'
cp listSYS listSYSse
while read LINE
do
# more /etc/hosts | grep -i $LINE
ping -c 1 $LINE | grep PING | awk '{print $2 "   has IP "   $3}'
((i++))
done < $FN

i=0
ps -ef | grep jc.sap | grep pf | grep -v SMDA | awk '{ print $(NF) }' | cut -f 3 -d _ > listSYS
FN='listSYS'
cp listSYS listSYSjc
while read LINE
do
# more /etc/hosts | grep -i $LINE
ping -c 1 $LINE | grep PING | awk '{print $2 "   has IP "   $3}'
((i++))
done < $FN

cat listSYSse > listSYSall
cat listSYSjc >> listSYSall
rm listSYS listSYSse listSYSjc
sort -u listSYSall > listSYS


if [ $SERVTYPE = "dcp" ]
then
while read LINE
do
echo "" >> mapfile
echo -n $LPAR >> mapfile 
echo -n "," >> mapfile
echo -n $i >> mapfile 
echo -n "," >> mapfile
SID=`echo $LINE | cut -c 6-9`
INST=`echo $LINE | cut -c 9-10`
TYPE=`echo $LINE | cut -c 3-4`
echo -n $SID "_" $INST "_" $TYPE >> mapfile 
echo -n "," >> mapfile
echo -n $SID >> mapfile 
echo -n "," >> mapfile
echo -n $INST >> mapfile 
echo -n "," >> mapfile
echo -n $TYPE >> mapfile 
echo -n "," >> mapfile
echo -n $VLAN >> mapfile 
echo -n "," >> mapfile
echo -n $PHYIP >> mapfile 
echo -n "," >> mapfile
SERVIP=`ping -c 1 $LINE | grep PING | awk '{print $3}' | tr -d '():'`
echo -n $SERVIP 
echo -n "," >> mapfile

done < listSYS


echo "" >> mapfile


else
while read LINE
do
echo "" >> mapfile
echo -n $LPAR >> mapfile 
echo -n "," >> mapfile
echo -n $LINE >> mapfile 
echo -n "," >> mapfile
SID=`echo $LINE | cut -c 3-5`
INST=`echo $LINE | cut -c 6-8`
TYPE=`echo $LINE | cut -c 1-2`
echo -n $SID"_"$INST"_"$TYPE >> mapfile 
echo -n "," >> mapfile
echo -n "${SID^^}" >> mapfile 
echo -n "," >> mapfile
echo -n $INST >> mapfile 
echo -n "," >> mapfile
echo -n "${TYPE^^}" >> mapfile 
echo -n "," >> mapfile
echo -n $VLAN >> mapfile 
echo -n "," >> mapfile
echo -n $PHYIP >> mapfile 
echo -n "," >> mapfile
SERVIP=`ping -c 1 $LINE | grep PING | awk '{print $3}' | tr -d '():'`
echo -n $SERVIP >> mapfile
echo "" >> mapfile

done < listSYS


echo "" >> mapfile
fi

sort -u mapfile > mapfile.tmp
mv mapfile.tmp mapfile.csv

uuencode mapfile.csv  mapfile.csv | mailx -r "Sumit.Das" -s "DCP-AppCom_VLAN_Sheet" "sam8boc@gmail.com"
#cat mapfile.csv | mailx -r "Sumit.Das" -s "DCP-AppCom_VLAN_Sheet" "sam8boc@gmail.com"
#(cat mapfile.csv ; uuencode mapfile.csv ) | mailx -r "Sumit.Das" -s "DCP-AppCom_VLAN_Sheet" "sam8boc@gmail.com"
#(echo "This is VLAN Sheet" ; uuencode mapfile ) | mailx -r "SumitDas" -s "DCP_AppCom_VLAN_Sheet" "sam8boc@gmail.com"
exit 
