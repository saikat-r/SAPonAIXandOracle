#!/usr/bin/bash
#Sumit Das 2017 02 24
#Send  VLAN Sheet to ALL

#echo "Number of Arguments is " $#
#if [ $# -eq 2 ] ; then datestamp=$1 ; debugmode=$2 ; echo "$debugmode mode ON" ; fi
#if [ $# -eq 1 ] ; then datestamp=$1 ; debugmode="nodebug" ; fi
#if [ $# -eq 0 ] ; then datestamp=$(date "+%Y.%m.%d-%H.%M.%S") ; debugmode="nodebug" ; fi

#set -x
datestamp=$(date "+%Y.%m.%d-%H.%M.%S")
debugmode="nodebug"

cd /home/users/in10c2/moni
rm -f DCP_VLAN_Sheet.xls
ftp -vn 10.81.66.19 <<FTP_GnS_REP > ftp_GnS.log
user WINmoni Iamroot0
cd VLANmap
prompt
ascii
get DCP_VLAN_Sheet.xls
quit
FTP_GnS_REP

rc=$?
if [ $rc -eq 0 ] ; then
	echo "DCP_VLAN_Sheet.xls was fetched from E0 server"
else
	echo "DCP_VLAN_Sheet.xls could NOT be fetched from E0 server"
fi

#cp -pr VLANsheetLIVE.xls DCP_VLAN_Sheet.xls
uuencode DCP_VLAN_Sheet.xls DCP_VLAN_Sheet.xls | mailx -s "DCP VLAN Sheet" sumit.das@linde.com
rc=$?
if [ $rc -eq 0 ] ; then
	echo "DCP_VLAN_Sheet.xls was sent to ALL"
else
	echo "DCP_VLAN_Sheet.xls could NOT be sent !"
fi

#(echo "This is the body";uuencode VLANsheetLIVE.CSV) | mail -s "This is the subject" sumit.das@linde.com
