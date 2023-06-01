#!/bin/bash

file="/etc/passwd"

read -p "Enter the user login name: " login_name

if [[ -z "$login_name" ]]; then
    echo "Error: User login name cannot be empty."
    exit 1
fi

detail_info=$(grep "^$login_name:" $file)

if [[ -z "$detail_info" ]]; then
    echo "Error: User login name '$login_name' not found."
    exit 1
fi

IFS=':' read -a arr_split <<< "$detail_info"

fields=(
    "Username"
    "Password"
    "User Id"
    "Group Id"
    "User Id Info"
    "Home Directory"
    "Login Shell"
)

echo -e "\nDetailed user login information of user $login_name:"

for i in {0..6}
do
    echo "${fields[$i]}: ${arr_split[$i]}"
done

