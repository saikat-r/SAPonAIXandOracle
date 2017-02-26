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


REPORT_NAME_SWAP=$REPORT_DIR/"SWAP_"$SERVICE_NAME".html"
echo $REPORT_NAME_SWAP

OS_SWAP_GRN_THRES=60
OS_SWAP_RED_THRES=90


#==========================================================================================================================
#CPU/MEMORY RELATED
#==========================================================================================================================

OS_SWAP_TOTAL=$(lsps -s | tail -n 1 | awk '{print $1}' | cut -f 1,3 -d MB | awk '{print $1/1024}')

OS_SWAP_USED_PERCENTAGE=$(lsps -s | tail -n 1 | awk '{print $2}' | cut -f 1,3 -d %)

#OS_SWAP_GRN_THRES=$($SWAP_GRN_THRES)
#OS_SWAP_RED_THRES=$($SWAP_RED_THRES)

OS_SWAP_UTLZD=$(echo "scale=2;($OS_SWAP_TOTAL*$OS_SWAP_USED_PERCENTAGE)/100" | bc)
OS_SWAP_FREE=$(echo "scale=2;$OS_SWAP_TOTAL-$OS_SWAP_UTLZD" | bc)



#====================================================================================================
#
# CANVAS SECTION FOR SWAP MEMORY UTILIZATION
#
#====================================================================================================


echo $OS_SWAP_UTLZD
echo $OS_SWAP_GRN_THRES


echo '<canvas id="myCanvas3" width="300" height="200" style="border:1px solid #34495e; background-color:#34495e">' > $REPORT_NAME_SWAP
echo "Your browser does not support the canvas element." >> $REPORT_NAME_SWAP
echo "</canvas>" >> $REPORT_NAME_SWAP


#=================


if [[ "$OS_SWAP_TOTAL" -lt 15 ]]

then

#MEMORY UTILIZED <SWAP> --> Green Section

if [[ "$OS_SWAP_UTLZD" -le "$OS_SWAP_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*17",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*17",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*17",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*17",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP




#MEMORY UTILIZED <SWAP> --> Red Section

elif [[ "$OS_SWAP_UTLZD" -gt "$OS_SWAP_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*17",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*17",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*17",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*17",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

else

#MEMORY UTILIZED <SWAP> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*17",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*17",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*17",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*17",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

fi


fi





if [[ "$OS_SWAP_TOTAL" -ge 15 && "$OS_SWAP_TOTAL" -lt 25 ]]

then

#MEMORY UTILIZED <SWAP> --> Green Section

if [[ "$OS_SWAP_UTLZD" -le "$OS_SWAP_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*10",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*10",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*10",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*10",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP




#MEMORY UTILIZED <SWAP> --> Red Section

elif [[ "$OS_SWAP_UTLZD" -gt "$OS_SWAP_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*10",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*10",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*10",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*10",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

else

#MEMORY UTILIZED <SWAP> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*10",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*10",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*10",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*10",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

fi


fi


if [[ "$OS_SWAP_TOTAL" -ge 25 && "$OS_SWAP_TOTAL" -lt 40 ]]

then

#MEMORY UTILIZED <SWAP> --> Green Section

if [[ "$OS_SWAP_UTLZD" -le "$OS_SWAP_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*7",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*7",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*7",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*7",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP




#MEMORY UTILIZED <SWAP> --> Red Section

elif [[ "$OS_SWAP_UTLZD" -gt "$OS_SWAP_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*7",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*7",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*7",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*7",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

else

#MEMORY UTILIZED <SWAP> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*7",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*7",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*7",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*7",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

fi


fi


if [[ "$OS_SWAP_TOTAL" -ge 40 && "$OS_SWAP_TOTAL" -lt 55 ]]

then

#MEMORY UTILIZED <SWAP> --> Green Section

if [[ "$OS_SWAP_UTLZD" -le "$OS_SWAP_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*4",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*4",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*4",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*4",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP




#MEMORY UTILIZED <SWAP> --> Red Section

elif [[ "$OS_SWAP_UTLZD" -gt "$OS_SWAP_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*4",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*4",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*4",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*4",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

else

#MEMORY UTILIZED <SWAP> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*4",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*4",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*4",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*4",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

fi


fi


if [[ "$OS_SWAP_TOTAL" -ge 55 && "$OS_SWAP_TOTAL" -lt 75 ]]

then

#MEMORY UTILIZED <SWAP> --> Green Section

if [[ "$OS_SWAP_UTLZD" -le "$OS_SWAP_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*3",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*3",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*3",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*3",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP




#MEMORY UTILIZED <SWAP> --> Red Section

elif [[ "$OS_SWAP_UTLZD" -gt "$OS_SWAP_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*3",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*3",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*3",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*3",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

else

#MEMORY UTILIZED <SWAP> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*3",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*3",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*3",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*3",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

fi


fi



if [[ "$OS_SWAP_TOTAL" -ge 75 && "$OS_SWAP_TOTAL" -lt 140 ]]

then

#MEMORY UTILIZED <SWAP> --> Green Section

if [[ "$OS_SWAP_UTLZD" -le "$OS_SWAP_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*2",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*2",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*2",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*2",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP




#MEMORY UTILIZED <SWAP> --> Red Section

elif [[ "$OS_SWAP_UTLZD" -gt "$OS_SWAP_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*2",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*2",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*2",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*2",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

else

#MEMORY UTILIZED <SWAP> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL*2",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD*2",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD*2",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL*2",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

fi


fi




if [[ "$OS_SWAP_TOTAL" -ge 140 ]]

then

#MEMORY UTILIZED <SWAP> --> Green Section

if [[ "$OS_SWAP_UTLZD" -le "$OS_SWAP_GRN_THRES" ]]

then

echo Green

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#1e8449";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#eafaf1";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP




#MEMORY UTILIZED <SWAP> --> Red Section

elif [[ "$OS_SWAP_UTLZD" -gt "$OS_SWAP_GRN_THRES" ]]

then

echo Red

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#7b241c";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fadbd8";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

else

#MEMORY UTILIZED <SWAP> --> yellow Section

echo yellow

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_TOTAL",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_SWAP
echo "ctx.fillRect(1,1,"$OS_SWAP_UTLZD",40);" >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_UTLZD""GB" '"'",1,25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#9a7d0a";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_FREE""GB" '"'","$OS_SWAP_UTLZD",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#fcf3cf";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"  ""$OS_SWAP_TOTAL""GB" '"'","$OS_SWAP_TOTAL",25,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP

fi


fi

echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#85c1e9";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "10px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"TOTAL SWAP SIZE: ""$OS_SWAP_TOTAL""GB" '"'",1,80,250,8);" >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"UTILIZED SWAP SIZE: ""$OS_SWAP_UTLZD""GB" '"'",1,95,250,8);" >> $REPORT_NAME_SWAP
echo "ctx.fillText("'"'"FREE SWAP SIZE: ""$OS_SWAP_FREE""GB" '"'",1,110,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP


echo "<script>" >> $REPORT_NAME_SWAP
echo 'var canvas = document.getElementById("myCanvas3");' >> $REPORT_NAME_SWAP
echo 'var ctx = canvas.getContext("2d");' >> $REPORT_NAME_SWAP
echo 'ctx.fillStyle = "#85c1e9";' >> $REPORT_NAME_SWAP
echo 'ctx.font = "20px Arial";' >> $REPORT_NAME_SWAP
echo "ctx.fillText('"'SWAP UTILIZATION'"',60,170,250,8);" >> $REPORT_NAME_SWAP
echo "</script>" >> $REPORT_NAME_SWAP



