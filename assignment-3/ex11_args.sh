# Exercise 11b: Write a shell script to find the gcd of two given numbers (By command line arguments).
a=$1; b=$2
if [ -z "$a" ] || [ -z "$b" ]; then echo "Usage: $0 <a> <b>"; exit; fi
while [ $b -ne 0 ]; do
  t=$b; b=$((a%b)); a=$t;
done
echo "GCD is $a"