#!/bin/bash

sum=0
if [ "$#" -ne 2 ]; then
   echo "incorrect arguments"
   exit 1
   fi

cmd='grep -c -r -h '$2' './$1' '

result=$($cmd)

for i in $result
do
   sum=$(($sum + $i))
done

#echo "line count: "$sum

for item in ./$1/*
do
if [ -f "$item" ]
    then
         file_count=$[$file_count+1]
fi
done

echo "file count: " $file_count

echo "The number of files are $file_count and the number of matching lines are $sum"

