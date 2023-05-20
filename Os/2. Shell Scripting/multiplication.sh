#!/bin/bash
echo "Enter the number whose table you want to see "
read num
for i in {0..10}
	do
		echo "$num * $i = $(($num * $i))"
	done

