#include <stdlib.h>


void merge(int *array, size_t left, size_t mid, size_t right)
{
    size_t lower = left;
    size_t upper = mid;
    size_t index = 0;
    size_t temp_size = right - left;

    // create a temporary array for the properly ordered subgroup to transfer to the main array
    int *temp = malloc(temp_size * sizeof(int));

    while (lower < mid && upper < right) {
        if (array[lower] <= array[upper]) {
            temp[index] = array[lower];
            lower++;
        } else {
            temp[index] = array[upper];
            upper++;
        }
        index++;
    }

    while (lower < mid) {
        temp[index] = array[lower];
        lower++;
        index++;
    }
    while (upper < right) {
        temp[index] = array[upper];
        upper++;
        index++;
    }

    //transfer ordered subgroup to the actual array
    for (size_t i = 0; i < temp_size; ++i) {
        array[left + i] = temp[i];
    }

    free(temp);
}


void organize_ascending_order(int *array, size_t size)
{

    // implement bottom-up merge sort with nested for loop resulting in O(log n)
    // on first pass organize two adjecent elements, then 4 elements on second pass, then 8
    for (size_t width = 1; width < size; width *= 2) {

        // inner loop traversal
        // [ 1 2 6 7 ]     [ 4 5 8 9 ]    [ ? ? ? ? ]
        // i             i+= width * 2

        for (size_t i = 0; i < size; i += width * 2) {
            size_t left = i;

            // when even, the middle will just become the upper bound
            size_t mid  = left + width < size ? left + width : size;

            // don't let the right marker ever go past the array's final index
            size_t right = left + width * 2 < size ? left + width * 2 : size;

            if (mid < right) merge(array, left, mid, right);
        }
    }
}
