#!/bin/bash
str1=hello
str2=bye
str3=hello
str4=
if [ str1 != str2 ]; then
    echo "not matched"
fi


if [ str1 = str3 ]; then
    echo "matched"
fi



if [ -n str2 ]; then
    echo "not null"
fi

if [ -z str4 ]; then
    echo "null"
fi
exit 0
