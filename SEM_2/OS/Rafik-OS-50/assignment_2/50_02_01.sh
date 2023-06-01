#!/bin/bash

if [ ! "$(ls -A)" ]
then
    echo "Error: The current directory is empty."
    exit 1
fi

for file in *
do
  if [ -f "$file" ]
  then
    echo "$file is a regular file."
  elif [ -d "$file" ]
  then
    echo "$file is a directory."
  fi
done

