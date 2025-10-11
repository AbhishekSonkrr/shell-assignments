#!/bin/bash

# Input array with duplicates
arr=(1 2 3 2 4 1 5 3 6 4)

# Print the original array
echo "Original array: ${arr[@]}"

# Use associative array to track unique elements
declare -A seen
unique=()

# Loop through each number in the array
for num in "${arr[@]}"; do
    # Check if this number is already seen
    if [[ -z "${seen[$num]}" ]]; then
        # If not seen, add to unique array
        unique+=("$num")
        # Mark it as seen
        seen[$num]=1
    fi
done

# Print the resulting array without duplicates
	echo "Array after removing duplicates: ${unique[@]}"

