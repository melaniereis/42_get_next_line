# 🌟 42_get_next_line

<div align="center">

![Animated Reading Line GIF](https://media.giphy.com/media/JIX9t2j0ZTN9S/giphy.gif)

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
   ```bash
   git clone https://github.com/melaniereis/get_next_line.git
   cd get_next_line

    Compile the project:

    bash
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 *.c

Include the header in your C file:

c
#include "get_next_line.h"

Use get_next_line in your code:

c
char *line = get_next_line(fd);

</details>
💡 Example Usages
<details> <summary>Click to see code examples</summary>

c
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
