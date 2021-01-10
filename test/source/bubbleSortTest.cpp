#include <gtest/gtest.h>

extern "C"
{
  #include "sortings.h"
}

#include "test_tools.hpp"

TEST(BubbleSort1, PositiveNos) { 

    bubbleSort(varArrInt, sizeof(varArrInt)/sizeof(int), greaterThan_int, swap_int);
    EXPECT_EQ ( isEqualArr(varArrInt, varArrInt_sorted, sizeof(varArrInt)/sizeof(int), compareItems_int), 1 );
}

TEST (BubbleSort2, PositiveNos) { 
    initTestArr();
    generateTestArr();

    bubbleSort(varArrIntD, TEST_ARR_SIZE, greaterThan_int, swap_int);
    bubbleSort(varArrCharD, TEST_ARR_SIZE, greaterThan_char, swap_char);
    bubbleSort(varArrDoubleD, TEST_ARR_SIZE, greaterThan_double, swap_double);
    bubbleSort(varArrFloatD, TEST_ARR_SIZE, greaterThan_float, swap_float);

    EXPECT_EQ ( isEqualArr(varArrIntD, varArrIntDSorted, TEST_ARR_SIZE, compareItems_int), 1 );
    EXPECT_EQ ( isEqualArr(varArrCharD, varArrCharDSorted, TEST_ARR_SIZE, compareItems_char), 1 );
    EXPECT_EQ ( isEqualArr(varArrDoubleD, varArrDoubleDSorted, TEST_ARR_SIZE, compareItems_double), 1 );
    EXPECT_EQ ( isEqualArr(varArrFloatD, varArrFloatDSorted, TEST_ARR_SIZE, compareItems_float), 1 );
}