# Code Practice Repository

## Overview
This repository is dedicated to practicing various coding techniques and concepts. The goal is to improve coding skills, explore new technologies, and experiment with different programming languages.

## Project Structure
    /project
        /module
            /src
                main.cpp
                utils.cpp
            /tests
                main_test.cpp
            /bin
                main.out
            /out/buid/${presetName}/... (if CMake)

## Compilation:
We can compile and run c++ via compile_run.sh using **CMake** build or below scripts (if unit tests are not needed)
### At your workspace folder:
```bash
./compile_run.sh <directory-to-cpp-files>
```
### For example:
```bash
./compile_run.sh Fundamentals/Loop/src/
```