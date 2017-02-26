#!/usr/bin/bash
# Sumit Das 2016 02 03
# Script to collect VLAN data

DCPcustIP=`cat DCPcustIP`
AppComcustIP=`cat AppComcustIP`

for ipl in $DCPcustIP
do
echo "Hostname of " $ipl `ssh -q $ipl hostname`
#ssh -q $line sh ~/sumit/readHOSTNAME.sh 
#ssh -q $ipl hostname
done 

for ipl in $AppComcustIP
do
echo "Hostname of " $ipl `ssh -q $ipl hostname`
done


