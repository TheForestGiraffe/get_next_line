# get_next_line — Line-by-Line File Reader in C

This repository contains my implementation of the **get_next_line** project from the 42 curriculum.

The objective of this project is to create a function that reads and returns a file descriptor's content **one line at a time**, handling memory safely and efficiently.

---

## Project Overview

`get_next_line` implements the function:

```c
char *get_next_line(int fd);
```

Each call returns the next line from the given file descriptor, including the newline character (`\n`) when present, until the end of file is reached.

The function works with arbitrary file sizes and does not require loading the entire file into memory.

---

## Objectives

- Read from a file descriptor using `read`
- Return one line per function call
- Handle multiple file descriptors (bonus)
- Manage memory correctly (no leaks)
- Handle EOF and errors safely

Only low-level functions such as `read`, `malloc`, and `free` are allowed.

---

## Repository Structure

- `get_next_line.c` – Core implementation
- `get_next_line_utils.c` – Helper functions
- `get_next_line.h` – Prototypes and macros
- `*_bonus.c` – Bonus implementation (multi-FD support)

---

## 🧪 Example Usage

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}

close(fd);
```

Each returned line must be freed by the caller.

---

## 🧠 Skills Developed

- Low-level file I/O (POSIX)
- Dynamic memory management
- Static state handling
- Buffering strategies

---

## Notes

- Compiled with `-Wall -Wextra -Werror`
- Tested on Linux
- Follows 42 Norm
