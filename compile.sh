#!/bin/bash
# filepath: /c:/Users/aldis/code/c++/Rufus/Rufus/compile.sh
# Bash script to compile the Rufus project

# Set the source files
sourceFiles="main.cpp rufus.cpp"

# Set the output executable name
output="rufus"

# Set the compiler and flags
compiler="g++"
flags="-std=c++11 -Wall"

# Compile the source files
compileCommand="$compiler $flags -o $output $sourceFiles"
echo "Compiling with command: $compileCommand"
$compileCommand

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable created: $output"
else
    echo "Compilation failed."
fi