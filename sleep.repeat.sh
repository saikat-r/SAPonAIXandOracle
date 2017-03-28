while true
do
date
df -gt | grep oracle | grep DGE
#ps -e -o pmem -o vsz -o args | sort -rn | head -10
echo ""
echo ""

# Wait for a process to finish
#wait 29884428
# Wait for a process to finish END


# Send Mail command
PCT=`df -gt | grep oracle | grep DGE | awk '{print $5}'`
df -gt | grep oracle | grep DGE > tempfileforsleep
#echo "PCT is = "
#echo $PCT
PCT=`echo ${PCT%?}`
#echo "PCT is now = "
#echo $PCT
Sender="DGE"
Subject="DGE_oracle_fs_status"
Recipient="sam8boc@gmail.com"

#if [ $PCT -gt 5 ]; then mailx -r "PRD DB" -s "PRD DB oraaarch filling" "sam8boc@gmail.com" ; echo "E-mail sent..." ; fi
if [ $PCT -gt 5 ];
then
        cat "tempfileforsleep" | mailx -r $Sender -s $Subject $Recipient
        rm -f tempfileforsleep
        echo "E-mail sent..."
fi
# Send Mail command END


sleep 60
done

