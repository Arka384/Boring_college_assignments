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
elif [ $digit -lt 10000 ]
then
    echo "Enter the value greater than 10000"
else
    echo "The five-digit number is: $digit"
    sum=0

    while [ $digit -gt 0 ]
    do
        r=$(expr $digit % 10)
        sum=$(expr $r + \( $sum \* 10 \))
        digit=$(expr $digit / 10)
    done

    echo "The reverse digit is: $sum"
    flag=0
fi
done
