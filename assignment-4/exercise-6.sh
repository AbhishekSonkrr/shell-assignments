#!/bin/bash

# Read two strings
read -p "Enter first string: " str1
read -p "Enter second string: " str2

# Normalize: lowercase, remove spaces
cleaned1=$(echo "$str1" | tr -d '[:space:]' | tr '[:upper:]' '[:lower:]' | fold -w1 | sort | tr -d '\n')
cleaned2=$(echo "$str2" | tr -d '[:space:]' | tr '[:upper:]' '[:lower:]' | fold -w1 | sort | tr -d '\n')

# Compare
if [[ "$cleaned1" == "$cleaned2" ]]; then
    echo "\"$str1\" and \"$str2\" are anagrams."
else
    echo "\"$str1\" and \"$str2\" are NOT anagrams."
fi

