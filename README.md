*This project has been created as part of the 42 curriculum by dde-fite*

<p align="center">
	<img align="center" src="media/42_push_swap.jpg">
	<h1 align="center">42_push_swap</h1>
</p>

<p align="center">
	<img alt="Static Badge" src="https://img.shields.io/badge/pending/100-yellow?logo=42&logoColor=white">
</p>

<p align="center">
This work is published under the terms of <a href="LICENSE"><b>MIT license</b></a>
</p>

<div align="center">
	<h2>Returns the operations needed to sort numbers using two stacks.</h2>
	<img src="media/preview.gif">
</div>

## Description

## Instructions

## Resources
- [(YT) All the Sorting Algorithms - Boot dev](https://www.youtube.com/watch?v=GMV7ycKZ-mM)
- [(YT) I Made Sorting Algorithms Race Each Other - Green Code](https://www.youtube.com/watch?v=N4JVT3eVBP8)
- [(YT) Learn Insertion Sort in 7 minutes 🧩 - Bro Code](https://www.youtube.com/watch?v=N4JVT3eVBP8)
- [(YT) Learn Selection Sort in 8 minutes 🔦 - Bro Code](https://www.youtube.com/watch?v=EwjnF7rFLns)
- [Sorting a Singly Linked List - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/sorting-a-singly-linked-list/)
- [Push_Swap Turk algorithm explained in 6 steps - Yutong Deng](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
- [My journey to find a good sorting algorithm for the Push_Swap 42 project - MannBell](https://m4nnb3ll.medium.com/my-journey-to-find-a-good-sorting-algorithm-for-the-push-swap-42-project-4a18bc38b474)



## Testings

```fish
set args (seq -214748 214748 | sort -R | head -n 100); ./push_swap $args | wc -l
```

## Features
- Implements all basic `printf` conversions.
- Fully supports all bonus features:
  - Complete handling of flags: `-`, `0`, `.`, field width, `#`, `+`, and space.
  - All possible flag combinations for each conversion.

## Requirements
The functions and Makefile are designed for use in a UNIX-like environment; any use outside this scope does not guarantee correct or efficient operation.
- Make
- GCC

## Usage

### Compiling
- Clone the repository recursively to download the submodules.
``` bash
git clone --recursive https://github.com/dde-fite/42_ft_printf.git
```

- For the general section
``` bash
make
```

- For the bonus section.
``` bash
make bonus
```

### Using it as a static library
After installation is complete, the libft.a file will appear. This static library can be used in any project.s

You can include the library by including libft.h and libft.a as in the example:

- First include the header file in your C or header files.
``` h
#include "ft_printf.h"

// or for bonus
#include "ft_printf_bonus.h"
```

- Then compile using the library
``` bash
gcc main.c libftprintf.a
```

## Got any suggestions?
If you find any errors or have any new ideas for improving this repository, feel free to open an Issue or Pull Request, or contact me at my email address: nora@defitero.com