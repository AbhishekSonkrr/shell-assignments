#!/usr/bin/env bash
# Exercise 23: compress a string by replacing repeated characters with character+count

if [ $# -ne 1 ]; then
  echo "Usage: $0 <string>"
  exit 2
fi

str="$1"
[ -z "$str" ] && echo "" && exit 0

out=""
count=1
for ((i=1; i<${#str}; i++)); do
  if [ "${str:i:1}" = "${str:i-1:1}" ]; then
    count=$((count+1))
  else
    out+="${str:i-1:1}$count"
    count=1
  fi
done
out+="${str: -1}$count"
echo "$out"
