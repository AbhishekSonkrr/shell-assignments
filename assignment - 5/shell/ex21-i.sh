#!/usr/bin/env bash
# ex21-i.sh: Pattern i (numbers)
for i in {1..5}; do
  for ((j=0;j<i;j++)); do printf "%d" "$i"; done
  printf "\n"
done
