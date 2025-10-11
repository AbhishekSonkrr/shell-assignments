# This script counts lines and words in a file specified as a command line argument.
file=$1

lines=$(wc -l < "$file")
words=$(wc -w < "$file")

echo "Number of lines: $lines"
echo "Number of words: $words"
