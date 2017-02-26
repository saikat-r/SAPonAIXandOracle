#!/usr/bin/bash
#Sumit Das 2015 05 21
# Monitoring Script

#Define Variables
APP=$1
SID=$2
SNO=$3
debugmode=$4
if [[ -z $debugmode ]]; then debugmode="nodebug" ; echo $debugmode ; fi
if [ $debugmode = "debug" ]; then echo "$( basename $0 )" ; fi
#LPARLIST1=/home/users/in10c2/sumit/ALL-LPAR-List


#Check OS specifics
echo ""
echo ""
echo "==================================="
echo "Start Monitoring for $APP $SID $SNO"
echo "==================================="
echo ""
echo "Check OS specifications:"
echo "------------------------"
date; hostname; uname -a; oslevel -s;
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
# sleep 3

echo "Check Swap Space:"
echo "-----------------"
lsps -a > templsps
TOTSWP=`more templsps | grep paging | awk '{print $4}'`
USEDSWP=`more templsps | grep paging | awk '{print $5}'`
echo "Total Swap Space          = " $TOTSWP
echo "Swap Space Used in %      = " $USEDSWP
echo ""
rm -f templsps
# sleep 3

vmstat -w >> tempvmstat 2>&1

:<<NONEED2
# Analysis via nmon
nmon -F nmon.$LPAR -c 1
gzip nmon.$LPAR
mv nmon.$LPAR.gz nmonlogs/.
NONEED2

echo "Check CPU Utilization:"
echo "----------------------"
#echo ""
USERCPU=`awk '/us/{x=NR+1;next}(NR<=x){print}' tempvmstat | awk '{print $14}'`
SYSTEM=`awk '/us/{x=NR+1;next}(NR<=x){print}' tempvmstat | awk '{print $15}'`
IDLE=`awk '/us/{x=NR+1;next}(NR<=x){print}' tempvmstat | awk '{print $16}'`
WAIT=`awk '/us/{x=NR+1;next}(NR<=x){print}' tempvmstat | awk '{print $17}'`
echo "User CPU %     =    " $USERCPU
echo "System CPU %   =    " $SYSTEM
echo "IDLE CPU %     =    " $IDLE
echo "WAIT CPU %     =    " $WAIT
echo ""
# sleep 3

echo "Top 10 CPU processes:"
echo "--------------------"
#echo ""
ps aux | head -1; ps aux | sort -rn +2 | head -10
echo ""
# sleep 3

echo "CPU Wait Time Analysis:"
echo "-----------------------"
ps -ekf | grep -v grep | egrep "syncd|lrud|nfsd|biod|wait" | sort -rn +7
echo ""
echo ""
# sleep 3

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
# sleep 3

echo "Top Memory Consuming Processes:"
#echo "-------------------------------"
svmon -Pt15 | perl -e 'while(<>){print if($.==2||$&&&!$s++);$.=0 if(/^-+$/)}'
echo ""
# sleep 3

rm -r tempvmstat

#Check filesystems
echo ""
echo "Check SAP specific filesystems:"
echo "-------------------------------"
df -gt | grep -i $SID | awk '{$1=""; print $0}'
# sleep 3

# Check SMD agents
echo ""
echo "Check SMD agents:"
echo "-----------------"
ps -ef | grep jc. | grep SMDA
echo""
# sleep 3

# Check saposcol agaent
echo ""
echo "Check saposcol agaent:"
echo "----------------------"
ps -ef | grep saposcol
echo ""
# sleep 3

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


