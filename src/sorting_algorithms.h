#ifndef __SORTING_ALGORITHMS_H__
#define __SORTING_ALGORITHMS_H__


void bubble_sort(int *num_array, size_t length);
void selection_sort(int *num_array, size_t length);
void insertion_sort(int *num_array, size_t length);
void _merge_sort(int *num_array, size_t beggining, size_t end, int *buffer);


#endif