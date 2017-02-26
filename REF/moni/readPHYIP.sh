#!/usr/bin/bash
# Sumit Das 2016 12 26
# Find All PHYsical HOSTs and their IP in a cluster

#set -x
#cd /home/users/in10c2/moni
ls -1 /cAppCom/os_init.d | grep dcpaix > listPHYSERV
FN='listPHYSERV'
rm listPHYIP 2> /dev/null
while read LINE
do
PHYHOST=$LINE
PHYHOSTIP=`ping -c 1 $LINE | grep PING | awk '{print $3}' | cut -c2- | rev | cut -c3- | rev`

IPV6IPchk=`echo $PHYHOSTIP | cut -c -4`
if [ $IPV6IPchk = "2a00" ] 
	then 
	ssh -n -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $LINE ifconfig -a > IFCNF 
	PHYHOSTIP=`awk '/en2:/{x=NR+1;next}(NR<=x){print}' IFCNF | awk '{print $2}'` 
	rm IFCNF
fi

echo "$PHYHOST,$PHYHOSTIP" >> listPHYIP
done < $FN

cat listPHYIP
cp  /home/users/in10c2/moni/ALL_PHY_HOSTIP_`uname -n`.txt
