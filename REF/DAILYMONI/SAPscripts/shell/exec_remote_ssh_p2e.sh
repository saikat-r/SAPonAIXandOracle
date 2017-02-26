#!/usr/bin/ksh
# SJL 20091025 for move to TSI
# SJL 20101224 mod to run from hd204c
# SD  20150513 for moni
cmd=$*
log=/tmp/$$.sshp2e.log
echo $*
ssh -i $HOME/.ssh/id_rsa p2eadm@cip2e69.edc.linde.grp $* >$log
tail -1 $log|read return code rc
cat $log
rm $log
if [ .$code = ".Code:" ]
then
  code=code
fi
if [ .$code = ".code:" ]
then
  code=code
fi
if [ .$return = .Return -a .$code = .code ]
then
  exit $rc
else
  exit 16
fi


