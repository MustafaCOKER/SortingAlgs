#include <gtest/gtest.h>

extern "C"
{
  #include "sortings.h"
}

#include "test_tools.hpp"

TEST (SelectionSort1, PositiveNos) { 
    initTestArr();
    generateTestArr();

    selectionSort(varArrIntD, TEST_ARR_SIZE, greaterThan_int, swap_int);
    selectionSort(varArrCharD, TEST_ARR_SIZE, greaterThan_char, swap_char);
    selectionSort(varArrDoubleD, TEST_ARR_SIZE, greaterThan_double, swap_double);
    selectionSort(varArrFloatD, TEST_ARR_SIZE, greaterThan_float, swap_float);

    EXPECT_EQ ( isEqualArr(varArrIntD, varArrIntDSorted, TEST_ARR_SIZE, compareItems_int), 1 );
    EXPECT_EQ ( isEqualArr(varArrCharD, varArrCharDSorted, TEST_ARR_SIZE, compareItems_char), 1 );
    EXPECT_EQ ( isEqualArr(varArrDoubleD, varArrDoubleDSorted, TEST_ARR_SIZE, compareItems_double), 1 );
    EXPECT_EQ ( isEqualArr(varArrFloatD, varArrFloatDSorted, TEST_ARR_SIZE, compareItems_float), 1 );
}