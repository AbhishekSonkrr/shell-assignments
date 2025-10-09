#!/usr/bin/env bash
# Exercise 25: longest common substring between two strings

if [ $# -ne 2 ]; then
  echo "Usage: $0 string1 string2"
  exit 2
fi

s1="$1"
s2="$2"
len1=${#s1}
len2=${#s2}
longest=""

for ((i=0; i<len1; i++)); do
  for ((j=i+1; j<=len1; j++)); do
    sub=${s1:i:j-i}
    if [[ $s2 == *"$sub"* ]] && [ ${#sub} -gt ${#longest} ]; then
      longest="$sub"
    fi
  done
done

echo "$longest"
