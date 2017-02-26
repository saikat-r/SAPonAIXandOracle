#!/usr/bin/bash
#Sumit Das 2017 01 28
#Collect data for VLAN mapping 

#echo "Number of Arguments is " $#
#if [ $# -eq 2 ] ; then datestamp=$1 ; debugmode=$2 ; echo "$debugmode mode ON" ; fi
#if [ $# -eq 1 ] ; then datestamp=$1 ; debugmode="nodebug" ; fi
#if [ $# -eq 0 ] ; then datestamp=$(date "+%Y.%m.%d-%H.%M.%S") ; debugmode="nodebug" ; fi

#set -x
datestamp=$(date "+%Y.%m.%d-%H.%M.%S")
debugmode="nodebug"
SHEETname="DCPAIX.$datestamp.VLANsheet.CSV"

/home/users/in10c2/moni/readALLphyIP.sh >/dev/null 2>&1

while IFS=, read LPAR IP
do
	if [ -n $IP ]; then
	ssh -q -n -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $IP sh /home/users/in10c2/moni/readSERVICEdataAUTO.sh $datestamp
	fi
done < /home/users/in10c2/moni/ALL_PHY_HOSTIP_`uname -n`.txt

ftp -vn wlggceod000e0.linde.lds.grp <<FTP_REP > ftp.log
user WINmoni Iamroot0
cd VLANmap
prompt
ascii
mput /home/users/in10c2/sumit/VLANmap/$SHEETname
quit
FTP_REP


