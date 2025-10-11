# Exercise 13a: Write a shell script to find the scalar product of two vectors (Interactively).
echo "Size:"
read n
echo "Vector 1:"
for ((i=0;i<n;i++)); do read a[$i]; done
echo "Vector 2:"
for ((i=0;i<n;i++)); do read b[$i]; done
s=0
for ((i=0;i<n;i++)); do s=$((s+a[$i]*b[$i])); done
echo "Scalar product: $s"