#!/usr/bin/bash
while true
do
date >> moniNFS.log
df -gt | grep nfs-sap >> moniNFS.log
df -gt | grep ACE_OCR >> moniNFS.log
echo "" >> moniNFS.log
echo "" >> moniNFS.log
PCT=`df -gt | grep ACE_OCR| awk  '{print $5}'`
USED=`df -gt | grep ACE_OCR| awk  '{print $3}'`
FREE=`df -gt | grep ACE_OCR| awk  '{print $4}'`
echo "QAS SAMBA filsystem is $PCT full ! " >> moniNFS.log
echo "QAS SAMBA filsystem is $USED GB used !" >> moniNFS.log
echo "QAS SAMBA filsystem has $FREE GB free space !" >> moniNFS.log

echo "" >> moniNFS.log
echo "" >> moniNFS.log
PCT=`df -gt | grep nfs-sap| awk  '{print $5}'`
USED=`df -gt | grep nfs-sap| awk  '{print $3}'`
FREE=`df -gt | grep nfs-sap| awk  '{print $4}'`
echo "PRD SAMBA filsystem is $PCT full ! " >> moniNFS.log
echo "PRD SAMBA filsystem is $USED GB used !" >> moniNFS.log
echo "PRD SAMBA filsystem has $FREE GB free space !" >> moniNFS.log
echo "-------------" >> moniNFS.log
echo ""
echo ""
sleep 60
done


