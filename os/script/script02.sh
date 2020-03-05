#!/bin/bash

echo -n "enter n1: "
read n1

echo -n  "enter n2: "
read n2

sum=`expr $n1 + $n2`
echo "sum=$sum"
exit

