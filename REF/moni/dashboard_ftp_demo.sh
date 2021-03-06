!/usr/bin/bash
# Sumit Das 2016 06 03 Original
# Sumit Das 2016 08 31 Modified
# Record SAP status to Dashboard

set -x

while true
do
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

APP=DB ; SID=BWP ; SNO=70 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=BWP ; SNO=70 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=CRP ; SNO=60 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=CRP ; SNO=60 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=DOG ; SNO=34 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JI ; SID=GCU ; SNO=87 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JD ; SID=GCU ; SNO=87 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=GP6 ; SNO=83 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=GP6 ; SNO=83 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=GPA ; SNO=70 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=GPA ; SNO=71 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=GPA ; SNO=72 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=GPA ; SNO=73 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=GPA ; SNO=75 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=GPA ; SNO=70 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=GPA ; SNO=78 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=GPA ; SNO=79 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=GPB ; SNO=61 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=GPB ; SNO=61 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=GPC ; SNO=82 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=GPC ; SNO=82 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JD ; SID=GPE ; SNO=44 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JI ; SID=GPE ; SNO=44 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JI ; SID=GPF ; SNO=35 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JD ; SID=GPF ; SNO=34 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JI ; SID=GPF ; SNO=34 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JI ; SID=GPL ; SNO=22 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JI ; SID=GPL ; SNO=23 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JD ; SID=GPL ; SNO=22 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JI ; SID=GPL ; SNO=25 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JI ; SID=GPL ; SNO=24 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=GPU ; SNO=66 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=GPU ; SNO=66 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=HPS ; SNO=22 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=HPS ; SNO=22 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JI ; SID=JP1 ; SNO=31 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JD ; SID=JP1 ; SNO=31 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JI ; SID=JP4 ; SNO=34 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JD ; SID=JP4 ; SNO=34 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=P01 ; SNO=22 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=P01 ; SNO=21 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=P01 ; SNO=20 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=P01 ; SNO=20 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=P01 ; SNO=24 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=P01 ; SNO=23 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=P1B ; SNO=37 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=P1B ; SNO=37 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=P2E ; SNO=69 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=P2E ; SNO=70 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=P2E ; SNO=77 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=P6E ; SNO=45 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=P6E ; SNO=45 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=P7E ; SNO=46 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=P7E ; SNO=46 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=P8B ; SNO=55 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=P8B ; SNO=55 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=P8E ; SNO=13 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=P8E ; SNO=47 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=P8E ; SNO=31 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=P8E ; SNO=47 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=P9B ; SNO=19 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=P9B ; SNO=19 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=P9E ; SNO=24 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=P9E ; SNO=12 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=P9E ; SNO=27 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=P9E ; SNO=24 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=P9E ; SNO=67 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=PFE ; SNO=07 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JD ; SID=PGD ; SNO=04 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JI ; SID=PGD ; SNO=04 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=PGH ; SNO=59 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JI ; SID=PGI ; SNO=07 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=PGU ; SNO=83 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=PGU ; SNO=83 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=PGV ; SNO=80 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=PGV ; SNO=80 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=PJB ; SNO=40 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=PJE ; SNO=14 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=PJE ; SNO=14 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=PJE ; SNO=92 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JI ; SID=PN2 ; SNO=43 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JD ; SID=PN2 ; SNO=43 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=PNU ; SNO=42 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=PNU ; SNO=42 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JD ; SID=PP1 ; SNO=30 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=JI ; SID=PP1 ; SNO=30 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=PRD ; SNO=00 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=PRD ; SNO=41 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=PRD ; SNO=42 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=PRD ; SNO=00 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=AP ; SID=PRD ; SNO=44 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=VP4 ; SNO=33 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=VP4 ; SNO=33 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=DB ; SID=ZP2 ; SNO=86 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log
APP=CI ; SID=ZP2 ; SNO=86 ; sh $WorkDir/dashboard_demo.sh $APP $SID $SNO > $LogDir/$datesh/$APP$SID$SNO.$datestamp.log


rm temptbl_Dashboard_Prod_Demo_*
echo "</table>" >> tbl_im_Dashboard_Prod_LIVE.html
echo "</body>" >> tbl_im_Dashboard_Prod_LIVE.html
echo "</html>" >> tbl_im_Dashboard_Prod_LIVE.html
mv tbl_im_Dashboard_Prod_LIVE.html /home/users/in10c2/sumit/moniscripts/monitoringLOGS/.
#mv tbl_im_Dashboard_Prod_LIVE.html /usr/sap/scratch/DAILYMONI/reports/.

#cp -pr /usr/sap/scratch/DAILYMONI/reports/MON* /home/users/in10c2/sumit/moniscripts/monitoringLOGS/.
#cp -pr /usr/sap/scratch/DAILYMONI/reports/REP* /home/users/in10c2/sumit/moniscripts/monitoringLOGS/.
#cp -pr /usr/sap/scratch/DAILYMONI/reports/tbl_im_* /home/users/in10c2/sumit/moniscripts/monitoringLOGS/.

#cd $LogDir/$datesh
#ftp -vn ftpq.edc.linde.grp <<EOF1 > ftp.log
#user SImoni Iamroot0
#cd $FTPdir
#prompt
#ascii
#put tbl_im_Dashboard_Prod_LIVE.html
#quit
#EOF1

done

