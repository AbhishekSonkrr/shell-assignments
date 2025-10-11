# This script prints the multiplication table for a number passed as a command line argument.

n=$1

echo "Multiplication table for $n"
for i in $(seq 1 10)
do
  result=$(expr $n \* $i)
  echo "$n x $i = $result"
done
