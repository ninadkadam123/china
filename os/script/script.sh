#!/bin/bash

clear
echo "enter the length : "
read len

echo "enter the breadth: "
read brd

area=`expr $len \* $brd`
echo "area=$area"
exit
