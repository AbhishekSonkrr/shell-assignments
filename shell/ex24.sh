#!/usr/bin/env bash
# Exercise 24: generate all permutations of a given array

if [ "$#" -lt 1 ]; then
  echo "Usage: $0 item1 [item2 ...]"
  exit 2
fi

permute() {
  local prefix="$1"
  shift
  local arr=("$@")
  if [ "${#arr[@]}" -eq 0 ]; then
    echo "$prefix"
    return
  fi
  for i in "${!arr[@]}"; do
    local rest=("${arr[@]:0:i}" "${arr[@]:i+1}")
    permute "$prefix ${arr[i]}" "${rest[@]}"
  done
}

permute "" "$@"