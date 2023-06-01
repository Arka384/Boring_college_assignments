#!/bin/bash

if [ $# -eq 0 ]; then
  echo "Error: Please provide at least one directory as an argument."
  exit 1
fi

for dir in "$@"; do
  echo "Directory: $dir"
  
  if [ ! -d "$dir" ]; then
    echo "Error: Directory '$dir' does not exist or is not accessible."
    echo ""
    continue
  fi
  
  size=$(du -sb "$dir" | awk '{print $1}')
  if [ $? -ne 0 ]; then
    echo "Error: Failed to retrieve size in bytes for directory '$dir'."
  else
    echo "Size in bytes: $size"
  fi
  
  size=$(du -sk "$dir" | awk '{print $1}')
  if [ $? -ne 0 ]; then
    echo "Error: Failed to retrieve size in kilobytes for directory '$dir'."
  else
    echo "Size in kilobytes: $size"
  fi
  
  size=$(du -sm "$dir" | awk '{print $1}')
  if [ $? -ne 0 ]; then
    echo "Error: Failed to retrieve size in megabytes for directory '$dir'."
  else
    echo "Size in megabytes: $size"
  fi
  
  echo ""
done

