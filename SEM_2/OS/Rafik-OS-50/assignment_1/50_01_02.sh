#!/bin/bash


flag=1

while [ $flag -eq 1 ]
do

read -p "Enter your basic salary: " basic

if ! [[ "$basic" =~ ^[0-9]+([.][0-9]+)?$ ]]
then
    echo "Error: Basic salary should be a numeric value."
elif (( $(echo "$basic <= 0" | bc -l) ))
then
    echo "Error: Basic salary should be a positive value."
else
    da=40
    hra=10
    echo "Basic salary is: $basic"
    echo "DA is: $da%"
    echo "HRA is: $hra%"

    net=$(echo "$basic + ($basic * $da) / 100 + ($basic * $hra) / 100" | bc -l)

    echo "Net payment is: $net"
    flag=0
fi
done
