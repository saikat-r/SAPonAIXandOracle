#!/bin/ksh
 
# --- Environment --- #
SERVER=$(uname -n)
MAILTO=[Atap@company.com]
 
# --- High Water Marks --- #
typeset -i CPUHWM=60
typeset -i PAGHWM=60
typeset -i TMHWM=60
 
# --- Vars --- #
typeset -i CPU PAG TM
 
 
CPU=$(vmstat 1 1 | tail -1 | awk '{print $14+$15}')
[ $CPU -gt $CPUHWM ] && echo "CPU exceeded $CPU us+sy percent on $SERVER" | mailx -s "CPU alert for $SERVER (${CPU}%)" $MAILTO
 
PAG=$(vmstat 1 1 | tail -1 | awk '{print $6+$7}')
[ $PAG -gt $PAGHWM ] && echo "PAGING exceeded $PAG pi+po pages on $SERVER" | mailx -s "Paging alert for $SERVER (${PAG}/s)" $MAILTO
 
for DISK in $(lspv | awk '{print $1}')
 do
  TM=$(iostat -d $DISK 1 1 | grep hdisk | awk '{print $2}')
  [ $TM -gt $TMHWM ] && echo "Disk $DISK exceeded ${TM}% tm_act on $SERVER" | mailx -s "DiskIO alert for $SERVER ($DISK ${TM}%)" $MAILTO
 done
 
exit