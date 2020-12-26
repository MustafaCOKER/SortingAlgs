#include <stdio.h>

typedef unsigned char bool;

typedef void (*t_sswap)(void *pos, int index1, int index2);
typedef bool (*t_greaterThan)(void *pos, int index1, int index2);

#define GOTO_INDEX(ttype, startPos, index)                                  \
    ( * ((ttype*) (startPos + index * sizeof(ttype))) )

#define DEF_GREATER_THAN( type, fooName )                                   \
    bool fooName(void* p1, int index1, int index2)                          \
    {                                                                       \
        return GOTO_INDEX( type, p1, index1 )                               \
             > GOTO_INDEX( type, p1, index2 );                              \
    }

#define DEF_SWAP( type, fooName )                                           \
    void fooName(void* p1, int index1, int index2)                          \
    {                                                                       \
        type temp = GOTO_INDEX( type, p1, index2 );                         \
        GOTO_INDEX( type, p1, index2 ) = GOTO_INDEX( type, p1, index1 );    \
        GOTO_INDEX( type, p1, index1 ) = temp;                              \
    }

#define DEF_PRINT( type, fooName, printfFrmt )                              \
    void fooName(void* p, int index)                                        \
    {                                                                       \
        printf(printfFrmt, GOTO_INDEX( type, p, index ) );                  \
    }

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

void printArr(void *p, int size, void (*print)(void *p1, int index))
{
    for (int i=0; i<size; ++i)
        print(p, i);

    printf("\n");
}

DEF_GREATER_THAN(int, greaterThan_int);
DEF_SWAP(int, swap_int);
DEF_PRINT(int, print_int, "%d ");

DEF_GREATER_THAN(char, greaterThan_char);
DEF_SWAP(char, swap_char);
DEF_PRINT(char, print_char, "%c ");

// Test Functions

void SelectionSortTest4Int()
{
    printf("********** Selection Sort For Int **********\n");
    int varArrInt[] = {2, 6, 1, 9, 8, 0, 4};
    size_t arrSize = sizeof(varArrInt) / sizeof(int);

    printArr(varArrInt,     arrSize, print_int);
    selectionSort(varArrInt,   arrSize, greaterThan_int, swap_int);
    printArr(varArrInt,     arrSize, print_int);
}

void SelectionSortTest4Char()
{
    printf("********** Selection Sort For Char **********\n");
    char varArrChar[] = "Sort Me Please !";
    size_t arrSize = sizeof(varArrChar) / sizeof(char);

    printArr(varArrChar,    arrSize, print_char);
    selectionSort(varArrChar,  arrSize, greaterThan_char, swap_char);
    printArr(varArrChar,    arrSize, print_char);
}

void BubbleSortTest4Int()
{
    printf("********** Bubble Sort For Int **********\n");
    int varArrInt[] = {2, 6, 1, 9, 8, 0, 4};
    size_t arrSize = sizeof(varArrInt) / sizeof(int);

    printArr(varArrInt,     arrSize, print_int);
    bubbleSort(varArrInt,   arrSize, greaterThan_int, swap_int);
    printArr(varArrInt,     arrSize, print_int);
}

void BubbleSortTest4Char()
{
    printf("********** Bubble Sort For Char **********\n");
    char varArrChar[] = "Sort Me Please !";
    size_t arrSize = sizeof(varArrChar) / sizeof(char);

    printArr(varArrChar,    arrSize, print_char);
    bubbleSort(varArrChar,  arrSize, greaterThan_char, swap_char);
    printArr(varArrChar,    arrSize, print_char);
}

int main()
{
    // Bubble Sort
    BubbleSortTest4Int();
    BubbleSortTest4Char();

    // Selection Sort
    SelectionSortTest4Int();
    SelectionSortTest4Char();


    return 0;
}


