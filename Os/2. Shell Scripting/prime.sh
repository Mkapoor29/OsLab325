#!/bin/bash
echo  "Enter the upper bound "
read up
i=2
l=2
echo "2"
while [ $i -le $up ]
	do
		if [ $((i%l)) -ne 0 ]
			then 
				echo "$i"
		fi
		i = $((i+1))
	done
