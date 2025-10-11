# Exercise 12a: Write a shell script to reverse the rows and columns of a matrix (Interactively).
echo "Rows:"
read r
echo "Cols:"
read c
echo "Enter matrix:"
declare -A m
for ((i=0;i<r;i++)); do
  for ((j=0;j<c;j++)); do
    read m[$i,$j]
  done
done
for ((j=0;j<c;j++)); do
  for ((i=0;i<r;i++)); do
    echo -n "${m[$i,$j]} "
  done
  echo
done