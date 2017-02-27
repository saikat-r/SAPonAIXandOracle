#!/usr/bin/bash
# Sumit Das 2016 10 09
# Last Modified 2017 01 22
# Read DCPAIX list

#echo "Number of Arguments is " $#
#if [ $# -eq 2 ] ; then datestamp=$1 ; debugmode=$2 ; echo "$debugmode mode ON" ; fi
#if [ $# -eq 1 ] ; then datestamp=$1 ; debugmode="nodebug" ; fi
#if [ $# -eq 0 ] ; then datestamp=$(date "+%Y.%m.%d-%H.%M.%S") ; debugmode="nodebug" ; fi
#datestamp=$(date "+%Y.%m.%d-%H.%M.%S")

#set -x
datestamp=$1
debugmode="nodebug"
SHEETname="DCPAIX.$datestamp.VLANsheet.CSV"

SERVTYPE=`more /etc/motd | grep Welcome | awk '{print $3}' | cut -c 1-3`
if [ $SERVTYPE = "dcp" ] ; then CLUSTER=`df -gt / | tail -n 1 | cut -c 48-55` ;
else CLUSTER="APPCOM" ; fi
SERVER_NAME=`uname -n` ;

PHY_SERVER_NAME=`more /etc/motd | grep physical | awk '{print $NF}'` ;
ifconfig -a > IFCNF ; PHY_IP=`awk '/en2:/{x=NR+1;next}(NR<=x){print}' IFCNF | awk '{print $2}'` ; rm IFCNF

SERVER_SLICE=`more /etc/motd | grep slice | awk '{print $NF}'` ;
VLAN_ID=`more /etc/motd | grep VLAN | awk '{print $NF}'` ;

#echo "Start Host data Colleciton on " $PHY_IP
#echo "ABAP CI DATA Collection"
#set -x
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -c 7-9 > /home/users/in10c2/moni/tmp_ABAP_SID
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | cut -d _ -f 2 > /home/users/in10c2/moni/tmp_ABAP_INSTANCE
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ > /home/users/in10c2/moni/tmp_ABAP_HOSTNAMES
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF-1) }' | rev | cut -c 1-2 | rev > /home/users/in10c2/moni/tmp_ABAP_SYS_NR
ps -ef | grep ms.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 4-5 | awk '{print toupper($0)}' > /home/users/in10c2/moni/tmp_ABAP_TYPE

if [ -f /home/users/in10c2/moni/tmp_ABAP_SID ] ; then
i=0
while IFS= read -r line; do
   SID[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_ABAP_SID
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
i=0
while IFS= read -r line; do
   ABAP_INSTANCE[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_ABAP_INSTANCE
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"i=0
i=0
while IFS= read -r line; do
   ABAP_HOSTNAMES[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_ABAP_HOSTNAMES
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"i=0
i=0
while IFS= read -r line; do
   ABAP_SYS_NR[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_ABAP_SYS_NR
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"i=0
i=0
while IFS= read -r line; do
   ABAP_TYPE[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_ABAP_TYPE
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
fi

# SID=( `cat "/home/users/in10c2/moni/tmp_ABAP_SID" ` ) ; #echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
# ABAP_INSTANCE=( `cat "/home/users/in10c2/moni/tmp_ABAP_INSTANCE" ` ) ; #echo ${ABAP_INSTANCE[@]} ; echo ${#ABAP_INSTANCE[@]}
# ABAP_HOSTNAMES=( `cat "/home/users/in10c2/moni/tmp_ABAP_HOSTNAMES" ` ) ; #echo ${ABAP_HOSTNAMES[@]} ; echo ${#ABAP_HOSTNAMES[@]}
# ABAP_SYS_NR=( `cat "/home/users/in10c2/moni/tmp_ABAP_SYS_NR" ` ) ; #echo ${ABAP_SYS_NR[@]} ; echo ${#ABAP_SYS_NR[@]}
# ABAP_TYPE=( `cat "/home/users/in10c2/moni/tmp_ABAP_TYPE" ` ) ; #echo ${ABAP_TYPE[@]} ; echo ${#ABAP_TYPE[@]}

rm -f /home/users/in10c2/moni/tmp_CUST_IP
for LINE in "${ABAP_HOSTNAMES[@]}"
do
        ping -c 1 $LINE | grep PING | awk '{print $3}' | rev | cut -c3- | rev | cut -c2- >> /home/users/in10c2/moni/tmp_CUST_IP
done
if [ -f /home/users/in10c2/moni/tmp_CUST_IP ]; then 
i=0
while IFS= read -r line; do
   CUST_IP[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_CUST_IP
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
fi

i=0
while [ $i -lt "${#SID[@]}" ]
do
        TYPE=`echo "${ABAP_TYPE[$i]}"` ; SYSSID=`echo "${SID[$i]}"` ; NR=`echo "${ABAP_SYS_NR[$i]}"` ;
        SERVICE_NAME=$SYSSID"_"$NR"_"$TYPE
        IP=`echo "${CUST_IP[$i]}"` ; INST=`echo "${ABAP_INSTANCE[$i]}"` ;
        if [ $TYPE = "JI" ] ; then INST=`ps -ef | grep ig.sap | grep pf | grep -v DV | awk '{ print $(NF) }' | cut -d _ -f 2` ; fi
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST >> /home/users/in10c2/sumit/VLANmap/$SHEETname.CSV
        (( i += 1 ))
done

#echo "ABAP APP SE DATA Collection"
#set -x
ps -ef | grep se.sap | grep pf | awk '{ print $(NF-2) }' | cut -c 7-9 > /home/users/in10c2/moni/tmp_ABAP_SID_SE
ps -ef | grep se.sap | grep pf | awk '{ print $(NF-2) }' | cut -d _ -f 2 > /home/users/in10c2/moni/tmp_ABAP_INSTANCE_SE
ps -ef | grep se.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ > /home/users/in10c2/moni/tmp_ABAP_HOSTNAMES_SE
ps -ef | grep se.sap | grep pf | awk '{ print $(NF-1) }' | cut -f 3 -d _ > /home/users/in10c2/moni/tmp_ABAP_HOSTNAMES_SE_1
ps -ef | grep se.sap | grep pf | awk '{ print $(NF-2) }' | rev | cut -c 1-2 | rev > /home/users/in10c2/moni/tmp_ABAP_SYS_NR_SE
ps -ef | grep se.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 4-5 | awk '{print toupper($0)}' > /home/users/in10c2/moni/tmp_ABAP_TYPE_SE
ps -ef | grep se.sap | grep pf | awk '{ print $(NF-1) }' | cut -f 3 -d _ | cut -c 4-5 | awk '{print toupper($0)}' > /home/users/in10c2/moni/tmp_ABAP_TYPE_SE_1


if [ -f /home/users/in10c2/moni/tmp_ABAP_SID_SE ] ; then
i=0
while IFS= read -r line; do
   SID_SE[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_ABAP_SID_SE
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
i=0
while IFS= read -r line; do
   ABAP_INSTANCE_SE[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_ABAP_INSTANCE_SE
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"i=0
i=0
#set -x
while IFS= read -r line; do
  if [ $line != "-F" ] ; then
   ABAP_HOSTNAMES_SE[$i]="$line" ;   (( i += 1 )) ;
  fi 
done < /home/users/in10c2/moni/tmp_ABAP_HOSTNAMES_SE
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"i=0
i=0
while IFS= read -r line; do
  if [ $line != "-F" ] ; then
   ABAP_HOSTNAMES_SE[$i]="$line" ;   (( i += 1 )) ;
  fi 
done < /home/users/in10c2/moni/tmp_ABAP_HOSTNAMES_SE_1
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"i=0
#set +x
i=0
while IFS= read -r line; do
   ABAP_SYS_NR_SE[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_ABAP_SYS_NR_SE
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"i=0
i=0
while IFS= read -r line; do
   if [ $line != "-F" ] ; then
   ABAP_TYPE_SE[$i]="$line" ;   (( i += 1 )) ;
  fi
done < /home/users/in10c2/moni/tmp_ABAP_TYPE_SE
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
while IFS= read -r line; do
   if [ $line != "-F" ] ; then
   ABAP_TYPE_SE[$i]="$line" ;   (( i += 1 )) ;
  fi
done < /home/users/in10c2/moni/tmp_ABAP_TYPE_SE_1
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
fi


# SID_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_SID_SE" ` ) ; #echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
# ABAP_INSTANCE_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_INSTANCE_SE" ` ) ; #echo ${ABAP_INSTANCE[@]} ; echo ${#ABAP_INSTANCE[@]}
# ABAP_HOSTNAMES_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_HOSTNAMES_SE" ` ) ; #echo ${ABAP_HOSTNAMES[@]} ; echo ${#ABAP_HOSTNAMES[@]}
# ABAP_SYS_NR_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_SYS_NR_SE" ` ) ; #echo ${ABAP_SYS_NR[@]} ; echo ${#ABAP_SYS_NR[@]}
# ABAP_TYPE_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_TYPE_SE" ` ) ; #echo ${ABAP_TYPE[@]} ; echo ${#ABAP_TYPE[@]}

rm -f /home/users/in10c2/moni/tmp_CUST_IP_SE
for LINE in "${ABAP_HOSTNAMES_SE[@]}"
do
        ping -c 1 $LINE | grep PING | awk '{print $3}' | rev | cut -c3- | rev | cut -c2- >> /home/users/in10c2/moni/tmp_CUST_IP_SE
done
if [ -f /home/users/in10c2/moni/tmp_CUST_IP_SE ]; then 
i=0
while IFS= read -r line; do
   CUST_IP_SE[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_CUST_IP_SE
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
fi

i=0
while [ $i -lt "${#SID_SE[@]}" ]
do
        if [ "${ABAP_INSTANCE_SE[$i]}" != "${ABAP_INSTANCE[$i]}" ]
        then
        TYPE=`echo "${ABAP_TYPE_SE[$i]}"` ; SYSSID=`echo "${SID_SE[$i]}"` ; NR=`echo "${ABAP_SYS_NR_SE[$i]}"` ;
        SERVICE_NAME=$SYSSID"_"$NR"_"$TYPE
        IP=`echo "${CUST_IP_SE[$i]}"` ; INST=`echo "${ABAP_INSTANCE_SE[$i]}"` ;
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST >> /home/users/in10c2/sumit/VLANmap/$SHEETname.CSV
        (( i += 1 ))
        else
        (( i += 1 ))
        fi
done

#echo "ABAP APP IG DATA Collection"
#set -x
ps -ef | grep ig.sap | grep pf | awk '{ print $(NF-2) }' | cut -c 7-9 > /home/users/in10c2/moni/tmp_ABAP_SID_IG
ps -ef | grep ig.sap | grep pf | awk '{ print $(NF-2) }' | cut -d _ -f 2 > /home/users/in10c2/moni/tmp_ABAP_INSTANCE_IG
ps -ef | grep ig.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ > /home/users/in10c2/moni/tmp_ABAP_HOSTNAMES_IG
ps -ef | grep ig.sap | grep pf | awk '{ print $(NF-1) }' | cut -f 3 -d _ > /home/users/in10c2/moni/tmp_ABAP_HOSTNAMES_IG_1
ps -ef | grep ig.sap | grep pf | awk '{ print $(NF-2) }' | rev | cut -c 1-2 | rev > /home/users/in10c2/moni/tmp_ABAP_SYS_NR_IG
ps -ef | grep ig.sap | grep pf | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 4-5 | awk '{print toupper($0)}' > /home/users/in10c2/moni/tmp_ABAP_TYPE_IG


if [ -f /home/users/in10c2/moni/tmp_ABAP_SID_IG ] ; then
i=0
while IFS= read -r line; do
   SID_IG_IG[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_ABAP_SID_IG
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
i=0
while IFS= read -r line; do
   ABAP_INSTANCE_IG[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_ABAP_INSTANCE_IG
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"i=0
#set -x
i=0
while IFS= read -r line; do
  if [[ $line != -m* ]] ; then
   ABAP_HOSTNAMES_IG[$i]="$line" ;   (( i += 1 )) ;
  fi
done < /home/users/in10c2/moni/tmp_ABAP_HOSTNAMES_IG
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"i=0
i=0
while IFS= read -r line; do
  if [[ $line != -m* ]] ; then
   ABAP_HOSTNAMES_IG[$i]="$line" ;   (( i += 1 )) ;
  fi
done < /home/users/in10c2/moni/tmp_ABAP_HOSTNAMES_IG_1
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"i=0
#set +x
i=0
while IFS= read -r line; do
   ABAP_SYS_NR_IG[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_ABAP_SYS_NR_IG
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"i=0
i=0
while IFS= read -r line; do
   ABAP_TYPE_IG[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_ABAP_TYPE_IG
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
fi


# SID_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_SID_SE" ` ) ; #echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
# ABAP_INSTANCE_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_INSTANCE_SE" ` ) ; #echo ${ABAP_INSTANCE[@]} ; echo ${#ABAP_INSTANCE[@]}
# ABAP_HOSTNAMES_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_HOSTNAMES_SE" ` ) ; #echo ${ABAP_HOSTNAMES[@]} ; echo ${#ABAP_HOSTNAMES[@]}
# ABAP_SYS_NR_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_SYS_NR_SE" ` ) ; #echo ${ABAP_SYS_NR[@]} ; echo ${#ABAP_SYS_NR[@]}
# ABAP_TYPE_SE=( `cat "/home/users/in10c2/moni/tmp_ABAP_TYPE_SE" ` ) ; #echo ${ABAP_TYPE[@]} ; echo ${#ABAP_TYPE[@]}

rm -f /home/users/in10c2/moni/tmp_CUST_IP_IG
for LINE in "${ABAP_HOSTNAMES_IG[@]}"
do
        ping -c 1 $LINE | grep PING | awk '{print $3}' | rev | cut -c3- | rev | cut -c2- >> /home/users/in10c2/moni/tmp_CUST_IP_IG
done
if [ -f /home/users/in10c2/moni/tmp_CUST_IP_IG ]; then 
i=0
while IFS= read -r line; do
   CUST_IP_IG[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_CUST_IP_IG
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
fi

i=0
while [ $i -lt "${#SID_IG[@]}" ]
do
        if [ "${ABAP_INSTANCE_IG[$i]}" != "${ABAP_INSTANCE[$i]}" ]
        then
        TYPE=`echo "${ABAP_TYPE_IG[$i]}"` ; SYSSID=`echo "${SID_IG[$i]}"` ; NR=`echo "${ABAP_SYS_NR_IG[$i]}"` ;
        SERVICE_NAME=$SYSSID"_"$NR"_"$TYPE
        IP=`echo "${CUST_IP_IG[$i]}"` ; INST=`echo "${ABAP_INSTANCE_IG[$i]}"` ;
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST >> /home/users/in10c2/sumit/VLANmap/$SHEETname.CSV
        (( i += 1 ))
        else
        (( i += 1 ))
        fi
done

#echo "JAVA CI DATA Collection"
#set -x
ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF-1) }' | cut -c 7-9 > /home/users/in10c2/moni/tmp_JAVA_SID
ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF-1) }' | cut -d _ -f 2 > /home/users/in10c2/moni/tmp_JAVA_INSTANCE
ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF) }' | cut -f 3 -d _ > /home/users/in10c2/moni/tmp_JAVA_HOSTNAMES
ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF-1) }' | rev | cut -c 1-2 | rev > /home/users/in10c2/moni/tmp_JAVA_SYS_NR
ps -ef | grep jc.sap | grep pf | grep -v SMD | awk '{ print $(NF) }' | cut -f 3 -d _ | cut -c 4-5 | awk '{print toupper($0)}' > /home/users/in10c2/moni/tmp_JAVA_TYPE

# SID_JC=( `cat "/home/users/in10c2/moni/tmp_JAVA_SID" ` ) ; #echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
# JAVA_INSTANCE=( `cat "/home/users/in10c2/moni/tmp_JAVA_INSTANCE" ` ) ; #echo ${ABAP_INSTANCE[@]} ; echo ${#ABAP_INSTANCE[@]}
# JAVA_HOSTNAMES=( `cat "/home/users/in10c2/moni/tmp_JAVA_HOSTNAMES" ` ) ; #echo ${ABAP_HOSTNAMES[@]} ; echo ${#ABAP_HOSTNAMES[@]}
# JAVA_SYS_NR=( `cat "/home/users/in10c2/moni/tmp_JAVA_SYS_NR" ` ) ; #echo ${ABAP_SYS_NR[@]} ; echo ${#ABAP_SYS_NR[@]}
# JAVA_TYPE=( `cat "/home/users/in10c2/moni/tmp_JAVA_TYPE" ` ) ; #echo ${ABAP_TYPE[@]} ; echo ${#ABAP_TYPE[@]}

rm -f /home/users/in10c2/moni/tmp_CUST_IP_JC
for LINE in "${JAVA_HOSTNAMES[@]}"
do
        ping -c 1 $LINE | grep PING | awk '{print $3}' | rev | cut -c3- | rev | cut -c2- >> /home/users/in10c2/moni/tmp_CUST_IP_JC
done
if [ -f /home/users/in10c2/moni/tmp_CUST_IP_JC ]; then 
i=0
while IFS= read -r line; do
   CUST_IP_JC[$i]="$line" ;   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_CUST_IP_JC
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
fi

i=0
while [ $i -lt "${#SID_JC[@]}" ]
do
        TYPE=`echo "${JAVA_TYPE[$i]}"` ; SYSSID=`echo "${SID_JC[$i]}"` ; NR=`echo "${JAVA_SYS_NR[$i]}"` ;
        SERVICE_NAME=$SYSSID"_"$NR"_"$TYPE
        IP=`echo "${/home/users/in10c2/moni/tmp_CUST_IP_JC[$i]}"` ; INST=`echo "${JAVA_INSTANCE[$i]}"` ;
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST >> /home/users/in10c2/sumit/VLANmap/$SHEETname.CSV
         (( i += 1 ))
done


#echo "Oracle DB DATA Collection"
#set -x
rm -f /home/users/in10c2/moni/tmp_SID_DB
ps -ef | grep tns | grep -v grep | awk '{print $(NF-1)}' | cut -f 2 -d _ > /home/users/in10c2/moni/tmp_SID_DB
if [ -f /home/users/in10c2/moni/tmp_SID_DB ] ; then
i=0
while IFS= read -r line; do
   SID_DB[$i]="$line" ;   
   SID_DB_LO[$i]=`echo "$SID_DB" | awk '{print tolower($0)}'` ;
   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_SID_DB
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
fi

i=0
while [ $i -lt "${#SID_DB[@]}" ]
do
        SYSSID=`echo "${SID_DB[$i]}"`
        DBHOST=`grep ^SAPDBHOST /sapmnt/$SYSSID/profile/DEFAULT.PFL | awk '{print ($NF)}'`
        TYPE=`echo "$DBHOST" | cut -c 4-5 | awk '{print toupper($0)}'`
        NR=`echo "$DBHOST" | cut -c 9-10`
        SERVICE_NAME=$SYSSID"_"$NR"_"$TYPE
        INST="DB"
        IP=`ping -c 1 $DBHOST | grep PING | awk '{print $3}' | rev | cut -c3- | rev | cut -c2-`
        CUST_IP_DB=$IP
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST >> /home/users/in10c2/sumit/VLANmap/$SHEETname.CSV
         (( i += 1 ))
done

rm -rf /home/users/in10c2/moni/tmp_*

#echo "Live Cache System Data Collection"
#set -x
rm -f /home/users/in10c2/moni/tmp_SID_LC
ps -ef | grep sdb | grep dbmsrv | awk '{print $(NF-2)}' | cut -c 8-10 > /home/users/in10c2/moni/tmp_SID_LC
if [ -f /home/users/in10c2/moni/tmp_SID_LC ] ; then
i=0
while IFS= read -r line; do
   SID_LC[$i]="$line" ;   
   SID_LC_LO[$i]=`echo "$SID_LC" | awk '{print tolower($0)}'` ;
   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_SID_LC
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
fi

i=0
while [ $i -lt "${#SID_LC[@]}" ]
do
        SYSSID=`echo "${SID_LC[$i]}"`
        LCsearch="linlc"$SYSSID
        DBHOST=`grep -i $LCsearch /etc/hosts | head -n 1 | awk '{print ($NF)}'`
        TYPE=`echo "$DBHOST" | cut -c 4-5 | awk '{print toupper($0)}'`
        NR=`echo "$DBHOST" | cut -c 9-10`
        SERVICE_NAME=$SYSSID"_"$NR"_"$TYPE
        INST="LC"
        IP=`ping -c 1 $DBHOST | grep PING | awk '{print $3}' | rev | cut -c3- | rev | cut -c2-`
        CUST_IP_DB=$IP
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST >> /home/users/in10c2/sumit/VLANmap/$SHEETname.CSV
         (( i += 1 ))
done


#echo "TREX System Data Collection"
#set -x
rm -f /home/users/in10c2/moni/tmp_SID_TX
ps -ef | grep TREXDaemon | grep ini | awk '{print $(NF)}' | cut -d _ -f 1 | rev | cut -c 1-3 | rev > /home/users/in10c2/moni/tmp_SID_TX
ps -ef | grep TREXDaemon | grep ini | awk '{print $(NF)}' | cut -d _ -f 2 > /home/users/in10c2/moni/tmp_INST_TX
ps -ef | grep TREXDaemon | grep ini | awk '{print $(NF)}' | cut -d _ -f 3 > /home/users/in10c2/moni/tmp_HOSTNAMES_TX
if [ -f /home/users/in10c2/moni/tmp_SID_TX ] ; then
i=0
while IFS= read -r line; do
   SID_TX[$i]="$line" ;   
   SID_TX_LO[$i]=`echo "$SID_TX" | awk '{print tolower($0)}'` ;
   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_SID_TX
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
fi
if [ -f /home/users/in10c2/moni/tmp_INST_TX ] ; then
i=0
while IFS= read -r line; do
   INST_TX[$i]="$line" ;   
   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_INST_TX
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
fi
if [ -f /home/users/in10c2/moni/tmp_HOSTNAMES_TX ] ; then
i=0
while IFS= read -r line; do
   TREX_HOSTNAMES[$i]="$line" ;   
   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_HOSTNAMES_TX
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
fi

i=0
while [ $i -lt "${#SID_TX[@]}" ]
do
        SYSSID=`echo "${SID_TX[$i]}"`
        TXHOST=`echo "${TREX_HOSTNAMES[$i]}"`
        TYPE=`echo "$TXHOST" | cut -c 4-5 | awk '{print toupper($0)}'`
        NR=`echo "$TXHOST" | cut -c 9-10`
        SERVICE_NAME=$SYSSID"_"$NR"_"$TYPE
        IP=`ping -c 1 $TXHOST | grep PING | awk '{print $3}' | rev | cut -c3- | rev | cut -c2-`
        INST=`echo "${INST_TX[$i]}"`
        CUST_IP_DB=$IP
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST >> /home/users/in10c2/sumit/VLANmap/$SHEETname.CSV
         (( i += 1 ))
done


#echo "CUPs Printing Data Collection"
#set -x
rm -f /home/users/in10c2/moni/tmp_HOST_CUPs
ps -ef | grep cupsd | grep -v grep | grep -v spool | awk '{print $(NF)}' | cut -d/ -f6 > /home/users/in10c2/moni/tmp_HOST_CUPs
if [ -f /home/users/in10c2/moni/tmp_HOST_CUPs ] ; then
i=0
while IFS= read -r line; do
   CUPS_HOSTNAME[$i]="$line" ;   
   (( i += 1 )) ;
done < /home/users/in10c2/moni/tmp_HOST_CUPs
#echo ${SID[@]} ; echo ${#SID[@]} ; echo "${SID[2]}"
fi

i=0
while [ $i -lt "${#CUPS_HOSTNAME[@]}" ]
do
        SYSSID="CUP"
        CUPsHOST="`echo "${CUPS_HOSTNAME[$i]}"`"
        TYPE="CP"
        NR=`echo "$CUPsHOST" | cut -c 9-10`
        SERVICE_NAME=$SYSSID"_"$NR"_"$TYPE
        INST="CUPs"
        IP=`ping -c 1 $CUPsHOST | grep PING | awk '{print $3}' | rev | cut -c3- | rev | cut -c2-`
        CUST_IP_DB=$IP
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST
        echo $SERVTYPE,$CLUSTER,$SERVER_NAME,$PHY_SERVER_NAME,$PHY_IP,$SERVER_SLICE,$VLAN_ID,$SERVICE_NAME,$IP,$INST >> /home/users/in10c2/sumit/VLANmap/$SHEETname.CSV
         (( i += 1 ))
done

rm -rf /home/users/in10c2/moni/tmp_*
