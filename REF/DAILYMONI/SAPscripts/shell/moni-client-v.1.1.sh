#!/usr/bin/bash
# Sumit Das 2015 05 21
# Monitoring Script
# Define Variables
APP=$1
SID=$2
SNO=$3
#LPARLIST1=/home/users/in10c2/sumit/ALL-LPAR-List
LPARLIST2=/drives/c/Users/in10c2/Documents/SAP/SAPscripts/ALL-LPAR-List.txt
temp1=/drives/c/Users/in10c2/Documents/SAP/SAPscripts/temp_moni1
temp2=/drives/c/Users/in10c2/Documents/SAP/SAPscripts/temp_moni2
# Find Customer IP
grep -i $2 $LPARLIST1 > $temp1
grep -i $1 $temp1 > $temp2
grep -i $2 $temp2 | read LPAR SID INST TYPE VLAN CustIP
echo $LPAR
echo $SIDR
echo $INST
echo $TYPE
echo $VLAN
echo $CustIP
# Check filesystems
ssh $CustIP df -gt | grep $SID | awk '{$1=""; print $0}'
exit
