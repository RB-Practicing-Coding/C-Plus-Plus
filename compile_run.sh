#!/bin/bash
MODULE=$1
# Call script2.sh
./compile.sh $MODULE

# Get the directory of the script
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Run binary file
"$DIR/$MODULE/../bin/main.out"