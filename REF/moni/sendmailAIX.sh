#!/usr/bin/bash
# Sumit Das 2015 06 08

recipentLIST=$1
filesLIST=`cat filesLIST.list`

for i in recipentLIST
do 
	echo $i
	for j in filesLIST
	do
		echo $j
		cat "$j" | mailx -r "monitoring" -s "$j" $i
	done
done

