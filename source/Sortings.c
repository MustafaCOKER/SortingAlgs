
#include "Tools.h"
#include "Sortings.h"

void bubbleSort(void *arr, size_t size, t_greaterThan greaterThan, t_sswap sswap)
{
    int sorted = 0;

    for (size_t i = 0; i < size - 1; ++i)
    {
        if (sorted == 1)
            break;

        sorted = 1;

        for (size_t j = 1; j < size - i; ++j)
            if (greaterThan(arr, j - 1, j))
            {
                sswap(arr, j - 1, j);
                sorted = 0;
            }
    }
}

void selectionSort(void *arr, size_t size, t_greaterThan greaterThan, t_sswap sswap)
{
    for (size_t i = 0; i < size - 1; ++i)
    {
        size_t selected = i;
        for (size_t j = i + 1; j < size; ++j)
        {
            if (greaterThan(arr, selected, j))
                selected = j;
        }

        sswap(arr, selected, i);
    }
}

void recursiveBubbleSort(void *arr, size_t size, t_greaterThan greaterThan, t_sswap sswap)
{
    if (size <= 1)
        return;

    for (size_t i = 0; i < size - 1; ++i)
    {
        if (greaterThan(arr, i, i + 1))
            sswap(arr, i, i + 1);
    }

    recursiveBubbleSort(arr, size - 1, greaterThan, sswap);
}

void insertionSort(void *arr, size_t size, t_greaterThan greaterThan, t_sswap sswap)
{
    if (size <= 1)
        return;

    for (size_t i = 1; i < size; ++i)
    {
        for (size_t j = i; j > 0; --j)
        {
            if (greaterThan(arr, j - 1, j))
                sswap(arr, j - 1, j);
        }
    }
}

void recursiveInsertionSort(void *arr, size_t size, t_greaterThan greaterThan, t_sswap sswap)
{
    if (size <= 1)
        return;

    recursiveInsertionSort(arr, size - 1, greaterThan, sswap);

    for (size_t i = size - 1; i > 0; --i)
    {
        if (greaterThan(arr, i - 1, i))
            sswap(arr, i - 1, i);
    }
}

void gnomeSort(void *arr, size_t size, t_greaterThan greaterThan, t_sswap sswap)
{
    for (int i = 1; i < size; ++i)
    {
        if (i == 0)
            continue;

        if (greaterThan(arr, i - 1, i))
        {
            sswap(arr, i - 1, i);
            i -= 2;
        }
    }
}