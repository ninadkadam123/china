#!/bin/bash

function table()
{
   echo "table of $1 is: "
		 for i in {1..10..1}
	 do
		 res=`expr $1 \* $i`
			 echo "$res"
		done

}

clear

echo -n "enter the number: "
read num
tab=$(table $num)
echo "tab : $tab"

exit
