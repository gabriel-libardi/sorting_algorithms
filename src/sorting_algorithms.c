#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sorting_algorithms.h"
#include "utils.h"


/************************************************************
    Bubble sort has a worst case time complexity of O(n²),
and a worst case space complexity of O(1) (It is an in-place
algorithm). If the input is a nearly sorted array (with ele_
ments at most k steps away from their sorted position), the
algorithm has time complexity of O(nk) (maybe even better
complexity with respect to k). This algorithm is therefore
adaptative, and it is also stable, but it is not online.
*************************************************************/


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


/************************************************************
    Selection sort has a time complexity of O(n²) and a space
complexity of O(1) (It is an in-place algorithm). This 
algorithm is not stable, not adaptative and not online.
*************************************************************/


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


/************************************************************
    Insertion Sort has wort case time comlpexity of O(n²) and
worst case space complexity of O(1) (It is an in-place
algorithm). It is adaptative for nearly sorted lists
(just like bubble sort), having a worst case time complexity
of O(nlogk) for arrays in which every element is at most k
steps away from its sorted position. It is also adaptative 
for partially sorted arrays, for which it has a worst case
time complexity of O(nk), where k is the number of unsorted
elements in the array. Furthermore, insertion sort is a stable 
and an online algorithm.
*************************************************************/


void insertion_sort(int *num_array, size_t length) {
    if (num_array == NULL) {
        return;
    }

    for (int *to_insert = num_array + 1; to_insert < num_array + length; to_insert++) {
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


/************************************************************
    Merge Sort has a worst case time complexity of O(nlogn)
and a worst case space complexity of O(n) (It is NOT an 
in-place algorithm). It is stable, but not adaptative and not
an online algorithm.
*************************************************************/


void _merge_sort(int *num_array, size_t beggining, size_t end, int *buffer) {
    if ((num_array == NULL) || (buffer == NULL)) {
        exit(EXIT_FAILURE);

    } else if (beggining >= end) {
        return;

    } else {
        _merge_sort(num_array, beggining, (beggining + end)/2, buffer);
        _merge_sort(num_array, (beggining + end)/2 + 1, end, buffer);
        merge_halves(num_array, beggining, end, buffer);
    }
}


void merge_sort(int *num_array, size_t length) {
    if ((num_array == NULL) || (length == 1)) {
        return;

    } else {
        int *buffer = malloc(sizeof(int)*length);
        _merge_sort(num_array, 0, length - 1, buffer);
        free(buffer);
    }
}


/************************************************************
    Heap sort has a worst case time complexity of O(nlogn), 
and a space complexity of O(1) (It is an in-place algorithm).
It is non-adaptative, not stable and not an online algorithm.
*************************************************************/


void heap_sort(int *num_array, size_t length) {
    build_max_heap(num_array, length);

    for (size_t iterator = 0; iterator < length; iterator++) {
        swap(num_array, num_array + length - iterator - 1);
        down_heapfy(num_array, 0, length - iterator - 1);
    }
}
