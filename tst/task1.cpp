#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "task1.h"

TEST(Task1Test, NPrimes) {
    int primes[10];
    calculate_primes(10, primes);
    EXPECT_THAT(primes, ::testing::ElementsAreArray({2, 3, 5, 7, 11, 13, 17, 19, 23, 29}));
}
