# Libft

This repository contains a custom implementation of the **libft** library in C, providing essential functions for string manipulation, memory management, and other common tasks.

## Functions
- **ft_isalpha**: Checks if a character is alphabetic.
- **ft_isdigit**: Checks if a character is a digit.
- **ft_isalnum**: Checks if a character is alphanumeric.
- **ft_isascii**: Checks if a character is ASCII.
- **ft_isprint**: Checks if a character is printable.
- **ft_strlen**: Calculates the length of a string.
- **ft_strdup**: Duplicates a string.
- **ft_strcpy**: Copies a string.
- **ft_strncpy**: Copies a specified number of characters from a string.
- **ft_strcmp**: Compares two strings.
- **ft_strncmp**: Compares a specified number of characters between two strings.
- **ft_strchr**: Finds the first occurrence of a character in a string.
- **ft_strrchr**: Finds the last occurrence of a character in a string.
- **ft_strstr**: Locates a substring within a string.
- **ft_memset**: Sets memory to a specific value.
- **ft_bzero**: Sets memory to zero.
- **ft_memcpy**: Copies memory from one location to another.
- **ft_memmove**: Moves memory from one location to another, handling overlapping regions.
- **ft_memchr**: Locates a character in a block of memory.
- **ft_memcmp**: Compares two blocks of memory.
- **ft_memalloc**: Allocates memory and initializes it to zero.
- **ft_memdel**: Frees dynamically allocated memory.
- **ft_strnew**: Allocates memory for a new string.
- **ft_strdel**: Frees a string.
- **ft_strclr**: Clears a string by setting it to zero.
- **ft_striter**: Applies a function to each character of a string.
- **ft_striteri**: Applies a function to each character of a string, passing its index.
- **ft_strmap**: Applies a function to each character of a string, creating a new string.
- **ft_strmapi**: Applies a function to each character of a string, creating a new string with index.
- **ft_strequ**: Compares two strings for equality.
- **ft_strnequ**: Compares two strings for equality up to a specified number of characters.
- **ft_strsub**: Extracts a substring from a string.
- **ft_strjoin**: Joins two strings together.
- **ft_strtrim**: Trims whitespace from both ends of a string.
- **ft_strsplit**: Splits a string into an array of substrings based on a delimiter.
- **ft_itoa**: Converts an integer to a string.
- **ft_putchar**: Prints a character to standard output.
- **ft_putstr**: Prints a string to standard output.
- **ft_putendl**: Prints a string followed by a newline to standard output.
- **ft_putnbr**: Prints an integer to standard output.
- **ft_putchar_fd**: Prints a character to a specified file descriptor.
- **ft_putstr_fd**: Prints a string to a specified file descriptor.
- **ft_putendl_fd**: Prints a string followed by a newline to a specified file descriptor.
- **ft_putnbr_fd**: Prints an integer to a specified file descriptor.

## Example Usage

#### Step 1: Compilation
To compile the library, run the following command:

```bash
make
```

This will generate the `libft.a` file.

#### Step 2: Main

```c
#include "libft.h"

int main(void)
{
    char *str = "Hello, World!";
    int len = ft_strlen(str);
    ft_putstr_fd(str, 1);
    return 0;
}
```
This main is only one example, you can test another function using the same template.

#### Step 3: Cleaning Up
To remove object files:

```bash
make clean
```

To remove both object files and the compiled library:

```bash
make fclean
```

### Step 4: Run the Test
For additional tests and resources to validate your **libft** project, you can use the **libft Tester** repository by Tripouille. It provides an extensive set of tests for evaluating your implementation.

Check out the repository here: [https://github.com/Tripouille/libftTester](https://github.com/Tripouille/libftTester).
