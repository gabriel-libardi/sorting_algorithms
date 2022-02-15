#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    Insertion Sort has wort case time complexity of O(n²) and
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


/**************************************************************
    Shell sort is a family of sorting algorithms that improve
on insertion sort. Each of them generate a sequence p[i] of
positive integers and p[i]-order the array. The last p[i] is
always equal to one, so as to guarantee that the array is 
ordered at the end of the procedure (because 1-sorting is
basically just insertion sort). The idea is to arrive at the
last step with a nearly sorted list and capitalize on the
efficiency of insertion sort for nearly sorted lists. The best
shellsort algorithm has a worst case time complexity of
O(nlog²n), and a worst case space complexity of O(1) (it is
an in-place algorithm). In practice, it is faster than most 
of the algorithms implemented above. However, it is neither
stable, nor adaptative, nor online.
***************************************************************/


void shell_sort(int *num_array, size_t length) {
    for (ULONG power = max_pow_2(length); power > 0; power /= 2) {
        for_while(ULONG period = power, period < length, !(period%2), period *= 3, period /= 2) {
            for (size_t chain = 0; chain < period; chain++) {
                for (size_t index = period + chain; index < length; index += period) {
                    if (num_array[index - period] > num_array[index]) {
                        swap(num_array + index, num_array + index - period);
                    }
                }
            }
        }
    }
}


/*************************************************************
    Quicksort is a classic divide-and-conquer algorithm and it
is the de facto king of sorting algorithms. It has a worst case 
time complexity of O(n²) and a worst case space complexity of
O(log(n)). However, its average time complexity is O(nlog(n))
and it is in pratice much faster than all the other algorithms.
It is neither stable, nor adaptative, nor online.
*************************************************************/


void _quick_sort(int *num_array, size_t beggining, size_t end) {
    if (beggining >= end) {
        return;
    }

    size_t partition_index = partition(num_array, beggining, end);
    _quick_sort(num_array, beggining, partition_index);
    _quick_sort(num_array, partition_index + 1, end);
}


void quick_sort(int *num_array, size_t length) {
    if (num_array == NULL || length == 1) {
        return;
    }

    _quick_sort(num_array, 0, length - 1);
}


/*************************************************************
    Counting sort has a worst time complexity of O(nk), where
n is the size of the array and k is the number of distinct 
elements in the array. Hence, this algorithm is excellent for
large arrays with few distinct elements, but very bad (roughly
quadratic) in random arrays. Its worst case space complexity
is O(n + k), for it utilizes an auxiliary array and a counting
array. Furthermore, this sorting method is stable, not
adaptable and not online.
*************************************************************/


void counting_sort(int *num_array, size_t length, size_t num_types) {
    /*******************************************************   
    This imlpementation sorts numbers n such that:
    -(ceiling(num_types/2) - 1) <= n <= floor(num_types/2)
    ********************************************************/
    size_t *count = calloc(num_types, sizeof(size_t));
    size_t shift = (num_types - 1)/2;
    int *output = malloc(sizeof(int)*length);

    for (size_t index = 0; index < length; index++) {
        count[num_array[index] + shift]++;
    }

    for (size_t index = 1; index < num_types; index++) {
        count[index] += count[index - 1];
    }

    for (size_t index = length - 1; index < length; index--) {
        count[num_array[index] + shift]--;
        output[count[num_array[index] + shift]] = num_array[index];
    }

    for (size_t index = 0; index < length; index++) {
        num_array[index] = output[index];
    }

    free(count);
    free(output);
}
