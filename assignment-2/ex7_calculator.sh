# This script performs basic arithmetic operations based on command line arguments.
#!/bin/bash
operation=$1
num1=$2
num2=$3

case $operation in
  -a)
    result=$(expr $num1 + $num2)
    echo "Addition: $result"
    ;;
  -s)
    result=$(expr $num1 - $num2)
    echo "Subtraction: $result"
    ;;
  -m)
    result=$(expr $num1 \* $num2)
    echo "Multiplication: $result"
    ;;
  -c)
    result=$(expr $num1 / $num2)
    echo "Quotient: $result"
    ;;
  -r)
    result=$(expr $num1 % $num2)
    echo "Remainder: $result"
    ;;
  *)
    echo "Invalid operation. Use -a, -s, -m, -c, or -r."
    ;;
esac
