#!/bin/bash

clear

echo -n "enter the num :"
read num

echo "while: table of a $num is:"
i=1
while [ $i -le 10 ]
do
  res=`expr $num \* $i`
	echo "$res"
	i=`expr $i + 1`
	done

	echo "until: table of a $num is:"
	i=1
	until [ $i -gt 10 ]
	do
	  res=`expr $num \* $i`
		echo "$res"
		i=`expr $i + 1`
	done

	echo "for : tableof a $num is :"
	for i in 1 2 3 4 5 6 7 8 9 10
	do
	 res=`expr $num \* $i`
	 echo "$res"
	done
	
	
	
	exitt
