#!/bin/bash


for file in *.sh; do
  mv -- "$file" "${file%.sh}.exe"
done

# Print a message indicating how many files were renamed
num_renamed=$(find . -name "*.exe" -type f | wc -l)
echo "Renamed $num_renamed files from .sh to .exe"
