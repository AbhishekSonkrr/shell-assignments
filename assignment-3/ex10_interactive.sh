# Exercise 10a: Write a shell script to print the first n Fibonacci numbers (Interactively).
echo "Enter n:"
read n
a=0; b=1
for ((i=0;i<n;i++)); do
  echo -n "$a ";
  t=$((a+b)); a=$b; b=$t;
done
echo