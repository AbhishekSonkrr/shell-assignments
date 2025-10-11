#!/bin/bash

#Input array
arr=(10 20 30 40 50)

#Print original array
echo "Original array: ${arr[@]}"

#Reverse logic
rev=()
len=${#arr[@]}   # length of array

for (( i=len-1; i>=0; i-- ))
do
    rev+=("${arr[i]}")
done

#Print reversed array
echo "Reversed array: ${rev[@]}"

