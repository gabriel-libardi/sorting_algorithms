#include "utils.h"

void swap(int *num_ptr_1, int *num_ptr_2) {
    
    int tmp = *num_ptr_1;
    *num_ptr_1 = *num_ptr_2;
    *num_ptr_2 = tmp;
}