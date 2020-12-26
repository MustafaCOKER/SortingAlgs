#include "tools.h"


void printArr(void *p, int size, void (*print)(void *p1, int index))
{
    for (int i=0; i<size; ++i)
        print(p, i);

    printf("\n");
}