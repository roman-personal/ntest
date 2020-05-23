#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "task1.h"

TEST(Task1Test, FirstPrime) {
    int primes[1];
    calculate_primes(1, primes);
    EXPECT_THAT(primes, ::testing::ElementsAre(2));
}

TEST(Task1Test, NPrimes) {
    int primes[10];
    calculate_primes(10, primes);
    EXPECT_THAT(primes, ::testing::ElementsAreArray({2, 3, 5, 7, 11, 13, 17, 19, 23, 29}));
}

TEST(Task1Test, NIsInvalid) {
    EXPECT_THROW(
        { 
            int primes[10];
            calculate_primes(0, primes);
        }, 
        std::invalid_argument);
}

TEST(Task1Test, PrimesIsNull) {
    EXPECT_THROW({ calculate_primes(1, nullptr); }, std::invalid_argument);
}