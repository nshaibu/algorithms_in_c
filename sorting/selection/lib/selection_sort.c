#include "selection_sort.h"

void swap(int list[], int i, int j)
{
    int hold = list[i];
    list[i] = list[j];
    list[j] = hold;
}

int get_smallest_value(int list[], int low, int high)
{
    int small = low;
    for (int i=low + 1; i <= high; i++)
        if (list[i] < list[small]) small = i;
    return small;
}

void selection_sort(int list[], int low, int high) {
    for (int h = low; h <= high; h++)
        swap(list, h, get_smallest_value(list, h, high));
}
