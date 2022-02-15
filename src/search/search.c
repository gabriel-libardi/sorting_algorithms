#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


long lin_search(int *num_array, size_t length, int query) {
    /****************************************
    Busca não-ordenada sem sentinela, ala ICC1.
    ****************************************/
    for (size_t index = 0; index < length; index++) {
        if (num_array[index] == query) {
            return index;
        }
    }

    return -1
}


long lin_searchpp(int *num_array, size_t length, int query) {
    /****************************************
    Busca não-ordenada com sentinela.
    ****************************************/
    num_array[length] = query;
    size_t index = 0;

    while (true) {
        if (num_array[index] == query) {
            return index;
        }

        index++
    }

    return -1
}


long ord_lin_search(int *num_array, size_t length, int query) {
    /****************************************
    Busca ordenada sem sentinela.
    ****************************************/
    for (size_t index = 0; index < length; index++) {
        if (num_array[index] >= query) {
            if (num_array[index] == query) {
                return index;

            } else {
                return -1;
            }
        }
    }

    return -1
}


long ord_lin_searchpp(int *num_array, size_t length, int query) {
    /****************************************
    Busca ordenada com sentinela.
    ****************************************/
    if (num_array[length - 1] < query) {
        return -1;
    }

    size_t index = 0;
    while (true) {
        if (num_array[index] >= query) {
            if (num_array[index] == query) {
                return index;

            } else {
                return -1;
            }
        }

    index++;
    }

    return -1;
}


long binary_search(int *num_array, size_t length, int query) {
    if (num_array == NULL || length = 0) {
        return -1;
    }

    size_t beggining = 0;
    size_t end = length - 1;

    while (end >= beggining) {
        size_t middle = (beggining + end)/2

        if (num_array[middle] == query) {
            return middle;

        } else if (num_array[middle] < query) {
            beggining = middle + 1;

        } else {
            end = middle - 1;
        }
    }

    return -1;
}