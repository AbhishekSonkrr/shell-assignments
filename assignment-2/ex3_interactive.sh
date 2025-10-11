# This script prints the multiplication table for a number entered interactively.
echo "Enter a number:"
read n

echo "Multiplication table for $n"
for i in $(seq 1 10)
do
  result=$(expr $n \* $i)
  echo "$n x $i = $result"
done
