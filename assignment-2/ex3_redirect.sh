#!/bin/bash
read n
echo "Multiplication table for $n"
i=1
while [ $i -le 10 ]
do
  result=$(expr $n \* $i)
  echo "$n x $i = $result"
  i=$(expr $i + 1)
done
