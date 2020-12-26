#include <stdio.h>

#include "tools.h"
#include "sortings.h"


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


