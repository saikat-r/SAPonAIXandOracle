#!/usr/bin/bash
set -x
SID=$1
mkdir -p /home/appusers/`echo $SID`adm/.ssh
cat /home/users/in10c2/.ssh/authorized_keys >> /home/appusers/`echo $SID`adm/.ssh/authorized_keys
chown -R `echo $SID`adm:sapsys /home/appusers/`echo $SID`adm/.ssh
ls -ltr /home/appusers/`echo $SID`adm/.ssh
