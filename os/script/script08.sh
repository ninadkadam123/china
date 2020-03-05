#!/bin/bash

clear

echo "executable files in a cur dir are: "
for filename in `ls`

do
 if [ -e $filename -a -x $filename ]
 then
   echo "$filename"
  fi
done

exit
