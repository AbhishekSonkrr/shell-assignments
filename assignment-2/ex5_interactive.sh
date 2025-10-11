# This script interactively counts lines and words in a specified file.
echo "Enter file name:"
read file

lines=$(wc -l < "$file")
words=$(wc -w < "$file")

echo "Number of lines: $lines"
echo "Number of words: $words"
