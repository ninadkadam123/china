#!/bin/bash

clear

echo -n "enter the filepath "
read filepath

if [ -e $filepath ]
then
   if [ -f $filepath ] 
	 then
	  echo "contents of reg file are : "
		cat $filepath
		elif [ -d $filepath ]
		then
		 echo "contents of dir file are :"
		 ls -l  $filepath
		 else
		 echo "$filepath is neithr reg file nor dir file "
	fi
else
   echo "invalid filepath"
	 fi

	 exit



