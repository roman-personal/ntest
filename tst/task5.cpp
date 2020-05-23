#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "task5.h"

class Task5Test : public ::testing::Test
{
protected:
    struct TreeNode* tree;

    Task5Test() {}

    ~Task5Test() override {}

    void SetUp() override {
        tree = nullptr;
    }

    void TearDown() override {
        delete_node(tree);
        tree = nullptr;
    }
};

TEST_F(Task5Test, EmptyTree) {
    auto [depth, paths] = calculate_tree_depth(tree);
    EXPECT_EQ(depth, 0);
    EXPECT_EQ(paths.size(), 0);
}

TEST_F(Task5Test, RootOnly) {
    tree = make_node(1, nullptr, nullptr);
    auto [depth, paths] = calculate_tree_depth(tree);
    EXPECT_EQ(depth, 1);
    EXPECT_EQ(paths.size(), 1);
    EXPECT_THAT(paths[0], ::testing::ElementsAre(1));
}

TEST_F(Task5Test, SingleLeftPath) {
    tree = make_node(1, 
        make_node(2, nullptr, nullptr), 
        nullptr);
    auto [depth, paths] = calculate_tree_depth(tree);
    EXPECT_EQ(depth, 2);
    EXPECT_EQ(paths.size(), 1);
    EXPECT_THAT(paths[0], ::testing::ElementsAre(1, 2));
}

TEST_F(Task5Test, SingleRightPath) {
    tree = make_node(1, 
        nullptr,
        make_node(3, nullptr, nullptr));
    auto [depth, paths] = calculate_tree_depth(tree);
    EXPECT_EQ(depth, 2);
    EXPECT_EQ(paths.size(), 1);
    EXPECT_THAT(paths[0], ::testing::ElementsAre(1, 3));
}

TEST_F(Task5Test, LeftAndRightPath) {
    tree = make_node(1, 
        make_node(2, nullptr, nullptr), 
        make_node(3, nullptr, nullptr));
    auto [depth, paths] = calculate_tree_depth(tree);
    EXPECT_EQ(depth, 2);
    EXPECT_EQ(paths.size(), 2);
    EXPECT_THAT(paths[0], ::testing::ElementsAre(1, 2));
    EXPECT_THAT(paths[1], ::testing::ElementsAre(1, 3));
}