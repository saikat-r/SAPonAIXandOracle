#!/usr/bin/bash
#Sumit Das 2015 06 02
# Monitoring Script

#Define Variables
APP=$1
SID=$2
SNO=$3
debugmode=$4
if [[ -z $debugmode ]]; then debugmode="nodebug" ; echo $debugmode ; fi
if [[ -n $debugmode ]]; then echo "$( basename $0 )" ; fi
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

ssh -q $CustIP /home/users/in10c2/sumit/moniscripts/moni-server-v.2.2.sh $APP $SID $SNO $debugmode
