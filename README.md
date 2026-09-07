# DSA

A collection of data structure and algorithm implementations in C++, written for myself and friends who want to learn or brush up on these concepts.

Each file is self-contained with a `main` function that demonstrates and tests the implementation, so you can just compile and run any single file to see it in action.

## Structure

- `common/` — shared data structure headers (`TreeNode.h`, `ListNode.h`, `GraphNode.h`, ect.) reused across folders
- `design/` — design problems (e.g. LRU Cache)
- `linkedlist/` — linked list implementations
- `sorting/` — sorting algorithms (quick sort, merge sort, stack sorter, etc.)
- `dfs/` — depth-first search examples
- `bfs/` — breadth-first search examples (e.g. level-order tree traversal)

## Running

Each `.cpp` file can be compiled and run independently:

```bash
g++ -std=c++11 -g path/to/File.cpp -o path/to/File && ./path/to/File
```

Feel free to explore, learn, and adapt any of this for your own practice.
