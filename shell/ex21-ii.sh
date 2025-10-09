#!/usr/bin/env bash
# ex21-ii.sh: Pattern ii (letters)
letters="ABCDE"
for ((i=1;i<=${#letters};i++)); do
  printf "%s\n" "${letters:0:i}"
done
