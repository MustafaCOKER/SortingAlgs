#include "tools.h"

void printArr(void *p, size_t size, void (*print)(void *p1, size_t index))
{
    for (int i=0; i<size; ++i)
        print(p, i);

    printf("\n");
}

boolean isEqualArr(const void *arr1, const void *arr2, size_t size, t_compareNthItemsOf2Array compare)
{
    for (size_t i=0; i<size; ++i)
        if (compare(arr1, arr2, i) == FALSE)
            return FALSE;
    
    return TRUE;
}