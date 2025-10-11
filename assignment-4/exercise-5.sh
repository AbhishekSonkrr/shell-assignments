#!/bin/bash

# Read input string from user
read -p "Enter a string: " str

# Remove spaces and convert to lowercase for uniformity
cleaned=$(echo "$str" | tr -d '[:space:]' | tr '[:upper:]' '[:lower:]')

# Reverse the string
reversed=$(echo "$cleaned" | rev)

# Check if palindrome
if [[ "$cleaned" == "$reversed" ]]; then
    echo "\"$str\" is a palindrome."
else
    echo "\"$str\" is NOT a palindrome."
fi

