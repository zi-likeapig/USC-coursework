#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(IsPrime, MinusOne) { 
  int determination = IsPrime(-1);
  EXPECT_EQ(0, determination); 
}

TEST(IsPrime, Zero) { 
  int determination = IsPrime(0);
  EXPECT_EQ(0, determination); 
}

TEST(IsPrime, One) { 
  int determination = IsPrime(1);
  EXPECT_EQ(0, determination); 
}

TEST(IsPrime, N2) { 
  int determination = IsPrime(2);
  EXPECT_EQ(1, determination); 
}

TEST(IsPrime, N3) { 
  int determination = IsPrime(3);
  EXPECT_EQ(1, determination); 
}

TEST(IsPrime, N4) { 
  int determination = IsPrime(4);
  EXPECT_EQ(0, determination); 
}

TEST(IsPrime, N5) { 
  int determination = IsPrime(5);
  EXPECT_EQ(1, determination); 
}

TEST(IsPrime, N1009) { 
  int determination = IsPrime(1009);
  EXPECT_EQ(1, determination); 
}

TEST(IsPrime, N1011) { 
  int determination = IsPrime(1011);
  EXPECT_EQ(0, determination); 
}

TEST(IsPrime, N1013) { 
  int determination = IsPrime(1013);
  EXPECT_EQ(1, determination); 
}