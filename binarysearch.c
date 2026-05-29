//#include <stdio.h>
//#include <stdlib.h>

int binarySearch(int *array, int start, int end, int search_value)
{
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
