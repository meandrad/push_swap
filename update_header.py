import os
import re
from collections import defaultdict

def extract_function_prototypes(file_path):
    """Extract function prototypes from a .c file."""
    prototypes = []
    with open(file_path, 'r') as file:
        lines = file.readlines()
        for line in lines:
            # Match function prototypes (basic regex for return_type func_name(args))
            match = re.match(r'^\s*(static\s+)?([a-zA-Z_][a-zA-Z0-9_*\s]+)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*\(([^)]*)\)\s*{?', line)
            if match:
                return_type = match.group(2).strip()
                func_name = match.group(3).strip()
                args = match.group(4).strip()
                # Format with tabulation between return type and function name
                prototypes.append(f"{return_type}\t{func_name}({args});")
    return prototypes

def group_prototypes_by_folder(source_dir, exclude_dir):
    """Group function prototypes by folder."""
    grouped_prototypes = defaultdict(list)

    # Walk through all .c files in the directory, excluding the specified folder
    for root, _, files in os.walk(source_dir):
        if exclude_dir in root:
            continue
        for file in files:
            if file.endswith(".c"):
                file_path = os.path.join(root, file)
                folder_name = os.path.relpath(root, source_dir)
                prototypes = extract_function_prototypes(file_path)
                grouped_prototypes[folder_name].extend(prototypes)

    # Remove duplicates within each group
    for folder in grouped_prototypes:
        grouped_prototypes[folder] = sorted(set(grouped_prototypes[folder]))

    return grouped_prototypes

def rewrite_header_file(header_file, grouped_prototypes, start_line=32):
    """Rewrite the .h file starting from a specific line."""
    with open(header_file, 'r') as file:
        content = file.readlines()

    # Keep the content up to the specified start line
    header_content = content[:start_line]

    # Add the grouped prototypes
    for folder, prototypes in grouped_prototypes.items():
        header_content.append(f"// {folder}/\n")
        header_content.extend(prototype + "\n" for prototype in prototypes)
        header_content.append("\n")  # Add a blank line after each group

    # End the header guard
    header_content.append("#endif\n")

    # Write the new content to the header file
    with open(header_file, 'w') as file:
        file.writelines(header_content)

def main():
    # Define the directory to search and the header file to update
    source_dir = "./srcs"  # Adjust to your source directory
    header_file = "inc/push_swap.h"  # Adjust to your header file path
    exclude_dir = "libft"  # Directory to exclude

    # Group prototypes by folder
    grouped_prototypes = group_prototypes_by_folder(source_dir, exclude_dir)

    # Rewrite the header file starting from line 32
    rewrite_header_file(header_file, grouped_prototypes, start_line=32)

if __name__ == "__main__":
    main()