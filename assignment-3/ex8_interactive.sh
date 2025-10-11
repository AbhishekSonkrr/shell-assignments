# Exercise 8a: Write a shell script to determine whether a given number is a prime number or not (Interactively).
echo "Enter a number:"
read n
if [ $n -le 1 ]; then echo "Not prime"; exit; fi
for ((i=2;i<n;i++)); do
  if [ $((n%i)) -eq 0 ]; then echo "Not prime"; exit; fi
done
echo "Prime"