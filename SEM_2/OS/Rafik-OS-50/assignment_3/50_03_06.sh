#!/bin/bash

num_scripts=$(find . -maxdepth 1 -type f -name "*.sh" | wc -l)

echo "There are $num_scripts shell scripts in the current directory"

