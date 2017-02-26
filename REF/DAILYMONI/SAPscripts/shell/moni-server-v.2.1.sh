#!/usr/bin/bash
#Sumit Das 2015 05 21
# Monitoring Script

#Define Variables
APP=$1
SID=$2
SNO=$3
debugmode=$4
if [[ -z $debugmode ]]; then debugmode="nodebug" ; echo $debugmode ; fi
LPARLIST1=/home/users/in10c2/sumit/ALL-LPAR-List

#Find Customer IP
grep -i $SID $LPARLIST1 > /home/users/in10c2/sumit/tempmoni1
grep -i $APP /home/users/in10c2/sumit/tempmoni1 > /home/users/in10c2/sumit/tempmoni2
count=`more /home/users/in10c2/sumit/tempmoni2 | wc -l`
if [ $debugmode = "debug" ]; then echo $debugmode ; echo "Entries read from LPARLIST: " $count ; fi
read LPAR SIDR INST TYPE VLAN CustIP < /home/users/in10c2/sumit/tempmoni2
if [ $debugmode = "debug" ]; then echo "Entries from LPARLIST: " ; cat /home/users/in10c2/sumit/tempmoni2 ; fi
rm /home/users/in10c2/sumit/tempmoni*
if [ $debugmode = "debug" ]; then
        echo $LPAR
        echo $SIDR
        echo $INST
        echo $TYPE
        echo $VLAN
        echo $CustIP
fi

#Check OS specifics
echo ""
echo "Check OS specifications:"
echo "------------------------"
date; hostname; uname -a; oslevel -s;
uptime > tempuptime
UPDAYS=`more tempuptime | awk '{print $3}'`; # UPDAYS=`echo ${UPDAYS%?}`;
MIN1CPU=`more tempuptime | awk '{print $10}'`; MIN1CPU=`echo ${MIN1CPU%?}`;
MIN5CPU=`more tempuptime | awk '{print $11}'`; MIN5CPU=`echo ${MIN5CPU%?}`;
MIN10CPU=`more tempuptime | awk '{print $12}'`; # MIN10CPU=`echo ${MIN10CPU%?}`;
echo "Server is up for           = " $UPDAYS  "Days"
echo "Last  1 Min. CPU Average Load = " $MIN1CPU
echo "Last  5 Min. CPU Average Load = " $MIN5CPU
echo "Last 10 Min. CPU Average Load = " $MIN10CPU
echo ""
rm -f tempuptime

echo "Check Swap Space:"
echo "-----------------"
lsps -a > templsps
TOTSWP=`more templsps | awk '{print $4}'`
USEDSWP=`more templsps | awk '{print $5}'`
echo "Total Swap Space          = " $TOTSWP
echo "Swap Space Used in %      = " $USEDSWP
echo ""
rm -f templsps


vmstat -w 2>&1 >> tempvmstat
# Analysis via nmon
#nmon -F nmon.$LPAR -c 1
#gzip nmon.$LPAR
#mv nmon.$LPAR.gz nmonlogs/.


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
echo "Top 10 CPU processes:"
echo "--------------------"
#echo ""
ps aux | head -1; ps aux | sort -rn +2 | head -10
echo ""
echo "CPU Wait Time Analysis:"
echo "-----------------------"
ps -ekf | grep -v grep | egrep "syncd|lrud|nfsd|biod|wait" | sort -rn +7
echo ""
echo ""


echo "Check Memory Utilization:"
echo "-------------------------"
lsattr -El sys0 -a realmem
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

#Check Database
if [ $APP = "db" ];
   then
        echo ""
        echo "Checking Database:"
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
fi


exit

