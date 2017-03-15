#!/usr/bin/bash
# Sumit Das 2017 03 06
# Correction f DB Backup 

set -x
sid=$1
SID=`echo $sid | awk '{print toupper($0)}'`

sh /home/users/in10c2/moni/backupSTATUSauto.sh $SID
cd /home/appusers
ls -ltr | grep $sid
ADM=adm
ID="$sid$ADM"
chmod 755 /home/appusers/$ID/.
ls -ltr | grep $sid
su - $ID 



