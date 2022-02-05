#include <time.h>
#include <stdlib.h>
#include "utils.h"
#include "sorting_algorithms.h"

#define NUM_TESTS 1


int *rand_list(size_t length) {
    int *new_list = malloc(sizeof(int)*length);

    for (size_t index = 0; index < length; index++) {
        time_t current_time;
        time(&current_time);
        srand(current_time);
        new_list[index] = rand()%200;
    }

    return new_list;
}


int main(int argc, char **argv) {
    for (int dummy_index = 0; dummy_index < NUM_TESTS; dummy_index++) {
        int *list_1 = rand_list(25);
        int *list_2 = rand_list(25);
        int *list_3 = rand_list(25);
        int *list_4 = rand_list(25);
        int *list_5 = rand_list(25);
        int *list_6 = rand_list(25);
        int *list_7 = rand_list(25);
        int *list_8 = rand_list(25);

        bubble_sort(list_1, 25);
        selection_sort(list_2, 25);
        insertion_sort(list_3, 25);
        merge_sort(list_4, 25);
        heap_sort(list_5, 25);
        shell_sort(list_6, 25);
        quick_sort(list_7, 25);
        counting_sort(list_8, 25, 400);

        free(list_1);
        free(list_2);
        free(list_3);
        free(list_4);
        free(list_5);
        free(list_6);
        free(list_7);
        free(list_8);
    }
}