#!/usr/bin/bash
# Sumit Das 2016 12 26
# Read all PHYsical Hosts of each DCP cluster
# Collate the PHY HOSTS from each DCP cluster into single file
# Use this file to trigger other scritps

datestamp=$(date "+%Y.%m.%d-%H.%M.%S")

plink -ssh 10.141.64.48 -l in10c2 -pw Start1234  sh /home/users/in10c2/moni/readALLphyIP.sh > ALL_PHY_HOSTIP_10.141.64.48.TXT
plink -ssh 10.141.64.113 -l in10c2 -pw Start1234  sh /home/users/in10c2/moni/readALLphyIP.sh > ALL_PHY_HOSTIP_10.141.64.113.TXT
plink -ssh 10.141.112.30 -l in10c2 -pw Start1234  sh /home/users/in10c2/moni/readALLphyIP.sh > ALL_PHY_HOSTIP_10.141.112.30.TXT
plink -ssh 10.141.112.62 -l in10c2 -pw Start1234  sh /home/users/in10c2/moni/readALLphyIP.sh > ALL_PHY_HOSTIP_10.141.112.62.TXT
plink -ssh 10.141.64.104 -l in10c2 -pw Start1234  sh /home/users/in10c2/moni/readALLphyIP.sh > ALL_PHY_HOSTIP_10.141.64.104.TXT

cat ALL_PHY_HOSTIP_10.141.64.48.TXT >> LOGS/ALL_PHY_HOSTIP_$datestamp.TXT
cat ALL_PHY_HOSTIP_10.141.64.113.TXT >> LOGS/ALL_PHY_HOSTIP_$datestamp.TXT
cat ALL_PHY_HOSTIP_10.141.112.30.TXT >> LOGS/ALL_PHY_HOSTIP_$datestamp.TXT
cat ALL_PHY_HOSTIP_10.141.112.62.TXT >> LOGS/ALL_PHY_HOSTIP_$datestamp.TXT
cat ALL_PHY_HOSTIP_10.141.64.104.TXT >> LOGS/ALL_PHY_HOSTIP_$datestamp.TXT

cp LOGS/ALL_PHY_HOSTIP_$datestamp.TXT ALL_PHY_HOSTIP_.TXT

