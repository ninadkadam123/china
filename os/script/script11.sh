#!/bin/bash

function addition()
{
  snum=`expr $1 + $2`
		echo "$snum"

}

clear

echo -n "enter n1: "
read n1

echo -n "enter n2 : "
read n2

addition $n1 $n2

sum=$(addition $n1 $n2)
	echo "sum= $sum"

exit

