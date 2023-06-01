#!/bin/bash

IFS=:
for dir in $PATH
do
  if [ -d $dir ]
      then 
        echo "$dir"
        echo "Permision : $(ls -ld $dir | awk '{print $1}')"
	echo "Modification Time : $(date -r $dir)"
  else
	echo "$dir does not exit"
      fi
done



