#include "gtest/gtest.h"
#include "task4.h"

TEST(Task4Test, ZeroBits) {
    auto [min, max] = get_min_max(0);
    EXPECT_EQ(min, 0);
    EXPECT_EQ(max, 0);
}

TEST(Task4Test, OneBitLSB) {
    auto [min, max] = get_min_max(1);
    EXPECT_EQ(min, 1);
    EXPECT_EQ(max, 0x80000000);
}

TEST(Task4Test, OneBitMSB) {
    auto [min, max] = get_min_max(0x80000000);
    EXPECT_EQ(min, 1);
    EXPECT_EQ(max, 0x80000000);
}
TEST(Task4Test, SeveralBits) {
    auto [min, max] = get_min_max(0xa513);
    EXPECT_EQ(min, 0x0000007f);
    EXPECT_EQ(max, 0xfe000000);
}

TEST(Task4Test, AllBits) {
    auto [min, max] = get_min_max(0xffffffff);
    EXPECT_EQ(min, 0xffffffff);
    EXPECT_EQ(max, 0xffffffff);
}