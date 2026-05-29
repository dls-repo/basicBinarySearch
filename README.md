# Merge Sort & Binary Search

A C program that generates a random array of a given size, sorts it using a bottom-up merge sort implemented from scratch, and searches for a value using binary search.

## Usage

```bash
make
./program <size> <search>
```

### Example

```bash
./program 25 46
```

## How it works

- Generates an array of random integers
- Sorts it in ascending order using merge sort
- Searches for the target value using binary search
- Reports the index if found

## Files

- `main.c` — entry point and CLI argument handling
- `mergesort.c/h` — merge sort implementation
- `binarysearch.c/h` — binary search implementation
- `arrayutils.c/h` — array generation and printing utilities
