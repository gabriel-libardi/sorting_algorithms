#include <stdio.h>
#include "sorting_algorithms.h"
#include "utils.h"


void bubble_sort(int *num_array, size_t length) {
    if (num_array == NULL) {
        return;
    }

    for (int *end = num_array + length - 1; num_array != end;) {
        int *last_swap = num_array;

        for (int *element_ptr = num_array; element_ptr < end; element_ptr++) {
            if (*element_ptr > *(element_ptr + 1)) {
                swap(element_ptr, element_ptr + 1);
                last_swap = element_ptr;
            }
        }

        end = last_swap;
    }
}


void selection_sort(int *num_array, size_t length) {
    if (num_array == NULL) {
        return;
    }

    for (int *beggining = num_array; beggining < num_array + length; beggining++) {
        int *minimum_ptr = beggining;

        for (int *num_ptr = beggining; num_ptr < num_array + length; num_ptr++) {
            if (*minimum_ptr > *num_ptr) {
                minimum_ptr = num_ptr;
            }
        }

        swap(beggining, minimum_ptr);
    }
}


void insertion_sort(int *num_array, size_t length) {
    if (num_array == NULL) {
        return;
    }

    for (int *to_insert = num_array + 1; to_insert < num_array + length; to_insert++) {
        for (int *compare_to = to_insert - 1; compare_to >= num_array; compare_to--) {
            if (*(compare_to + 1) < *(compare_to)) {
                swap(compare_to, compare_to + 1);

            } else {
                break;
            }
        }
    }
}


void merge_sort(int *num_array, size_t length) {
    if ((num_array == NULL) || (length == 1)) {
        return;

    } else if (length == 2 && (*num_array > *(num_array + 1))) {
        swap(num_array, num_array + 1);

    } else {
        merge_sort(num_array, length/2);
        merge_sort(num_array + length/2, length - length/2);
        insertion_sort(num_array, length);
    }
}
