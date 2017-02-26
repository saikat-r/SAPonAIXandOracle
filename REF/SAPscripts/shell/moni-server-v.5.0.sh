#!/usr/bin/bash
#Sumit Das 2015 05 21
# Monitoring Script

#Define Variables
SID=$1
debugmode=$2
if [[ -z $debugmode ]]; then debugmode="nodebug" ; echo $debugmode ; fi
if [ $debugmode = "debug" ]; then echo "$( basename $0 )" ; fi
LPARLIST1=/home/users/in10c2/sumit/ALL-LPAR-List


#Find Customer IP
grep -i $SID $LPARLIST1 > /home/users/in10c2/sumit/monitemp1
countzero=`more /home/users/in10c2/sumit/monitemp1 | wc -l`
if [ $debugmode = "debug" ]; then echo $debugmode ; echo "Entries initially read from LPARLIST: " $countzero ; fi
if [ $debugmode = "debug" ]; then cat /home/users/in10c2/sumit/monitemp1 ; fi
if [ $countzero -eq 0 ]; then echo "$SID not found in VLAN-LPAR list !" ; exit ; fi

# START for loop
i=1
while [ $i -le $countzero ]
do
if [ $debugmode = "debug" ]; then echo "I am in for loop now..." ; fi
if [ $debugmode = "debug" ]; then echo "For loop started..." ; fi
if [ $debugmode = "debug" ]; then echo $i ; fi
line=$(sed -n "${i}p" "/home/users/in10c2/sumit/monitemp1")
echo $line > /home/users/in10c2/sumit/monitemp2
#sed -n "$i" "/home/users/in10c2/sumit/monitemp1" > "/home/users/in10c2/sumit/monitemp2"
read LPAR SIDR INST TYPE VLAN CustIP < /home/users/in10c2/sumit/monitemp2
if [ $debugmode = "debug" ]; then echo "Entries from LPARLIST: " ; cat /home/users/in10c2/sumit/monitemp2 ; fi
if [ $debugmode = "debug" ]; then
        echo $LPAR
        echo $SIDR
        echo $INST
        echo $TYPE
        echo $VLAN
        echo $CustIP
fi

#sh /home/users/in10c2/sumit/moniscripts/moni-server-v.3.2.sh $TYPE $SIDR $INST $debugmode
ssh -q $CustIP /home/users/in10c2/sumit/moniscripts/moni-server-v.2.5.sh $TYPE $SIDR $INST $debugmode

if [ $debugmode = "debug" ]; then sleep 5 ; fi
rm /home/users/in10c2/sumit/monitemp2
i=$(( $i+1 ))
done
# END for loop

rm /home/users/in10c2/sumit/monitemp1

