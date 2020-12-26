
#include "tools.h"
#include "sortings.h"

void bubbleSort(void* arr, int size, t_greaterThan greaterThan, t_sswap sswap)
{
    for (int i=0;i<size-1; ++i)
    {
        for (int j=1; j<size-i; ++j)
            if (greaterThan(arr, j-1, j))
                sswap(arr, j-1, j);
    }
}

void selectionSort(void* arr, int size, t_greaterThan greaterThan, t_sswap sswap)
{
    for (int i=0;i<size-1; ++i)
    {
        int selected = i;
        for (int j=i+1; j<size; ++j)
        {
            if (greaterThan(arr, selected, j))
                selected = j;
        }

        sswap(arr, selected, i);
    }
}