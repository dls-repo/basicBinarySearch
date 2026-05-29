#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_array_random_numbers(int *array, int size)
{
    // set random time for seed
    srand(time(NULL));

    for(int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
    }
}


void print_array(int *array, int size)
{

    for(int i = 0; i < size; ++i) {
        printf("[%d] ", array[i]);
    }

    printf("\n\n");

}
