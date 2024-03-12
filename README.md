# Push Swap

Welcome to Push Swap! This project focuses on sorting a stack of integers using only two stacks and a set of predefined operations. By implementing an efficient sorting algorithm, you'll deepen your understanding of data structures and algorithms, particularly stack manipulation and sorting techniques.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Algorithm Description](#algorithm-description)
4. [Building](#building)
5. [Contributing](#contributing)
6. [Credits](#credits)

## Introduction

In this project, you'll implement a program that sorts a stack of integers provided as input using a set of operations. The objective is to sort the stack with the minimum number of operations. The allowed operations include swapping the top two elements of a stack (`sa`, `sb`), pushing an element from one stack to another (`pa`, `pb`), rotating a stack upwards (`ra`, `rb`) or downwards (`rra`, `rrb`), and executing a series of operations (`rr`, `rrr`) simultaneously on both stacks.

## Usage

To use the Push Swap program, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/adrgonza/push_swap.git
    ```

2. Build the program:

    ```bash
    make
    ```

3. Run the program with a list of integers as input:

    ```bash
    ./push_swap 4 2 3 1
    ```

    This will output a series of operations to sort the stack.

## Algorithm Description

The Push Swap algorithm aims to sort the stack in as few operations as possible. My push_swap uses radix sort working with binary to be more efficient.

## Building

To build the Push Swap program, simply run:

```bash
make
```
## Contributing
Contributions are welcome! If you find any bugs or have suggestions for improvement, please open an issue or submit a pull request on GitHub.

## Credits
This project was created by adrgonza for the push_swap project at 42Madrid.
