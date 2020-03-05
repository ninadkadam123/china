#/bin/bash

clear

for params in $*
do
 sum=`expr $sum + $params`
 done

 echo "sum = $sum"
 
 exit

