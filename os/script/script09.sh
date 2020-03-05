#!/bin/bash

if [ $# -ne 2 ]
then
  echo "invalid no. of pos params to script: $0"
	exit
	fi

	sum=`expr $1 + $2`
	echo "sum = $sum"

	exit

