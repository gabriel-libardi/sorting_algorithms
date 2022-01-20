#ifndef __UTILS_H__
#define __UTILS_H__


void swap(int *num_ptr_1, int *num_ptr_2);
void merge_halves(int *num_array, size_t beggining, size_t end, int *buffer);
void build_max_heap(int *heap, size_t length);
void down_heapfy(int *heap, size_t start_index, size_t length);


#endif