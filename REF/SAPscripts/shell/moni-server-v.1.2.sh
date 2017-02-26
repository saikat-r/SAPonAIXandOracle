#!/usr/bin/bash
#Sumit Das 2015 05 21
# Monitoring Script

#Define Variables
APP=$1
SID=$2
SNO=$3
debugmode=$4 
if [[ -z $debugmode ]]; then debugmode="nodebug" ; echo $debugmode ; fi
LPARLIST1=/home/users/in10c2/sumit/ALL-LPAR-List

#Find Customer IP
grep -i $SID $LPARLIST1 > /home/users/in10c2/sumit/tempmoni1
grep -i $APP /home/users/in10c2/sumit/tempmoni1 > /home/users/in10c2/sumit/tempmoni2
count=`more /home/users/in10c2/sumit/tempmoni2 | wc -l`
if [ $debugmode = "debug" ]; then echo $debugmode ; echo "Entries read from LPARLIST: " $count ; fi
read LPAR SIDR INST TYPE VLAN CustIP < /home/users/in10c2/sumit/tempmoni2 
if [ $debugmode = "debug" ]; then echo "Entries from LPARLIST: " ; cat /home/users/in10c2/sumit/tempmoni2 ; fi
rm /home/users/in10c2/sumit/tempmoni*
if [ $debugmode = "debug" ]; then
	echo $LPAR
	echo $SIDR
	echo $INST
	echo $TYPE
	echo $VLAN
	echo $CustIP
fi

#Check OS specifics
echo ""
echo "Check OS specifics:"
echo ""
ssh -q $CustIP date; hostname; uname -a; oslevel -s;uptime | awk '{print $2 $3 $4}'
echo ""
echo "Check Swap Space:"
ssh -q $CustIP lsps -a
echo ""
echo "Check CPU Utilization"
echo ""
echo "Check Memory Utilization"
echo ""


#Check filesystems
echo ""
echo "Check SAP specific filesystems"
ssh -q $CustIP df -gt | grep -i $SID | awk '{$1=""; print $0}'

#Check Database
if [ $APP = "db" ]; 
   then
	echo ""
	echo "Checking Database:" 
	ssh -q $CustIP ps -ef | grep ora_pmon_ | grep -i -c $SID > /home/users/in10c2/sumit/tempmoni3
	read ORAINSTcount < /home/users/in10c2/sumit/tempmoni3
	if [ $debugmode = "debug" ]; then echo "Number of pmon ps lines returned: " ; cat /home/users/in10c2/sumit/tempmoni3 ; fi
	if [ $debugmode = "debug" ]; then echo "Number of pmon ps lines returned: " $ORAINSTcount ; fi
	if [ $ORAINSTcount -ge 1 ]; then
        	echo "Oracle Instance - $SID:       UP"
  	else
        	echo "Oracle Instance - $SID:       DOWN"
  	fi
fi


exit
