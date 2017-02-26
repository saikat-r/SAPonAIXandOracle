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


REPORT_DIR=/usr/sap/scratch/DAILYMONI/reports
#SCRIPT_DIRECTORY=/usr/sap/scratch/MONITORING_SCRIPT/

REPORT_NAME_RAM=$REPORT_DIR/"RAM_"$SERVICE_NAME".html"
RAM_GRN_THRES=60
RAM_RED_THRES=90


#==========================================================================================================================
#CPU/MEMORY RELATED
#==========================================================================================================================

OS_RAM_TOTAL=$(svmon -G -O unit=GB | tail -n 6 | head -n 1| awk '{print $2}')
OS_RAM_GRN_THRES=$(svmon -G -O unit=GB | tail -n 6 | head -n 1| awk '{print $2*'$RAM_GRN_THRES'/100}')
OS_RAM_RED_THRES=$(svmon -G -O unit=GB | tail -n 6 | head -n 1| awk '{print $2*'$RAM_RED_THRES'/100}')

OS_RAM_UTLZD=$(svmon -G -O unit=GB | tail -n 6 | head -n 1| awk '{print $3}')
OS_RAM_FREE=$(svmon -G -O unit=GB | tail -n 6 | head -n 1| awk '{print $4}')

OS_CPU_USER=$(lparstat | tail -1 | awk '{print $1}')
OS_CPU_SYS=$(lparstat | tail -1 | awk '{print $2}')
OS_CPU_WAIT=$(lparstat | tail -1 | awk '{print $3}')
OS_CPU_IDLE=$(lparstat | tail -1 | awk '{print $4}')


#====================================================================================================
#
# CANVAS SECTION FOR MEMORY UTILIZATION
#
#====================================================================================================


echo $OS_RAM_UTLZD
echo $OS_RAM_GRN_THRES


echo '<canvas id="myCanvas2" width="300" height="200" style="border:1px solid #34495e; background-color:#34495e">' > $REPORT_NAME_RAM
echo "Your browser does not support the canvas element." >> $REPORT_NAME_RAM
echo "</canvas>" >> $REPORT_NAME_RAM


#=================


if [[ "$OS_RAM_TOTAL" -lt 15 ]]

then

#MEMORY UTILIZED <RAM> --> Green Section

if [[ "$OS_RAM_UTLZD" -le "$OS_RAM_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*17",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*17",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*17",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*17",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM




#MEMORY UTILIZED <RAM> --> Red Section

elif [[ "$OS_RAM_UTLZD" -gt "$OS_RAM_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*17",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*17",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*17",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*17",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

else

#MEMORY UTILIZED <RAM> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*17",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*17",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*17",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*17",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

fi


fi





if [[ "$OS_RAM_TOTAL" -ge 15 && "$OS_RAM_TOTAL" -lt 25 ]]

then

#MEMORY UTILIZED <RAM> --> Green Section

if [[ "$OS_RAM_UTLZD" -le "$OS_RAM_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*10",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*10",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*10",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*10",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM




#MEMORY UTILIZED <RAM> --> Red Section

elif [[ "$OS_RAM_UTLZD" -gt "$OS_RAM_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*10",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*10",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*10",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*10",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

else

#MEMORY UTILIZED <RAM> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*10",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*10",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*10",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*10",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

fi


fi


if [[ "$OS_RAM_TOTAL" -ge 25 && "$OS_RAM_TOTAL" -lt 40 ]]

then

#MEMORY UTILIZED <RAM> --> Green Section

if [[ "$OS_RAM_UTLZD" -le "$OS_RAM_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*7",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*7",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*7",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*7",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM




#MEMORY UTILIZED <RAM> --> Red Section

elif [[ "$OS_RAM_UTLZD" -gt "$OS_RAM_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*7",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*7",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*7",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*7",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

else

#MEMORY UTILIZED <RAM> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*7",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*7",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*7",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*7",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

fi


fi


if [[ "$OS_RAM_TOTAL" -ge 40 && "$OS_RAM_TOTAL" -lt 55 ]]

then

#MEMORY UTILIZED <RAM> --> Green Section

if [[ "$OS_RAM_UTLZD" -le "$OS_RAM_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*4",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*4",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*4",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*4",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM




#MEMORY UTILIZED <RAM> --> Red Section

elif [[ "$OS_RAM_UTLZD" -gt "$OS_RAM_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*4",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*4",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*4",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*4",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

else

#MEMORY UTILIZED <RAM> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*4",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*4",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*4",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*4",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

fi


fi


if [[ "$OS_RAM_TOTAL" -ge 55 && "$OS_RAM_TOTAL" -lt 75 ]]

then

#MEMORY UTILIZED <RAM> --> Green Section

if [[ "$OS_RAM_UTLZD" -le "$OS_RAM_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*3",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*3",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*3",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*3",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM




#MEMORY UTILIZED <RAM> --> Red Section

elif [[ "$OS_RAM_UTLZD" -gt "$OS_RAM_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*3",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*3",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*3",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*3",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

else

#MEMORY UTILIZED <RAM> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*3",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*3",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*3",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*3",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

fi


fi



if [[ "$OS_RAM_TOTAL" -ge 75 && "$OS_RAM_TOTAL" -lt 140 ]]

then

#MEMORY UTILIZED <RAM> --> Green Section

if [[ "$OS_RAM_UTLZD" -le "$OS_RAM_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*2",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*2",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*2",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*2",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM




#MEMORY UTILIZED <RAM> --> Red Section

elif [[ "$OS_RAM_UTLZD" -gt "$OS_RAM_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*2",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*2",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*2",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*2",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

else

#MEMORY UTILIZED <RAM> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL*2",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD*2",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD*2",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL*2",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

fi


fi




if [[ "$OS_RAM_TOTAL" -ge 140 && "$OS_RAM_TOTAL" -lt 300 ]]

then

#MEMORY UTILIZED <RAM> --> Green Section

if [[ "$OS_RAM_UTLZD" -le "$OS_RAM_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM




#MEMORY UTILIZED <RAM> --> Red Section

elif [[ "$OS_RAM_UTLZD" -gt "$OS_RAM_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

else

#MEMORY UTILIZED <RAM> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

fi


fi


if [[ "$OS_RAM_TOTAL" -ge 300 ]]

then

#MEMORY UTILIZED <RAM> --> Green Section

if [[ "$OS_RAM_UTLZD" -le "$OS_RAM_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL/2",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD/2",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD/2",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL/2",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM




#MEMORY UTILIZED <RAM> --> Red Section

elif [[ "$OS_RAM_UTLZD" -gt "$OS_RAM_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL/2",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD/2",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD/2",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL/2",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

else

#MEMORY UTILIZED <RAM> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_TOTAL/2",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo "ctx.fillRect(1,1,"$OS_RAM_UTLZD/2",40);" >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_FREE""GB" '"'","$OS_RAM_UTLZD/2",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"  ""$OS_RAM_TOTAL""GB" '"'","$OS_RAM_TOTAL/2",25,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

fi


fi






echo  "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#85c1e9";' >> $REPORT_NAME_RAM
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"TOTAL RAM SIZE: ""$OS_RAM_TOTAL""GB" '"'",1,80,250,8);" >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"UTILIZED RAM SIZE: ""$OS_RAM_UTLZD""GB" '"'",1,95,250,8);" >> $REPORT_NAME_RAM
echo "ctx.fillText("'"'"FREE RAM SIZE: ""$OS_RAM_FREE""GB" '"'",1,110,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM


echo "<script>" >> $REPORT_NAME_RAM
echo 'var canvas = document.getElementById("myCanvas2");' >> $REPORT_NAME_RAM
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_RAM
echo 'ctx.fillStyle = "#85c1e9";' >> $REPORT_NAME_RAM
echo 'ctx.font = "20px Arial";' >> $REPORT_NAME_RAM
echo "ctx.fillText('"'RAM UTILIZATION'"',60,170,250,8);" >> $REPORT_NAME_RAM
echo "</script>" >> $REPORT_NAME_RAM

