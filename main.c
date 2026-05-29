#include "mergesort.h"
#include "binarysearch.h"
#include "arrayutils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    if (argc != 3) {
        fprintf(stderr, "Error: expected exactly 2 argument but got %d.\n", argc - 1);
        fprintf(stderr, "Usage: %s <size>\n", argv[0]);
        return 1;
    }

    int size = atoi(argv[1]);
    int search_value = atoi(argv[2]);
    int num[size];

    fill_array_random_numbers(num, size);
    print_array(num, size);
    organize_ascending_order(num, size);
    print_array(num, size);

    int location = binarySearch(num, 0, size - 1, search_value);

    if (location != -1) {
	printf("%d was located at index %d", search_value, location);

    } else {
	
	printf("%d is not in the array", search_value);
    }
}
