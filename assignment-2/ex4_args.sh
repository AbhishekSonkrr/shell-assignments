# This script copies multiple files to a specified directory using command line arguments.

dest=$1
shift
mkdir -p "$dest"

for file in "$@"
do
  cp "$file" "$dest"
done

echo "Files copied to $dest"
