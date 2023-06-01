#!/bin/bash


echo "Home directory: $HOME"


os=$(uname -o)
echo "Operating System type: $os"


version=$(uname -v | cut -d ' ' -f 1 | cut -c 6-)
echo "Operating System version: $version"


release=$(uname -v)
echo "Operating System release: $release"


kernel=$(uname -r)
echo "Kernel version: $kernel"


echo "Current path setting: $PATH"

