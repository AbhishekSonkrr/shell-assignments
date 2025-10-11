# Exercise 9a: Write a shell script to print all the primes below a given number (Interactively).
echo "Enter a number:"
read n
for ((x=2;x<n;x++)); do
  p=1
  for ((i=2;i<x;i++)); do
    if [ $((x%i)) -eq 0 ]; then p=0; break; fi
  done
  if [ $p -eq 1 ]; then echo -n "$x "; fi
done
echo