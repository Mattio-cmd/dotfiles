#!/usr/bin/python

import os
import shutil
import sys

def move_pdfs(source_dir, destination_dir):
    # Ensure that the destination directory exists
    if not os.path.exists(destination_dir):
        os.makedirs(destination_dir)

    # Traverse through the directory structure using os.walk
    for root, dirs, files in os.walk(source_dir):
        # Check the depth of the current directory relative to source_dir
        current_depth = root[len(source_dir):].count(os.path.sep)

        # Move PDF files found at depth <= 2 (source_dir and its direct subdirectories)
        if current_depth <= 2:
            for file in files:
                if file.lower().endswith('.pdf'):
                    source_path = os.path.join(root, file)
                    destination_path = os.path.join(destination_dir, file)
                    shutil.move(source_path, destination_path)
                    print(f"Moved: {file}")

if __name__ == "__main__":
    # Check if two command-line arguments are provided
    if len(sys.argv) != 3:
        print("Usage: python script.py source_directory destination_directory")
        sys.exit(1)

    # Get source and destination directories from command-line arguments
    source_directory = sys.argv[1]
    destination_directory = sys.argv[2]

    move_pdfs(source_directory, destination_directory)
