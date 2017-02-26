################################################################### 
## ckinstance.ksh ## 
###################################################################
ORATAB=/etc/oratab_moni
echo "`date`   "
echo  "Oracle Database(s) Status `hostname` :\n"
db=`egrep -i ":Y|:N" $ORATAB | cut -d":" -f1 | grep -v "\#" | grep -v "\*"`
pslist="`ps -ef | grep pmon`"
for i in $db ; do
  echo  "$pslist" | grep  "ora_pmon_$i"  > /dev/null 2>$1
  if (( $? )); then
        echo "Oracle Instance - $i:       Down"
  else
        echo "Oracle Instance - $i:       Up"
  fi
done     
