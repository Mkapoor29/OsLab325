#!/bin/bash
echo "Is it morning? Please answer in yes r no."
read time
if [ $time = "yes" ]; then
	echo "Good morning"
elif [ $time = "no" ]; then
	echo "Good Afternoon"
else
	echo "Sorry $time not recognized Enter yes or no"
fi



