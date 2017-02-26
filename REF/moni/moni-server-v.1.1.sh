#!/usr/bin/bash
#Sumit Das 2015 05 21
# Monitoring Script

#Define Variables
APP=$1
SID=$2
SNO=$3
debugmode=$4

LPARLIST1=/home/users/in10c2/sumit/ALL-LPAR-List

#Find Customer IP
grep -i $SID $LPARLIST1 > /home/users/in10c2/sumit/tempmoni1
grep -i $APP /home/users/in10c2/sumit/tempmoni1 > /home/users/in10c2/sumit/tempmoni2
count=`more /home/users/in10c2/sumit/tempmoni2 | wc -l`
if [ debugmode = "debug" ]; then echo $count ; fi
read LPAR SIDR INST TYPE VLAN CustIP < /home/users/in10c2/sumit/tempmoni2 
if [ debugmode = "debug" ]; then cat /home/users/in10c2/sumit/tempmoni2 ; fi
rm /home/users/in10c2/sumit/tempmoni*
if [ debugmode = "debug" ] 
   then
	echo $LPAR
	echo $SIDR
	echo $INST
	echo $TYPE
	echo $VLAN
	echo $CustIP
fi

#Check filesystems
echo "Check SAP specific filesystems"
ssh -q $CustIP df -gt | grep -i $SID | awk '{$1=""; print $0}'



exit
