#!/bin/bash

# Get the directory of the script
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Check if a module name is provided
if [ -z "$1" ]; then
    echo "Please specify a module to compile (module1 or module2)."
    exit 1
fi

MODULE=$1

# Find all .cpp files in the src directory of the specified module
SRC_FILES=$(find "$DIR/$MODULE" -name "*.cpp" 2>/dev/null)

# Check if there are any source files
if [ -z "$SRC_FILES" ]; then
    echo "No source files found for module: $MODULE"
    exit 1
fi

# # Find all .cpp files in the tests directory of the specified module (if exists)
# if [ -d "$DIR/$MODULE/../tests" ]; then
#     TEST_FILES=$(find "$DIR/$MODULE/../tests" -name "*.cpp" 2>/dev/null)
# fi

# Create bin directory if it does not exist
mkdir -p "$DIR/$MODULE/../bin"

# Compile command
g++ -fdiagnostics-color=always -g $SRC_FILES -o "$DIR/$MODULE/../bin/main.out"
# Error, Update later
# if [ -z "$TEST_FILES" ]; then
#     g++ -fdiagnostics-color=always -g $SRC_FILES -o "$DIR/$MODULE/../bin/main.out"
# else
#     g++ -fdiagnostics-color=always -I/path/to/gtest/include -L/path/to/gtest/lib -lgtest -lgtest_main -pthread -g $TEST_FILES -o "$DIR/$MODULE/../bin/main_test.out"
# fi