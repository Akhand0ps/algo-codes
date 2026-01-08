# Competitive Programming Algorithms

This repository contains C++ implementations of common algorithms used in competitive programming, organized by topic:

## Directory Structure

- **dp/** - Dynamic Programming
  - `fib.cpp`: Implementation of the Fibonacci sequence using dynamic programming.
  - `longest-pallindromic-substring.cpp`: Find the longest palindromic substring.
  - `subsequences.cpp`: Dynamic programming for subsequence problems.

- **gp/** - Graph Problems
  - `bfs.cpp`: Breadth-First Search algorithm for graph traversal.
  - `dfs.cpp`: Depth-First Search algorithm for graph traversal.

- **sw/** - Sliding Window
  - `m.cpp`: Sliding window problem implementation.
  - `minisizesubarr.cpp`: Minimum size subarray sum problem.
  - `without_rep_char.cpp`: Sliding window algorithm to find the longest substring without repeating characters.

- **trees/** - Tree Data Structure & Algorithms
  - `node.h`: Tree node definition and structure.
  - `setup.cpp`: Tree setup and initialization utilities.
  - **bfs/** - Breadth-First Search on Trees
    - `levelorder.cpp`: Level-order traversal of binary tree.
    - `maximum_level_sum.cpp`: Find the level with maximum sum in a binary tree.
  - **dfs/** - Depth-First Search on Trees
    - `dfs_inorder.cpp`: In-order traversal (Left, Root, Right).
    - `dfs_postorder.cpp`: Post-order traversal (Left, Right, Root).
    - `dfs_preorder.cpp`: Pre-order traversal (Root, Left, Right).
    - `Maximum_Product_of_Splitted_Binary_Tree.cpp`: Find maximum product after splitting binary tree.
    - `maximum_product_of_two_subtree_with_max_sum.cpp`: Find two subtrees with maximum sum product.

## How to Use

1. Clone the repository:
   ```sh
   git clone <repo-url>
   ```
2. Navigate to the desired directory and compile the C++ files using g++:
   ```sh
   cd dp
   g++ fib.cpp -o fib
   ./fib
   ```
   Replace `fib.cpp` with the file you want to run.

## Requirements
- C++ compiler (e.g., g++)
- Basic knowledge of C++ and algorithms

## Contributing
Feel free to submit pull requests for new algorithms or improvements.

## License
This project is licensed under the MIT License.
