#!/usr/bin/bash
# Sumit Das 2016 09 15
# Read DCPAIX list

set -e

i=0
FN='DCPAIX.list'
while read LINE
do
echo "Now executing for Server $LINE"
ssh -q -o ConnectTimeout=10 -o BatchMode=yes -o StrictHostKeyChecking=no $LINE 'bash -s' < /home/users/in10c2/moni/readDCPAIXlist4ssh
((i++))
done < $FN


