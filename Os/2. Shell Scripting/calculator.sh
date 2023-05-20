#!/bin/bash
echo "Enter number 1 "
read num1
echo "Enter number 2 "
read num2
echo "Enter the operation symbol you want to perform "
read opr
case $opr in
	"+"|"sum"|"add")
	echo "sum is $((num1+num2))";;
	"-"|"difference"|"subtract")
	echo "difference is $((num1-num2))";;
	"*"|"multiply")
	echo "Multiplaction is $((num1*num2))";;
	"/"|"divide")
	if [$num2 -eq 0]
	then
		echo "division by zero not possible"
	else
		echo "Division is $((num1/num2))"
	fi
	;;
	"%"|"mod")
	echo "mod is $((num1%num2))";;
	*)
	echo "Not valid operator";;
esac
