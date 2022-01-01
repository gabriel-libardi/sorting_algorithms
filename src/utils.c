#include <stdio.h>
#include "utils.h"

void swap(int *num_ptr_1, int *num_ptr_2) {
    
    int tmp = *num_ptr_1;
    *num_ptr_1 = *num_ptr_2;
    *num_ptr_2 = tmp;
}


void merge_ordered_lists(int *num_array, size_t length) {
    if (num_array == NULL) {
        return;
    }

    for (int *to_insert = num_array + length/2; to_insert < num_array + length; to_insert++) {
        int copy = *to_insert;
        int *compare_to = to_insert - 1;

        while (compare_to >= num_array) {
            if (copy < *(compare_to)) {
                *(compare_to + 1) = *(compare_to);
            } else {
                break;
            }
            compare_to--;
        }

        *(compare_to + 1) = copy;
    }
}
