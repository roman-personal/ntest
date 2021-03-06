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

    struct TreeNode* make_node(int tag, struct TreeNode* left, struct TreeNode* right) {
        auto node = new TreeNode();
        node->tag = tag;
        node->leftChild = left;
        node->rightChild = right;
        return node;
    }

    void delete_node(struct TreeNode* node) {
        if (node == nullptr)
            return;
        delete_node(node->leftChild);
        delete_node(node->rightChild);
        delete node;
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
    ASSERT_EQ(paths.size(), 1);
    EXPECT_THAT(paths[0], ::testing::ElementsAre(1));
}

TEST_F(Task5Test, SingleLeftPath) {
    tree = make_node(1, 
        make_node(2, nullptr, nullptr), 
        nullptr);
    auto [depth, paths] = calculate_tree_depth(tree);
    EXPECT_EQ(depth, 2);
    ASSERT_EQ(paths.size(), 1);
    EXPECT_THAT(paths[0], ::testing::ElementsAre(1, 2));
}

TEST_F(Task5Test, SingleRightPath) {
    tree = make_node(1, 
        nullptr,
        make_node(3, nullptr, nullptr));
    auto [depth, paths] = calculate_tree_depth(tree);
    EXPECT_EQ(depth, 2);
    ASSERT_EQ(paths.size(), 1);
    EXPECT_THAT(paths[0], ::testing::ElementsAre(1, 3));
}

TEST_F(Task5Test, LeftAndRightPaths) {
    tree = make_node(1, 
        make_node(2, nullptr, nullptr), 
        make_node(3, nullptr, nullptr));
    auto [depth, paths] = calculate_tree_depth(tree);
    EXPECT_EQ(depth, 2);
    ASSERT_EQ(paths.size(), 2);
    EXPECT_THAT(paths[0], ::testing::ElementsAre(1, 2));
    EXPECT_THAT(paths[1], ::testing::ElementsAre(1, 3));
}

TEST_F(Task5Test, LeftMaxPath) {
    tree = make_node(1, 
        make_node(2, 
            make_node(4, nullptr, nullptr), 
            nullptr), 
        make_node(3, nullptr, nullptr));
    auto [depth, paths] = calculate_tree_depth(tree);
    EXPECT_EQ(depth, 3);
    ASSERT_EQ(paths.size(), 1);
    EXPECT_THAT(paths[0], ::testing::ElementsAre(1, 2, 4));
}

TEST_F(Task5Test, RightMaxPath) {
    tree = make_node(1, 
        make_node(2, nullptr, nullptr),
        make_node(3, 
            make_node(4, nullptr, nullptr), 
            nullptr));
    auto [depth, paths] = calculate_tree_depth(tree);
    EXPECT_EQ(depth, 3);
    ASSERT_EQ(paths.size(), 1);
    EXPECT_THAT(paths[0], ::testing::ElementsAre(1, 3, 4));
}

TEST_F(Task5Test, AllPaths) {
    tree = make_node(1, 
        make_node(2, 
            make_node(4, nullptr, nullptr), 
            make_node(5, nullptr, nullptr)),
        make_node(3, 
            make_node(6, nullptr, nullptr), 
            make_node(7, nullptr, nullptr))
        );
    auto [depth, paths] = calculate_tree_depth(tree);
    EXPECT_EQ(depth, 3);
    ASSERT_EQ(paths.size(), 4);
    EXPECT_THAT(paths[0], ::testing::ElementsAre(1, 2, 4));
    EXPECT_THAT(paths[1], ::testing::ElementsAre(1, 2, 5));
    EXPECT_THAT(paths[2], ::testing::ElementsAre(1, 3, 6));
    EXPECT_THAT(paths[3], ::testing::ElementsAre(1, 3, 7));
}
