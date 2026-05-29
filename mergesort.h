#ifndef MERGESORT_H
#define MERGESORT_H

#include <stddef.h>

void fill_array_random_numbers(int *array, int size);
void organize_ascending_order(int *array, int size);
void merge(int *array, size_t left, size_t mid, size_t right);
void print_array(int *array, int size);

#endif
