# Exercise 12b: Write a shell script to reverse the rows and columns of a matrix (By command line arguments).
r=$1; c=$2; shift 2
if [ -z "$r" ] || [ -z "$c" ] || [ $# -ne $((r*c)) ]; then echo "Usage: $0 <r> <c> <elements>"; exit; fi
declare -A m
k=0
for ((i=0;i<r;i++)); do
  for ((j=0;j<c;j++)); do
    m[$i,$j]=${@:$((k+1)):1}
    k=$((k+1))
  done
done
for ((j=0;j<c;j++)); do
  for ((i=0;i<r;i++)); do
    echo -n "${m[$i,$j]} "
  done
  echo
done