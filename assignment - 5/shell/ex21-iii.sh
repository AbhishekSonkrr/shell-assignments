#!/usr/bin/env bash
# ex21-iii.sh: Pattern iii (diamond stars)
max=5 # number of rows in upper half
for ((i=1;i<=max;i++)); do
  stars=$((2*i-1))
  indent=$(( (max - i) ))
  printf "%*s" "$indent" ""
  for ((s=0;s<stars;s++)); do printf "*"; done
  printf "\n"
done
for ((i=max-1;i>=1;i--)); do
  stars=$((2*i-1))
  indent=$(( (max - i) ))
  printf "%*s" "$indent" ""
  for ((s=0;s<stars;s++)); do printf "*"; done
  printf "\n"
done
