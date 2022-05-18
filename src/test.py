import ctypes
import pytest
import random


sort = ctypes.cdll.LoadLibrary("sorting_algorithms.so")
IntVector = ctypes.c_int*25


def rand_list(length):
    return [random.randint(-100,100) for _ in range(length)]


def test_bubble_sort():
    '''Tests whether bubble_sort() works properly.'''

    for _ in range(1000):
        int_rand_list = rand_list(25)
        c_int_rand_list = IntVector()
        length = ctypes.c_size_t(25)

        for index in range(25):
            c_int_rand_list[index] = int_rand_list[index]
        sort.bubble_sort(c_int_rand_list, length)

        assert sorted(int_rand_list) == [element for element in c_int_rand_list]


def test_selection_sort():
    '''Tests whether election_sort() works properly.'''

    for _ in range(1000):
        int_rand_list = rand_list(25)
        c_int_rand_list = IntVector()
        length = ctypes.c_size_t(25)

        for index in range(25):
            c_int_rand_list[index] = int_rand_list[index]
        sort.selection_sort(c_int_rand_list, length)

        assert sorted(int_rand_list) == [element for element in c_int_rand_list]


def test_insertion_sort():
    '''Tests whether insertion_sort() works properly.'''

    for _ in range(1000):
        int_rand_list = rand_list(25)
        c_int_rand_list = IntVector()
        length = ctypes.c_size_t(25)

        for index in range(25):
            c_int_rand_list[index] = int_rand_list[index]
        sort.insertion_sort(c_int_rand_list, length)

        assert sorted(int_rand_list) == [element for element in c_int_rand_list]


def test_merge_sort():
    '''Tests whether merge_sort() works properly.'''

    for _ in range(1000):
        int_rand_list = rand_list(25)
        c_int_rand_list = IntVector()
        length = ctypes.c_size_t(25)

        for index in range(25):
            c_int_rand_list[index] = int_rand_list[index]
        sort.merge_sort(c_int_rand_list, length)

        assert sorted(int_rand_list) == [element for element in c_int_rand_list]


def test_heap_sort():
    '''Tests whether heap_sort() works properly.'''

    for _ in range(1000):
        int_rand_list = rand_list(25)
        c_int_rand_list = IntVector()
        length = ctypes.c_size_t(25)

        for index in range(25):
            c_int_rand_list[index] = int_rand_list[index]
        sort.heap_sort(c_int_rand_list, length)

        assert sorted(int_rand_list) == [element for element in c_int_rand_list]


def test_shell_sort():
    '''Tests whether shell_sort() works properly.'''

    for _ in range(1000):
        int_rand_list = rand_list(25)
        c_int_rand_list = IntVector()
        length = ctypes.c_size_t(25)

        for index in range(25):
            c_int_rand_list[index] = int_rand_list[index]
        sort.shell_sort(c_int_rand_list, length)

        assert sorted(int_rand_list) == [element for element in c_int_rand_list]


def test_quick_sort():
    '''Tests whether quick_sort() works properly.'''

    for _ in range(1000):
        int_rand_list = rand_list(25)
        c_int_rand_list = IntVector()
        length = ctypes.c_size_t(25)

        for index in range(25):
            c_int_rand_list[index] = int_rand_list[index]
        sort.quick_sort(c_int_rand_list, length)

        assert sorted(int_rand_list) == [element for element in c_int_rand_list]


def test_quick_sort_lomuto():
    '''Tests whether quick_sort_lomuto() works properly.'''

    for _ in range(1000):
        int_rand_list = rand_list(25)
        c_int_rand_list = IntVector()
        length = ctypes.c_size_t(25)

        for index in range(25):
            c_int_rand_list[index] = int_rand_list[index]
        sort.quick_sort_lomuto(c_int_rand_list, length)

        assert sorted(int_rand_list) == [element for element in c_int_rand_list]


def test_counting_sort():
    '''Tests whether counting_sort() works properly.'''

    for _ in range(1000):
        int_rand_list = rand_list(25)
        c_int_rand_list = IntVector()
        length = ctypes.c_size_t(25)

        for index in range(25):
            c_int_rand_list[index] = int_rand_list[index]
        sort.counting_sort(c_int_rand_list, length, 201)

        assert sorted(int_rand_list) == [element for element in c_int_rand_list]
