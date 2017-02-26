#!/usr/bin/bash
while true
do
DATETIME=$(date "+%Y.%m.%d-%H.%M.%S")
tail -n 15 moniNFS.log > moniNFS.log.tr
sh sendmailAIX3.sh sumit.das@linde.com moniNFS.log.tr SAMBA_fs_monitor
sh sendmailAIX3.sh deepjyoti.banerjee@linde.com moniNFS.log.tr SAMBA_fs_monitor
sh sendmailAIX3.sh santosh.kumar@linde.com moniNFS.log.tr SAMBA_fs_monitor
mv moniNFS.log.tr moniNFS.log.tr.$DATETIME
sleep 3600
done
