#ifndef __SORTING_ALGORITHMS_H__
#define __SORTING_ALGORITHMS_H__


void bubble_sort(int *num_array, size_t length);
void selection_sort(int *num_array, size_t length);
void insertion_sort(int *num_array, size_t length);

void _merge_sort(int *num_array, size_t beggining, size_t end, int *buffer);
void merge_sort(int *num_array, size_t length);

void heap_sort(int *num_array, size_t length);
void shell_sort(int *num_array, size_t length);

void quick_sort(int *num_array, size_t length);
void _quick_sort(int *num_array, size_t beggining, size_t end);

void quick_sort_lomuto(int *num_array, size_t length);
void _quick_sort_lomuto(int *num_array, size_t beggining, size_t end);

void counting_sort(int *num_array, size_t length, size_t num_types);


#endif