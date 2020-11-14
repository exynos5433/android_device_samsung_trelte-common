#!/bin/sh
# loggy.sh

date=`date +%F_%H-%M-%S`
logcat -b all -v time -f  /cache/logcat_${date}.txt &
cat /dev/kmsg > /cache/kmsg_${date}.txt &
mv /data/tombstones > /cache/tombstones_${date} &
cat /proc/last_kmsg > /cache/last_kmsg${date}.txt
