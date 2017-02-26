#!/usr/bin/bash
# Sumit Das 2015 05 13
# Monitoring Script
echo ""
echo "Check Filesystems"
echo ""
echo ""
ssh $1$2$3 df -gt | grep -i $2 | awk '{$1=""; print $0}'


exit
