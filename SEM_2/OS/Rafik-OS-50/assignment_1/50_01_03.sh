#!/bin/bash

flag=1

while [ $flag -eq 1 ]
do


read -p "Enter a five-digit number: " digit

if ! [[ "$digit" =~ ^[0-9]+$ ]]
then
    echo "Error: Input should be a numeric value."
elif (( ${#digit} != 5 ))
then
    echo "Error: Input should be a five-digit number."
else
    echo "The five-digit number is: $digit"
    sum=0

    while [ $digit -gt 0 ]
    do
        r=$(expr $digit % 10)
        sum=$(expr $sum + $r)
        digit=$(expr $digit / 10)
    done

    echo "The sum of digits is: $sum"
    flag=0
fi
done
