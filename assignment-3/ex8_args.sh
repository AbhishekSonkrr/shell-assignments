# Exercise 8b: Write a shell script to determine whether a given number is a prime number or not (By command line arguments).
n=$1
if [ -z "$n" ]; then echo "Usage: $0 <number>"; exit; fi
if [ $n -le 1 ]; then echo "Not prime"; exit; fi
for ((i=2;i<n;i++)); do
  if [ $((n%i)) -eq 0 ]; then echo "Not prime"; exit; fi
done
echo "Prime"