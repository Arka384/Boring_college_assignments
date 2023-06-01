#!/bin/bash

# Write a shell script to rename file having extension
# sh to.exe.

for file in *.sh; do
    echo "Renamed $file to ${file%.sh}.exe"
    mv -- "$file" "${file%.sh}.exe"
done