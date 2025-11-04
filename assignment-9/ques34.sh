#!/bin/bash
read -p "Enter directory path: " dir
if [ ! -d "$dir" ]; then
    echo "Not a directory."
    exit 1
fi
count=$(find "$dir" -type f | wc -l)
echo "Number of files in $dir: $count"