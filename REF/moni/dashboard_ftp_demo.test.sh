!/usr/bin/bash
# Sumit Das 2016 06 03 Original
# Sumit Das 2016 08 31 Modified
# Record SAP status to Dashboard

set -x

#Define Variables
APP=$1 ; SID=$2 ; SNO=$3 ;
debugmode=$4
if [[ -z $debugmode ]]; then debugmode="nodebug" ; echo $debugmode ; fi
if [ $debugmode = "debug" ]; then echo "$( basename $0 )" ; fi
if [ $debugmode = "debug" ]; then set -x ; fi

datestamp=$(date "+%Y.%m.%d-%H.%M.%S")
datesh=$(date "+%Y.%m.%d")

WorkDir=/home/users/in10c2/moni
LogDir=/home/users/in10c2/moni/monitoringLOGS
FTPdir=/home/users/in10c2/sumit/moniscripts/monitoringLOGS
mkdir -p $LogDir/$datesh
cd $WorkDir

# Write to HTML files
cp -pr webpub/tables/tbl_im_Dashboard_Prod_Demo.html tbl_im_Dashboard_Prod_LIVE.html
sed s/IAMDATE/" $datestamp"/g tbl_im_Dashboard_Prod_LIVE.html > temptbl_Dashboard_Prod_Demo_tmp.html
mv temptbl_Dashboard_Prod_Demo_tmp.html tbl_im_Dashboard_Prod_LIVE.html

APP=DB ; SID=BWP ; SNO=70 ; sh $WorkDir/dashboard_demo.test.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=BWP ; SNO=70 ; sh $WorkDir/dashboard_demo.test.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log

rm temptbl_Dashboard_Prod_Demo_*
echo "</table>" >> tbl_im_Dashboard_Prod_LIVE.html
echo "</body>" >> tbl_im_Dashboard_Prod_LIVE.html
echo "</html>" >> tbl_im_Dashboard_Prod_LIVE.html
mv tbl_im_Dashboard_Prod_LIVE.html /home/users/in10c2/sumit/moniscripts/monitoringLOGS/.

#cd $LogDir/$datesh
#ftp -vn ftpq.edc.linde.grp <<EOF1 > ftp.log
#user SImoni Iamroot0
#cd $FTPdir
#prompt
#ascii
#put tbl_im_Dashboard_Prod_LIVE.html
#quit
#EOF1

