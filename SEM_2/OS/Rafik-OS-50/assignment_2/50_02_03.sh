#!/bin/bash

cpuinfo_file="/proc/cpuinfo"

vendor=$(grep -m 1 "vendor_id" $cpuinfo_file | awk '{print $3}')
model=$(grep -m 1 "model name" $cpuinfo_file | awk -F ': ' '{print $2}')
cpumhz=$(grep -m 1 "cpu MHz" $cpuinfo_file | awk '{print $4}')
cache=$(grep -m 1 "cache size" $cpuinfo_file | awk '{print $4}')

echo "Vendor ID: $vendor"
echo "Model Name: $model"
echo "CPU MHz: $cpumhz"
echo "Cache Size: $cache"

