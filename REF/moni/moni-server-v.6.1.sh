#!/usr/bin/bash
# Sumit Das 2015 06 27
# Monitoring Script On-Demand

#Define Variables
APP=$1
SID=$2
SNO=$3
debugmode=$4
if [[ -z $debugmode ]]; then debugmode="nodebug" ; echo $debugmode ; fi
if [ $debugmode = "debug" ]; then echo "$( basename $0 )" ; fi
if [ $debugmode = "debug" ]; then set -x ; fi
datestamp=$(date "+%Y.%m.%d-%H.%M.%S")
datesh=$(date "+%Y.%m.%d")
cd /home/users/in10c2/sumit/moniscripts
mkdir -p monitoringLOGS/$datesh

#Check OS specifics
echo ""
echo ""
echo "==================================="
echo "Start Monitoring for $APP $SID $SNO"
echo "==================================="
echo ""
echo "Check OS specifications:"
echo "------------------------"
date; hostname; uname -a; #oslevel -s;
uptime > tempuptime
UPDAYS=`more tempuptime | awk '{print $3}'`; # UPDAYS=`echo ${UPDAYS%?}`;
MIN1CPU=`more tempuptime | awk '{print $10}'`; MIN1CPU=`echo ${MIN1CPU%?}`;
MIN5CPU=`more tempuptime | awk '{print $11}'`; MIN5CPU=`echo ${MIN5CPU%?}`;
MIN10CPU=`more tempuptime | awk '{print $12}'`; # MIN10CPU=`echo ${MIN10CPU%?}`;
echo "Server is up for          = " $UPDAYS "Days"
echo "Last  1 Min. CPU Average Load = " $MIN1CPU
echo "Last  5 Min. CPU Average Load = " $MIN5CPU
echo "Last 10 Min. CPU Average Load = " $MIN10CPU
echo ""
rm -f tempuptime

echo "Check Swap Space:"
echo "-----------------"
lsps -a > templsps
TOTSWP=`more templsps | grep paging | awk '{print $4}'`
USEDSWP=`more templsps | grep paging | awk '{print $5}'`
echo "Total Swap Space          = " $TOTSWP
echo "Swap Space Used in %      = " $USEDSWP
echo ""
rm -f templsps

vmstat_sec=3
vmstat_count=4

vmstat -w $vmstat_sec $vmstat_count >> tempvmstat 2>&1

:<<NONEED2
# Analysis via nmon
nmon -F nmon.$LPAR -c 1
gzip nmon.$LPAR
mv nmon.$LPAR.gz nmonlogs/.
NONEED2

echo "Check CPU Utilization:"
echo "----------------------"
#echo ""
i=1
cp -pr webpub/charts/bar_vmstat_CPU.html bar_vmstat_CPU_$APP.$SID.$SNO.html
sed s/myheader2/"VMSTAT collected $vmstat_count times with interval of $vmstat_sec second"/g bar_vmstat_CPU_$APP.$SID.$SNO.html > tempbar_vmstat_CPU_$APP.$SID.$SNO.html
mv tempbar_vmstat_CPU_$APP.$SID.$SNO.html bar_vmstat_CPU_$APP.$SID.$SNO.html
sed s/myheader3/"Analysis Time: $datestamp"/g bar_vmstat_CPU_$APP.$SID.$SNO.html > tempbar_vmstat_CPU_$APP.$SID.$SNO.html
mv tempbar_vmstat_CPU_$APP.$SID.$SNO.html bar_vmstat_CPU_$APP.$SID.$SNO.html
while [ $i -le $vmstat_count ]
do
if [ $debugmode = "debug" ]; then echo "Do loop entered... i is $i" ; fi
USERCPU=`sed -n $((i+6))p tempvmstat | awk '{print $14}'`
SYSTEM=`sed -n $((i+6))p tempvmstat | awk '{print $15}'`
IDLE=`sed -n $((i+6))p tempvmstat | awk '{print $16}'`
WAIT=`sed -n $((i+6))p tempvmstat | awk '{print $17}'`
echo "CPU Metrics: Count $i"
echo "User CPU %     =    " $USERCPU
echo "System CPU %   =    " $SYSTEM
echo "IDLE CPU %     =    " $IDLE
echo "WAIT CPU %     =    " $WAIT
echo ""
# Write to HTML file
sed s/var_us_$i/$USERCPU/g bar_vmstat_CPU_$APP.$SID.$SNO.html > tempbar_vmstat_CPU_$APP.$SID.$SNO.html
mv tempbar_vmstat_CPU_$APP.$SID.$SNO.html bar_vmstat_CPU_$APP.$SID.$SNO.html
sed s/var_sy_$i/$SYSTEM/g bar_vmstat_CPU_$APP.$SID.$SNO.html > tempbar_vmstat_CPU_$APP.$SID.$SNO.html
mv tempbar_vmstat_CPU_$APP.$SID.$SNO.html bar_vmstat_CPU_$APP.$SID.$SNO.html
sed s/var_id_$i/$IDLE/g bar_vmstat_CPU_$APP.$SID.$SNO.html > tempbar_vmstat_CPU_$APP.$SID.$SNO.html
mv tempbar_vmstat_CPU_$APP.$SID.$SNO.html bar_vmstat_CPU_$APP.$SID.$SNO.html
sed s/var_wa_$i/$WAIT/g bar_vmstat_CPU_$APP.$SID.$SNO.html > tempbar_vmstat_CPU_$APP.$SID.$SNO.html
mv tempbar_vmstat_CPU_$APP.$SID.$SNO.html bar_vmstat_CPU_$APP.$SID.$SNO.html
i=$(($i+1))
if [ $debugmode = "debug" ]; then echo "Now i is $i" ; fi
done
mv bar_vmstat_CPU_$APP.$SID.$SNO.html monitoringLOGS/$datesh/.

echo "Top 10 CPU processes:"
echo "--------------------"
#echo ""
ps aux | head -1; ps aux | sort -rn +2 | head -10 > top10cputemp
cat top10cputemp
cp -pr webpub/tables/tbl_im_Top10_CPU.html tbl_im_Top10_CPU_$APP.$SID.$SNO.html
#sed s/myheader1/"Top 10 CPU processes in $APP.$SID.$SNO"/g tbl_im_Top10_CPU_$APP.$SID.$SNO.html > temp_vmstat_CPU_$APP.$SID.$SNO.html
#mv temp_vmstat_CPU_$APP.$SID.$SNO.html tbl_im_Top10_CPU_$APP.$SID.$SNO.html
sed s/myheader2/"For $APP.$SID.$SNO "/g tbl_im_Top10_CPU_$APP.$SID.$SNO.html > temptbl_vmstat_CPU_$APP.$SID.$SNO.html
mv temptbl_vmstat_CPU_$APP.$SID.$SNO.html tbl_im_Top10_CPU_$APP.$SID.$SNO.html
sed s/myheader3/"Analysis Time: $datestamp"/g tbl_im_Top10_CPU_$APP.$SID.$SNO.html > temptbl_vmstat_CPU_$APP.$SID.$SNO.html
mv temptbl_vmstat_CPU_$APP.$SID.$SNO.html tbl_im_Top10_CPU_$APP.$SID.$SNO.html

# Write to HTML files
echo "<tr><th>User</th><th>PID</th><th>CPU %</th><th>Memory %</th><th>Started</th><th>Time Elapsed</th><th>Command</th></tr>" >> tbl_im_Top10_CPU_$APP.$SID.$SNO.html

i=0
while [ $i -lt 10 ]
do
if [ $debugmode = "debug" ]; then echo "Line number is : $((i+1))" ; fi
USERN=`sed -n $((i+1))p top10cputemp| awk '{print $1}'`
UserPID=`sed -n $((i+1))p top10cputemp | awk '{print $2}'`
CPUpercnt=`sed -n $((i+1))p top10cputemp  | awk '{print $3}'`
MEMpercnt=`sed -n $((i+1))p top10cputemp  | awk '{print $4}'`
time1=`sed -n $((i+1))p top10cputemp  | awk '{print $9}'`
time2=`sed -n $((i+1))p top10cputemp  | awk '{print $10}'`
time3=`sed -n $((i+1))p top10cputemp  | awk '{print $11}'`
Ucommd=`sed -n $((i+1))p top10cputemp  | awk '{print $12}'`
time12="$time1 $time2"

# Write to HTML files
echo "<tr><td>$USERN</td><td>$UserPID</td><td>$CPUpercnt</td><td>$MEMpercnt</td><td>$time12</td><td>$time3</td><td>$Ucommd</td></tr>" >> tbl_im_Top10_CPU_$APP.$SID.$SNO.html

echo ""
i=$(($i+1))
done

# Write to HTML files
echo "</table>" >> tbl_im_Top10_CPU_$APP.$SID.$SNO.html
echo "</body>" >> tbl_im_Top10_CPU_$APP.$SID.$SNO.html
echo "</html>" >> tbl_im_Top10_CPU_$APP.$SID.$SNO.html

rm top10cputemp
mv tbl_im_Top10_CPU_$APP.$SID.$SNO.html monitoringLOGS/$datesh/.

echo "CPU Wait Time Analysis:"
echo "-----------------------"
ps -ekf | grep -v grep | egrep "syncd|lrud|nfsd|biod|wait" | sort -rn +7
echo ""
echo ""

echo "Check Memory Utilization:"
echo "-------------------------"
REALMEMTOT=`lsattr -El sys0 -a realmem | awk '{print $2}'`
echo "Real Memory of Server in KB = " $REALMEMTOT
echo ""
AVM=`awk '/avm/{x=NR+1;next}(NR<=x){print}' tempvmstat | awk '{print $3}'`
FREE=`awk '/fre/{x=NR+1;next}(NR<=x){print}' tempvmstat | awk '{print $4}'`
echo "Average Memory Utilization   = " $AVM
echo "Free Memory Utilization      = " $FREE
echo""

echo "Top Memory Consuming Processes:"
#echo "-------------------------------"
svmon -Pt15 | perl -e 'while(<>){print if($.==2||$&&&!$s++);$.=0 if(/^-+$/)}'
echo ""

rm -r tempvmstat

#Check filesystems
echo ""
echo "Check SAP specific filesystems:"
echo "-------------------------------"
df -gt | grep -i $SID | awk '{$1=""; print $0}'

# Check SMD agents
echo ""
echo "Check SMD agents:"
echo "-----------------"
ps -ef | grep jc. | grep SMDA
echo""

# Check saposcol agaent
echo ""
echo "Check saposcol agaent:"
echo "----------------------"
ps -ef | grep saposcol
echo ""

#Check ABAP Database
if [ $APP = "db" -o $APP = 'DB' ];
   then
        echo ""
        echo "Checking ABAP Database:"
	    echo "-----------------------"
        ps -ef | grep  ora_pmon_ | grep -i -c $SID > /home/users/in10c2/sumit/tempmoni3
        read ORAINSTcount < /home/users/in10c2/sumit/tempmoni3
        if [ $debugmode = "debug" ]; then echo "Number of pmon ps lines returned: " ; cat /home/users/in10c2/sumit/tempmoni3 ; fi
        rm /home/users/in10c2/sumit/tempmoni3
        if [ $debugmode = "debug" ]; then echo "Number of pmon ps lines returned: " $ORAINSTcount ; fi
        if [ $ORAINSTcount -ge 1 ]; then
            echo "Oracle Instance - $SID:       UP"
        else
            echo "Oracle Instance - $SID:       DOWN"
        fi
echo ""
echo ""
#Check DB Backup
echo "Check ABAP DB Backup Status:"
echo "----------------------------"
echo ""
DBbackupFile=`ls /oracle/$SID/sapbackup/*.anf | tail -n 1`
if [ $debugmode = "debug" ]; then echo "Last DB Backup Log file is " ; echo $DBbackupFile ; fi
grep -e 'Start of database backup' $DBbackupFile
grep -e 'End of database backup' $DBbackupFile
tail -n 2 $DBbackupFile
echo ""
echo ""
echo "For more info on DB, login to DB server with ora<sid> and run script moni-server-v.4.0.sh"
fi

#Check JAVA Database
if [ $APP = "jd" -o $APP = 'JD' ];
   then
        echo ""
        echo "Checking JAVA Database:"
        ps -ef | grep  ora_pmon_ | grep -i -c $SID > /home/users/in10c2/sumit/tempmoni3
        read ORAINSTcount < /home/users/in10c2/sumit/tempmoni3
        if [ $debugmode = "debug" ]; then echo "Number of pmon ps lines returned: " ; cat /home/users/in10c2/sumit/tempmoni3 ; fi
        rm /home/users/in10c2/sumit/tempmoni3
        if [ $debugmode = "debug" ]; then echo "Number of pmon ps lines returned: " $ORAINSTcount ; fi
        if [ $ORAINSTcount -ge 1 ]; then
            echo "Oracle Instance - $SID:       UP"
        else
            echo "Oracle Instance - $SID:       DOWN"
        fi
echo ""
echo ""
#Check DB Backup
echo "Check JAVA DB Backup Status:"
echo "----------------------------"
echo ""
DBbackupFile=`ls /oracle/$SID/sapbackup/*.anf | tail -n 1`
if [ $debugmode = "debug" ]; then echo "Last DB Backup Log file is " ; echo $DBbackupFile ; fi
grep -e 'Start of database backup' $DBbackupFile
grep -e 'End of database backup' $DBbackupFile
tail -n 2 $DBbackupFile
echo ""
echo ""
echo "For more info on DB, login to DB server with ora<sid> and run script moni-server-v.4.0.sh"
fi
echo ""


