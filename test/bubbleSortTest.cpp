#include <gtest/gtest.h>

extern "C"
{
  #include "sortings.h"
}

TEST(SquareRootTest5, PositiveNos) { 
    EXPECT_EQ (18.0, 18.0);
    EXPECT_EQ (25.4, 25.4);
    EXPECT_EQ (50.3321, 50.3321);
}

TEST (SquareRootTest1, ZeroAndNegativeNo) { 
    ASSERT_EQ (0.0, 0.0);
}

TEST (SquareRootTest2, ZeroAndNegativeN) { 
    ASSERT_EQ (0.0, 0.0);
}

TEST (SquareRootTest3, ZeroAndNegative) { 
    ASSERT_EQ (0.0, 0.0);
}