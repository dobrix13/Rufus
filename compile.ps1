# PowerShell script to compile the Rufus project

# Set the source files
$sourceFiles = "main.cpp", "rufus.cpp"

# Set the output executable name
$output = "rufus.exe"

# Set the compiler and flags
$compiler = "g++"
$flags = "-std=c++11 -Wall"

# Compile the source files
$compileCommand = "$compiler $flags -o $output $sourceFiles"
Write-Host "Compiling with command: $compileCommand"
Invoke-Expression $compileCommand

# Check if the compilation was successful
if ($?) {
    Write-Host "Compilation successful. Executable created: $output"
} else {
    Write-Host "Compilation failed."
}