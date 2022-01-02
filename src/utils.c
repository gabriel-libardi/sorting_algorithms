#include <stdio.h>
#include "utils.h"

void swap(int *num_ptr_1, int *num_ptr_2) {
    
    int tmp = *num_ptr_1;
    *num_ptr_1 = *num_ptr_2;
    *num_ptr_2 = tmp;
}


void merge_halves(int *num_array, size_t beggining, size_t end, int *buffer) {
    if (num_array == NULL || buffer == NULL) {
        return;
    }

    size_t buf_index = beggining;
    size_t half_1_index = beggining;
    size_t half_2_index = (beggining + end)/2 + 1;

    while (buf_index <= end) {
        if (((half_2_index > end) || (num_array[half_1_index] < num_array[half_2_index]))
            && (half_1_index <= (beggining + end)/2)) {
            buffer[buf_index] = num_array[half_1_index];
            half_1_index++;

        } else {
            buffer[buf_index] = num_array[half_2_index];
            half_2_index++;
        }

        buf_index++;
    }

    for (size_t index = beggining; index <= end; index++) {
        num_array[index] = buffer[index];
    }
}
