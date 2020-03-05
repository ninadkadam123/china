#!/bin/bash

clear

PI=3.14

echo "enter the radius"
read rad

area=`echo "$PI * $rad * $rad" | bc`

echo "area= $area"

exit

