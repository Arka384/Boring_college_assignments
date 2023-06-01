#!/bin/bash


num_files=$(ls -l | grep "^-" | wc -l)
num_dirs=$(ls -l | grep "^d" | wc -l)


echo "Number of files: $num_files"
echo "Number of directories: $num_dirs"

echo "Files:"
ls -p | grep -v / 
echo "Directories:"
ls -p | grep / 

