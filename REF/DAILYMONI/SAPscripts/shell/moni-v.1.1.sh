#!/usr/bin/bash
#Sumit Das 2015 05 21
# Monitoring Script

#Define Variables
APP=$1
SID=$2
SNO=$3

LPARLIST1=/home/users/in10c2/sumit/ALL-LPAR-List
LPARLIST2="C:\Users\in10c2\Box Sync\BOC\SIsupport\UNIXscripts\ALL-LPAR-List.txt"



#Find Customer IP
grep "$SID" | grep "$APP" | grep "$LPARLIST"|read LPAR	SIDR INST TYPE VLAN CustIP

echo $LPAR
echo $SIDR
echo $INST
echo $TYPE
echo $VLAN
echo $CustIP

#Check filesystems
ssh $CustIP df -gt | grep $SID | awk '{$1=""; print $0}'
exit
