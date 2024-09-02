<h1 align="center"> C - Sorting algorithms & Big O </h1>



<br>


<div align="center">

**`C - sorting algorithms & Big O`** project consists of implementing various sorting algorithms in C, including bubble sort, insertion sort, selection sort, quick sort, shell sort, cocktail sort, counting sort, merge sort, heap sort, and radix sort.
<br>
<br>
The programs focus on understanding the mechanics of these algorithms, their implementation details, and analyzing their time complexities using `Big O` notation.
<br>
Additionally, the project emphasizes the importance of choosing the right algorithm for different scenarios by comparing their efficiencies in `best`, `average`, and `worst` cases, while also requiring students to print the array after each swap to visualize the sorting process.
<br>
<br>
This project has been created by **[Holberton School](https://www.holbertonschool.com/about-holberton)** to enable every student to understand how `sorting algorithms` & `Big O` in C language work.

</div>

<br>
<br>

### Background Context

<br>

This project is meant to be done by groups of two students. <br>
Each group of two should [pair program](https://en.wikipedia.org/wiki/Pair_programming) for at least the mandatory part.

<br>
<br>

<!-- ------------------------------------------------------------------------------------------------- -->

## :hammer_and_wrench: Tasks

<br>

**`0. Bubble sort`**

**`1. Insertion sort`**

**`2. Selection sort`**

**`3. Quick sort`**

**`4. Shell sort - Knuth Sequence`**

**`5. Cocktail shaker sort`**

**`6. Counting sort`**

**`7. Merge sort`**

**`8. Heap sort`**

**`9. Radix sort`**

**`10. Bitonic sort`**

**`11. Quick Sort - Hoare Partition scheme`**

**`12. Dealer`**

<br>
<br>

<!-- ------------------------------------------------------------------------------------------------- -->

## :memo: Learning objectives

<br>

**_You are expected to be able to [explain to anyone](https://fs.blog/feynman-learning-technique/), without the help of Google:_**

<br>

```diff

General

+ At least four different sorting algorithms

+ What is the Big O notation, and how to evaluate the time complexity of an algorithm

+ How to select the best sorting algorithm for a given input

+ What is a stable sorting algorithm

```

<br>
<br>

<!-- ------------------------------------------------------------------------------------------------- -->

## :computer: Requirements

<br>

```diff

General

+ Allowed editors: vi, vim, emacs

+ All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89

+ All your files should end with a new line

+ A README.md file, at the root of the folder of the project, is mandatory

+ Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

- You are not allowed to use global variables

+ No more than 5 functions per file

- Unless specified otherwise, you are not allowed to use the standard library. Any use of functions like printf, puts, … is totally forbidden.

+ In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples

+ The prototypes of all your functions should be included in your header file called sort.h

+ Don’t forget to push your header file

+ All your header files should be include guarded

- A list/array does not need to be sorted if its size is less than 2.

```

<br>

**_Why all your files should end with a new line? See [HERE](https://unix.stackexchange.com/questions/18743/whats-the-point-in-adding-a-new-line-to-the-end-of-a-file/18789)_**

<br>
<br>

### GitHub

<br>

There should be one project repository per group. <br>
If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.

<br>
<br>

<!-- ------------------------------------------------------------------------------------------------- -->

## :keyboard: More Info

<br>

### Data Structure and Functions:

<br>

- For this project you are given the following `print_array`, and `print_list` functions:

<br>

```yaml
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```

<br>
<br>

```yaml
#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
```

<br>
<br>

- Our files `print_array.c` and `print_list.c` (containing the `print_array` and `print_list` functions) will be compiled with your functions during the correction.

- Please declare the prototype of the functions `print_array` and `print_list` in your `sort.h` header file.

<br>
<br>

- Please use the following data structure for doubly linked list:

<br>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```

<br>
<br>

- Please, note this format is used for Quiz and Task questions:

  - `O(1)`
  - `O(n)`
  - `O(n!)`
  - n square -> `O(n^2)`
  - log(n) -> `O(log(n))`
  - n * log(n) -> `O(nlog(n))`
  - n + k -> `O(n+k)`
  - …

<br>
<br>

- Please use the “short” notation (don’t use constants).
  - Example: `O(nk)` or `O(wn)` should be written `O(n)`.

- If an answer is required within a file, all your answers files must have a newline at the end.

<br>
<br>

### Tests:

<br>

- Here is a quick tip to help you test your sorting algorithms with big sets of random integers: [Random.org](https://www.random.org/integer-sets/).





```C - sorting algorithms & Big O``` _pro

<p align="center"><br>2024</p>