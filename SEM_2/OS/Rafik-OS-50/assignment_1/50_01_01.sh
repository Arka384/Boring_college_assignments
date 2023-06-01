#!/bin/bash

flag=1

while [ $flag -eq 1 ]
do
    read -p "Enter the value of length: " length
    read -p "Enter the value of breadth: " breadth

    if ! [[ "$length" =~ ^[0-9]+([.][0-9]+)?$ && "$breadth" =~ ^[0-9]+([.][0-9]+)?$ ]]
    then
        echo "Error: Length and breadth should be positive numbers."
    elif [ "$length" == 0 -o "$breadth" == 0 ]
    then
        echo "Error: Length and breadth should be non-zero."
    else
        flag=0
    fi
done

area=$(echo "$length * $breadth" | bc -l)
peri=$(echo "2 * ($length + $breadth)" | bc -l)

echo "The area of the rectangle is $area."
echo "The perimeter of the rectangle is $peri."

