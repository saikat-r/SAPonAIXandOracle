#!/usr/bin/bash

SID=$1
mkdir -p /home/appusers/ora$SID/.ssh
cat /home/users/in10c2/.ssh/authorized_keys >> /home/appusers/ora$SID/.ssh/authorized_keys
chown -R ora$SID:dba /home/appusers/ora$SID/.ssh