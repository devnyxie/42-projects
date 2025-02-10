#!/bin/bash

# Check if a directory is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

# Get a random file from the directory
random_file=$(find "$1" -type f | shuf -n 1)

# Check if a file was found
if [ -z "$random_file" ]; then
    echo "No files found in the directory."
    exit 1
fi

# Print the random filename
echo "$random_file"

