
#include "tools.h"
#include "sortings.h"

void bubbleSort(void* arr, size_t size, t_greaterThan greaterThan, t_sswap sswap)
{
    for (size_t i=0;i<size-1; ++i)
    {
        for (size_t j=1; j<size-i; ++j)
            if (greaterThan(arr, j-1, j))
                sswap(arr, j-1, j);
    }
}

void selectionSort(void* arr, size_t size, t_greaterThan greaterThan, t_sswap sswap)
{
    for (size_t i=0;i<size-1; ++i)
    {
        size_t selected = i;
        for (size_t j=i+1; j<size; ++j)
        {
            if (greaterThan(arr, selected, j))
                selected = j;
        }

        sswap(arr, selected, i);
    }
}