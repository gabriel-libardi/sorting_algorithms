#ifndef __UTILS_H__
#define __UTILS_H__


#include <stdbool.h>


#define ULONG unsigned long
#define for_while(initialize, stop, one_more, update_1, update_2) \
    initialize;                                                   \
    bool last_iteration = false;                                  \
    goto loop;                                                    \
                                                                  \
    while (true)                                                  \
        if (true) {                                               \
            update_1;                                             \
            update_2;                                             \
            loop:                                                 \
                                                                  \
            if (!(stop) || last_iteration) {                      \
                break;                                            \
            }                                                     \
                                                                  \
            if (!(one_more)) {                                    \
                last_iteration = true;                            \
            }                                                     \
                                                                  \
            goto loop_body;                                       \
        } else                                                    \
            loop_body:


void swap(int *num_ptr_1, int *num_ptr_2);
void merge_halves(int *num_array, size_t beggining, size_t end, int *buffer);
void build_max_heap(int *heap, size_t length);
void down_heapfy(int *heap, size_t start_index, size_t length);
unsigned long max_pow_2(size_t positive_num);
size_t partition(int *num_array, size_t beggining, size_t end);


#endif