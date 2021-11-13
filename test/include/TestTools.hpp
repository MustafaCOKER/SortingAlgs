#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstring>

int varArrInt[] = {2, 6, 1, 9, 8, 0, 4};
char varArrChar[] = "Sort Me Please !";

const char varArrChar_sorted[] = "   !MPSaeeelorst";
const int varArrInt_sorted[] = {0, 1, 2, 4, 6, 8, 9};

#define TEST_ARR_SIZE 4096
#define FILL(arr) std::memset(arr, 0, sizeof(arr));

int varArrIntD[TEST_ARR_SIZE];
int varArrIntDSorted[TEST_ARR_SIZE];

char varArrCharD[TEST_ARR_SIZE];
char varArrCharDSorted[TEST_ARR_SIZE];

double varArrDoubleD[TEST_ARR_SIZE];
double varArrDoubleDSorted[TEST_ARR_SIZE];

double varArrFloatD[TEST_ARR_SIZE];
double varArrFloatDSorted[TEST_ARR_SIZE];

// definitions of required functions for int
DEF_GREATER_THAN(int, greaterThan_int);
DEF_LESS_THAN(int, lessThan_int);
DEF_SWAP(int, swap_int);
DEF_PRINT(int, print_int, "%d ");
DEF_COMPARE_Nth_ITEMs_Of_2ARRAY(int, compareItems_int);

// definitions of required functions for char
DEF_GREATER_THAN(char, greaterThan_char);
DEF_LESS_THAN(char, lessThan_char);
DEF_SWAP(char, swap_char);
DEF_PRINT(char, print_char, "%c ");
DEF_COMPARE_Nth_ITEMs_Of_2ARRAY(char, compareItems_char);

// definitions of required functions for double
DEF_GREATER_THAN(double, greaterThan_double);
DEF_LESS_THAN(double, lessThan_double);
DEF_SWAP(double, swap_double);
DEF_PRINT(double, print_double, "%c ");
DEF_COMPARE_Nth_ITEMs_Of_2ARRAY(double, compareItems_double);

// definitions of required functions for float
DEF_GREATER_THAN(float, greaterThan_float);
DEF_LESS_THAN(float, lessThan_float);
DEF_SWAP(float, swap_float);
DEF_PRINT(float, print_float, "%c ");
DEF_COMPARE_Nth_ITEMs_Of_2ARRAY(float, compareItems_float);

void initTestArr()
{
    FILL(varArrIntD);
    FILL(varArrIntDSorted);

    FILL(varArrCharD);
    FILL(varArrCharDSorted);

    FILL(varArrDoubleD);
    FILL(varArrDoubleDSorted);

    FILL(varArrFloatD);
    FILL(varArrFloatDSorted);
}

void generateTestArr()
{
    std::srand(std::time(nullptr));
    int randomNum = 0;

    for (size_t i = 0; i < TEST_ARR_SIZE; ++i)
    {
        randomNum = std::rand() % TEST_ARR_SIZE;

        varArrIntD[i] = randomNum;
        varArrCharD[i] = (char)32 + randomNum % 95;
        varArrDoubleD[i] = (double)randomNum;
        varArrFloatD[i] = (float)randomNum;

        varArrIntDSorted[i] = varArrIntD[i];
        varArrCharDSorted[i] = varArrCharD[i];
        varArrDoubleDSorted[i] = varArrDoubleD[i];
        varArrFloatDSorted[i] = varArrFloatD[i];
    }

    bubbleSort(varArrIntDSorted, TEST_ARR_SIZE, greaterThan_int, swap_int);
    bubbleSort(varArrCharDSorted, TEST_ARR_SIZE, greaterThan_char, swap_char);
    bubbleSort(varArrDoubleDSorted, TEST_ARR_SIZE, greaterThan_double, swap_double);
    bubbleSort(varArrFloatDSorted, TEST_ARR_SIZE, greaterThan_float, swap_float);
}