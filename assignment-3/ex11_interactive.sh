# Exercise 11a: Write a shell script to find the gcd of two given numbers (Interactively).
echo "Enter two numbers:"
read a b
while [ $b -ne 0 ]; do
  t=$b; b=$((a%b)); a=$t;
done
echo "GCD is $a"