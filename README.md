# 🌟 42_get_next_line

<div align="center">

![Animated Reading Line GIF](https://media.giphy.com/media/l0HlOBZcl7sbV6LnO/giphy.gif)

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![Norminette](https://img.shields.io/badge/norminette-passing-brightgreen.svg)](https://github.com/42School/norminette)

[Overview](#-project-overview) •
[Features](#-features) •
[Quick Start](#-quick-start-guide) •
[Examples](#-example-usages) •
[Author](#-author)

</div>

## 📖 Project Overview

<details>
<summary>Click to expand</summary>

**get_next_line** is a crucial project in the **42 School** curriculum, focusing on file I/O operations and static variables in C. This function allows you to read content line by line from a file descriptor, enhancing your understanding of:

- File descriptors
- Static variables
- Memory allocation and management
- Buffer handling

The main goal is to create a function that reads a line from a file descriptor each time it's called, returning the line that was read. If there's nothing else to read or if an error occurred, it should return NULL.

</details>

## ✨ Features

<details>
<summary>Core Functionality</summary>

- Reads from any file descriptor (files, standard input, etc.)
- Returns one line at a time
- Handles multiple file descriptors simultaneously
- Efficient memory management to prevent leaks
- Graceful handling of various edge cases

</details>

<details>
<summary>Bonus Features</summary>

- Uses only one static variable
- Manages multiple file descriptors without losing the reading thread on each of them

</details>

## 🚀 Quick Start Guide

<details>
<summary>Installation Steps</summary>

1. **Clone the repository:**
   bash
   git clone https://github.com/melaniereis/get_next_line.git
   cd get_next_line

2. Compile the project:
   bash
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 *.c

3. Include the header in your C file:
   
#include "get_next_line.h"

5. Use get_next_line in your code:

char *line = get_next_line(fd);

</details>
💡 Example Usages
<details> <summary>Click to see code examples</summary>

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}

</details>
📁 Project Structure
<details> <summary>File Structure</summary>

text
.
├── get_next_line.c      # Main function implementation
├── get_next_line.h      # Header file with function prototypes
├── get_next_line_utils.c # Utility functions
└── Makefile             # Compilation rules

</details>
📏 Norminette Compliance
This project adheres to the Norm, the coding standard of 42 School. All files pass the Norminette check, ensuring clean and maintainable code.
🧪 Testing
<details> <summary>Test Files and Edge Cases</summary> To thoroughly test get_next_line, consider the following scenarios:

    Empty files
    Files with only newline characters
    Files with no newline characters
    Very large files
    Files with long lines
    Files with varying line lengths
    Reading from standard input
    Reading from multiple file descriptors

You can create test files or use existing text files to cover these cases. </details>
👩‍💻 Author
Melanie Reis <details> <summary>Contact Information</summary>

    GitHub: @melaniereis
    LinkedIn: Melanie Reis

</details>
📄 License
This project is licensed under the MIT License - see the LICENSE file for details.
🙏 Acknowledgments

    Special thanks to 42 School for providing this project subject and guidelines.
    Inspired by various C programming resources and best practices.

<details> <summary>📚 Additional Resources</summary>

    C File I/O Tutorial
    Understanding Static Variables in C
    42 School Official Website

</details> 
