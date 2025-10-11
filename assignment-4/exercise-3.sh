#!/bin/bash

# Create a sparse array
arr=()
arr[0]="Apple"
arr[3]="Banana"
arr[5]="Cherry"
arr[8]="Mango"

echo "Original sparse array (with gaps):"
declare -p arr   # shows array structure with indexes

echo -e "\nNon-empty elements:"
for i in "${!arr[@]}"; do
    echo "Index $i: ${arr[$i]}"
done

