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


void build_max_heap(int *heap, size_t length) {
    for (size_t root_index = length/2 - 1; root_index < length; root_index--) {
        down_heapfy(heap, root_index, length);
    }
}


void down_heapfy(int *heap, size_t start_index, size_t length) {
    for (size_t index = start_index; index < length;) {
        size_t largest = index;

        if (2*index + 1 < length && heap[largest] < heap[2*index + 1]) {
            largest = 2*index + 1;
        } 
        
        if (2*index + 2 < length && heap[largest] < heap[2*index + 2]) {
            largest = 2*index + 2;
        }

        if (largest != index) {
            swap(heap + index, heap + largest);
            index = largest;

        } else {
            break;
        }
    }
}


unsigned long max_pow_2(size_t positive_num) {
    unsigned long max_pow_2 = 1;

    for (double iterator = positive_num; iterator > 2; iterator /= 2) {
        max_pow_2 *= 2;
    }

    return max_pow_2;
}


size_t partition(int *num_array, size_t beggining, size_t end) {
    int pivot = num_array[(beggining + end)/2];
    size_t smaller = beggining;
    size_t bigger = end;

    while (true) {
        while (num_array[smaller] < pivot) smaller++;
        while (num_array[bigger] > pivot) bigger--;

        if (bigger <= smaller) {
            break;
        }

        swap(num_array + smaller, num_array + bigger);
        smaller++;
        bigger--;
    }

    return bigger;
}