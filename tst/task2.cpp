#include "gtest/gtest.h"
#include "task2.h"

TEST(Task2Test, NullText) {
    auto result = count_words_by_length(nullptr);
    ASSERT_EQ(result.size(), 0);
}

TEST(Task2Test, EmptyText) {
    auto result = count_words_by_length("");
    ASSERT_EQ(result.size(), 0);
}

TEST(Task2Test, OneWord) {
    auto result = count_words_by_length("test");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[4], 1);
}

TEST(Task2Test, SpaceDelimited) {
    auto result = count_words_by_length("The quick brown fox jumps over the lazy dog");
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[3], 4);
    EXPECT_EQ(result[4], 2);
    EXPECT_EQ(result[5], 3);
}

TEST(Task2Test, ExclamationMark) {
    auto result = count_words_by_length("Hi!");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[2], 1);
}

TEST(Task2Test, QuestionMark) {
    auto result = count_words_by_length("Really?");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[6], 1);
}

TEST(Task2Test, Dot) {
    auto result = count_words_by_length("The end.");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[3], 2);
}

TEST(Task2Test, Comma) {
    auto result = count_words_by_length("a,b,c");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[1], 3);
}

TEST(Task2Test, Apostrophe) {
    auto result = count_words_by_length("'sign'");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[4], 1);
}

TEST(Task2Test, QuotationMark) {
    auto result = count_words_by_length("\"sign\"");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[4], 1);
}

TEST(Task2Test, Colon) {
    auto result = count_words_by_length("For example: cat");
    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[3], 2);
    EXPECT_EQ(result[7], 1);
}

TEST(Task2Test, Semicolon) {
    auto result = count_words_by_length("one;two");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[3], 2);
}

TEST(Task2Test, Slash) {
    auto result = count_words_by_length("one/two");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[3], 2);
}

TEST(Task2Test, BackSlash) {
    auto result = count_words_by_length("one\\two");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[3], 2);
}