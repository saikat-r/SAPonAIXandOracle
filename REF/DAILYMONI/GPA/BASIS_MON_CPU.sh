#!/bin/ksh

typeset CALLER="$(id | sed 's/[^(]*(//;s/).*//')"
SCNAME=$0
SVNAME=${SCNAME%.*}
DIRNAME=`dirname $0`
#DIRNAME=`pwd`
CFGFILE=${SVNAME}.config
CFGTEMP="/tmp/"`basename ${CFGFILE}`".temp"
egrep -v '^[ ]*#|^$' $CFGFILE | awk '{ print $1 " " $2 }' | sed -e 's/ $//' > $CFGTEMP
. $CFGTEMP


#SCRIPT_DIRECTORY=/usr/sap/scratch/MONITORING_SCRIPT/
REPORT_DIR=/usr/sap/scratch/DAILYMONI/reports


REPORT_NAME_CPU=$REPORT_DIR/"CPU_"$SERVICE_NAME".html"


CPU_GRN_THRES=60
CPU_RED_THRES=90


#==========================================================================================================================
#CPU/MEMORY RELATED
#==========================================================================================================================

OS_CPU_TOTAL=100
OS_CPU_USER=$(lparstat | tail -n 1 | awk '{print $1}')
OS_CPU_SYS=$(lparstat | tail -n 1 | awk '{print $2}')
OS_CPU_WAIT=$(lparstat | tail -n 1 | awk '{print $3}')
OS_CPU_IDLE=$(lparstat | tail -n 1 | awk '{print $4}')

OS_CPU_SYS_POS=$(echo "scale=2;($OS_CPU_USER*2.5)+1" | bc)
OS_CPU_WAIT_POS=$(echo "scale=2;(($OS_CPU_USER*2.5)+($OS_CPU_SYS*2.5))+1" | bc)


#====================================================================================================
#
# CANVAS SECTION FOR CPU UTILIZATION
#
#====================================================================================================


echo '<canvas id="myCanvas4" width="300" height="200" style="border:1px solid #34495e; background-color:#34495e">' > $REPORT_NAME_CPU
echo "Your browser does not support the canvas element." >> $REPORT_NAME_CPU
echo "</canvas>" >> $REPORT_NAME_CPU



echo "<script>" >> $REPORT_NAME_CPU
echo 'var canvas = document.getElementById("myCanvas4");' >> $REPORT_NAME_CPU
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_CPU
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_CPU
echo "ctx.fillRect(1,1,"$OS_CPU_TOTAL*2.5",40);" >> $REPORT_NAME_CPU
echo "ctx.fillRect(1,72,8,8);" >> $REPORT_NAME_CPU
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_CPU
echo "ctx.fillText("'"'"CPU IDLE: ""$OS_CPU_IDLE""%" '"'",10,80,250,8);" >> $REPORT_NAME_CPU
echo "</script>" >> $REPORT_NAME_CPU

echo "<script>" >> $REPORT_NAME_CPU
echo 'var canvas = document.getElementById("myCanvas4");' >> $REPORT_NAME_CPU
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_CPU
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_CPU
echo "ctx.fillRect(1,1,"$OS_CPU_USER*2.5",40);" >> $REPORT_NAME_CPU
echo "ctx.fillRect(1,87,8,8);" >> $REPORT_NAME_CPU
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_CPU
echo "ctx.fillText("'"'"CPU UTILIZATION USER: ""$OS_CPU_USER""%" '"'",10,95,250,8);" >> $REPORT_NAME_CPU
echo "</script>" >> $REPORT_NAME_CPU

echo "<script>" >> $REPORT_NAME_CPU
echo 'var canvas = document.getElementById("myCanvas4");' >> $REPORT_NAME_CPU
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_CPU
echo 'ctx.fillStyle = "#d7bde2";' >> $REPORT_NAME_CPU
echo "ctx.fillRect("$OS_CPU_SYS_POS",1,"$OS_CPU_SYS*2.5",40);" >> $REPORT_NAME_CPU
echo "ctx.fillRect(1,102,8,8);" >> $REPORT_NAME_CPU
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_CPU
echo "ctx.fillText("'"'"CPU UTILIZATION SYSTEM: ""$OS_CPU_SYS""%" '"'",10,110,250,8);" >> $REPORT_NAME_CPU
echo "</script>" >> $REPORT_NAME_CPU


echo "<script>" >> $REPORT_NAME_CPU
echo 'var canvas = document.getElementById("myCanvas4");' >> $REPORT_NAME_CPU
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_CPU
echo 'ctx.fillStyle = " #f1c40f";' >> $REPORT_NAME_CPU
echo "ctx.fillRect("$OS_CPU_WAIT_POS",1,"$OS_CPU_WAIT*2.5",40);" >> $REPORT_NAME_CPU
echo "ctx.fillRect(1,117,8,8);" >> $REPORT_NAME_CPU
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_CPU
echo "ctx.fillText("'"'"CPU WAIT: ""$OS_CPU_WAIT""%" '"'",10,125,250,8);" >> $REPORT_NAME_CPU
echo "</script>" >> $REPORT_NAME_CPU








echo "<script>" >> $REPORT_NAME_CPU
echo 'var canvas = document.getElementById("myCanvas4");' >> $REPORT_NAME_CPU
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_CPU
echo 'ctx.fillStyle = "#85c1e9";' >> $REPORT_NAME_CPU
echo 'ctx.font = "20px Arial";' >> $REPORT_NAME_CPU
echo "ctx.fillText('"'CPU UTILIZATION'"',60,170,250,8);" >> $REPORT_NAME_CPU
echo "</script>" >> $REPORT_NAME_CPU

