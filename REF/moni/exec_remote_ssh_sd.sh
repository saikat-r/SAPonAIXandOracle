#!/usr/bin/bash
# SJL 20091025 for move to TSI
# SJL 20101224 mod to run from hd204c
# NAYAN 20160727 mod return code section and remove all other commands after DCP migration
# SD 20161226 for Genesis

set -x
SID=$1
SIDLower=`echo "$SID" | awk '{print tolower($0)}'`
ADM=adm
ID="$SIDLower$ADM"
TARGETHOST=$2
DATESTAMP=$(date "+%Y.%m.%d-%H.%M.%S")
cmd=$*
#echo $cmd
log=/tmp/$$.ssh.$DATESTAMP.log
shift 2
echo $*
set -x
ssh -n -o BatchMode=yes -o StrictHostKeyChecking=no -q -i $HOME/.ssh/id_rsa $ID@$TARGETHOST $* $SID >$log
rc=$?
set +x
echo "rc=$rc" >> $log
#tail -1 $log|read return code rc
cat $log
rm -f $log

if [ $rc -eq 0 ]
then
        echo success !!!
        exit $rc
else
        echo Failed !!!
        exit $rc
fi
