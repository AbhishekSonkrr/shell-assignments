
# interactive file copy script
echo "Enter destination directory:"
read dest
mkdir -p "$dest"

echo "Enter number of files to copy:"
read n



for ((i=1; i<=n; i++))
do
  echo "Enter file $i path:"
  read file
  if [ -f "$file" ]; then
    mv "$file" "$dest"
  else
    echo "$file is not a regular file. Skipping."
  fi
done

echo "Done."
