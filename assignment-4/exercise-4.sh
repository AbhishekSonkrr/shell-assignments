#!/bin/bash

# Define a 3x3 matrix using a 1D array
matrix=(
  1 2 3
  4 5 6
  7 8 9
)

rows=3
cols=3

echo "Matrix:"
for ((i=0; i<rows; i++)); do
    for ((j=0; j<cols; j++)); do
        index=$((i*cols + j))
        echo -n "${matrix[$index]} "
    done
    echo
done

echo

# Row sums
echo "Row sums:"
for ((i=0; i<rows; i++)); do
    sum=0
    for ((j=0; j<cols; j++)); do
        index=$((i*cols + j))
        sum=$((sum + matrix[index]))
    done
    echo "Row $i sum = $sum"
done

echo

# Column sums
echo "Column sums:"
for ((j=0; j<cols; j++)); do
    sum=0
    for ((i=0; i<rows; i++)); do
        index=$((i*cols + j))
        sum=$((sum + matrix[index]))
    done
    echo "Column $j sum = $sum"
done

echo

# Diagonal sums
main_diag=0
sec_diag=0
for ((i=0; i<rows; i++)); do
    main_index=$((i*cols + i))
    sec_index=$((i*cols + (cols - i - 1)))
    main_diag=$((main_diag + matrix[main_index]))
    sec_diag=$((sec_diag + matrix[sec_index]))
done

echo "Main diagonal sum = $main_diag"
echo "Secondary diagonal sum = $sec_diag"

