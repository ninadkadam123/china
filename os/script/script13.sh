#!/bin/bash

function addition()
{
res=`expr $1 + $2`
	echo "$res"

}

function substraction()
{
res=`expr $1 - $2`
	echo "$res"



}


function multiplication()
{
res=`expr $1 \* $2`
	echo "$res"

}
function division()
{
res=`expr $1 / $2`
	echo "$res"

}
while [ 1 ]
do
 clear
 echo "basic calculator"
 echo "0.exit"
 echo "1. addition"
 echo "2. substraction"
 echo "3. multiplication"
 echo "4. division"
 read ch

 if [ $ch -eq 0 ]
 then
   exit
 fi

 echo -n "enter n1:"
 read n1
 echo -n "enter n2: "
 read n2

 case $ch in 
 1)
 res=$(addition $n1 $n2)
	echo "res=$res"
	;;
 2)
 res=$(substraction $n1 $n2)
	echo "res=$res"
	;;

 3)
 res=$(multiplication $n1 $n2)
	echo "res=$res"
	;;
 
 4)
 res=$(division $n1 $n2)
	echo "res=$res"
	;;
 
	*)
	echo "invalid choice"
	;;
	esac

	echo -n "press enter to continue....."
	read enter

	done

	
