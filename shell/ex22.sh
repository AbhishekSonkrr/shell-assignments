#!/usr/bin/env bash
# Simple sum, mean, variance calculator

if [ "$#" -lt 1 ]; then
  echo "Usage: $0 num1 [num2 ...]"
  exit 2
fi

n=$#
sum=0
sumsq=0

for x in "$@"; do
  sum=$(echo "$sum + $x" | bc)
  sumsq=$(echo "$sumsq + ($x * $x)" | bc)
done

mean=$(echo "scale=5; $sum / $n" | bc)
variance=$(echo "scale=5; $sumsq / $n - ($mean * $mean)" | bc)

echo "n = $n"
echo "sum = $sum"
echo "mean = $mean"
echo "variance = $variance"