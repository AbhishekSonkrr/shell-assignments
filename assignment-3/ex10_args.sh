# Exercise 10b: Write a shell script to print the first n Fibonacci numbers (By command line arguments).
n=$1
if [ -z "$n" ]; then echo "Usage: $0 <n>"; exit; fi
a=0; b=1
for ((i=0;i<n;i++)); do
  echo -n "$a ";
  t=$((a+b)); a=$b; b=$t;
done
echo