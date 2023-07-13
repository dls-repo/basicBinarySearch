#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

// Binary Search function
int binarySearch(int *array, int start, int end, int search_value) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        // If the element is present at the middle
        if (array[mid] == search_value)
            return mid;

        // If element is smaller than mid, then it can only be present in left subarray
        if (array[mid] > search_value)
            return binarySearch(array, start, mid - 1, search_value);

        // Else the element can only be present in right subarray
        return binarySearch(array, mid + 1, end, search_value);
    }

    // We reach here when element is not present in array
    return -1;
}

int main() {
    // Ask for array size
    int array_size;
    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    // Allocate memory for the array
    int *numbers = (int*) malloc(array_size * sizeof(int));

    // Generate random numbers
    for (int i = 0; i < array_size; i++) {
        numbers[i] = rand() % 1000;  // Generate numbers between 0 and 999
    }
    
    for (int i = 0; i < array_size; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\nSorted Array:\n");

    // Sort the array
    qsort(numbers, array_size, sizeof(int), compare); 

    // Print sorted array
    for (int i = 0; i < array_size; i++) {
        printf("%d ", numbers[i]);
    }

    // Ask for a value to search
    int search_value;
    printf("\nEnter the value to search: ");
    scanf("%d", &search_value);

    // Perform binary search
    int result = binarySearch(numbers, 0, array_size - 1, search_value);
    
    // Print the result
    if(result == -1) printf("\nElement is not present in array\n");
    else printf("\nElement is present at index %d\n", result);

    // Don't forget to free the memory
    free(numbers);

    return 0;
}

